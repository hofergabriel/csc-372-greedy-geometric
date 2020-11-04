/*********************************************************************
Author: Gabriel Hofer
Instructor: Dr. Rebenitsch
Course: CSC-372
Date: November 5, 2020
*********************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef pair<double,double> pt;

#include "getPoints.cpp"
#include "debug.cpp"
#include "monotone.cpp"
#include "getArea.cpp"
#include "despeckle.cpp"

/*********************************************************************
Main
*********************************************************************/
int main(int argc, char ** argv){
  double A;
  double thresh=(double)atoi(argv[2])/100;

  vector<pt> points=getPoints(argv);
  despeckle(points,thresh);
  printStack(points);
}





