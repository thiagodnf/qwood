#ifndef TrieNodoTRIE_H
#define TrieNodoTRIE_H

#include <QGraphicsItem>
#include <QList>

class QTrieNodo : public QGraphicsItem
{    
public:
    QTrieNodo(int x,QGraphicsItem* pai,bool folha = false);

    bool pintarNodo;
    int cor;

    int raio;
    int alturaRaiz;

    int valor;
    QTrieNodo* dir;
    QTrieNodo* esq;
    bool folha;

    void pintar(bool pintar, int cor);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // TrieNodoTRIE_H
