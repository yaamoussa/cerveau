#ifndef ANIMATION_H
#define ANIMATION_H

#include <QWidget>
#include <QPainter>
#include "etat.h"

class Animation : public QWidget
{
    Q_OBJECT
private:
    Etat_redacteur redacteurs[3];
    Etat_lecteur lecteurs[3];
    int n;
    bool priorites_egales;
    void paintEvent(QPaintEvent *event);

public:
    explicit Animation(Etat_redacteur tab_red[3],Etat_lecteur tab_lect[3],bool prio_egale,int alea,QWidget *parent = nullptr);

signals:


public slots:

};

#endif // ANIMATION_H
