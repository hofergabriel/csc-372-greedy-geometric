#include <vector>
typedef pair<double,double> pt;

bool ccw(pt a, pt b, pt c) {
  return a.first*(b.second-c.second)+
    b.first*(c.second-a.second)+
    c.first*(a.second-b.second);
}

/*********************************************************************
Sort points by polar angle
*********************************************************************/
void polarSort(vector<pt> &v){
  sort(v.begin(),v.end()); // find v[0]
  set<pair<double,pt>> s;
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
vector<pt> graham(vector<pt> &points){
  vector<pt> stack;
  polarSort(points);
  for(int i=0;i<points.size();i++){
    while(stack.size()>1 && ccw(stack[stack.size()-2], stack.back(), points[i]) <= 0)
      stack.pop_back();
    stack.push_back(points[i]);
  }
  return stack;
}

