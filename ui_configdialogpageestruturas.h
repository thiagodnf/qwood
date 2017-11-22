/********************************************************************************
** Form generated from reading UI file 'configdialogpageestruturas.ui'
**
** Created: Mon Mar 14 14:39:36 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGDIALOGPAGEESTRUTURAS_H
#define UI_CONFIGDIALOGPAGEESTRUTURAS_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QCheckBox>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QTabWidget>
#include <QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigDialogPageEstruturas
{
public:
    QWidget *trieTab;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *trieLayout;
    QLabel *trieLabel;
    QLineEdit *trieLineEdit;
    QWidget *arvoreBTab;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *arvoreBLayout;
    QLabel *arvoreBLabel;
    QLineEdit *arvoreBLineEdit;
    QWidget *arvoreBPlusTab;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *arvoreBPlusLayout;
    QLabel *arvoreBPlusLabel;
    QLineEdit *arvoreBPlusLineEdit;
    QWidget *hashTab;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *hashTamanhoTabelaLayout;
    QLabel *hashTamanhoTabelaLabel;
    QLineEdit *arvoreBPlusLineEdit_3;
    QGroupBox *hashGroupBox;
    QCheckBox *ativarFatorDeCargaCheckBox;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QTabWidget *ConfigDialogPageEstruturas)
    {
        if (ConfigDialogPageEstruturas->objectName().isEmpty())
            ConfigDialogPageEstruturas->setObjectName(QString::fromUtf8("ConfigDialogPageEstruturas"));
        ConfigDialogPageEstruturas->setWindowModality(Qt::NonModal);
        ConfigDialogPageEstruturas->resize(344, 249);
        ConfigDialogPageEstruturas->setAutoFillBackground(false);
        ConfigDialogPageEstruturas->setInputMethodHints(Qt::ImhDigitsOnly);
        ConfigDialogPageEstruturas->setTabPosition(QTabWidget::North);
        ConfigDialogPageEstruturas->setTabShape(QTabWidget::Rounded);
        trieTab = new QWidget();
        trieTab->setObjectName(QString::fromUtf8("trieTab"));
        horizontalLayoutWidget = new QWidget(trieTab);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 321, 41));
        trieLayout = new QHBoxLayout(horizontalLayoutWidget);
        trieLayout->setObjectName(QString::fromUtf8("trieLayout"));
        trieLayout->setContentsMargins(0, 0, 0, 0);
        trieLabel = new QLabel(horizontalLayoutWidget);
        trieLabel->setObjectName(QString::fromUtf8("trieLabel"));

        trieLayout->addWidget(trieLabel);

        trieLineEdit = new QLineEdit(horizontalLayoutWidget);
        trieLineEdit->setObjectName(QString::fromUtf8("trieLineEdit"));
        trieLineEdit->setInputMethodHints(Qt::ImhNone);
        trieLineEdit->setMaxLength(2);

        trieLayout->addWidget(trieLineEdit);

        ConfigDialogPageEstruturas->addTab(trieTab, QString());
        arvoreBTab = new QWidget();
        arvoreBTab->setObjectName(QString::fromUtf8("arvoreBTab"));
        horizontalLayoutWidget_2 = new QWidget(arvoreBTab);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 10, 321, 41));
        arvoreBLayout = new QHBoxLayout(horizontalLayoutWidget_2);
        arvoreBLayout->setObjectName(QString::fromUtf8("arvoreBLayout"));
        arvoreBLayout->setContentsMargins(0, 0, 0, 0);
        arvoreBLabel = new QLabel(horizontalLayoutWidget_2);
        arvoreBLabel->setObjectName(QString::fromUtf8("arvoreBLabel"));

        arvoreBLayout->addWidget(arvoreBLabel);

        arvoreBLineEdit = new QLineEdit(horizontalLayoutWidget_2);
        arvoreBLineEdit->setObjectName(QString::fromUtf8("arvoreBLineEdit"));
        arvoreBLineEdit->setMaxLength(2);

        arvoreBLayout->addWidget(arvoreBLineEdit);

        ConfigDialogPageEstruturas->addTab(arvoreBTab, QString());
        arvoreBPlusTab = new QWidget();
        arvoreBPlusTab->setObjectName(QString::fromUtf8("arvoreBPlusTab"));
        horizontalLayoutWidget_3 = new QWidget(arvoreBPlusTab);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(10, 10, 321, 41));
        arvoreBPlusLayout = new QHBoxLayout(horizontalLayoutWidget_3);
        arvoreBPlusLayout->setObjectName(QString::fromUtf8("arvoreBPlusLayout"));
        arvoreBPlusLayout->setContentsMargins(0, 0, 0, 0);
        arvoreBPlusLabel = new QLabel(horizontalLayoutWidget_3);
        arvoreBPlusLabel->setObjectName(QString::fromUtf8("arvoreBPlusLabel"));

        arvoreBPlusLayout->addWidget(arvoreBPlusLabel);

        arvoreBPlusLineEdit = new QLineEdit(horizontalLayoutWidget_3);
        arvoreBPlusLineEdit->setObjectName(QString::fromUtf8("arvoreBPlusLineEdit"));
        arvoreBPlusLineEdit->setMaxLength(2);

        arvoreBPlusLayout->addWidget(arvoreBPlusLineEdit);

        ConfigDialogPageEstruturas->addTab(arvoreBPlusTab, QString());
        hashTab = new QWidget();
        hashTab->setObjectName(QString::fromUtf8("hashTab"));
        horizontalLayoutWidget_4 = new QWidget(hashTab);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(10, 10, 321, 41));
        hashTamanhoTabelaLayout = new QHBoxLayout(horizontalLayoutWidget_4);
        hashTamanhoTabelaLayout->setObjectName(QString::fromUtf8("hashTamanhoTabelaLayout"));
        hashTamanhoTabelaLayout->setContentsMargins(0, 0, 0, 0);
        hashTamanhoTabelaLabel = new QLabel(horizontalLayoutWidget_4);
        hashTamanhoTabelaLabel->setObjectName(QString::fromUtf8("hashTamanhoTabelaLabel"));

        hashTamanhoTabelaLayout->addWidget(hashTamanhoTabelaLabel);

        arvoreBPlusLineEdit_3 = new QLineEdit(horizontalLayoutWidget_4);
        arvoreBPlusLineEdit_3->setObjectName(QString::fromUtf8("arvoreBPlusLineEdit_3"));
        arvoreBPlusLineEdit_3->setMaxLength(2);

        hashTamanhoTabelaLayout->addWidget(arvoreBPlusLineEdit_3);

        hashGroupBox = new QGroupBox(hashTab);
        hashGroupBox->setObjectName(QString::fromUtf8("hashGroupBox"));
        hashGroupBox->setGeometry(QRect(10, 60, 321, 151));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(hashGroupBox->sizePolicy().hasHeightForWidth());
        hashGroupBox->setSizePolicy(sizePolicy);
        ativarFatorDeCargaCheckBox = new QCheckBox(hashGroupBox);
        ativarFatorDeCargaCheckBox->setObjectName(QString::fromUtf8("ativarFatorDeCargaCheckBox"));
        ativarFatorDeCargaCheckBox->setGeometry(QRect(10, 30, 78, 15));
        horizontalLayoutWidget_5 = new QWidget(hashGroupBox);
        horizontalLayoutWidget_5->setObjectName(QString::fromUtf8("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(10, 50, 160, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget_5);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(false);

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(horizontalLayoutWidget_5);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEdit->setMaxLength(10);
        lineEdit->setDragEnabled(false);

        horizontalLayout->addWidget(lineEdit);

        ConfigDialogPageEstruturas->addTab(hashTab, QString());
#ifndef QT_NO_SHORTCUT
        trieLabel->setBuddy(trieLineEdit);
        label->setBuddy(lineEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(ConfigDialogPageEstruturas);

        ConfigDialogPageEstruturas->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ConfigDialogPageEstruturas);
    } // setupUi

    void retranslateUi(QTabWidget *ConfigDialogPageEstruturas)
    {
        ConfigDialogPageEstruturas->setWindowTitle(QApplication::translate("ConfigDialogPageEstruturas", "TabWidget", 0));
#ifndef QT_NO_WHATSTHIS
        trieLabel->setWhatsThis(QApplication::translate("ConfigDialogPageEstruturas", "Define o tamanho m\303\241ximo em BITS do n\303\272mero que ser\303\241 inserido. Quanto maior o n\303\272mero de Bits, maior o n\303\272mero de valores que podem ser inseridos", 0));
#endif // QT_NO_WHATSTHIS
        trieLabel->setText(QApplication::translate("ConfigDialogPageEstruturas", "N\303\272mero de Bits:", 0));
        ConfigDialogPageEstruturas->setTabText(ConfigDialogPageEstruturas->indexOf(trieTab), QApplication::translate("ConfigDialogPageEstruturas", "TRIE", 0));
        arvoreBLabel->setText(QApplication::translate("ConfigDialogPageEstruturas", "Ordem:", 0));
        ConfigDialogPageEstruturas->setTabText(ConfigDialogPageEstruturas->indexOf(arvoreBTab), QApplication::translate("ConfigDialogPageEstruturas", "Arvore B", 0));
        arvoreBPlusLabel->setText(QApplication::translate("ConfigDialogPageEstruturas", "Ordem:", 0));
        ConfigDialogPageEstruturas->setTabText(ConfigDialogPageEstruturas->indexOf(arvoreBPlusTab), QApplication::translate("ConfigDialogPageEstruturas", "Arvore B+", 0));
#ifndef QT_NO_WHATSTHIS
        hashTamanhoTabelaLabel->setWhatsThis(QApplication::translate("ConfigDialogPageEstruturas", "Define o tamanho da tabela hash. Os n\303\272meros inseridos devem ser n\303\272meros primos entre 2 e 100.", 0));
#endif // QT_NO_WHATSTHIS
        hashTamanhoTabelaLabel->setText(QApplication::translate("ConfigDialogPageEstruturas", "Tamanho da Tabela:", 0));
        hashGroupBox->setTitle(QApplication::translate("ConfigDialogPageEstruturas", "Fator de Carga", 0));
        ativarFatorDeCargaCheckBox->setText(QApplication::translate("ConfigDialogPageEstruturas", "Ativar", 0));
        label->setText(QApplication::translate("ConfigDialogPageEstruturas", "THo:", 0));
        ConfigDialogPageEstruturas->setTabText(ConfigDialogPageEstruturas->indexOf(hashTab), QApplication::translate("ConfigDialogPageEstruturas", "Hash", 0));
    } // retranslateUi

};

namespace Ui {
    class ConfigDialogPageEstruturas: public Ui_ConfigDialogPageEstruturas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGDIALOGPAGEESTRUTURAS_H
