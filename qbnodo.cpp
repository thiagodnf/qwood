#include <QPainter>
#include <iostream>
#include <QtCore>

#include "qbnodo.h"

#define NOINTERNO 1
#define FOLHA 2

using namespace std;


QBNodo::QBNodo(int _ordem,QBNodo* pai,int ntipo)
    :achado(false),
    raio(40),
    alturaRaiz(10),
    ordem(_ordem),
    indiceBuscado(-1)
{
    valores = new int[ordem*2+1];
    filhos = new QBNodo*[ordem*2 +2];
    index = 0;

    if(ntipo != 0) tipo = ntipo;
    else tipo = FOLHA;

    for(int i=0;i<ordem*2;i++) valores[i]=50505050;
    for(int i=0;i<ordem*2+2;i++) filhos[i] = 0;

    setFlag(ItemSendsGeometryChanges);
    setParentItem(pai);
    setY(50);
}

void QBNodo::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing);
    /*Prepara o Gradiente*/
    QRadialGradient gradient(0,0, 40*(index+1));
    gradient.setCenter(40, 20);
    gradient.setFocalPoint(3, 3);
    gradient.setColorAt(1, QColor(91,91,91).light(220));
    gradient.setColorAt(0, QColor(Qt::white).light(120));

    /*Aplica o Gradiente de acordo com a situação*/
    if(!achado){
        painter->setBrush(gradient);
    }else{
        /*Caso eu esteja a procura desse nó*/
        painter->setBrush(QColor(0,170,255,255));


    }

    /*Desenha o nó*/
    for(int i=0;i<index;i++){
        QRect rect = QRect(i*raio,alturaRaiz,raio,raio);
        if(valores[i] != 50505050){

            if(i==indiceBuscado){
                painter->setBrush(QColor(0,170,255,255));
                painter->drawRect(i*raio,alturaRaiz,raio,raio);
            }else{
                painter->setBrush(gradient);
                painter->drawRect(i*raio,alturaRaiz,raio,raio);

            }

            painter->drawText(rect,Qt::AlignCenter,QString::number(valores[i]));
        }
    }

    //Reinicia os valores
    indiceBuscado = -1;
    achado = false;

    /*Desenha as ligações*/

    for(int i=0;i<=ordem*2;i++){
        QPointF Qpai = mapFromItem(this,i*raio,raio-20);
        if(filhos[i] != 0){
            QPointF Qdir = mapFromItem(filhos[i],(40*filhos[i]->index)/2,0+10);
            QLineF linee(QPointF(Qpai.x(),Qpai.y()+30),Qdir);

            painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
            painter->drawLine(linee);
        }

    }

    /*Desenha a linha se o nó for a raiz*/
    if(parentItem() == 0){
        QLineF line;
        line.setP1(QPointF(x()+(40*index)/2,0));
        line.setP2(QPointF(x()+(40*index)/2,alturaRaiz));
        painter->drawLine(line);
    }



}

void QBNodo::setBusca(void)
{
    achado = true;
    update();
}

QRectF QBNodo::boundingRect() const
{
    QPointF Qprimeiro;
    QPointF Qultimo;
    
    /*Verifica se é nó interno*/
    if(tipo == 1){
        Qprimeiro = mapFromItem(filhos[0],0,0);

        for(int i=0;i<ordem*2+1;i++){
            if(filhos[i] != 0){
                Qultimo= mapFromItem(filhos[i],0,0);
            }
        }

        return QRectF(Qprimeiro.x(), 0 , qAbs(Qprimeiro.x()) + qAbs(Qultimo.x())+raio*(filhos[index]->index) ,qAbs(Qultimo.y())+alturaRaiz+raio);
    }

    /*Caso seja a raiz*/
    return QRectF(0,0,index*raio,raio+alturaRaiz);
}

void QBNodo::inserirValor(int valor)
{
    if(!cheio()) valores[index++] = valor;
    else valores[index++] = valor;
    bubbleSort();
}

void QBNodo::inserirValor(int valor,QBNodo* irmao)
{

    valores[index++] = valor;
    filhos[index] = irmao;
    bubbleSort();
}

bool QBNodo::folha(){
    return tipo == FOLHA;
}

void QBNodo::inserirFilhos(QBNodo* p, int valor, QBNodo* irmao)
{
    filhos[index-1] = p;
    filhos[index] = irmao;

    p->setParentItem(this);
    irmao->setParentItem(this);
}

void QBNodo::inserirFilhoAntes(QBNodo* p)
{
    filhos[index-1] = p;
    if(p != 0) p->setParentItem(this);
}

void QBNodo::inserirFilho(QBNodo* p)
{
    filhos[index] = p;
    p->setParentItem(this);
}

int QBNodo::quantidadeDeFilhos(void)
{
    int quant = 0;
    for(int i=0;i<ordem*2+1;i++)
        if(filhos[i] != 0) quant++;
    return quant;
}

QBNodo* QBNodo::buscarPagina(int valor)
{
    if(valor < valores[0]) return filhos[0];
    if(valor > valores[index-1]) return filhos[index];
    else{
        for(int i=1;i<index;i++){
            if(valor < valores[i]) return filhos[i];
        }
    }
}

bool QBNodo::cheio()
{
    if(index >= ordem*2) return true;
    return false;
}

bool QBNodo::extrapolou()
{
    if(index > ordem*2) return true;
    return false;
}

bool QBNodo::vazio()
{
    if(index == 0) return true;
    return false;
}

void QBNodo::bubbleSort(void)
{
    for(int i=0;i<index-1;i++){
        for(int j=0;j<index-1;j++){
            if(valores[j] > valores[j+1]){
                int aux = valores[j];
                valores[j] = valores[j+1];
                valores[j+1] = aux;

                /*Troca os ponteiros*/
                QBNodo* cop = filhos[j+1];
                filhos[j+1] = filhos[j+2];
                filhos[j+2] = cop;
            }
        }
    }
}

int QBNodo::getPosicao(int valor)
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

int QBNodo::posicaoEmRelacaoAoPai(void)
{
    if(parentItem() == 0) return -1;
    int posicaoFilho = -1;
    QBNodo* pai = (QBNodo*) parentItem();
    /*Procuramos inicialmente a posição do elemento em relacao ao pai*/
    for(int i=0;i<=pai->index;i++){
        if(pai->filhos[i] == this){
            posicaoFilho = i;
            break;
        }
    }
    return posicaoFilho;
}

QBNodo* QBNodo::irmaoDireita(void)
{
    if(parentItem()==0) return 0;
    QBNodo* irmaoDir = 0;
    QBNodo* pai = (QBNodo*) parentItem();
    int posicaoFilho = posicaoEmRelacaoAoPai();

    /*Elemento da ponta Direita não tem filho a direita*/
    if(posicaoFilho != pai->index)
        irmaoDir = pai->filhos[posicaoFilho+1];

    return irmaoDir;
}

QBNodo* QBNodo::irmaoEsquerda(void)
{
    if(parentItem()==0) return 0;
    QBNodo* irmaoEsq = 0;
    QBNodo* pai = (QBNodo*) parentItem();
    int posicaoFilho = posicaoEmRelacaoAoPai();

    /*Elemento da ponta esquerda não tem filho a esquerda*/
    if(posicaoFilho != 0)
        irmaoEsq = pai->filhos[posicaoFilho-1];

    return irmaoEsq;
}


