/********************************************************************************
** Form generated from reading UI file 'untitled.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNTITLED_H
#define UI_UNTITLED_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QSplitter *splitter;
    QTableWidget *tableWidget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QLabel *label;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(796, 527);
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 1);

        splitter = new QSplitter(Dialog);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        tableWidget = new QTableWidget(splitter);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        if (tableWidget->rowCount() < 2)
            tableWidget->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 3, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 4, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 5, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 6, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(1, 0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(1, 1, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(1, 2, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(1, 3, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(1, 4, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(1, 5, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        __qtablewidgetitem22->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(1, 6, __qtablewidgetitem22);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setMaximumSize(QSize(16777215, 120));
        tableWidget->setShowGrid(true);
        tableWidget->setGridStyle(Qt::SolidLine);
        tableWidget->setSortingEnabled(false);
        tableWidget->setWordWrap(true);
        tableWidget->setCornerButtonEnabled(true);
        splitter->addWidget(tableWidget);
        tableWidget->horizontalHeader()->setVisible(true);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->verticalHeader()->setVisible(true);
        scrollArea = new QScrollArea(splitter);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(20);
        sizePolicy1.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy1);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1056, 584));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setTextFormat(Qt::RichText);
        label->setMargin(0);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);
        splitter->addWidget(scrollArea);

        gridLayout->addWidget(splitter, 1, 0, 1, 1);


        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Dialog", "\345\270\247\345\244\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Dialog", "\346\214\207\344\273\244\347\240\201", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Dialog", "\345\217\202\346\225\2601", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Dialog", "\345\217\202\346\225\2602", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Dialog", "\345\217\202\346\225\2603", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("Dialog", "\346\240\241\351\252\214\347\240\201", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("Dialog", "\347\273\223\346\235\237\347\254\246", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem7->setText(QApplication::translate("Dialog", "\345\217\221\351\200\201\345\270\247\346\240\274\345\274\217", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem8->setText(QApplication::translate("Dialog", "\346\216\245\346\224\266\345\270\247\346\240\274\345\274\217", Q_NULLPTR));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->item(0, 0);
        ___qtablewidgetitem9->setText(QApplication::translate("Dialog", "0xAA", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->item(0, 1);
        ___qtablewidgetitem10->setText(QApplication::translate("Dialog", "0x07~0xA", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->item(0, 2);
        ___qtablewidgetitem11->setText(QApplication::translate("Dialog", "0x55 0x55 0x55 0x55", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->item(0, 3);
        ___qtablewidgetitem12->setText(QApplication::translate("Dialog", "0x55 0x55 0x55 0x55", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->item(0, 4);
        ___qtablewidgetitem13->setText(QApplication::translate("Dialog", "0x55 0x55 0x55 0x55", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->item(0, 5);
        ___qtablewidgetitem14->setText(QApplication::translate("Dialog", "CS", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->item(0, 6);
        ___qtablewidgetitem15->setText(QApplication::translate("Dialog", "0x2F", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->item(1, 0);
        ___qtablewidgetitem16->setText(QApplication::translate("Dialog", "0xAA", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->item(1, 1);
        ___qtablewidgetitem17->setText(QApplication::translate("Dialog", "0x88", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->item(1, 2);
        ___qtablewidgetitem18->setText(QApplication::translate("Dialog", "0x55 0x55 0x55 0x55", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->item(1, 3);
        ___qtablewidgetitem19->setText(QApplication::translate("Dialog", "0x55 0x55 0x55 0x55", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->item(1, 4);
        ___qtablewidgetitem20->setText(QApplication::translate("Dialog", "0x55 0x55 0x55 0x55", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->item(1, 5);
        ___qtablewidgetitem21->setText(QApplication::translate("Dialog", "CS", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->item(1, 6);
        ___qtablewidgetitem22->setText(QApplication::translate("Dialog", "0x2F", Q_NULLPTR));
        tableWidget->setSortingEnabled(__sortingEnabled);

        label->setText(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:3px; margin-bottom:3px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\217\221\351\200\201\345\270\247 \357\274\232\344\273\216\347\224\265\350\204\221\345\217\221\351\200\201\346\225\260\346\215\256\345\270\247\345\210\260\346\216\247\345\210\266\346\235\277\343\200\202</p>\n"
"<p style=\" margin-top:3px; margin-bottom:3px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\216\245\346\224\266\345\270\247 \357\274\232\344\273\216\346\216\247\345\210\266\346\235\277\345\217\221\351\200\201\346\225\260\346\215\256\345\270\247\345\210\260\347\224\265\350\204\221\343\200\202</p>\n"
"<p style=\" margin-top"
                        ":3px; margin-bottom:3px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\350\265\267\345\247\213\347\254\246 \357\274\232 \346\225\260\346\215\256\345\270\247\347\232\204\345\274\200\345\244\264\345\255\227\347\254\246\357\274\214\345\233\272\345\256\232\346\230\2570xAA\343\200\202</p>\n"
"<p style=\" margin-top:3px; margin-bottom:3px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\214\207\344\273\244\347\240\201 \357\274\232 \345\212\250\344\275\234\346\214\207\344\273\244 0x07:\350\256\276\347\275\256PID\345\217\202\346\225\260\357\274\233 0x08:\350\256\276\347\275\256\347\233\256\346\240\207\345\200\274\357\274\2330x09:\345\244\215\344\275\215\346\216\247\345\210\266\346\235\277\357\274\2330x0A:\345\220\257\345\212\250\357\274\2330x88:\346\216\247\345\210\266\346\235\277\345\217\215\351\246\210\346\225\260\346\215\256\343\200\202</p>\n"
"<p style=\" margin-top:3px; margin-bottom:3px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent"
                        ":0px;\">\345\217\202\346\225\2601  \357\274\232 \347\254\254\344\270\200\344\270\252\345\217\202\346\225\260\345\200\274\357\274\214\351\225\277\345\272\246\344\270\2724\344\270\252\345\255\227\350\212\202\347\232\204\346\265\256\347\202\271\345\236\213\346\225\260\346\215\256\343\200\202\345\246\202\346\236\234\346\225\260\346\215\256\345\270\247\344\270\215\351\234\200\350\246\201\344\275\277\347\224\250\345\217\202\346\225\260\357\274\214\345\210\231\344\275\277\347\224\2500x55\345\241\253\345\205\205\343\200\202</p>\n"
"<p style=\" margin-top:3px; margin-bottom:3px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\217\202\346\225\2602  \357\274\232 \347\254\254\344\272\214\344\270\252\345\217\202\346\225\260\345\200\274\357\274\214\351\225\277\345\272\246\344\270\2724\344\270\252\345\255\227\350\212\202\347\232\204\346\265\256\347\202\271\345\236\213\346\225\260\346\215\256\343\200\202\345\246\202\346\236\234\346\225\260\346\215\256\345\270\247\344\270\215\351\234\200\350\246\201"
                        "\344\275\277\347\224\250\345\217\202\346\225\260\357\274\214\345\210\231\344\275\277\347\224\2500x55\345\241\253\345\205\205\343\200\202</p>\n"
"<p style=\" margin-top:3px; margin-bottom:3px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\217\202\346\225\2603  \357\274\232 \347\254\254\344\270\211\344\270\252\345\217\202\346\225\260\345\200\274\357\274\214\351\225\277\345\272\246\344\270\2724\344\270\252\345\255\227\350\212\202\347\232\204\346\265\256\347\202\271\345\236\213\346\225\260\346\215\256\343\200\202\345\246\202\346\236\234\346\225\260\346\215\256\345\270\247\344\270\215\351\234\200\350\246\201\344\275\277\347\224\250\345\217\202\346\225\260\357\274\214\345\210\231\344\275\277\347\224\2500x55\345\241\253\345\205\205\343\200\202</p>\n"
"<p style=\" margin-top:3px; margin-bottom:3px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\240\241\351\252\214\347\240\201 \357\274\232 \347\264\257\345\212\240\345\222\214\346\240\241\351\252\214\357\274"
                        "\214\345\260\206\346\214\207\344\273\244\347\240\201\345\217\2123\344\270\252\345\217\202\346\225\260\345\205\26113\344\270\252\345\255\227\350\212\202\347\232\204\346\225\260\346\215\256\350\277\233\350\241\214\347\264\257\345\212\240\357\274\214\345\217\226\344\275\2168\344\275\215\345\260\261\346\230\257\346\243\200\351\252\214\347\240\201\343\200\202</p>\n"
"<p style=\" margin-top:3px; margin-bottom:3px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\347\273\223\346\235\237\347\254\246 \357\274\232 \346\225\260\346\215\256\345\270\247\347\232\204\347\273\223\346\235\237\345\255\227\347\254\246\357\274\214\345\233\272\345\256\232\344\270\2720x2F\343\200\202</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:3px; margin-bottom:3px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:3px; margin-bottom:3px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\217\202\346\225\2601/2/3\346\225\260"
                        "\346\215\256\347\261\273\345\236\213\350\257\264\346\230\216\357\274\232\346\265\256\347\202\271\346\225\260\345\255\230\345\202\250\344\275\277\347\224\250IEEE754\346\240\207\345\207\206\357\274\214\345\205\267\344\275\223\347\232\204\346\240\207\345\207\206\345\256\232\344\271\211\350\257\267\350\207\252\350\241\214\346\220\234\347\264\242\344\272\206\350\247\243\343\200\202\344\275\277\347\224\250C\350\257\255\350\250\200\345\217\257\344\273\245\344\275\277\347\224\250\345\205\261\347\224\250\344\275\223\347\261\273\345\236\213\346\235\245\345\260\206\346\265\256\347\202\271\346\225\260\350\275\254\346\215\242\346\210\220\346\225\264\345\236\213\346\225\260\346\215\256\343\200\202</p>\n"
"<p style=\" margin-top:3px; margin-bottom:3px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; color:#d6bb9a;\">--------------------------------------</span></p>\n"
"<p style=\" margin-top:3px; margin-bottom:3px; margin-left:0px; margin-right:0px; -qt-block-indent:0"
                        "; text-indent:0px;\"><span style=\" font-weight:600; font-style:italic; color:#308c96;\">typedef</span><span style=\" font-weight:600; color:#308c96;\"> </span><span style=\" font-weight:600; font-style:italic; color:#308c96;\">union</span><span style=\" font-weight:600; color:#bec0c2;\"> </span><span style=\" font-weight:600; color:#8c8e8f;\">{</span></p>\n"
"<p style=\" margin-top:3px; margin-bottom:3px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New'; font-weight:600; color:#d69aa7;\">    </span><span style=\" font-family:'Courier New'; font-weight:600; color:#a25151;\">float</span><span style=\" font-family:'Courier New'; font-weight:600; color:#bec0c2;\">   </span><span style=\" font-family:'Courier New'; font-weight:600;\">Float</span><span style=\" font-family:'Courier New'; font-weight:600; color:#d6bb9a;\">;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:"
                        "0px;\"><span style=\" font-family:'Courier New'; font-weight:600; color:#bec0c2;\">    </span><span style=\" font-family:'Courier New'; font-weight:600; color:#a25151;\">uint32_t</span><span style=\" font-family:'Courier New'; font-weight:600; color:#bec0c2;\"> </span><span style=\" font-family:'Courier New'; font-weight:600;\">IntNum</span><span style=\" font-family:'Courier New'; font-weight:600; color:#d6bb9a;\">;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New'; font-weight:600; color:#8f7d67;\">}</span><span style=\" font-family:'Courier New'; font-weight:600; color:#a25151;\">FloatToInt_Typedef</span><span style=\" font-family:'Courier New'; font-weight:600; color:#d6bb9a;\">;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New'; font-weight:600; color:#a25"
                        "151;\">FloatToInt_Typedef</span><span style=\" font-family:'Courier New'; font-weight:600; color:#bec0c2;\"> </span><span style=\" font-weight:600;\">ftoi</span><span style=\" font-family:'Courier New'; font-weight:600; color:#d6bb9a;\">;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">ftoi.Float</span><span style=\" font-weight:600; color:#bec0c2;\"> </span><span style=\" font-weight:600; color:#8c8e8f;\">=</span><span style=\" font-weight:600; color:#bec0c2;\"> </span><span style=\" font-weight:600; color:#6a6b6c;\">1.5f</span><span style=\" font-weight:600; color:#95826b;\">;// \346\265\256\347\202\271\345\236\213\346\225\260\346\215\256</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">ftoi.Int</span><span style=\" font-weight:600; color:#d6bb9a;\">;         </span><sp"
                        "an style=\" font-weight:600; color:#95826b;\">// \346\225\264\345\236\213\346\225\260\346\215\256\357\274\214\346\225\260\345\200\274\346\230\257 0x00000C3F</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; color:#d6bb9a;\">--------------------------------------</span></p>\n"
"<p style=\" margin-top:3px; margin-bottom:3px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">ftoi.Int\345\260\261\346\230\257\345\215\240\347\224\2504\344\270\252\345\255\227\350\212\202\347\232\204\345\217\202\346\225\260\357\274\214\345\234\250\345\217\221\351\200\201\346\225\260\346\215\256\347\232\204\346\227\266\345\200\231\346\263\250\346\204\217\344\275\216\344\275\215\345\255\227\350\212\202\345\234\250\345\211\215\357\274\214\351\253\230\344\275\215\345\255\227\350\212\202\345\234\250\345\220\216\343\200\202</p>\n"
"<p style=\" margin-top:3px; margin-bottom:3px; margin-left:0px; margin"
                        "-right:0px; -qt-block-indent:0; text-indent:0px;\">\350\214\203\344\276\213\357\274\232</p>\n"
"<p style=\" margin-top:3px; margin-bottom:3px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ff0000;\">\346\216\245\346\224\266\345\270\247</span>\357\274\232 <span style=\" font-weight:600; color:#000000;\">AA 88 58 07 00 00 00 00 00 00 00 00 00 00 E7 2F</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\350\247\243\351\207\212\357\274\232 58 07 00 00 \346\230\257\345\217\202\346\225\2601\357\274\214\344\271\237\346\230\257\346\233\262\347\272\2771\347\232\204\346\225\260\346\215\256\357\274\214\346\230\257\346\225\264\345\236\213\346\225\260\346\215\256\357\274\214\346\225\260\345\200\274\346\230\2571880\343\200\202 \345\217\202\346\225\2602\343\200\201\345\217\202\346\225\2603\346\230\257\346\233\262\347\272\2772\343\200\201\346\233\262\347\272\2773\347\232\204\346\225\260\346\215"
                        "\256\343\200\202</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ff0000;\">\345\217\221\351\200\201\345\270\2471</span>\357\274\232<span style=\" font-weight:600; color:#000000;\">AA 07 3F C0 00 00 40 13 33 33 00 00 00 00 BF 2F</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\350\247\243\351\207\212\357\274\232 07\344\273\243\350\241\250\350\277\231\345\270\247\346\225\260\346\215\256\346\230\257\345\217\221\351\200\201PID\345\217\202\346\225\260\357\274\214\345\217\202\346\225\2601\345\260\261\346\230\257\346\257\224\344\276\213\347\263\273\346\225\260P,\345\217\202\346\225\2602\345\260\261\346\230\257\347\247\257\345\210\206\347\263\273\346\225\260I\357\274\214\345"
                        "\217\202\346\225\2603\345\260\261\346\230\257\345\276\256\345\210\206\347\263\273\346\225\260D,\345\217\202\346\225\2601\346\225\260\345\200\274\346\230\257\357\274\2103F C0 00 00)\357\274\214\346\230\257\346\265\256\347\202\271\345\236\213\346\225\260\346\215\256\357\274\214\346\225\260\345\200\274\346\230\2571.5f\357\274\214BF\345\260\261\346\230\257\345\211\21513\344\270\252\345\255\227\347\254\246\347\232\204\347\264\257\345\212\240\345\222\214\343\200\202</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ff0000;\">\345\217\221\351\200\201\345\270\2472</span>\357\274\232<span style=\" font-weight:600; color:#000000;\">AA 08 E8 03 00 00 55 55 55 55 55 55 55 55 9B 2F</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin"
                        "-right:0px; -qt-block-indent:0; text-indent:0px;\">\350\247\243\351\207\212\357\274\232 08\344\273\243\350\241\250\350\277\231\345\270\247\346\225\260\346\215\256\346\230\257\345\217\221\351\200\201\347\233\256\346\240\207\345\200\274\357\274\214\345\217\202\346\225\2601\345\260\261\346\230\257\347\233\256\346\240\207\345\200\274\357\274\214\345\217\202\346\225\2602\343\200\2013\346\262\241\346\234\211\346\204\217\344\271\211\357\274\214\344\275\277\347\224\25055\345\241\253\345\205\205\343\200\202\345\217\202\346\225\2601\346\225\260\345\200\274\346\230\257\357\274\210E8 03 00 00 )\357\274\214\346\230\257\346\225\264\345\236\213\346\225\260\346\215\256\357\274\214\346\225\260\345\200\274\346\230\2571000\357\274\2149B\345\260\261\346\230\257\345\211\21513\344\270\252\345\255\227\347\254\246\347\232\204\347\264\257\345\212\240\345\222\214\343\200\202</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p"
                        ">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ff0000;\">\345\217\221\351\200\201\345\270\2473</span>\357\274\232<span style=\" font-weight:600; color:#000000;\">AA 0A 0A 55 55 55 55 55 55 55 55 55 55 55 BB 2F</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\350\247\243\351\207\212\357\274\232 0A\344\273\243\350\241\250\350\277\231\345\270\247\346\225\260\346\215\256\346\230\257\345\220\257\345\212\250\347\224\265\346\234\272\357\274\214\345\217\202\346\225\2601\347\232\2040A\345\260\261\346\230\257\345\212\250\344\275\234\345\200\274\357\274\214\345\205\266\344\273\226\345\217\202\346\225\260\346\262\241\346\234\211\346\204\217\344\271\211\357\274\214\344\275\277\347\224\25055\345\241\253\345\205\205\343\200\202\345\217\202\346\225\2601\346\225\260\345\200\274\346\230\257\357\274\2100A 55 55 55 )\357\274\214\345\217\252\346"
                        "\234\2110A\346\211\215\346\234\211\346\204\217\344\271\211\357\274\214BB\345\260\261\346\230\257\345\211\21513\344\270\252\345\255\227\347\254\246\347\232\204\347\264\257\345\212\240\345\222\214\343\200\202</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ff0000;\">\345\217\221\351\200\201\345\270\2474</span>\357\274\232<span style=\" font-weight:600; color:#000000;\">AA 09 09 55 55 55 55 55 55 55 55 55 55 55 B9 2F</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\350\247\243\351\207\212\357\274\232 09\344\273\243\350\241\250\350\277\231\345\270\247\346\225\260\346\215\256\346\230\257\346\216\247\345\210\266\346\235\277\345\244\215\344\275\215\357\274\214\345\220\214"
                        "\345\217\221\351\200\201\345\270\2473\343\200\202</p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNTITLED_H
