#include<glut.h>
#include<Windows.h>
#include<math.h>
#include<iostream>

float timer = 10;
float red, green, blue;
int positionX[100];
int positionY[100];
bool SunInCenter = false;
bool simulate;

void myInit(void)
{

	glClearColor(0, 0, 0, 0);      // set the bg color to a bright white
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPointSize(10.0);		            //set the point size to 4 by 4 pixels
	glMatrixMode(GL_PROJECTION);// set up appropriate matrices- to be explained 
	glLoadIdentity();// to be explained
	gluOrtho2D(-1366, 1366, -1080, 1080.0);// to be explained
}



void DrawAsteroid(int posx, int posy, float radius, int num_segments)
{
	glColor3f(0.7, 1, 0.1);

	glBegin(GL_POLYGON);
	for (int i = 0; i < num_segments; i++)
	{

		float angle = 2 * 3.14f * float(i) / float(num_segments);//get the current angle 

		float x = (radius * cosf(angle + 0.5));//calculate the x component 
		float y = radius * sinf(angle);//calculate the y component 
		x = x + posx;
		y = y + posy;
		glVertex2f(x, y);//output vertex 

	}

	glEnd();
	glFlush();
}

void DrawCircle(float cx, float cy, float radius, int num_segments,bool isLines,float r,float g,float b)
{
	glColor3f(r, g, b);
	if (!isLines)
	{
		glBegin(GL_POLYGON);

	}
	else
	{
		glBegin(GL_LINE_LOOP);


	}
	for (int i = 0; i < num_segments; i++)
	{

			float angle = 2 * 3.14f * float(i) / float(num_segments);//get the current angle 

			float x = radius * cosf(angle);//calculate the x component 
			float y = radius * sinf(angle);//calculate the y component 
			int posx = x + cx;
			int posy = y + cy;
			glVertex2f(posx, posy);//output vertex 
			
	}	
	
	glEnd();
	glFlush();
}

void BigBangAnim(int segaments, int radius)
{
	float x, y;
	if (!SunInCenter)
	{

		for (int i = 0; i < segaments; i++)
		{

			float angle = 2 * 3.14 * i / segaments;
			x = (radius * cosf(angle)) + radius;
			y = (radius * sinf(angle)) + radius;
			DrawCircle(x, y, 100, 100, false, 1, 0.5, 0.2);

			Sleep(100);
			glutPostRedisplay();
			glClear(GL_COLOR_BUFFER_BIT);
			if (i == segaments - 1)
			{
				glClearColor(0, 0, 0, 1);

				SunInCenter = true;
			}

			else if (i == segaments - 2)
			{

				glClearColor(1, 1, 1, 1);

			}
			else if (i == segaments - 3)
			{

				glClearColor(0.8, 0.7, 0.2, 1);

			}
			else if (i == segaments - 5)
			{
				glClearColor(1, 0.8, 0.2, 1);

			}

			else if (i == segaments - 10)
			{
				glClearColor(1, 1, 0.1, 1);

			}
			else if (i >= segaments - 30)
			{
				DrawCircle(250, 300, 190, 190, false, 0.5, 0.6, 1);

			}
		}
	}
}

void circleRotate(int segaments)
{


	float x, y;
	int size;
	for (int i = 0; i < segaments; i++)
	{

		//SolarLines
		DrawCircle(0, 0, 100, 100, true, 1, 1, 1);
		DrawCircle(0, 0, 200, 200, true, 1, 1, 1);
		DrawCircle(0, 0, 300, 300, true, 1, 1, 1);
		DrawCircle(0, 0, 400, 400, true, 1, 1, 1);
		DrawCircle(0, 0, 500, 500, true, 1, 1, 1);
		DrawCircle(0, 0, 600, 600, true, 1, 1, 1);
		DrawCircle(0, 0, 700, 700, true, 1, 1, 1);
		DrawCircle(0, 0, 800, 800, true, 1, 1, 1);
		DrawCircle(0, 0, 30, 30, true, 1, 1, 0.2f);
		DrawCircle(0, 0, 100, 100, true, 1, 1, 1);
		DrawCircle(0, 0, 50, 50, false, 1, 1, 0.2);


		float angle = 2 * 3.14 * i / segaments;
		for (int i = 1; i < 9; i++)
		{

			switch (i)
			{
			case 1:
				size = 100;
				x = (size * cosf(angle)) + size;
				y = (size * sinf(angle)) + size;

				DrawCircle(-x + size, y - size, 25, 100, false, 0.5, 0.8, 0.2);

				break;
			case 2:
				size = 200;
				x = (size * cosf(angle)) + size;
				y = (size * sinf(angle)) + size;

				DrawCircle(x - size, y - size, 30, 100, false, 00.2, 0.5, 0.8);

				break;

			case 3:
				size = 300;
				x = (size * cosf(angle)) + size;
				y = (size * sinf(angle)) + size;

				DrawCircle(-x + size, y - size, 35, 100, false, 0.6, 0.3, 0.2);

				break;

			case 4:
				
				size = 400;
				x = (size * cosf(angle)) + size;
				y = (size * sinf(angle)) + size;

				DrawCircle(x - size, y - size, 40, 100, false, 0.1, 1, 0.25);

				break;

			case 5:
				
				size = 500;
				x = (size * cosf(angle)) + size;
				y = (size * sinf(angle)) + size;

				DrawCircle(-x + size, -y + size, 55, 100, false, 0.4, 0.15, 0.8);

				break;

			case 6:
				
				size = 600;
				x = (size * cosf(angle)) + size;
				y = (size * sinf(angle)) + size;

				DrawCircle(x - size, -y + size, 42, 100, false, 0.3, 0.55, 0.45);

				break;
			case 7:
				
				size = 700;
				x = (size * cosf(angle)) + size;
				y = (size * sinf(angle)) + size;

				DrawCircle(-x + size, y - size, 38, 100, false, 0.62, 0.3, 0.66);

			case 8:
				
				size = 800;
				x = (size * cosf(angle)) + size;
				y = (size * sinf(angle)) + size;

				DrawCircle(-x + size, -y + size, 60, 100, false, 1, 0.3, 0.66);

				break;
				break;
			default:
				break;

			}

		}

		Sleep(150);
		glClear(GL_COLOR_BUFFER_BIT);
		glutPostRedisplay();
	}
}


