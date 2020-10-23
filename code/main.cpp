/*********************************************************************
Author: Gabriel Hofer
Instructor: Dr. Rebenitsch
Course: CSC-372
Date: October 22, 2020
*********************************************************************/

#include <bits/stdc++.h>
using namespace std;

 

/*********************************************************************
The code below uses a function ccw: 
  ccw > 0 if three points make a counter-clockwise turn, 
  clockwise if ccw < 0, and collinear if ccw = 0.
*********************************************************************/
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

/*********************************************************************
https://www.geeksforgeeks.org/orientation-3-ordered-points/

To find orientation of ordered triplet (p1, p2, p3). 
The function returns following values 
0 --> p, q and r are colinear 
1 --> Clockwise 
2 --> Counterclockwise 
*********************************************************************/
int orientation(pair<int,int> a, pair<int,int> b, pair<int,int> c) { 
  return (b.second - a.second) * (c.first - b.first) - 
    (b.first - a.first) * (c.second - b.second); 
}

/*********************************************************************
https://en.wikipedia.org/wiki/Graham_scan#Pseudocode

let points be the list of points
let stack = empty_stack()

find the lowest y-coordinate and leftmost point, called P0
sort points by polar angle with P0, if several points have the same polar angle then only keep the farthest

for point in points:
    # pop the last point from the stack if we turn clockwise to reach this point
    while count stack > 1 and ccw(next_to_top(stack), top(stack), point) <= 0:
        pop stack
    push point to stack
end




*********************************************************************/
vector<int> graham(vector<pair<int,int>> &points){
  vector<int> stack;
  sort(points.begin(),points.end());
  for(int i=0;i<points.size();i++){
    cout<<points[i].first<<' '<<points[i].second<<endl;
  }
  cout<<endl;
  return stack;
}



/*********************************************************************
Main
*********************************************************************/
int main(int argc, char ** argv){

  int threshold=atoi(argv[2]);
  vector<pair<int,int>> points=getPoints(argv);

  vector<int> sorted = graham(points);

/*
  for(int i=0;i<points.size();i++){
    cout<<points[i].first<<' '<<points[i].second<<endl;
  }
  cout<<endl;
*/
  return 0;
}









