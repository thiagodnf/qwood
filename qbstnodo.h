#ifndef NODO_H
#define NODO_H

#include <QGraphicsItem>

class QBSTNodo: public QGraphicsItem
{
public:    
    bool pintarNodo;
    int cor;

    int valor;
    int bal;
    QBSTNodo* dir;
    QBSTNodo* esq;    

    QBSTNodo(int x,QBSTNodo* pai);
    void pintar(bool valor,int cor);
protected:    
    QRectF boundingRect() const;   
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // NODO_H
