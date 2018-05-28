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
//variable para control de frame
int frameNumber; 
//int ba[4],pe[4];
//declaracion de variables globales
void startAnimation(void);
void startAnimation1(void);
void startAnimation2(void);
void pauseAnimation(void);
void pauseAnimation1(void);
void pauseAnimation2(void);
//Arreglo de imagenes
//GLuint texture[0];
//Definimos variables
double rotate_y=0;
double rotate_x=0;
double rotate_z=0;
float x1rot = 0.00, y1rot = 0.00, zoom1 = 1;
double PX=65;
double yrot=0;
GLuint tex1,tex2,tex3,tex4,tex5,tex6,tex7,negro, gris, cafe, grisclaro, rojo, blanco,amarillo,tex8,tex9,tex10;
GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 125.0f+X;
GLfloat scale1 = 1.0f;
GLUquadricObj* cylinder;  
GLUquadricObj *sphere;	
int texto=1;

float scale = 2;  // escala en  x, y, and z

int frameN,caminar,saltar;   // Numero de frames 
float trasladarIzq, trasladarDer,TrasladarSalto, rotateY; 

void init(void)
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0); //Activamos las luces en 
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

void black (){
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, negro);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}

void gray (){
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, gris);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}

void brown (){
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, cafe);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}

void white (){
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, blanco);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}

void grayC (){
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, grisclaro);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}

void red (){
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, rojo);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}

