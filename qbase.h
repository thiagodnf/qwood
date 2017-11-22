#ifndef TREEBASE_H
#define TREEBASE_H

#include <QGraphicsView>

class QBase: public QGraphicsView
{
    Q_OBJECT
public:
    QBase();
    virtual void inserirValor(int x)=0;
    virtual bool buscarValor(int x)=0;
    virtual void removerValor(int x)=0;
    virtual void limparTudo(void)=0;
    virtual bool salvar(QString fileName)=0;
    virtual void setAlinhamento(int tipo) = 0;

    bool exportToPNG(QString filename);
    bool exportToPDF(QString filename);
    QGraphicsScene* getScene(void);
    void scaleView(qreal scaleFactor);
    void keyPressEvent(QKeyEvent *event);

    void zoomIn(void);
    void zoomOut(void);
    void wheelEvent(QWheelEvent *event);
    void update(void);    
};

#endif // QTREE_H
