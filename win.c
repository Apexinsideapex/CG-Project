#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>

float rot=0;

void drawtri()
{
	glBegin(GL_TRIANGLES);
		glVertex3f(0,0,0);
		glVertex3f(5,0,0);
		glVertex3f(2,7.2,0);
	glEnd();
}

void rotate()
{
	rot = fmod(rot+1,360);
}

void display()
{
	glMatrixMode(GL_MODELVIEW);
	glColor3f(0,1,0);
	glPushMatrix();
	glutWireTorus(1.4,1.4,8,10);
	
	glPushMatrix(); //blade1
	glTranslatef(2,1.5,0);	
	glRotatef(-120+rot,0,0,1);
	drawtri();
	glPopMatrix();

	glPushMatrix();//blade2
	glTranslatef(-2.3,1,0);	
	glRotatef(0+rot,0,0,1);
	drawtri();
	glPopMatrix();

	glPushMatrix();//blade3
	glTranslatef(0,-2.7,0);	
	glRotatef(110+rot,0,0,1);
	drawtri();
	glPopMatrix();

	glColor3f(0,0,1);
	glPushMatrix();//base
	glTranslatef(-2,-7,0);	
	drawtri();
	glPopMatrix();

	glColor3f(1,0,1);
	glPushMatrix();
	glTranslatef(-2,-12,0);
	glRecti(0,0,5,5);
	glPopMatrix();

	glutSwapBuffers();

	//glFlush();
}

void init()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glOrtho(-15,15,-15,15,-10,10);
}

void men(int val)
{
	switch(val)
	{
		case 1: //col = 1;
				break;
		case 2: exit(0);
				break;
	}

	glutPostRedisplay();
}


int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutCreateWindow("Windmill");
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutDisplayFunc(display);
	glutCreateMenu(men);
	glutIdleFunc(rotate);

	glutAddMenuEntry("Start Rotation",1);
	glutAddMenuEntry("Exit",2);

	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutInitWindowSize(500,500);
	init();
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
}
