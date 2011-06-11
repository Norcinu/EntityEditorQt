#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QtOpenGL/QGLWidget>

class Visualisation;

class GLWidget : public QGLWidget 
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent);
	~GLWidget();

	void SetFilename(const char *f);

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);

private:
	Visualisation *vis;
};

#endif  
