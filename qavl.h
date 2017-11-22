#ifndef QAVL_H
#define QAVL_H

#include "qbst.h"

class QBSTNodo;

class QAVL: public QBST
{
public:
    QAVL(int alinhamento);
    ~QAVL();

    void inserirValor(int x);    
    void removerValor(int x);
private:  
    void inserir(int x, QBSTNodo** p, QBSTNodo** pai,QBSTNodo** avo);

    void remover(QBSTNodo** p, int x,QBSTNodo** pai);

    void calcularBalanceamento(QBSTNodo* p);

    void rotacaoSimplesDireita(QBSTNodo** p);
    void rotacaoSimplesEsquerda(QBSTNodo** p);

    void rotacaoDuplaDireita(QBSTNodo** p);
    void rotacaoDuplaEsquerda(QBSTNodo** p);

    void balancear(QBSTNodo** p);

    bool exibirBal;       
};

//class QAVLNodo;
//
//class QAVL: public QBase
//{
//public:
//    QAVL();
//    QAVL(int alinhamento);
//    ~QAVL();
//    bool vazia(void);
//    void inserirValor(int x);
//    bool buscarValor(int x);
//    void removerValor(int x);
//    void limparTudo(void);
//    bool salvar(QString fileName);
//    void balanceamentoAutomatico(bool opcao);
//    void setAlinhamento(int tipo);
//private:
//    QList<int> imprimirEmLargura(QAVLNodo* p);
//
//    void inserir(int x, QAVLNodo** p, QAVLNodo** pai,QAVLNodo** avo);
//    QAVLNodo* buscar(QAVLNodo* p,int x);
//
//    int quantidadeDeNos(QAVLNodo* p);
//
//    void alinhamentoCompleto(QAVLNodo* p,int dir);
//    void alinhamentoPadrao(QAVLNodo* p,int dir);
//
//    int alturaArvore(QAVLNodo* p);
//
//    void remover(QAVLNodo** p, int x,QAVLNodo** pai);
//
//    void calcularBalanceamento(QAVLNodo* p);
//
//    void rotacaoSimplesDireita(QAVLNodo** p);
//    void rotacaoSimplesEsquerda(QAVLNodo** p);
//
//    void rotacaoDuplaDireita(QAVLNodo** p);
//    void rotacaoDuplaEsquerda(QAVLNodo** p);
//
//    void balancear(QAVLNodo** p);
//
//    bool exibirBal;
//    bool autoBalanceamento;
//    QAVLNodo* ptraiz;
//    int tipoAlinhamento;
//};

#endif // QAVL_H
