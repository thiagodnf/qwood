#include <QtGui>
#include <QStackedWidget>
#include <QListWidget>
#include <QPushButton>
#include <QHBoxLayout>


#include "configdialog.h"
#include "configdialogpages.h"
#include "configdialogpageestruturas.h"

ConfigDialog::ConfigDialog()
{
    setWindowTitle(QString::fromUtf8("Configurações"));
    setMinimumWidth(500);

    estruturas = new ConfigDialogPageEstruturas;

    contentsWidget = new QListWidget;
    pagesWidget = new QStackedWidget;

    contentsWidget->setViewMode(QListView::IconMode);
    contentsWidget->setIconSize(QSize(96, 84));
    contentsWidget->setMovement(QListView::Static);
    contentsWidget->setMaximumWidth(118);
    contentsWidget->setMinimumHeight(250);
    contentsWidget->setSpacing(12);

    pagesWidget->addWidget(new ConfigDialogGeral);
    pagesWidget->addWidget(estruturas);

    createIcons();
    contentsWidget->setCurrentRow(0);

    QPushButton *cancelarButton = new QPushButton(tr("Cancelar"));
    QPushButton *okButton = new QPushButton(tr("OK"));
    okButton->setMinimumWidth(70);
    cancelarButton->setMinimumWidth(70);
    connect(cancelarButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));

    QHBoxLayout *horizontalLayout = new QHBoxLayout;
    horizontalLayout->addWidget(contentsWidget);
    horizontalLayout->addWidget(pagesWidget, 1);

    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    buttonsLayout->addStretch(1);
    buttonsLayout->addWidget(okButton);
    buttonsLayout->addWidget(cancelarButton);


    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(horizontalLayout);
    mainLayout->addStretch(1);
    mainLayout->addSpacing(12);
    mainLayout->addLayout(buttonsLayout);
    setLayout(mainLayout);
}

void ConfigDialog::createIcons()
{
    QListWidgetItem *configButton = new QListWidgetItem(contentsWidget);    
    configButton->setIcon(QIcon(":/images/config_estruturas.png"));
    configButton->setText(tr("Geral"));
    configButton->setTextAlignment(Qt::AlignHCenter);
    configButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *estruturasButton1 = new QListWidgetItem(contentsWidget);
    estruturasButton1->setIcon(QIcon(":/images/logotipo_base.png"));
    estruturasButton1->setText(tr("Estruturas"));
    estruturasButton1->setTextAlignment(Qt::AlignHCenter);
    estruturasButton1->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    connect(contentsWidget,
            SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),
            this, SLOT(changePage(QListWidgetItem*,QListWidgetItem*)));
}

void ConfigDialog::changePage(QListWidgetItem *current, QListWidgetItem *previous)
{
    if (!current)
        current = previous;

    pagesWidget->setCurrentIndex(contentsWidget->row(current));
}

int ConfigDialog::TRIEQuantidadeDeBits(void)
{
    return estruturas->TRIEQuantidadeDeBits();
}

void ConfigDialog::setTRIEQuantidadeDeBits(int valor)
{
    estruturas->setTRIEQuantidadeDeBits(valor);
}
