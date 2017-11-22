#ifndef QOPENHASH_H
#define QOPENHASH_H

#include "qbase.h"

class QOpenHashTable;
class QOpenHashNodo;

class QOpenHash: public QBase
{
public:
    QOpenHash(int tamanho);
    ~QOpenHash();
    void inserirValor(int x);
    bool buscarValor(int x);
    bool vazia(void);
    void removerValor(int x);
    void limparTudo(void);
    bool salvar(QString fileName);
    void setAlinhamento(int tipo);
protected:
    int hash(int valor);
private:

    QOpenHashTable *ptraiz;
    QOpenHashNodo* ultimoValorProcurado;
    int tamanho;
};


#endif // QOPENHASH_H
