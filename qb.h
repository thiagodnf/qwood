#ifndef QB_H
#define QB_H

#include "qbase.h"

class QBNodo;

class QB: public QBase
{
public:
    QB(void);
    QB(int alinhamento,int ordem);
    ~QB(void);
    void inserirValor(int x);
    bool buscarValor(int x);
    bool vazia(void);
    void removerValor(int x);

    void limparTudo(void);

    bool salvar(QString fileName);
    QList<int> imprimirEmLargura(QBNodo* p,QList<int> &list);
    void setAlinhamento(int tipo);
protected:
    void alinhamentoCompleto(QBNodo* p,int dir);
    void alinhamentoPadrao(QBNodo* p,int dir);

    QBNodo* inserir(QBNodo* p,int x,QBNodo* pai);
    QBNodo* buscar(QBNodo* p,int x,bool pintar);
    void remover(QBNodo* p,int x);
    int quantidadeDeNos(QBNodo* p);
    int quantidadeDeFolhas(QBNodo* p);
    int quantidadeDeValoresFolhas(QBNodo* p);
    int quantidadeDeValoresTotal(QBNodo* p);
private:
    QBNodo* irmaoComNosSobrando(QBNodo* dir,QBNodo* esq);
    int split(QBNodo* fonte, QBNodo* destino);
    void splitReverso(QBNodo* p, QBNodo* irmao,QBNodo* pai,int posicao);
    int alturaArvore(QBNodo* p);
    void bubbleSort(QBNodo* p);

    QBNodo *ptraiz;
    int tipoAlinhamento;
    int ordem;   
};

#endif // QB_H
