#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <SOIL/SOIL.h>
#include <cstdio>
#include <math.h>
#include <SDL2/SDL.h>
#define PI 3.1415927
#define RUTA_AUDIO "imperial.wav" //nombre del archivo de audio


using namespace std;

int frameNumber; 
// funcion para cargar audio
	void my_audio_callback(void *userdata, Uint8 *stream, int len);
	
	// variables para audio
	static Uint8 *audio_pos; // global pointer to the audio buffer to be played
	static Uint32 audio_len; // remaining length of the sample we have to play
	
//Arreglo de imagenes
//GLuint texture[0];
//Definimos variables
double rotate_y=0;
double rotate_x=0;
double rotate_z=0;
float x1rot = 0.00, y1rot = 0.00, zoom1 = 1;
double PX=60;
double yrot=0;
GLuint tex1,tex2,tex3,tex4,tex5,tex6,tex7;
GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 125.0f+X;
GLfloat scale = 1.0f;
GLUquadricObj* cylinder;  
GLUquadricObj *sphere;	
int texto=1;
	

void init(void)
{
	//glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0); //Activamos las luces en 
    glDepthFunc(GL_LESS); //comparación de profundidad
	glEnable(GL_DEPTH_TEST); //activa GL_DEPTH_TEST
	
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}


void Text(void)
{
	//glNewList(texto,GL_COMPILE);
	glPushMatrix();
    char text[32];
    sprintf(text, "Score:%.0f",x1rot);
    //glColor3f(0, 0, 0);
    glRasterPos3f( 100,75,zoom1);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    glPopMatrix();
	//glEndList();
}
void pulsemos(){
	glNewList(texto,GL_COMPILE);
	glPushMatrix();
	Text();
	 glPopMatrix();
	glEndList();
}
//funcion que permite buscar el url de las imagenes a utilizar
GLuint loadTex(const char* filename){
    GLuint tex_ID = SOIL_load_OGL_texture(filename, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,(SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT));
        glEnable( GL_TEXTURE_2D );
        glBindTexture( GL_TEXTURE_2D, tex_ID );
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        return tex_ID;
}
void draw_cylinder(GLfloat radius,
                   GLfloat height,
                   GLubyte R,
                   GLubyte G,
                   GLubyte B)
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x, y , height);
            glVertex3f(x, y , 0.0);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius, 0.0, height);
        glVertex3f(radius, 0.0, 0.0);
    glEnd();

    /** Draw the circle on top of cylinder */
    glColor3ub(R,G,B);
    glBegin(GL_POLYGON);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x, y , height);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius, 0.0, height);
    glEnd();
}


void esce(void)
{	
	glPushMatrix();
	//cielo
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glBegin(GL_POLYGON);
	glNormal3f( 0.0f, -1.0f,0.0f);
	glTexCoord2f(300.0f, 0.0f); glVertex3f(0, 5, 0.0);
	glTexCoord2f(300.0f, 40.0f); glVertex3f(0, 80, 0);
	glTexCoord2f(0.0f, 40.0f); glVertex3f(1000, 80, 0.0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1000, 5, 0.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	
	glPushMatrix();
	//cesped
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glBegin(GL_POLYGON);	
	glNormal3f( -1.0f, 0.0f,0.0f);
	glTexCoord2f(80.0f, 0.0f); glVertex3f(0, 0, 0.0);
	glTexCoord2f(80.0f, 1.0f); glVertex3f(0, -7, 0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1000, -7, 0.0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1000, 0, 0.0);
	
	glEnd();
	
	 glDisable(GL_TEXTURE_2D);
	 glPopMatrix();
	 glPushMatrix();
	 	//lava
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex3);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    //glTranslatef(0,0,0.0000001);
	glBegin(GL_POLYGON);	
	glNormal3f( -1.0f, 0.0f,0.0f);
	glTexCoord2f(400.0f, 0.0f); glVertex3f(0, 0, 0.0);
	glTexCoord2f(400.0f, 1.0f); glVertex3f(0, 5, 0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1000, 5, 0.0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1000, 0, 0.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	
	}

void esfera (float r)
{	
	glPushMatrix();
	glutSolidSphere(r,100,100);
	glPopMatrix();
}
void nuve (void){
	
	glPushMatrix();
    glTranslatef(15,58,1);
	esfera(7.0);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(35,60,1);
	esfera(7.0);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(24,55,1);
	esfera(7.0);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(25,67,1);
	esfera(7.0);
	glPopMatrix();
	glTranslatef(14,67,1);
	esfera(7.0);
	glPopMatrix();
	}

void pinos (float r,float al, float rc ,float alc)
{
    glPushMatrix();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex4);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    glTranslatef(0,0,0);
	glRotatef(-90, 1.0, 0.0, 0.0);
	cylinder = gluNewQuadric();
	gluQuadricTexture(cylinder,tex4);
	gluQuadricDrawStyle( cylinder, GLU_FILL );
    gluCylinder(cylinder,r, al, 9, 211, 211);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
	
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex5);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTranslated(0.0,al,0.0);
	glRotatef(-180,0,1.0,1.0);
	glutSolidCone(rc,alc,100,100);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void barril (float r,float al)
{
    glPushMatrix();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex6);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    glTranslatef(0,0,0);
	glRotatef(-90, 1.0, 0.0, 0.0);

	cylinder = gluNewQuadric();
	gluQuadricTexture(cylinder,tex6);
	gluQuadricDrawStyle( cylinder, GLU_FILL );
	gluCylinder( cylinder, 3.5, 3.5, 9.0, 211, 211);
	glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

