#include<Windows.h>
#include<gl/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <time.h>
#include <iostream>
#include <ctime>
#include <string>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#include <sstream>
using namespace std;





float xxxx =0;
GLfloat walkX = 3.5, walkY = 3, lookX = 0, lookY = 0;
GLint world = 1;
GLint doll = -1;
int ggf = -10;
int gg = -5;
GLfloat AmbientLight[] = { 0.3,0.3,0.3,1.0 };                  //Initialization values for lighting
GLfloat DiffuseLight[] = { 0.8,0.8,0.8,1.0 };
GLfloat SpecularLight[] = { 1.0,1.0,1.0,1.0 };
GLfloat SpecRef[] = { 0.7,0.7,0.7,1.0 };
GLint Shine = 128;
GLuint makeaTree;
GLfloat h, w, y = -1.5, mx = 0.0, my = 0.0, mz = -6.0, y2 = -1.4, d = -100.0;
bool s = 1, qq = 0;
GLfloat angle = 0.0f, aspect, loca, locp;
bool pause = 0;
float xrr, yrr, zrr;

///////////////tree/////////////////

void makeCylinder(float height, float base) {
	GLUquadric* obj = gluNewQuadric();
	glColor3f(0, .5, 0);
	glPushMatrix();
	glRotatef(-90, 1.0, 0.0, 0.0);
	gluCylinder(obj, base, base - (0.2 * base), height, 20, 20);
	glPopMatrix();
	glutSwapBuffers();
}

void makeTree(float height, float base) {

	float angle;
	makeCylinder(height, base);
	glTranslatef(0, height, 0.0);
	height -= height * .2;
	base -= base * 0.3;
	for (int a = 0; a < 3; a++) {
		angle = rand() % 50 + 20;
		if (angle > 48)
			angle = -(rand() % 50 + 20);
		if (height > 1) {
			glPushMatrix();
			glRotatef(angle, 1, 0.0, 1);
			makeTree(height, base);
			glPopMatrix();

		}
	}

}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	makeaTree = glGenLists(1);
	glNewList(makeaTree, GL_COMPILE);

	makeTree(1.8, 0.2);
	glEndList();
}

///////////////////doll//////////////

void legleft()
{
	glPushMatrix();
	glTranslatef(.3, -.5, 0);     //Specify the position for the left leg
	glRotatef(-90.0, 1, 0, 0);
	glScalef(.8, .8, .8);
	gluCylinder(gluNewQuadric(), .5, .5, .5, 30, 6);
	glPopMatrix();
}

void legright()
{
	glPushMatrix();
	glTranslatef(-.3, -.5, 0);     //Specify the position for the right leg
	glRotatef(-90.0, 1, 0, 0);
	glScalef(.8, .8, .8);
	gluCylinder(gluNewQuadric(), .5, .5, .5, 30, 6);
	glPopMatrix();
}

void armleft()
{
	glPushMatrix();
	glTranslatef(-.82, 0, .1);     //Specify the position for the left arm
	glRotatef(90, 0, 1, 0);
	glRotatef(-50, 1, 0, 0);
	gluCylinder(gluNewQuadric(), .15, .15, .48, 30, 6);
	glPopMatrix();
}

void armright()
{
	glPushMatrix();
	glTranslatef(.82, 0, .1);      //Specify the position for the right arm
	glRotatef(90, 0, 1, 0);
	glRotatef(-130, 1, 0, 0);
	gluCylinder(gluNewQuadric(), .15, .15, .48, 30, 6);
	glPopMatrix();
}

void handleft()
{
	glPushMatrix();
	glTranslatef(.82, 0, .1);     //Specify the position for the left hand
	glScalef(.4, .3, .3);
	gluSphere(gluNewQuadric(), .4, 100, 100);
	glPopMatrix();
}

void handright()
{
	glPushMatrix();
	glTranslatef(-.82, 0, .1);    //Specify the position for the right hand
	glScalef(.4, .3, .3);
	gluSphere(gluNewQuadric(), .4, 100, 100);
	glPopMatrix();
}

void head()
{
	glPushMatrix();
	glTranslatef(0, 1.2, 0);
	glScalef(.9, .9, .9);
	glColor3f(1.0, 0.8, 0.6);
	gluSphere(gluNewQuadric(), 1, 100, 100);
	glPopMatrix();
}

void footleft()
{
	glPushMatrix();
	glTranslatef(-.3, -.5, 0);
	glScalef(1.5, .3, 1.5);
	glColor3f(0.0, 0.0, 0.0);
	gluSphere(gluNewQuadric(), .3, 100, 100);
	glPopMatrix();
}