void anim()
{
	if (!simulate)
	{

		glClear(GL_COLOR_BUFFER_BIT);
		//SolarLines
		Sleep(100);
		DrawCircle(0, 0, 100, 100, true, 1, 1, 1);
		Sleep(100);
		DrawCircle(0, 0, 200, 200, true, 1, 1, 1);
		Sleep(100);
		DrawCircle(0, 0, 300, 300, true, 1, 1, 1);
		Sleep(100);
		DrawCircle(0, 0, 400, 400, true, 1, 1, 1);
		Sleep(100);
		DrawCircle(0, 0, 500, 500, true, 1, 1, 1);
		Sleep(100);
		DrawCircle(0, 0, 600, 600, true, 1, 1, 1);
		Sleep(100);
		DrawCircle(0, 0, 700, 700, true, 1, 1, 1);
		Sleep(100);
		DrawCircle(0, 0, 800, 800, true, 1, 1, 1);
		//Planets
		//	RotateCircle();
		Sleep(1000);
		DrawCircle(200, 20, 30, 50, false, 0.2, 0.2, 0.8);
		Sleep(1000);
		DrawCircle(0, 0, 50, 50, false, 1, 1, 0.1);
		Sleep(1000);
		DrawCircle(100, 50, 25, 50, false, 0.8 - red, 0.23 + green, 0.1 + blue);
		Sleep(800);
		DrawCircle(-200, 450, 40, 50, false, 0 + red, 0.5 - green, 0.3 + blue);
		Sleep(600);
		DrawCircle(-300, -420, 50, 50, false, 0.6 - red, 0.5 + green, 0.5 + blue);
		Sleep(1200);
		DrawCircle(500, 450, 65, 50, false, 0.8 - red, 0.2 + green, 0.3 + blue);
		Sleep(700);
		DrawCircle(-400, -50, 60, 50, false, 0.4 + red, 0.5 - green, 0.4 + blue);
		Sleep(1000);
		DrawCircle(150, -150, 50, 50, false, 0.8 - red, 0.5 - green, 0.3 + blue);
		Sleep(1000);
		DrawCircle(600, -520, 80, 80, false, 0.4 + red, 0.3 + green, 0.8 - blue);
		Sleep(1000);
		DrawCircle(-600, 520, 80, 80, false, 0.1 + red, 0.6 + green, 0.2 + blue);
		simulate = true;
	}
	else
	{

		while (simulate == true)
		{

			circleRotate(50);

		}
	}
	
}

int x = -500, y = 500;
int sizex = 25;

void DrawMovingCircle()
{
	
	do 
	{

		if (x < 0)
		{
			SunInCenter = false;
			DrawAsteroid(x, y, 50, 50);
			x = x + 5;
			y = y - 5;

			Sleep(20);
			
			glutPostRedisplay();
			glClear(GL_COLOR_BUFFER_BIT);

			if (-20 < x)
			{
				
				anim();
			}
			else if (-25 < x)
			{

				glClearColor(0, 0, 0, 1);

			}

			else if (-30 < x)
			{

				glClearColor(1, 1, 1, 1);

			}

		}
		DrawCircle(0, 0, 50, 50, false, 1, 1, 0.1);

	} while (x < 0);

}

void myDisplay(void)
{
	while (!simulate)
	{

		BigBangAnim(50, 200);
		if (SunInCenter)
		{

			DrawMovingCircle();

		}
	}
}



void main(int argc, char **argv)
{
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set the display mode
	glutInitWindowSize(640, 480);     // set the window size
	glutInitWindowPosition(100, 150); // set the window position on the screen
	glutCreateWindow("Big Bang & Solar System"); // open the screen window(with its exciting title)
	glutDisplayFunc(myDisplay);     // register the redraw function

//	glutKeyboardFunc(Keyboard_Callback_Function);
	//glutSpecialFunc(ArrowMove);
	myInit();
	glutMainLoop(); 		     // go into a perpetual loop
}