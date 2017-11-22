/********************************************************************************
** Form generated from reading UI file 'qdialogarvorebplus.ui'
**
** Created: Mon Mar 14 14:39:36 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QDIALOGARVOREBPLUS_H
#define UI_QDIALOGARVOREBPLUS_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QDialog>
#include <QDialogButtonBox>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QWidget>

QT_BEGIN_NAMESPACE

class Ui_QDialogArvoreBPlus
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *padraolabel;

    void setupUi(QDialog *QDialogArvoreBPlus)
    {
        if (QDialogArvoreBPlus->objectName().isEmpty())
            QDialogArvoreBPlus->setObjectName(QString::fromUtf8("QDialogArvoreBPlus"));
        QDialogArvoreBPlus->resize(251, 131);
        buttonBox = new QDialogButtonBox(QDialogArvoreBPlus);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(20, 80, 221, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        verticalLayoutWidget = new QWidget(QDialogArvoreBPlus);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 231, 65));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMaxLength(2);

        verticalLayout->addWidget(lineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        padraolabel = new QLabel(verticalLayoutWidget);
        padraolabel->setObjectName(QString::fromUtf8("padraolabel"));

        horizontalLayout->addWidget(padraolabel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(QDialogArvoreBPlus);
        QObject::connect(buttonBox, SIGNAL(accepted()), QDialogArvoreBPlus, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QDialogArvoreBPlus, SLOT(reject()));

        QMetaObject::connectSlotsByName(QDialogArvoreBPlus);
    } // setupUi

    void retranslateUi(QDialog *QDialogArvoreBPlus)
    {
        QDialogArvoreBPlus->setWindowTitle(QApplication::translate("QDialogArvoreBPlus", "Dialog", 0));
        label->setText(QApplication::translate("QDialogArvoreBPlus", "Digite a ordem da \303\241rvore B+:", 0));
        label_2->setText(QApplication::translate("QDialogArvoreBPlus", "Min: 1", 0));
        label_3->setText(QApplication::translate("QDialogArvoreBPlus", "Max: 10", 0));
        padraolabel->setText(QApplication::translate("QDialogArvoreBPlus", "Padr\303\243o: 2", 0));
    } // retranslateUi

};

namespace Ui {
    class QDialogArvoreBPlus: public Ui_QDialogArvoreBPlus {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QDIALOGARVOREBPLUS_H
