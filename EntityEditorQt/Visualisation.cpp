#include "Visualisation.h"
#include <QtOpenGL\qgl.h>
#include <cassert>

Visualisation::Visualisation(void) : panelWidth(0), panelHeight(0), xPosition(0), yPosition(0)
{
}


Visualisation::~Visualisation(void)
{
	if (!drawables.empty())
	{
		for (size_t i = 0; i < drawables.size(); ++i)
			delete drawables[i];
	}
}

bool Visualisation::Initialise(const int width, const int height)
{
	panelWidth = width;
	panelHeight = height;

	glDisable(GL_TEXTURE_2D);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_COLOR_MATERIAL);
    glEnable(GL_BLEND);
    glEnable(GL_POLYGON_SMOOTH);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0.5, 0.5, 0.5, 0.5);

	return true;
}

bool Visualisation::LoadEntity(const char *filename)
{
	assert (filename != nullptr);

	return true;
}

void Visualisation::Resize()
{
	glViewport(10, 20, panelWidth, panelHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, panelWidth, 0, panelHeight); // 0,0
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Visualisation::BeginScene()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);
	glColor3f(0.5,0.3,0.7);
	
	glBegin(GL_POLYGON);
	glVertex3f( 0.0f, 1.0f, 0.0f);				// Top
	glVertex3f( 100.0f,500.0f, 0.0f);				// Bottom Left
	glVertex3f( 500.0f,100.0f, 0.0f);
}

void Visualisation::EndScene()
{
	glEnd();
}