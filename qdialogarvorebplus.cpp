#include "qdialogarvorebplus.h"
#include "ui_qdialogarvorebplus.h"

QDialogArvoreBPlus::QDialogArvoreBPlus(int ordem,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QDialogArvoreBPlus)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QIntValidator(0,9999,this ));
    ui->lineEdit->installEventFilter(this);
    ui->lineEdit->setText(QString::number(ordem) );
    ui->lineEdit->setSelection(0,2);
}

QDialogArvoreBPlus::~QDialogArvoreBPlus()
{
    delete ui;
}

void QDialogArvoreBPlus::accept()
{
    if(ui->lineEdit->text() == ""){
        QMessageBox::information(this,QString::fromUtf8("Ordem Árvore B+"),QString::fromUtf8("Digite uma ordem válida"));
        ui->lineEdit->setFocus();
    }else{
        if(ui->lineEdit->text().toInt() == 0){
            ui->lineEdit->setText("1");
            ui->lineEdit->setFocus();
        }else QDialog::accept();
    }
}

bool QDialogArvoreBPlus::eventFilter( QObject *dist, QEvent *event )
{
    if (dist == ui->lineEdit){

        if(ui->lineEdit->text().toInt() > 10){
            ui->lineEdit->setText("10");
        }
    }
    return false;

}

void QDialogArvoreBPlus::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

int QDialogArvoreBPlus::getOrdem(void)
{
    if(ui->lineEdit->text() == "") ui->lineEdit->setFocus();
    if(ui->lineEdit->text().toInt() == 0) return 1;
    else return ui->lineEdit->text().toInt();
}
