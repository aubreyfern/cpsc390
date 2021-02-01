#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <math.h>
#include "GH.h"

using namespace std;


//constructor that finds i first
GH::GH(char** array, int r){
  theArray=array;
  rows=r;
  findInitial();
  findGoal();
  makeCopy();
  simGH();
  Print();
  outFile.open("output.out",ios_base::app);
  outFile<<PrintFile();
  outFile.close();
}


GH::~GH(){
}

//find initial i in grid
void GH::findInitial(){
   startX=0;
   startY=0;
    for(int i=0; i<rows; ++i){
      for (int j=0; j<rows;++j){
        if(theArray[i][j]=='i'){
          startX=i;
          startY=j;

      }
    }
  }
  //  cout<<"Start x:"<<startX<<endl<<"Start Y:"<<startY<<endl;
}

//find goal g in grid
void GH::findGoal(){
  goalX=0;
  goalY=0;
  for(int i=0; i<rows; ++i){
    for (int j=0; j<rows;++j){
      if(theArray[i][j]=='g'){
        goalX=i;
        goalY=j;
    }
  }
}
//  cout<<"Goal x:"<<goalX<<endl<<"Goal Y:"<<goalY<<endl;
}

//make a copy of grid to output path later
void GH::makeCopy()
{
	newArray = new char*[rows];
	for(int i=0; i<rows;++i)
	{
		newArray[i]= new char[rows];
	}

	for(int i=0; i<rows; ++i)
	{
		for(int j=0;j<rows;++j)
		{
      newArray[i][j]=theArray[i][j];
		}
	}
}

//euclidean formula
float GH::euclidean(int x, int y){
  int curr_x = x;
  int curr_y = y;
  float dist = sqrt(pow((x-goalX),2)+(pow((y-goalY),2)));
//  cout<<dist<<endl;
return dist;
}


//manhattan formula
float GH::manhattan(int x, int y){
  int curr_x = x;
  int curr_y = y;
  float dist  = abs(x-goalX) + abs(y-goalY);
}


//simulation finding path
void GH::simGH(){
  bool found= false;
  int  x=startX;
  int y=startY;
  int newX=0;
  int newY=0;
  float smallestDist=0;
  totalDist=0;
  totalNodes=0;
  bool set=false;
  //loop until g is found
  while(found==false)
  {
    smallestDist=0;
    set=false;

  //left posiition
  //if position exists on board
  if(y-1>=0)
  {
    //check if neighbor is traversable
    if(isOpen(theArray[x][y-1])){
      float leftdist = euclidean(x,y-1)+manhattan(x,y-1);
      //if shortest distance has not been found intialized yet since resetting
      //then set smallest dist to this distance
      if(!set)
      {
        smallestDist = leftdist;
        newX=x;
        newY=y-1;
        set = true;
      }

      //if smallest distance has been set, is this position less than it
      //keep track of where smallest dist is located too
      else if(smallestDist>leftdist)
      {
        smallestDist = leftdist;
        newX=x;
        newY=y-1;
      }

    }
  }

  //up position
  if(x-1>=0)
  {
    if(isOpen(theArray[x-1][y])){
    float updist = euclidean(x-1,y)+manhattan(x-1,y);
    if(!set)
    {
      smallestDist= updist;
      newX=x-1;
      newY=y;
      set = true;
    }
    else if(updist<smallestDist)
    {
      smallestDist= updist;
      newX=x-1;
      newY=y;
    }
  }

  }

  //down posiition
  if(x+1<=rows)
  {
    if(isOpen(theArray[x+1][y])){
      float down_dist = euclidean(x+1,y)+manhattan(x+1,y);
      if(!set)
      {
        smallestDist = down_dist;
        newX=x+1;
        newY=y;
        set = true;
      }
      else if (down_dist<smallestDist)
      {
        smallestDist = down_dist;
        newX=x+1;
        newY=y;
      }
    }
  }

  //right position
  if(y+1<=rows)
  {
    if(isOpen(theArray[x][y+1])){
      float rt_dist= euclidean(x,y+1)+manhattan(x,y+1);
      if(!set)
      {
        smallestDist = rt_dist;
        newX=x;
        newY=y+1;
        set = true;
      }
      else if (rt_dist<smallestDist)
      {
        smallestDist = rt_dist;
        newX=x;
        newY=y+1;
      }

    }
  }

    //set x and y to position with smallest distance
    x = newX;
    y = newY;
    totalDist+=smallestDist;
    totalNodes++;

    //if find smallest distance location is equal to the position of goal
    if(x==goalX&&y==goalY)
    {
      found=true;
    }
    else{
      newArray[x][y]='o';
    }
      }
      cout<<"GH DISTANCE:"<<endl;
      cout<<"Total Distance:"<<totalDist<<endl<<"Total Nodes:"<<totalNodes<<endl;
    }

//check if neighbor is traverable
bool GH::isOpen(char position){
  if(position=='.'){
    return true;
  }
  else if(position=='g'){
    return true;
  }
  else{
    return false;
  }
}

//print to terminal
void GH::Print()
{
	for(int p = 0; p < rows; ++p)
	{
		for(int m=0; m<rows; ++m)
		{
			cout<<newArray[p][m];
		}
		cout<<endl;
	}
  cout<<endl;
}


//print to file
string GH::PrintFile()
{
	stringstream write;
  write<<"GH DISTANCE"<<endl;
  write<<"Total Distance:"<<totalDist<<endl<<"Total Nodes:"<<totalNodes<<endl;
	for(int p = 0; p < rows; ++p)
	{
		for(int m = 0; m< rows; ++m)
		{
			write<<newArray[p][m];
		}
		write<<endl;
	}
  write<<endl;
	return write.str();
}
