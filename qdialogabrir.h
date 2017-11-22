#ifndef QABRIRDIALOG_H
#define QABRIRDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QFileDialog>

namespace Ui {
    class QDialogAbrir;
}

class QDialogAbrir : public QDialog {
    Q_OBJECT
public:
    QDialogAbrir(QWidget *parent = 0);
    ~QDialogAbrir();

    QString getDiretorio(void);
    int* getArvoresSelecionadas(void);

protected:
    void changeEvent(QEvent *e);
private slots:
    void procurarArquivo(void);
    void accept();

private:
    Ui::QDialogAbrir *ui;
};

#endif // QABRIRDIALOG_H
