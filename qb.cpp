#include <cmath>
#include <QString>
#include <QQueue>
#include <QFile>
#include <iostream>
#include <QGraphicsItem>
#include <QLabel>
#include <iostream>

#include <QtCore/QtCore>

#include "qb.h"
#include "qbnodo.h"

#define NOINTERNO 1
#define FOLHA 2

using namespace std;

QB::QB():QBase()
{    
    QB(0,2);
}

QB::QB(int alinhamento,int ordem_):
        QBase(),
        ptraiz(0),
        ordem(ordem_),
        tipoAlinhamento(alinhamento)
{

}

QB::~QB(void)
{
    limparTudo();
}

QBNodo* QB::inserir(QBNodo* p,int x, QBNodo* pai)
{
    /** @todo*/
}

void QB::bubbleSort(QBNodo* p)
{
    for(int i=0;i<p->index-1;i++){
        for(int j=0;j<p->index-1;j++){
            if(p->valores[j] > p->valores[j+1]){
                int aux = p->valores[j];
                p->valores[j] = p->valores[j+1];
                p->valores[j+1] = aux;

                /*Troca os ponteiros*/
                QBNodo* cop = p->filhos[j+1];
                p->filhos[j+1] = p->filhos[j+2];
                p->filhos[j+2] = cop;

            }
        }
    }

}

void QB::inserirValor(int x)
{
    if(buscar(ptraiz,x,false) != 0) throw "B: O valor já existe";
    else{
        if(vazia()){
            ptraiz = new QBNodo(ordem,0);
            ptraiz->valores[ptraiz->index++] = x;
            bubbleSort(ptraiz);
            QBase::getScene()->addItem(ptraiz);
        }else{
            QBNodo* p = ptraiz;
            /*Procuramos um nó folha para inserir o valor*/
            while(p->tipo != FOLHA){
                p = p->buscarPagina(x);
            }

            QBNodo* node2 = 0;
            while(1){
                if(!p->cheio()){
                    p->valores[p->index++] = x;

                    p->filhos[p->index] = node2;
                    if(node2 != 0) node2->setParentItem(p);

                    bubbleSort(p);
                    break;
                }else{
                    p->valores[p->index++] = x;
                    p->filhos[p->index] = node2;
                    if(node2 != 0) node2->setParentItem(p);
                    bubbleSort(p);

                    QBNodo* aux = node2;

                    node2 = new QBNodo(ordem);

                    QBase::getScene()->addItem(node2);

                    x = split(p,node2);

                    //node2->filhos[node2->index] = aux;
                    if(aux != 0){
                        //aux->setParentItem(node2);
                        node2->tipo = NOINTERNO;
                    }

                    QBNodo* node1 = p;
                    if(node1 == ptraiz){
                        ptraiz = new QBNodo(ordem,0,NOINTERNO);
                        QBase::getScene()->addItem(ptraiz);

                        node1->setParentItem(ptraiz);
                        node2->setParentItem(ptraiz);

                        ptraiz->valores[ptraiz->index++] = x;
                        ptraiz->filhos[ptraiz->index-1] = node1;
                        ptraiz->filhos[ptraiz->index] = node2;

                        break;
                    }else{
                        p = (QBNodo*) p->parentItem();
                    }
                }
            }
        }
    }

    alinhamentoCompleto(ptraiz,0);
    QBase::update();
}

int QB::split(QBNodo* fonte, QBNodo* destino)
{
    int valorMedio = 0;

    int contador = ordem+1;
    fonte->index = ordem;
    while(contador <= ordem*2){
        destino->valores[destino->index++] = fonte->valores[contador];
        destino->filhos[destino->index-1] = fonte->filhos[contador];

        if(destino->filhos[destino->index-1] != 0)
            destino->filhos[destino->index-1]->setParentItem(destino);

        fonte->filhos[contador] = 0;
        fonte->valores[contador] = 50505050;
        contador++;
    }
    destino->filhos[destino->index] = fonte->filhos[contador];
    if(destino->filhos[destino->index] != 0)
        destino->filhos[destino->index]->setParentItem(destino);

    if(fonte->filhos[fonte->index] != 0)
        fonte->filhos[fonte->index]->setParentItem(fonte);

    fonte->filhos[contador] = 0;

    valorMedio =  fonte->valores[fonte->index];
    fonte->valores[fonte->index] = 50505050;

    return valorMedio;

}

void QB::splitReverso(QBNodo* p, QBNodo* irmao,QBNodo* pai,int posicao)
{

}

