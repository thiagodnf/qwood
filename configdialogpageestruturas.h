#ifndef CONFIGDIALOGPAGEESTRUTURAS_H
#define CONFIGDIALOGPAGEESTRUTURAS_H

#include <QTabWidget>

namespace Ui {
    class ConfigDialogPageEstruturas;
}

class ConfigDialogPageEstruturas : public QTabWidget {
    Q_OBJECT
public:
    ConfigDialogPageEstruturas(QWidget *parent = 0);
    ~ConfigDialogPageEstruturas();
    int TRIEQuantidadeDeBits(void);
    void setTRIEQuantidadeDeBits(int valor);

protected:
    void changeEvent(QEvent *e);
    bool eventFilter( QObject *dist, QEvent *event );
    void accept(void);
private slots:
    void validarTRIECampoBits(void);

private:
    Ui::ConfigDialogPageEstruturas *ui;
};

#endif // CONFIGDIALOGPAGEESTRUTURAS_H
