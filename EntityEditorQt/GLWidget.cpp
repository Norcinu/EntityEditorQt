#include <QtGui/QMouseEvent>
#include "GLWidget.h"
#include "Visualisation.h"

GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent), vis(new Visualisation)
{
    setMouseTracking(true);
}

GLWidget::~GLWidget()
{
	delete vis;
}

void GLWidget::initializeGL() 
{
	vis->Initialise(0,0);
   /* glDisable(GL_TEXTURE_2D);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_COLOR_MATERIAL);
    glEnable(GL_BLEND);
    glEnable(GL_POLYGON_SMOOTH);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0.5, 0.5, 0.5, 0.5);*/
}

void GLWidget::resizeGL(int w, int h) 
{
	vis->SetDimensions(h, w);
	vis->Resize();
    //glViewport(10, 20, w, h);
    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    //gluOrtho2D(0, w, 0, h); // 0,0
    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();
}

void GLWidget::paintGL() 
{
	vis->BeginScene();
	vis->EndScene();
	//glClear(GL_COLOR_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);
 //   glColor3f(0.5,0.3,0.7);
	//
	//glBegin(GL_POLYGON);
	//	glVertex3f( 0.0f, 1.0f, 0.0f);				// Top
	//	glVertex3f( 100.0f,500.0f, 0.0f);				// Bottom Left
	//	glVertex3f( 500.0f,100.0f, 0.0f);
 //   glEnd();
}

void GLWidget::mousePressEvent(QMouseEvent *event) 
{

}

void GLWidget::mouseMoveEvent(QMouseEvent *event) 
{
    printf("%d, %d\n", event->x(), event->y());
}

void GLWidget::keyPressEvent(QKeyEvent* event) 
{
    switch(event->key()) {
    case Qt::Key_Escape:
        close();
        break;
	case Qt::Key_W:
		break;
	case Qt::Key_S:
		break;
	case Qt::Key_A:
		break;
	case Qt::Key_D:
		break;
    default:
        event->ignore();
        break;
    }
}

void GLWidget::SetFilename(const char *f)
{
}