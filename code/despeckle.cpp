#include <vector>
#include "graham_pt.cpp"
typedef pair<double,double> pt; 
using namespace std;

/*********************************************************************
Despeckle Images 
*********************************************************************/
void despeckle(vector<pt> & pts, const double thresh, const char option){ 
  vector<pt> tmp, hull;
  set<pair<double,int>> mayRemove;
  double a1, a2;
  pair<bool,bool> ok={true,false};

  switch(option){
    case 'g': hull=graham(pts);
    default: hull=monotone(pts);
  }
  a1=getArea(hull);

  while(pts.size()>3 && ok.first){
    ok.first=false;
    for(int i=0;i<pts.size();i++){
      tmp=pts;
      tmp.erase(tmp.begin()+i);
      
      switch(option){
        case 'g': hull=graham(pts);
        default: hull=monotone(pts);
      }
      a2=getArea(hull);

      if(1.0-(a2/a1)>=thresh)
        mayRemove.insert({a2,i});

      tmp=pts;
      a1=a2;
    }
    if(mayRemove.size()){
      cout<<"Delete pixel at ("<<pts[mayRemove.begin()->second].first
          <<", "<<pts[mayRemove.begin()->second].second<<")"<<endl;
      pts.erase(pts.begin()+mayRemove.begin()->second);
      ok={true,true};
      mayRemove.clear();
    }
  }
  if(!ok.second) cout<<"No pixels deleted."<<endl;
}


