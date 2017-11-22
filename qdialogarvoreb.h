#ifndef QARVOREBDIALOG_H
#define QARVOREBDIALOG_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
    class QDialogArvoreB;
}

class QDialogArvoreB : public QDialog {
    Q_OBJECT
public:
    QDialogArvoreB(int ordem,QWidget *parent = 0);
    ~QDialogArvoreB();

    int getOrdem(void);
    bool eventFilter( QObject *dist, QEvent *event );
    void accept(void);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::QDialogArvoreB *ui;
};

#endif // QARVOREBDIALOG_H
