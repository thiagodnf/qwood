#include "qdialogabrir.h"
#include "ui_qdialogabrir.h"

QDialogAbrir::QDialogAbrir(QWidget *parent) :
        QDialog(parent),
    ui(new Ui::QDialogAbrir)
{
    ui->setupUi(this);

    connect(ui->abrirPushButton,SIGNAL(clicked()),this,SLOT(procurarArquivo()));   
}

QDialogAbrir::~QDialogAbrir()
{
    delete ui;
}

void QDialogAbrir::changeEvent(QEvent *e)
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

void QDialogAbrir::accept()
{
    QString diretorio = ui->diretorioLineEdit->text();
    if(diretorio.isEmpty() ||diretorio.isNull()){
        QMessageBox::information(this,QString::fromUtf8("Diretório Vazio"),QString::fromUtf8("Por favor, verifique o diretório do arquivo"));
    }else{
        /*Garante que exista no minimo uma arvore selecionada*/
        if(ui->BSTCheckBox->isChecked() ||
           ui->TRIECheckBox->isChecked() ||
           ui->AVLCheckBox->isChecked() ||
           ui->BCheckBox->isChecked() ||
           ui->BPlusCheckBox->isChecked() ||
           ui->SPLAYCheckBox->isChecked() ||
           ui->OpenHashCheckBox->isChecked())
        QDialog::accept();
        else{
            QMessageBox::information(this,QString::fromUtf8("Diretório Vazio"),QString::fromUtf8("Selecione no mínimo uma estrutura para exibir"));
        }
    }

}

void QDialogAbrir::procurarArquivo(void)
{
    QFileDialog dialog;
    QString arquivo = dialog.getOpenFileName(this,tr("Salvar"), QDir::currentPath(),"TXT (*.txt)",0,QFileDialog::DontUseNativeDialog);

    if(!arquivo.isNull() || !arquivo.isEmpty() ){
        ui->diretorioLineEdit->setText(arquivo);
    }
}

QString QDialogAbrir::getDiretorio(void)
{
    return ui->diretorioLineEdit->text();
}

int* QDialogAbrir::getArvoresSelecionadas(void)
{
    int* arvores = new int[5];

    arvores[0] = (ui->BSTCheckBox->isChecked())?1:0;
    arvores[1] = (ui->TRIECheckBox->isChecked())?1:0;
    arvores[2] = (ui->AVLCheckBox->isChecked())?1:0;
    arvores[3] = (ui->SPLAYCheckBox->isChecked())?1:0;
    arvores[4] = (ui->BCheckBox->isChecked())?1:0;
    arvores[5] = (ui->OpenHashCheckBox->isChecked())?1:0;
    arvores[6] = (ui->BPlusCheckBox->isChecked())?1:0;

    return arvores;
}

