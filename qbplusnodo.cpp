#include <QPainter>
#include <iostream>
#include <QtCore>

#include "qbplusnodo.h"

#define NOINTERNO 1
#define FOLHA 2
#define FILE 3

using namespace std;


QBPlusNodo::QBPlusNodo(int _ordem,QBPlusNodo* primeiroArquivo,QBPlusNodo* pai,int ntipo)
    :achado(false),
    raio(40),
    alturaRaiz(10),
    ordem(_ordem),
    indiceBuscado(-1)
{
    //setFlag(ItemIsMovable);

    this->primeiroArquivo = primeiroArquivo;

    valores = new int[ordem*2+1];
    filhos = new QBPlusNodo*[ordem*2 +2];
    index = 0;

    if(ntipo != 0) tipo = ntipo;
    else tipo = FOLHA;

    prox = 0;

    for(int i=0;i<ordem*2;i++) valores[i]=50505050;
    for(int i=0;i<ordem*2+2;i++) filhos[i] = 0;

    setFlag(ItemSendsGeometryChanges);
    setParentItem(pai);
    setY(50);
}

void QBPlusNodo::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing);
    /*Prepara o Gradiente*/
    QRadialGradient gradient(0,0, 40*(index+1));
    gradient.setCenter(40, 20);
    gradient.setFocalPoint(3, 3);
    gradient.setColorAt(1, QColor(91,91,91).light(220));
    gradient.setColorAt(0, QColor(Qt::white).light(120));

    //painter->drawRect(boundingRect());
    /*Aplica o Gradiente de acordo com a situação*/
    if(!achado)
        painter->setBrush(gradient);
    else/*Caso eu esteja a procura desse nó*/
        painter->setBrush(QColor(0,170,255,255));

    /*Desenha a borda*/
    if(tipo == FILE){
        painter->setPen(QPen(QColor(Qt::gray)));
        painter->setBrush(QColor(Qt::gray));
        painter->drawRect(-20,alturaRaiz-5,40*2*ordem+40,raio+10);
        painter->setPen(QPen(QColor(Qt::black)));
        /*Desenha a linha superior*/
        painter->drawLine(-20,alturaRaiz-5,40*2*ordem+40,alturaRaiz-5);
        /*Desenha a linha inferior*/
        painter->drawLine(-20,raio+15,40*2*ordem+40,raio+15);
    }


    /*Desenha o nó*/
    if(tipo != FILE){
        for(int i=0;i<index;i++){
            QRect rect = QRect(i*raio,alturaRaiz,raio,raio);
            if(valores[i] != 50505050){
                if(i==indiceBuscado) painter->setBrush(QColor(0,170,255,255));
                else painter->setBrush(gradient);
                painter->drawRect(i*raio,alturaRaiz,raio,raio);                
                painter->drawText(rect,Qt::AlignCenter,QString::number(valores[i]));
            }
        }
    }else{
        for(int i=0;i<2*ordem;i++){
            QRect rect = QRect(i*raio,alturaRaiz,raio,raio);

            if(i==indiceBuscado) painter->setBrush(QColor(0,170,255,255));
            else painter->setBrush(gradient);
            painter->drawRect(i*raio,alturaRaiz,raio,raio);            
            if(valores[i] != 50505050) painter->drawText(rect,Qt::AlignCenter,QString::number(valores[i]));

        }
    }
    //Reinicia os valores
    indiceBuscado = -1;
    achado = false;

    /*Desenha as ligações*/

    for(int i=0;i<=ordem*2;i++){
        QPointF Qpai = mapFromItem(this,i*raio,raio-20);
        if(tipo == NOINTERNO){
            if(filhos[i] != 0){
                QPointF Qdir = mapFromItem(filhos[i],(40*filhos[i]->index)/2,0+10);
                QLineF linee(QPointF(Qpai.x(),Qpai.y()+30),Qdir);

                painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
                painter->drawLine(linee);
            }
        }else if(tipo==FOLHA){
            if(filhos[i] != 0){
                QPointF Qdir = mapFromItem(filhos[i],(40*(2*ordem))/2,0+10);
                QLineF linee(QPointF(Qpai.x(),Qpai.y()+30),Qdir);

                painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
                painter->drawLine(linee);
            }
        }

    }

    /*Desenha a linha se o nó for a raiz*/

    if(parentItem() == 0){
        QLineF line;
        if(tipo == FOLHA){
            line.setP1(QPointF(x()+(40*index)/2,0));
            line.setP2(QPointF(x()+(40*index)/2,alturaRaiz));
        }else if(tipo == FILE){
            line.setP1(QPointF(x()+(40*(2*ordem))/2,0));
            line.setP2(QPointF(x()+(40*(2*ordem))/2,alturaRaiz));
        }
        painter->drawLine(line);
    }

}

