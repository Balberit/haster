#include <QCoreApplication>
#include <fstream>
#include <math.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
      ofstream myfile;
//      myfile.open("C:\User\gener\Documents\LAB254187\example.txt");
      myfile.open ("example.txt");
      myfile << "Writing this to a file.\n";
      myfile.close();
    return 0;
}

