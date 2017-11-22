#include "qsplay.h"
#include "qbstnodo.h"

QSplay::QSplay(int alinhamento):
        QBST(alinhamento)
{

}

QSplay::~QSplay(void)
{
    limparTudo();
}

bool QSplay::buscarValor(int x)
{    
    bool achou = false;

    if(vazia())
        throw "A SLAY esta vazia!";
    else{
        /*Limpa o ultimo nó corrente*/
        if(ultimoNo != 0)
            ultimoNo->pintar(false,4);

        buscar(ptraiz,x);
        if(ptraiz->valor == x){            
            achou = true;
            ultimoNo = ptraiz;
            ultimoNo->pintar(true,1);
        }
    }

    if(tipoAlinhamento==0) alinhamentoPadrao(ptraiz,3);
    else alinhamentoCompleto(ptraiz,3);

    return achou;
}

QBSTNodo* QSplay::buscar(QBSTNodo *p,int x)
{
    if(p != 0){
        QBSTNodo* p = ptraiz;
        while(1){
            if(p == 0) break;
            if(p->valor == x){
                QBSTNodo* pai = (QBSTNodo*)p->parentItem();
                if(pai == 0) break; /*O elemento está na raiz*/
                if(pai == ptraiz){
                    if(ptraiz->dir == p) rotacaoZag(&ptraiz);
                    else if(ptraiz->esq == p) rotacaoZig(&ptraiz);
                    break;
                }
                QBSTNodo* avo = (QBSTNodo*) pai->parentItem();
                if(avo->dir == pai){
                    if(pai->dir == p) rotacaoZagZag(avo);
                    else if(pai->esq == p) rotacaoZigZag(avo);
                }else if(avo->esq == pai){
                    if(pai->esq == p) rotacaoZigZig(avo);
                    else if(pai->dir == p) rotacaoZagZig(avo);
                }
                p = avo;
            }else if(x > p->valor) p = p->dir;
            else if(x < p->valor) p = p->esq;
        }
    }
}

void QSplay::rotacaoZag(QBSTNodo** pai)
{
    /*Operações básicas*/
    QBSTNodo* aux = (*pai);
    (*pai) = (*pai)->dir;
    aux->dir = (*pai)->esq;
    (*pai)->esq = aux;

    /*Refaz o parentesco - Dedicado ao Qt*/
    (*pai)->setParentItem(0);
    (*pai)->setPos(aux->pos());
    aux->setParentItem((*pai));
    if(aux->dir != 0)
        aux->dir->setParentItem(aux);
}

void QSplay::rotacaoZig(QBSTNodo** pai)
{
    /*Operações básicas*/
    QBSTNodo* aux = (*pai);
    (*pai) = (*pai)->esq;
    aux->esq = (*pai)->dir;
    (*pai)->dir = aux;

    /*Refaz o parentesco - Dedicado ao Qt*/
    (*pai)->setParentItem(0);
    (*pai)->setPos(aux->pos());
    aux->setParentItem((*pai));
    if(aux->esq != 0)
        aux->esq->setParentItem(aux);
}

void QSplay::rotacaoZagZag(QBSTNodo* avo)
{
    QBSTNodo* pai = avo->dir;
    QBSTNodo* filho = pai->dir;

    /*Fazemos um Swap com o filho e o avó antes de fazer a troca*/
    int aux = avo->valor;
    avo->valor = filho->valor;
    filho->valor = aux;

    /*Agora, fazemos as devidas trocas de ponteiros*/
    avo->dir = filho->dir;
    filho->dir = pai->esq;
    pai->esq = filho;
    pai->dir = filho->esq;
    filho->esq = avo->esq;
    avo->esq = pai;

    /*Refaz o parentesco - Dedicado ao Qt*/
    if(avo->dir != 0) avo->dir->setParentItem(avo);
    if(avo->esq != 0) avo->esq->setParentItem(avo);
    if(pai->dir != 0) pai->dir->setParentItem(pai);
    if(pai->esq != 0) pai->esq->setParentItem(pai);
    if(filho->dir != 0) filho->dir->setParentItem(filho);
    if(filho->esq != 0) filho->esq->setParentItem(filho);
}