int QB::alturaArvore(QBNodo* p)
{
    int altura = 0;
    if(p != 0){
        for(int i=0;i<p->quantidadeDeFilhos();i++){
            int alt_filhos = alturaArvore(p->filhos[i]);
            alt_filhos++;
            if(alt_filhos > altura) altura = alt_filhos;
        }        
    }
    return altura;
}

void QB::alinhamentoCompleto(QBNodo* p,int dir)
{
    if(p != 0){
        if(p->parentItem() != 0) p->setY(100);
        if(!p->folha()){

            for(int i=0;i<p->quantidadeDeFilhos();i++){
                alinhamentoCompleto(p->filhos[i],dir+1);

                int altura = alturaArvore(p);

                if(altura == 1){

                    int quantValores = quantidadeDeValoresFolhas(p);
                    int quantFilhos = p->quantidadeDeFilhos()-1;

                    int espacoTotal = quantValores*40+quantFilhos*40;

                    if(i == 0){
                        quantValores = quantidadeDeValoresFolhas(p->filhos[0]);
                        p->filhos[i]->setX(-espacoTotal/2+20*(p->index));
                    }else{
                        quantFilhos = quantValores = 0;

                        for(int j=0;j<i;j++){
                            quantValores += quantidadeDeValoresFolhas(p->filhos[j]);
                            quantFilhos++;
                        }

                        p->filhos[i]->setX(-espacoTotal/2+20*(p->index)+quantValores*40+40*quantFilhos);

                    }
                }else{
                    int quantValores = quantidadeDeValoresFolhas(p);
                    int quantValoresTotal = quantidadeDeValoresTotal(p);


                    int espacoTotal = 40*quantValoresTotal;

                    if(i == 0){
                        quantValores = quantidadeDeValoresTotal(p->filhos[0]);
                        int posX = -espacoTotal/2+20*quantValores+20*(p->index-1);                        
                        p->filhos[i]->setX(posX);
                    }else{
                        int quantFilhos = 0 ;
                        int quantValores = 0;

                        for(int j=0;j<i;j++){
                            quantValores += quantidadeDeValoresTotal(p->filhos[j]);
                            quantFilhos++;
                        }

                        QBNodo* q = p;
                        while(q->filhos[0] != 0){
                            q = q->filhos[0];
                        }

                        QPointF point = p->mapFromItem(q,0,0);                        

                        /*fator usado para deslocar o nó corrente o tamanho necessário para desenhar seus filhos*/
                        int fator = 40*quantidadeDeValoresTotal(p->filhos[i])/2-20;

                        p->filhos[i]->setX(point.x()+40*(quantValores+1)+fator+40*(quantFilhos-1)-20*(p->filhos[i]->index-1));

                    }

                }
            }

        }
    }
}

void QB::alinhamentoPadrao(QBNodo* p,int dir)
{
    /** @todo */
}

int QB::quantidadeDeNos(QBNodo* p)
{
    int quant = 0;
    if(p != 0){
       for(int i=0;i<p->quantidadeDeFilhos();i++){
            quant = quant + quantidadeDeNos(p->filhos[i]);
       }
       quant++;
    }
    return quant;
}

int QB::quantidadeDeFolhas(QBNodo* p)
{
    int quant = 0;
    if(p != 0){
       for(int i=0;i<p->quantidadeDeFilhos();i++){
            quant = quant + quantidadeDeFolhas(p->filhos[i]);
       }
       if(p->folha()) quant++;
    }
    return quant;
}

int QB::quantidadeDeValoresFolhas(QBNodo* p)
{
    int quant = 0;
    if(p != 0){
       for(int i=0;i<p->quantidadeDeFilhos();i++){
            quant = quant + quantidadeDeValoresFolhas(p->filhos[i]);
       }
       if(p->folha()) quant += p->index;
    }
    return quant;
}

int QB::quantidadeDeValoresTotal(QBNodo* p)
{
    int quant = 0;
    if(p != 0){
       for(int i=0;i<p->quantidadeDeFilhos();i++){
            quant = quant + quantidadeDeValoresTotal(p->filhos[i]);
       }
       quant += p->index;
    }
    return quant;
}

bool QB::vazia(void){
    return ptraiz == 0;
}

void QB::limparTudo(void)
{
    while(!vazia()){        
        removerValor(ptraiz->valores[0]);
    }
}

bool QB::buscarValor(int x)
{
    QBase::update();
    bool achou = false;
    if(vazia()) throw "A B esta vazia!";
    else{
        QBNodo* p = buscar(ptraiz,x,true);
        if(p != 0){
            achou = true;
            p->setBusca();
        }
    }
    return achou;
}

