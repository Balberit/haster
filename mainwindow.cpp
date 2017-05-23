#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextCodec>  // Обеспечивает использование кириллицы
#include <QFileDialog> // Обеспечивает работу с файлами
#include <QDebug> // для вывода отладочных сообщений
#include <QMessageBox> // для вывода сообщений программы
#include <fstream>
#include <conio.h>
#include <iostream>
#include <stdlib.h>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //  Выводим специальное окно для работы с файлами:
    QString name = QFileDialog::getOpenFileName(this, "Открыть", "data.txt", QString("Текстовые файлы(*.txt);;Все файлы(*)"));
        QFile file(name); // создаем объект для работы с файлами
        file.open(QIODevice::ReadOnly); // открываем файл
        QString str; // Одна строка файла
        QStringList list; // Список слов из строки


        while (!file.atEnd()) // пока файл не закончен
        {
           str = file.readLine(); // считываем строку
      //     qDebug() << str;
           strcount++; //количество строк
        }
        file.close();

         file.open(QIODevice::ReadOnly);
        QString* massX = new QString[strcount - 1];
        QString* massY = new QString[strcount - 1];
        QString* massdef = new QString[strcount];
        int count=0, i=0;

        while (!file.atEnd()) // пока файл не закончен
        {
           str = file.readLine(); // считываем строку

    // Делим строку на слова (слова могут отделяться друг от друга любыми пробельными символами) :
           list = str.split(QRegExp("\\s+"), QString::SkipEmptyParts);
           massdef[count] = str;
           count++;

           if (list.size() > 1)
           {
               massX[i] = list[0];
               massY[i] = list[1];
               i++;
           }
           else
           {
               vecX = list[0];
               nomerstroki = count;
           }

        }



        double MassX[strcount-1];
        double MassY[strcount-1];
        bool ok;
        double Z = 1;
        double VecX = vecX.toDouble(&ok);

        for (int i = 0; i < strcount - 1; i++)
        {
             MassX[i] = massX[i].toDouble(&ok);//(&ok, 10);
             MassY[i] = massY[i].toDouble(&ok);//(&ok, 10);

        }
        // основная функция программы
        for (int i = 0; i < strcount-1; i++)
        {
             for (int j = 0; j < strcount-1; j++)
             {
                 if (i != j)
                 {
                     double a = VecX - MassX[j];
                     double b = (MassX[i] - MassX[j]);
                     vecY = a / b ;
                     Z = Z * vecY;
                 }
             }
             Z = Z *MassY[i];
             VR =(VR + Z); // складываем функции
             Z = 1;
        }

        QString Vr;
        Vr.setNum(VR);

        QString tmp;
        tmp = tmp.append(vecX);
        tmp = tmp.append("\t");
        tmp = tmp.append(Vr);
        tmp = tmp.append("\r");
        tmp = tmp.append("\n");
        massdef[nomerstroki-1] = tmp;







       QString fileName = QFileDialog::getSaveFileName(this, "Сохранить файл", QString(), QString("Текстовые файлы (*.txt);;Все файлы (*.*)"));
       // используем окно для задания имени сохраняемого файла
           QFile rezFile; // Результирующий файл
           if (!fileName.isEmpty()) // Если имя файла задано
           {
               QString line; // строка из файла
               if (file.isOpen()) // если исходный файл открыт
               {
                   file.seek(0); // переходим в начало файла
                   rezFile.setFileName(fileName);
       // присваиваем физическое имя результирующему файлу
                   rezFile.open(QIODevice::WriteOnly|QIODevice::Text);
       // открываем сохраняемый файл
                   QTextStream out(&rezFile);
       /* создаем поток, связанный с файлом (запись файла обычно выполняется с помощью потока) */
                   for (int i = 0; i < strcount; ++i)
       // отсчитываем половину строк
                   {
                       line =  massdef[i];

       // считываем строку из исходного файла
                       out << line; // записываем в результирующий файл
                   }
                   rezFile.close(); // закрываем создаваемый файл

               }
           }








}


