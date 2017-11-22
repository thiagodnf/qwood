/********************************************************************************
** Form generated from reading UI file 'qdialoghash.ui'
**
** Created: Mon Mar 14 14:39:36 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QDIALOGHASH_H
#define UI_QDIALOGHASH_H

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

class Ui_QDialogHash
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *padraolabel;

    void setupUi(QDialog *QDialogHash)
    {
        if (QDialogHash->objectName().isEmpty())
            QDialogHash->setObjectName(QString::fromUtf8("QDialogHash"));
        QDialogHash->resize(253, 122);
        buttonBox = new QDialogButtonBox(QDialogHash);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(100, 80, 141, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        verticalLayoutWidget = new QWidget(QDialogHash);
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

        padraolabel = new QLabel(verticalLayoutWidget);
        padraolabel->setObjectName(QString::fromUtf8("padraolabel"));

        horizontalLayout->addWidget(padraolabel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(QDialogHash);
        QObject::connect(buttonBox, SIGNAL(accepted()), QDialogHash, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QDialogHash, SLOT(reject()));

        QMetaObject::connectSlotsByName(QDialogHash);
    } // setupUi

    void retranslateUi(QDialog *QDialogHash)
    {
        QDialogHash->setWindowTitle(QApplication::translate("QDialogHash", "Dialog", 0));
        label->setText(QApplication::translate("QDialogHash", "Digite o tamanho da tabela Hash:", 0));
        label_2->setText(QApplication::translate("QDialogHash", "Min: 3", 0));
        padraolabel->setText(QApplication::translate("QDialogHash", "Padr\303\243o: 7", 0));
    } // retranslateUi

};

namespace Ui {
    class QDialogHash: public Ui_QDialogHash {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QDIALOGHASH_H
