#ifndef QOPENHASHNODO_H
#define QOPENHASHNODO_H

#include <QGraphicsItem>


class QOpenHashNodo: public QGraphicsItem
{
public:
    QOpenHashNodo(int x,QGraphicsItem* pai);
    int valor;
    QOpenHashNodo* prox;    
    void setBusca(void);
    bool cabeca;
    bool achado;
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // QOPENHASHNODO_H
