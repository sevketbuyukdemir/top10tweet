#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include "top10Tweet.h"
using namespace std;

int main()
{
	int control;
	do
	{
		string file_name, file_format;
		cout << "Enter file name: ";
		cin >> file_name;
		cout << "Enter file format: ";
		cin >> file_format;
		top10Tweet tp;
		tp.project(file_name, file_format);
		cout << "Press 0 to exit." << endl;
		cin >> control;
	} while (control != 0);
	return 0;
}