void footright()
{
	glPushMatrix();
	glTranslatef(.3, -.5, 0);
	glScalef(1.5, .3, 1.5);
	glColor3f(0.0, 0.0, 0.0);
	gluSphere(gluNewQuadric(), .3, 100, 100);
	glPopMatrix();
}

void bellyCoatbottom()
{
	glPushMatrix();
	glTranslatef(0, -.2, 0);
	glScalef(1, .7, 1);
	glRotatef(90.0, 1, 0, 0);
	gluDisk(gluNewQuadric(), 0, .8, 30, 30);
	glPopMatrix();
}

void BellyCoat()
{
	glPushMatrix();
	glTranslatef(0, .5, 0);
	glScalef(1, .7, 1);
	glRotatef(90.0, 1, 0, 0);
	gluCylinder(gluNewQuadric(), .6, .8, 1, 100, 100);
	glPopMatrix();
}

////////////////////////////////////////////








////////////////background///////////////

void background()
{

	glClearColor(0, 0, 0, 0);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);

}

/////////////pause and restatrt keys/////

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 27:
		exit(0);
		break;
	case 32:
		if (pause == 1) {
			qq = 0;
			pause = 0;

		}
		else if (pause == 0)
		{
			
			qq = 1;
			pause = 1;

		}
		break;
	case 127:
		if (s == 0) {
			mz = -6;
			ggf = -10;
			gg = -5;
			walkY = 3;
			d = -100;
			xxxx=0;
			s = 1;
			qq = 0;
			pause = 0;
		}
		break;}}

/////////////////movement keys///////////

void specialkey(int key, int x, int y)
{
	switch (key) {

	case GLUT_KEY_LEFT:
		walkX = -1.5;
		break;
	case GLUT_KEY_RIGHT:
		walkX = 3.5;
		break;
	}
}

