#include <cmath>
#include <QQueue>
#include <QFile>

#include "qavl.h"
#include "qbstnodo.h"

QAVL::QAVL(int alinhamento):
    QBST(alinhamento)
{   

}

QAVL::~QAVL(void)
{
    limparTudo();
}

void QAVL::inserirValor(int x)
{
    //QBST::inserirValor(x);
    if(buscar(ptraiz,x) != 0)
        throw "AVL: O valor já existe";
    else{
        /*Limpa o ultimo nó corrente*/
        if(ultimoNo != 0)
            ultimoNo->pintar(false,2);

        if(ptraiz == 0){
            ultimoNo = ptraiz = new QBSTNodo(x,0);
            getScene()->addItem(ptraiz);
        }else
            inserir(x,&ptraiz,0,0);


        ultimoNo->pintar(true,2);

        /*Depois de inserir os valores, fazemos o alinhamento dos nós*/
        if(tipoAlinhamento == 0) alinhamentoPadrao(ptraiz,3);
        else alinhamentoCompleto(ptraiz,3);

    }
}

void QAVL::inserir(int x, QBSTNodo** p, QBSTNodo** pai,QBSTNodo** avo)
{
    if((*p) != 0){
        if(x > (*p)->valor){
            if((*p)->dir == 0) ultimoNo = (*p)->dir = new QBSTNodo(x,(*p));
            else inserir(x,&(*p)->dir,p,0);
        }else{
            if((*p)->esq == 0) ultimoNo = (*p)->esq = new QBSTNodo(x,(*p));
            else inserir(x,&(*p)->esq,p,0);
        }
        balancear(p);
    }
}

void QAVL::rotacaoSimplesDireita(QBSTNodo** p)
{
    if((*p) != 0){
        QBSTNodo* q = (*p);
        (*p) = (*p)->esq;

        if(q->parentItem() == 0){
            (*p)->setParentItem(0);
            (*p)->setPos(q->pos());
        }else (*p)->setParentItem(q->parentItem());

        /*Salva subarvore B*/
        QBSTNodo* subB = (*p)->dir;
        (*p)->dir = q;
        q->setParentItem((*p));

        q->esq = subB;
        if(subB != 0) subB->setParentItem(q);
    }

}

void QAVL::rotacaoSimplesEsquerda(QBSTNodo** p)
{
    if((*p) != 0){
        QBSTNodo* q = (*p);
        (*p) = (*p)->dir;

        if(q->parentItem() == 0){
            (*p)->setParentItem(0);
            (*p)->setPos(q->pos());
        }else (*p)->setParentItem(q->parentItem());

        /*Salva subarvore B*/
        QBSTNodo* subB = (*p)->esq;
        (*p)->esq = q;
        q->setParentItem((*p));

        q->dir = subB;
        if(subB != 0) subB->setParentItem(q);
    }
}

void QAVL::rotacaoDuplaEsquerda(QBSTNodo** p)
{
    if((*p) != 0){
        QBSTNodo* aux = (*p)->dir;
        QBSTNodo* corrente = (*p);

        (*p) = aux->esq;
        aux->esq->setParentItem(corrente->parentItem());
        if((*p)->parentItem()==0)(*p)->setPos(aux->pos());

        corrente->dir = (*p)->esq;
        if(corrente->dir != 0) corrente->dir->setParentItem(corrente);

        aux->esq = (*p)->dir;
        if(aux->esq != 0) aux->esq->setParentItem(aux);

        (*p)->dir = aux;
        aux->setParentItem((*p));

        (*p)->esq = corrente;
        corrente->setParentItem((*p));
    }
}

void QAVL::rotacaoDuplaDireita(QBSTNodo** p)
{
    if((*p) != 0){
        QBSTNodo* aux = (*p)->esq;
        QBSTNodo* corrente = (*p);

        (*p) = aux->dir;
        aux->dir->setParentItem(corrente->parentItem());
        if((*p)->parentItem()==0)(*p)->setPos(aux->pos());

        corrente->esq = (*p)->dir;
        if(corrente->esq != 0) corrente->esq->setParentItem(corrente);

        aux->dir = (*p)->esq;
        if(aux->dir != 0) aux->dir->setParentItem(aux);

        (*p)->esq = aux;
        aux->setParentItem((*p));

        (*p)->dir = corrente;
        corrente->setParentItem((*p));
    }

}

