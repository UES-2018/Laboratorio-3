#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <SOIL/SOIL.h>
#include <math.h>

//Arreglo de imagenes
GLuint texture[0];
//Definimos variables
double rotate_y=0;
double rotate_x=0;
double rotate_z=0;

GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 125.0f+X;
GLfloat scale = 1.0f;

void init(void)
{
     glDepthFunc(GL_LESS); //comparación de profundidad
	glEnable(GL_DEPTH_TEST); //activa GL_DEPTH_TEST
	
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
void esce(void)
{	
	glNormal3f( 0.0f, -1.0f,0.0f);
	glTexCoord2f(80.0f, 0.0f); glVertex3f(0, 10, 0.0);
	glTexCoord2f(80.0f, 40.0f); glVertex3f(0, 80, 0);
	glTexCoord2f(0.0f, 40.0f); glVertex3f(450, 80, 0.0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(450, 10, 0.0);
	
	}
		void esfera (float r)
	{
	//glColor3f(1.0,0.0,1.0);
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
void display()
{
	
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//gluLookAt(120.0, 80.10, 100.0 ,0.0, 0.0, 0.0, 0.0,1.0,0.0);
	 
	glTranslatef(X,0.0f,0.0f);
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
		"../img/orilla.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
							);
	texture[3] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
														(
		"../img/loma2.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
							);

////////////////////////escenario de el fondo//////////////////////////////
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	double i=0;
	glBegin(GL_POLYGON);
	for (i=120; i<=600; i+=120){
		glTranslated(i,0,0);
		esce();
	
}glEnd();

/*
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glBegin(GL_POLYGON);
	for (i=0; i<=2; i+=1){
		
		esce(ini1,0,fin1,20);
	ini1=fin1;
	fin1+=120;
	
	}glEnd();*/
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glBegin(GL_POLYGON);	
	glNormal3f( -1.0f, 0.0f,0.0f);
	glTexCoord2f(20.0f, 0.0f); glVertex3f(0, 0, 0.0);
	glTexCoord2f(20.0f, 1.0f); glVertex3f(0, -15, 0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(450, -15, 0.0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(450, 0, 0.0);
	
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
	glTexCoord2f(20.0f, 0.0f); glVertex3f(0, 0, 0.0);
	glTexCoord2f(20.0f, 1.0f); glVertex3f(0, 10, 0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(450, 10, 0.0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(450, 0, 0.0);
	glEnd();
	 glDisable(GL_TEXTURE_2D);
	//loma 2
	/*
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTranslatef(0,0,0.00000001);
	glBegin(GL_POLYGON);	
	glNormal3f( -1.0f, 0.0f,0.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(70, 0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(70, 15, 0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(110, 15, 0.0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(110, 0, 0.0);
	glEnd();*/
	//piso
	
	/*glPushMatrix();
	 glTranslatef(20,-5,1);
    // Agregar Codigo acá, para dibujar
    //glColor3f(1.0,0.0,0.0);
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
     double i1, x, y;   //Declaracion de Variables
    glPointSize(10.0); //Tamaño de los puntos
	glBegin(GL_POLYGON);//Definimos la clase de primitiva
	//Dibujamos el primer arco
    for (i1=0.37;i1<=2.770; i1+=0.01)
    {	
		x=10.5*cos(i1) +0.0;
		y=40.5*sin(i1) +0.0;	
		glTexCoord2f(1, 0);glVertex2f(x,y); 		
	}
	glEnd();
    glPopMatrix();*/
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
	glFlush();
	
	glutSwapBuffers();
	
	printf("%f ",X);

}



void resize(int w, int h) {
    glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-5,(Z),-15,85,(-Z),(Z));
	//gluPerspective(300.0, (float)w / (float)h, 1, 120.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void specialKeys( int key, int x, int y )
{

	//  Flecha derecha: aumentar rotación 7 grados
	if (key == GLUT_KEY_RIGHT){
					//				rotate_y += 7;}
						//rotate_y -= 7;
					X+=10;
					//Z=Z+X;}
					
					}

	//  Flecha izquierda: rotación en eje Y negativo 7 grados
	else if (key == GLUT_KEY_LEFT){
								//rotate_y -= 7;
					X-=10;
					//Z=Z+X;}
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
	//else if (key == GLUT_KEY_HOME)
									//rotate_z = rotate_x=rotate_y=0;
									

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

	// Funciones de retrollamada
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutSpecialFunc(specialKeys);
	
	glutMainLoop();

	// Regresar al sistema operativo
	return 0;

}