/////////////////display/////////////////

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT |
		GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(mx, my, mz);

	glBegin(GL_QUADS);
	float z1 = 5.0, z2 = -2.0, zq;
	//////////////////////road//////////////////////////////////////
	glColor3f(.25f, 0.25f, 0.25f);
	glVertex3f(5.0f, y, z1);
	glVertex3f(-5.0f, y, z1);
	glVertex3f(-5.0f, y, d);
	glVertex3f(5.0f, y, d);
	/////////////////////////walk space/////////////////////////////
	glColor3f(1.0f, 1.0f, 1.0f);
	zq = z1;
	for (float i = 0.0; z1 - 2 > d; i = i++)
	{
		glVertex3f(2.0f, y2, z1);
		glVertex3f(3.0f, y2, z1);
		glVertex3f(3.0f, y2, z1 - 5);
		glVertex3f(2.0f, y2, z1 - 5);
		glVertex3f(-2.0f, y2, z1);
		glVertex3f(-3.0f, y2, z1);
		glVertex3f(-3.0f, y2, z1 - 5);
		glVertex3f(-2.0f, y2, z1 - 5);
		z1 = z1 - 7;
	}
	z1 = zq;
	zq = z1;
	////////////////////////edges/////////////////////////////////
	bool n = 0;
	for (int i = 0; z1 - 2 > d; i++)
	{
		if (n == 0)
		{
			glColor3f(1.0f, 0.0f, 0.0f);

			n = 1;
		}
		else if (n == 1)
		{
			glColor3f(1.0f, 1.0f, 0.0f);
			n = 0;
		}

		glVertex3f(5.0f, y + .3, z1);
		glVertex3f(4.5f, y + .3, z1);
		glVertex3f(4.5f, y + .3, z1 - 3);
		glVertex3f(5.0f, y + .3, z1 - 3);

		glVertex3f(-5.0f, y + .3, z1);
		glVertex3f(-4.5f, y + .3, z1);
		glVertex3f(-4.5f, y + .3, z1 - 3);
		glVertex3f(-5.0f, y + .3, z1 - 3);


		glVertex3f(4.5f, y + .3, z1);
		glVertex3f(4.5f, y, z1);
		glVertex3f(4.5f, y, z1 - 3);
		glVertex3f(4.5f, y + .3, z1 - 3);

		glVertex3f(-4.5f, y + .3, z1);
		glVertex3f(-4.5f, y, z1);
		glVertex3f(-4.5f, y, z1 - 3);
		glVertex3f(-4.5f, y + .3, z1 - 3);
		z1 = z1 - 3;
	}
	z1 = zq;
	glEnd();

	
	/////////////////////////////Doll//////////////////////////////////////
	glPushMatrix();
	if (world == 1)
	{
		glTranslatef(walkX, -.8, walkY);
		glRotatef(lookY, 0, 1, 0);
		glRotatef(lookX, 1, 0, 0);
	}


	//**Doll**
	glPushMatrix();
	glTranslatef(-1, 0, -5);
	if (doll == 1)
	{
		glTranslatef(walkX, -.8, walkY);
		glRotatef(lookY, 0, 1, 0);
		glRotatef(lookX, 1, 0, 0);
	}
	glColor3ub(50, 40, 60);
	legright();
	legleft();
	glColor3ub(255, 90, 0);
	armleft();
	armright();
	BellyCoat();
	bellyCoatbottom();
	glColor3ub(0, 185, 0);
	handleft();
	handright();
	glColor3ub(255, 222, 173);
	head();
	glColor3f(0.0, 0.0, 0.0);
	footleft();
	footright();
	glPopMatrix();
	glPopMatrix();                                    

	////////////////////////trees////////////////////////////
	int ss = -15;
	for (int i = 0; i > d; i--)
	{
		glPushMatrix();
		glTranslatef(-2, -1, ss);
		glRotatef(xrr, 1.0, 0.0, 0.0);
		glRotatef(yrr, 0.0, 1.0, 0.0);
		glRotatef(zrr, 0.0, 0.0, 1.0);
		glCallList(makeaTree);
		glLoadIdentity();
		glPopMatrix();
		ss = ss - 10;
	}

	int g = -10;
	for (int i = 0; i > d; i--)
	{
		glPushMatrix();

		glTranslatef(2, -1, g);
		glRotatef(xrr, 1.0, 0.0, 0.0);
		glRotatef(yrr, 0.0, 1.0, 0.0);
		glRotatef(zrr, 0.0, 0.0, 1.0);
		glCallList(makeaTree);
		glLoadIdentity();
		glPopMatrix();

		g = g - 10;
	}

	
	/////////////////////text////////////////////////////////

	if (s == 1 && qq == 1) {
		xxxx += 0.1;
	}

	if (s == 0)
	{
		int ww, bb;
		char hh[2];
		if (xxxx >= 10 && xxxx < 100)
		{
			int ssc = xxxx;
			ww = ssc % 10 + 48;
			ssc = ssc / 10;
			bb = ssc + 48;
			hh[1] = ww;
			hh[0] = bb;

		}
		else if (xxxx < 10) {
			hh[0] = xxxx + 48;
			hh[1] = '\0';
		}
		char n = hh[0];
		char *val = &n;

		glColor3f(1.0, 1.0, 1.0);
		glRasterPos3f(0, 2, walkY); //define position on the screen
		const char *string = "game over your score is : ";

		while (*string) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
		}
		if (xxxx < 10)
		{

			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *val);

		
		}
		if (xxxx > 10 && xxxx < 100)
		{

			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *val);


			n = hh[1];
			val = &n;

			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *val);
	


		}
	}
	////////////////////////////anemation///////////////////////////////

	float add=.5,pp=0;
	if(xxxx>15)
		{add=1;pp=.2;}

		if(xxxx>30)
		{add=1.5;pp=-.1;}

		if(xxxx>60)
		{add=2;}
	glutSwapBuffers();
	if (s == 1 && qq == 1) {
		if (walkX == 3.5)
		{

			for (int i = 0; i > d; i--)
			{
				if (walkY <= gg)
				{
					gg = gg - 10;
				}
				if (gg - walkY > -.6&&gg - walkY < -.4)
				{
					s = 0;
				}

			}
		}

		if (walkX == -1.5)
		{
			for (int i = 0; i > d; i--)
			{
				if (walkY <= ggf)
				{
					ggf = ggf - 10;
				}
				if (ggf - walkY > -.6&&ggf - walkY < -.4)
				{
					s = 0;
				}

			}
		}

		

		mz = mz + add;
		d = d - add;
		walkY -= add;


	}

	else if (s == 0)
	{
		mz = mz;
		d = d;
		walkY = walkY;
	}
}

//////////////////reshap/////////////////

void reshape(GLsizei  width, GLsizei  height)
{
	w = width;
	h = height;
	if (height == 0) height = 1;
	aspect = (GLfloat)width / (GLfloat)height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, aspect, 0.1f, 100.0f);
	gluLookAt(
		0, 1, 0,
		0, 1, -5,
		0, 1, 0
	);

}

////////////////////timer////////////////

void timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(90, timer, 0);
}

///////////////////main//////////////////

int main(int argc, char** argv)
{
	glutInit(&argc, argv);            // Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
	glutCreateWindow("3d");
	background();
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(0, timer, 0);
	glutSpecialFunc(specialkey);
	glutKeyboardFunc(keyboard);
	glutFullScreen();
	glutMainLoop();
	return 0;}