/*********************************************************************
Author: Gabriel Hofer
Instructor: Dr. Rebenitsch
Course: CSC-372
Date: November 5, 2020

TODO: 
  write test functions

*********************************************************************/
#include <bits/stdc++.h>
#include <utility>
using namespace std;

#include "graham_pt.cpp"
#include "getPoints.cpp"
#include "debug.cpp"
#include "monotone.cpp"
#include "getArea.cpp"
#include "despeckle.cpp"
#include "test.cpp"

/*
#include "rosetta_code_graham_correctness.cpp"
#include "cp_algorithms_graham_correctness.cpp"
*/

typedef pair<double,double> pt;

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




