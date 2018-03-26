/********************************************************************************
** Form generated from reading UI file 'cpwalker.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CPWALKER_H
#define UI_CPWALKER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CPWalker
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QSlider *horizontalSlider;
    QLCDNumber *lcdNumber;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label_3;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_4;
    QSlider *horizontalSlider_2;
    QLCDNumber *lcdNumber_2;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CPWalker)
    {
        if (CPWalker->objectName().isEmpty())
            CPWalker->setObjectName(QStringLiteral("CPWalker"));
        CPWalker->resize(900, 761);
        CPWalker->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        centralWidget = new QWidget(CPWalker);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(120, 130, 205, 161));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(15);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        verticalLayoutWidget_2 = new QWidget(centralWidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(410, 130, 201, 77));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSlider = new QSlider(verticalLayoutWidget_2);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMinimum(5);
        horizontalSlider->setMaximum(30);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalSlider);

        lcdNumber = new QLCDNumber(verticalLayoutWidget_2);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));

        horizontalLayout_3->addWidget(lcdNumber);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 1);
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(670, 130, 81, 81));
        pushButton_4->setStyleSheet(QStringLiteral("border-image: url(:/play_3.png);"));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(670, 220, 81, 81));
        pushButton_5->setStyleSheet(QStringLiteral("border-image: url(:/stop_2.png);"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(210, 320, 191, 281));
        label_3->setStyleSheet(QStringLiteral("border-image: url(:/kid_transparency.png);"));
        verticalLayoutWidget_3 = new QWidget(centralWidget);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(410, 219, 201, 79));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(verticalLayoutWidget_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_3->addWidget(label_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSlider_2 = new QSlider(verticalLayoutWidget_3);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setMinimum(0);
        horizontalSlider_2->setMaximum(100);
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(horizontalSlider_2);

        lcdNumber_2 = new QLCDNumber(verticalLayoutWidget_3);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));

        horizontalLayout_4->addWidget(lcdNumber_2);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);

        verticalLayout_3->addLayout(horizontalLayout_4);

        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(370, 500, 92, 23));
        checkBox->setStyleSheet(QLatin1String("color: rgb(11, 98, 227);\n"
""));
        checkBox_2 = new QCheckBox(centralWidget);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(370, 540, 92, 23));
        checkBox_2->setStyleSheet(QStringLiteral("color: rgb(11, 98, 227);"));
        checkBox_3 = new QCheckBox(centralWidget);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setGeometry(QRect(230, 500, 92, 23));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(checkBox_3->sizePolicy().hasHeightForWidth());
        checkBox_3->setSizePolicy(sizePolicy);
        checkBox_3->setMaximumSize(QSize(16777215, 16777215));
        checkBox_3->setStyleSheet(QLatin1String("background-color: none;\n"
"color: rgb(11, 98, 227);"));
        checkBox_4 = new QCheckBox(centralWidget);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));
        checkBox_4->setGeometry(QRect(230, 540, 92, 23));
        checkBox_4->setStyleSheet(QLatin1String("background-color: none;\n"
"color: rgb(11, 98, 227);"));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(600, 390, 51, 61));
        pushButton_6->setStyleSheet(QStringLiteral("border-image: url(:/flecha_ar.png);"));
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(650, 450, 61, 51));
        pushButton_7->setStyleSheet(QStringLiteral("border-image: url(:/flecha_d.png);"));
        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(540, 450, 61, 51));
        pushButton_8->setStyleSheet(QStringLiteral("border-image: url(:/flecha_i.png);"));
        pushButton_9 = new QPushButton(centralWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(600, 500, 51, 61));
        pushButton_9->setStyleSheet(QStringLiteral("border-image: url(:/flecha_ab.png);"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(570, 340, 141, 31));
        label_5->setFont(font);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(0, 610, 901, 81));
        label_6->setStyleSheet(QStringLiteral("border-image: url(:/SLOGAN-UQ.png);"));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(290, 0, 291, 111));
        label_7->setStyleSheet(QStringLiteral("border-image: url(:/Programa Ingenieria Electronica.png);"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(650, 40, 113, 25));
        CPWalker->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CPWalker);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 900, 21));
        CPWalker->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CPWalker);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CPWalker->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CPWalker);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CPWalker->setStatusBar(statusBar);

        retranslateUi(CPWalker);

        QMetaObject::connectSlotsByName(CPWalker);
    } // setupUi

    void retranslateUi(QMainWindow *CPWalker)
    {
        CPWalker->setWindowTitle(QApplication::translate("CPWalker", "CPWalker", 0));
        label->setText(QApplication::translate("CPWalker", "Modo de Uso", 0));
        pushButton->setText(QApplication::translate("CPWalker", "Exoesqueleto", 0));
        pushButton_2->setText(QApplication::translate("CPWalker", "Exoesqueleto y SmartWalker", 0));
        pushButton_3->setText(QApplication::translate("CPWalker", "Exoesqueleto manual", 0));
        label_2->setText(QApplication::translate("CPWalker", "Velocidad de marcha en cm/s", 0));
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        label_3->setText(QString());
        label_4->setText(QApplication::translate("CPWalker", "Apertura de las piernas en %", 0));
        checkBox->setText(QString());
        checkBox_2->setText(QString());
        checkBox_3->setText(QString());
        checkBox_4->setText(QString());
        pushButton_6->setText(QString());
        pushButton_7->setText(QString());
        pushButton_8->setText(QString());
        pushButton_9->setText(QString());
        label_5->setText(QApplication::translate("CPWalker", "Teleoperaci\303\263n", 0));
        label_6->setText(QString());
        label_7->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CPWalker: public Ui_CPWalker {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CPWALKER_H
