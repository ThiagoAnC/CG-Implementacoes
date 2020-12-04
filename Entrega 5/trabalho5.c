#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<GL/glut.h>

int asp = 1;  /* aspect ratio */


void desenhaCubo() {
  glColor3f(0.2, 0.3, 0.7);

  glBegin(GL_POLYGON);
     glVertex3f(0.25,0.25,0.25);
     glVertex3f(0.25,0.25,0.0);
     glVertex3f(0.0,0.25,0.0);
     glVertex3f(0.0,0.25,0.25);
  glEnd();                        

  glColor3f(0.4, 0.2, 0.8);

  glBegin(GL_POLYGON);
     glVertex3f(0.25,0.25,0.25);
     glVertex3f(0.25,0.0,0.25);
     glVertex3f(0.25,0.0,0.0);
     glVertex3f(0.25,0.25,0.0);
  glEnd();                        
                        
  glColor3f(0.2, 0.3, 0.4);

  glBegin(GL_POLYGON);
     glVertex3f(0.25,0.25,0.25);
     glVertex3f(0.25,0.0,0.25);
     glVertex3f(0.0,0.0,0.25);
     glVertex3f(0.0,0.25,0.25);
  glEnd();                        

  glColor3f(0.2, 0.3, 0.55);

  glBegin(GL_POLYGON);
     glVertex3f(0.0,0.0,0.0);
     glVertex3f(0.0,0.25,0.0);
     glVertex3f(0.25,0.25,0.0);
     glVertex3f(0.25,0.0,0.0);
  glEnd();                        

  glColor3f(0.2, 0.45, 0.4);

  glBegin(GL_POLYGON);
     glVertex3f(0.0,0.0,0.0);
     glVertex3f(0.25,0.0,0.0);
     glVertex3f(0.25,0.0,0.25);
     glVertex3f(0.0,0.0,0.25);
  glEnd();                        

  glColor3f(0.33, 0.3, 0.4);

  glBegin(GL_POLYGON);
     glVertex3f(0.0,0.0,0.0);
     glVertex3f(0.0,0.0,0.25);
     glVertex3f(0.0,0.25,0.25);
     glVertex3f(0.0,0.25,0.0);
  glEnd();  
  
  glColor3f(0.0, 1.0, 0.0);

  glBegin(GL_POLYGON);
     glVertex3f(0.25,0.25,0.25);
     glVertex3f(0.25,0.0,0.25);
     glVertex3f(0.25,0.0,0.0);
     glVertex3f(0.25,0.25,0.0);
  glEnd();                        
                        
  glColor3f(1.0, 0.0, 0.0);

  glBegin(GL_POLYGON);
     glVertex3f(0.25,0.25,0.25);
     glVertex3f(0.25,0.0,0.25);
     glVertex3f(0.0,0.0,0.25);
     glVertex3f(0.0,0.25,0.25);
  glEnd();                        

  glFlush();
}

void criaMatrizProjecao(int width,int height)
{

  GLfloat mprojecao[16];
  asp = (height>0) ? (double)width/height : 1;
  glViewport(0,0,width,height); 
  glMatrixMode( GL_PROJECTION ); 
  glLoadIdentity(); 

  mprojecao [0]= 1;
  mprojecao [1]= 0;
  mprojecao [2]= -1;
  mprojecao [3]= 0;

  mprojecao [4]= 0;
  mprojecao [5]= 1;
  mprojecao [6]= -1;
  mprojecao [7]= 0;

  mprojecao [8]= 0;
  mprojecao [9]= 0;
  mprojecao [10]= 0;
  mprojecao [11]= 0;
  
  mprojecao [12]= 0;
  mprojecao [13]= 0;
  mprojecao [14]= 0;
  mprojecao [15]= 1;

  

  glLoadMatrixf (mprojecao);
  glClearColor(0.0f,0.0f,0.0f,0.0f); 
  glClear( GL_COLOR_BUFFER_BIT  );

  glClear(GL_DEPTH_BUFFER_BIT); 
  glEnable(GL_DEPTH_TEST);
  
  glMatrixMode( GL_MODELVIEW ); 
  glLoadIdentity();


}


void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0, 0, 0, 1);
    desenhaCubo();
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
    //glutInitContextVersion(3, 1);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(300, 300);
	
	glutCreateWindow("Desenhando o cubo na tela utilizando a projecao perspectiva ");
	
    glutReshapeFunc(criaMatrizProjecao);
	glutDisplayFunc(Display);

    GLfloat m[16];
    glGetFloatv(GL_MODELVIEW_MATRIX, m);
    printf("%f\n",m[0]);
    printf("%f\n",m[1]);
    printf("%f\n",m[2]);
	glutMainLoop();
	return 0;
}