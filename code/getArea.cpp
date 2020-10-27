#include <vector>
using namespace std;
typedef pair<double,double> pt;
/*********************************************************************
https://cp-algorithms.com/geometry/area-of-simple-polygon.html
*********************************************************************/
double getArea(const vector<pt>& points) {
  double area=0;
  for (int i=0; i<points.size(); i++) {
    pt a = i ? points[i - 1] : points.back();
    pt b = points[i];
    area+= (a.first-b.first) * (a.second+b.second);
  }
  return fabs(area) / 2;
}