QBNodo* QB::buscar(QBNodo* p,int x,bool pintar)
{
    if(p != 0){

        int inicio = 0;
        int fim = p->index-1;

        while(inicio <= fim){
            int media = floor((inicio+fim)/2);
            if(x == p->valores[media]){
                if(pintar) p->indiceBuscado = media;
                return p;
            }

            if(inicio == fim){
                if(x > p->valores[media]){
                    return buscar(p->filhos[media+1],x,pintar);
                }
                if(x < p->valores[media]){
                    if(media==0) return buscar(p->filhos[0],x,pintar);
                    else return buscar(p->filhos[media],x,pintar);
                }
            }else{
                if(x > p->valores[media]){
                    inicio = media+1;
                }
                if(x < p->valores[media]){
                    if(media==0) fim = media;
                    if(inicio == media) fim=media;
                    else fim = media-1;
                }
            }
        }
        return 0;
    }
    else return 0;
}

void QB::remover(QBNodo* p, int x)
{
    QBNodo* node = buscar(p,x,false);

    /*Se retornou 0 é porque o elemento não existe na árvore*/
    if(node != 0){
        if(!node->folha()){
            /*Encontraremos a folha com o sucessor mais próximo de "x"*/
            int indiceRemocao = node->getPosicao(x);
            QBNodo* suc = node->filhos[indiceRemocao+1];
            while(suc->filhos[0] != 0){
                suc = suc->filhos[0];
            }

            node->valores[indiceRemocao] = suc->valores[0];
            node = suc;
            /*Remove o elemento da folha*/
            for(int i=0;i<suc->index-1;i++){
                suc->valores[i] = suc->valores[i+1];
            }
            suc->valores[suc->index--] = 50505050;
        }else{  /*Apenas removemos o valor do nó*/
            /*Pega a posição do nó no vetor*/
            int indiceRemocao = node->getPosicao(x);
            /*Remove o elemento*/
            for(int i=indiceRemocao;i<node->index-1;i++){
                node->valores[i] = node->valores[i+1];
            }
            node->valores[node->index--] = 50505050;
        }
        while(1){
            if(node == ptraiz){
                if(node->index == 0){
                    QBase::getScene()->removeItem(node);
                    delete node;                    
                    ptraiz = 0;
                }
                return;
            }

            /*Verifica se o nó não está subutilizado*/
            if(node->index >= ordem){
                return;
            }else if(irmaoComNosSobrando(node->irmaoDireita(),node->irmaoEsquerda()) != 0){
                /*Redistribuir as chaves entre os irmãos*/
                QBNodo* irmao = irmaoComNosSobrando(node->irmaoDireita(),node->irmaoEsquerda());
                int posicao = node->posicaoEmRelacaoAoPai();
                QBNodo* pai = (QBNodo*) node->parentItem();

                if(irmao == node->irmaoDireita()){
                    node->valores[node->index++] = pai->valores[posicao];
                    pai->valores[posicao] = irmao->valores[0];
                    /*Remove o elemento da folha*/
                    for(int i=0;i<irmao->index-1;i++){
                        irmao->valores[i] = irmao->valores[i+1];
                    }
                    /*Transfere-se o filho do irmão para o node*/
                    node->filhos[node->index] = irmao->filhos[0];
                    /*Colocamos agora um novo para o filho de do irmão que será agora o node*/
                    if(node->filhos[node->index] != 0)
                        node->filhos[node->index]->setParentItem(node);
                    /*Atualiza os filhos do irmão*/
                    for(int i=0;i<irmao->index;i++){
                        irmao->filhos[i] = irmao->filhos[i+1];
                    }
                    irmao->valores[--irmao->index] = 50505050;
                    irmao->filhos[irmao->index+1] = 0;
                }else if(irmao == node->irmaoEsquerda()){

                    /*Fasta o valor para que seja possível adicionar o novo*/
                    for(int i=node->index-1;i>=0;i--){
                        node->valores[i+1] = node->valores[i];
                    }
                    node->valores[0] = pai->valores[posicao-1];
                    node->index++;

                    /*Organiza-se os filhos do node para receber o novo filho*/
                    for(int i=node->index-1;i>=0;i--){
                        node->filhos[i+1] = node->filhos[i];
                    }
                    node->filhos[0] = irmao->filhos[irmao->index];
                    if(node->filhos[0] != 0)
                        node->filhos[0]->setParentItem(node);

                    pai->valores[posicao-1] = irmao->valores[irmao->index-1];

                    irmao->valores[irmao->index-1] = 50505050;
                    irmao->filhos[irmao->index--] = 0;
                }
                return;
            }else if( ((QBNodo*)node->parentItem()) == ptraiz){
                QBNodo* pai = (QBNodo*) node->parentItem();
                if(pai->index == 1){
                    /*Fusão entre o node,seu irmao e o ascendente formará uma nova raiz*/
                    QBNodo* irmao = 0;
                    if(pai->filhos[0] == node){
                        irmao = pai->filhos[1];              
                        node->valores[node->index++] = pai->valores[pai->index-1];
                        pai->filhos[pai->index-1] = 0;
                        int aux = node->index;
                        /*Copia os valores para o irmão*/
                        for(int i=0;i<irmao->index;i++){
                            node->valores[node->index++] = irmao->valores[i];
                        }
                        /*Copia os ponteiros para o irmão*/

                        for(int i=0;i<=irmao->index;i++){
                            node->filhos[aux++]=  irmao->filhos[i];
                            if(node->filhos[aux-1] != 0)
                                node->filhos[aux-1]->setParentItem(node);
                            irmao->filhos[i] = 0;
                        }

                        bubbleSort(node);

                        node->setPos(pai->pos());
                        node->setParentItem(0);

                        ptraiz = node;
                        delete irmao;
                    }else{
                        irmao = pai->filhos[0];
                        irmao->valores[irmao->index++] = pai->valores[pai->index-1];
                        pai->filhos[pai->index-1] = 0;
                        int aux = irmao->index;
                        /*Copia os valores para o irmão*/
                        for(int i=0;i<node->index;i++){
                            irmao->valores[irmao->index++] = node->valores[i];
                        }
                        /*Copia os ponteiros para o irmão*/

                        for(int i=0;i<=node->index;i++){
                            irmao->filhos[aux++]=  node->filhos[i];
                            if(irmao->filhos[aux-1] != 0)
                                irmao->filhos[aux-1]->setParentItem(irmao);
                            node->filhos[i] = 0;
                        }

                        bubbleSort(irmao);

                        irmao->setPos(pai->pos());
                        irmao->setParentItem(0);

                        ptraiz = irmao;
                        delete node;
                    }

                    delete pai;

                }else{/*A raiz possui mais de uma chave, faremos apenas a fusão entre os filhos*/
                    int posicaoEmRelacaoPai = node->posicaoEmRelacaoAoPai();
                    QBNodo* irmao = 0;
                    if(posicaoEmRelacaoPai == pai->index){
                        irmao = pai->filhos[pai->index-1];
                        irmao->valores[irmao->index++] = pai->valores[posicaoEmRelacaoPai-1];
                        pai->filhos[posicaoEmRelacaoPai] = 0;
                        int aux = irmao->index;
                        /*Copia os valores para o irmão*/
                        for(int i=0;i<node->index;i++){
                            irmao->valores[irmao->index++] = node->valores[i];
                        }
                        /*Copia os ponteiros para o irmão*/
                        for(int i=0;i<=node->index;i++){
                            irmao->filhos[aux++]=  node->filhos[i];
                            if(irmao->filhos[aux-1] != 0) irmao->filhos[aux-1]->setParentItem(irmao);
                            node->filhos[i] = 0;
                        }
                        bubbleSort(irmao);
                        //QBase::getScene()->removeItem(node);
                        delete node;
                        /*Remove o elemento do pai e o reorganiza*/
                        for(int i=posicaoEmRelacaoPai-1;i<pai->index-1;i++){
                            irmao->valores[i] = irmao->valores[i+1];
                        }
                        pai->valores[--pai->index] = 50505050;
                        pai->filhos[pai->index+1] = 0;
                    }else{
                        irmao = pai->filhos[posicaoEmRelacaoPai+1];                       
                        node->valores[node->index++] = pai->valores[posicaoEmRelacaoPai];
                         int aux = irmao->index;
                        /*Copia os valores do irmao para o node*/
                        for(int i=0;i<irmao->index;i++){
                            node->valores[node->index++] = irmao->valores[i];
                        }
                        /*Copia os filhos do irmão para o node*/
                        for(int i=0;i<=irmao->index;i++){
                            node->filhos[aux++]=  irmao->filhos[i];
                            if(node->filhos[aux-1] != 0) node->filhos[aux-1]->setParentItem(node);
                            irmao->filhos[i] = 0;
                        }
                        /*Remove o elemento do pai e o reorganiza*/
                        for(int i=posicaoEmRelacaoPai;i<pai->index-1;i++){
                            pai->valores[i] = pai->valores[i+1];
                            pai->filhos[i+1] = pai->filhos[i+2];
                        }
                        pai->valores[--pai->index] = 50505050;
                        pai->filhos[pai->index+1] = 0;

                        //QBase::getScene()->removeItem(irmao);
                        delete irmao;
                    }
                }
                return;
            }else{/*Caso seja um nó interno*/
                QBNodo* pai = (QBNodo*) node->parentItem();
                int posicaoEmRelacaoPai = node->posicaoEmRelacaoAoPai();
                QBNodo* irmao = 0;
                if(posicaoEmRelacaoPai == pai->index){
                    irmao = pai->filhos[pai->index-1];
                    irmao->valores[irmao->index++] = pai->valores[posicaoEmRelacaoPai-1];
                    pai->filhos[posicaoEmRelacaoPai] = 0;
                    int aux = irmao->index;
                    /*Copia os valores para o irmão*/
                    for(int i=0;i<node->index;i++){
                        irmao->valores[irmao->index++] = node->valores[i];
                    }
                    /*Copia os ponteiros para o irmão*/
                    for(int i=0;i<=node->index;i++){
                        irmao->filhos[aux++]=  node->filhos[i];
                        if(irmao->filhos[aux-1] != 0) irmao->filhos[aux-1]->setParentItem(irmao);
                        node->filhos[i] = 0;
                    }
                    bubbleSort(irmao);
                    //QBase::getScene()->removeItem(node);
                    delete node;
                    /*Remove o elemento do pai e o reorganiza*/
                    for(int i=posicaoEmRelacaoPai-1;i<pai->index-1;i++){
                        irmao->valores[i] = irmao->valores[i+1];
                    }
                    pai->valores[--pai->index] = 50505050;
                    pai->filhos[pai->index+1] = 0;
                }else{
                    irmao = pai->filhos[posicaoEmRelacaoPai+1];
                    node->valores[node->index++] = pai->valores[posicaoEmRelacaoPai];
                     int aux = irmao->index;
                    /*Copia os valores do irmao para o node*/
                    for(int i=0;i<irmao->index;i++){
                        node->valores[node->index++] = irmao->valores[i];
                    }
                    /*Copia os filhos do irmão para o node*/
                    for(int i=0;i<=irmao->index;i++){
                        node->filhos[aux++]=  irmao->filhos[i];
                        if(node->filhos[aux-1] != 0) node->filhos[aux-1]->setParentItem(node);
                        irmao->filhos[i] = 0;
                    }
                    /*Remove o elemento do pai e o reorganiza*/
                    for(int i=posicaoEmRelacaoPai;i<pai->index-1;i++){
                        pai->valores[i] = pai->valores[i+1];
                        pai->filhos[i+1] = pai->filhos[i+2];
                    }
                    pai->valores[--pai->index] = 50505050;
                    pai->filhos[pai->index+1] = 0;

                    //QBase::getScene()->removeItem(irmao);
                    delete irmao;
                }
                node = pai;


            }

        }
    }else throw "Arvore B: O elemento não existe";

}

