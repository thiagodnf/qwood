#include <QtGui>
#include <ctime>
#include <iostream>
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>
#include <QMdiSubWindow>

#include "mainwindow.h"
#include "qbst.h"
#include "qavl.h"
#include "qtrie.h"
#include "qsplay.h"
#include "qb.h"
#include "qbplus.h"
#include "qopenhash.h"
#include "qdialogabrir.h"
#include "qdialogarvoreb.h"
#include "qdialogarvorebplus.h"
#include "qdialoghash.h"
#include "configdialog.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent):
        QMainWindow(parent),
        ultimoValorInserido(-1),
        countBST(1),
        countTRIE(1),
        countAVL(1),
        countSPLAY(1),
        countB(1),
        countBPlus(1),
        countOpenHash(1),
        tipoAlinhamento(0),
        ordemArvoreB(2),
        ordemArvoreBPlus(2),
        tamanhoHash(7)
{
    /*Inicializa as configurações padrões do programa*/
    config_TRIE_QuantBITS = 4;



    /*Área onde irá guardar todas as estruturas*/
    mdiArea = new QMdiArea;
    mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    /*Coloca o MdiArea como sendo principal na janela*/
    setCentralWidget(mdiArea);

    connect(mdiArea, SIGNAL(subWindowActivated(QMdiSubWindow*)),this, SLOT(updateMenus()));

    windowMapper = new QSignalMapper(this);
    connect(windowMapper, SIGNAL(mapped(QWidget*)),this, SLOT(setActiveSubWindow(QWidget*)));

    createActions();
    createMenus();
    createToolBox();
    createToolBar();
    createStatusBar();

    updateMenus();

    setWindowIcon(QIcon(tr(":/images/logotipo_base2.png")));
    setWindowTitle(tr("QWood"));
    setUnifiedTitleAndToolBarOnMac(true);

    QTime midnight(0, 0, 0);
    qsrand(midnight.secsTo(QTime::currentTime()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::createMenus()
{
    /*Formatar Menu Principal*/
    arquivoMenu = menuBar()->addMenu(tr("&Arquivo"));
    novoMenu = arquivoMenu->addMenu(tr("&Novo"));
    arquivoMenu->addSeparator();
    arquivoMenu->addAction(abrirAction);
    arquivoMenu->addSeparator();
    arquivoMenu->addAction(salvarTXTAction);
    arquivoMenu->addSeparator();    
    arquivoMenu->addAction(exportToPNGAction);
    arquivoMenu->addSeparator();
    arquivoMenu->addAction(sair);

    editarMenu = menuBar()->addMenu(tr("&Editar"));    

    novoMenu->addAction(newBSTAction);
    novoMenu->addAction(newTRIEAction);
    novoMenu->addAction(newAVLAction);
    novoMenu->addAction(newSPLAYAction);
    novoMenu->addAction(newBAction);
    novoMenu->addAction(newBPlusAction);
    novoMenu->addAction(newOpenHashAction);

    alinhamentoMenu = editarMenu->addMenu("&Alinhamento");
    editarMenu->addSeparator();
    editarMenu->addAction(zoomInAction);
    editarMenu->addAction(zoomOutAction);   
    editarMenu->addSeparator();
    editarMenu->addAction(limparTudoAction);
    editarMenu->addSeparator();
    editarMenu->addAction(configuracoesAction);

    alinhamentoMenu->addAction(alinhamentoPadraoAction);
    alinhamentoMenu->addAction(alinhamentoCompletoAction);

    configuracoesMenu = menuBar()->addMenu(QString::fromUtf8("&Configurações"));
    configuracoesMenu->addAction(conf_arvoreBMenu);
    configuracoesMenu->addAction(conf_arvoreBPlusMenu);
    configuracoesMenu->addAction(conf_hashMenu);

    windowsMenu = menuBar()->addMenu(tr("&Janelas"));

    windowsMenu->addAction(ladoALadoAction);
    windowsMenu->addAction(cascataAction);
    windowsMenu->addSeparator();
    windowsMenu->addAction(fecharTudoAction);

    ajudaMenu = menuBar()->addMenu(tr("A&juda"));
    ajudaMenu->addAction(sobreQtAction);
    ajudaMenu->addAction(aboutAction);
}

void MainWindow::createActions()
{
    sair = new QAction(QIcon(":/images/sair.png"),tr("&Sair"), this);
    sair->setShortcuts(QKeySequence::Quit);
    sair->setStatusTip(tr("Fecha completamente o programa"));
    connect(sair, SIGNAL(triggered()), this, SLOT(close()));

    abrirAction = new QAction(tr("&Abrir"), this);
    abrirAction->setShortcuts(QKeySequence::Open);
    abrirAction->setStatusTip(tr("Abre um arquivo com valores a serem inseridos"));
    connect(abrirAction, SIGNAL(triggered()), this, SLOT(abrirArquivo()));

    aboutAction = new QAction(tr("&Sobre"), this);
    aboutAction->setShortcut(tr("CTRl+B"));
    aboutAction->setStatusTip(QString::fromUtf8("Exibe informações sobre o programa"));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(exibirAbout()));

    sobreQtAction = new QAction(QIcon(":/images/logo_qt.png"),tr("&Sobre Qt"), this);
    sobreQtAction->setStatusTip(tr("Exibe informacoes o framework de desenvolvimento"));
    connect(sobreQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    limparTudoAction = new QAction(QIcon(":/images/limpar.png"),tr("&Limpar Tudo"), this);
    limparTudoAction->setStatusTip("Esvazia todas as arvores ativas");
    connect(limparTudoAction, SIGNAL(triggered()), this, SLOT(limparArvores()));

    zoomInAction = new QAction(QIcon(":/images/zoomIn.png"),tr("Zoom &In"), this);
    zoomInAction->setShortcut(tr("CTRl+I"));
    zoomInAction->setStatusTip(tr("Zoom In"));
    connect(zoomInAction, SIGNAL(triggered()), this, SLOT(zoomIn()));

    zoomOutAction = new QAction(QIcon(":/images/zoomOut.png"),tr("Zoom &Out"), this);
    zoomOutAction->setShortcut(tr("CTRl+O"));
    zoomOutAction->setStatusTip(tr("Zoom Out"));
    connect(zoomOutAction, SIGNAL(triggered()), this, SLOT(zoomOut()));

    alinhamentoPadraoAction = new QAction(QString::fromUtf8("&Padrão"),this);
    alinhamentoPadraoAction->setStatusTip(QString::fromUtf8("Alinhamento padrão para todas as árvores"));
    alinhamentoPadraoAction->setCheckable(true);    
    alinhamentoCompletoAction = new QAction(tr("&Completo"),this);
    alinhamentoCompletoAction->setStatusTip(QString::fromUtf8("Alinha a arvore como se cada nível estivesse completo"));
    alinhamentoCompletoAction->setCheckable(true);
    alinhamentoGroupAction = new QActionGroup(this);
    alinhamentoGroupAction->addAction(alinhamentoPadraoAction);
    alinhamentoGroupAction->addAction(alinhamentoCompletoAction);
    alinhamentoPadraoAction->setChecked(true);
    connect(alinhamentoCompletoAction, SIGNAL(triggered()), this, SLOT(alinhamentoCompleto()));
    connect(alinhamentoPadraoAction, SIGNAL(triggered()), this, SLOT(alinhamentoPadrao()));

    salvarTXTAction = new QAction(tr("&Salvar"), this);
    salvarTXTAction->setShortcut(QKeySequence::Save);
    salvarTXTAction->setStatusTip(QString::fromUtf8("Salva o conteúdo dos nós percorrendo a arvore em largura"));
    connect(salvarTXTAction, SIGNAL(triggered()), this, SLOT(save()));

    ladoALadoAction = new QAction(QIcon(":/images/lado_a_lado.png"),tr("&Lado a Lado"), this);
    ladoALadoAction->setStatusTip(tr("Janelas lado a lado"));
    connect(ladoALadoAction, SIGNAL(triggered()), mdiArea, SLOT(tileSubWindows()));

    cascataAction = new QAction(QIcon(":/images/cascata.png"),tr("&Cascata"), this);
    cascataAction->setStatusTip(tr("Janelas em forma de cascatas"));
    connect(cascataAction, SIGNAL(triggered()), mdiArea, SLOT(cascadeSubWindows()));

    fecharTudoAction = new QAction(QIcon(":/images/fechar_tudo.png"),tr("&Fechar Tudo"), this);
    fecharTudoAction->setStatusTip(QString::fromUtf8("Fecha todas as árvores abertas"));
    connect(fecharTudoAction, SIGNAL(triggered()),mdiArea, SLOT(closeAllSubWindows()));

    newBSTAction = new QAction(tr("&Binary Search Tree (BST)"), this);
    newBSTAction->setStatusTip(tr("Cria uma arvore do tipo BST"));
    connect(newBSTAction, SIGNAL(triggered()), this, SLOT(createBST()));

    newTRIEAction = new QAction(tr("&TRIE"), this);
    newTRIEAction->setStatusTip(tr("Cria uma arvore do tipo TRIE"));
    connect(newTRIEAction, SIGNAL(triggered()), this, SLOT(createTRIE()));

    newAVLAction = new QAction(tr("&Adelson-Velskii and Landis (AVL)"), this);
    newAVLAction->setStatusTip(tr("Cria uma arvore do tipo AVL"));
    connect(newAVLAction, SIGNAL(triggered()), this, SLOT(createAVL()));

    newSPLAYAction = new QAction(tr("&SPLAY"), this);
    newSPLAYAction->setStatusTip(tr("Cria uma arvore do tipo SPLAY"));
    connect(newSPLAYAction, SIGNAL(triggered()), this, SLOT(createSPLAY()));

    newBAction = new QAction(QString::fromUtf8("&Árvore B"), this);
    newBAction->setStatusTip(tr("Cria uma arvore do tipo B"));
    connect(newBAction, SIGNAL(triggered()), this, SLOT(createB()));

    newBPlusAction = new QAction(QString::fromUtf8("&Árvore B+"), this);
    newBPlusAction->setStatusTip(tr("Cria uma arvore do tipo B+"));
    connect(newBPlusAction, SIGNAL(triggered()), this, SLOT(createBPlus()));

    newOpenHashAction = new QAction(tr("&Open Hash"), this);
    newOpenHashAction->setStatusTip(tr("Cria uma Open Hash"));
    connect(newOpenHashAction, SIGNAL(triggered()), this, SLOT(createOpenHash()));

    exportToPNGAction = new QAction(tr("&Exportar PNG"), this);
    exportToPNGAction->setStatusTip(tr("Exporta uma imagem da arvore selecionada em PNG"));
    connect(exportToPNGAction, SIGNAL(triggered()), this, SLOT(exportToPNG()));

    conf_arvoreBMenu = new QAction(tr("&Ordem da Arvore B"),this);
    connect(conf_arvoreBMenu, SIGNAL(triggered()), this, SLOT(configurarOrdemArvoreB()));

    conf_arvoreBPlusMenu = new QAction(tr("&Ordem da Arvore B+"),this);
    connect(conf_arvoreBPlusMenu, SIGNAL(triggered()), this, SLOT(configurarOrdemArvoreBPlus()));

    conf_hashMenu = new QAction(tr("&Tamanho da Tabela Hash"),this);
    connect(conf_hashMenu, SIGNAL(triggered()), this, SLOT(configurarTamanhoHash()));

    configuracoesAction = new QAction(QString::fromUtf8("&Configurações"),this);
    connect(configuracoesAction, SIGNAL(triggered()), this, SLOT(configuracoes()));

}

void MainWindow::createToolBox()
{
    toolBox = new QToolBox;
    toolBox->setSizePolicy(QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Ignored));
}

void MainWindow::createStatusBar()
{
    statusBar =  new QStatusBar;
    setStatusBar(statusBar);
}

void MainWindow::createToolBar()
{
    editToolBar = addToolBar(tr("Principal"));

    /*Botões da Janela*/
    btnInserir = new QPushButton;
    btnBuscar = new QPushButton;
    btnRemover = new QPushButton;
    btnLimparTudo = new QPushButton;    

    /*Adiciona texto ao botões criado*/
    btnInserir->setText("Inserir");
    btnBuscar->setText("Buscar");
    btnRemover->setText("Remover");
    btnLimparTudo->setText("Limpar Tudo");

    /*Adiciona os ícones nos botões*/   
    btnRemover->setIcon(QIcon(":/images/delete.png"));
    btnInserir->setIcon(QIcon(":/images/inserir.png"));
    btnBuscar->setIcon(QIcon(":/images/buscar.png"));
    btnLimparTudo->setIcon(QIcon(":/images/limpar.png"));

    /*Adiciona os eventos aos botões*/
    connect(btnInserir, SIGNAL(clicked()),this, SLOT(inserirValor()));
    connect(btnBuscar, SIGNAL(clicked()),this, SLOT(buscarValor()));
    connect(btnRemover, SIGNAL(clicked()),this, SLOT(removerValor()));
    connect(btnLimparTudo, SIGNAL(clicked()),this, SLOT(limparArvores()));

    /*Entrada de Dados*/
    lneInserir = new QLineEdit;
    lneInserir->setMinimumSize(100,0);    
    lneInserir->setMaximumWidth(200);
    lneInserir->setMaxLength(4);
    lneInserir->setStatusTip("Digite aqui o valor a ser inserido");


    /*Permitir apenas numero inteiros de 0 a 9999*/
    //lneInserir->setValidator(new QIntValidator(0,9999,this ));
    QRegExp rx("-?\\d{1,5}");
    lneInserir->setValidator(new QRegExpValidator(rx, this));
    connect(lneInserir,SIGNAL(returnPressed()),this,SLOT(inserirValor()));

    /*Adiciona os botões ao ToolBar "EDIT"*/
    editToolBar->addWidget(lneInserir);
    editToolBar->addWidget(btnInserir);
    editToolBar->addWidget(btnBuscar);
    editToolBar->addWidget(btnRemover);
    editToolBar->addWidget(btnLimparTudo);    

}

int MainWindow::geraValorAleatorio()
{    
    return qrand() % 500;
}

/*===================================*/
/* Eventos do Programa               */
/*===================================*/

void MainWindow::inserirValor(int x)
{

    try{
        int valor = 0;

        if(x != 0) valor = x;
        else valor = lneInserir->text().toInt();

        if(valor == 0) valor = geraValorAleatorio();

        /*Adquire todas as janelas criadas no MDI*/
        QList<QMdiSubWindow *> windows = mdiArea->subWindowList();

        /*Condição usada para verificar se existe alguma arvore criada*/
        if(windows.size()==0) QMessageBox::warning(this,"QWood","Nenhuma arvore criada");
        else{
            /*Laço irá percorrer todas as janelas abertas inserindo o valor nas devidas árvores*/
            for (int i = 0; i < windows.size(); i++) {
                try{
                    QBase *child = qobject_cast<QBase *>(windows[i]->widget());
                    child->inserirValor(valor);                    
                }catch(const char * myerro){
                    statusBar->showMessage(QString::fromUtf8(myerro));
                }
            }
            /*Depois de inserir todos os valores, atualizamos a visualização*/
            for (int i = 0; i < windows.size(); i++) {
                    QBase *child = qobject_cast<QBase *>(windows[i]->widget());
                    child->update();
            }
        }
        statusBar->showMessage("Valor inserido: "+QString::number(valor));
    }catch(const char * myerro){
        statusBar->showMessage(QString::fromUtf8(myerro));
    }
    lneInserir->clear();
    lneInserir->setFocus();
}

void MainWindow::buscarValor()
{
    try{
        int valor = lneInserir->text().toInt();

        if(valor == 0) valor = geraValorAleatorio();

        /*Adquire todas as janelas criadas no MDI*/
        QList<QMdiSubWindow *> windows = mdiArea->subWindowList();

        statusBar->showMessage("Buscar valor: "+QString::number(valor));

        /*Condição usada para verificar se existe alguma arvore criada*/
        if(windows.size()==0) QMessageBox::warning(this,"QWood","Nenhuma arvore criada");
        else{
            /*Laço irá percorrer todas as janelas abertas buscando o valor em cada uma*/
            for (int i = 0; i < windows.size(); i++) {
                    QBase *child = qobject_cast<QBase *>(windows[i]->widget());
                    bool achou = child->buscarValor(valor);
                    if(!achou) statusBar->showMessage(QString::fromUtf8("Valor não encontrado"));
            }
            /*Depois de inserir todos os valores, atualizamos a visualização*/
            for (int i = 0; i < windows.size(); i++) {
                    QBase *child = qobject_cast<QBase *>(windows[i]->widget());
                    child->update();
            }
        }        
    }catch(const char* myerro){        
        statusBar->showMessage(myerro);
    }
    lneInserir->clear();
    lneInserir->setFocus();    
}

void MainWindow::removerValor(void)
{
    try{
        int valor = lneInserir->text().toInt();

        /*Adquire todas as janelas criadas no MDI*/
        QList<QMdiSubWindow *> windows = mdiArea->subWindowList();

        /*Condição usada para verificar se existe alguma arvore criada*/
        if(windows.size()==0) QMessageBox::warning(this,"QWood","Nenhuma arvore criada");
        else{
            /*Laço irá percorrer todas as janelas abertas para remover os nós*/
            for (int i = 0; i < windows.size(); i++) {
                    QBase *child = qobject_cast<QBase *>(windows[i]->widget());
                    child->removerValor(valor);             
            }
            /*Depois de inserir todos os valores, atualizamos a visualização*/
            for (int i = 0; i < windows.size(); i++) {
                    QBase *child = qobject_cast<QBase *>(windows[i]->widget());
                    child->update();
            }
        }
        statusBar->showMessage("Valor removido: "+QString::number(valor));      
    }catch(const char* myerro){
        QMessageBox::warning(this,"QWood",QString::fromUtf8(myerro));
    }
    lneInserir->clear();
    lneInserir->setFocus();
}

void MainWindow::limparArvores()
{   
    /*Adquire todas as janelas criadas no MDI*/
    QList<QMdiSubWindow *> windows = mdiArea->subWindowList();

    /*Condição usada para verificar se existe alguma arvore criada*/
    if(windows.size()==0) QMessageBox::warning(this,"QWood","Nenhuma arvore criada");
    else{
        /*Laço irá percorrer todas as janelas abertas alinhando árvores*/
        for (int i = 0; i < windows.size(); i++) {
                QBase *child = qobject_cast<QBase *>(windows[i]->widget());
                child->limparTudo();
        }
    }

}

void MainWindow::exibirAbout()
{
    QMessageBox::about(this,"Sobre",
                       QString::fromUtf8("<html><head></head><body>QWood<br><br>"
                          "Universidade Estadual do Ceará - UECE <br><br>"
                          "Curso de Ciência da Computação<br>"
                          "Fluxo: 2010.2<br><br>"
                          "Autores: <br>"
                          "Thiago do Nascimento Ferreira<br>"
                          "Débora de Vasconcelos Martins<br><br>"
                          "Versão: 1.8<br><br>"
                          "Site: <a href='www.thiagonascimento.info'>www.thiagonascimento.info</a></body></html>"));
}

void MainWindow::zoomIn(void)
{
    QList<QMdiSubWindow *> windows = mdiArea->subWindowList();

    /*Condição usada para verificar se existe alguma arvore criada*/
    if(windows.size()==0) QMessageBox::warning(this,"QWood","Nenhuma arvore criada");
    else{
        /*Laço irá percorrer todas as janelas abertas aplicando o zoomIn*/
        for (int i = 0; i < windows.size(); i++) {
                QBase *child = qobject_cast<QBase *>(windows[i]->widget());
                child->zoomIn();
        }
    }
}

void MainWindow::zoomOut(void)
{
    QList<QMdiSubWindow *> windows = mdiArea->subWindowList();

    /*Condição usada para verificar se existe alguma arvore criada*/
    if(windows.size()==0) QMessageBox::warning(this,"QWood","Nenhuma arvore criada");
    else{
        /*Laço irá percorrer todas as janelas abertas aplicando o zoomOut*/
        for (int i = 0; i < windows.size(); i++) {
                QBase *child = qobject_cast<QBase *>(windows[i]->widget());
                child->zoomOut();
        }
    }
}

void MainWindow::exportToPNG(void)
{
    QBase* janela = 0;
    if (activeMdiChild()) janela = activeMdiChild();
    if(janela == 0){
        statusBar->showMessage(tr("Erro ao exportar!"), 2000);
        return;
    }

    QFileDialog dialog;
    QString fileName = dialog.getSaveFileName(this,tr("Exportar como PNG"), QDir::currentPath(),"Images (*.png)",0,QFileDialog::DontUseNativeDialog);

    if (fileName.isEmpty()){
        statusBar->showMessage(tr("Nome do arquivo vazio!"), 2000);
        return;
    }

    fileName = fileName + ".png";

    janela->exportToPNG(fileName);

    statusBar->showMessage(tr("Arquivo exportado com sucesso"), 2000);
}

QBase* MainWindow::createBST()
{
    QBST *mBST = new QBST(tipoAlinhamento);    
    mBST->setWindowTitle("BST"+QString::number(countBST));
    mBST->setMinimumSize(300,300);
    mdiArea->addSubWindow(mBST);
    mBST->show();
    countBST++;
    lneInserir->setFocus();
    return mBST;
}

QBase* MainWindow::createTRIE()
{
    QTrie *mTrie = new QTrie(tipoAlinhamento,config_TRIE_QuantBITS);
    mTrie->setWindowTitle("TRIE"+QString::number(countTRIE)+ " - BITS: "+QString::number(config_TRIE_QuantBITS));
    mTrie->setMinimumSize(300,300);
    mdiArea->addSubWindow(mTrie);
    mTrie->show();
    countTRIE++;
    lneInserir->setFocus();
    return mTrie;
}

QBase* MainWindow::createB()
{
    QB *mB = new QB(tipoAlinhamento,ordemArvoreB);
    mB->setWindowTitle("B"+QString::number(countB) + " - Ordem: "+QString::number(ordemArvoreB));
    mB->setMinimumSize(300,300);
    mdiArea->addSubWindow(mB);
    mB->show();
    countB++;
    lneInserir->setFocus();
    return mB;
}

QBase* MainWindow::createBPlus()
{
    QBPlus *mBPlus = new QBPlus(tipoAlinhamento,ordemArvoreBPlus);
    mBPlus->setWindowTitle("B+"+QString::number(countB) + " - Ordem: "+QString::number(ordemArvoreB));
    mBPlus->setMinimumSize(300,300);
    mdiArea->addSubWindow(mBPlus);
    mBPlus->show();
    countBPlus++;
    lneInserir->setFocus();
    return mBPlus;
}

QBase* MainWindow::createAVL()
{
    QAVL *myAVL = new QAVL(tipoAlinhamento);
    myAVL->setWindowTitle("AVL"+QString::number(countAVL));
    myAVL->setMinimumSize(300,300);
    mdiArea->addSubWindow(myAVL);
    myAVL->show();
    countAVL++;
    lneInserir->setFocus();
    return myAVL;
}

QBase* MainWindow::createSPLAY()
{
    QSplay *mySPLAY = new QSplay(tipoAlinhamento);
    mySPLAY->setWindowTitle("SPLAY"+QString::number(countSPLAY));
    mySPLAY->setMinimumSize(300,300);
    mdiArea->addSubWindow(mySPLAY);
    mySPLAY->show();
    countSPLAY++;
    lneInserir->setFocus();
    return mySPLAY;
}

QBase* MainWindow::createOpenHash()
{
    QOpenHash *myOpenHash = new QOpenHash(tamanhoHash);
    myOpenHash->setWindowTitle("Open Hash"+QString::number(countOpenHash)+ " - Tamanho: "+QString::number(tamanhoHash));
    myOpenHash->setMinimumSize(300,300);
    mdiArea->addSubWindow(myOpenHash);
    myOpenHash->show();
    countOpenHash++;
    lneInserir->setFocus();
    return myOpenHash;

}

void MainWindow::updateMenus(void)
{
    bool hasMdiChild = (activeMdiChild() != 0);

    fecharTudoAction->setEnabled(hasMdiChild);
    ladoALadoAction->setEnabled(hasMdiChild);
    cascataAction->setEnabled(hasMdiChild);
    exportToPNGAction->setEnabled(hasMdiChild);
    zoomInAction->setEnabled(hasMdiChild);
    zoomOutAction->setEnabled(hasMdiChild);   
    salvarTXTAction->setEnabled(hasMdiChild);
    lneInserir->setEnabled(hasMdiChild);
    lneInserir->clear();
    btnBuscar->setEnabled(hasMdiChild);
    btnInserir->setEnabled(hasMdiChild);
    btnRemover->setEnabled(hasMdiChild);
    btnLimparTudo->setEnabled(hasMdiChild);
    limparTudoAction->setEnabled(hasMdiChild);        
}

QBase* MainWindow::activeMdiChild(void)
{    
    if (QMdiSubWindow *activeSubWindow = mdiArea->activeSubWindow()){
        return qobject_cast<QBase *>(activeSubWindow->widget());
    }
    return 0;
}

void MainWindow::setActiveSubWindow(QWidget *window)
{
    if (!window) return;
    mdiArea->setActiveSubWindow(qobject_cast<QMdiSubWindow *>(window));
}

void MainWindow::save(void)
{
    QBase* janela = 0;
    if (activeMdiChild()) janela = activeMdiChild();
    if(janela == 0){
        statusBar->showMessage(tr("Erro ao exportar!"), 2000);
        return;
    }

    QFileDialog dialog;
    QString fileName = dialog.getSaveFileName(this,tr("Salvar"), QDir::currentPath(),"TXT (*.txt)",0,QFileDialog::DontUseNativeDialog);

    if (fileName.isEmpty()){
        statusBar->showMessage(tr("Nome do arquivo vazio!"), 2000);
        return;
    }

    fileName = fileName + ".txt";

    janela->salvar(fileName);

    statusBar->showMessage(tr("Arquivo salvado com sucesso"), 2000);
}

void MainWindow::abrirArquivo(void)
{
    QDialogAbrir abrir(this);
    int estado = abrir.exec();

    /*Condição usada para verificar se o usuário conseguiu entrar com os dados*/
    if(estado != 0){
        QString diretorio = abrir.getDiretorio();
        int* vet = abrir.getArvoresSelecionadas();
        QOpenHash *myHash = 0;
        QBST* myBST = 0;
        QTrie* myTrie = 0;
        QAVL* myAVL = 0;
        QSplay* mySPLAY = 0;
        QB* myB = 0;
        QBPlus* myBPlus = 0;

        if(vet[0]==1) myBST = (QBST*)createBST();
        if(vet[1]==1) myTrie = (QTrie*)createTRIE();
        if(vet[2]==1) myAVL = (QAVL*)createAVL();
        if(vet[3]==1) mySPLAY = (QSplay*)createSPLAY();
        if(vet[4]==1) myB = (QB*) createB();
        if(vet[5]==1) myHash = (QOpenHash*)createOpenHash();
        if(vet[6]==1) myBPlus = (QBPlus*)createBPlus();


        QFile file(diretorio);
        try{
            QString linha;
            if (file.open(QIODevice::ReadOnly|QIODevice::Text)){
                QTextStream stream( &file );

                while (!stream.atEnd() ){
                    linha = stream.readLine();
                    int valor = linha.toInt();
                    if(valor <=9999 && valor > 0){
                        if(myHash != 0) myHash->inserirValor(valor);
                        if(myAVL != 0) myAVL->inserirValor(valor);
                        if(myB != 0) myB->inserirValor(valor);
                        if(myBST != 0) myBST->inserirValor(valor);
                        if(mySPLAY != 0) mySPLAY->inserirValor(valor);
                        if(myTrie != 0) myTrie->inserirValor(valor);
                        if(myBPlus != 0) myBPlus->inserirValor(valor);
                    }
                }
            }
            file.close();
        }catch(const char * myerro){
            statusBar->showMessage(QString::fromUtf8(myerro));
        }
    }
}

void MainWindow::configurarOrdemArvoreB(void)
{
    QDialogArvoreB conf(ordemArvoreB,this);
    int estado = conf.exec();   
    if(estado != 0){
        ordemArvoreB = conf.getOrdem();
    }
}

void MainWindow::configurarOrdemArvoreBPlus(void)
{
    QDialogArvoreBPlus conf(ordemArvoreBPlus,this);
    int estado = conf.exec();
    if(estado != 0){
        ordemArvoreBPlus = conf.getOrdem();
    }
}

void MainWindow::configurarTamanhoHash(void)
{
    QDialogHash conf(tamanhoHash,this);
    int estado = conf.exec();
    if(estado != 0){
        tamanhoHash = conf.getTamanho();
    }
}

void MainWindow::alinhamentoPadrao(void)
{
    tipoAlinhamento = 0;

    QList<QMdiSubWindow *> windows = mdiArea->subWindowList();

    /*Condição usada para verificar se existe alguma arvore criada*/
    if(windows.size() !=0){
        /*Laço irá percorrer todas as janelas abertas aplicando o zoomOut*/
        for (int i = 0; i < windows.size(); i++) {
                QBase *child = qobject_cast<QBase *>(windows[i]->widget());
                child->setAlinhamento(tipoAlinhamento);
        }
    }
}

void MainWindow::alinhamentoCompleto(void)
{
    tipoAlinhamento = 1;
    QList<QMdiSubWindow *> windows = mdiArea->subWindowList();

    /*Condição usada para verificar se existe alguma arvore criada*/
    if(windows.size() != 0){
        /*Laço irá percorrer todas as janelas abertas aplicando o zoomOut*/
        for (int i = 0; i < windows.size(); i++) {
                QBase *child = qobject_cast<QBase *>(windows[i]->widget());
                child->setAlinhamento(tipoAlinhamento);
        }
    }
}

void MainWindow::configuracoes(void)
{
    ConfigDialog dialog;
    /*Inicializa com os valores*/
    dialog.setTRIEQuantidadeDeBits(config_TRIE_QuantBITS);

    int estado = dialog.exec();

    /*Se for diferente de 0, o usuário apertou "OK"*/
    if(estado != 0){
        config_TRIE_QuantBITS = dialog.TRIEQuantidadeDeBits();
    }
}


