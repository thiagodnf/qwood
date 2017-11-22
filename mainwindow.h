#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QToolBox>
#include <QMainWindow>
#include <QtGui>
#include <QStack>
#include <QPushButton>
#include <QLineEdit>
#include <QMdiArea>
#include <QActionGroup>

class QBase;

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QSignalMapper *windowMapper;

    QToolBox *toolBox;

    QToolBar *editToolBar;       

    QStatusBar* statusBar;

    QPushButton* btnInserir;
    QPushButton* btnBuscar;
    QPushButton* btnRemover;
    QPushButton* btnLimparTudo;
    QLineEdit* lneInserir;

    QMdiArea* mdiArea;    

    QMenu* arquivoMenu;
    QMenu* editarMenu;
    QMenu* alinharMenu;
    QMenu* novoMenu;
    QMenu* windowsMenu; 
    QMenu* configuracoesMenu;    
    QMenu* ajudaMenu;
    QMenu* alinhamentoMenu;

    QAction* conf_arvoreBMenu;
    QAction* conf_arvoreBPlusMenu;
    QAction* conf_hashMenu;

    QAction* sair;
    QAction* abrirAction;
    QAction* aboutAction;
    QAction* sobreQtAction;
    QAction* zoomInAction;
    QAction* zoomOutAction;
    QAction* salvarTXTAction;
    QAction* closeAction;
    QAction* fecharTudoAction; 
    QAction* exportToPNGAction;
    QAction* limparTudoAction;
    QAction* configuracoesAction;

    QActionGroup* alinhamentoGroupAction;
    QAction* alinhamentoPadraoAction;
    QAction* alinhamentoCompletoAction;

    QAction* newBSTAction;
    QAction* newTRIEAction;
    QAction* newAVLAction;
    QAction* newSPLAYAction;
    QAction* newBAction;
    QAction* newBPlusAction;
    QAction* newOpenHashAction;

    QAction *ladoALadoAction;
    QAction *cascataAction;

    int countBST;
    int countTRIE;
    int countAVL;
    int countSPLAY;
    int countB;
    int countBPlus;
    int countOpenHash;

    int tipoAlinhamento;
    int ordemArvoreB;
    int ordemArvoreBPlus;
    int tamanhoHash;
    int ultimoValorInserido;

    int config_TRIE_QuantBITS;
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void createToolBox();
    void createToolBar();
    void createMenus();
    void createActions();
    void createStatusBar();

    QBase* activeMdiChild(void);


private:
    int geraValorAleatorio(void);    
private slots:    
    void inserirValor(int x=0);
    void buscarValor();
    void removerValor(void);       

    void alinhamentoPadrao(void);
    void alinhamentoCompleto(void);

    void updateMenus(void);

    QBase* createBST(void);
    QBase* createTRIE(void);
    QBase* createAVL(void);
    QBase* createSPLAY(void);
    QBase* createB(void);
    QBase* createBPlus(void);
    QBase* createOpenHash(void);

    void zoomIn(void);
    void zoomOut(void);

    void exportToPNG(void);

    void save(void);
    void abrirArquivo(void);
    void configurarOrdemArvoreB(void);
    void configurarOrdemArvoreBPlus(void);
    void configurarTamanhoHash(void);
    void configuracoes(void);

    void exibirAbout(void);
    void limparArvores(void);

    void setActiveSubWindow(QWidget *window);


};

#endif // MAINWINDOW_H
