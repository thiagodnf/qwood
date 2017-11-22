#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include <QDialog>

class QListWidget;
class QListWidgetItem;
class QStackedWidget;
class ConfigDialogPageEstruturas;

class ConfigDialog: public QDialog
{    
    Q_OBJECT
public:
    ConfigDialog();
    int TRIEQuantidadeDeBits(void);
    void setTRIEQuantidadeDeBits(int valor);
public slots:
    void changePage(QListWidgetItem *current, QListWidgetItem *previous);
private:
    void createIcons();

    QListWidget* contentsWidget;
    QStackedWidget* pagesWidget;

    ConfigDialogPageEstruturas* estruturas;
};

#endif // CONFIGDIALOG_H
