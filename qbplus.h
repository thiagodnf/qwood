#ifndef QBPLUS_H
#define QBPLUS_H

#include "qbase.h"

class QBPlusNodo;

class QBPlus: public QBase
{
public:
    QBPlus(void);
    QBPlus(int alinhamento,int ordem);
    ~QBPlus(void);
    void inserirValor(int x);
    bool buscarValor(int x);
    bool vazia(void);
    void removerValor(int x);

    void limparTudo(void);

    bool salvar(QString fileName);
    QList<int> imprimirEmLargura(QBPlusNodo* p,QList<int> &list);
    void setAlinhamento(int tipo);
protected:
    void alinhamentoCompleto(QBPlusNodo* p,int dir);
    void alinhamentoPadrao(QBPlusNodo* p,int dir);

    QBPlusNodo* inserir(QBPlusNodo* p,int x,QBPlusNodo* pai);
    QBPlusNodo* buscar(QBPlusNodo* p,int x,bool pintar);
    void remover(QBPlusNodo* p,int x);
    int quantidadeDeNos(QBPlusNodo* p);
    int quantidadeDeFolhas(QBPlusNodo* p);
    int quantidadeDeValoresFolhas(QBPlusNodo* p);
    int quantidadeDeValoresTotal(QBPlusNodo* p);
private:
    QBPlusNodo* irmaoComNosSobrando(QBPlusNodo* dir,QBPlusNodo* esq);
    int split(QBPlusNodo* fonte, QBPlusNodo* destino);    
    int alturaArvore(QBPlusNodo* p);
    void bubbleSort(QBPlusNodo* p);

    void alinhamentoFile(void);

    QBPlusNodo *ptraiz;
    QBPlusNodo *fileRaiz;
    int tipoAlinhamento;
    int ordem;
};

#endif // QBPLUS_H
