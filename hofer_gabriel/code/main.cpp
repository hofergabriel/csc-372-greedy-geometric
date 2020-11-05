/*********************************************************************
Author: Gabriel Hofer
Instructor: Dr. Rebenitsch
Course: CSC-372
Date: November 5, 2020
*********************************************************************/
#include <vector>
#include <utility>
#include <iostream>
#include <set>
#include <cmath>
#include <algorithm>
#include <fstream>
using namespace std;
typedef pair<double, double> pt;

void despeckle(vector<pt>& pts, const double thresh);
void printStack(vector<pt>& s);
double cp(const pt a, const pt b, const pt c);
vector<pt> monotone(vector<pt>& pts);
vector<pt> readPoints(char** argv);
double getArea(const vector<pt>& points);

/*********************************************************************
Main
*********************************************************************/
int main(int argc, char ** argv){
  double thresh=(double)atoi(argv[2])/100;
  vector<pt> points=readPoints(argv);
  despeckle(points,thresh);
}

/*********************************************************************
Remove speckles from images
@param pts - points 
@param thresh - threshold
@description - Uses two sets of points pts and tmp. We initially enter 
the while loop if there are at least 3 points. Then we try to remove
each point from the original set of points pts, and see which point
decreases the area the most. This point which is located at myRemove.begin()
is removed from the set. This process is repeated until no point can 
be removed in a way that exceeds the threshold.
*********************************************************************/
void despeckle(vector<pt>& pts, const double thresh) {
    vector<pt> tmp, hull;
    set<pair<double, int>> mayRemove;               // pair<area of hull, index to remove in set>
    double a1, a2;
    pair<bool, bool> ok = { true,false };           
    hull = monotone(pts);                           // initialize hull
    a1 = getArea(hull);                             // initialize area
    while (pts.size() > 3 && ok.first) {
        ok.first = false;                           // break while loop if no point is found
        for (int i = 0; i < (int)pts.size(); i++) {
            tmp = pts;                              // reset tmp to the original set
            tmp.erase(tmp.begin() + i);             // erase ith point
            hull = monotone(tmp);                   // get convex hull
            a2 = getArea(hull);                     // get area of hull
            if (1.0 - (a2 / a1) >= thresh)
                mayRemove.insert({ a2,i });
            a1 = a2;                                // reset area 
        }
        if (mayRemove.size()) {                     // if we found a point beyond threshold
            cout << "Delete pixel at (" << pts[mayRemove.begin()->second].first
                << ", " << pts[mayRemove.begin()->second].second << ")" << endl;
            pts.erase(pts.begin() + mayRemove.begin()->second); // erase the point
            ok = { true,true };
            mayRemove.clear();                      // reset remove set
        }
    }
    if (!ok.second) cout << "No pixels deleted." << endl;
}

/*********************************************************************
Print Stack (Debugging)
*********************************************************************/
void printStack(vector<pt>& s) {
    cout << "********************************************************" << endl;
    for (int i = 0; i < (int)s.size(); i++) 
        cout << "\t" << s[i].first << ' ' << s[i].second << endl;
    cout << endl;
}

/*********************************************************************
Cross Product
*********************************************************************/
double cp(const pt a, const pt b, const pt c) {
    return (b.first - a.first) * (c.second - a.second) -
        (b.second - a.second) * (c.first - a.first);
}

/*********************************************************************
Monotone Chain convex Hull Algorithm
@param pts - list of all of the points
@description - U is the upper hull. L is the lower hull. 
*********************************************************************/
vector<pt> monotone(vector<pt>& pts) {
    if (pts.size() <= 3) return pts;
    vector<pt> L, U;
    sort(pts.begin(), pts.end());
    for (int i = 0; i < (int)pts.size(); i++) {
        while (L.size() >= 2 && cp(L[L.size() - 2], L.back(), pts[i]) <= 0)
            L.pop_back();
        L.push_back(pts[i]);
    }
    for (int i = pts.size() - 1; i >= 0; i--) {
        while (U.size() >= 2 && cp(U[U.size() - 2], U.back(), pts[i]) <= 0)
            U.pop_back();
        U.push_back(pts[i]);
    }
    L.pop_back(); U.pop_back();
    L.insert(L.end(), U.begin(), U.end());
    return L;
}

/*********************************************************************
Reads PBM image file
*********************************************************************/
vector<pt> readPoints(char** argv) {
    int rows, cols, p;
    string p1;
    vector<pt> points;
    ifstream fin;
    fin.open(argv[1]);
    fin >> p1 >> cols >> rows;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            fin >> p;
            if (p) points.push_back({ i,j });
        }
    return points;
    fin.close();
}

/*********************************************************************
Calculate area enclosed in a convex hull of points
*********************************************************************/
double getArea(const vector<pt>& points) {
    double area = 0;
    for (int i = 0; i < (int)points.size(); i++) {
        pt a = i ? points[i - 1] : points.back();
        pt b = points[i];
        area += (a.first - b.first) * (a.second + b.second);
    }
    return fabs(area) / 2;
}

