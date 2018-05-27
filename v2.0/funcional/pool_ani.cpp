#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>

using namespace std;

int frameNumber,caminar;   // Numero de frames 

float scale = 2;  // escala en  x, y, and z

float trasladarIzq, trasladarDer,salto, rotateY;  // variables para rotación con teclas especiales 




void piernasIzq(void){
	
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
	
	
	
	
	
	
}
void piernaDer(void){
	
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
	
	
	}
void cabeza(void){
	
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
	
	
	
	}
void cuerpo(void){
	
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
	
	
}



void display() {
       // LLamada a función dibujo 

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_PROJECTION);  // Set up the projection.
    glLoadIdentity();
    glOrtho(-9, 35, -1,44, 0.9, -0.9);
    glMatrixMode(GL_MODELVIEW);
    
    glLoadIdentity(); 
               // configuración de matrix de identidad. 
    
    

    // Agregar Codigo acá, para dibujar
    
    glTranslatef(0, salto, 0);
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
    glFlush ();
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
  
	glColor3f(0.0,1.0,0.0);
	//Hacemos que la tetera gire 
	for (int i=0; i<=2; i++){
		trasladarIzq+= i;
		trasladarDer+= i;
	}
   //Verificamos el numero de frames para detener animación 
   if(frameNumber==2)
		{
			
			trasladarIzq= 0;
			trasladarDer= 0;
			frameNumber=0;
		}
		
   if(frameNumber==100){
      pauseAnimation();
      frameNumber=0;}
  //Almacenamos el numero de frames 
  frameNumber++;
  printf ("Numero de Frame: %d \n", frameNumber);
}

void timerFunction(int timerID) {
      // Invocamos la funcion para controlar el tiempo de la ejecucion de funciones 
    if (animating) {
        updateFrame();
        glutTimerFunc(210, timerFunction, 0);
        glutPostRedisplay();
    }
}

void startAnimation() {
      // llamamos la función para iniciar la animación 
   if ( ! animating ) {
       animating = 1;
       glutTimerFunc(210, timerFunction, 1);
   }
}



// ------------- Manejo de Teclado-----------------------------------------------

void key(unsigned char key, int x, int y) {
        // La animación inicia al presionar la tecla espaciadora de igual forma se detiene
    if ( key == ' ' ) {
		if ( animating )
		   pauseAnimation();
	
		else
		   startAnimation();
	}
	if (key == 27){
		exit(0);
	}
}

void special(int key, int x, int y) {
	
		   // control de teclas especiales 
    if ( key == GLUT_KEY_LEFT )
       rotateY -= 15;
    else if ( key == GLUT_KEY_RIGHT )
       rotateY += 15;
    else if ( key == GLUT_KEY_DOWN){
		salto=0;
		
		
		}
       
    else if ( key == GLUT_KEY_UP ){
       salto=24;
       //salto=0;
		//salto=-10;
		}
    else if ( key == GLUT_KEY_HOME )
       trasladarIzq = rotateY = 0;
    glutPostRedisplay();
}

// ----------------------  Funcion principal ------------------

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("OpenGL Tetera");
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutSpecialFunc(special);
    glEnable(GL_DEPTH_TEST);

    frameNumber = caminar =0;
    trasladarIzq =  trasladarDer = 0;
    
    // Activar iluminación 
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);
    
    // Descomentar si queremos que la animación inicie al levantar el script
    //startAnimation();

    glutMainLoop();
    return 0;
}
