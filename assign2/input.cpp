#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <ctype.h>
#include "input.h"
using namespace std;


Input::Input()
{
	Input::ReadFile();
}


Input::~Input()
{

}


//Reads in amount of rows
void Input::ReadFile()
{
	string line;
	int countLines=0;
	cout<<"Enter in File Name:"<<endl;
	cin>>fileName;
	cout<<endl;

	ifstream infile(fileName.c_str());
	if((infile.is_open())&&(infile.good()))
	{
		while(getline(infile,line))
		{
			countLines++;
			if(countLines==1)
			{
				rows = atoi(line.c_str());
			//	cout<<"row:"<<rows<<endl;
			}
		}
	}
	else{
		cout<<"File doesn't exist"<<endl;
	}
	makeMap();
	infile.close();
}

//make grrid
void Input::makeMap()
{
	theArray = new char*[rows];
	for(int i=0; i<rows;++i)
	{
		theArray[i]= new char[rows];
	}

	for(int i=0; i<rows; ++i)
	{
		for(int j=0;j<rows;++j)
		{
			theArray[i][j]='-';
		}
	}
}

//read in file and make array from it
 char** Input::GenerateMapFromFile()
{
	int countLines=0;
	string line;
	ifstream infile(fileName.c_str());
	if((infile.is_open())&&(infile.good()))
	{
		while(getline(infile,line))
		{
			countLines++;

				for(int i=0; i<rows; ++i){
					if(countLines>1){
						for (int j=0; j<rows; ++j){
							theArray[countLines-2][j]=line[j];
						}
					}

				}
		}
	}

	infile.close();
	//Print();
	return theArray;
}

void Input::Print()
{
	for(int p = 0; p < rows; ++p)
	{
		for(int m=0; m<rows; ++m)
		{
			cout<<theArray[p][m];
		}
		cout<<"\n";
	}
}


int Input::getRow()
{
	return rows;
}
