#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<GL/glut.h>

void init()
{
	gluOrtho2D(-300, 300, -300, 300);
}

//Desenha os 8 pontos da circuferência dado um ponto (x,y)
void CirclePoints(int x, int y)
{
	glColor3f(1, 0, 0);
	glBegin(GL_POINTS);
	
	glVertex2i(x,y);
	glVertex2i(x,-y);
	glVertex2i(-x,y);
	glVertex2i(-x,-y);
	
	glVertex2i(y,x);
	glVertex2i(y,-x);
	glVertex2i(-y,x);
	glVertex2i(-y,-x);
	
	glEnd();
	glFlush();
}

void desenhaCircunferencia(int r)
{
	//Valores utilizados
	int x,y;
	float d;
	
	//Valores iniciais
	x = 0;
	y = r;
	d = (5 / 4) - r;
	
	//Pintando os pontos iniciais(Neste caso, pinta apenas 4 pontos) [(0,R),(0,-R),(-0,R),(-0,-R),(R,0),(R,-0),(-R,0),(-R,-0)]
	CirclePoints(x,y);
	
	//Começando iterações
	while(y > x)
	{
		if(d < 0)
		{
			//Escolhemos E
			d += 2 * x + 3; //Incrementador de E = "2x  + 3"
			x++;
		}
		else 
		{
			//Escolhemos SE
			d += 2 * (x - y) + 5; //Incrementador de SE = "2x - 2y + 5"
			x++;
			y--;
		}
		
		//Pintando os novos pontos
		CirclePoints(x,y);
	}
}


void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0, 0, 0, 1);
	desenhaCircunferencia(200);
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(300, 300);
	
	glutCreateWindow("Desenho de circunferencia");
	
	init();
	glutDisplayFunc(Display);
	glutMainLoop();
	return 0;
}
