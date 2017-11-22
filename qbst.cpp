#include <cmath>
#include <QString>
#include <QQueue>
#include <QFile>
#include <iostream>
#include <QGraphicsItem>
#include <QLabel>

#include "qbst.h"
#include "qbstnodo.h"

QBST::QBST(int alinhamento):
        QBase(),
        ptraiz(0),
        ultimoNo(0),
        tipoAlinhamento(alinhamento)
{    

}

QBST::~QBST(void)
{
    limparTudo();
}

void QBST::inserir(QBSTNodo* p,int x)
{
    if(p != 0){
        if(x > p->valor){
            if(p->dir == 0) ultimoNo = p->dir = new QBSTNodo(x,p);
            else inserir(p->dir,x);
        }else{
            if(p->esq == 0) ultimoNo = p->esq = new QBSTNodo(x,p);
            else inserir(p->esq,x);
        }
    }
}

void QBST::inserirValor(int x)
{
    if(buscar(ptraiz,x) != 0) throw "BST: O valor já existe";
    else{
        /*Limpa o ultimo nó corrente*/
        if(ultimoNo != 0)
            ultimoNo->pintar(false,2);

        if(ptraiz == 0){
            ultimoNo = ptraiz = new QBSTNodo(x,0);
            getScene()->addItem(ptraiz);            
        }else inserir(ptraiz,x);

        ultimoNo->pintar(true,2);

        /*Depois de inserir os valores, fazemos o alinhamento*/
        if(tipoAlinhamento == 0) alinhamentoPadrao(ptraiz,3);
        else alinhamentoCompleto(ptraiz,3);        
    }
}

int QBST::alturaArvore(QBSTNodo* p)
{
    int altura = 0;
    if(p != 0){
        int alt_dir = alturaArvore(p->dir);
        int alt_esq = alturaArvore(p->esq);
        alt_dir++;
        alt_esq++;
        if(alt_dir > altura) altura = alt_dir;
        if(alt_esq > altura) altura = alt_esq;
    }
    return altura;
}

void QBST::alinhamentoCompleto(QBSTNodo* p,int dir)
{
    if(p != 0){
        int altNodo = alturaArvore(p);
        int quant = pow(2,altNodo);
        if(dir==1) p->setX(20*quant);
        if(dir==2) p->setX(-20*quant);

        if(p->parentItem() != 0) p->setY(50);

        alinhamentoCompleto(p->dir,1);
        alinhamentoCompleto(p->esq,2);
    }
}

void QBST::alinhamentoPadrao(QBSTNodo* p,int dir)
{
    if(p != 0){
        int quantNodo = 0;
        if(dir == 1) quantNodo = quantidadeDeNos(p->esq);
        if(dir == 2) quantNodo = quantidadeDeNos(p->dir);

        if(p->parentItem() != 0) p->setY(50);

        if(dir==1) p->setX(40*(quantNodo+1));
        if(dir==2) p->setX(-40*(quantNodo+1));

        alinhamentoPadrao(p->dir,1);
        alinhamentoPadrao(p->esq,2);
    }
}

int QBST::quantidadeDeNos(QBSTNodo* p)
{
    int quant = 0;
    if(p != 0){
       quant = quant + quantidadeDeNos(p->dir);
       quant = quant + quantidadeDeNos(p->esq);
       quant++;
    }
    return quant;
}

bool QBST::vazia(void){ return ptraiz == 0; }

void QBST::limparTudo(void)
{
    while(!vazia())
        removerValor(ptraiz->valor);    
    getScene()->clear();
}

bool QBST::buscarValor(int x)
{    
    bool achou = false;

    if(vazia())
        throw "A BST esta vazia!";
    else{
        /*Limpa o ultimo nó corrente*/
        if(ultimoNo != 0)
            ultimoNo->pintar(false,4);

        QBSTNodo* aux = buscar(ptraiz,x);
        if(aux != 0){            
            achou = true;
            ultimoNo = aux;
            ultimoNo->pintar(true,1);
        }
    }
    return achou;
}

QBSTNodo* QBST::buscar(QBSTNodo* p,int x)
{
    QBSTNodo* result = 0;

    if(p != 0){
        if(p->valor == x)
            result = p;
        else{
            result = buscar(p->dir,x);
            if(result == 0) result =  buscar(p->esq,x);
        }
    }

    return result;
}

void QBST::remover(QBSTNodo** p, int x,QBSTNodo** pai)
{
    if((*p) != 0){
        if((*p)->valor == x){
            /*Caso seja folha*/
            if((*p)->dir == 0 && (*p)->esq == 0){                
                delete (*p);
                (*p) = 0;
            }else{
                /*Caso tenha apenas  UM filho a direita*/
                if((*p)->dir != 0 && (*p)->esq == 0){
                    if((*p) == ptraiz) (*p)->dir->setParentItem(0);
                    else (*p)->dir->setParentItem((*pai));
                    (*p)->dir->setPos((*p)->pos());
                    QBSTNodo* bkp = (*p);
                    (*p) = (*p)->dir;                    
                    delete (bkp);
                }else if((*p)->dir == 0 && (*p)->esq != 0){  /*Caso tenha apenas UM filho a esquerda*/
                    if((*p) == ptraiz) (*p)->esq->setParentItem(0);
                    else (*p)->esq->setParentItem((*pai));
                    (*p)->esq->setPos((*p)->pos());
                    QBSTNodo* bkp = (*p);
                    (*p) = (*p)->esq;
                    delete (bkp);
                }else if((*p)->dir != 0 && (*p)->esq != 0){ /*Caso possua DOIS filhos*/
                    QBSTNodo* k = (*p)->dir;
                    /*Procura o filho a ser deletado*/
                    while(k->esq != 0)
                        k = k->esq;
                    (*p)->valor = k->valor;
                    remover(&(*p)->dir,k->valor,p);
                }
            }
        }else{
            if(x > (*p)->valor) remover(&(*p)->dir,x,p);
            else remover(&(*p)->esq,x,p);
        }
    }else throw "BST: O elemento não existe na arvore";
}

void QBST::removerValor(int x)
{
    if(vazia()) throw "BST: A arvore está vazia!";
    else remover(&ptraiz,x,&ptraiz);

    if(tipoAlinhamento == 0) alinhamentoPadrao(ptraiz,3);
    else alinhamentoCompleto(ptraiz,3);    
}

QList<int> QBST::imprimirEmLargura(QBSTNodo* p)
{
    QList<int> list;
    QBSTNodo* root = p;
    QQueue<QBSTNodo* > fila;
    if(root != 0){
        fila.enqueue(root);
        while(!fila.empty()) {
            p = fila.dequeue();
            list.push_back(p->valor);
            if(p->esq!=0)
                fila.enqueue(p->esq);
            if(p->dir!=0)
                fila.enqueue(p->dir);
        }
    }
    return list;
}

bool QBST::salvar(QString fileName)
{
    QList<int> a = imprimirEmLargura(ptraiz);

    QFile file(fileName);

    if (file.open(QIODevice::WriteOnly|QIODevice::Text)){
        for(int i=0;i<a.count();i++){
            QString valor = QString::number(a[i]);
            file.write(valor.toLatin1());
            file.write("\n");
        }
    }

    file.close();

    return true;
}

void QBST::setAlinhamento(int tipo)
{
    tipoAlinhamento = tipo;
    if(tipoAlinhamento==0) alinhamentoPadrao(ptraiz,3);
    else alinhamentoCompleto(ptraiz,3);
    QBase::update();
}


