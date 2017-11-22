#ifndef BST_H
#define BST_H

#include "qbase.h"

class QBSTNodo;

class QBST: public QBase
{    
public:    
    QBST(int alinhamento);
    ~QBST(void);
    void inserirValor(int x);
    bool buscarValor(int x);
    bool vazia(void);
    void removerValor(int x);

    void limparTudo(void);

    bool salvar(QString fileName);
    QList<int> imprimirEmLargura(QBSTNodo* p);
    void setAlinhamento(int tipo);
protected:
    void alinhamentoCompleto(QBSTNodo* p,int dir);
    void alinhamentoPadrao(QBSTNodo* p,int dir);

    void inserir(QBSTNodo* p,int x);
    QBSTNodo* buscar(QBSTNodo* p,int x);    
    void remover(QBSTNodo** p,int x,QBSTNodo** pai);
    int quantidadeDeNos(QBSTNodo* p);
    int alturaArvore(QBSTNodo* p);

    QBSTNodo* ptraiz;
    QBSTNodo* ultimoNo;
    int tipoAlinhamento;
};

#endif // BST_H
