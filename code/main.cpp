/*********************************************************************
Author: Gabriel Hofer
Instructor: Dr. Rebenitsch
Course: CSC-372
Date: October 22, 2020

TODO: 
  despeckle
  write test functions

*********************************************************************/
#include <bits/stdc++.h>
#include "getPoints.cpp"
#include "debug.cpp"
#include "monotone.cpp"
#include "getArea.cpp"
#include "despeckle.cpp"
#include "test.cpp"

//#include "graham_pt.cpp"
/*
#include "rosetta_code_graham_correctness.cpp"
#include "cp_algorithms_graham_correctness.cpp"
*/

using namespace std;

/*********************************************************************
Main
*********************************************************************/
int main(int argc, char ** argv){
  double A, thresh=(double)atoi(argv[2])/100;

  vector<pt> points=getPoints(argv);
  despeckle(points,thresh,'m');
  printStack(points);

  // test();
}






