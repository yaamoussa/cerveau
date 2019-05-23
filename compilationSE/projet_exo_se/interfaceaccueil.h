#ifndef INTERFACE_ACCUEIL_H
#define INTERFACE_ACCUEIL_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>

class InterfaceAccueil : public QWidget
{
    Q_OBJECT
private:
    QHBoxLayout *box;
    QLabel *label;

public:
    explicit InterfaceAccueil(QWidget *parent = nullptr);
    ~InterfaceAccueil();

signals:

public slots:
};

#endif // ACCUEIL_H
