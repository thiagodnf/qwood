#ifndef QBNODO_H
#define QBNODO_H

#include <QGraphicsItem>

class QBNodo: public QGraphicsItem
{
public:
    bool achado;   
    int raio;
    int alturaRaiz;
    int indiceBuscado;

    static int id;

    int tipo;
    int ordem;
    int index;
    int* valores;
    QBNodo **filhos;

    QBNodo(int ordem,QBNodo* pai=0,int ntipo=0);

    bool cheio(void);
    bool vazio(void);
    bool extrapolou(void);

    int getPosicao(int valor);


    bool folha(void);

    void inserirValor(int valor);
    void inserirValor(int valor,QBNodo* irmao);


    QBNodo* buscarPagina(int valor);
    void inserirFilhos(QBNodo* p, int valor, QBNodo* irmao);
    void inserirFilho(QBNodo* p);
    void inserirFilhoAntes(QBNodo* p);
    QBNodo* irmaoDireita();
    QBNodo* irmaoEsquerda();
    int posicaoEmRelacaoAoPai(void);


    void setBusca(void);
    int quantidadeDeFilhos(void);
protected:    
    void bubbleSort(void);    

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // QBNODO_H
