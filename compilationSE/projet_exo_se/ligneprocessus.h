#ifndef LIGNEPROCESSUS_H
#define LIGNEPROCESSUS_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>

class LigneProcessus : public QWidget
{
    Q_OBJECT
public:
    explicit LigneProcessus(QWidget *parent = nullptr);

signals:

private:
    QWidget *widget;
    QHBoxLayout *ligne;
    QLineEdit *numero;
    QLineEdit *date;
    QLineEdit *duree;
    QLineEdit *priorite;
};

#endif // LIGNEPROCESSUS_H
