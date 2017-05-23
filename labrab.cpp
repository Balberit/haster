// labrab.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include <math.h>
#include <iostream>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	ofstream myfile;
	//      myfile.open("C:\User\gener\Documents\LAB254187\example.txt");
	myfile.open("");
	//myfile << "Writing this to a file.\n";
	while (1)
	{
		if (myfile.end)
			break;
		
	}
	double* corx;
	double* cory;
	int n;
	corx = new double[n + 1];
	cory = new double[n + 1]; 
	double xa; double LG = 0;
	double* F;
	F = new double[n];
	for (int i = 0; i <= n; i++)
	{
		F[i] = 1;
		for (int j = 0; j <= n; j++)
		{
			F[i] = F[i] * (xa - corx[j]) / (corx[i] - corx[j]);
		}
	}
	for (int k = 0; k <= n + 1; k++)
	{
		LG = LG + F[k] * cory[k];
	}
	myfile.close();
	return 0;
}

