#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class Euclidean{
public:
  Euclidean(char** array,int r);
  ~Euclidean();

  void findInitial();
  void findGoal();


  float euclidean(int x, int y);
  void simEuclidean();

  bool isOpen(char x);

  float manhattan(int x, int y);
  void makeCopy();

  void Print();
  string PrintFile();

private:
  char** theArray;
	char** newArray;
  int rows;
  int startX;
  int startY;
  int goalX;
  int goalY;
  float totalDist;
  int totalNodes;
  ofstream outFile;

};
