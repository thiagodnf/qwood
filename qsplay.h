#ifndef QSPLAY_H
#define QSPLAY_H

#include "qbst.h"

class QBSTNodo;

class QSplay: public QBST
{
public:
    QSplay(int alinhamento);
    ~QSplay(void);

    bool buscarValor(int x);   
private:
    QBSTNodo* buscaSimples(QBSTNodo* p,int x);
    QBSTNodo* buscar(QBSTNodo* p,int x);

    void rotacaoZag(QBSTNodo** pai);
    void rotacaoZig(QBSTNodo** pai);

    void rotacaoZagZag(QBSTNodo* avo);
    void rotacaoZigZig(QBSTNodo* avo);

    void rotacaoZigZag(QBSTNodo* avo);
    void rotacaoZagZig(QBSTNodo* avo);
};

//class QSplay: public QBase
//{
//public:
//    QSplay(int alinhamento);
//    ~QSplay(void);
//
//    void inserirValor(int x);
//    bool buscarValor(int x);
//    bool vazia(void);
//    void removerValor(int x);
//
//    void limparTudo(void);
//
//    bool salvar(QString fileName);
//
//    void setAlinhamento(int tipo);
//private:
//    void alinhamentoCompleto(QSplayNodo* p,int dir);
//    void alinhamentoPadrao(QSplayNodo* p,int dir);
//
//    QSplayNodo* buscaSimples(QSplayNodo* p,int x);
//
//    int quantidadeDeNos(QSplayNodo* p);
//
//    void rotacaoZag(QSplayNodo** pai);
//    void rotacaoZig(QSplayNodo** pai);
//
//    void rotacaoZagZag(QSplayNodo* avo);
//    void rotacaoZigZig(QSplayNodo* avo);
//
//    void rotacaoZigZag(QSplayNodo *avo);
//    void rotacaoZagZig(QSplayNodo *avo);
//
//    QList<int> imprimirEmLargura(QSplayNodo* p);
//
//    void inserir(QSplayNodo* p,int x);
//    void buscar(QSplayNodo *p,int x);
//    void remover(QSplayNodo** p,int x,QSplayNodo** pai);
//    int alturaArvore(QSplayNodo* p);
//
//    QSplayNodo *ptraiz;
//    int tipoAlinhamento;
//};

#endif // QSPLAY_H
