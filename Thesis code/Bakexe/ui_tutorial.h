/********************************************************************************
** Form generated from reading UI file 'tutorial.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TUTORIAL_H
#define UI_TUTORIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tutorial
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;

    void setupUi(QDialog *Tutorial)
    {
        if (Tutorial->objectName().isEmpty())
            Tutorial->setObjectName("Tutorial");
        Tutorial->resize(1240, 378);
        layoutWidget = new QWidget(Tutorial);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 40, 1203, 311));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName("label_6");

        verticalLayout->addWidget(label_6);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName("label_7");

        verticalLayout->addWidget(label_7);


        retranslateUi(Tutorial);

        QMetaObject::connectSlotsByName(Tutorial);
    } // setupUi

    void retranslateUi(QDialog *Tutorial)
    {
        Tutorial->setWindowTitle(QCoreApplication::translate("Tutorial", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Tutorial", "Els\305\221 l\303\251p\303\251sk\303\251nt a felfedez\303\251si m\303\263dot v\303\241lasztjuk ki. Az algoritmus ilyenkor felfedezi az utat a c\303\251lhoz.  A felfedezett r\303\241csok s\303\241rga sz\303\255nnel jelennek meg.", nullptr));
        label_2->setText(QCoreApplication::translate("Tutorial", "Ezut\303\241n kiv\303\241laszthatjuk a legr\303\266videbb \303\272tkeres\303\251s m\303\263dj\303\241t. Ilyenkor a program megkeresi a legr\303\266videbb utat kiz\303\241r\303\263lag a felt\303\251rk\303\251pezett r\303\251szeket kihaszn\303\241lva.", nullptr));
        label_3->setText(QCoreApplication::translate("Tutorial", "Lehet\305\221s\303\251g\303\274nk van akad\303\241lyokat lehelyezni, ezeket a program kiker\303\274li ak\303\241r a felt\303\251rk\303\251pez\303\251s sor\303\241n, ak\303\241r a legr\303\266videbb \303\272tkeres\303\251s sor\303\241n.", nullptr));
        label_4->setText(QCoreApplication::translate("Tutorial", "Ez megt\303\266rt\303\251nhet \303\272gy, hogy megadjuk, mennyi akad\303\241lyt szeretn\303\251nk lehelyezni \303\251s a program v\303\251letlenszer\305\261en lehelyezi. Tov\303\241bb\303\241 lehelyezhetj\303\274k \305\221ket \303\272gy is, hogy a gombokra kattintunk.", nullptr));
        label_5->setText(QCoreApplication::translate("Tutorial", "A program k\303\251pes \303\251rz\303\251kelni, ha a v\303\251gpont nem \303\251rhet\305\221 el.", nullptr));
        label_6->setText(QCoreApplication::translate("Tutorial", "A szimul\303\241ci\303\263s m\303\263dban nagyobb mennyis\303\251g\305\261t tudunk lefuttatni r\303\266vid id\305\221 alatt.", nullptr));
        label_7->setText(QCoreApplication::translate("Tutorial", "A t\303\251rk\303\251p bet\303\266lt\305\221 m\303\263dban el\305\221re meghat\303\241rozott t\303\251rk\303\251pekkel tudunk folgalkozn.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tutorial: public Ui_Tutorial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TUTORIAL_H
