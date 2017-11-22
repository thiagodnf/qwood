#include <QDebug>
#include <QGraphicsScene>
#include <QMessageBox>
#include <QWheelEvent>
#include <cmath>
#include <QFile>
#include <QQueue>

#include "qtrie.h"
#include "qtrienodo.h"

QTrie::QTrie(int alinhamento,int quantidadeDeBits):
    QBase(),
    ptraiz(0),
    ultimoNo(0),
    BITS(quantidadeDeBits),
    tipoAlinhamento(alinhamento)
{

}

QTrie::~QTrie()
{
    limparTudo();
}

bool QTrie::vazia(void){ return ptraiz == 0; }

void QTrie::criarFolha(QTrieNodo** p,int x,QTrieNodo* pai,int dir)
{
    if(pai==0)
        (*p) = new QTrieNodo(x,0);
    else
        (*p) = new QTrieNodo(x,pai,true);
    ultimoNo = (*p);
}

void QTrie::criarNodo(QTrieNodo** p,QTrieNodo* pai,int dir)
{
    (*p) = new QTrieNodo(-1,pai);
}

int QTrie::devolveBit(int x,int pos)
{
    return (x>>(BITS-pos))%2;
}

void QTrie::expandirArvore(QTrieNodo* p,int x,int j)
{
    int backup = p->valor;
    int i=0;
    p->folha = false;
    p->valor = -1;
    p->update();
    for(i=j;i<=BITS;i++){
        if(devolveBit(backup,i) == devolveBit(x,i)){
            if(devolveBit(x,i) == 0){
                criarNodo(&p->esq,p,0);
                p = p->esq;
            }else{
                criarNodo(&p->dir,p,1);
                p = p->dir;
            }
        }else{
            if(devolveBit(x,i) == 0){
                criarFolha(&p->esq,x,p,0);
                criarFolha(&p->dir,backup,p,1);
            }else{
                criarFolha(&p->dir,x,p,1);
                criarFolha(&p->esq,backup,p,0);
            }
            break;
        }
    } /*Fim do laço for*/
}

bool QTrie::validarValor(int valor)
{
    return valor > 0 && valor < pow(2,BITS);
}

void QTrie::inserirValor(int x)
{
    if(!validarValor(x)) throw "TRIE: Numero fora do intervalo para o número de BITS";

    if(vazia()){
        ultimoNo = ptraiz = new QTrieNodo(x,0,true);
        getScene()->addItem(ptraiz);
    }else{
        /*Limpa o ultimo nó corrente*/
        if(ultimoNo != 0)
            ultimoNo->pintar(false,2);

       QTrieNodo* p = ptraiz;
       int i=0;
       for(i=1;i<=BITS;i++){
           if(p->folha){
               if(x == p->valor) printf("O valor ja existe!\n");
               else expandirArvore(p,x,i);
               break;
           }
           if(devolveBit(x,i) == 0){
               if(p->esq == 0){
                   criarFolha(&p->esq,x,p,0);
                   break;
               }else p = p->esq;
           }else{
               if(p->dir == 0){
                   criarFolha(&p->dir,x,p,1);
                   break;
               }else p = p->dir;
           }
       } /*Fim do laço for*/
    }

    ultimoNo->pintar(true,2);

    /*Depois de inserir os valores, fazemos o alinhamento*/
    if(tipoAlinhamento == 0)
        alinhamentoPadrao(ptraiz,3);
    else
        alinhamentoCompleto(ptraiz,3);

    numerosInseridos.push_front(x);
}

void QTrie::alinhamentoCompleto(QTrieNodo* p,int dir)
{
    if(p != 0){
        int altNodo = alturaArvore(p);
        int quant = pow(2,altNodo);
        if(dir==1) p->setX(20*quant);
        if(dir==2) p->setX(-20*quant);

        alinhamentoCompleto(p->dir,1);
        alinhamentoCompleto(p->esq,2);
    }
}

void QTrie::alinhamentoPadrao(QTrieNodo* p,int dir)
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

int QTrie::quantidadeDeNos(QTrieNodo* p)
{
    int quant = 0;
    if(p != 0){
        quant = quant + quantidadeDeNos(p->dir);
        quant = quant + quantidadeDeNos(p->esq);
        quant++;
    }
    return quant;
}

int QTrie::quantidadeDeNos(QTrieNodo* p,int dir)
{
    int quant = 0;
    if(p != 0){
        if(dir == 1) quant = quant + quantidadeDeNos(p->dir,dir);
        else quant = quant + quantidadeDeNos(p->esq,dir);
        quant++;
    }
    return quant;
}

int QTrie::alturaArvore(QTrieNodo* p)
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

