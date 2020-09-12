#include "apropos.h"

Apropos::Apropos(QWidget *parent) : QMainWindow(parent)
{
    w = new QWidget;
    box = new QVBoxLayout;
    label1 = new QLabel;
    label2 = new QLabel;

    label1->setText("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"
                    "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF");
    label2->setText("Realise par : El Hadji Aly KANE (P251216) et Moussa Diouf (P25    )");
    label1->setStyleSheet("text-align: center;");
    label2->setStyleSheet("text-align: center;");

    box->addWidget(label1);
    box->addWidget(label2);
    box->setAlignment(label1,Qt::AlignCenter);
    box->setAlignment(label2,Qt::AlignCenter);
    box->setMargin(10);
    box->setContentsMargins(10,10,10,10);
    setFixedHeight(550);
    setFixedWidth(550);
    setWindowTitle("A propos");
    setFont(QFont("Comic Sans MS",11,30,true));

    w->setLayout(box);
    setCentralWidget(w);
}