void QBPlusNodo::setBusca(void)
{
    achado = true;
    update();
}

QRectF QBPlusNodo::boundingRect() const
{
    QPointF Qprimeiro;
    QPointF Qultimo;

    if(tipo == NOINTERNO){
        Qprimeiro = mapFromItem(filhos[0],0,0);

        for(int i=0;i<ordem*2+1;i++){
            if(filhos[i] != 0){
                Qultimo= mapFromItem(filhos[i],0,0);
            }
        }
        return QRectF(Qprimeiro.x(), 0 , qAbs(Qprimeiro.x()) + qAbs(Qultimo.x())+raio*(filhos[index]->index) ,qAbs(Qultimo.y())+alturaRaiz+raio);
    }else if(tipo == FILE){
        return QRectF(-20,-10,raio*(2*ordem)+40,raio+alturaRaiz+20);
    }else{
        Qprimeiro = mapFromItem(primeiroArquivo,0,0);

        QBPlusNodo* aux = filhos[0];

        while(aux->prox != 0)
            aux = aux->prox;
        Qultimo= mapFromItem(aux,0,0);

        for(int i=1;i<ordem*2+1;i++){
            if(filhos[i] != 0){
                QPointF tmp = mapFromItem(filhos[i],0,0);
                if(Qprimeiro.x() > tmp.x()){
                    Qprimeiro = tmp;
                }
            }
        }        

        return QRectF(Qprimeiro.x(), 0 , qAbs(Qprimeiro.x()) + qAbs(Qultimo.x())+raio*(2*ordem) ,qAbs(Qultimo.y())+alturaRaiz+raio);

    }


    /*Caso seja a raiz*/
    return QRectF(-10,0,index*raio,raio+alturaRaiz);
}


bool QBPlusNodo::folha(){
    return tipo == FOLHA;
}

int QBPlusNodo::quantidadeDeFilhos(void)
{
    int quant = 0;
    for(int i=0;i<ordem*2+1;i++)
        if(filhos[i] != 0) quant++;
    return quant;
}

QBPlusNodo* QBPlusNodo::buscarPagina(int valor)
{
    if(valor < valores[0]) return filhos[0];
    if(valor > valores[index-1]) return filhos[index];
    else{
        for(int i=1;i<index;i++){
            if(valor < valores[i]) return filhos[i];
        }
    }
}

bool QBPlusNodo::cheio()
{
    if(index >= ordem*2) return true;
    return false;
}
bool QBPlusNodo::vazio()
{
    if(index == 0) return true;
    return false;
}

void QBPlusNodo::bubbleSort(void)
{
    for(int i=0;i<index-1;i++){
        for(int j=0;j<index-1;j++){
            if(valores[j] > valores[j+1]){
                int aux = valores[j];
                valores[j] = valores[j+1];
                valores[j+1] = aux;

                /*Troca os ponteiros*/
                QBPlusNodo* cop = filhos[j+1];
                filhos[j+1] = filhos[j+2];
                filhos[j+2] = cop;
            }
        }
    }
}

int QBPlusNodo::getPosicao(int valor)
{
    int indiceRemocao = -1;
    for(int i=0;i<index;i++){
        if(valores[i] == valor){
            indiceRemocao = i;
            break;
        }
    }
    return indiceRemocao;
}

int QBPlusNodo::posicaoEmRelacaoAoPai(void)
{
    if(parentItem() == 0) return -1;
    int posicaoFilho = -1;
    QBPlusNodo* pai = (QBPlusNodo*) parentItem();
    /*Procuramos inicialmente a posição do elemento em relacao ao pai*/
    for(int i=0;i<=pai->index;i++){
        if(pai->filhos[i] == this){
            posicaoFilho = i;
            break;
        }
    }
    return posicaoFilho;
}

QBPlusNodo* QBPlusNodo::irmaoDireita(void)
{
    if(parentItem()==0) return 0;
    QBPlusNodo* irmaoDir = 0;
    QBPlusNodo* pai = (QBPlusNodo*) parentItem();
    int posicaoFilho = posicaoEmRelacaoAoPai();

    /*Elemento da ponta Direita não tem filho a direita*/
    if(posicaoFilho != pai->index)
        irmaoDir = pai->filhos[posicaoFilho+1];

    return irmaoDir;
}

QBPlusNodo* QBPlusNodo::irmaoEsquerda(void)
{
    if(parentItem()==0) return 0;
    QBPlusNodo* irmaoEsq = 0;
    QBPlusNodo* pai = (QBPlusNodo*) parentItem();
    int posicaoFilho = posicaoEmRelacaoAoPai();

    /*Elemento da ponta esquerda não tem filho a esquerda*/
    if(posicaoFilho != 0)
        irmaoEsq = pai->filhos[posicaoFilho-1];

    return irmaoEsq;
}


