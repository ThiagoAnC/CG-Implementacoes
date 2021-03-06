#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

void triangulo(float ax, float ay, float bx, float by,GLdouble theta,float cx, float cy, float cz){
	GLfloat coss,seno,normal; //declaracao de tipos necessarios para rotacao

	if (theta > 0){
		coss = cos(theta); //cosseno de theta para a formula da rotacao
		seno = sin(theta); //seno de theta para a rotacao
	}
	else {
		coss = 0; //Para o caso de nao haver rotacao
		seno = 0;	
	}	

	normal = sqrt(pow(cx,cx)+pow(cy,cy)+pow(cz,cz)); //normalizacao das variaveis, senao aplicaria mais de uma funcao

	if (normal < 1.0e-4) { //Padrao que vi na implementacao padrao
		cx /= normal; //normalizando x
		cz /= normal; //normalizando y
		cy /= normal; //normalizando z
	}

	glBegin(GL_TRIANGLES);

	glColor3f(0,1,0);  //abaixo aplicam-se todas as operacoes, translacao, escala e rotacao, respectivamente 
	glVertex3f((((-2+ax)*bx)+(pow(cx,cx)*(1-coss) + coss)),((2+ay)*by+((cx*cy)*(1-coss) - (cz * seno))),(0 + ((cx*cz)*(1-coss) + (cy * seno))));

	glColor3f(0,0,1);
	glVertex3f((((-1+ax)*bx)+((cy*cx)*(1-coss) + (cz * seno))),(((3+ay)*by)+(pow(cy,cy)*(1-coss) + coss)),(0+((cy*cz)*(1-coss) - (cx * seno))));

	glColor3f(1,0,1);
	glVertex3f(((0+ax)*bx+((cx*cz)*(1-coss) - (cy * seno))),((2+ay)*by+((cy*cz)*(1-coss) + (cx * seno))),0+(pow(cz,cz)*(1-coss) + coss));
}

void init(){
	glClearColor(0,0,0,0);
	gluOrtho2D(-5,5,-5,5);
}

void display(){
	GLdouble theta = 90; //declaracao de theta
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();

	triangulo(0,0,1,1,0,0,0,0); 
	//ax,ay sao parametros da translocacao
	//bx, by sao parametros da escala
	//theta, cx,cy,cz sao parametros da rotacao
	//a funcao recebe na respectiva ordem acima

	glEnd();

	glPopMatrix();
	glFlush();
}

int main(int argc, char ** argv){
	glutInit(&argc, argv);
	glutInitWindowSize(600,400);
	glutInitWindowPosition(10,50);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);    
	glutCreateWindow("Transformacoes");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}

