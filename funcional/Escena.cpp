#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <SDL2/SDL.h>
#include <cstdio>
#include <math.h>
#include <SOIL/SOIL.h>
#define PI 3.1415927
#define RUTA_AUDIO "theme.wav" //nombre del archivo de audio


using namespace std;

int frameNumber,caminar,saltar;   // Numero de frames 
float trasladarIzq, trasladarDer,TrasladarSalto, rotateY; 

//Arreglo de imagenes
//GLuint texture[0];
//Definimos variables
double rotate_y=0;
double rotate_x=0;
double rotate_z=0;
float x1rot = 0.00, y1rot = 0.00, zoom1 = 1;
double PX=65;
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

void piernasIzq(void){
	glPushMatrix();
	/////////////////////////////pierna lado izq////////////////////////////////////////////////////////////////////
	glColor3f(0, 0, 0);
	
	//orilla color negro de arriba a abajo y  de izq a der
	
	glBegin(GL_POLYGON);glVertex3f(8,2,0);glVertex3f(8,8,0);glVertex3f(9,8,0);glVertex3f(9,2,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(9,1,0);glVertex3f(9,2,0);glVertex3f(10,2,0);glVertex3f(10,1,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(10,0,0);glVertex3f(10,1,0);glVertex3f(15,1,0);glVertex3f(15,0,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(14,1,0);glVertex3f(14,2,0);glVertex3f(15,2,0);glVertex3f(15,1,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(13,2,0);glVertex3f(13,3,0);glVertex3f(14,3,0);glVertex3f(14,2,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(12,3,0);glVertex3f(12,8,0);glVertex3f(13,8,0);glVertex3f(13,3,0);glEnd();
	
	
	glBegin(GL_POLYGON);glVertex3f(13,8,0);glVertex3f(13,9,0);glVertex3f(14,9,0);glVertex3f(14,8,0);glEnd();
	//rodilla
	
	glBegin(GL_POLYGON);glVertex3f(10,6,0);glVertex3f(10,8,0);glVertex3f(11,8,0);glVertex3f(11,6,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(11,6,0);glVertex3f(11,7,0);glVertex3f(12,7,0);glVertex3f(12,6,0);glEnd();
	
	//relleno color rojo
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);glVertex3f(11,7,0);glVertex3f(11,8,0);glVertex3f(12,8,0);glVertex3f(12,7,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(9,5,0);glVertex3f(9,8,0);glVertex3f(10,8,0);glVertex3f(10,5,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(10,5,0);glVertex3f(10,6,0);glVertex3f(12,6,0);glVertex3f(12,5,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(12,2,0);glVertex3f(12,3,0);glVertex3f(13,3,0);glVertex3f(13,2,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(11,1,0);glVertex3f(11,2,0);glVertex3f(14,2,0);glVertex3f(14,1,0);glEnd();
	
	//relleno color gris
	//color gris oscuro de izq a der
	glColor3f(0.45, 0.45, 0.45);
	glBegin(GL_POLYGON);glVertex3f(9,2,0);glVertex3f(9,5,0);glVertex3f(12,5,0);glVertex3f(12,2,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(10,1,0);glVertex3f(10,2,0);glVertex3f(11,2,0);glVertex3f(11,1,0);glEnd();
	glPopMatrix();
	
	
	
	
	
}
void piernaDer(void){
	 glPushMatrix();
	/////////////////////////////pierna lado der/////////////////////////////////////////////
	
	glColor3f(0, 0, 0);
	
	//orilla color negro de arriba a abajo y  de izq a der
	
	
	
	
	//lo que se va  trasladar
	
	glBegin(GL_POLYGON);glVertex3f(19,4,0);glVertex3f(19,9,0);glVertex3f(20,9,0);glVertex3f(20,4,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(20,3,0);glVertex3f(20,4,0);glVertex3f(21,4,0);glVertex3f(21,3,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(21,2,0);glVertex3f(21,3,0);glVertex3f(22,3,0);glVertex3f(22,2,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(17,1,0);glVertex3f(17,2,0);glVertex3f(22,2,0);glVertex3f(22,1,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(16,2,0);glVertex3f(16,3,0);glVertex3f(17,3,0);glVertex3f(17,2,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(15,3,0);glVertex3f(15,9,0);glVertex3f(16,9,0);glVertex3f(16,3,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(17,7,0);glVertex3f(17,9,0);glVertex3f(18,9,0);glVertex3f(18,7,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(18,7,0);glVertex3f(18,8,0);glVertex3f(19,8,0);glVertex3f(19,7,0);glEnd();
	
	//relleno color rojo
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);glVertex3f(18,8,0);glVertex3f(18,9,0);glVertex3f(19,9,0);glVertex3f(19,8,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(16,6,0);glVertex3f(16,9,0);glVertex3f(17,9,0);glVertex3f(17,6,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(17,6,0);glVertex3f(17,7,0);glVertex3f(19,7,0);glVertex3f(19,6,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(19,3,0);glVertex3f(19,4,0);glVertex3f(20,4,0);glVertex3f(20,3,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(18,2,0);glVertex3f(18,3,0);glVertex3f(21,3,0);glVertex3f(21,2,0);glEnd();
	
	//relleno color gris
	//color gris oscuro de izq a der
	glColor3f(0.45, 0.45, 0.45);
	glBegin(GL_POLYGON);glVertex3f(16,3,0);glVertex3f(16,6,0);glVertex3f(19,6,0);glVertex3f(19,3,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(17,2,0);glVertex3f(17,3,0);glVertex3f(18,3,0);glVertex3f(18,2,0);glEnd();
	
		glPopMatrix();
	}

void cabeza(void){
	 glPushMatrix();
	glColor3f(0, 0, 0);
	//orilla color negro de arriba a abajo y  de izq a der
	
	glBegin(GL_POLYGON);glVertex3f(10,40,0);glVertex3f(10,41,0);glVertex3f(16,41,0);glVertex3f(16,40,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(8,39,0);glVertex3f(8,40,0);glVertex3f(10,40,0);glVertex3f(10,39,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(7,38,0);glVertex3f(7,39,0);glVertex3f(8,39,0);glVertex3f(8,38,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(6,36,0);glVertex3f(6,38,0);glVertex3f(7,38,0);glVertex3f(7,36,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(5,31,0);glVertex3f(5,36,0);glVertex3f(6,36,0);glVertex3f(6,31,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(6,29,0);glVertex3f(6,31,0);glVertex3f(7,31,0);glVertex3f(7,29,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(7,28,0);glVertex3f(7,29,0);glVertex3f(8,29,0);glVertex3f(8,28,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(8,27,0);glVertex3f(8,28,0);glVertex3f(9,28,0);glVertex3f(9,27,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(9,26,0);glVertex3f(9,27,0);glVertex3f(10,27,0);glVertex3f(10,26,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(10,25,0);glVertex3f(10,26,0);glVertex3f(12,26,0);glVertex3f(12,25,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(12,24,0);glVertex3f(12,25,0);glVertex3f(17,25,0);glVertex3f(17,24,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(17,25,0);glVertex3f(17,26,0);glVertex3f(18,26,0);glVertex3f(18,25,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(18,26,0);glVertex3f(18,27,0);glVertex3f(19,27,0);glVertex3f(19,26,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(19,27,0);glVertex3f(19,30,0);glVertex3f(20,30,0);glVertex3f(20,27,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(20,30,0);glVertex3f(20,36,0);glVertex3f(21,36,0);glVertex3f(21,30,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(19,36,0);glVertex3f(19,38,0);glVertex3f(20,38,0);glVertex3f(20,36,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(18,38,0);glVertex3f(18,39,0);glVertex3f(19,39,0);glVertex3f(19,38,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(16,39,0);glVertex3f(16,40,0);glVertex3f(18,40,0);glVertex3f(18,39,0);glEnd();
	
	
	/////////////////relleno color rojo de arriba hacia abajo 
	
	glColor3f(1, 0, 0);
	
	
	glBegin(GL_POLYGON);glVertex3f(10,39,0);glVertex3f(10,40,0);glVertex3f(16,40,0);glVertex3f(16,39,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(8,38,0);glVertex3f(8,39,0);glVertex3f(18,39,0);glVertex3f(18,38,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(7,33,0);glVertex3f(7,38,0);glVertex3f(19,38,0);glVertex3f(19,33,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(6,31,0);glVertex3f(6,36,0);glVertex3f(7,36,0);glVertex3f(7,31,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(7,29,0);glVertex3f(7,33,0);glVertex3f(10,33,0);glVertex3f(10,29,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(10,32,0);glVertex3f(10,33,0);glVertex3f(11,33,0);glVertex3f(11,32,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(8,28,0);glVertex3f(8,29,0);glVertex3f(11,29,0);glVertex3f(11,28,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(9,27,0);glVertex3f(9,28,0);glVertex3f(12,28,0);glVertex3f(12,27,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(10,26,0);glVertex3f(10,27,0);glVertex3f(12,27,0);glVertex3f(12,26,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(12,25,0);glVertex3f(12,27,0);glVertex3f(17,27,0);glVertex3f(17,25,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(17,26,0);glVertex3f(17,27,0);glVertex3f(18,27,0);glVertex3f(18,26,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(16,27,0);glVertex3f(16,28,0);glVertex3f(19,28,0);glVertex3f(19,27,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(15,27,0);glVertex3f(15,28,0);glVertex3f(19,28,0);glVertex3f(19,27,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(16,28,0);glVertex3f(16,33,0);glVertex3f(18,33,0);glVertex3f(18,28,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(14,32,0);glVertex3f(14,33,0);glVertex3f(19,33,0);glVertex3f(19,32,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(19,33,0);glVertex3f(19,36,0);glVertex3f(20,36,0);glVertex3f(20,33,0);glEnd();
	
	
	//////////////////////////////////////ojos//////////////////////
	
	//ojo lado izq
	
	//color gris oscuro de izq a der
	glColor3f(0.45, 0.45, 0.45);
	
	glBegin(GL_POLYGON);glVertex3f(10,29,0);glVertex3f(10,32,0);glVertex3f(11,32,0);glVertex3f(11,29,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(11,28,0);glVertex3f(11,33,0);glVertex3f(12,33,0);glVertex3f(12,28,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(12,31,0);glVertex3f(12,32,0);glVertex3f(13,32,0);glVertex3f(13,31,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(12,27,0);glVertex3f(12,29,0);glVertex3f(14,29,0);glVertex3f(14,27,0);glEnd();
	
	//color gris oscuro de izq a der
	glColor3f(0.65, 0.65, 0.65);
	
	glBegin(GL_POLYGON);glVertex3f(12,32,0);glVertex3f(12,33,0);glVertex3f(14,33,0);glVertex3f(14,32,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(13,31,0);glVertex3f(13,32,0);glVertex3f(14,32,0);glVertex3f(14,31,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(14,30,0);glVertex3f(14,32,0);glVertex3f(16,32,0);glVertex3f(16,30,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(15,28,0);glVertex3f(15,30,0);glVertex3f(16,30,0);glVertex3f(16,28,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(14,27,0);glVertex3f(14,29,0);glVertex3f(15,29,0);glVertex3f(15,27,0);glEnd();
	
	
	
	//ojo lado der
	//color gris oscuro de izq a der
	glColor3f(0.65, 0.65, 0.65);
	
	glBegin(GL_POLYGON);glVertex3f(18,28,0);glVertex3f(18,32,0);glVertex3f(19,32,0);glVertex3f(19,28,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(19,30,0);glVertex3f(19,33,0);glVertex3f(20,33,0);glVertex3f(20,30,0);glEnd();
	
		glPopMatrix();
	
	}
void cuerpo(void){
	 glPushMatrix();
	//////////////////////////////////////////////parte superior de las piernas orilla/////////////////////////////////////////////////
	glColor3f(0, 0, 0);
	
	glBegin(GL_POLYGON);glVertex3f(8,8,0);glVertex3f(8,14,0);glVertex3f(9,14,0);glVertex3f(9,8,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(19,9,0);glVertex3f(19,14,0);glVertex3f(20,14,0);glVertex3f(20,9,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(15,9,0);glVertex3f(15,12,0);glVertex3f(16,12,0);glVertex3f(16,9,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(14,9,0);glVertex3f(14,13,0);glVertex3f(15,13,0);glVertex3f(15,9,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(16,12,0);glVertex3f(16,13,0);glVertex3f(17,13,0);glVertex3f(17,12,0);glEnd();
	
	//relleno color gris parte superior de las piernas
	
	//color gris "pierna lado izq"oscuro de arri  aba 
	glColor3f(0.45, 0.45, 0.45);
	
	glBegin(GL_POLYGON);glVertex3f(9,13,0);glVertex3f(9,14,0);glVertex3f(11,14,0);glVertex3f(11,13,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(9,12,0);glVertex3f(9,13,0);glVertex3f(10,13,0);glVertex3f(10,12,0);glEnd();
	
	//color gris "pierna lado der"oscuro de arri  aba
	glBegin(GL_POLYGON);glVertex3f(18,12,0);glVertex3f(18,14,0);glVertex3f(19,14,0);glVertex3f(19,12,0);glEnd(); 
	
	////////////////relleno color rojo de arriba hacia abajo 
	
	glColor3f(1, 0, 0);
	
	//superior
	glBegin(GL_POLYGON);glVertex3f(11,13,0);glVertex3f(11,14,0);glVertex3f(18,14,0);glVertex3f(18,13,0);glEnd();
	
	//pierna lado izq
    glBegin(GL_POLYGON);glVertex3f(10,12,0);glVertex3f(10,13,0);glVertex3f(14,13,0);glVertex3f(14,12,0);glEnd();
    
    glBegin(GL_POLYGON);glVertex3f(9,11,0);glVertex3f(9,12,0);glVertex3f(14,12,0);glVertex3f(14,11,0);glEnd();
    
    glBegin(GL_POLYGON);glVertex3f(9,10,0);glVertex3f(9,11,0);glVertex3f(14,11,0);glVertex3f(14,10,0);glEnd();
    
    glBegin(GL_POLYGON);glVertex3f(9,9,0);glVertex3f(9,10,0);glVertex3f(14,10,0);glVertex3f(14,9,0);glEnd();
    
    glBegin(GL_POLYGON);glVertex3f(9,8,0);glVertex3f(9,9,0);glVertex3f(14,9,0);glVertex3f(14,8,0);glEnd();
    
    //pierna lado der
    glBegin(GL_POLYGON);glVertex3f(15,12,0);glVertex3f(15,13,0);glVertex3f(16,13,0);glVertex3f(16,12,0);glEnd();
    
    glBegin(GL_POLYGON);glVertex3f(17,12,0);glVertex3f(17,13,0);glVertex3f(18,13,0);glVertex3f(18,12,0);glEnd();
    
    glBegin(GL_POLYGON);glVertex3f(16,11,0);glVertex3f(16,12,0);glVertex3f(19,12,0);glVertex3f(19,11,0);glEnd();
    
    glBegin(GL_POLYGON);glVertex3f(16,10,0);glVertex3f(16,11,0);glVertex3f(19,11,0);glVertex3f(19,10,0);glEnd();
    
    glBegin(GL_POLYGON);glVertex3f(16,9,0);glVertex3f(16,10,0);glVertex3f(19,10,0);glVertex3f(19,9,0);glEnd();
	
	
	//////////////////////////orilla color negro///////////////////////
	glColor3f(0, 0, 0);
	//orilla izq
	glBegin(GL_POLYGON);glVertex3f(9,14,0);glVertex3f(9,16,0);glVertex3f(10,16,0);glVertex3f(10,14,0);glEnd();
    
    glBegin(GL_POLYGON);glVertex3f(10,16,0);glVertex3f(10,19,0);glVertex3f(11,19,0);glVertex3f(11,16,0);glEnd();
    
    glBegin(GL_POLYGON);glVertex3f(11,17,0);glVertex3f(11,18,0);glVertex3f(12,18,0);glVertex3f(12,17,0);glEnd();
    
    glBegin(GL_POLYGON);glVertex3f(12,16,0);glVertex3f(12,17,0);glVertex3f(13,17,0);glVertex3f(13,16,0);glEnd();
    
    glBegin(GL_POLYGON);glVertex3f(8,19,0);glVertex3f(8,20,0);glVertex3f(10,20,0);glVertex3f(10,19,0);glEnd();
    
    glBegin(GL_POLYGON);glVertex3f(8,20,0);glVertex3f(8,21,0);glVertex3f(9,21,0);glVertex3f(9,20,0);glEnd();
    
    glBegin(GL_POLYGON);glVertex3f(9,21,0);glVertex3f(9,22,0);glVertex3f(10,22,0);glVertex3f(10,21,0);glEnd();
    
    glBegin(GL_POLYGON);glVertex3f(10,22,0);glVertex3f(10,24,0);glVertex3f(11,24,0);glVertex3f(11,22,0);glEnd();
    
    glBegin(GL_POLYGON);glVertex3f(11,21,0);glVertex3f(11,22,0);glVertex3f(13,22,0);glVertex3f(13,21,0);glEnd();
    
    
    //orilla cinturon
    //verticales
    glBegin(GL_POLYGON);glVertex3f(14,15,0);glVertex3f(14,17,0);glVertex3f(15,17,0);glVertex3f(15,15,0);glEnd();
    
    glBegin(GL_POLYGON);glVertex3f(18,15,0);glVertex3f(18,17,0);glVertex3f(19,17,0);glVertex3f(19,15,0);glEnd();
    
    //horizontales
    glBegin(GL_POLYGON);glVertex3f(15,17,0);glVertex3f(15,18,0);glVertex3f(18,18,0);glVertex3f(18,17,0);glEnd();
    
    glBegin(GL_POLYGON);glVertex3f(15,14,0);glVertex3f(15,15,0);glVertex3f(18,15,0);glVertex3f(18,14,0);glEnd();
	
	//orilla derecha
	glBegin(GL_POLYGON);glVertex3f(19,14,0);glVertex3f(19,24,0);glVertex3f(20,24,0);glVertex3f(20,14,0);glEnd();
    
    glBegin(GL_POLYGON);glVertex3f(18,21,0);glVertex3f(18,22,0);glVertex3f(19,22,0);glVertex3f(19,21,0);glEnd();
    
    glBegin(GL_POLYGON);glVertex3f(18,24,0);glVertex3f(18,25,0);glVertex3f(19,25,0);glVertex3f(19,24,0);glEnd();
    
    
    
    ////////////////////////////////////relleno color gris////////////////////////
    glColor3f(0.45, 0.45, 0.45);
    //lado izq
    
    //los cuadros van de arriba hacia abajo
    glBegin(GL_POLYGON);glVertex3f(10,24,0);glVertex3f(10,25,0);glVertex3f(12,25,0);glVertex3f(12,24,0);glEnd();
    
    glBegin(GL_POLYGON);glVertex3f(11,22,0);glVertex3f(11,24,0);glVertex3f(12,24,0);glVertex3f(12,22,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(10,19,0);glVertex3f(10,21,0);glVertex3f(13,21,0);glVertex3f(13,19,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(10,21,0);glVertex3f(10,22,0);glVertex3f(11,22,0);glVertex3f(11,21,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(9,20,0);glVertex3f(9,21,0);glVertex3f(10,21,0);glVertex3f(10,20,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(11,18,0);glVertex3f(11,19,0);glVertex3f(13,19,0);glVertex3f(13,18,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(12,17,0);glVertex3f(12,18,0);glVertex3f(13,18,0);glVertex3f(13,17,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(11,16,0);glVertex3f(11,17,0);glVertex3f(12,17,0);glVertex3f(12,16,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(13,16,0);glVertex3f(13,17,0);glVertex3f(14,17,0);glVertex3f(14,16,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(12,15,0);glVertex3f(12,16,0);glVertex3f(14,16,0);glVertex3f(14,15,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(10,14,0);glVertex3f(10,16,0);glVertex3f(12,16,0);glVertex3f(12,14,0);glEnd();
	
	
	//lado derecho
	//los cuadros van de arriba hacia abajo
	glBegin(GL_POLYGON);glVertex3f(18,22,0);glVertex3f(18,24,0);glVertex3f(19,24,0);glVertex3f(19,22,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(18,17,0);glVertex3f(18,21,0);glVertex3f(19,21,0);glVertex3f(19,17,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(18,14,0);glVertex3f(18,15,0);glVertex3f(19,15,0);glVertex3f(19,14,0);glEnd();
	
	
	/////////////////////////////relleno color rojo////////////////////
	glColor3f(1, 0, 0);
	//los cuadros van de arriba hacia abajo y de der a izq
	glBegin(GL_POLYGON);glVertex3f(17,24,0);glVertex3f(17,25,0);glVertex3f(18,25,0);glVertex3f(18,24,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(13,18,0);glVertex3f(13,24,0);glVertex3f(18,24,0);glVertex3f(18,18,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(12,22,0);glVertex3f(12,24,0);glVertex3f(13,24,0);glVertex3f(13,22,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(13,17,0);glVertex3f(13,18,0);glVertex3f(15,18,0);glVertex3f(15,17,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(12,14,0);glVertex3f(12,15,0);glVertex3f(15,15,0);glVertex3f(15,14,0);glEnd();
	
	
	//parte del cinturon
	glBegin(GL_POLYGON);glVertex3f(16,15,0);glVertex3f(16,17,0);glVertex3f(17,17,0);glVertex3f(17,15,0);glEnd();
	
	
	
	
	
	
	////////////////////////////////////////////////////////mano izq//////////////////////////////////
	glColor3f(0, 0, 0);
	//orilla color negro de arriba a abajo
	
	glBegin(GL_POLYGON);glVertex3f(7,26,0);glVertex3f(7,27,0);glVertex3f(8,27,0);glVertex3f(8,26,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(5,25,0);glVertex3f(5,26,0);glVertex3f(7,26,0);glVertex3f(7,25,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(5,23,0);glVertex3f(5,25,0);glVertex3f(6,25,0);glVertex3f(6,23,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(6,22,0);glVertex3f(6,23,0);glVertex3f(7,23,0);glVertex3f(7,22,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(4,21,0);glVertex3f(4,23,0);glVertex3f(5,23,0);glVertex3f(5,21,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(3,18,0);glVertex3f(3,21,0);glVertex3f(4,21,0);glVertex3f(4,18,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(2,12,0);glVertex3f(2,18,0);glVertex3f(3,18,0);glVertex3f(3,12,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(3,11,0);glVertex3f(3,12,0);glVertex3f(4,12,0);glVertex3f(4,11,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(4,10,0);glVertex3f(4,11,0);glVertex3f(7,11,0);glVertex3f(7,10,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(6,11,0);glVertex3f(6,13,0);glVertex3f(7,13,0);glVertex3f(7,11,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(7,11,0);glVertex3f(7,12,0);glVertex3f(8,12,0);glVertex3f(8,11,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(7,13,0);glVertex3f(7,15,0);glVertex3f(8,15,0);glVertex3f(8,13,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(6,15,0);glVertex3f(6,18,0);glVertex3f(7,18,0);glVertex3f(7,15,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(7,18,0);glVertex3f(7,19,0);glVertex3f(8,19,0);glVertex3f(8,18,0);glEnd();
	
	
	//relleno mano color gris de arriba hacia abajo
	glColor3f(0.45, 0.45, 0.45);
	glBegin(GL_POLYGON);glVertex3f(8,26,0);glVertex3f(8,27,0);glVertex3f(9,27,0);glVertex3f(9,26,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(7,22,0);glVertex3f(7,26,0);glVertex3f(10,26,0);glVertex3f(10,22,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(6,23,0);glVertex3f(6,25,0);glVertex3f(7,25,0);glVertex3f(7,23,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(5,22,0);glVertex3f(5,23,0);glVertex3f(6,23,0);glVertex3f(6,22,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(6,21,0);glVertex3f(6,22,0);glVertex3f(9,22,0);glVertex3f(9,21,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(7,20,0);glVertex3f(7,21,0);glVertex3f(8,21,0);glVertex3f(8,20,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(4,19,0);glVertex3f(4,21,0);glVertex3f(5,21,0);glVertex3f(5,19,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(5,18,0);glVertex3f(5,20,0);glVertex3f(6,20,0);glVertex3f(6,18,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(6,18,0);glVertex3f(6,19,0);glVertex3f(7,19,0);glVertex3f(7,18,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(3,15,0);glVertex3f(3,16,0);glVertex3f(6,16,0);glVertex3f(6,15,0);glEnd();
	
	
	//relleno mano color rojo de arriba hacia abajo
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);glVertex3f(5,20,0);glVertex3f(5,22,0);glVertex3f(6,22,0);glVertex3f(6,20,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(6,19,0);glVertex3f(6,21,0);glVertex3f(7,21,0);glVertex3f(7,19,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(7,19,0);glVertex3f(7,20,0);glVertex3f(8,20,0);glVertex3f(8,19,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(4,18,0);glVertex3f(4,19,0);glVertex3f(5,19,0);glVertex3f(5,18,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(3,16,0);glVertex3f(3,18,0);glVertex3f(6,18,0);glVertex3f(6,16,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(3,13,0);glVertex3f(3,15,0);glVertex3f(7,15,0);glVertex3f(7,13,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(3,12,0);glVertex3f(3,13,0);glVertex3f(6,13,0);glVertex3f(6,12,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(4,11,0);glVertex3f(4,12,0);glVertex3f(6,12,0);glVertex3f(6,11,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(7,12,0);glVertex3f(7,13,0);glVertex3f(8,13,0);glVertex3f(8,12,0);glEnd();
	
	
	/////////////////////////////////////////////mano der/////////////////////////////////////////////
	
	glColor3f(0, 0, 0);
	//orilla color negro de arriba a abajo
	
	glBegin(GL_POLYGON);glVertex3f(20,18,0);glVertex3f(20,21,0);glVertex3f(21,21,0);glVertex3f(21,18,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(21,14,0);glVertex3f(21,18,0);glVertex3f(22,18,0);glVertex3f(22,14,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(22,10,0);glVertex3f(22,14,0);glVertex3f(23,14,0);glVertex3f(23,10,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(20,10,0);glVertex3f(20,11,0);glVertex3f(22,11,0);glVertex3f(22,10,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(20,11,0);glVertex3f(20,13,0);glVertex3f(21,13,0);glVertex3f(21,11,0);glEnd();
	
	//relleno mano color gris de arriba hacia abajo
	glColor3f(0.45, 0.45, 0.45);
	glBegin(GL_POLYGON);glVertex3f(20,17,0);glVertex3f(20,18,0);glVertex3f(21,18,0);glVertex3f(21,17,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(20,14,0);glVertex3f(20,15,0);glVertex3f(21,15,0);glVertex3f(21,14,0);glEnd();
	
	
	//relleno mano color rojo de arriba hacia abajo
	glColor3f(1, 0, 0);
	
	glBegin(GL_POLYGON);glVertex3f(20,15,0);glVertex3f(20,17,0);glVertex3f(21,17,0);glVertex3f(21,15,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(20,13,0);glVertex3f(20,14,0);glVertex3f(22,14,0);glVertex3f(22,13,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(21,11,0);glVertex3f(21,13,0);glVertex3f(22,13,0);glVertex3f(22,11,0);glEnd();
	
	
	//////////////////////////////////////////////////espada/////////////////////////////////////////////
	
	glColor3f(0, 0, 0);
	//orilla color negro de arriba a abajo //parte superior//
	
	glBegin(GL_POLYGON);glVertex3f(1,30,0);glVertex3f(1,31,0);glVertex3f(2,31,0);glVertex3f(2,30,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(2,29,0);glVertex3f(2,30,0);glVertex3f(3,30,0);glVertex3f(3,29,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(3,28,0);glVertex3f(3,29,0);glVertex3f(4,29,0);glVertex3f(4,28,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(4,27,0);glVertex3f(4,28,0);glVertex3f(5,28,0);glVertex3f(5,27,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(5,26,0);glVertex3f(5,27,0);glVertex3f(6,27,0);glVertex3f(6,26,0);glEnd();
	
	
	//orilla color negro de arriba a abajo //parte inferior//
	
	glBegin(GL_POLYGON);glVertex3f(0,29,0);glVertex3f(0,31,0);glVertex3f(1,31,0);glVertex3f(1,29,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(1,28,0);glVertex3f(1,29,0);glVertex3f(2,29,0);glVertex3f(2,28,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(2,27,0);glVertex3f(2,28,0);glVertex3f(3,28,0);glVertex3f(3,27,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(3,26,0);glVertex3f(3,27,0);glVertex3f(4,27,0);glVertex3f(4,26,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(4,25,0);glVertex3f(4,26,0);glVertex3f(5,26,0);glVertex3f(5,25,0);glEnd();
	
	
	//relleno espada
	
	glColor3f(0.627, 0.322, 0.176);
	 	
	
	glBegin(GL_POLYGON);glVertex3f(1,29,0);glVertex3f(1,30,0);glVertex3f(2,30,0);glVertex3f(2,29,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(2,28,0);glVertex3f(2,29,0);glVertex3f(3,29,0);glVertex3f(3,28,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(3,27,0);glVertex3f(3,28,0);glVertex3f(4,28,0);glVertex3f(4,27,0);glEnd();
	
	glBegin(GL_POLYGON);glVertex3f(4,26,0);glVertex3f(4,27,0);glVertex3f(5,27,0);glVertex3f(5,26,0);glEnd();
		glPopMatrix();
}

void esfera (float r)
{	
	glPushMatrix();
	glutSolidSphere(r,100,100);
	glPopMatrix();
}

void TUX(void){
	glPushMatrix();

	glBegin(GL_QUADS);
		glVertex3f(51.5, 10.7, 1.1);
		glVertex3f(51.5, 13.0, 1.1);
		glVertex3f(52.6, 13.0, 1.1);
		glVertex3f(52.6, 10.7, 1.1);
	glEnd();
	
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
    tex4 = loadTex("/home/victor/Victor/Mario/funcional/img/troco.jpg");
    tex5 = loadTex("/home/victor/Victor/Mario/funcional/img/orilla.png");
    tex6 = loadTex("/home/victor/Victor/Mario/funcional/img/barril.png");
    tex7 = loadTex("/home/victor/Victor/Mario/funcional/img/ball.jpg");
    tex1 = loadTex("/home/victor/Victor/Mario/funcional/img/fondo.png");
    tex2 = loadTex("/home/victor/Victor/Mario/funcional/img/sue.png");
    tex3 = loadTex("/home/victor/Victor/Mario/funcional/img/gra1.png");
}
	// funcion para cargar audio
void my_audio_callback(void *userdata, Uint8 *stream, int len);
	
	// variables para audio
static Uint8 *audio_pos; // global pointer to the audio buffer to be played
static Uint32 audio_len; // remaining length of the sample we have to play

void display()
{
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	glOrtho(-0,(Z),-7,80,(-Z),(Z));

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//GLfloat light_ambient[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
   // GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    //GLfloat light_position[] = { 20.0f, 1.0f, 1.0f, 0.0f };
    //GLfloat light_position[] = { 80.0, 60.0, 20.0, 0.0 };

    //glEnable(GL_LIGHT0);
    //glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    //glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    //glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glTranslatef(X,0.0f,0.0f);

////////////////////////escenario de el fondo//////////////////////////////
	

	glPushMatrix();
	esce();
	glPopMatrix();

    double j=0, cor=0;
    for(j=0;j<=3;j+=1){
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
    for(j1=0;j1<=3;j1+=1){
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
 	int j12=0, cor12=135;
 	int arrayBa[]={135,300,465,630};
    for(j12=0;j12<=3;j12+=1){
    //Barril
	glPushMatrix();
    glTranslatef(cor12,3.0,1.50);
    //arrayBa[j12]={cor12};
    barril(3.5,8.0);
    glPopMatrix();    
    cor12+=165;
    }
    int j123=0, cor123=135;
    for(j123=0;j123<=3;j123+=1){
    //Balon
    glPushMatrix();
    glTranslatef(X,0,0);
    glTranslated(cor123,-1.0,1.50);
    glRotatef(yrot, 0, 1, 0);
    pelota(3.0);
    glPopMatrix();     
	  cor123+=170;
	;
    }
    for(int k=0; k<4; k++)
    {	
		 // cout << A << ' ';
		  printf("posicion:(%f)",arrayBa[k]);
		}
	//glLineWidth(5);
    //glCallList(1);
    glPushMatrix();
    glTranslatef(-X,0,zoom1);
    Text();
    //glCallList(texto);
    glPopMatrix();

   //glFlush();

   // TUX();
   // glPushMatrix();
   /* glPointSize(1);
    glScalef(0.5,0.5,0.5);
    glTranslatef(-2*X,7.0,1.10);
    cabeza();
    cuerpo();
    piernasIzq();
    piernaDer();*/
     //  glPopMatrix();
     glTranslatef(-2*X,7.0,1.10);
     // Agregar Codigo acá, para dibujar
    glPushMatrix();
		glTranslatef(0, TrasladarSalto, 0);
		
		glScalef(0.5,0.5,0.5);
		glPushMatrix();
		glTranslatef(0, -trasladarIzq/6, 0);
		cabeza();
		glPopMatrix();
		cuerpo();
		glPushMatrix();
		glTranslatef(0, trasladarIzq, 0); 
		piernasIzq();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0,  -trasladarDer+4, 0); 
		piernaDer();
		glPopMatrix();
    
    glPopMatrix();
    
	glFlush();

	glutSwapBuffers();

}

// --------------- Para animación  ------------------------------------------

int animating = 0;      // 0 sin animación
int animating1 = 0;      // 0 sin animación
                        // Se cambia con la llamada a las funciones startAnimation() and pauseAnimation()

void pauseAnimation() {
        // Llamamo a la función para detener la animación
        animating = 0;
}
void pauseAnimation1() {
        // Llamamo a la función para detener la animación
        animating1 = 0;
}

void updateFrame() {
        // En esta funcion agregamos el codigo que hara la secuencia de cada escena como si fuera un fotograma
        for (int i=1; i<=1; i++) {
			X-=2.0;
			yrot+=3;
		
               // rotateY=rotateY-= i;
        }
        
        //Verificamos el numero de frames para detener animación
        if(frameNumber==450)
        {
                pauseAnimation();
                
                frameNumber=0;
                X=0;
                //si se detiene la animacion detenemos el audio
               //SDL_PauseAudio(1);
        }
        //Almacenamos el numero de frames
        frameNumber++;
        x1rot=frameNumber;
        printf ("Numero de Frame: %d \n", frameNumber);
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
			pauseAnimation1();
			}
	}
		
	
   
  //Almacenamos el numero de frames 
  saltar++;
  printf ("Numero de Frame: %d \n", saltar);

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
                glutTimerFunc(30, timerFunction1, 2);
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
void startAnimation1() {
        // llamamos la función para iniciar la animación
        if ( !animating1 ) {
                animating1 = 1;
                glutTimerFunc(30, timerFunction1, 3);
        }
}


void specialKeys( int key, int x, int y )
{

	//Mov Pelota, Proximamente de la figura
	if (key == GLUT_KEY_RIGHT){
		//yrot -=20.0;
        PX += 3.0f;
         startAnimation1();
	}

	else if (key == GLUT_KEY_LEFT){
		//yrot -=20.0;
        PX += 3.0f;
        TrasladarSalto=0;
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
   // glEnable(GL_COLOR_MATERIAL);
    //glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
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
void idle()
{
    display();
}
int main(int argc, char** argv)
{

	//  Inicializar los parámetros GLUT y de usuario proceso
	glutInit(&argc,argv);
	// Solicitar ventana con color real y doble buffer con Z-buffer
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH |GLUT_SINGLE | GLUT_RGB );
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
	glutIdleFunc(idle);
	// Habilitar la prueba de profundidad de Z-buffer
	//glEnable(GL_DEPTH_TEST);
	//frameNumber = 0;
	//glutIdleFunc(text);
	//pulsemos();
	//rameNumber = 0;
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
	glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glutMainLoop();

	// Regresar al sistema operativo
	return 0;


	SDL_PauseAudio(0);
	while ( audio_len > 0 )
	{
	SDL_Delay(100); // espera un segundo para la pausa
	}
	SDL_CloseAudio();
	SDL_FreeWAV(wav_buffer);}
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
	
	
