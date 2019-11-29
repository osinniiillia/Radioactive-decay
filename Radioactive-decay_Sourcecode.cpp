//если расстояние стало меньше определенной величины масса должна увеличится до значения 40 т.е. величины бомбардируемой частички
#include <cstdlib>
#include <glut.h>
#define M_PI       3.14159265358979323846
#include <vector>
#include <cmath>
using namespace std;

const float DT = 0.01;

struct P
{
	float x;
	float y;
	float vx;
	float vy;
	float m;
};

vector<P> p;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	for (vector<P>::iterator i = p.begin(); i != p.end(); ++i)
	{
		if (i->m <= 45)
		{
	
			glPointSize(8);
			glColor3f(0, 1, 1);
			glBegin(GL_POINTS);
			int a = 0;
			float x = i->m * cos(a * M_PI / 18);
			float y = i->m * sin(a * M_PI / 18);
			x = i->m * cos((a + 1) * M_PI / 18);
			y = i->m * sin((a + 1) * M_PI / 18);
			glVertex2f(i->x + x, i->y + y);
	
			glEnd();
		}
		else
		{
			
				glPointSize(8);
				glColor3f(0, 1, 0);
				glBegin(GL_POINTS);
				int a = 0;
				float x = i->m * cos(a * M_PI / 18);
				float y = i->m * sin(a * M_PI / 18);
				x = i->m * cos((a + 1) * M_PI / 18);
				y = i->m * sin((a + 1) * M_PI / 18);
				glVertex2f(i->x + x, i->y + y);
		
		}
	}
	glutSwapBuffers();
}

void timer(int = 0)
{
	//for (auto &i : p)
	//	i.vx = ...
	for (vector<P>::iterator i = p.begin(); i != p.end(); ++i)
		for (vector<P>::iterator j = p.begin(); j != p.end(); ++j)
			if (i != j)
			{
				float d = sqrt((i->x - j->x) * (i->x - j->x) + (i->y - j->y) * (i->y - j->y)); //проверяет расстояние
				if (d < i->m + j->m)
				{
					float f = (i->m + j->m - d)*75;  //сила вз-я
					i->vx += f * (i->x - j->x) / d / i->m * DT;
					i->vy += f * (i->y - j->y) / d / i->m * DT;
					j->vx -= f * (i->x - j->x) / d / j->m * DT;
					j->vy -= f * (i->y - j->y) / d / j->m * DT;

					j->m = 40;//увеличивает массу
					i->m = 40;
					
				}

			}
	for (vector<P>::iterator i = p.begin(); i != p.end(); ++i)
	{
		i->x += i->vx * DT;
		i->y += i->vy * DT;
		if (i->x < 0)          //частицы не вылетают
			i->x += 1920;
		if (i->y < 0)
			i->y += 1080;
		if (i->x > 1920)
			i->x -= 1920;
		if (i->y > 1080)
			i->y -= 1080;
	}
	display();
	glutTimerFunc(10, timer, 0);
}

int main(int argc, char** argv)
{
	
	
	P p0 = { 1460, 540, -300, 0, 10 };
	p.push_back(p0);
	for (int i = 0; i < 40; ++i)
	{
		P p0 = {rand() % 600 -1675, rand() % 600 - 750 , 0, 0, 2 };
		p.push_back(p0);
	}

	/*for (int k = 0; k < 6;) {
		if (sqrt((p[k].x - p0.x) * (p[k].x - p0.x) + (p[k].x - p0.x) * (p[k].x - p0.x)) < 1) {
			p[k].m = 40;
		}
	}*/
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1920, 1080);
	glutFullScreen;
	glutCreateWindow("Уран");
	glClearColor(0, 0, 0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 1920, 1080, 0, -1, 1);
	glutDisplayFunc(display);
	timer();
	glutMainLoop();
}

