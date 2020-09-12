#ifndef APROPOS_H
#define APROPOS_H

#include <QMainWindow>
#include <QLabel>
#include <QVBoxLayout>

class Apropos: public QMainWindow
{
    Q_OBJECT
private:
    QWidget *w;
    QLabel *label1;
    QLabel *label2;
    QVBoxLayout *box;

public:
    explicit Apropos(QWidget *parent = nullptr);
};


#endif // APROPOS_H
