#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <SOIL/SOIL.h>
#include <math.h>
#define PI 3.1415927
//Arreglo de imagenes
GLuint texture[0];
//Definimos variables
double rotate_y=0;
double rotate_x=0;
double rotate_z=0;
float aceX=0.0f,aceY=-0.001f;
float velX=0.01f,velY=0.0f;
float posX=0.0f,posY=10.0f;
float angX=0.0f,angY=0.0f;
//almacena el index del estado, de la lista
int bola=2;
float xrot = 0.00, yrot = 0.00, zoom = 30;

GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 125.0f;
int frameNumber; // Numero de frames

GLfloat scale = 1.0f;
<<<<<<< HEAD
    GLUquadricObj* cylinder;  	
    void text()
{
    char text[32];
    sprintf(text, "Y:%.0f X:%.0f", frameNumber, X);
    glColor3f(0, 0, 0);
    glRasterPos3f( 100 , 70 , zoom);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
}

=======
GLUquadricObj* cylinder;  
GLUquadricObj *sphere;	
	
>>>>>>> 8fb06fd4a4b3380235c1185e6098df8bc8288b80
void init(void)
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0); //Activamos las luces en 
    glDepthFunc(GL_LESS); //comparación de profundidad
	glEnable(GL_DEPTH_TEST); //activa GL_DEPTH_TEST
	
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
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
    glNewList(bola,GL_COMPILE);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glBegin(GL_POLYGON);
	glNormal3f( 0.0f, -1.0f,0.0f);
	glTexCoord2f(80.0f, 0.0f); glVertex3f(0, 5, 0.0);
	glTexCoord2f(80.0f, 40.0f); glVertex3f(0, 80, 0);
	glTexCoord2f(0.0f, 40.0f); glVertex3f(120, 80, 0.0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(120, 5, 0.0);
	glEnd();
	glEndList();
	}

void esfera (float r)
{
	glutSolidSphere(r,100,100);
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
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    glTranslatef(0,0,0);
	glRotatef(-90, 1.0, 0.0, 0.0);
	cylinder = gluNewQuadric();
	gluQuadricTexture(cylinder,texture[3]);
	gluQuadricDrawStyle( cylinder, GLU_FILL );
    gluCylinder(cylinder,r, al, 9, 211, 211);
    glPopMatrix();
	
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[5]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTranslated(0.0,al,0.0);
	glRotatef(-180,0,1.0,1.0);
	glutSolidCone(rc,alc,100,100);
	glPopMatrix();
}

void barril (float r,float al)
{
    glPushMatrix();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    glTranslatef(0,0,0);
	glRotatef(-90, 1.0, 0.0, 0.0);

	cylinder = gluNewQuadric();
	gluQuadricTexture(cylinder,texture[4]);
	gluQuadricDrawStyle( cylinder, GLU_FILL );
	gluCylinder( cylinder, 3.5, 3.5, 9.0, 211, 211);

    glPopMatrix();
}

<<<<<<< HEAD
=======
void pelota (float r)
{
    glPushMatrix();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[6]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    glTranslatef(0,0,0);
	glRotatef(-90, 1.0, 0.0, 0.0);

	sphere = gluNewQuadric();
	gluQuadricTexture(sphere,texture[6]);
	gluQuadricDrawStyle( sphere, GLU_FILL);
	gluQuadricNormals( sphere, GLU_SMOOTH);
	gluQuadricOrientation( sphere, GLU_OUTSIDE);
	gluSphere(sphere, r, 200, 200);
    glPopMatrix();
}
>>>>>>> 8fb06fd4a4b3380235c1185e6098df8bc8288b80

