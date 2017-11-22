#ifndef TRIE_H
#define TRIE_H


#include "qbase.h"

class QTrieNodo;

class QTrie : public QBase
{
public:    
    QTrie(int alinhamento,int quantidadeDeBits);
    ~QTrie(void);
    void inserirValor(int x);
    bool buscarValor(int x);
    bool vazia(void);
    void removerValor(int x);

    void expandirArvore(QTrieNodo* p,int x,int j);

    void limparTudo(void);
    bool salvar(QString fileName);

    int alturaArvore(QTrieNodo* p);

    void criarFolha(QTrieNodo** p,int x,QTrieNodo* pai,int dir);
    void criarNodo(QTrieNodo** p,QTrieNodo* pai,int dir);

    void setAlinhamento(int tipo);
protected:
    bool validarValor(int valor);
    QList<int> imprimirEmLargura(QTrieNodo* p);

    void alinhamentoCompleto(QTrieNodo* p,int dir);
    void alinhamentoPadrao(QTrieNodo* p,int dir);

    int quantidadeDeNos(QTrieNodo* p);
    int quantidadeDeNos(QTrieNodo* p,int dir);
    QTrieNodo* buscar(QTrieNodo* p,int x,int i);
    void remover(QTrieNodo* p,int x,int i);
private:
    int devolveBit(int x,int pos);

    QTrieNodo* ptraiz;
    QTrieNodo* ultimoNo;
    int tipoAlinhamento;
    int BITS;
    QList<int> numerosInseridos;
};

#endif // TRIE_H
