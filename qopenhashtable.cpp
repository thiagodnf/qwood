#include <QPainter>

#include "qopenhashtable.h"
#include "qopenhashnodo.h"

QOpenHashTable::QOpenHashTable(int tamanho)
{
    achado = false;
    this->tamanho = tamanho;

    filhos = new QOpenHashNodo*[tamanho];
    for(int i=0;i<tamanho;i++)
        filhos[i] = 0;

    setFlag(ItemSendsGeometryChanges);
    setFlag(ItemIsMovable);
    setCacheMode(DeviceCoordinateCache);
    setZValue(-1);

    setParentItem(0);
}

QOpenHashTable::~QOpenHashTable()
{
}

void QOpenHashTable::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing);
    /*Prepara o Gradiente*/
    QRadialGradient gradient(-4, -3, 50);
    gradient.setCenter(20, 20);
    gradient.setFocalPoint(3, 3);
    gradient.setColorAt(1, QColor(91,91,91).light(220));
    gradient.setColorAt(0, QColor(Qt::white).light(120));

    painter->setBrush(gradient);

    for(int i=0;i<tamanho;i++){
        /*Se ele tiver filhos*/
        if(filhos[i] != 0){
            /*Desenha a seta*/
            QPointF points[3] = {
                 QPointF( (60*i)+30-4,70-5),
                 QPointF( (60*i)+30+4,70-5),
                 QPointF( (60*i)+30,70),
             };
            /*Pinta a seta*/
            painter->setBrush(QColor(Qt::black));
            painter->drawConvexPolygon(points, 3);

            QLineF linee((60*i)+30,50,(60*i)+30,70);
            painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
            painter->drawLine(linee);
            painter->setBrush(gradient);
        }
        QRect rect = QRect(i*60,10,60,40);
        painter->drawRect(i*60,10,60,40);
        painter->drawText(rect,Qt::AlignCenter,QString::number(i));
    }

}

void QOpenHashTable::setBusca(void)
{
    achado = true;
    update();
}

QRectF QOpenHashTable::boundingRect() const
{
    int quantFilhos = 0;
    for(int i=0;i<tamanho;i++){
        if(filhos[i] != 0){            
            quantFilhos++;
            break;
        }        
    }

    if(quantFilhos != 0){        
        return QRectF(0,0,(tamanho)*60,90);
    }

    return QRectF(0,0,(tamanho)*60,50);
}


