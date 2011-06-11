#include "window.h"
#include <qmessagebox.h>
#include <qfiledialog.h>
#include <qinputdialog.h>
#include <qsettings.h>
#include <qlistwidget.h>
#include <iostream>
#include "GameEntity.h"
#include "Visualisation.h"
#include "GLWidget.h"

#define E(i) entities[index]

Window::Window(QWidget *parent, Qt::WFlags flags) : QWidget(parent, flags), session_running(false), vis(new Visualisation)
{
	ui.setupUi(this);
	ui.grpEntityData->setVisible(false);

	connect(ui.listWidget, SIGNAL(currentRowChanged(int)), this, SLOT(SL_UpdateEntityTextView()));
	connect(ui.btnSave, SIGNAL(clicked()), this, SLOT(SL_SaveEntityInfo()));
	connect(ui.btnLoadEntity, SIGNAL(clicked()), this, SLOT(SL_LoadEntityFile()));
	connect(ui.btnLoadGraphic, SIGNAL(clicked()), this, SLOT(SL_LoadModel()));
	connect(ui.btnNewEntity, SIGNAL(clicked()), this, SLOT(SL_NewEntity()));
	connect(ui.btnRemoveEntity, SIGNAL(clicked()), this, SLOT(SL_RemoveEntity()));
	connect(ui.btnQuit, SIGNAL(clicked()), this, SLOT(close()));
	connect(ui.btnSetData, SIGNAL(clicked()), this, SLOT(SL_UpdateEntity()));

	glWidget = new GLWidget(ui.graphicsView);
	glWidget->resize(640, 480);
	glWidget->show();

	QRect r = ui.graphicsView->geometry();
	vis->Initialise(r.width(), r.height());
}

Window::~Window()
{
	delete vis;
	for (std::vector<GameEntity*>::iterator it = entities.begin(); it!=entities.end(); ++it)
		delete *it;
}

template<class T>
void Window::AddToList(T& str)
{
	ui.listWidget->addItem(str);
}

void Window::SL_UpdateEntityTextView()
{
	int index = ui.listWidget->currentRow();
	if (index == -1 || index > entities.size())
		return;
	//ui.graphicsView->set
	ui.txtEntityName->setText(QString::fromStdString(entities[index]->name));
	ui.txtEntitySide->setText(QString::fromStdString(entities[index]->side));
	ui.txtEntityPosition->setText(QString::fromStdString(entities[index]->position));
	ui.txtEntityDamage->setText(QString::fromStdString(entities[index]->damage));

	ui.listWidget->currentItem()->setText(QString::fromStdString(entities[index]->name));
}

void Window::SL_SaveEntityInfo()
{
	if (ui.listWidget->count() > 0 && ui.listWidget->currentRow() != -1) 
	{
		QString name;

		QSettings settings(QSettings::UserScope, "Microsoft", "Windows");
		settings.beginGroup("CurrentVersion/Explorer/Shell Folders");
		name = QFileDialog::getSaveFileName(this, tr("Save File"), settings.value("Personal").toString(), 
			tr("Entities (*.ent)"));

		if (!name.isEmpty())
		{
			//write file
		}
		else
		{
			QMessageBox::warning( this, "Saving..", "Failed to save file." );
		}
	}
	else
	{
		QMessageBox::warning(this, "Warning..", "Please Select an Entity.");
	}
}

void Window::SL_NewEntity()
{
	QStringList items;
	items << "2D" << "3D";
	
	bool ok;
	QString text = QInputDialog::getItem(this, "Choose Entity type","Type", items, 0, false, &ok);

	if (ok && !text.isEmpty())
	{
		session_running = true;

		// might not be a need for two different types.
		if (text == "2D")
		{
			GameEntity2D* entity = new GameEntity2D(qPrintable(text));
			entities.push_back(entity);
		}
		else
		{
			GameEntity3D* entity = new GameEntity3D(qPrintable(text));
			entities.push_back(entity);
		}

		QString name = "Entity " + QString::number(entities.size());
		AddToList(name);

		ui.btnLoadEntity->setEnabled(true);
		ui.btnLoadGraphic->setEnabled(true);
		ui.btnRemoveEntity->setEnabled(true);
		ui.btnSave->setEnabled(true);

		SEG_ToggleGroupBoxView();
	}
}

void Window::SL_LoadEntityFile()
{
}

void Window::SL_LoadModel()
{
	if (entities.size() > 0)
	{
		int index = ui.listWidget->currentRow();
		if (index == -1)
		{
			QMessageBox msg;
			msg.setText("Please select a valid entity to load the file again.");
			msg.setStandardButtons(QMessageBox::Ok);
			msg.setDefaultButton(QMessageBox::Ok);
			msg.exec();
		}
		else
		{
			QString extension_type;
			if (entities[index]->entity_type == "2D")
				extension_type = "Bitmaps (*.bmp)";
			else
				extension_type = "Mesh Files (*.obj *.txt *.3ds)";

			QSettings settings(QSettings::UserScope, "Microsoft", "Windows");
			settings.beginGroup("CurrentVersion/Explorer/Shell Folders");
			QString name = QFileDialog::getOpenFileName(this, tr("Load Entity"), settings.value("Personal").toString(), extension_type);

		}
	}
}

void Window::SL_UpdateEntity()
{
	int index = ui.listWidget->currentRow();
	QString convertor;
	if (index == -1)
	{
		convertor = ui.txtEntityName->text();
		entities.back()->name = convertor.toStdString();
		convertor = ui.txtEntitySide->text();
		entities.back()->side = convertor.toStdString();
		convertor = ui.txtEntityPosition->text();
		entities.back()->position = convertor.toStdString();
		convertor = ui.txtEntityDamage->text();
		entities.back()->damage = convertor.toStdString();
	}
	else
	{
		convertor = ui.txtEntityName->text();
		entities[index]->name = convertor.toStdString();
		convertor = ui.txtEntitySide->text();
		entities[index]->side = convertor.toStdString();
		convertor = ui.txtEntityPosition->text();
		entities[index]->position = convertor.toStdString();
		convertor = ui.txtEntityDamage->text();
		entities[index]->damage = convertor.toStdString();
	}
	//ui.listWidget->item(ui.listWidget->count()-1)->setText(convertor);
	//emit ui.listWidget->repaint();
}

void Window::SL_RemoveEntity()
{
	int index = ui.listWidget->currentRow();
	if (index == -1)
	{
		QMessageBox msg;
		msg.setText("Please select a valid entity to remove.\nTry again.");
		msg.setStandardButtons(QMessageBox::Ok);
		msg.setDefaultButton(QMessageBox::Ok);
		msg.exec();
	}
	else
	{
		std::shared_ptr<QListWidgetItem> item(ui.listWidget->takeItem(index));
		entities.erase(entities.begin() + index);
		SEG_ToggleGroupBoxView();
	}
}

void Window::SEG_ToggleGroupBoxView()
{
	if (session_running || entities.size() == 0)
	{
		ui.txtEntityName->setText("");
		ui.txtEntityDamage->setText("");
		ui.txtEntitySide->setText("");
		ui.txtEntityPosition->setText("");
		if (!ui.grpEntityData->isVisible())
			ui.grpEntityData->setVisible(true);
	}
	
	if (!session_running)
		ui.grpEntityData->setVisible(false);
}