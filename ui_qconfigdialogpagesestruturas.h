/********************************************************************************
** Form generated from reading UI file 'qconfigdialogpagesestruturas.ui'
**
** Created: Tue Feb 15 15:04:26 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QCONFIGDIALOGPAGESESTRUTURAS_H
#define UI_QCONFIGDIALOGPAGESESTRUTURAS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QConfigDialogPagesEstruturas
{
public:
    QWidget *tab;
    QWidget *tab1;

    void setupUi(QTabWidget *QConfigDialogPagesEstruturas)
    {
        if (QConfigDialogPagesEstruturas->objectName().isEmpty())
            QConfigDialogPagesEstruturas->setObjectName(QString::fromUtf8("QConfigDialogPagesEstruturas"));
        QConfigDialogPagesEstruturas->resize(505, 320);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        QConfigDialogPagesEstruturas->addTab(tab, QString());
        tab1 = new QWidget();
        tab1->setObjectName(QString::fromUtf8("tab1"));
        QConfigDialogPagesEstruturas->addTab(tab1, QString());

        retranslateUi(QConfigDialogPagesEstruturas);

        QConfigDialogPagesEstruturas->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(QConfigDialogPagesEstruturas);
    } // setupUi

    void retranslateUi(QTabWidget *QConfigDialogPagesEstruturas)
    {
        QConfigDialogPagesEstruturas->setWindowTitle(QApplication::translate("QConfigDialogPagesEstruturas", "TabWidget", 0, QApplication::UnicodeUTF8));
        QConfigDialogPagesEstruturas->setTabText(QConfigDialogPagesEstruturas->indexOf(tab), QApplication::translate("QConfigDialogPagesEstruturas", "Tab 1", 0, QApplication::UnicodeUTF8));
        QConfigDialogPagesEstruturas->setTabText(QConfigDialogPagesEstruturas->indexOf(tab1), QApplication::translate("QConfigDialogPagesEstruturas", "Tab 2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QConfigDialogPagesEstruturas: public Ui_QConfigDialogPagesEstruturas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QCONFIGDIALOGPAGESESTRUTURAS_H