void QAVL::remover(QBSTNodo** p, int x,QBSTNodo** pai)
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
                }else{
                    /*Caso tenha apenas UM filho a esquerda*/
                    if((*p)->dir == 0 && (*p)->esq != 0){
                        if((*p) == ptraiz) (*p)->esq->setParentItem(0);
                        else (*p)->esq->setParentItem((*pai));
                        (*p)->esq->setPos((*p)->pos());
                        QBSTNodo* bkp = (*p);
                        (*p) = (*p)->esq;                        
                        delete (bkp);
                    }else{
                        /*Caso possua DOIS filhos*/
                        if((*p)->dir != 0 && (*p)->esq != 0){
                            QBSTNodo* k = (*p)->dir;
                            /*Procura o filho a ser deletado*/
                            while(k->esq != 0)
                                k = k->esq;
                            (*p)->valor = k->valor;
                            remover(&(*p)->dir,k->valor,p);
                        }
                    }
                }
            }

            balancear(p);

        }else{
            if(x > (*p)->valor) remover(&(*p)->dir,x,p);
            else remover(&(*p)->esq,x,p);

            balancear(p);
        }
    }else{
        throw "O elemento não existe na arvore";
    }
}

void QAVL::removerValor(int x)
{
    if(vazia())
        throw "A arvore está vazia!";
    else
        remover(&ptraiz,x,&ptraiz);

    if(tipoAlinhamento == 0)
        alinhamentoPadrao(ptraiz,3);
    else
        alinhamentoCompleto(ptraiz,3);
}

void QAVL::balancear(QBSTNodo** p)
{
    if((*p) != 0){

        calcularBalanceamento((*p));

        int balantes = (*p)->bal;
        if((*p)->bal > 1){
            rotacaoSimplesEsquerda(p);
        }
        if((*p)->bal < -1){
            rotacaoSimplesDireita(p);
        }
        calcularBalanceamento((*p));
        int baldepois = (*p)->bal;

        /*Se a simples não resolver, usaremos a dupla*/
        if(balantes == -baldepois){
            if((*p)->bal > 1){
                rotacaoDuplaEsquerda(p);
            }
            if((*p)->bal < -1){
                rotacaoDuplaDireita(p);
            }
            calcularBalanceamento((*p));
        }
    }
}

void QAVL::calcularBalanceamento(QBSTNodo* p)
{
    if(p != 0){
        p->bal = alturaArvore(p->dir)-alturaArvore(p->esq);
        calcularBalanceamento(p->dir);
        calcularBalanceamento(p->esq);
    }
}