void pelota (float r)
{
    glPushMatrix();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex7);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    glTranslatef(0,0,0);
	glRotatef(-90, 1.0, 0.0, 0.0);

	sphere = gluNewQuadric();
	gluQuadricTexture(sphere,tex7);
	gluQuadricDrawStyle( sphere, GLU_FILL);
	gluQuadricNormals( sphere, GLU_SMOOTH);
	gluQuadricOrientation( sphere, GLU_OUTSIDE);
	gluSphere(sphere, r, 200, 200);
	glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

void Cargartextura(){
    tex4 = loadTex("../img/troco.jpg");
    tex5 = loadTex("../img/orilla.png");
    tex6 = loadTex("../img/barril.png");
    tex7 = loadTex("../img/ball.jpg");
    tex1 = loadTex("../img/fondo.png");
    tex2 = loadTex("../img/sue.png");
    tex3 = loadTex("../img/gra1.png");
}
	
void display()
{
	
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	glOrtho(-0,(Z),-7,80,(-Z),(Z));

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//GLfloat light_ambient[]  = { 0.50f, 0.50f, 0.50f, 0.50f };
   // GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    //GLfloat light_position[] = { 20.0f, 1.0f, 1.0f, 0.0f };
    //GLfloat light_position[] = { 80.0, 60.0, 20.0, 0.0 };

    //glEnable(GL_LIGHT0);
   // glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    //glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    //glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glTranslatef(X,0.0f,0.0f);

////////////////////////escenario de el fondo//////////////////////////////
	

	glPushMatrix();
	esce();
	glPopMatrix();

    double j=0, cor=0;
    for(j=0;j<=2;j+=1){
    glPushMatrix();
    glTranslatef(cor,0,0);
	nuve();
	glPopMatrix();
	glPushMatrix();
	
	glTranslatef(90+cor,-20,0);	
	//glScalef(100,10,0);
	nuve();
	glPopMatrix();
	cor+=190;
}

	double j1=0, cor1=20;
    for(j1=0;j1<=2;j1+=1){
	//pino grande
	glPushMatrix();
    glTranslatef(cor1,4,1.0);
    pinos(2.75,5.0,10,30);
    glPopMatrix();
    //pino pequeño
	glPushMatrix();
    glTranslatef(60+cor1,4,1.0);
    pinos(1.75,3.7,7,18);
    glPopMatrix();
    cor1+=185;
    }
 
    //Barril
	glPushMatrix();
    glTranslatef(40,4.0,1.10);
    barril(3.5,8.0);
    glPopMatrix();    
    
    //Balon
    glPushMatrix();
    glTranslatef(PX,7.0,1.10);
    glRotatef(yrot, 0, 1, 0);
    pelota(3.0);
    glPopMatrix();     
	    
	glLineWidth(5);
    //glCallList(1);
    glPushMatrix();
    glTranslatef(-X,0,zoom1);
    //Text();
    //glCallList(texto);
    glPopMatrix();
   glFlush();
	glutSwapBuffers();

}

// --------------- Para animación  ------------------------------------------

int animating = 0;      // 0 sin animación
                        // Se cambia con la llamada a las funciones startAnimation() and pauseAnimation()

void pauseAnimation() {
        // Llamamo a la función para detener la animación
        animating = 0;
}

void updateFrame() {
        // En esta funcion agregamos el codigo que hara la secuencia de cada escena como si fuera un fotograma
        for (int i=1; i<=1; i++) {
			X-=2.0;
			//x1rot+=1;
		
               // rotateY=rotateY-= i;
        }
        
        //Verificamos el numero de frames para detener animación
        if(frameNumber==450)
        {
                pauseAnimation();
                
                frameNumber=0;
                X=0;
                //si se detiene la animacion detenemos el audio
                SDL_PauseAudio(1);
        }
        //Almacenamos el numero de frames
        frameNumber++;
        x1rot=frameNumber;
        printf ("Numero de Frame: %d \n", frameNumber);
}

void timerFunction(int timerID) {
        // Invocamos la funcion para controlar el tiempo de la ejecucion de funciones
        if (animating) {
                updateFrame();
                glutTimerFunc(30, timerFunction, 0);
                glutPostRedisplay();
        }
}

void startAnimation() {
        // llamamos la función para iniciar la animación
        if ( !animating ) {
                animating = 1;
                glutTimerFunc(30, timerFunction, 1);
        }
}


