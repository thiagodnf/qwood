#include <QMessageBox>

#include "configdialogpageestruturas.h"
#include "ui_configdialogpageestruturas.h"

ConfigDialogPageEstruturas::ConfigDialogPageEstruturas(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::ConfigDialogPageEstruturas)
{
    ui->setupUi(this);
    ui->trieLineEdit->installEventFilter(this);
    ui->trieLineEdit->setFocus();
    ui->trieLineEdit->setSelection(0,2);

    /*Limita o números de BITS a no máximo 13 para não extrapolar a entrada
    máxima do programa*/    
    ui->trieLineEdit->setValidator(new QIntValidator(2,13, this));
    setCurrentIndex(0);

    //connect(ui->trieLineEdit,SIGNAL(),this,SLOT(validarTRIECampoBits()));
}

ConfigDialogPageEstruturas::~ConfigDialogPageEstruturas()
{
    delete ui;
}

void ConfigDialogPageEstruturas::validarTRIECampoBits(void)
{
    int a = 10;


}

bool ConfigDialogPageEstruturas::eventFilter( QObject *dist, QEvent *event )
{
    if (dist == ui->trieLineEdit){

        if(ui->trieLineEdit->text().toInt() > 13 && ui->trieLineEdit->text().toInt() < 2){
            ui->trieLineEdit->setText("13");
        }
    }
    return false;
}

void ConfigDialogPageEstruturas::changeEvent(QEvent *e)
{
    QTabWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

int ConfigDialogPageEstruturas::TRIEQuantidadeDeBits(void)
{
    return ui->trieLineEdit->text().toInt();
}

void ConfigDialogPageEstruturas::setTRIEQuantidadeDeBits(int valor)
{
    ui->trieLineEdit->setText(QString::number(valor));
}
