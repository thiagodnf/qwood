#include <QPainter>

#include "qtrienodo.h"


QTrieNodo::QTrieNodo(int x,QGraphicsItem* pai,bool folha)
    :pintarNodo(false),
    raio(40),
    alturaRaiz(10)
{
    this->folha = folha;
    valor = x;
    dir = 0;
    esq = 0;

    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);
    setParentItem(pai);
}

void QTrieNodo::pintar(bool pintar, int cor)
{
    pintarNodo = valor;
    this->cor = cor;
    if(!pintar) this->cor = 0;
}

void QTrieNodo::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing);
    /*Prepara o Gradiente*/
    QRadialGradient gradient(-4, -3, 50);
    gradient.setCenter(20, 20);
    gradient.setFocalPoint(3, 3);
    gradient.setColorAt(1, QColor(91,91,91).light(220));
    gradient.setColorAt(0, QColor(Qt::white).light(120));
    painter->setBrush(gradient);

    /*Aplica o Gradiente de acordo com a situação*/
    if(pintarNodo){
        if(cor == 1) painter->setBrush(QColor(0,170,255,255));
        else if(cor == 2) painter->setBrush(QColor(Qt::green));
    }

    /*
     * Caso o nó seja a raiz,
     * iremos então desenhar a ligação do topo com o nó raiz
     */
   if(parentItem() == 0) painter->drawLine(QLineF(QPointF(20,10),QPointF(x()+20,y())));

    /*Caso o nó tenha algum filho, este será desenhado*/
    QPointF Qpai = mapFromItem(this,raio/2,raio/2);
    /*Caso possua filho a esquerda*/
    if(esq != 0){
        QPointF Qesq = mapFromItem(esq,raio/2,raio/2);
        QLineF linee(QPointF(Qpai.x(),Qpai.y()+30),Qesq);
        painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        painter->drawLine(linee);
        /*Desenha o valor da ligação*/
        QRect rect = QRect(linee.x1(),linee.y1(),linee.x2()-linee.x1(),linee.y2()-linee.y1());
        painter->drawText(rect,Qt::AlignCenter,QString::number(0));
    }
    /*Caso possua filho a direita*/
    if(dir != 0){       
        QPointF Qdir = mapFromItem(dir,raio/2,raio/2);
        QLineF linee(QPointF(Qpai.x(),Qpai.y()+30),Qdir);
        painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        painter->drawLine(linee);
        /*Desenha o valor da ligação*/
        QRect rect = QRect(linee.x1(),linee.y1(),linee.x2()-linee.x1(),linee.y2()-linee.y1());
        painter->drawText(rect,Qt::AlignCenter,QString::number(1));
    }

    /*Desenha o TrieNodo*/
    painter->setPen(QPen(Qt::black, 0));
    painter->drawEllipse(0,alturaRaiz, raio,raio);

    if(folha){
        /*Desenha o Conteúdo do TrieNodo*/
        QRect rect = QRect(0, alturaRaiz, raio, raio);
        painter->drawText(rect,Qt::AlignCenter,QString::number(valor));
    }
}

QRectF QTrieNodo::boundingRect() const
{
    if(esq != 0 && dir == 0) return QRectF(esq->x(),0,qAbs(esq->x())+40,esq->y()+50);
    if(esq == 0 && dir != 0) return QRectF(0,0,dir->x()+40,dir->y()+50);
    if(esq != 0 && dir != 0) return QRectF(esq->x(),0,qAbs(esq->x())+dir->x()+40,(dir->y() > esq->y())?dir->y()+50:esq->y()+50);

    /*Caso seja a raiz*/
    return QRectF(0,0,40,50);
}
