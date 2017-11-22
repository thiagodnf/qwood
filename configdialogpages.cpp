#include <QtGui>
#include <QGroupBox>
#include <QLabel>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "configdialogpages.h"

ConfigDialogGeral::ConfigDialogGeral(QWidget *parent)
    : QWidget(parent)
{
    QGroupBox *configGroup = new QGroupBox(tr("Server configuration"));

    QLabel *serverLabel = new QLabel(tr("Server:"));
    QComboBox *serverCombo = new QComboBox;
    serverCombo->addItem(tr("Qt (Australia)"));
    serverCombo->addItem(tr("Qt (Germany)"));
    serverCombo->addItem(tr("Qt (Norway)"));
    serverCombo->addItem(tr("Qt (People's Republic of China)"));
    serverCombo->addItem(tr("Qt (USA)"));

    QHBoxLayout *serverLayout = new QHBoxLayout;
    serverLayout->addWidget(serverLabel);
    serverLayout->addWidget(serverCombo);

    QVBoxLayout *configLayout = new QVBoxLayout;
    configLayout->addLayout(serverLayout);
    configGroup->setLayout(configLayout);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(configGroup);
    mainLayout->addStretch(1);
    setLayout(mainLayout);
}

ConfigDialogEstruturas::ConfigDialogEstruturas(QWidget *parent)
    : QTabWidget(parent)
{ 
    QComboBox *ordemBCombo1 = new QComboBox;
    QComboBox *ordemBCombo2 = new QComboBox;
    QComboBox *ordemBCombo3 = new QComboBox;
    QComboBox *ordemBCombo4 = new QComboBox;

    QHBoxLayout *ordemBLayout = new QHBoxLayout;

    addTab(ordemBCombo1,"Trie");
    addTab(ordemBCombo2,"B");
    addTab(ordemBCombo3,"B+");
    addTab(ordemBCombo4,"Hash");
    setLayout(ordemBLayout);


    //addTab(ordemBLayout,"dff");
//    configurarArvoreB();
//    configurarArvoreBPlus();
//
//    setLayout(mainLayout);
//    mainLayout->addStretch(1);

}

void ConfigDialogEstruturas::configurarArvoreB(void)
{
    QGroupBox *configBGroup = new QGroupBox(QString::fromUtf8("Árvore B"));

    QLabel *ordemBLabel = new QLabel(tr("Ordem:"));

    QComboBox *ordemBCombo = new QComboBox;

    ordemBCombo->addItem(tr("2"));
    ordemBCombo->addItem(tr("3"));
    ordemBCombo->addItem(tr("4"));
    ordemBCombo->addItem(tr("5"));
    ordemBCombo->addItem(tr("6"));
    ordemBCombo->addItem(tr("7"));
    ordemBCombo->addItem(tr("8"));
    ordemBCombo->addItem(tr("9"));
    ordemBCombo->addItem(tr("10"));



    QHBoxLayout *ordemBLayout = new QHBoxLayout;
    ordemBLayout->addWidget(ordemBLabel);
    ordemBLayout->addWidget(ordemBCombo);



    QVBoxLayout *configLayout = new QVBoxLayout;
    configLayout->addLayout(ordemBLayout);

    configBGroup->setLayout(configLayout);

//    mainLayout = new QVBoxLayout;
//    mainLayout->addWidget(configBGroup);

}

void ConfigDialogEstruturas::configurarArvoreBPlus()
{
    QGroupBox *configBPlusGroup = new QGroupBox(QString::fromUtf8("Árvore B+"));
    QLabel *ordemBPlusLabel = new QLabel(tr("Ordem:"));
    QComboBox *ordemBPlusCombo = new QComboBox;


    ordemBPlusCombo->addItem(tr("2"));
    ordemBPlusCombo->addItem(tr("3"));
    ordemBPlusCombo->addItem(tr("4"));
    ordemBPlusCombo->addItem(tr("5"));
    ordemBPlusCombo->addItem(tr("6"));
    ordemBPlusCombo->addItem(tr("7"));
    ordemBPlusCombo->addItem(tr("8"));
    ordemBPlusCombo->addItem(tr("9"));
    ordemBPlusCombo->addItem(tr("10"));

    QHBoxLayout *ordemBPlusLayout = new QHBoxLayout;
    ordemBPlusLayout->addWidget(ordemBPlusLabel);
    ordemBPlusLayout->addWidget(ordemBPlusCombo);

    QVBoxLayout *configBPlusLayout = new QVBoxLayout;
    configBPlusLayout->addLayout(ordemBPlusLayout);
    configBPlusGroup->setLayout(configBPlusLayout);

    //mainLayout->addWidget(configBPlusGroup);

}