void specialKeys( int key, int x, int y )
{

	//Mov Pelota, Proximamente de la figura
	if (key == GLUT_KEY_RIGHT){
		yrot -=20.0;
        PX += 3.0f;
	}

	else if (key == GLUT_KEY_LEFT){
		yrot -=20.0;
        PX += 3.0f;
	}
	/*//  Flecha arriba: rotación en eje X positivo 7 grados
	else if (key == GLUT_KEY_UP)
									//rotate_x += 7;
									X+=5;
	//  Flecha abajo: rotación en eje X negativo 7 grados
	else if (key == GLUT_KEY_DOWN)
									//rotate_x -= 7;
									X-=5;
	//  Tecla especial F2 : rotación en eje Z positivo 7 grados
	else if (key == GLUT_KEY_F2)
									rotate_z += 7;
	//  Tecla especial F2 : rotación en eje Z negativo 7 grados
	else if (key == GLUT_KEY_F2)
									rotate_z -= 7;*/
	else if (key == GLUT_KEY_HOME){
		PX=60;
		X=0;
	}
									

	//  Solicitar actualización de visualización
	glutPostRedisplay();

}

void key(unsigned char key, int x, int y) {
        // La animación inicia al presionar la tecla espaciadora de igual forma se detiene
        if ( key == ' ' && animating==1) {
				SDL_PauseAudio(1);
                pauseAnimation();
               // glTranslatef(0,0,1);      
				//Text();
        }
        else
        {
                startAnimation();
                SDL_PauseAudio(0);
        }
        if (key == 27) {
                exit(0);
        }
}
void Init(void)
{
    glClearColor( 1, 1, 1, 1);
    glClearDepth( 1.0 );
    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_LIGHTING);
   // glShadeModel(GL_SMOOTH);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    //glEnable(GL_LIGHT0);
}
	
	void resize(int w, int h)
{
    float aspectRatio = (float)w/(float)h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, aspectRatio, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char* argv[])
{

	//  Inicializar los parámetros GLUT y de usuario proceso
	glutInit(&argc,argv);
	// Solicitar ventana con color real y doble buffer con Z-buffer
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize (800, 620);
	glutInitWindowPosition (100, 50);
	// Crear ventana
	glutCreateWindow("Escenario Mario");
	//init();
	// sonido
	// Inicializar SDL.
	if (SDL_Init(SDL_INIT_AUDIO) < 0)
	return 1;
	
	// Variables locales
	static Uint32 wav_length; // Longitud de nuestra muestra
	static Uint8 *wav_buffer; // Buffer que contiene nuestro archivo de audio
	static SDL_AudioSpec wav_spec; // Las especificaciones de nuestra pieza de música
	
	/* Cargar el WAV */
	// Las especificaciones, la longitud y el búfer de nuestro wav se llenan
	if( SDL_LoadWAV(RUTA_AUDIO, &wav_spec, &wav_buffer, &wav_length) == NULL )
	{
	return 1;
	}
	// Establecer la función de devolución de llamada
	wav_spec.callback = my_audio_callback;
	wav_spec.userdata = NULL;
	
	// Establecer nuestras variables estáticas globales
	audio_pos = wav_buffer; // Copia el buffer de sonido
	audio_len = wav_length; // Copia la longitud del archivo
	
	/*Abrir el dispositivo de audio */
	if ( SDL_OpenAudio(&wav_spec, NULL) < 0 )
	{
	fprintf(stderr, "No se pudo abrir el audio: %s\n", SDL_GetError());
	exit(-1);
	}

	Cargartextura();
	// Funciones de retrollamada
	glutDisplayFunc(display);
	//glutReshapeFunc(resize);
	glutKeyboardFunc(key);
	glutSpecialFunc(specialKeys);
		
	// Habilitar la prueba de profundidad de Z-buffer
	glEnable(GL_DEPTH_TEST);
	//frameNumber = 0;
	//glutIdleFunc(text);
	//pulsemos();
		frameNumber = 0;
	//rotateX = rotateY = 0;
	
	// Activar iluminación
	/*glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_NORMALIZE);
	
	// Descomentar si queremos que la animación y el audio inicie al levantar el script
	//startAnimation();
	/* Empezar a sonar */
	//SDL_PauseAudio(0);
	glutMainLoop();

	// Regresar al sistema operativo
	return 0;


//SDL_PauseAudio(0);
	while ( audio_len > 0 )
	{
	SDL_Delay(100); // espera un segundo para la pausa
	}
	SDL_CloseAudio();
	SDL_FreeWAV(wav_buffer);
	}
	
	//Función de devolución de llamada de audio donde se recoren los valores del bufer
	void my_audio_callback(void *userdata, Uint8 *stream, int len)
	{
	
	if (audio_len ==0)
	return;
	
	len = ( len > audio_len ? audio_len : len );
	
	SDL_memcpy (stream, audio_pos, len); // Simplemente copie desde un buffer en el otro
	//SDL_MixAudio(stream, audio_pos, len, SDL_MIX_MAXVOLUME / 2); // Mezclar de un buffer a otro
	
	audio_pos += len;
	audio_len -= len;
	}
