#include <vector>
using namespace std;
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

