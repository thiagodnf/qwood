/********************************************************************************
** Form generated from reading UI file 'qdialogabrir.ui'
**
** Created: Mon Mar 14 14:39:36 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QDIALOGABRIR_H
#define UI_QDIALOGABRIR_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QCheckBox>
#include <QDialog>
#include <QDialogButtonBox>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

QT_BEGIN_NAMESPACE

class Ui_QDialogAbrir
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *ArvoresGroupBox;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout;
    QCheckBox *BSTCheckBox;
    QCheckBox *TRIECheckBox;
    QCheckBox *AVLCheckBox;
    QCheckBox *SPLAYCheckBox;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *BCheckBox;
    QCheckBox *BPlusCheckBox;
    QCheckBox *OpenHashCheckBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *arquivoLabel;
    QLineEdit *diretorioLineEdit;
    QPushButton *abrirPushButton;

    void setupUi(QDialog *QDialogAbrir)
    {
        if (QDialogAbrir->objectName().isEmpty())
            QDialogAbrir->setObjectName(QString::fromUtf8("QDialogAbrir"));
        QDialogAbrir->setWindowModality(Qt::NonModal);
        QDialogAbrir->resize(336, 195);
        buttonBox = new QDialogButtonBox(QDialogAbrir);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(110, 150, 221, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        ArvoresGroupBox = new QGroupBox(QDialogAbrir);
        ArvoresGroupBox->setObjectName(QString::fromUtf8("ArvoresGroupBox"));
        ArvoresGroupBox->setGeometry(QRect(10, 40, 321, 111));
        layoutWidget_2 = new QWidget(ArvoresGroupBox);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 20, 80, 80));
        verticalLayout = new QVBoxLayout(layoutWidget_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        BSTCheckBox = new QCheckBox(layoutWidget_2);
        BSTCheckBox->setObjectName(QString::fromUtf8("BSTCheckBox"));

        verticalLayout->addWidget(BSTCheckBox);

        TRIECheckBox = new QCheckBox(layoutWidget_2);
        TRIECheckBox->setObjectName(QString::fromUtf8("TRIECheckBox"));

        verticalLayout->addWidget(TRIECheckBox);

        AVLCheckBox = new QCheckBox(layoutWidget_2);
        AVLCheckBox->setObjectName(QString::fromUtf8("AVLCheckBox"));

        verticalLayout->addWidget(AVLCheckBox);

        SPLAYCheckBox = new QCheckBox(layoutWidget_2);
        SPLAYCheckBox->setObjectName(QString::fromUtf8("SPLAYCheckBox"));

        verticalLayout->addWidget(SPLAYCheckBox);

        layoutWidget_3 = new QWidget(ArvoresGroupBox);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(100, 20, 89, 80));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        BCheckBox = new QCheckBox(layoutWidget_3);
        BCheckBox->setObjectName(QString::fromUtf8("BCheckBox"));

        verticalLayout_2->addWidget(BCheckBox);

        BPlusCheckBox = new QCheckBox(layoutWidget_3);
        BPlusCheckBox->setObjectName(QString::fromUtf8("BPlusCheckBox"));

        verticalLayout_2->addWidget(BPlusCheckBox);

        OpenHashCheckBox = new QCheckBox(layoutWidget_3);
        OpenHashCheckBox->setObjectName(QString::fromUtf8("OpenHashCheckBox"));

        verticalLayout_2->addWidget(OpenHashCheckBox);

        layoutWidget = new QWidget(QDialogAbrir);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 9, 321, 27));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        arquivoLabel = new QLabel(layoutWidget);
        arquivoLabel->setObjectName(QString::fromUtf8("arquivoLabel"));

        horizontalLayout->addWidget(arquivoLabel);

        diretorioLineEdit = new QLineEdit(layoutWidget);
        diretorioLineEdit->setObjectName(QString::fromUtf8("diretorioLineEdit"));
        diretorioLineEdit->setEnabled(false);
        diretorioLineEdit->setMinimumSize(QSize(150, 0));

        horizontalLayout->addWidget(diretorioLineEdit);

        abrirPushButton = new QPushButton(layoutWidget);
        abrirPushButton->setObjectName(QString::fromUtf8("abrirPushButton"));

        horizontalLayout->addWidget(abrirPushButton);

#ifndef QT_NO_SHORTCUT
        arquivoLabel->setBuddy(diretorioLineEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(QDialogAbrir);
        QObject::connect(buttonBox, SIGNAL(accepted()), QDialogAbrir, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QDialogAbrir, SLOT(reject()));

        QMetaObject::connectSlotsByName(QDialogAbrir);
    } // setupUi

    void retranslateUi(QDialog *QDialogAbrir)
    {
        QDialogAbrir->setWindowTitle(QApplication::translate("QDialogAbrir", "Escolha do arquivo", 0));
        ArvoresGroupBox->setTitle(QApplication::translate("QDialogAbrir", "Estruturas de Dados", 0));
        BSTCheckBox->setText(QApplication::translate("QDialogAbrir", "BST", 0));
        TRIECheckBox->setText(QApplication::translate("QDialogAbrir", "TRIE", 0));
        AVLCheckBox->setText(QApplication::translate("QDialogAbrir", "AVL", 0));
        SPLAYCheckBox->setText(QApplication::translate("QDialogAbrir", "SPLAY", 0));
        BCheckBox->setText(QApplication::translate("QDialogAbrir", "\303\201rvore B", 0));
        BPlusCheckBox->setText(QApplication::translate("QDialogAbrir", "\303\201rvore B+", 0));
        OpenHashCheckBox->setText(QApplication::translate("QDialogAbrir", "Open Hash", 0));
        arquivoLabel->setText(QApplication::translate("QDialogAbrir", "Arquivo:", 0));
        abrirPushButton->setText(QApplication::translate("QDialogAbrir", "Abrir", 0));
    } // retranslateUi

};

namespace Ui {
    class QDialogAbrir: public Ui_QDialogAbrir {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QDIALOGABRIR_H
