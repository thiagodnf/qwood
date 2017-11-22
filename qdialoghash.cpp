#include <QMessageBox>

#include "qdialoghash.h"
#include "ui_qdialoghash.h"

QDialogHash::QDialogHash(int tamanho,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QDialogHash)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QIntValidator(0,9999,this ));
    ui->lineEdit->installEventFilter(this);
    ui->lineEdit->setText(QString::number(tamanho) );
    ui->lineEdit->setSelection(0,2);
    ui->lineEdit->setFocus();
}

QDialogHash::~QDialogHash()
{
    delete ui;
}

void QDialogHash::changeEvent(QEvent *e)
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

bool QDialogHash::isPrimo(int valor)
{
    int primos[25] = {3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    int posicao = -1;
    /*Procura ver se o elemento digitado é primo*/
    for(int i=0;i<24;i++){
        if(valor == primos[i]) return true;
    }
    return false;
}

bool QDialogHash::eventFilter( QObject *dist, QEvent *event )
{
    if (dist == ui->lineEdit){
        int valorDigitado = ui->lineEdit->text().toInt();        
    }
    return false;
}

void QDialogHash::accept()
{
    if(ui->lineEdit->text() == ""){
        QMessageBox::information(this,QString::fromUtf8("Tabela Hash"),QString::fromUtf8("Digite um tamanho válida"));
        ui->lineEdit->setFocus();
    }else{
        if(ui->lineEdit->text().toInt() == 0){
            ui->lineEdit->setText("3");
            ui->lineEdit->setFocus();
        }else if(!isPrimo(ui->lineEdit->text().toInt())){
            QMessageBox::information(this,QString::fromUtf8("Tabela Hash"),QString::fromUtf8("Digite um número Primo maior que 2"));
            ui->lineEdit->setFocus();
        }else
            QDialog::accept();
    }
}

int QDialogHash::getTamanho(void)
{
    if(ui->lineEdit->text() == "") ui->lineEdit->setFocus();
    else if(ui->lineEdit->text().toInt() == 0) return 3;
    else if(isPrimo(ui->lineEdit->text().toInt()))
        return ui->lineEdit->text().toInt();
}