void yellow (){
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, amarillo);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}
void cerrar(){
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void T1(){
    glBegin(GL_POLYGON);	
	glNormal3f( -1.0f, 0.0f,0.0f);
	glTexCoord2f(0.0f, 0.0f);	
}
void T2(){
glTexCoord2f(4.0f, 0.0f);	
}
void T3(){
glTexCoord2f(4.0f, 4.0f);	
}
void T4(){
glTexCoord2f(0.0f, 4.0f);	
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
	glTexCoord2f(0.0f, 40.0f); glVertex3f(600, 80, 0.0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(600, 5, 0.0);
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
	glTexCoord2f(0.0f, 1.0f); glVertex3f(600, -7, 0.0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(600, 0, 0.0);
	
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
	glTexCoord2f(0.0f, 1.0f); glVertex3f(600, 5, 0.0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(600, 0, 0.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	
	}

void esce2(int x, int x1)
{	
	glPushMatrix();
	//cielo
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex8);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glBegin(GL_POLYGON);
	glNormal3f( 0.0f, -1.0f,0.0f);
	glTexCoord2f(100.0f, 0.0f); glVertex3f(x, 5, 0.0);
	glTexCoord2f(100.0f, 20.0f); glVertex3f(x, 80, 0);
	glTexCoord2f(0.0f, 20.0f); glVertex3f(x1, 80, 0.0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x1, 5, 0.0);
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
	glTexCoord2f(80.0f, 0.0f); glVertex3f(x, 0, 0.0);
	glTexCoord2f(80.0f, 1.0f); glVertex3f(x, -7, 0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x1, -7, 0.0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x1, 0, 0.0);
	
	glEnd();
	
	 glDisable(GL_TEXTURE_2D);
	 glPopMatrix();
	 glPushMatrix();
	 	//lava
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex4);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    //glTranslatef(0,0,0.0000001);
	glBegin(GL_POLYGON);	
	glNormal3f( -1.0f, 0.0f,0.0f);
	glTexCoord2f(400.0f, 0.0f); glVertex3f(x, 0, 0.0);
	glTexCoord2f(400.0f, 1.0f); glVertex3f(x, 5, 0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x1, 5, 0.0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x1, 0, 0.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	
	}

void piernasIzq(void){
	
	/////////////////////////////pierna lado izq////////////////////////////////////////////////////////////////////
	
	//orilla color negro de arriba a abajo y  de izq a der
	black();
	T1();glVertex3f(8,2,0);T2();glVertex3f(8,8,0);T3();glVertex3f(9,8,0);T4();glVertex3f(9,2,0);glEnd();
	
	T1();glVertex3f(9,1,0);T2();glVertex3f(9,2,0);T3();glVertex3f(10,2,0);T4();glVertex3f(10,1,0);glEnd();
	
	T1();glVertex3f(10,0,0);T2();glVertex3f(10,1,0);T3();glVertex3f(15,1,0);T4();glVertex3f(15,0,0);glEnd();
	
	T1();glVertex3f(14,1,0);T2();glVertex3f(14,2,0);T3();glVertex3f(15,2,0);T4();glVertex3f(15,1,0);glEnd();
	
	T1();glVertex3f(13,2,0);T2();glVertex3f(13,3,0);T3();glVertex3f(14,3,0);T4();glVertex3f(14,2,0);glEnd();
	
	T1();glVertex3f(12,3,0);T2();glVertex3f(12,8,0);T3();glVertex3f(13,8,0);T4();glVertex3f(13,3,0);glEnd();
	
	T1();glVertex3f(13,8,0);T2();glVertex3f(13,9,0);T3();glVertex3f(14,9,0);T4();glVertex3f(14,8,0);glEnd();
	//rodilla
	
	T1();glVertex3f(10,6,0);T2();glVertex3f(10,8,0);T3();glVertex3f(11,8,0);T4();glVertex3f(11,6,0);glEnd();
	
	T1();glVertex3f(11,6,0);T2();glVertex3f(11,7,0);T3();glVertex3f(12,7,0);T4();glVertex3f(12,6,0);glEnd();
	cerrar();
	
	//relleno color rojo
	red();
	T1();glVertex3f(11,7,0);T2();glVertex3f(11,8,0);T3();glVertex3f(12,8,0);T4();glVertex3f(12,7,0);glEnd();
	
	T1();glVertex3f(9,5,0);T2();glVertex3f(9,8,0);T3();glVertex3f(10,8,0);T4();glVertex3f(10,5,0);glEnd();
	
	T1();glVertex3f(10,5,0);T2();glVertex3f(10,6,0);T3();glVertex3f(12,6,0);T4();glVertex3f(12,5,0);glEnd();
	
	T1();glVertex3f(12,2,0);T2();glVertex3f(12,3,0);T3();glVertex3f(13,3,0);T4();glVertex3f(13,2,0);glEnd();
	
	T1();glVertex3f(11,1,0);T2();glVertex3f(11,2,0);T3();glVertex3f(14,2,0);T4();glVertex3f(14,1,0);glEnd();
	cerrar();
	
	//relleno color gris
	//color gris oscuro de izq a der
	gray();
	T1();glVertex3f(9,2,0);T2();glVertex3f(9,5,0);T3();glVertex3f(12,5,0);T4();glVertex3f(12,2,0);glEnd();
	
	T1();glVertex3f(10,1,0);T2();glVertex3f(10,2,0);T3();glVertex3f(11,2,0);T4();glVertex3f(11,1,0);glEnd();
	cerrar();
}
void piernaDer(void){
	
	/////////////////////////////pierna lado der/////////////////////////////////////////////
	
	//orilla color negro de arriba a abajo y  de izq a der
	
	//lo que se va  trasladar
	black();
	T1();glVertex3f(19,4,0);T2();glVertex3f(19,9,0);T3();glVertex3f(20,9,0);T4();glVertex3f(20,4,0);glEnd();
	
	T1();glVertex3f(20,3,0);T2();glVertex3f(20,4,0);T3();glVertex3f(21,4,0);T4();glVertex3f(21,3,0);glEnd();
	
	T1();glVertex3f(21,2,0);T2();glVertex3f(21,3,0);T3();glVertex3f(22,3,0);T4();glVertex3f(22,2,0);glEnd();
	
	T1();glVertex3f(17,1,0);T2();glVertex3f(17,2,0);T3();glVertex3f(22,2,0);T4();glVertex3f(22,1,0);glEnd();
	
	T1();glVertex3f(16,2,0);T2();glVertex3f(16,3,0);T3();glVertex3f(17,3,0);T4();glVertex3f(17,2,0);glEnd();
	
	T1();glVertex3f(15,3,0);T2();glVertex3f(15,9,0);T3();glVertex3f(16,9,0);T4();glVertex3f(16,3,0);glEnd();
	
	T1();glVertex3f(17,7,0);T2();glVertex3f(17,9,0);T3();glVertex3f(18,9,0);T4();glVertex3f(18,7,0);glEnd();

	T1();glVertex3f(18,7,0);T2();glVertex3f(18,8,0);T3();glVertex3f(19,8,0);T4();glVertex3f(19,7,0);glEnd();
	cerrar();
	
	//relleno color rojo
	red();
	T1();glVertex3f(18,8,0);T2();glVertex3f(18,9,0);T3();glVertex3f(19,9,0);T4();glVertex3f(19,8,0);glEnd();
	
	T1();glVertex3f(16,6,0);T2();glVertex3f(16,9,0);T3();glVertex3f(17,9,0);T4();glVertex3f(17,6,0);glEnd();
	
	T1();glVertex3f(17,6,0);T2();glVertex3f(17,7,0);T3();glVertex3f(19,7,0);T4();glVertex3f(19,6,0);glEnd();

	T1();glVertex3f(19,3,0);T2();glVertex3f(19,4,0);T3();glVertex3f(20,4,0);T4();glVertex3f(20,3,0);glEnd();
	
	T1();glVertex3f(18,2,0);T2();glVertex3f(18,3,0);T3();glVertex3f(21,3,0);T4();glVertex3f(21,2,0);glEnd();
	cerrar();
	
	//relleno color gris
	//color gris oscuro de izq a der
	gray();
	T1();glVertex3f(16,3,0);T2();glVertex3f(16,6,0);T3();glVertex3f(19,6,0);T4();glVertex3f(19,3,0);glEnd();
	
	T1();glVertex3f(17,2,0);T2();glVertex3f(17,3,0);T3();glVertex3f(18,3,0);T4();glVertex3f(18,2,0);glEnd();
	cerrar();
}
void cabeza(void){
	
	black();
	//orilla color negro de arriba a abajo y  de izq a der
	
	T1();glVertex3f(10,40,0);T2();glVertex3f(10,41,0);T3();glVertex3f(16,41,0);T4();glVertex3f(16,40,0);glEnd();
	
	T1();glVertex3f(8,39,0);T2();glVertex3f(8,40,0);T3();glVertex3f(10,40,0);T4();glVertex3f(10,39,0);glEnd();
	
	T1();glVertex3f(7,38,0);T2();glVertex3f(7,39,0);T3();glVertex3f(8,39,0);T4();glVertex3f(8,38,0);glEnd();
	
	T1();glVertex3f(6,36,0);T2();glVertex3f(6,38,0);T3();glVertex3f(7,38,0);T4();glVertex3f(7,36,0);glEnd();
	
	T1();glVertex3f(5,31,0);T2();glVertex3f(5,36,0);T3();glVertex3f(6,36,0);T4();glVertex3f(6,31,0);glEnd();
	
	T1();glVertex3f(6,29,0);T2();glVertex3f(6,31,0);T3();glVertex3f(7,31,0);T4();glVertex3f(7,29,0);glEnd();
	
	T1();glVertex3f(7,28,0);T2();glVertex3f(7,29,0);T3();glVertex3f(8,29,0);T4();glVertex3f(8,28,0);glEnd();
	
	T1();glVertex3f(8,27,0);T2();glVertex3f(8,28,0);T3();glVertex3f(9,28,0);T4();glVertex3f(9,27,0);glEnd();
	
	T1();glVertex3f(9,26,0);T2();glVertex3f(9,27,0);T3();glVertex3f(10,27,0);T4();glVertex3f(10,26,0);glEnd();
	
	T1();glVertex3f(10,25,0);T2();glVertex3f(10,26,0);T3();glVertex3f(12,26,0);T4();glVertex3f(12,25,0);glEnd();
	
	T1();glVertex3f(12,24,0);T2();glVertex3f(12,25,0);T3();glVertex3f(17,25,0);T4();glVertex3f(17,24,0);glEnd();
	
	T1();glVertex3f(17,25,0);T2();glVertex3f(17,26,0);T3();glVertex3f(18,26,0);T4();glVertex3f(18,25,0);glEnd();
	
	T1();glVertex3f(18,26,0);T2();glVertex3f(18,27,0);T3();glVertex3f(19,27,0);T4();glVertex3f(19,26,0);glEnd();
	
	T1();glVertex3f(19,27,0);T2();glVertex3f(19,30,0);T3();glVertex3f(20,30,0);T4();glVertex3f(20,27,0);glEnd();
	
	T1();glVertex3f(20,30,0);T2();glVertex3f(20,36,0);T3();glVertex3f(21,36,0);T4();glVertex3f(21,30,0);glEnd();
	
	T1();glVertex3f(19,36,0);T2();glVertex3f(19,38,0);T3();glVertex3f(20,38,0);T4();glVertex3f(20,36,0);glEnd();
	
	T1();glVertex3f(18,38,0);T2();glVertex3f(18,39,0);T3();glVertex3f(19,39,0);T4();glVertex3f(19,38,0);glEnd();
	
	T1();glVertex3f(16,39,0);T2();glVertex3f(16,40,0);T3();glVertex3f(18,40,0);T4();glVertex3f(18,39,0);glEnd();
	cerrar();
	
	/////////////////relleno color rojo de arriba hacia abajo 
	
	
	red();
	T1();glVertex3f(10,39,0);T2();glVertex3f(10,40,0);T3();glVertex3f(16,40,0);T4();glVertex3f(16,39,0);glEnd();
	
	T1();glVertex3f(8,38,0);T2();glVertex3f(8,39,0);T3();glVertex3f(18,39,0);T4();glVertex3f(18,38,0);glEnd();
	
	T1();glVertex3f(7,33,0);T2();glVertex3f(7,38,0);T3();glVertex3f(19,38,0);T4();glVertex3f(19,33,0);glEnd();
	
	T1();glVertex3f(6,31,0);T2();glVertex3f(6,36,0);T3();glVertex3f(7,36,0);T4();glVertex3f(7,31,0);glEnd();
	
	T1();glVertex3f(7,29,0);T2();glVertex3f(7,33,0);T3();glVertex3f(10,33,0);T4();glVertex3f(10,29,0);glEnd();
	
	T1();glVertex3f(10,32,0);T2();glVertex3f(10,33,0);T3();glVertex3f(11,33,0);T4();glVertex3f(11,32,0);glEnd();
	
	T1();glVertex3f(8,28,0);T2();glVertex3f(8,29,0);T3();glVertex3f(11,29,0);T4();glVertex3f(11,28,0);glEnd();
	
	T1();glVertex3f(9,27,0);T2();glVertex3f(9,28,0);T3();glVertex3f(12,28,0);T4();glVertex3f(12,27,0);glEnd();
	
	T1();glVertex3f(10,26,0);T2();glVertex3f(10,27,0);T3();glVertex3f(12,27,0);T4();glVertex3f(12,26,0);glEnd();
	
	T1();glVertex3f(12,25,0);T2();glVertex3f(12,27,0);T3();glVertex3f(17,27,0);T4();glVertex3f(17,25,0);glEnd();
	
	T1();glVertex3f(17,26,0);T2();glVertex3f(17,27,0);T3();glVertex3f(18,27,0);T4();glVertex3f(18,26,0);glEnd();
	
	T1();glVertex3f(16,27,0);T2();glVertex3f(16,28,0);T3();glVertex3f(19,28,0);T4();glVertex3f(19,27,0);glEnd();
	
	T1();glVertex3f(15,27,0);T2();glVertex3f(15,28,0);T3();glVertex3f(19,28,0);T4();glVertex3f(19,27,0);glEnd();
	
	T1();glVertex3f(16,28,0);T2();glVertex3f(16,33,0);T3();glVertex3f(18,33,0);T4();glVertex3f(18,28,0);glEnd();
	
	T1();glVertex3f(14,32,0);T2();glVertex3f(14,33,0);T3();glVertex3f(19,33,0);T4();glVertex3f(19,32,0);glEnd();
	
	T1();glVertex3f(19,33,0);T2();glVertex3f(19,36,0);T3();glVertex3f(20,36,0);T4();glVertex3f(20,33,0);glEnd();
	cerrar();
	
	//////////////////////////////////////ojos//////////////////////
	
	//ojo lado izq
	
	//color gris oscuro de izq a der
	gray();
	
	T1();glVertex3f(10,29,0);T2();glVertex3f(10,32,0);T3();glVertex3f(11,32,0);T4();glVertex3f(11,29,0);glEnd();
	
	T1();glVertex3f(11,28,0);T2();glVertex3f(11,33,0);T3();glVertex3f(12,33,0);T4();glVertex3f(12,28,0);glEnd();
	
	T1();glVertex3f(12,31,0);T2();glVertex3f(12,32,0);T3();glVertex3f(13,32,0);T4();glVertex3f(13,31,0);glEnd();
	
	T1();glVertex3f(12,27,0);T2();glVertex3f(12,29,0);T3();glVertex3f(14,29,0);T4();glVertex3f(14,27,0);glEnd();
	cerrar();
	
	//color gris oscuro de izq a der
	grayC();
	
	T1();glVertex3f(12,32,0);T2();glVertex3f(12,33,0);T3();glVertex3f(14,33,0);T4();glVertex3f(14,32,0);glEnd();
	
	T1();glVertex3f(13,31,0);T2();glVertex3f(13,32,0);T3();glVertex3f(14,32,0);T4();glVertex3f(14,31,0);glEnd();
	
	T1();glVertex3f(14,30,0);T2();glVertex3f(14,32,0);T3();glVertex3f(16,32,0);T4();glVertex3f(16,30,0);glEnd();
	
	T1();glVertex3f(15,28,0);T2();glVertex3f(15,30,0);T3();glVertex3f(16,30,0);T4();glVertex3f(16,28,0);glEnd();
	
	T1();glVertex3f(14,27,0);T2();glVertex3f(14,29,0);T3();glVertex3f(15,29,0);T4();glVertex3f(15,27,0);glEnd();
	cerrar();
	
	
	//ojo lado der
	//color gris oscuro de izq a der
	grayC();
	
	T1();glVertex3f(18,28,0);T2();glVertex3f(18,32,0);T3();glVertex3f(19,32,0);glVertex3f(19,28,0);glEnd();
	
	T1();glVertex3f(19,30,0);T2();glVertex3f(19,33,0);T3();glVertex3f(20,33,0);glVertex3f(20,30,0);glEnd();
	cerrar();
	
	
	}
void cuerpo(void){
	
	//////////////////////////////////////////////parte superior de las piernas orilla/////////////////////////////////////////////////
	black();
	
	T1();glVertex3f(8,8,0);T2();glVertex3f(8,14,0);T3();glVertex3f(9,14,0);T4();glVertex3f(9,8,0);glEnd();
	
	T1();glVertex3f(19,9,0);T2();glVertex3f(19,14,0);T3();glVertex3f(20,14,0);T4();glVertex3f(20,9,0);glEnd();
	
	T1();glVertex3f(15,9,0);T2();glVertex3f(15,12,0);T3();glVertex3f(16,12,0);T4();glVertex3f(16,9,0);glEnd();
	
	T1();glVertex3f(14,9,0);T2();glVertex3f(14,13,0);T3();glVertex3f(15,13,0);T4();glVertex3f(15,9,0);glEnd();
	
	T1();glVertex3f(16,12,0);T2();glVertex3f(16,13,0);T3();glVertex3f(17,13,0);T4();glVertex3f(17,12,0);glEnd();
	cerrar();
	//relleno color gris parte superior de las piernas
	
	//color gris "pierna lado izq"oscuro de arri  aba 
	gray();
	
	T1();glVertex3f(9,13,0);T2();glVertex3f(9,14,0);T3();glVertex3f(11,14,0);T4();glVertex3f(11,13,0);glEnd();
	
	T1();glVertex3f(9,12,0);T2();glVertex3f(9,13,0);T3();glVertex3f(10,13,0);T4();glVertex3f(10,12,0);glEnd();
	
	//color gris "pierna lado der"oscuro de arri  aba
	T1();glVertex3f(18,12,0);T2();glVertex3f(18,14,0);T3();glVertex3f(19,14,0);T4();glVertex3f(19,12,0);glEnd(); 
	cerrar();
	////////////////relleno color rojo de arriba hacia abajo 
	
	red();
	
	//superior
	T1();glVertex3f(11,13,0);T2();glVertex3f(11,14,0);T3();glVertex3f(18,14,0);T4();glVertex3f(18,13,0);glEnd();
	
	//pierna lado izq
    T1();glVertex3f(10,12,0);T2();glVertex3f(10,13,0);T3();glVertex3f(14,13,0);T4();glVertex3f(14,12,0);glEnd();
    
    T1();glVertex3f(9,11,0);T2();glVertex3f(9,12,0);T3();glVertex3f(14,12,0);T4();glVertex3f(14,11,0);glEnd();
    
    T1();glVertex3f(9,10,0);T2();glVertex3f(9,11,0);T3();glVertex3f(14,11,0);T4();glVertex3f(14,10,0);glEnd();
    
    T1();glVertex3f(9,9,0);T2();glVertex3f(9,10,0);T3();glVertex3f(14,10,0);T4();glVertex3f(14,9,0);glEnd();
    
    T1();glVertex3f(9,8,0);T2();glVertex3f(9,9,0);T3();glVertex3f(14,9,0);T4();glVertex3f(14,8,0);glEnd();
    
    //pierna lado der
    T1();glVertex3f(15,12,0);T2();glVertex3f(15,13,0);T3();glVertex3f(16,13,0);T4();glVertex3f(16,12,0);glEnd();
    
    T1();glVertex3f(17,12,0);T2();glVertex3f(17,13,0);T3();glVertex3f(18,13,0);T4();glVertex3f(18,12,0);glEnd();
    
    T1();glVertex3f(16,11,0);T2();glVertex3f(16,12,0);T3();glVertex3f(19,12,0);T4();glVertex3f(19,11,0);glEnd();
    
    T1();glVertex3f(16,10,0);T2();glVertex3f(16,11,0);T3();glVertex3f(19,11,0);T4();glVertex3f(19,10,0);glEnd();
    
    T1();glVertex3f(16,9,0);T2();glVertex3f(16,10,0);T3();glVertex3f(19,10,0);T4();glVertex3f(19,9,0);glEnd();
	cerrar();
	
	//////////////////////////orilla color negro///////////////////////
	black();
	//orilla izq
	T1();glVertex3f(9,14,0);T2();glVertex3f(9,16,0);T3();glVertex3f(10,16,0);T4();glVertex3f(10,14,0);glEnd();
    
    T1();glVertex3f(10,16,0);T2();glVertex3f(10,19,0);T3();glVertex3f(11,19,0);T4();glVertex3f(11,16,0);glEnd();
    
    T1();glVertex3f(11,17,0);T2();glVertex3f(11,18,0);T3();glVertex3f(12,18,0);T4();glVertex3f(12,17,0);glEnd();
    
    T1();glVertex3f(12,16,0);T2();glVertex3f(12,17,0);T3();glVertex3f(13,17,0);T4();glVertex3f(13,16,0);glEnd();
    
    T1();glVertex3f(8,19,0);T2();glVertex3f(8,20,0);T3();glVertex3f(10,20,0);T4();glVertex3f(10,19,0);glEnd();
    
    T1();glVertex3f(8,20,0);T2();glVertex3f(8,21,0);T3();glVertex3f(9,21,0);T4();glVertex3f(9,20,0);glEnd();
    
    T1();glVertex3f(9,21,0);T2();glVertex3f(9,22,0);T3();glVertex3f(10,22,0);T4();glVertex3f(10,21,0);glEnd();
    
    T1();glVertex3f(10,22,0);T2();glVertex3f(10,24,0);T3();glVertex3f(11,24,0);T4();glVertex3f(11,22,0);glEnd();
    
    T1();glVertex3f(11,21,0);T2();glVertex3f(11,22,0);T3();glVertex3f(13,22,0);T4();glVertex3f(13,21,0);glEnd();
    
    
    //orilla cinturon
    //verticales
    T1();glVertex3f(14,15,0);T2();glVertex3f(14,17,0);T3();glVertex3f(15,17,0);T4();glVertex3f(15,15,0);glEnd();
    
    T1();glVertex3f(18,15,0);T2();glVertex3f(18,17,0);T3();glVertex3f(19,17,0);T4();glVertex3f(19,15,0);glEnd();
    
    //horizontales
    T1();glVertex3f(15,17,0);T2();glVertex3f(15,18,0);T3();glVertex3f(18,18,0);T4();glVertex3f(18,17,0);glEnd();
    
    T1();glVertex3f(15,14,0);T2();glVertex3f(15,15,0);T3();glVertex3f(18,15,0);T4();glVertex3f(18,14,0);glEnd();
	
	//orilla derecha
	T1();glVertex3f(19,14,0);T2();glVertex3f(19,24,0);T3();glVertex3f(20,24,0);T4();glVertex3f(20,14,0);glEnd();
    
    T1();glVertex3f(18,21,0);T2();glVertex3f(18,22,0);T3();glVertex3f(19,22,0);T4();glVertex3f(19,21,0);glEnd();
    
    T1();glVertex3f(18,24,0);T2();glVertex3f(18,25,0);T3();glVertex3f(19,25,0);T4();glVertex3f(19,24,0);glEnd();
    cerrar();
    
    
    ////////////////////////////////////relleno color gris////////////////////////
    gray();
    //lado izq
    
    //los cuadros van de arriba hacia abajo
    T1();glVertex3f(10,24,0);T2();glVertex3f(10,25,0);T3();glVertex3f(12,25,0);T4();glVertex3f(12,24,0);glEnd();
    
    T1();glVertex3f(11,22,0);T2();glVertex3f(11,24,0);T3();glVertex3f(12,24,0);T4();glVertex3f(12,22,0);glEnd();
	
	T1();glVertex3f(10,19,0);T2();glVertex3f(10,21,0);T3();glVertex3f(13,21,0);T4();glVertex3f(13,19,0);glEnd();
	
	T1();glVertex3f(10,21,0);T2();glVertex3f(10,22,0);T3();glVertex3f(11,22,0);T4();glVertex3f(11,21,0);glEnd();
	
	T1();glVertex3f(9,20,0);T2();glVertex3f(9,21,0);T3();glVertex3f(10,21,0);T4();glVertex3f(10,20,0);glEnd();
	
	T1();glVertex3f(11,18,0);T2();glVertex3f(11,19,0);T3();glVertex3f(13,19,0);T4();glVertex3f(13,18,0);glEnd();
	
	T1();glVertex3f(12,17,0);T2();glVertex3f(12,18,0);T3();glVertex3f(13,18,0);T4();glVertex3f(13,17,0);glEnd();
	
	T1();glVertex3f(11,16,0);T2();glVertex3f(11,17,0);T3();glVertex3f(12,17,0);T4();glVertex3f(12,16,0);glEnd();
	
	T1();glVertex3f(13,16,0);T2();glVertex3f(13,17,0);T3();glVertex3f(14,17,0);T4();glVertex3f(14,16,0);glEnd();
	
	T1();glVertex3f(12,15,0);T2();glVertex3f(12,16,0);T3();glVertex3f(14,16,0);T4();glVertex3f(14,15,0);glEnd();
	
	T1();glVertex3f(10,14,0);T2();glVertex3f(10,16,0);T3();glVertex3f(12,16,0);T4();glVertex3f(12,14,0);glEnd();
	
	
	//lado derecho
	//los cuadros van de arriba hacia abajo
	T1();glVertex3f(18,22,0);T2();glVertex3f(18,24,0);T3();glVertex3f(19,24,0);T4();glVertex3f(19,22,0);glEnd();
	
	T1();glVertex3f(18,17,0);T2();glVertex3f(18,21,0);T3();glVertex3f(19,21,0);T4();glVertex3f(19,17,0);glEnd();
	
	T1();glVertex3f(18,14,0);T2();glVertex3f(18,15,0);T3();glVertex3f(19,15,0);T4();glVertex3f(19,14,0);glEnd();
	cerrar();
	
	/////////////////////////////relleno color rojo////////////////////
	red();
	//los cuadros van de arriba hacia abajo y de der a izq
	T1();glVertex3f(17,24,0);T2();glVertex3f(17,25,0);T3();glVertex3f(18,25,0);T4();glVertex3f(18,24,0);glEnd();
	
	T1();glVertex3f(13,18,0);T2();glVertex3f(13,24,0);T3();glVertex3f(18,24,0);T4();glVertex3f(18,18,0);glEnd();
	
	T1();glVertex3f(12,22,0);T2();glVertex3f(12,24,0);T3();glVertex3f(13,24,0);T4();glVertex3f(13,22,0);glEnd();
	
	T1();glVertex3f(13,17,0);T2();glVertex3f(13,18,0);T3();glVertex3f(15,18,0);T4();glVertex3f(15,17,0);glEnd();
	
	T1();glVertex3f(12,14,0);T2();glVertex3f(12,15,0);T3();glVertex3f(15,15,0);T4();glVertex3f(15,14,0);glEnd();
	
	
	//parte del cinturon
	T1();glVertex3f(16,15,0);T2();glVertex3f(16,17,0);T3();glVertex3f(17,17,0);T4();glVertex3f(17,15,0);glEnd();
	cerrar();
	
	
	////////////////////////////////////////////////////////mano izq//////////////////////////////////
	black();
	//orilla color negro de arriba a abajo
	
	T1();glVertex3f(7,26,0);T2();glVertex3f(7,27,0);T3();glVertex3f(8,27,0);T4();glVertex3f(8,26,0);glEnd();
	
	T1();glVertex3f(5,25,0);T2();glVertex3f(5,26,0);T3();glVertex3f(7,26,0);T4();glVertex3f(7,25,0);glEnd();
	
	T1();glVertex3f(5,23,0);T2();glVertex3f(5,25,0);T3();glVertex3f(6,25,0);T4();glVertex3f(6,23,0);glEnd();
	
	T1();glVertex3f(6,22,0);T2();glVertex3f(6,23,0);T3();glVertex3f(7,23,0);T4();glVertex3f(7,22,0);glEnd();
	
	T1();glVertex3f(4,21,0);T2();glVertex3f(4,23,0);T3();glVertex3f(5,23,0);T4();glVertex3f(5,21,0);glEnd();
	
	T1();glVertex3f(3,18,0);T2();glVertex3f(3,21,0);T3();glVertex3f(4,21,0);T4();glVertex3f(4,18,0);glEnd();
	
	T1();glVertex3f(2,12,0);T2();glVertex3f(2,18,0);T3();glVertex3f(3,18,0);T4();glVertex3f(3,12,0);glEnd();
	
	T1();glVertex3f(3,11,0);T2();glVertex3f(3,12,0);T3();glVertex3f(4,12,0);T4();glVertex3f(4,11,0);glEnd();
	
	T1();glVertex3f(4,10,0);T2();glVertex3f(4,11,0);T3();glVertex3f(7,11,0);T4();glVertex3f(7,10,0);glEnd();
	
	T1();glVertex3f(6,11,0);T2();glVertex3f(6,13,0);T3();glVertex3f(7,13,0);T4();glVertex3f(7,11,0);glEnd();
	
	T1();glVertex3f(7,11,0);T2();glVertex3f(7,12,0);T3();glVertex3f(8,12,0);T4();glVertex3f(8,11,0);glEnd();
	
	T1();glVertex3f(7,13,0);T2();glVertex3f(7,15,0);T3();glVertex3f(8,15,0);T4();glVertex3f(8,13,0);glEnd();
	
	T1();glVertex3f(6,15,0);T2();glVertex3f(6,18,0);T3();glVertex3f(7,18,0);T4();glVertex3f(7,15,0);glEnd();
	
	T1();glVertex3f(7,18,0);T2();glVertex3f(7,19,0);T3();glVertex3f(8,19,0);T4();glVertex3f(8,18,0);glEnd();
	cerrar();
	
	
	//relleno mano color gris de arriba hacia abajo
	gray();
	T1();glVertex3f(8,26,0);T2();glVertex3f(8,27,0);T3();glVertex3f(9,27,0);T4();glVertex3f(9,26,0);glEnd();
	
	T1();glVertex3f(7,22,0);T2();glVertex3f(7,26,0);T3();glVertex3f(10,26,0);T4();glVertex3f(10,22,0);glEnd();
	
	T1();glVertex3f(6,23,0);T2();glVertex3f(6,25,0);T3();glVertex3f(7,25,0);T4();glVertex3f(7,23,0);glEnd();
	
	T1();glVertex3f(5,22,0);T2();glVertex3f(5,23,0);T3();glVertex3f(6,23,0);T4();glVertex3f(6,22,0);glEnd();
	
	T1();glVertex3f(6,21,0);T2();glVertex3f(6,22,0);T3();glVertex3f(9,22,0);T4();glVertex3f(9,21,0);glEnd();
	
	T1();glVertex3f(7,20,0);T2();glVertex3f(7,21,0);T3();glVertex3f(8,21,0);T4();glVertex3f(8,20,0);glEnd();
	
	T1();glVertex3f(4,19,0);T2();glVertex3f(4,21,0);T3();glVertex3f(5,21,0);T4();glVertex3f(5,19,0);glEnd();
	
	T1();glVertex3f(5,18,0);T2();glVertex3f(5,20,0);T3();glVertex3f(6,20,0);T4();glVertex3f(6,18,0);glEnd();
	
	T1();glVertex3f(6,18,0);T2();glVertex3f(6,19,0);T3();glVertex3f(7,19,0);T4();glVertex3f(7,18,0);glEnd();
	
	T1();glVertex3f(3,15,0);T2();glVertex3f(3,16,0);T3();glVertex3f(6,16,0);T4();glVertex3f(6,15,0);glEnd();
	cerrar();
	
	//relleno mano color rojo de arriba hacia abajo
	red();
	T1();glVertex3f(5,20,0);T2();glVertex3f(5,22,0);T3();glVertex3f(6,22,0);T4();glVertex3f(6,20,0);glEnd();
	
	T1();glVertex3f(6,19,0);T2();glVertex3f(6,21,0);T3();glVertex3f(7,21,0);T4();glVertex3f(7,19,0);glEnd();
	
	T1();glVertex3f(7,19,0);T2();glVertex3f(7,20,0);T3();glVertex3f(8,20,0);T4();glVertex3f(8,19,0);glEnd();

	T1();glVertex3f(4,18,0);T2();glVertex3f(4,19,0);T3();glVertex3f(5,19,0);T4();glVertex3f(5,18,0);glEnd();
	
	T1();glVertex3f(3,16,0);T2();glVertex3f(3,18,0);T3();glVertex3f(6,18,0);T4();glVertex3f(6,16,0);glEnd();
	
	T1();glVertex3f(3,13,0);T2();glVertex3f(3,15,0);T3();glVertex3f(7,15,0);T4();glVertex3f(7,13,0);glEnd();
	
	T1();glVertex3f(3,12,0);T2();glVertex3f(3,13,0);T3();glVertex3f(6,13,0);T4();glVertex3f(6,12,0);glEnd();
	
	T1();glVertex3f(4,11,0);T2();glVertex3f(4,12,0);T3();glVertex3f(6,12,0);T4();glVertex3f(6,11,0);glEnd();
	
	T1();glVertex3f(7,12,0);T2();glVertex3f(7,13,0);T3();glVertex3f(8,13,0);T4();glVertex3f(8,12,0);glEnd();
	cerrar();
	
	/////////////////////////////////////////////mano der/////////////////////////////////////////////
	
	black();
	//orilla color negro de arriba a abajo
	
	T1();glVertex3f(20,18,0);T2();glVertex3f(20,21,0);T3();glVertex3f(21,21,0);T4();glVertex3f(21,18,0);glEnd();
	
	T1();glVertex3f(21,14,0);T2();glVertex3f(21,18,0);T3();glVertex3f(22,18,0);T4();glVertex3f(22,14,0);glEnd();
	
	T1();glVertex3f(22,10,0);T2();glVertex3f(22,14,0);T3();glVertex3f(23,14,0);T4();glVertex3f(23,10,0);glEnd();
	
	T1();glVertex3f(20,10,0);T2();glVertex3f(20,11,0);T3();glVertex3f(22,11,0);T4();glVertex3f(22,10,0);glEnd();
	
	T1();glVertex3f(20,11,0);T2();glVertex3f(20,13,0);T3();glVertex3f(21,13,0);T4();glVertex3f(21,11,0);glEnd();
	cerrar();
	
	//relleno mano color gris de arriba hacia abajo
	gray();
	T1();glVertex3f(20,17,0);T2();glVertex3f(20,18,0);T3();glVertex3f(21,18,0);T4();glVertex3f(21,17,0);glEnd();
	
	T1();glVertex3f(20,14,0);T2();glVertex3f(20,15,0);T3();glVertex3f(21,15,0);T4();glVertex3f(21,14,0);glEnd();
	cerrar();
	
	//relleno mano color rojo de arriba hacia abajo
	red();
	
	T1();glVertex3f(20,15,0);T2();glVertex3f(20,17,0);T3();glVertex3f(21,17,0);T4();glVertex3f(21,15,0);glEnd();
	
	T1();glVertex3f(20,13,0);T2();glVertex3f(20,14,0);T3();glVertex3f(22,14,0);T4();glVertex3f(22,13,0);glEnd();
	
	T1();glVertex3f(21,11,0);T2();glVertex3f(21,13,0);T3();glVertex3f(22,13,0);T4();glVertex3f(22,11,0);glEnd();
	cerrar();
	
	//////////////////////////////////////////////////espada/////////////////////////////////////////////
	
	black();
	//orilla color negro de arriba a abajo //parte superior//
	
	T1();glVertex3f(1,30,0);T2();glVertex3f(1,31,0);T3();glVertex3f(2,31,0);T4();glVertex3f(2,30,0);glEnd();
	
	T1();glVertex3f(2,29,0);T2();glVertex3f(2,30,0);T3();glVertex3f(3,30,0);T4();glVertex3f(3,29,0);glEnd();
	
	T1();glVertex3f(3,28,0);T2();glVertex3f(3,29,0);T3();glVertex3f(4,29,0);T4();glVertex3f(4,28,0);glEnd();
	
	T1();glVertex3f(4,27,0);T2();glVertex3f(4,28,0);T3();glVertex3f(5,28,0);T4();glVertex3f(5,27,0);glEnd();
	
	T1();glVertex3f(5,26,0);T2();glVertex3f(5,27,0);T3();glVertex3f(6,27,0);T4();glVertex3f(6,26,0);glEnd();
	
	
	//orilla color negro de arriba a abajo //parte inferior//
	
	T1();glVertex3f(0,29,0);T2();glVertex3f(0,31,0);T3();glVertex3f(1,31,0);T4();glVertex3f(1,29,0);glEnd();
	
	T1();glVertex3f(1,28,0);T2();glVertex3f(1,29,0);T3();glVertex3f(2,29,0);T4();glVertex3f(2,28,0);glEnd();
	
	T1();glVertex3f(2,27,0);T2();glVertex3f(2,28,0);T3();glVertex3f(3,28,0);T4();glVertex3f(3,27,0);glEnd();
	
	T1();glVertex3f(3,26,0);T2();glVertex3f(3,27,0);T3();glVertex3f(4,27,0);T4();glVertex3f(4,26,0);glEnd();
	
	T1();glVertex3f(4,25,0);T2();glVertex3f(4,26,0);T3();glVertex3f(5,26,0);T4();glVertex3f(5,25,0);glEnd();
	cerrar();
	
	//relleno espada
	 	
	brown();
	T1();glVertex3f(1,29,0);T2();glVertex3f(1,30,0);T3();glVertex3f(2,30,0);T4();glVertex3f(2,29,0);glEnd();
	
	T1();glVertex3f(2,28,0);T2();glVertex3f(2,29,0);T3();glVertex3f(3,29,0);T4();glVertex3f(3,28,0);glEnd();
	
	T1();glVertex3f(3,27,0);T2();glVertex3f(3,28,0);T3();glVertex3f(4,28,0);T4();glVertex3f(4,27,0);glEnd();
	
	T1();glVertex3f(4,26,0);T2();glVertex3f(4,27,0);T3();glVertex3f(5,27,0);T4();glVertex3f(5,26,0);glEnd();
	cerrar();
}

void esfera (float r)
{
	glutSolidSphere(r,100,100);
}
void TUX(void){
	
	
	//Pata Izquierda
	yellow();
	T1();glVertex3f(0,3,0);T2();glVertex3f(1,3,0);T3();glVertex3f(1,5,0);T4();glVertex3f(0,5,0);glEnd();
			
	T1();;glVertex3f(1,2,0);T2();glVertex3f(10,2,0);T3();glVertex3f(10,12,0);T4();glVertex3f(1,12,0);glEnd();		
			
	T1();glVertex3f(4,1,0);T2();glVertex3f(15,1,0);T3();glVertex3f(15,2,0);T4();glVertex3f(4,2,0);glEnd();		
			
	T1();glVertex3f(9,0,0);T2();glVertex3f(14,0,0);T3();glVertex3f(14,1,0);T4();glVertex3f(9,1,0);glEnd();		

	T1();glVertex3f(10,1,0);T2();glVertex3f(15,1,0);T3();glVertex3f(15,4,0);T4();glVertex3f(10,4,0);glEnd();		

	T1();glVertex3f(10,4,0);T2();glVertex3f(14,4,0);T3();glVertex3f(14,6,0);T4();glVertex3f(10,6,0);glEnd();		

	T1();glVertex3f(10,6,0);T2();glVertex3f(13,6,0);T3();glVertex3f(13,7,0);T4();glVertex3f(10,7,0);glEnd();		

	T1();glVertex3f(10,7,0);T2();glVertex3f(12,7,0);T3();glVertex3f(12,8,0);T4();glVertex3f(10,8,0);glEnd();		
	
	T1();glVertex3f(10,8,0);T2();glVertex3f(11,8,0);T3();glVertex3f(11,11,0);T4();glVertex3f(10,11,0);glEnd();		
	
	T1();glVertex3f(5,12,0);T2();glVertex3f(10,12,0);T3();glVertex3f(10,13,0);T4();glVertex3f(5,13,0);glEnd();		
	
	T1();glVertex3f(6,13,0);T2();glVertex3f(10,13,0);T3();glVertex3f(10,14,0);T4();glVertex3f(6,14,0);glEnd();		
	
	T1();glVertex3f(6,14,0);T2();glVertex3f(8,14,0);T3();glVertex3f(8,15,0);T4();glVertex3f(6,15,0);glEnd();		
	
	//Pata Derecha
	
	T1();glVertex3f(27,1,0);T2();glVertex3f(28,1,0);T3();glVertex3f(28,6,0);T4();glVertex3f(27,6,0);glEnd();
	
	T1();glVertex3f(28,1,0);T2();glVertex3f(34,1,0);T3();glVertex3f(34,0,0);T4();glVertex3f(28,0,0);glEnd();
	
	T1();glVertex3f(28,1,0);T2();glVertex3f(35,1,0);T3();glVertex3f(35,11,0);T4();glVertex3f(28,11,0);glEnd();

	T1();glVertex3f(28,11,0);T2();glVertex3f(31,11,0);T3();glVertex3f(31,14,0);T4();glVertex3f(28,14,0);glEnd();
	
	T1();glVertex3f(35,2,0);T2();glVertex3f(37,2,0);T3();glVertex3f(37,12,0);T4();glVertex3f(35,12,0);glEnd();
	
	T1();glVertex3f(37,3,0);T2();glVertex3f(38,3,0);T3();glVertex3f(38,13,0);T4();glVertex3f(37,13,0);glEnd();
	
	T1();glVertex3f(38,4,0);T2();glVertex3f(40,4,0);T3();glVertex3f(40,9,0);T4();glVertex3f(38,9,0);glEnd();
	
	T1();glVertex3f(40,5,0);T2();glVertex3f(41,5,0);T3();glVertex3f(41,8,0);T4();glVertex3f(40,8,0);glEnd();
	
	T1();glVertex3f(38,9,0);T2();glVertex3f(39,9,0);T3();glVertex3f(39,10,0);T4();glVertex3f(38,10,0);glEnd();
	
	T1();glVertex3f(36,12,0);T2();glVertex3f(37,12,0);T3();glVertex3f(37,13,0);T4();glVertex3f(36,13,0);glEnd();
	
	//BOCA
	T1();glVertex3f(15,33,0);T2();glVertex3f(25,33,0);T3();glVertex3f(25,36,0);T4();glVertex3f(15,36,0);glEnd();
	
	T1();glVertex3f(16,33,0);T2();glVertex3f(24,33,0);T3();glVertex3f(24,32,0);T4();glVertex3f(16,32,0);glEnd();
	
	T1();glVertex3f(17,32,0);T2();glVertex3f(23,32,0);T3();glVertex3f(23,31,0);T4();glVertex3f(17,31,0);glEnd();
	
	T1();glVertex3f(16,36,0);T2();glVertex3f(23,36,0);T3();glVertex3f(23,37,0);T4();glVertex3f(16,37,0);glEnd();
	
	T1();glVertex3f(18,37,0);T2();glVertex3f(21,37,0);T3();glVertex3f(21,38,0);T4();glVertex3f(18,38,0);glEnd();
	cerrar();
	
	
	//Estomago
	white();
	T1();glVertex3f(14,7,0);T2();glVertex3f(27,7,0);T3();glVertex3f(27,30,0);T4();glVertex3f(14,30,0);glEnd();
	
	T1();glVertex3f(15,30,0);T2();glVertex3f(26,30,0);T3();glVertex3f(26,31,0);T4();glVertex3f(15,31,0);glEnd();
	
	T1();glVertex3f(15,31,0);T2();glVertex3f(17,31,0);T3();glVertex3f(17,32,0);T4();glVertex3f(15,32,0);glEnd();
	
	T1();glVertex3f(15,32,0);T2();glVertex3f(16,32,0);T3();glVertex3f(16,33,0);T4();glVertex3f(15,33,0);glEnd();
	
	T1();glVertex3f(13,6,0);T2();glVertex3f(25,6,0);T3();glVertex3f(25,7,0);T4();glVertex3f(13,7,0);glEnd();
	
	T1();glVertex3f(14,5,0);T2();glVertex3f(24,5,0);T3();glVertex3f(24,6,0);T4();glVertex3f(14,6,0);glEnd();
	
	T1();glVertex3f(16,4,0);T2();glVertex3f(21,4,0);T3();glVertex3f(21,5,0);T4();glVertex3f(16,5,0);glEnd();
	
	T1();glVertex3f(13,10,0);T2();glVertex3f(14,10,0);T3();glVertex3f(14,30,0);T4();glVertex3f(13,30,0);glEnd();
	
	T1();glVertex3f(12,11,0);T2();glVertex3f(13,11,0);T3();glVertex3f(13,28,0);T4();glVertex3f(12,28,0);glEnd();
	
	T1();glVertex3f(11,12,0);T2();glVertex3f(12,12,0);T3();glVertex3f(12,24,0);T4();glVertex3f(11,24,0);glEnd();
	
	T1();glVertex3f(10,14,0);T2();glVertex3f(11,14,0);T3();glVertex3f(11,20,0);T4();glVertex3f(10,20,0);glEnd();
	
	T1();glVertex3f(22,31,0);T2();glVertex3f(25,31,0);T3();glVertex3f(25,32,0);T4();glVertex3f(22,32,0);glEnd();
	
	T1();glVertex3f(24,32,0);T2();glVertex3f(25,32,0);T3();glVertex3f(25,33,0);T4();glVertex3f(24,33,0);glEnd();
	
	T1();glVertex3f(27,12,0);T2();glVertex3f(28,12,0);T3();glVertex3f(28,26,0);T4();glVertex3f(27,26,0);glEnd();
	
	T1();glVertex3f(28,14,0);T2();glVertex3f(29,14,0);T3();glVertex3f(29,25,0);T4();glVertex3f(28,25,0);glEnd();
	
	T1();glVertex3f(29,14,0);T2();glVertex3f(30,14,0);T3();glVertex3f(30,24,0);T4();glVertex3f(29,24,0);glEnd();
	
	T1();glVertex3f(30,15,0);T2();glVertex3f(31,15,0);T3();glVertex3f(31,23,0);T4();glVertex3f(30,23,0);glEnd();
	
	T1();glVertex3f(31,16,0);T2();glVertex3f(32,16,0);T3();glVertex3f(32,21,0);T4();glVertex3f(31,21,0);glEnd();
	
	T1();glVertex3f(32,17,0);T2();glVertex3f(33,17,0);T3();glVertex3f(33,19,0);T4();glVertex3f(32,19,0);glEnd();
	
	
	//OJOS
	
	T1();glVertex3f(14,36,0);T2();glVertex3f(16,36,0);T3();glVertex3f(16,37,0);T4();glVertex3f(14,37,0);glEnd();
	
	T1();glVertex3f(14,36,0);T2();glVertex3f(15,36,0);T3();glVertex3f(15,41,0);T4();glVertex3f(14,41,0);glEnd();
	
	T1();glVertex3f(17,40,0);T2();glVertex3f(18,40,0);T3();glVertex3f(18,37,0);T4();glVertex3f(17,37,0);glEnd();
	
	T1();glVertex3f(14,40,0);T2();glVertex3f(18,40,0);T3();glVertex3f(18,41,0);T4();glVertex3f(14,41,0);glEnd();
	
	T1();glVertex3f(15,41,0);T2();glVertex3f(17,41,0);T3();glVertex3f(17,42,0);T4();glVertex3f(15,42,0);glEnd();
	
	
	T1();glVertex3f(21,37,0);T2();glVertex3f(22,37,0);T3();glVertex3f(22,41,0);T4();glVertex3f(21,41,0);glEnd();
	
	T1();glVertex3f(22,40,0);T2();glVertex3f(24,40,0);T3();glVertex3f(24,42,0);T4();glVertex3f(22,42,0);glEnd();
	
	T1();glVertex3f(24,41,0);T2();glVertex3f(25,41,0);T3();glVertex3f(25,36,0);T4();glVertex3f(24,36,0);glEnd();
	
	T1();glVertex3f(23,36,0);T2();glVertex3f(24,36,0);T3();glVertex3f(24,37,0);T4();glVertex3f(23,37,0);glEnd();
	cerrar();


	//NEGRURA
	black();
	T1();glVertex3f(15,1,0);T2();glVertex3f(27,1,0);T3();glVertex3f(27,4,0);T4();glVertex3f(15,4,0);glEnd();
	
	T1();glVertex3f(14,4,0);T2();glVertex3f(16,4,0);T3();glVertex3f(16,5,0);T4();glVertex3f(14,5,0);glEnd();
	
	T1();glVertex3f(21,4,0);T2();glVertex3f(27,4,0);T3();glVertex3f(27,5,0);T4();glVertex3f(21,5,0);glEnd();
	
	T1();glVertex3f(24,5,0);T2();glVertex3f(27,5,0);T3();glVertex3f(27,6,0);T4();glVertex3f(24,6,0);glEnd();
	
	T1();glVertex3f(25,6,0);T2();glVertex3f(28,6,0);T3();glVertex3f(28,7,0);T4();glVertex3f(25,7,0);glEnd();
	
	T1();glVertex3f(27,7,0);T2();glVertex3f(28,7,0);T3();glVertex3f(28,12,0);T4();glVertex3f(27,12,0);glEnd();
	
	T1();glVertex3f(30,14,0);T2();glVertex3f(31,14,0);T3();glVertex3f(31,15,0);T4();glVertex3f(30,15,0);glEnd();
	
	T1();glVertex3f(31,11,0);T2();glVertex3f(32,11,0);T3();glVertex3f(32,16,0);T4();glVertex3f(31,16,0);glEnd();
	
	T1();glVertex3f(32,11,0);T2();glVertex3f(33,11,0);T3();glVertex3f(33,17,0);T4();glVertex3f(32,17,0);glEnd();
	
	T1();glVertex3f(33,11,0);T2();glVertex3f(34,11,0);T3();glVertex3f(34,28,0);T4();glVertex3f(33,28,0);glEnd();
	
	T1();glVertex3f(34,11,0);T2();glVertex3f(35,11,0);T3();glVertex3f(35,27,0);T4();glVertex3f(34,27,0);glEnd();
	
	T1();glVertex3f(35,12,0);T2();glVertex3f(36,12,0);T3();glVertex3f(36,24,0);T4();glVertex3f(35,24,0);glEnd();
	
	T1();glVertex3f(36,13,0);T2();glVertex3f(37,13,0);T3();glVertex3f(37,22,0);T4();glVertex3f(36,22,0);glEnd();
	
	T1();glVertex3f(37,15,0);T2();glVertex3f(38,15,0);T3();glVertex3f(38,20,0);T4();glVertex3f(37,20,0);glEnd();
	
	T1();glVertex3f(32,19,0);T2();glVertex3f(33,19,0);T3();glVertex3f(33,28,0);T4();glVertex3f(32,28,0);glEnd();
	
	T1();glVertex3f(31,21,0);T2();glVertex3f(32,21,0);T3();glVertex3f(32,30,0);T4();glVertex3f(31,30,0);glEnd();
	
	T1();glVertex3f(30,23,0);T2();glVertex3f(31,23,0);T3();glVertex3f(31,32,0);T4();glVertex3f(30,32,0);glEnd();
	
	T1();glVertex3f(29,24,0);T2();glVertex3f(30,24,0);T3();glVertex3f(30,35,0);T4();glVertex3f(29,35,0);glEnd();
	
	T1();glVertex3f(28,25,0);T2();glVertex3f(29,25,0);T3();glVertex3f(29,42,0);T4();glVertex3f(28,42,0);glEnd();
	
	T1();glVertex3f(27,26,0);T2();glVertex3f(28,26,0);T3();glVertex3f(28,45,0);T4();glVertex3f(27,45,0);glEnd();
	
	T1();glVertex3f(26,30,0);T2();glVertex3f(27,30,0);T3();glVertex3f(27,47,0);T4();glVertex3f(26,47,0);glEnd();
	
	T1();glVertex3f(25,31,0);T2();glVertex3f(26,31,0);T3();glVertex3f(26,47,0);T4();glVertex3f(25,47,0);glEnd();
	
	T1();glVertex3f(24,41,0);T2();glVertex3f(25,41,0);T3();glVertex3f(25,49,0);T4();glVertex3f(24,49,0);glEnd();
	
	T1();glVertex3f(22,42,0);T2();glVertex3f(24,42,0);T3();glVertex3f(24,49,0);T4();glVertex3f(22,49,0);glEnd();
	
	T1();glVertex3f(21,41,0);T2();glVertex3f(22,41,0);T3();glVertex3f(22,50,0);T4();glVertex3f(21,50,0);glEnd();
	
	T1();glVertex3f(18,38,0);T2();glVertex3f(21,38,0);T3();glVertex3f(21,50,0);T4();glVertex3f(18,50,0);glEnd();
	
	T1();glVertex3f(22,37,0);T2();glVertex3f(24,37,0);T3();glVertex3f(24,40,0);T4();glVertex3f(22,40,0);glEnd();
	
	T1();glVertex3f(15,37,0);T2();glVertex3f(17,37,0);T3();glVertex3f(17,40,0);T4();glVertex3f(15,40,0);glEnd();
	
	T1();glVertex3f(17,41,0);T2();glVertex3f(18,41,0);T3();glVertex3f(18,49,0);T4();glVertex3f(17,49,0);glEnd();
	
	T1();glVertex3f(15,42,0);T2();glVertex3f(17,42,0);T3();glVertex3f(17,48,0);T4();glVertex3f(15,48,0);glEnd();
	
	T1();glVertex3f(14,41,0);T2();glVertex3f(15,41,0);T3();glVertex3f(15,45,0);T4();glVertex3f(14,45,0);glEnd();
	
	T1();glVertex3f(13,33,0);T2();glVertex3f(14,33,0);T3();glVertex3f(14,43,0);T4();glVertex3f(13,43,0);glEnd();
	
	T1();glVertex3f(12,36,0);T2();glVertex3f(13,36,0);T3();glVertex3f(13,42,0);T4();glVertex3f(12,42,0);glEnd();
	
	T1();glVertex3f(14,30,0);T2();glVertex3f(15,30,0);T3();glVertex3f(15,36,0);T4();glVertex3f(14,36,0);glEnd();
	
	T1();glVertex3f(13,28,0);T2();glVertex3f(14,28,0);T3();glVertex3f(14,31,0);T4();glVertex3f(13,31,0);glEnd();
	
	T1();glVertex3f(12,25,0);T2();glVertex3f(13,25,0);T3();glVertex3f(13,30,0);T4();glVertex3f(12,30,0);glEnd();
	
	T1();glVertex3f(11,22,0);T2();glVertex3f(12,22,0);T3();glVertex3f(12,28,0);T4();glVertex3f(11,28,0);glEnd();
	
	T1();glVertex3f(10,20,0);T2();glVertex3f(11,20,0);T3();glVertex3f(11,27,0);T4();glVertex3f(10,27,0);glEnd();
	
	T1();glVertex3f(9,14,0);T2();glVertex3f(10,14,0);T3();glVertex3f(10,25,0);T4();glVertex3f(9,25,0);glEnd();
	
	T1();glVertex3f(8,14,0);T2();glVertex3f(9,14,0);T3();glVertex3f(9,23,0);T4();glVertex3f(8,23,0);glEnd();
	
	T1();glVertex3f(7,15,0);T2();glVertex3f(8,15,0);T3();glVertex3f(8,20,0);T4();glVertex3f(7,20,0);glEnd();
	
	T1();glVertex3f(6,15,0);T2();glVertex3f(7,15,0);T3();glVertex3f(7,18,0);T4();glVertex3f(6,18,0);glEnd();
	
	T1();glVertex3f(10,11,0);T2();glVertex3f(11,11,0);T3();glVertex3f(11,14,0);T4();glVertex3f(10,14,0);glEnd();
	
	T1();glVertex3f(11,8,0);T2();glVertex3f(12,8,0);T3();glVertex3f(12,12,0);T4();glVertex3f(11,12,0);glEnd();
	
	T1();glVertex3f(12,7,0);T2();glVertex3f(13,7,0);T3();glVertex3f(13,11,0);T4();glVertex3f(12,11,0);glEnd();
	
	T1();glVertex3f(13,7,0);T2();glVertex3f(14,7,0);T3();glVertex3f(14,10,0);T4();glVertex3f(13,10,0);glEnd();
	cerrar();
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
    
    glTranslatef(50,7,0);
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
	tex1 = loadTex("../img/fondo.png");
    tex2 = loadTex("../img/sue.png");
    tex3 = loadTex("../img/gra1.png");
    tex4 = loadTex("../img/troco.jpg");
    tex5 = loadTex("../img/orilla.png");
    tex6 = loadTex("../img/barril.png");
    tex7 = loadTex("../img/ball.jpg");
    tex8 = loadTex("../img/estre1.jpg");    
    negro = loadTex("../TexturaD/negro.png"); 
    gris= loadTex("../TexturaD/gris.png");
    cafe = loadTex("../TexturaD/cafe.png");
    grisclaro = loadTex("../TexturaD/grisClaro.png");
    rojo = loadTex("../TexturaD/Rojo.png");
    blanco = loadTex("../TexturaD/blanco.png");
    amarillo = loadTex("../TexturaD/ama.png");
    
}
void display()
{
	//glClearColor(1,1,1,1);
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

    glEnable(GL_LIGHT0);
    //glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    //glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    //glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glTranslatef(X,0.0f,0.0f);

////////////////////////escenario de el fondo//////////////////////////////
	

	glPushMatrix();
	esce();
	glPopMatrix();
	glPushMatrix();
	esce2(600,1200);
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

	//glTranslatef(0,4.25,0.50);
	double j1=0, cor1=20;
    for(j1=0;j1<=3;j1+=1){
	//pino grande
	glPushMatrix();
    glTranslatef(cor1,4.25,1.50);
    pinos(2.75,5.0,10,30);
    glPopMatrix();
    //pino pequeño
	glPushMatrix();
    glTranslatef(60+cor1,4.25,1.50);
    pinos(1.75,3.7,7,18);
    glPopMatrix();
    cor1+=185;
    }
	int ba[8]={};
 	int j12=0, cor12=135;
    for(j12=0;j12<=8;j12+=1){
    //Barril
	glPushMatrix();
    glTranslatef(cor12+16,3.0,1.50);
    barril(3.5,8.0);
    glPopMatrix();
    ba[j12]={cor12};    
    cor12+=165;
  
    }
   
	int pe[8]={};
    int j123=0, cor123=217;
    for(j123=0;j123<=8;j123+=1){
    //Balon
    glPushMatrix();
   // glTranslatef(X,0,0);
    glTranslated(cor123 -37,-1.0,1.50);
    glRotatef(yrot, 0, 1, 0);
    pelota(3.0);
    glPopMatrix(); 
    pe[j123]={cor123};    
	cor123+=175;
    } 
	 for(int k =0; k<7; k++)
    { 
		if((-X)==ba[k] || (-X)==pe[k])
		{	
			//pauseAnimation();
			//pauseAnimation2();
			//printf("%s\n","jodido");
			//printf("%u\n",pe[k]);
			//printf("%u\n",ba[k]);
			}
		// printf("%u\n",pe[k]);
		//break;
	}
	    
	glLineWidth(5);
    glCallList(1);
    glPushMatrix();
    glTranslatef(-X,0,zoom1);
    Text();
    //glCallList(texto);
    glPopMatrix();
    
    int pingui[8]={};
    int j1234=0, cor1234=270;
    for(j1234=0;j1234<=8;j1234+=1){
    //mascota
    glPushMatrix();
   // glTranslatef(X,0,0);
    glTranslated(cor1234 -30,3.0,1.50);
    glScalef(0.2,0.2,0.2);
    TUX();
    glPopMatrix(); 
    pingui[j1234]={cor1234};    
	cor1234+=175;
    } 
    

    glTranslatef(-1*X,1.50,2.50);
    //pe[4]={-X};
    //Agregar Codigo acá, para dibujar
    glPushMatrix();
		glTranslatef(0, TrasladarSalto, 1.50);
		
		glScalef(0.5,0.5,0.5);
		glPushMatrix();
		glTranslatef(0, -trasladarIzq/6, 1.50);
		cabeza();
		glPopMatrix();
		cuerpo();
		glPushMatrix();
		glTranslatef(0, trasladarIzq, 1.50); 
		piernasIzq();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0,  -trasladarDer+4, 1.50); 
		piernaDer();
		glPopMatrix();
    
    glPopMatrix();
    
    
	glFlush();
	glutSwapBuffers();

}

// --------------- Para animación  ------------------------------------------

int animating = 0;      // 0 sin animación
int animating1 = 0;      // 0 sin animación
int animating2 = 0;      // 0 sin animación
                        // Se cambia con la llamada a las funciones startAnimation() and pauseAnimation()

void pauseAnimation() {
        // Llamamo a la función para detener la animación
        animating = 0;
}
void pauseAnimation1() {
        // Llamamo a la función para detener la animación
        animating1 = 0;
}
void pauseAnimation2() {
        // Llamamo a la función para detener la animación
        animating2 = 0;
}
void updateFrame() {
        // En esta funcion agregamos el codigo que hara la secuencia de cada escena como si fuera un fotograma

        for (int i=1; i<=1; i++) {
			
			X-=5.0;
			//x1rot+=1;
		
               // rotateY=rotateY-= i;
        }
        //Verificamos el numero de frames para detener animación
        if(frameNumber==2000)
        {
                pauseAnimation();
                pauseAnimation1();
                //si se detiene la animacion detenemos el audio
                //SDL_PauseAudio(1);
                frameNumber=0;
                X=0;
        }
        //Almacenamos el numero de frames
        frameNumber++;
        x1rot=frameNumber;
       // printf ("Numero de Frame: %d \n", frameNumber);
}

void updateFrame1() {
        // En esta funcion agregamos el codigo que hara la secuencia de cada escena como si fuera un fotograma
     
        if (saltar<11){
		TrasladarSalto+= 2;
		
    }
   //Verificamos el numero de frames para detener animación 
   else if(saltar>=11){
		TrasladarSalto-= 2;  
		if(saltar==20){
			TrasladarSalto=0;
			saltar=0;
			startAnimation2();
			pauseAnimation1();
			}
	}
  //Almacenamos el numero de frames 
  saltar++;
 // printf ("Numero de Frame: %d \n", saltar);
}

void updateFrame2() {
    for (int j=0; j<=2; j++){
        trasladarIzq+= j;
        trasladarDer+= j;
    }
    //Verificamos el numero de frames para detener animación 
    if(frameN==2){
        trasladarIzq= 0;
        trasladarDer= 0;
        frameN=0;
    }
    //Almacenamos el numero de frames 
    frameN++;
    //Verificamos el numero de frames para detener animación
    if(frameN==2000){
        pauseAnimation2();
        //si se detiene la animacion detenemos el audio
        //SDL_PauseAudio(1);
        frameN=0;
        X=0;
    }
}


void timerFunction(int timerID) {
        // Invocamos la funcion para controlar el tiempo de la ejecucion de funciones
        if (animating) {
                updateFrame();
                glutTimerFunc(30, timerFunction, 0);
                glutPostRedisplay();
        }
}

void timerFunction1(int timerID2) {
        // Invocamos la funcion para controlar el tiempo de la ejecucion de funciones
        if (animating1) {
            updateFrame1();
            glutTimerFunc(10, timerFunction1, 2);
            glutPostRedisplay();
        }
}

void timerFunction2(int timerID3) {
        // Invocamos la funcion para controlar el tiempo de la ejecucion de funciones
        if (animating2) {
            updateFrame2();
            glutTimerFunc(10, timerFunction2, 2);
            glutPostRedisplay();
        }
}

void startAnimation() {
        // llamamos la función para iniciar la animación
        if ( !animating ) {
                animating = 1;
                glutTimerFunc(30, timerFunction, 1);
                //glutTimerFunc(210, timerFunction1, 1);
        }
}
void startAnimation1() {
        // llamamos la función para iniciar la animación
        if ( !animating1 ) {
                animating1 = 1;
                glutTimerFunc(30, timerFunction1, 3);
        }
}

void startAnimation2() {
        // llamamos la función para iniciar la animación
        if ( !animating2 ) {
                animating2 = 1;
                glutTimerFunc(30, timerFunction2, 3);
        }
}


void specialKeys( int key, int x, int y )
{

	//Mov Pelota, Proximamente de la figura
	if (key == GLUT_KEY_RIGHT){
		yrot -=20.0;
        PX += 4.0f;
	}

	else if (key == GLUT_KEY_LEFT){
		yrot -=20.0;
        PX += 4.0f;
	}
	else if (key == GLUT_KEY_UP){
        startAnimation1();
        startAnimation();
         pauseAnimation2();
         X=X-1;
         }
	else if (key == GLUT_KEY_DOWN){
        TrasladarSalto=0;}
	//  Tecla especial F2 : rotación en eje Z positivo 7 grados
    /*
	else if (key == GLUT_KEY_F2)
									rotate_z += 7;
	//  Tecla especial F2 : rotación en eje Z negativo 7 grados
	else if (key == GLUT_KEY_F2)
									rotate_z -= 7;*/
	else if (key == GLUT_KEY_HOME){
		PX=60;
		X=0;
		x1rot=0;
		frameNumber=0;
	}
									

	//  Solicitar actualización de visualización
	glutPostRedisplay();

}

void key(unsigned char key, int x, int y) {
    // La animación inicia al presionar la tecla espaciadora de igual forma se detiene
    if ( key == ' ' && animating==1) {
        pauseAnimation();
        pauseAnimation2();
    }
    else{
        startAnimation();
        startAnimation2();
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
    glShadeModel(GL_SMOOTH);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_LIGHT0);
}
	
void resize(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-0,(Z),-7,80,(-Z),(Z));
    glMatrixMode(GL_MODELVIEW);
}
void idle()
{
    display();
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
    
	//Init();
	// Habilitar la prueba de profundidad de Z-buffer
	//glEnable(GL_DEPTH_TEST);
	Cargartextura();
	// Funciones de retrollamada
	glutDisplayFunc(display);
	//glutReshapeFunc(resize);
	glutKeyboardFunc(key);
	glutSpecialFunc(specialKeys);
    glutIdleFunc(idle);
	//frameNumber = 0;
	//glutIdleFunc(text);
	//pulsemos();
	glutMainLoop();

	// Regresar al sistema operativo
	return 0;
}
