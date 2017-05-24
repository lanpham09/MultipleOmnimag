/********************************************************************************
** Form generated from reading UI file 'PointSelectWindow.ui'
**
** Created: Fri Nov 1 12:55:43 2013
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POINTSELECTWINDOW_H
#define UI_POINTSELECTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>
#include "GUI/VideoDisplayWidget.h"

QT_BEGIN_NAMESPACE

class Ui_PointSelectWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    VideoDisplayWidget *VideoDisplay;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PointSelectWindow)
    {
        if (PointSelectWindow->objectName().isEmpty())
            PointSelectWindow->setObjectName(QString::fromUtf8("PointSelectWindow"));
        PointSelectWindow->resize(708, 708);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PointSelectWindow->sizePolicy().hasHeightForWidth());
        PointSelectWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(PointSelectWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 702, 602));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        VideoDisplay = new VideoDisplayWidget(gridLayoutWidget);
        VideoDisplay->setObjectName(QString::fromUtf8("VideoDisplay"));
        sizePolicy.setHeightForWidth(VideoDisplay->sizePolicy().hasHeightForWidth());
        VideoDisplay->setSizePolicy(sizePolicy);
        VideoDisplay->setMinimumSize(QSize(700, 600));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        VideoDisplay->setFont(font);
        VideoDisplay->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(VideoDisplay, 0, 0, 1, 1);

        PointSelectWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PointSelectWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 708, 25));
        PointSelectWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(PointSelectWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        PointSelectWindow->setStatusBar(statusbar);

        retranslateUi(PointSelectWindow);

        QMetaObject::connectSlotsByName(PointSelectWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PointSelectWindow)
    {
        PointSelectWindow->setWindowTitle(QApplication::translate("PointSelectWindow", "Point Select Window", 0, QApplication::UnicodeUTF8));
        VideoDisplay->setText(QApplication::translate("PointSelectWindow", "Point Display", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PointSelectWindow: public Ui_PointSelectWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POINTSELECTWINDOW_H
