/*********************************************************************
Author: Gabriel Hofer
Instructor: Dr. Rebenitsch
Course: CSC-372
Date: October 22, 2020

*********************************************************************/
#include <bits/stdc++.h>
#include "getPoints.cpp"
#include "debug.cpp"
#include "monotone.cpp"
#include "getArea.cpp"
/*

#include "rosetta_code_graham_correctness.cpp"
#include "cp_algorithms_graham_correctness.cpp"
*/
using namespace std;
typedef pair<double,double> pt;

/*********************************************************************
Main
*********************************************************************/
int main(int argc, char ** argv){
  double A, thresh=atoi(argv[2])/100;
  vector<pt> points=getPoints(argv);
  printStack(points);
  vector<pt> hull=monotone(points);
  printStack(hull);
  A = getArea(hull);
  cout<<"Area: "<<A<<endl;

  //despeckle(points,thresh);
}



