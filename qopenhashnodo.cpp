#include <QPainter>

#include "qopenhashnodo.h"

#define CABECA 1

QOpenHashNodo::QOpenHashNodo(int x, QGraphicsItem *pai)
{
    valor = x;
    prox = 0;

    setFlag(ItemSendsGeometryChanges);
    setFlag(ItemIsMovable);
    setCacheMode(DeviceCoordinateCache);
    setZValue(-1);
    cabeca = true;
    achado = false;

    setParentItem(pai);    
}

void QOpenHashNodo::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing);
    /*Prepara o Gradiente*/
    QRadialGradient gradient(-4, -3, 50);
    gradient.setCenter(20, 20);
    gradient.setFocalPoint(3, 3);
    gradient.setColorAt(1, QColor(91,91,91).light(220));
    gradient.setColorAt(0, QColor(Qt::white).light(120));

    painter->setBrush(gradient);

    /*Se for o primeiro nó da lista, terá uma posição diferenciada*/    

    /*Verifica se tem filho e desenha a ligação*/
    if(prox != 0){

        /*Desenha a seta*/
        QPointF points[4] = {
             QPointF(30-4,40-5),
             QPointF(30+4,40-5),
             QPointF(30,40),
         };
        /*Pinta a seta*/
        painter->setBrush(QColor(Qt::black));
        painter->drawConvexPolygon(points, 3);

        painter->setBrush(gradient);
        QLineF linee(30,20,30,40);
        painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        painter->drawLine(linee);
    }

    /*Desenha o nó*/
    painter->setPen(QPen(Qt::black, 0));

    if(achado) painter->setBrush(QColor(0,170,255,255));
    else painter->setBrush(gradient);

    painter->drawRoundedRect(10,0, 40,20,10,5);
    /*Desenha o Conteúdo do Nodo*/
    QRect rect = QRect(0,0,60, 20);
    painter->drawText(rect,Qt::AlignCenter,QString::number(valor));

}

void QOpenHashNodo::setBusca(void)
{
    achado = true;
    update();
}

QRectF QOpenHashNodo::boundingRect() const
{
    if(prox != 0){
        return QRectF(0,0,60,60);
    }
    /*Caso seja a raiz*/
    return QRectF(0,0,60,20);
}