void QSplay::rotacaoZigZig(QBSTNodo* avo)
{
    QBSTNodo* pai = avo->esq;
    QBSTNodo* filho = pai->esq;

    /*Fazemos um Swap com o filho e o avó antes de fazer a troca*/
    int aux = avo->valor;
    avo->valor = filho->valor;
    filho->valor = aux;

    /*Agora, fazemos as devidas trocas de ponteiros*/
    avo->esq = filho->esq;
    filho->esq = pai->dir;
    pai->dir = filho;
    pai->esq = filho->dir;
    filho->dir = avo->dir;
    avo->dir = pai;

    /*Refaz o parentesco - Dedicado ao Qt*/
    if(avo->dir != 0) avo->dir->setParentItem(avo);
    if(avo->esq != 0) avo->esq->setParentItem(avo);
    if(pai->dir != 0) pai->dir->setParentItem(pai);
    if(pai->esq != 0) pai->esq->setParentItem(pai);
    if(filho->dir != 0) filho->dir->setParentItem(filho);
    if(filho->esq != 0) filho->esq->setParentItem(filho);
}

void QSplay::rotacaoZigZag(QBSTNodo *avo)
{
    QBSTNodo* pai = avo->dir;
    QBSTNodo* filho = pai->esq;

    /*Fazemos um Swap com o filho e o avó antes de fazer a troca*/
    int aux = avo->valor;
    avo->valor = filho->valor;
    filho->valor = aux;

    /*Agora, fazemos as devidas trocas de ponteiros*/
    pai->esq = filho->dir;
    filho->dir = filho->esq;
    filho->esq = avo->esq;
    avo->esq = filho;

    /*Refaz o parentesco - Dedicado ao Qt*/
    if(avo->esq != 0) avo->esq->setParentItem(avo);
    if(pai->esq != 0) pai->esq->setParentItem(pai);
    if(filho->dir != 0) filho->dir->setParentItem(filho);
    if(filho->esq != 0) filho->esq->setParentItem(filho);
}

void QSplay::rotacaoZagZig(QBSTNodo *avo)
{
    QBSTNodo* pai = avo->esq;
    QBSTNodo* filho = pai->dir;

    /*Fazemos um Swap com o filho e o avó antes de fazer a troca*/
    int aux = avo->valor;
    avo->valor = filho->valor;
    filho->valor = aux;

    /*Agora, fazemos as devidas trocas de ponteiros*/
    pai->dir = filho->esq;
    filho->esq = filho->dir;
    filho->dir = avo->dir;
    avo->dir = filho;

    /*Refaz o parentesco - Dedicado ao Qt*/
    if(avo->dir != 0) avo->dir->setParentItem(avo);
    if(pai->dir != 0) pai->dir->setParentItem(pai);
    if(filho->dir != 0) filho->dir->setParentItem(filho);
    if(filho->esq != 0) filho->esq->setParentItem(filho);

}

QBSTNodo* QSplay::buscaSimples(QBSTNodo* p,int x)
{
    QBSTNodo* result = 0;
    if(p != 0){
        if(p->valor == x) result = p;
        QBSTNodo* dir = buscaSimples(p->dir,x);
        if(dir != 0) result = dir;
        else{
            QBSTNodo* esq = buscaSimples(p->esq,x);
            if(esq != 0) result = esq;
        }
    }
    return result;
}

