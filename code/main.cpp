/*********************************************************************
Author: Gabriel Hofer
Instructor: Dr. Rebenitsch
Course: CSC-372
Date: October 22, 2020
*********************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*********************************************************************
the code below uses a function ccw: 
  ccw > 0 if three points make a counter-clockwise turn, 
  clockwise if ccw < 0, and collinear if ccw = 0.
*********************************************************************/
vector<pair<int,int>> getPoints(char ** argv){
  int rows, cols, p;
  string p1;
  vector<pair<int,int>> points;
  ifstream fin;
  fin.open(argv[1]);
  fin>>p1>>cols>>rows;
  for(int i=0;i<rows;i++)
    for(int j=0;j<cols;j++){
      fin>>p;
      if(p) points.push_back({i,j});
    }
  return points;
}

/*********************************************************************
https://www.geeksforgeeks.org/orientation-3-ordered-points/

To find orientation of ordered triplet (p1, p2, p3). 
The function returns following values 
=0 --> p, q and r are colinear 
>0 --> Clockwise 
<0 --> Counterclockwise 
*********************************************************************/
int ccw(pair<int,int> a, pair<int,int> b, pair<int,int> c) { 
  return (b.second - a.second) * (c.first - b.first) - 
    (b.first - a.first) * (c.second - b.second); 
}

/*********************************************************************
Print Stack
*********************************************************************/
void printStack(vector<pair<int,int>> &s){
  for(int i=0;i<s.size();i++)
    cout<<"\t"<<s[i].first<<' '<<s[i].second<<endl;
  cout<<endl;
}

/*********************************************************************
Graham's Scan
*********************************************************************/
vector<pair<int,int>> graham(vector<pair<int,int>> &points){
  vector<pair<int,int>> stack;
  for(int i=0;i<points.size();i++){
    while(stack.size()>1 && ccw(stack[stack.size()-2], stack.back(), points[i]) <= 0)
      stack.pop_back();
    stack.push_back(points[i]);
    printStack(stack);
  }
  return stack;
}

/*********************************************************************
Sort points by polar angle
*********************************************************************/
void polarSort(vector<pair<int,int>> &v){
  sort(v.begin(),v.end()); // find v[0]
  set<pair<float,pair<int,int>>> s;
  for(int i=1;i<v.size();i++) s.insert({atan2(v[i].second-v[0].second,v[i].first-v[0].first),v[i]});
  s.insert({-100,v[0]});
  v.clear();
  for(auto e:s) v.push_back(e.second);
  reverse(v.begin()+1,v.end());
}


/*********************************************************************
Main
*********************************************************************/
int main(int argc, char ** argv){

  int threshold=atoi(argv[2]);
  vector<pair<int,int>> points=getPoints(argv);

  polarSort(points);
  printStack(points);

  vector<pair<int,int>> cvhull = graham(points);
  cout<<"cvhull size: "<<cvhull.size()<<endl;
  printStack(cvhull);
}









