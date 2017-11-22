#ifndef QOPENHASHTABLE_H
#define QOPENHASHTABLE_H

#include <QGraphicsItem>

class QOpenHashNodo;

class QOpenHashTable: public QGraphicsItem
{
public:
    QOpenHashTable(int tamanho);
    ~QOpenHashTable();

    QOpenHashNodo** filhos;

    bool achado;
    void setBusca(void);
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    int tamanho;

};

#endif // QOPENHASHTABLE_H
