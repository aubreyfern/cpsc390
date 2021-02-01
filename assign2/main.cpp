#include<iostream>
#include <fstream>
#include "input.h"
//#include "Game.h"
#include "Euclidean.h"
#include "Manhattan.h"
#include "GH.h"

using namespace std;
int main()
{
	cout<<"Welcome to Robot Navigation"<<endl;
	Input i;
	i.makeMap();

	//gather data from input for search classes
	int rows = i.getRow();
	char** myArray= i.GenerateMapFromFile();

	//clear file
	ofstream outfile;
	outfile.open("output.out", ios::trunc);
	outfile.close();

	//search algorithmns
	Euclidean e(myArray,rows);
	Manhattan m(myArray,rows);
	GH gh(myArray,rows);

}
