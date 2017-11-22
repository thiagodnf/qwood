#include <QFileDialog>
#include <QPrinter>
#include <QGraphicsItem>
#include <QWheelEvent>
#include <cmath>

#include "qbase.h"

QBase::QBase()
{   
    /*Seta a cena que será desenhada*/
    setScene(new QGraphicsScene);

    /*Adiciona Cor ao plano de fundo*/
    setStyleSheet("\nbackground-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(186, 186, 186), stop:1 rgba(255, 255, 255, 255));");

    setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    /*Coloca o cursor em formato de "mão" para poder movimentar a tela*/
    setDragMode(QGraphicsView::ScrollHandDrag);

    setAttribute(Qt::WA_DeleteOnClose);

    //setRenderHint(QPainter::Antialiasing);

    setAlignment(Qt::AlignTop);
}

bool QBase::exportToPDF(QString filename)
{
    int w = scene()->width();
    int h = scene()->height();

    w = (w < 200)? 300:w;
    h = (h < 200)? 300:h;

    QPrinter *pdfPrinter = new QPrinter;
    QPainter *pdfPainter = new QPainter;
    pdfPrinter->setOutputFormat(QPrinter::PdfFormat);
    pdfPrinter->setPaperSize(QSize(w,h), QPrinter::Point);
    pdfPrinter->setFullPage(true);
    pdfPrinter->setOutputFileName(filename);
    pdfPainter->begin(pdfPrinter);
    scene()->render(pdfPainter);
    pdfPainter->end();

    delete pdfPainter;
    delete pdfPrinter;

    return true;
}

bool QBase::exportToPNG(QString filename)
{    
    QPainter *pngPainter = new QPainter();    
    int w = scene()->width();
    int h = scene()->height();

    w = (w < 200)? 300:w;
    h = (h < 200)? 300:h;

    QImage *image = new QImage(QSize(w,h), QImage::Format_ARGB32);
    pngPainter->setRenderHint(QPainter::Antialiasing);
    // Resolution of the image is 1200 dpi by default
    image->setDotsPerMeterX(1200*254);
    image->setDotsPerMeterY(1200*254);
    pngPainter->begin(image);   
    scene()->render(pngPainter);
    pngPainter->end();
    if(!image->save(filename,"PNG",100)) return false;

    delete pngPainter;
    delete image;

    return true;
}

QGraphicsScene* QBase::getScene(void)
{
    return scene();
}

void QBase::scaleView(qreal scaleFactor)
{
    qreal factor = matrix().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 0.07 || factor > 100)
        return;

    scale(scaleFactor, scaleFactor);
}

void QBase::zoomIn(void)
{
    scaleView(qreal(1.2));
}

void QBase::zoomOut(void)
{
    scaleView(1 / qreal(1.2));
}

void QBase::keyPressEvent(QKeyEvent *event)
{
//    switch (event->key()) {
//        case Qt::Key_Plus:
//            scaleView(qreal(1.2));
//            break;
//        case Qt::Key_Minus:
//            scaleView(1 / qreal(1.2));
//            break;
//        default:
//            QGraphicsView::keyPressEvent(event);
//    }
}

void QBase::wheelEvent(QWheelEvent *event)
{
    scaleView(pow((double)2, -event->delta() / 240.0));
}

void QBase::update(void)
{
    scene()->update();
    scene()->setSceneRect(scene()->itemsBoundingRect());
    /*Atualiza cada elemento da cena*/
//    QList<QGraphicsItem *> itens = scene()->items();
//    for(int i=0;i<itens.size();i++){
//        itens[i]->update();
//    }
}