bool QTrie::buscarValor(int x)
{   
    bool achou = false;

    if(vazia()) 
        throw "A arvore TRIE esta vazia!";
    else{
        /*Limpa o ultimo nó corrente*/
        if(ultimoNo != 0)
            ultimoNo->pintar(false,2);


        QTrieNodo* aux = buscar(ptraiz,x,1);
        if(aux != 0){
            /*Limpa o ultimo nó corrente*/
            if(ultimoNo != 0)
                ultimoNo->pintar(false,4);
            achou = true;
            ultimoNo = aux;
            ultimoNo->pintar(true,1);
        }
    }

    return achou;
}

QTrieNodo* QTrie::buscar(QTrieNodo* p,int x,int i)
{
    QTrieNodo* achou = 0;
    if(p->folha){
        if(p->valor == x) achou = p;
    }else{
        if(devolveBit(x,i) == 0){
            if(p->esq !=0) achou = buscar(p->esq,x,i+1);
        }else{
            if(p->dir !=0) achou = buscar(p->dir,x,i+1);
        }
    }
    return achou;
}

QList<int> QTrie::imprimirEmLargura(QTrieNodo* p)
{
    QList<int> list;
    QTrieNodo* root = p;
    QQueue<QTrieNodo* > fila;
    if(root != 0){
        fila.enqueue(root);
        while(!fila.empty()) {
            p = fila.dequeue();
            if(p->folha) list.push_back(p->valor);
            if(p->esq!=0)
                fila.enqueue(p->esq);
            if(p->dir!=0)
                fila.enqueue(p->dir);
        }
    }
    return list;
}

bool QTrie::salvar(QString fileName)
{
    QList<int> a = imprimirEmLargura(ptraiz);

    QFile file(fileName);

    if (file.open(QIODevice::WriteOnly|QIODevice::Text)){
        for(int i=0;i<a.count();i++){
            QString valor = QString::number(a[i]);
            file.write(valor.toLatin1());
            file.write("\n");
        }
    }else return false;

    file.close();

    return true;
}

void QTrie::removerValor(int x)
{
    if(vazia())
        throw "A arvore Trie esta vazia!";
    else{
        if(ptraiz->folha){
            if(ptraiz->valor == x){
                delete ptraiz;
                ptraiz = 0;
            }else throw "Trie: valor não existe!";
        }else{
            if(buscarValor(x))
                remover(ptraiz,x,1);
            else throw "Trie: valor não existe!";
        }
    }

    if(tipoAlinhamento == 0)
        alinhamentoPadrao(ptraiz,3);
    else
        alinhamentoCompleto(ptraiz,3);

    for (int i = 0; i < numerosInseridos.size(); i++) {
         if (numerosInseridos.at(i) == x)
             numerosInseridos.removeAt(i);
     }
}

void QTrie::remover(QTrieNodo* p,int x,int i)
{
    if(devolveBit(x,i) == 0){
        if(p->esq != 0){
            if(p->esq->valor == x){
                delete p->esq;
                p->esq = 0;
                if(p->dir != 0 && p->dir->folha){
                    p->valor = p->dir->valor;
                    p->folha = true;
                    getScene()->removeItem(p->dir);
                    delete p->dir;
                    p->dir = 0;
                }
            }else remover(p->esq,x,i+1);
        }
    }else{
        if(p->dir->valor == x){
            delete p->dir;
            p->dir = 0;
            if(p->esq != 0 && p->esq->folha){
                p->valor = p->esq->valor;
                p->folha = true;
                getScene()->removeItem(p->esq);
                delete p->esq;
                p->esq = 0;
            }
        }else remover(p->dir,x,i+1);
    }
    /* Condição usada para verificar se o no deletado se encontra
       no seu ancestral mais proximo e esse ancestral possui irmão.
       Caso contrário, o nó é "subido" até que seja satisfeito a condição */
    if(p->dir == 0 || p->esq == 0){
        if(p->esq != 0 && p->esq->folha){
            p->valor = p->esq->valor;
            p->folha = true;
            delete p->esq;
            p->esq = 0;
        }
        if(p->dir != 0 && p->dir->folha){
            p->valor = p->dir->valor;
            p->folha = true;
            delete p->dir;
            p->dir = 0;
        }
    }
}

void QTrie::limparTudo(void)
{
    while(!numerosInseridos.empty()){
        removerValor(numerosInseridos[0]);        
    }
    getScene()->clear();
}

void QTrie::setAlinhamento(int tipo)
{
    tipoAlinhamento = tipo;
    if(tipoAlinhamento==0) alinhamentoPadrao(ptraiz,3);
    else alinhamentoCompleto(ptraiz,3);
    QBase::update();
}
