#ifndef WINDOW_H
#define WINDOW_H

#include <QtGui/QWidget>
#include "ui_window.h"
#include "ui_dialog.h"
#include <vector>

class GameEntity;
class Visualisation;
class GLWidget;

class Window : public QWidget
{
	Q_OBJECT

public:
	Window(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Window();

	template<class T>
	void AddToList(T& str);

public slots:
	void SL_UpdateEntityTextView();
	void SL_SaveEntityInfo();
	void SL_LoadEntityFile();
	void SL_LoadModel();
	void SL_NewEntity();
	void SL_UpdateEntity();
	void SL_RemoveEntity();

private:
	void SEG_ToggleGroupBoxView();
	
private:
	bool session_running;
	Ui::WindowClass ui;
	GLWidget *glWidget;
	Visualisation *vis;
	std::vector<GameEntity*> entities;
	//std::map<QString, ent_ptr> entity_map;
};

#endif // WINDOW_H
