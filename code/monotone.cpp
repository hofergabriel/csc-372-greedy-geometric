#include <algorithm>
#include <vector>
using namespace std;
typedef pair<double,double> pt

/*********************************************************************
Compare Lexicographically
*********************************************************************/
bool cmp(pt a, pt b) {
    return a.first < b.first || (a.first == b.first && a.second < b.second);
}

/*********************************************************************
Cross Product
*********************************************************************/
int cp(const pt a, const pt b, const pt c){
  return (b.first - a.first) * (c.second - a.second) - 
    (b.second - a.second) * (c.first - a.first);
}

/*********************************************************************
Convex Hull
*********************************************************************/
vector<pt> convexHull(vector<pt> &pts){

  if(P.size()<=3) return P;
  vector<pt> L, U;

  sort(pts.begin(),pts.end(),cmp);

  for(int i=0;i<pts.size();i++){
    while(L.size()>=2 && cp(L[L.size()-2], L.back(), pts[i]))
      L.pop_back();
    L.push_back(pts[i]);
  }

  for(int i=0;i<pts.size();i++){
    while(U.size()>=2 && cp(U[U.size()-2], U.back(), pts[i]))
      U.pop_back();
    U.push_back(pts[i]);
  }

  L.pop(); U.pop();
  L.insert(L.end(),U.begin(),U.end());
  return L;
}












