/*********************************************************************
Author: Gabriel Hofer
Instructor: Dr. Rebenitsch
Course: CSC-372
Date: November 5, 2020
*********************************************************************/
#include <bits/stdc++.h>
#include <utility>
using namespace std;
typedef pair<double,double> pt;

#include "graham_pt.cpp"
#include "getPoints.cpp"
#include "debug.cpp"
#include "monotone.cpp"
#include "getArea.cpp"
#include "despeckle.cpp"
#include "test.cpp"


/*********************************************************************
Main
*********************************************************************/
int main(int argc, char ** argv){
  double A;
  double thresh=(double)atoi(argv[2])/100;
  char ch=argv[3][0];

  vector<pt> points=getPoints(argv);
  despeckle(points,thresh,ch);
  printStack(points);

}