void display()
{
	
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//gluLookAt(120.0, 80.10, 100.0 ,0.0, 0.0, 0.0, 0.0,1.0,0.0);
	
	//Definicion de texturas
	texture[0] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
														(
		"../img/fondo.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
							);
	texture[1] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
														(
		"../img/sue.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
							);
	texture[2] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
														(
		"../img/gra1.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
							);
	texture[3] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
														(
		"../img/troco.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
							);
	texture[4] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
														(
		"../img/orilla.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
							);

	texture[4] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
														(
		"../img/barril.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
							);
	texture[5] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
														(
		"../img/orilla.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
							);
							
	texture[6] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
														(
		"../img/ball.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
							);

 
	//glTranslatef(X,0.0f,0.0f);
////////////////////////escenario de el fondo//////////////////////////////

	glCallList(1);
	glTranslatef(posX,posY,0.0f);
	glCallList(bola);
		//esce();

	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glBegin(GL_POLYGON);	
	glNormal3f( -1.0f, 0.0f,0.0f);
	glTexCoord2f(20.0f, 0.0f); glVertex3f(0, 0, 0.0);
	glTexCoord2f(20.0f, 1.0f); glVertex3f(0, -7, 0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(550, -7, 0.0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(550, 0, 0.0);
	
	glEnd();
	
	 glDisable(GL_TEXTURE_2D);
	
	//loma
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    //glTranslatef(0,0,0.0000001);
	glBegin(GL_POLYGON);	
	glNormal3f( -1.0f, 0.0f,0.0f);
	glTexCoord2f(120.0f, 0.0f); glVertex3f(0, 0, 0.0);
	glTexCoord2f(120.0f, 1.0f); glVertex3f(0, 5, 0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(550, 5, 0.0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(550, 0, 0.0);
	glEnd();
	 glDisable(GL_TEXTURE_2D);

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
    glTranslatef(40,4.0,1.0);
    barril(3.5,8.0);
    glPopMatrix();    
<<<<<<< HEAD
	glPushMatrix();								
	text();
	glPopMatrix();
=======
    
    //Balon
    glPushMatrix();
    glTranslatef(60,7.0,1.0);
    pelota(3.0);
    glPopMatrix();     
    
>>>>>>> 8fb06fd4a4b3380235c1185e6098df8bc8288b80
    glFlush();
	glutSwapBuffers();

}

<<<<<<< HEAD
// --------------- Para animación ------------------------------------------
	
	int animating = 0; // 0 sin animación
	// Se cambia con la llamada a las funciones startAnimation() and pauseAnimation()
	
	void pauseAnimation() {
	// Llamamo a la función para detener la animación
	animating = 0;
	}
//rebote
void animacion(void){
        velY+=aceY; posY+=velY;
        velX+=aceX; posX+=velX;
        if(posY<0.0f){
          posY=0.0f; velY*=0.0f;
            if(velY<0.01f) {
                velX=0.0f; velY=0.0f;
              }
          }
        glutPostRedisplay();
}

void updateFrame() {
	// En esta funcion agregamos el codigo que hara la secuencia de cada escena como si fuera un fotograma
	/*
	//glColor3f(0.0,1.0,0.0);
		double i=0;
	for (i=120; i<=550; i+=120){
		glTranslated(i,80,0);
		esce();
	
}
	//Hacemos que la tetera gire
	for (int i=0; i<=100; i+=10) {
	X+= i;
	}*/
	//Verificamos el numero de frames para detener animación
	if(frameNumber==1000)
	{
	pauseAnimation();
	//si se detiene la animacion detenemos el audio
	frameNumber=0;
	}
	//Almacenamos el numero de frames
	frameNumber++;
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

=======
>>>>>>> 8fb06fd4a4b3380235c1185e6098df8bc8288b80
void resize(int w, int h) {
    glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-0,(Z),-7,80,(-Z),(Z));
	//gluPerspective(300.0, (float)w / (float)h, 1, 120.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
// ------------- Manejo de Teclado-----------------------------------------------
	
	void key(unsigned char key, int x, int y) {
	// La animación inicia al presionar la tecla espaciadora de igual forma se detiene
	if ( key == ' ' && animating==1) {
	//SDL_PauseAudio(1);
	pauseAnimation();
	
	}
	else
	{
	startAnimation();
	//SDL_PauseAudio(0);
	}
	if (key == 27) {
	exit(0);
	}
	}
	
void specialKeys( int key, int x, int y )
{

	//  Flecha derecha: aumentar rotación 7 grados
	if (key == GLUT_KEY_RIGHT){
<<<<<<< HEAD
					//				rotate_y += 7;}
						//rotate_y -= 7;
					x+=20;
					//Z=Z+X;}
					
					}

	//  Flecha izquierda: rotación en eje Y negativo 7 grados
	else if (key == GLUT_KEY_LEFT){
								//rotate_y -= 7;
					x-=20;
					//Z=Z+X;}
					}
=======
		X+=20;
	}

	else if (key == GLUT_KEY_LEFT){
		X-=20;
	}
>>>>>>> 8fb06fd4a4b3380235c1185e6098df8bc8288b80
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
									//rotate_z = rotate_x=rotate_y=0;
									X=0;}
									

	//  Solicitar actualización de visualización
	glutPostRedisplay();

}






int main(int argc, char* argv[])
{

	//  Inicializar los parámetros GLUT y de usuario proceso
	glutInit(&argc,argv);

	// Solicitar ventana con color real y doble buffer con Z-buffer
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize (800, 620);
	glutInitWindowPosition (100, 50);
	// Crear ventana
	glutCreateWindow("Escenario Mario");
	//init();
	// Habilitar la prueba de profundidad de Z-buffer
	glEnable(GL_DEPTH_TEST);
	glutIdleFunc(animacion);
	// Funciones de retrollamada
	glutDisplayFunc(display);
	glutKeyboardFunc(key);
	glutReshapeFunc(resize);
	glutSpecialFunc(specialKeys);
	//frameNumber = 0;
	//X = 0;
	esce();
	glutMainLoop();

	// Regresar al sistema operativo
	return 0;

}
