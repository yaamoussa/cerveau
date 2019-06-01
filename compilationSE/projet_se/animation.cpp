#include "animation.h"
#include <QDebug>

Animation::Animation(Etat_redacteur tab_red[3],Etat_lecteur tab_lect[3],bool prior_egale,int alea,QWidget *parent) : QWidget(parent)
{
    for (int i = 0; i < 3; i++) {
        lecteurs[i] = tab_lect[i];
        redacteurs[i] = tab_red[i];
    }

    priorites_egales = prior_egale;

    if (alea != -1)
        n = alea;

    setFixedHeight(500);
    setFixedWidth(1130);
    setStyleSheet("background-color:white");
}


void Animation::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.setPen(QPen(Qt::black,3,Qt::SolidLine,Qt::RoundCap));

    painter.setBrush(QBrush(Qt::white,Qt::SolidPattern));
    painter.drawRect(2,2,1126,496);

    painter.setFont(QFont("Comic Sans MS",8));

    painter.setBrush(QBrush(Qt::gray,Qt::SolidPattern));
    painter.drawRect(420,82,250,380);
    painter.drawText(450,246,"Base de donnees - Nombres aleatoires");

    painter.drawText(137,30,"Redacteurs");
    painter.drawText(830,30,"Lecteurs");

    painter.setFont(QFont("Comic Sans MS",8));
    painter.setPen(QPen(Qt::red,5,Qt::SolidLine,Qt::RoundCap));

    if (priorites_egales)
        painter.drawText(500,35,"Priorites egales");
    else
        painter.drawText(500,35,"Priorites des lecteurs");

    painter.setPen(QPen(Qt::black,3,Qt::SolidLine,Qt::RoundCap));
    painter.setFont(QFont("Comic Sans MS",7));

    if (redacteurs[0] == redacteur_bloque)
    {
        painter.setBrush(QBrush(Qt::red,Qt::SolidPattern));
        painter.drawEllipse(137,41,90,90);
        painter.drawText(175,80,"Bloque");
    }
    else if (redacteurs[0] == redacteur_pret)
    {
        painter.setBrush(QBrush(Qt::yellow,Qt::SolidPattern));
        painter.drawEllipse(137,41,90,90);
        painter.drawText(175,80,"Pret");
    }
    else if (redacteurs[0] == ecriture)
    {
        painter.setBrush(QBrush(Qt::green,Qt::SolidPattern));
        painter.drawEllipse(137,41,90,90);
        painter.drawLine(227,86,430,200);
        painter.drawText(175,80,"Ecriture");
        painter.drawText(100,45,tr("%1").arg(n));
    }

    if (redacteurs[1] == redacteur_bloque)
    {
        painter.setBrush(QBrush(Qt::red,Qt::SolidPattern));
        painter.drawEllipse(137,210,90,90);
        painter.drawText(175,250,"Bloque");
    }
    else if (redacteurs[1] == redacteur_pret)
    {
        painter.setBrush(QBrush(Qt::yellow,Qt::SolidPattern));
        painter.drawEllipse(137,210,90,90);
        painter.drawText(175,250,"Pret");
    }
    else if (redacteurs[1] == ecriture)
    {
        painter.setBrush(QBrush(Qt::green,Qt::SolidPattern));
        painter.drawEllipse(137,210,90,90);
        painter.drawLine(227,255,430,250);
        painter.drawText(175,250,"Ecriture");
        painter.drawText(100,240,tr("%1").arg(n));
    }

    if (redacteurs[2] == redacteur_bloque)
    {
        painter.setBrush(QBrush(Qt::red,Qt::SolidPattern));
        painter.drawEllipse(137,369,90,90);
        painter.drawText(175,410,"Bloque");
    }
    else if (redacteurs[2] == redacteur_pret)
    {
        painter.setBrush(QBrush(Qt::yellow,Qt::SolidPattern));
        painter.drawEllipse(137,369,90,90);
        painter.drawText(175,410,"Pret");
    }
    else if (redacteurs[2] == ecriture)
    {
        painter.setBrush(QBrush(Qt::green,Qt::SolidPattern));
        painter.drawEllipse(137,369,90,90);
        painter.drawLine(227,415,430,300);
        painter.drawText(175,410,"Ecriture");
        painter.drawText(100,385,tr("%1").arg(n));
    }

    if (lecteurs[0] == lecteur_bloque)
    {
        painter.setBrush(QBrush(Qt::red,Qt::SolidPattern));
        painter.drawEllipse(822,41,90,90);
        painter.drawText(860,90,"Bloque");
    }
    else if (lecteurs[0] == lecteur_pret)
    {
        painter.setBrush(QBrush(Qt::yellow,Qt::SolidPattern));
        painter.drawEllipse(822,41,90,90);
        painter.drawText(860,90,"Pret");
    }
    else if (lecteurs[0] == lecture)
    {
        painter.setBrush(QBrush(Qt::green,Qt::SolidPattern));
        painter.drawEllipse(822,41,90,90);
        painter.drawLine(822,82,670,200);
        painter.drawText(860,90,"Lecture");
        painter.drawText(915,55,tr("%1").arg(n));
    }

    if (lecteurs[1] == lecteur_bloque)
    {
        painter.setBrush(QBrush(Qt::red,Qt::SolidPattern));
        painter.drawEllipse(822,210,90,90);
        painter.drawText(860,250,"Bloque");
    }
    else if (lecteurs[1] == lecteur_pret)
    {
        painter.setBrush(QBrush(Qt::yellow,Qt::SolidPattern));
        painter.drawEllipse(822,210,90,90);
        painter.drawText(860,250,"Pret");
    }
    else if (lecteurs[1] == lecture)
    {
        painter.setBrush(QBrush(Qt::green,Qt::SolidPattern));
        painter.drawEllipse(822,210,90,90);
        painter.drawLine(822,250,670,250);
        painter.drawText(860,250,"Lecture");
        painter.drawText(915,225,tr("%1").arg(n));
    }

    if (lecteurs[2] == lecteur_bloque)
    {
        painter.setBrush(QBrush(Qt::red,Qt::SolidPattern));
        painter.drawEllipse(822,369,90,90);
        painter.drawText(860,410,"Bloque");
    }
    else if (lecteurs[2] == lecteur_pret)
    {
        painter.setBrush(QBrush(Qt::yellow,Qt::SolidPattern));
        painter.drawEllipse(822,369,90,90);
        painter.drawText(860,410,"Pret");
    }
    else if (lecteurs[2] == lecture)
    {
        painter.setBrush(QBrush(Qt::green,Qt::SolidPattern));
        painter.drawEllipse(822,369,90,90);
        painter.drawLine(822,415,670,280);
        painter.drawText(860,410,"Lecture");
        painter.drawText(915,385,tr("%1").arg(n));
    }
}
