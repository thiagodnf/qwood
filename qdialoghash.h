#ifndef QHASHDIALOG_H
#define QHASHDIALOG_H

#include <QDialog>

namespace Ui {
    class QDialogHash;
}

class QDialogHash : public QDialog {
    Q_OBJECT
public:
    QDialogHash(int tamanho,QWidget *parent = 0);
    ~QDialogHash();

    bool eventFilter( QObject *dist, QEvent *event );
    void accept(void);
    int getTamanho(void);
protected:
    void changeEvent(QEvent *e);
    bool isPrimo(int valor);



private:
    Ui::QDialogHash *ui;
};

#endif // QHASHDIALOG_H
