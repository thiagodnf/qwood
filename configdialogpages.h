#ifndef CONFIGDIALOGPAGES_H
#define CONFIGDIALOGPAGES_H

#include <QtGui>
#include <QWidget>

class QVBoxLayout;

class ConfigDialogGeral: public QWidget
{
public:
    ConfigDialogGeral(QWidget *parent = 0);
};



class ConfigDialogEstruturas: public QTabWidget
{
public:
    ConfigDialogEstruturas(QWidget *parent = 0);
    void configurarArvoreBPlus(void);
    void configurarArvoreB(void);
private:
    QVBoxLayout *mainBLayout;
};

#endif // CONFIGDIALOGPAGES_H
