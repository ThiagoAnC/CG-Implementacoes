#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

/*reference: http://www.songho.ca/opengl/gl_projectionmatrix.html*/
void projecaoPerspectiva(GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar)
{
	GLdouble xmin, xmax, ymin, ymax;

	GLdouble m[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	ymax = zNear * tan(fovy * M_PI / 360.0);
	ymin = -ymax;
	xmin = ymin * aspect;
	xmax = ymax * aspect;

	/*Matriz de projeção perspectiva, utilizando representação matricial no vetor!*/
	m[0] = (2.0 * zNear) / (xmax - xmin);
	m[1 + 4 * 1] = (2.0 * zNear) / (ymax - ymin);
	m[2 + 4 * 2] = -(zFar + zNear) / (zFar - zNear);
	m[0 + 4 * 2] = (xmax + xmin) / (xmax - xmin);
	m[1 + 4 * 2] = (ymax + ymin) / (ymax - ymin);
	m[3 + 4 * 2] = -1.0;
	m[2 + 4 * 3] = -(2.0 * zFar * zNear) / (zFar - zNear);
   
	/*lança a matriz!*/
	glMultMatrixd(m);
}

/*reference: http://www.songho.ca/opengl/gl_projectionmatrix.html*/
void projecaoOrtogonal(GLdouble xmin, GLdouble xmax, GLdouble ymin, GLdouble ymax, GLdouble zNear, GLdouble zFar){ 
    GLdouble m[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    m[0 + 4 * 0] = 2 / (xmax - xmin); 

    m[1 + 4 * 1] = 2 / (ymax - ymin); 

    m[2 + 4 * 2] = -2 / (zFar - zNear); 

    m[3 + 4 * 0] = -(xmax + xmin) / (xmax - xmin); 
    m[3 + 4 * 1] = -(ymax + ymin) / (ymax - ymin); 
    m[3 + 4 * 2] = -(zFar + zNear) / (zFar - zNear); 
    m[3 + 4 * 3] = 1; 
    
    glMultMatrixd(m);
} 

void init(){
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    double aspect = (double)viewport[2] / (double)viewport[3];
    
    
    projecaoPerspectiva(90, aspect, 1, 100);
    //projecaoOrtogonal(0, 4, 0, 4, 10, 40);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();



    static float angle = 0;
    angle += 0.5f;

	//cubo rosa
    glPushMatrix();
        glTranslatef(0,0,-30);
        glRotatef(-0.4, -angle, 0.9, 0.0);
        glColor3ub(255,13,255);
        glutSolidCube(5);
    glPopMatrix();

	//cubo do fundo
    glPushMatrix();
        glTranslatef(0, 0,-40);
        glRotatef(angle, 0.1, 0.2, 0.5);
        glColor3ub(255,13,0);
        glutSolidCube(5);
    glPopMatrix();

	
	//cubo vermelho
	glPushMatrix();
        glTranslatef(10,-10,-40);
        glRotatef(angle, 0.1, 0.2, 0.5);
        glColor3ub(255,0,0);
        glutSolidCube(5);
    glPopMatrix();
	
	//cubo verde
    glPushMatrix();
        glTranslatef(10,10,-20);
        glRotatef(angle, 0.1, 0.2, 0.5);
        glColor3ub(0,255,0);
        glutSolidCube(5);
    glPopMatrix();


	//cubo azul
    glPushMatrix();
        glTranslatef(-10,10,-30);
        glRotatef(angle, 0.1, 0.2, 0.0);
        glColor3ub(0,0,255);
        glutSolidCube(5);
    glPopMatrix();

	//cubo amarelo
    glPushMatrix();
        glTranslatef(-10,-10,-20);
        glRotatef(angle, 0.1, 0.2, 0.5);
        glColor3ub(255,255,0);
        glutSolidCube(5);
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
}

void timer(int extra)
{
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(800,600);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutCreateWindow("CUBES");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);

    init();

    glutMainLoop();
    return 0;
}