//#include <cmath>
//#include <QString>
//#include <QQueue>
//#include <QFile>
//#include <iostream>
//#include <fstream>
//#include <qfiledialog.h>
//#include <QGraphicsItem>
//#include <QLabel>
//
//#include "qsplay.h"
//#include "qsplaynodo.h"
//
//QSplay::QSplay(int alinhamento):
//        QBase(),
//        ptraiz(0),
//        tipoAlinhamento(alinhamento)
//{
//
//}
//
//QSplay::~QSplay(void)
//{
//    limparTudo();
//}
//
//void QSplay::inserir(QSplayNodo* p,int x)
//{
//    if(p != 0){
//        if(x > p->valor){
//            if(p->dir == 0){
//                p->dir = new QSplayNodo(x,p);
//                getScene()->addItem(p->dir);
//            }else inserir(p->dir,x);
//        }else{
//            if(p->esq == 0){
//                p->esq = new QSplayNodo(x,p);
//                getScene()->addItem(p->esq);
//            }else inserir(p->esq,x);
//        }
//    }
//}
//
//void QSplay::inserirValor(int x)
//{
//    if(buscaSimples(ptraiz,x) != 0) throw "SPLAY: O valor já existe";
//    else{
//        if(ptraiz == 0){
//            ptraiz = new QSplayNodo(x,0);
//            getScene()->addItem(ptraiz);
//        }else{
//            inserir(ptraiz,x);
//        }
//        /*Depois de inserir os valores, fazemos o alinhamento*/
//        if(tipoAlinhamento==0) alinhamentoPadrao(ptraiz,3);
//        else alinhamentoCompleto(ptraiz,3);
//        QBase::update();
//    }
//}
//
//int QSplay::alturaArvore(QSplayNodo* p)
//{
//    int altura = 0;
//    if(p != 0){
//        int alt_dir = alturaArvore(p->dir);
//        int alt_esq = alturaArvore(p->esq);
//        alt_dir++;
//        alt_esq++;
//        if(alt_dir > altura) altura = alt_dir;
//        if(alt_esq > altura) altura = alt_esq;
//    }
//    return altura;
//}
//
//void QSplay::alinhamentoCompleto(QSplayNodo* p,int dir)
//{
//    if(p != 0){
//        int altNodo = alturaArvore(p);
//        int quant = pow(2,altNodo);
//        if(dir==1) p->setX(20*quant);
//        if(dir==2) p->setX(-20*quant);
//
//        if(p->parentItem() != 0) p->setY(50);
//
//        alinhamentoCompleto(p->dir,1);
//        alinhamentoCompleto(p->esq,2);
//    }
//}
//
//void QSplay::alinhamentoPadrao(QSplayNodo* p,int dir)
//{
//    if(p != 0){
//        int quantNodo = 0;
//        if(dir == 1) quantNodo = quantidadeDeNos(p->esq);
//        if(dir == 2) quantNodo = quantidadeDeNos(p->dir);
//
//        if(p->parentItem() != 0) p->setY(50);
//
//        if(dir==1) p->setX(40*(quantNodo+1));
//        if(dir==2) p->setX(-40*(quantNodo+1));
//
//        alinhamentoPadrao(p->dir,1);
//        alinhamentoPadrao(p->esq,2);
//    }
//}
//
//int QSplay::quantidadeDeNos(QSplayNodo* p)
//{
//    int quant = 0;
//    if(p != 0){
//        quant = quant + quantidadeDeNos(p->dir);
//        quant = quant + quantidadeDeNos(p->esq);
//        quant++;
//    }
//    return quant;
//}
//
//bool QSplay::vazia(void){ return ptraiz == 0;}
//
//void QSplay::limparTudo(void)
//{
//    while(!vazia()){
//        removerValor(ptraiz->valor);
//    }
//}
//
//bool QSplay::buscarValor(int x)
//{
//    QBase::update();
//    bool achou = false;
//    if(vazia()) throw "A SLAY esta vazia!";
//    else{
//        buscar(ptraiz,x);
//        if(ptraiz->valor == x){
//            achou = true;
//            ptraiz->setBusca();
//        }
//    }
//
//    if(tipoAlinhamento==0) alinhamentoPadrao(ptraiz,3);
//    else alinhamentoCompleto(ptraiz,3);
//    QBase::update();
//    return achou;
//}
//
//void QSplay::buscar(QSplayNodo *p,int x)
//{
//    if(p != 0){
//        QSplayNodo* p = ptraiz;
//        while(1){
//            if(p == 0) break;
//            if(p->valor == x){
//                QSplayNodo* pai = (QSplayNodo*)p->parentItem();
//                if(pai == 0) break; /*O elemento está na raiz*/
//                if(pai == ptraiz){
//                    if(ptraiz->dir == p) rotacaoZag(&ptraiz);
//                    else if(ptraiz->esq == p) rotacaoZig(&ptraiz);
//                    break;
//                }
//                QSplayNodo* avo = (QSplayNodo*)pai->parentItem();
//                if(avo->dir == pai){
//                    if(pai->dir == p) rotacaoZagZag(avo);
//                    else if(pai->esq == p) rotacaoZigZag(avo);
//                }else if(avo->esq == pai){
//                    if(pai->esq == p) rotacaoZigZig(avo);
//                    else if(pai->dir == p) rotacaoZagZig(avo);
//                }
//                p = avo;
//            }else if(x > p->valor) p = p->dir;
//            else if(x < p->valor) p = p->esq;
//        }
//    }
//}
//
//void QSplay::rotacaoZag(QSplayNodo** pai)
//{
//    /*Operações básicas*/
//    QSplayNodo* aux = (*pai);
//    (*pai) = (*pai)->dir;
//    aux->dir = (*pai)->esq;
//    (*pai)->esq = aux;
//
//    /*Refaz o parentesco - Dedicado ao Qt*/
//    (*pai)->setParentItem(0);
//    (*pai)->setPos(aux->pos());
//    aux->setParentItem((*pai));
//    if(aux->dir != 0)
//        aux->dir->setParentItem(aux);
//}
//
//void QSplay::rotacaoZig(QSplayNodo** pai)
//{
//    /*Operações básicas*/
//    QSplayNodo* aux = (*pai);
//    (*pai) = (*pai)->esq;
//    aux->esq = (*pai)->dir;
//    (*pai)->dir = aux;
//
//    /*Refaz o parentesco - Dedicado ao Qt*/
//    (*pai)->setParentItem(0);
//    (*pai)->setPos(aux->pos());
//    aux->setParentItem((*pai));
//    if(aux->esq != 0)
//        aux->esq->setParentItem(aux);
//}
//
//void QSplay::rotacaoZagZag(QSplayNodo* avo)
//{
//    QSplayNodo* pai = avo->dir;
//    QSplayNodo* filho = pai->dir;
//
//    /*Fazemos um Swap com o filho e o avó antes de fazer a troca*/
//    int aux = avo->valor;
//    avo->valor = filho->valor;
//    filho->valor = aux;
//
//    /*Agora, fazemos as devidas trocas de ponteiros*/
//    avo->dir = filho->dir;
//    filho->dir = pai->esq;
//    pai->esq = filho;
//    pai->dir = filho->esq;
//    filho->esq = avo->esq;
//    avo->esq = pai;
//
//    /*Refaz o parentesco - Dedicado ao Qt*/
//    if(avo->dir != 0) avo->dir->setParentItem(avo);
//    if(avo->esq != 0) avo->esq->setParentItem(avo);
//    if(pai->dir != 0) pai->dir->setParentItem(pai);
//    if(pai->esq != 0) pai->esq->setParentItem(pai);
//    if(filho->dir != 0) filho->dir->setParentItem(filho);
//    if(filho->esq != 0) filho->esq->setParentItem(filho);
//}
//
//void QSplay::rotacaoZigZig(QSplayNodo* avo)
//{
//    QSplayNodo* pai = avo->esq;
//    QSplayNodo* filho = pai->esq;
//
//    /*Fazemos um Swap com o filho e o avó antes de fazer a troca*/
//    int aux = avo->valor;
//    avo->valor = filho->valor;
//    filho->valor = aux;
//
//    /*Agora, fazemos as devidas trocas de ponteiros*/
//    avo->esq = filho->esq;
//    filho->esq = pai->dir;
//    pai->dir = filho;
//    pai->esq = filho->dir;
//    filho->dir = avo->dir;
//    avo->dir = pai;
//
//    /*Refaz o parentesco - Dedicado ao Qt*/
//    if(avo->dir != 0) avo->dir->setParentItem(avo);
//    if(avo->esq != 0) avo->esq->setParentItem(avo);
//    if(pai->dir != 0) pai->dir->setParentItem(pai);
//    if(pai->esq != 0) pai->esq->setParentItem(pai);
//    if(filho->dir != 0) filho->dir->setParentItem(filho);
//    if(filho->esq != 0) filho->esq->setParentItem(filho);
//}
//
//void QSplay::rotacaoZigZag(QSplayNodo *avo)
//{
//    QSplayNodo* pai = avo->dir;
//    QSplayNodo* filho = pai->esq;
//
//    /*Fazemos um Swap com o filho e o avó antes de fazer a troca*/
//    int aux = avo->valor;
//    avo->valor = filho->valor;
//    filho->valor = aux;
//
//    /*Agora, fazemos as devidas trocas de ponteiros*/
//    pai->esq = filho->dir;
//    filho->dir = filho->esq;
//    filho->esq = avo->esq;
//    avo->esq = filho;
//
//    /*Refaz o parentesco - Dedicado ao Qt*/
//    if(avo->esq != 0) avo->esq->setParentItem(avo);
//    if(pai->esq != 0) pai->esq->setParentItem(pai);
//    if(filho->dir != 0) filho->dir->setParentItem(filho);
//    if(filho->esq != 0) filho->esq->setParentItem(filho);
//}
//
//void QSplay::rotacaoZagZig(QSplayNodo *avo)
//{
//    QSplayNodo* pai = avo->esq;
//    QSplayNodo* filho = pai->dir;
//
//    /*Fazemos um Swap com o filho e o avó antes de fazer a troca*/
//    int aux = avo->valor;
//    avo->valor = filho->valor;
//    filho->valor = aux;
//
//    /*Agora, fazemos as devidas trocas de ponteiros*/
//    pai->dir = filho->esq;
//    filho->esq = filho->dir;
//    filho->dir = avo->dir;
//    avo->dir = filho;
//
//    /*Refaz o parentesco - Dedicado ao Qt*/
//    if(avo->dir != 0) avo->dir->setParentItem(avo);
//    if(pai->dir != 0) pai->dir->setParentItem(pai);
//    if(filho->dir != 0) filho->dir->setParentItem(filho);
//    if(filho->esq != 0) filho->esq->setParentItem(filho);
//
//}
//
//QSplayNodo* QSplay::buscaSimples(QSplayNodo* p,int x)
//{
//    QSplayNodo* result = 0;
//    if(p != 0){
//        if(p->valor == x) result = p;
//        QSplayNodo* dir = buscaSimples(p->dir,x);
//        if(dir != 0) result = dir;
//        else{
//            QSplayNodo* esq = buscaSimples(p->esq,x);
//            if(esq != 0) result = esq;
//        }
//    }
//    return result;
//}
//
//void QSplay::remover(QSplayNodo** p, int x,QSplayNodo** pai)
//{
//    if((*p) != 0){
//        if((*p)->valor == x){
//            /*Caso seja folha*/
//            if((*p)->dir == 0 && (*p)->esq == 0){
//                getScene()->removeItem((*p));
//                delete (*p);
//                (*p) = 0;
//            }else{
//                /*Caso tenha apenas  UM filho a direita*/
//                if((*p)->dir != 0 && (*p)->esq == 0){
//                    if((*p) == ptraiz) (*p)->dir->setParentItem(0);
//                    else (*p)->dir->setParentItem((*pai));
//                    (*p)->dir->setPos((*p)->pos());
//                    QSplayNodo* bkp = (*p);
//                    (*p) = (*p)->dir;
//                    getScene()->removeItem(bkp);
//                    delete (bkp);
//                }else{
//                    /*Caso tenha apenas UM filho a esquerda*/
//                    if((*p)->dir == 0 && (*p)->esq != 0){
//                        if((*p) == ptraiz) (*p)->esq->setParentItem(0);
//                        else (*p)->esq->setParentItem((*pai));
//                        (*p)->esq->setPos((*p)->pos());
//                        QSplayNodo* bkp = (*p);
//                        (*p) = (*p)->esq;
//                        getScene()->removeItem(bkp);
//                        delete (bkp);
//                    }else{
//                        /*Caso possua DOIS filhos*/
//                        if((*p)->dir != 0 && (*p)->esq != 0){
//                            QSplayNodo* k = (*p)->dir;
//                            /*Procura o filho a ser deletado*/
//                            while(k->esq != 0)
//                                k = k->esq;
//                            (*p)->valor = k->valor;
//                            remover(&(*p)->dir,k->valor,p);
//                        }
//                    }
//                }
//            }
//        }else{
//            if(x > (*p)->valor) remover(&(*p)->dir,x,p);
//            else remover(&(*p)->esq,x,p);
//        }
//    }else{
//        throw "O elemento não existe na arvore";
//    }
//}
//
//void QSplay::removerValor(int x)
//{
//    if(vazia()) throw "SPLAY: A arvore está vazia!";
//    else remover(&ptraiz,x,&ptraiz);
//
//    if(tipoAlinhamento==0) alinhamentoPadrao(ptraiz,3);
//    else alinhamentoCompleto(ptraiz,3);
//    QBase::update();
//}
//
//QList<int> QSplay::imprimirEmLargura(QSplayNodo* p)
//{
//    QList<int> list;
//    QSplayNodo* root = p;
//    QQueue<QSplayNodo* > fila;
//    if(root != 0){
//        fila.enqueue(root);
//        while(!fila.empty()) {
//            p = fila.dequeue();
//            list.push_back(p->valor);
//            if(p->esq!=0)
//                fila.enqueue(p->esq);
//            if(p->dir!=0)
//                fila.enqueue(p->dir);
//        }
//    }
//    return list;
//}
//
//bool QSplay::salvar(QString fileName)
//{
//    QList<int> a = imprimirEmLargura(ptraiz);
//
//    QFile file(fileName);
//
//    if (file.open(QIODevice::WriteOnly|QIODevice::Text)){
//        for(int i=0;i<a.count();i++){
//            QString valor = QString::number(a[i]);
//            file.write(valor.toAscii());
//            file.write("\n");
//        }
//    }else return false;
//
//    file.close();
//
//    return true;
//}
//
//void QSplay::setAlinhamento(int tipo)
//{
//    tipoAlinhamento = tipo;
//    if(tipoAlinhamento==0) alinhamentoPadrao(ptraiz,3);
//    else alinhamentoCompleto(ptraiz,3);
//    QBase::update();
//
//}
