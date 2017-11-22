#ifndef QBPLUSNODO_H
#define QBPLUSNODO_H

#include <QGraphicsItem>

class QBPlusNodo: public QGraphicsItem
{
public:
    bool achado;
    int raio;
    int alturaRaiz;
    int indiceBuscado;

    int tipo;
    int ordem;
    int index;
    int* valores;
    QBPlusNodo **filhos;
    QBPlusNodo *prox;
    QBPlusNodo *primeiroArquivo;

    QBPlusNodo(int ordem,QBPlusNodo* primeiroArquivo,QBPlusNodo* pai=0,int ntipo=0);

    bool cheio(void);
    bool vazio(void);  

    int getPosicao(int valor);
    bool folha(void);
    QBPlusNodo* buscarPagina(int valor);   
    QBPlusNodo* irmaoDireita();
    QBPlusNodo* irmaoEsquerda();
    int posicaoEmRelacaoAoPai(void);
    void setBusca(void);
    int quantidadeDeFilhos(void);
protected:
    void bubbleSort(void);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // QBPLUSNODO_H