//#include <cmath>
//#include <QQueue>
//#include <QFile>
//
//#include "qavl.h"
//#include "qavlnodo.h"
//
//QAVL::QAVL():
//    QBase()
//{
//    ptraiz = 0;
//    autoBalanceamento = true;
//    tipoAlinhamento = 0;
//}
//
//QAVL::QAVL(int alinhamento):
//    QBase()
//{
//    ptraiz = 0;
//    autoBalanceamento = true;
//    tipoAlinhamento = alinhamento;
//}
//
//QAVL::~QAVL(void)
//{
//    limparTudo();
//}
//
//bool QAVL::vazia(void){
//    return ptraiz == 0;
//}
//
//void QAVL::limparTudo(void)
//{
//    while(!vazia()){
//        removerValor(ptraiz->valor);
//    }
//}
//
//void QAVL::inserirValor(int x)
//{
//    if(buscar(ptraiz,x) != 0) throw "AVL: O valor já existe";
//    else{
//        if(ptraiz == 0){
//            ptraiz = new QAVLNodo(x,0);
//            getScene()->addItem(ptraiz);
//        }else{
//            inserir(x,&ptraiz,0,0);
//        }
//        /*Depois de inserir os valores, fazemos o alinhamento dos nós*/
//        if(tipoAlinhamento == 0) alinhamentoPadrao(ptraiz,3);
//        else alinhamentoCompleto(ptraiz,3);
//        QBase::update();
//    }
//}
//
//void QAVL::inserir(int x, QAVLNodo** p, QAVLNodo** pai,QAVLNodo** avo)
//{
//    if((*p) != 0){
//        if(x > (*p)->valor){
//            if((*p)->dir == 0){
//                (*p)->dir = new QAVLNodo(x,(*p));
//                getScene()->addItem((*p)->dir);
//            }else{
//                inserir(x,&(*p)->dir,p,0);
//            }
//        }else{
//            if((*p)->esq == 0){
//                (*p)->esq = new QAVLNodo(x,(*p));
//                getScene()->addItem((*p)->esq);
//            }else{
//                inserir(x,&(*p)->esq,p,0);
//            }
//        }
//
//       if(autoBalanceamento) balancear(p);
//    }
//}
//
//void QAVL::rotacaoSimplesDireita(QAVLNodo** p)
//{
//    if((*p) != 0){
//        QAVLNodo* q = (*p);
//        (*p) = (*p)->esq;
//
//        if(q->parentItem() == 0){
//            (*p)->setParentItem(0);
//            (*p)->setPos(q->pos());
//        }else (*p)->setParentItem(q->parentItem());
//
//        /*Salva subarvore B*/
//        QAVLNodo* subB = (*p)->dir;
//        (*p)->dir = q;
//        q->setParentItem((*p));
//
//        q->esq = subB;
//        if(subB != 0) subB->setParentItem(q);
//    }
//
//}
//
//void QAVL::rotacaoSimplesEsquerda(QAVLNodo** p)
//{
//    if((*p) != 0){
//        QAVLNodo* q = (*p);
//        (*p) = (*p)->dir;
//
//        if(q->parentItem() == 0){
//            (*p)->setParentItem(0);
//            (*p)->setPos(q->pos());
//        }else (*p)->setParentItem(q->parentItem());
//
//        /*Salva subarvore B*/
//        QAVLNodo* subB = (*p)->esq;
//        (*p)->esq = q;
//        q->setParentItem((*p));
//
//        q->dir = subB;
//        if(subB != 0) subB->setParentItem(q);
//    }
//}
//
//void QAVL::rotacaoDuplaEsquerda(QAVLNodo** p)
//{
//    if((*p) != 0){
//        QAVLNodo* aux = (*p)->dir;
//        QAVLNodo* corrente = (*p);
//
//        (*p) = aux->esq;
//        aux->esq->setParentItem(corrente->parentItem());
//        if((*p)->parentItem()==0)(*p)->setPos(aux->pos());
//
//        corrente->dir = (*p)->esq;
//        if(corrente->dir != 0) corrente->dir->setParentItem(corrente);
//
//        aux->esq = (*p)->dir;
//        if(aux->esq != 0) aux->esq->setParentItem(aux);
//
//        (*p)->dir = aux;
//        aux->setParentItem((*p));
//
//        (*p)->esq = corrente;
//        corrente->setParentItem((*p));
//    }
//}
//
//void QAVL::rotacaoDuplaDireita(QAVLNodo** p)
//{
//    if((*p) != 0){
//        QAVLNodo* aux = (*p)->esq;
//        QAVLNodo* corrente = (*p);
//
//        (*p) = aux->dir;
//        aux->dir->setParentItem(corrente->parentItem());
//        if((*p)->parentItem()==0)(*p)->setPos(aux->pos());
//
//        corrente->esq = (*p)->dir;
//        if(corrente->esq != 0) corrente->esq->setParentItem(corrente);
//
//        aux->dir = (*p)->esq;
//        if(aux->dir != 0) aux->dir->setParentItem(aux);
//
//        (*p)->esq = aux;
//        aux->setParentItem((*p));
//
//        (*p)->dir = corrente;
//        corrente->setParentItem((*p));
//    }
//
//}
//
//bool QAVL::buscarValor(int x)
//{
//    QBase::update();
//    bool achou = false;
//    if(vazia()) return achou;
//    else{
//        QAVLNodo* p = buscar(ptraiz,x);
//        if(p != 0){
//            achou = true;
//            p->setBusca();
//        }
//    }
//    return achou;
//}
//
//QAVLNodo* QAVL::buscar(QAVLNodo* p,int x)
//{
//    QAVLNodo* result = 0;
//    if(p != 0){
//        if(p->valor == x) result = p;
//        QAVLNodo* dir = buscar(p->dir,x);
//        if(dir != 0) result = dir;
//        else{
//            QAVLNodo* esq = buscar(p->esq,x);
//            if(esq != 0) result = esq;
//        }
//    }
//    return result;
//}
//
//void QAVL::remover(QAVLNodo** p, int x,QAVLNodo** pai)
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
//                    QAVLNodo* bkp = (*p);
//                    (*p) = (*p)->dir;
//                    getScene()->removeItem(bkp);
//                    delete (bkp);
//                }else{
//                    /*Caso tenha apenas UM filho a esquerda*/
//                    if((*p)->dir == 0 && (*p)->esq != 0){
//                        if((*p) == ptraiz) (*p)->esq->setParentItem(0);
//                        else (*p)->esq->setParentItem((*pai));
//                        (*p)->esq->setPos((*p)->pos());
//                        QAVLNodo* bkp = (*p);
//                        (*p) = (*p)->esq;
//                        getScene()->removeItem(bkp);
//                        delete (bkp);
//                    }else{
//                        /*Caso possua DOIS filhos*/
//                        if((*p)->dir != 0 && (*p)->esq != 0){
//                            QAVLNodo* k = (*p)->dir;
//                            /*Procura o filho a ser deletado*/
//                            while(k->esq != 0)
//                                k = k->esq;
//                            (*p)->valor = k->valor;
//                            remover(&(*p)->dir,k->valor,p);
//                        }
//                    }
//                }
//            }
//
//            if(autoBalanceamento) balancear(p);
//
//        }else{
//            if(x > (*p)->valor) remover(&(*p)->dir,x,p);
//            else remover(&(*p)->esq,x,p);
//
//            if(autoBalanceamento) balancear(p);
//        }
//    }else{
//        throw "O elemento não existe na arvore";
//    }
//}
//
//void QAVL::removerValor(int x)
//{
//    if(vazia()) throw "A arvore está vazia!";
//    else remover(&ptraiz,x,&ptraiz);
//
//    if(tipoAlinhamento == 0) alinhamentoPadrao(ptraiz,3);
//    else alinhamentoCompleto(ptraiz,3);
//    QBase::update();
//}
//
//void QAVL::balancear(QAVLNodo** p)
//{
//    if((*p) != 0){
//
//        calcularBalanceamento((*p));
//
//        int balantes = (*p)->bal;
//        if((*p)->bal > 1){
//            rotacaoSimplesEsquerda(p);
//        }
//        if((*p)->bal < -1){
//            rotacaoSimplesDireita(p);
//        }
//        calcularBalanceamento((*p));
//        int baldepois = (*p)->bal;
//
//        /*Se a simples não resolver, usaremos a dupla*/
//        if(balantes == -baldepois){
//            if((*p)->bal > 1){
//                rotacaoDuplaEsquerda(p);
//            }
//            if((*p)->bal < -1){
//                rotacaoDuplaDireita(p);
//            }
//            calcularBalanceamento((*p));
//        }
//    }
//}
//
//QList<int> QAVL::imprimirEmLargura(QAVLNodo* p)
//{
//    QList<int> list;
//    QAVLNodo* root = p;
//    QQueue<QAVLNodo* > fila;
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
//bool QAVL::salvar(QString fileName)
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
//void QAVL::alinhamentoCompleto(QAVLNodo* p,int dir)
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
//void QAVL::alinhamentoPadrao(QAVLNodo* p,int dir)
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
//int QAVL::alturaArvore(QAVLNodo* p)
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
//int QAVL::quantidadeDeNos(QAVLNodo* p)
//{
//    int quant = 0;
//    if(p != 0){
//       quant = quant + quantidadeDeNos(p->dir);
//       quant = quant + quantidadeDeNos(p->esq);
//       quant++;
//    }
//    return quant;
//}
//
//void QAVL::calcularBalanceamento(QAVLNodo* p)
//{
//    if(p != 0){
//        p->bal = alturaArvore(p->dir)-alturaArvore(p->esq);
//        calcularBalanceamento(p->dir);
//        calcularBalanceamento(p->esq);
//    }
//}
//
//void QAVL::balanceamentoAutomatico(bool opcao)
//{
//    autoBalanceamento = opcao;
//}
//
//void QAVL::setAlinhamento(int tipo)
//{
//    tipoAlinhamento = tipo;
//    if(tipoAlinhamento==0) alinhamentoPadrao(ptraiz,3);
//    else alinhamentoCompleto(ptraiz,3);
//    QBase::update();
//}
