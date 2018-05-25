#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cstdio>
#include <SOIL/SOIL.h>

float xrot = 0.00, yrot = 0.00, zoom = -30;
GLuint texB;
GLUquadricObj *pSphere = NULL; 


void text()
{
    char text[32];
    sprintf(text, "X:%.0f Y:%.0f", xrot, yrot);
    glColor3f(0, 0, 0);
    glRasterPos3f( -30 , 15 , zoom);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
}

void pelota(float r){
	gluSphere(pSphere,r,100,100);
}
void init(void)
{	glShadeModel( GL_FLAT );
    glClearColor( 1, 1, 1, 1);
    glClearDepth( 1.0 );
    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_LIGHTING);
    //glShadeModel(GL_SMOOTH);
    //glEnable(GL_COLOR_MATERIAL);
    //glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    //glEnable(GL_LIGHT0);
    
    pSphere = gluNewQuadric();
    gluQuadricDrawStyle(pSphere, GLU_FILL);
    gluQuadricNormals(pSphere, GLU_SMOOTH);
    gluQuadricTexture(pSphere, GLU_TRUE);
}
GLuint loadTex(const char* filename){
    GLuint tex_ID = SOIL_load_OGL_texture(filename, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,(SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT));
    glEnable( GL_TEXTURE_2D );
    glBindTexture( GL_TEXTURE_2D, tex_ID );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    return tex_ID;
}



void balon(){
    glPushMatrix();  
    glEnable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texB);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    pelota(3.0);
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
    glPopMatrix();    
    

}

void Cargartextura(){
    texB = loadTex("../texture/ball.jpg");
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
	glTranslatef(0.0f,0.0f,-4.0f);
    glTranslatef(0, 0, zoom);

    // Escribir el texto despues de la transformación
    text();

    glRotatef(xrot, 1, 0, 0);
    glRotatef(yrot, 0, 1, 0);

    balon();

    glFlush();
    glutSwapBuffers();
}


void reshape(int w, int h)
{
    float aspectRatio = (float)w/(float)h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, aspectRatio, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_DEPTH_TEST);//Activamos el Test de profundidad.
    glDepthFunc(GL_LEQUAL);//Funcion de borrrado buffer depth.
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {

    case 27:
        exit(0);
    }
    glutPostRedisplay();
}

// Función para controlar teclas especiales
void specialKeys( int key, int x, int y )
{

    //  Flecha derecha: aumentar rotación 7 grados
    if (key == GLUT_KEY_RIGHT)
         yrot -= 3.0;

    //  Flecha izquierda: rotación en eje Y negativo 7 grados
    else if (key == GLUT_KEY_LEFT)
        yrot += 3.0;
    //  Flecha arriba: rotación en eje X positivo 7 grados
    else if (key == GLUT_KEY_UP)
         xrot += 3.0;
    //  Flecha abajo: rotación en eje X negativo 7 grados
    else if (key == GLUT_KEY_DOWN)
         xrot -= 3.0;

    //  Tecla especial F2 : rotación en eje Z positivo 7 grados

    //  Solicitar actualización de visualización
    glutPostRedisplay();

}
void Init (void){

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_TEXTURE_2D);
	
	// set up lighting
	glEnable(GL_LIGHTING);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glDisable(GL_LIGHTING);
}
int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
    glutInitWindowSize(800, 600);
    glutCreateWindow("Bitmap Ejemplo de texto");
    init();
    Init();
    Cargartextura();
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