QBNodo* QB::irmaoComNosSobrando(QBNodo* dir,QBNodo* esq)
{
    QBNodo* irmao = 0;    
    if(dir == 0){/*Possui somente o irmão da esquerda*/
        if(esq->index > ordem) irmao = esq;
    }else if(esq == 0){ /*Somente possui irmão direita*/
        if(dir->index > ordem) irmao = dir;
    }else{/*Possui os dois irmãos*/
        if(dir->index > ordem) irmao = dir;
        else if(esq->index > ordem) irmao = esq;
    }
    return irmao;
}

void QB::removerValor(int x)
{
    if(vazia()) throw "A arvore B está vazia!";
    else remover(ptraiz,x);

    alinhamentoCompleto(ptraiz,3);
    QBase::update();
}

QList<int> QB::imprimirEmLargura(QBNodo* p,QList<int> &list)
{
    if(p != 0){
        if(p != 0){
           for(int i=p->quantidadeDeFilhos()-1;i>=0;i--){
                imprimirEmLargura(p->filhos[i],list);
           }
           for(int i=p->index-1;i>=0;i--){
               list.push_back(p->valores[i]);
           }

        }
        return list;
    }


    return list;
}

bool QB::salvar(QString fileName)
{
    QList<int> list;
    imprimirEmLargura(ptraiz,list);

    QFile file(fileName);

    if (file.open(QIODevice::WriteOnly|QIODevice::Text)){
        for(int i=0;i<list.count();i++){
            QString valor = QString::number(list[i]);
            file.write(valor.toLatin1());
            file.write("\n");
        }
    }

    file.close();

    return true;
}

void QB::setAlinhamento(int tipo)
{
    tipoAlinhamento = tipo;
    if(tipoAlinhamento==0) alinhamentoPadrao(ptraiz,3);
    else alinhamentoCompleto(ptraiz,3);
    QBase::update();
}


