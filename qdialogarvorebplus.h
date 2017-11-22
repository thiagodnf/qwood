#ifndef QDIALOGARVOREPLUS_H
#define QDIALOGARVOREPLUS_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
    class QDialogArvoreBPlus;
}

class QDialogArvoreBPlus : public QDialog {
    Q_OBJECT
public:
    QDialogArvoreBPlus(int ordem,QWidget *parent = 0);
    ~QDialogArvoreBPlus();

    int getOrdem(void);
    bool eventFilter( QObject *dist, QEvent *event );
    void accept(void);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::QDialogArvoreBPlus *ui;
};

#endif // QDIALOGARVOREPLUS_H
