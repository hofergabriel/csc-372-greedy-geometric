/*********************************************************************
Author: Gabriel Hofer
Instructor: Dr. Rebenitsch
Course: CSC-372
Date: October 22, 2020
*********************************************************************/

#include <bits/stdc++.h>
using namespace std;


vector<pair<int,int>> getPoints(char ** argv){
  int rows, cols;
  ifstream fin;
  fin.open(argv[1]);

  cout<<"one"<<endl;
  string p1;
  fin>>p1;
  cout<<"type: "<<p1<<endl;

  fin>>cols>>rows;
  cout<<"cols, rows"<<endl;
  cout<<cols<<" "<<rows<<endl;

  int p;
  vector<pair<int,int>> points;
  for(int i=0;i<rows;i++)
    for(int j=0;j<cols;j++){
      fin>>p;
      if(p) points.push_back({i,j});
    }
  return points;
}


int main(int argc, char ** argv){

  int threshold=atoi(argv[2]);
  vector<pair<int,int>> points=getPoints(argv);
  for(int i=0;i<points.size();i++){
    cout<<points[i].first<<' '<<points[i].second<<endl;
  }
  cout<<endl;
  


  return 0;
}









