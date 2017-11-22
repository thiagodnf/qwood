#include <QFile>

#include "qopenhash.h"
#include "qopenhashtable.h"
#include "qopenhashnodo.h"

QOpenHash::QOpenHash(int tamanho)
{
    this->tamanho = tamanho;
    ptraiz = new QOpenHashTable(tamanho);
    QBase::getScene()->addItem(ptraiz);
    ultimoValorProcurado = 0;
}


QOpenHash::~QOpenHash()
{
    limparTudo();
}

/*Retorna a posição em que o valor deve ser inserido*/
int QOpenHash::hash(int valor)
{
    return valor%tamanho;
}

void QOpenHash::inserirValor(int x)
{
    if(ultimoValorProcurado != 0){
        /*Volta a cor normal dele*/
        ultimoValorProcurado->achado = false;
        ultimoValorProcurado->update();
    }

    int posicao = hash(x);

    if(ptraiz->filhos[posicao] == 0){
        ptraiz->filhos[posicao] = new QOpenHashNodo(x,ptraiz);        
        ptraiz->filhos[posicao]->setX(60*posicao);
        ptraiz->filhos[posicao]->setY(70);
    }else{
        QOpenHashNodo* p = ptraiz->filhos[posicao];
        ptraiz->filhos[posicao] = new QOpenHashNodo(x,ptraiz);        
        ptraiz->filhos[posicao]->setY(70);
        ptraiz->filhos[posicao]->prox = p;
        ptraiz->filhos[posicao]->setX(60*posicao);
        p->setParentItem(ptraiz->filhos[posicao]);
        p->cabeca = false;
        p->setY(40);
        p->setX(ptraiz->x());        
    }
    QBase::getScene()->addItem(ptraiz->filhos[posicao]);

    ptraiz->update();
    QBase::getScene()->update();
}

bool QOpenHash::buscarValor(int x)
{
    int posicao = hash(x);

    /*Verifica se tem algum valor já pintado na tela*/
    if(ultimoValorProcurado != 0){
        /*Volta a cor normal dele*/
        ultimoValorProcurado->achado = false;
        ultimoValorProcurado->update();
    }    
    bool achou = false;
    if(vazia()) throw "A tabela hash esta vazia!";
    else{
        QOpenHashNodo* p = ptraiz->filhos[posicao];
        /*A lista está vazia, então o número não está lá*/
        if(p == 0) return false;

        do{
            if( p->valor == x){
                break;
            }else{
                p = p->prox;
            }
        }while(p->prox != 0);

        if(p != 0){
            ultimoValorProcurado = p;
            achou = true;
           p->setBusca();
        }
    }
    return achou;
}

bool QOpenHash::vazia(void)
{
    /*Percorre todos as listas. Se encontrar pelo menos uma, não está vazia*/
    for(int i=0;i<tamanho;i++)
        if(ptraiz->filhos[i] != 0) return false;
    /*Caso contrário, ela estará vazia*/
    return true;
}

void QOpenHash::removerValor(int x)
{
    if(!buscarValor(x)) throw "Elemento não existe na árvore";
    else{
        int posicao = hash(x);
        QOpenHashNodo* p = ptraiz->filhos[posicao];

        /*Se o elemento está na tabela, iremos então procurar-lo*/
        do{
            if( p->valor == x) break;
            else p = p->prox;
        }while( p->prox != 0);

        if(p == ptraiz->filhos[posicao]){
            ptraiz->filhos[posicao] = p->prox;
            /*Verifica se p tinha filho*/
            if(ptraiz->filhos[posicao] != 0){
                ptraiz->filhos[posicao]->setParentItem(ptraiz);
                ptraiz->filhos[posicao]->setPos(p->pos());
            }            
        }else{
            /*O no é folha*/
            if( p->prox == 0){
                ((QOpenHashNodo*)p->parentItem())->prox = 0;                
            }else{
                /*Verifica se é a cabeça da lista*/
                if(p == ptraiz->filhos[posicao]){
                    ptraiz->filhos[posicao] = p->prox;
                    /*Verifica se p tinha filho*/
                    if(ptraiz->filhos[posicao] != 0){
                        ptraiz->filhos[posicao]->setParentItem(ptraiz);
                    }               
                }else{ /*Nó interno*/
                    ((QOpenHashNodo*)p->parentItem())->prox = p->prox;
                    if(p->prox != 0){
                        p->prox->setParentItem(p->parentItem());
                    }                    
                }
            }
        }
        delete p;
        ultimoValorProcurado = 0;
        ptraiz->update();
        /*Ainda restou filho nessa posição da tabela*/
        if(ptraiz->filhos[posicao] != 0)
            ptraiz->filhos[posicao]->update();

        QBase::getScene()->update();
    }
}

void QOpenHash::limparTudo(void)
{
    for(int i=0;i<tamanho;i++){
       while(ptraiz->filhos[i] != 0)
           removerValor(ptraiz->filhos[i]->valor);
    }
}

bool QOpenHash::salvar(QString fileName)
{
    QList<int> a;


    for(int i=0;i<tamanho;i++){
        QOpenHashNodo* p = ptraiz->filhos[i];
        while(p->prox != 0){
            p = p->prox;
        }
        do{
            a.push_back(p->valor);
            if(p == ptraiz->filhos[i]) break;
            p = (QOpenHashNodo*)p->parentItem();
        }while(1);
    }

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

void QOpenHash::setAlinhamento(int tipo)
{

}
