/*********************************************************************
Author: Gabriel Hofer
https://algorithmist.com/wiki/Monotone_chain_convex_hull
*********************************************************************/

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
vector<pt> monotone(vector<pt> &pts){
  if(pts.size()<=3) return pts;
  vector<pt> L, U;
  sort(pts.begin(),pts.end());
  for(int i=0;i<pts.size();i++){
    while(L.size()>=2 && cp(L[L.size()-2], L.back(), pts[i]) <= 0)
      L.pop_back();
    L.push_back(pts[i]);
  }
  for(int i=pts.size()-1;i>=0;i--){
    while(U.size()>=2 && cp(U[U.size()-2], U.back(), pts[i]) <= 0)
      U.pop_back();
    U.push_back(pts[i]);
  }
  L.pop_back(); U.pop_back();
  L.insert(L.end(),U.begin(),U.end());
  return L;
}


