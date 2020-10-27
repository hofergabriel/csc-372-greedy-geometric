/*********************************************************************
Author: Gabriel Hofer
Instructor: Dr. Rebenitsch
Course: CSC-372
Date: October 22, 2020

TODO: 
  1. Put polarSort function body in getPoints. 
  2. write correctness isConvexHull testing function

*********************************************************************/
#include <bits/stdc++.h>

#include "rosetta_code_graham_correctness.cpp"
#include "cp_algorithms_graham_correctness.cpp"

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
  cout<<"********************************************************"<<endl;
  for(int i=0;i<s.size();i++) cout<<"\t"<<s[i].first<<' '<<s[i].second<<endl;
  cout<<endl;
}

/*********************************************************************
Sort points by polar angle
*********************************************************************/
void polarSort(vector<pair<int,int>> &v){
  sort(v.begin(),v.end()); // find v[0]
  set<pair<double,pair<int,int>>> s;
  for(int i=1;i<v.size();i++) 
    s.insert({atan2(v[i].second-v[0].second,v[i].first-v[0].first),v[i]});
  s.insert({-100,v[0]}); 
  v.clear();
  for(auto e:s) v.push_back(e.second);
  reverse(v.begin()+1,v.end()); 
}

/*********************************************************************
Graham's Scan
*********************************************************************/
vector<pair<int,int>> graham(vector<pair<int,int>> &points){
  vector<pair<int,int>> stack;
  polarSort(points);
  for(int i=0;i<points.size();i++){
    while(stack.size()>1 && ccw(stack[stack.size()-2], stack.back(), points[i]) <= 0)
      stack.pop_back();
    stack.push_back(points[i]);
  }
  return stack;
}

/*********************************************************************
https://cp-algorithms.com/geometry/area-of-simple-polygon.html
*********************************************************************/
double getArea(const vector<pair<int,int>>& points) {
  double area=0;
  for (int i=0; i<points.size(); i++) {
    pair<int,int> a = i ? points[i - 1] : points.back();
    pair<int,int> b = points[i];
    area+= (a.first-b.first) * (a.second+b.second);
  }
  return fabs(area) / 2;
}

/*********************************************************************
Despeckle Images
*********************************************************************/
void despeckle(vector<pair<int,int>> & points, const double thresh){ }

/*********************************************************************
Despeckle Images
*********************************************************************/
bool isConvexHull(vector<pair<int,pair<int,int>>> &v){ 

}




/*********************************************************************
Main
*********************************************************************/
int main(int argc, char ** argv){

  double thresh=atoi(argv[2])/100;
  vector<pair<int,int>> points=getPoints(argv);

  vector<pair<int,int>> cvhull = graham(points);
  double A = getArea(cvhull);
  cout<<"Area: "<<A<<endl;

  despeckle(points,thresh);
}



