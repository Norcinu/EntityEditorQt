/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created: Wed 6. Apr 20:29:23 2011
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowClass
{
public:
    QPushButton *btnSave;
    QPushButton *btnLoadGraphic;
    QPushButton *btnLoadEntity;
    QGraphicsView *graphicsView;
    QListWidget *listWidget;
    QLabel *lblSelectView;
    QPushButton *btnNewEntity;
    QGroupBox *grpEntityData;
    QLineEdit *txtEntityName;
    QLineEdit *txtEntitySide;
    QLabel *label;
    QLabel *label_2;
    QPushButton *btnSetData;
    QLineEdit *txtEntityPosition;
    QLabel *label_3;
    QLineEdit *txtEntityDamage;
    QLabel *label_4;
    QPushButton *btnQuit;
    QPushButton *btnRemoveEntity;

    void setupUi(QWidget *WindowClass)
    {
        if (WindowClass->objectName().isEmpty())
            WindowClass->setObjectName(QString::fromUtf8("WindowClass"));
        WindowClass->resize(800, 550);
        WindowClass->setMaximumSize(QSize(800, 550));
        btnSave = new QPushButton(WindowClass);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setEnabled(false);
        btnSave->setGeometry(QRect(100, 510, 75, 23));
        btnLoadGraphic = new QPushButton(WindowClass);
        btnLoadGraphic->setObjectName(QString::fromUtf8("btnLoadGraphic"));
        btnLoadGraphic->setEnabled(false);
        btnLoadGraphic->setGeometry(QRect(190, 510, 75, 23));
        btnLoadEntity = new QPushButton(WindowClass);
        btnLoadEntity->setObjectName(QString::fromUtf8("btnLoadEntity"));
        btnLoadEntity->setGeometry(QRect(280, 510, 75, 23));
        graphicsView = new QGraphicsView(WindowClass);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 20, 640, 480));
        graphicsView->setFrameShadow(QFrame::Sunken);
        listWidget = new QListWidget(WindowClass);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(660, 40, 131, 161));
        listWidget->setViewMode(QListView::ListMode);
        lblSelectView = new QLabel(WindowClass);
        lblSelectView->setObjectName(QString::fromUtf8("lblSelectView"));
        lblSelectView->setGeometry(QRect(660, 20, 141, 16));
        btnNewEntity = new QPushButton(WindowClass);
        btnNewEntity->setObjectName(QString::fromUtf8("btnNewEntity"));
        btnNewEntity->setGeometry(QRect(10, 510, 75, 23));
        grpEntityData = new QGroupBox(WindowClass);
        grpEntityData->setObjectName(QString::fromUtf8("grpEntityData"));
        grpEntityData->setEnabled(true);
        grpEntityData->setGeometry(QRect(660, 210, 131, 331));
        grpEntityData->setCheckable(false);
        txtEntityName = new QLineEdit(grpEntityData);
        txtEntityName->setObjectName(QString::fromUtf8("txtEntityName"));
        txtEntityName->setGeometry(QRect(52, 30, 71, 20));
        txtEntitySide = new QLineEdit(grpEntityData);
        txtEntitySide->setObjectName(QString::fromUtf8("txtEntitySide"));
        txtEntitySide->setGeometry(QRect(52, 60, 71, 20));
        label = new QLabel(grpEntityData);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 46, 13));
        label_2 = new QLabel(grpEntityData);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 60, 21, 16));
        btnSetData = new QPushButton(grpEntityData);
        btnSetData->setObjectName(QString::fromUtf8("btnSetData"));
        btnSetData->setGeometry(QRect(30, 300, 75, 23));
        txtEntityPosition = new QLineEdit(grpEntityData);
        txtEntityPosition->setObjectName(QString::fromUtf8("txtEntityPosition"));
        txtEntityPosition->setGeometry(QRect(52, 90, 71, 20));
        label_3 = new QLabel(grpEntityData);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 90, 46, 13));
        txtEntityDamage = new QLineEdit(grpEntityData);
        txtEntityDamage->setObjectName(QString::fromUtf8("txtEntityDamage"));
        txtEntityDamage->setGeometry(QRect(52, 120, 71, 20));
        label_4 = new QLabel(grpEntityData);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 120, 41, 16));
        btnQuit = new QPushButton(WindowClass);
        btnQuit->setObjectName(QString::fromUtf8("btnQuit"));
        btnQuit->setGeometry(QRect(470, 510, 75, 23));
        btnRemoveEntity = new QPushButton(WindowClass);
        btnRemoveEntity->setObjectName(QString::fromUtf8("btnRemoveEntity"));
        btnRemoveEntity->setEnabled(false);
        btnRemoveEntity->setGeometry(QRect(370, 510, 81, 23));

        retranslateUi(WindowClass);

        QMetaObject::connectSlotsByName(WindowClass);
    } // setupUi

    void retranslateUi(QWidget *WindowClass)
    {
        WindowClass->setWindowTitle(QApplication::translate("WindowClass", "Entity Editor - Steven Gleed 2011", 0, QApplication::UnicodeUTF8));
        btnSave->setText(QApplication::translate("WindowClass", "Save", 0, QApplication::UnicodeUTF8));
        btnLoadGraphic->setText(QApplication::translate("WindowClass", "Load Graphic", 0, QApplication::UnicodeUTF8));
        btnLoadEntity->setText(QApplication::translate("WindowClass", "Load Entity", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        listWidget->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        lblSelectView->setText(QApplication::translate("WindowClass", "Select an Entity to view info", 0, QApplication::UnicodeUTF8));
        btnNewEntity->setText(QApplication::translate("WindowClass", "New Entity", 0, QApplication::UnicodeUTF8));
        grpEntityData->setTitle(QApplication::translate("WindowClass", "Entity Data View", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("WindowClass", "Name", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("WindowClass", "Side", 0, QApplication::UnicodeUTF8));
        btnSetData->setText(QApplication::translate("WindowClass", "Set Data", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("WindowClass", "Position", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("WindowClass", "Damage", 0, QApplication::UnicodeUTF8));
        btnQuit->setText(QApplication::translate("WindowClass", "Quit", 0, QApplication::UnicodeUTF8));
        btnRemoveEntity->setText(QApplication::translate("WindowClass", "Remove Entity", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WindowClass: public Ui_WindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
