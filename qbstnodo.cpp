#include <QPainter>
#include <iostream>
#include <QGraphicsSceneMouseEvent>

#include "qbstnodo.h"

using namespace std;

QBSTNodo::QBSTNodo(int x,QBSTNodo* pai)
{    
    pintarNodo = false;
    cor = 0;

    bal = -1;
    valor = x;
    dir = 0;
    esq = 0;

    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);    
    setParentItem(pai);
}

void QBSTNodo::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget*)
{
    painter->setRenderHint(QPainter::Antialiasing);    

    /*Prepara o Gradiente*/
    QRadialGradient gradient(-4, -3, 50);
    gradient.setCenter(20, 20);   
    gradient.setFocalPoint(3, 3);
    gradient.setColorAt(1, QColor(91,91,91).light(220));
    gradient.setColorAt(0, QColor(Qt::white).light(120));
    /*Aplica o Gradiente no nó*/
    painter->setBrush(gradient);

    if(pintarNodo){
        if(cor == 1) painter->setBrush(QColor(0,170,255,255));
        else if(cor == 2) painter->setBrush(QColor(Qt::green));
    }

    painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::SquareCap, Qt::RoundJoin));

    /*
     * Caso o nó seja a raiz,
     * iremos então desenhar a ligação do topo com o nó raiz
     */
    if(parentItem() == 0) painter->drawLine(QLineF(QPointF(20,10),QPointF(x()+20,y())));

    /*Caso o nó tenha algum filho, este será desenhado*/
    QPointF Qpai = mapFromItem(this,0,50);
    /*Caso possua filho a esquerda*/
    if(esq != 0){
        QPointF Qesq = mapFromItem(esq,20,30);
        QLineF line(QPointF(Qpai.x()+20,Qpai.y()),Qesq);
        painter->drawLine(line);
    }
    /*Caso possua filho a direita*/
    if(dir != 0){
        QPointF Qdir = mapFromItem(dir,20,30);
        QLineF line(QPointF(Qpai.x()+20,Qpai.y()),Qdir);
        painter->drawLine(line);
    }

    /*Desenha o nó*/
    painter->setPen(QPen(Qt::black, 0));
    painter->drawEllipse(0,10,40,40);

    /*Desenha o Conteúdo do Nodo*/
    QRect rect = QRect(0,10,40,40);
    painter->drawText(rect,Qt::AlignCenter,QString::number(valor));

//    /*Desenha a altura de cada filho*/
//    rect = QRect(0, alturaRaiz-13,raio, raio);
//    painter->drawText(rect,Qt::AlignCenter,QString::number(bal));
}

void QBSTNodo::pintar(bool pintar, int cor)
{
    pintarNodo = valor;   
    this->cor = cor;
    if(!pintar) this->cor = 0;
}

QRectF QBSTNodo::boundingRect() const
{
    if(esq != 0 && dir == 0) return QRectF(esq->x(),0,qAbs(esq->x())+40,esq->y()+50);
    if(esq == 0 && dir != 0) return QRectF(0,0,dir->x()+40,dir->y()+50);
    if(esq != 0 && dir != 0) return QRectF(esq->x(),0,qAbs(esq->x())+dir->x()+40,(dir->y() > esq->y())?dir->y()+50:esq->y()+50);

    /*Caso seja a raiz*/
    return QRectF(0,0,40,50);
}


