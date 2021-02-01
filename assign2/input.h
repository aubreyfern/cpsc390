#include <iostream>
#include <string>
using namespace std;
class Input
{
public:
	Input();
    void makeMap();
	~Input();
	void ReadFile();
	char** GenerateMapFromFile();
	void Print();
	int getRow();

private:
	string fileName;
	int rows;
	int columns;
	char** theArray;
};
