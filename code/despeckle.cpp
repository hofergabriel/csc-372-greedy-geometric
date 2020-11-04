/*********************************************************************
Despeckle Images 
Author: Gabriel Hofer
*********************************************************************/
void despeckle(vector<pt> & pts, const double thresh, const char option){ 
  vector<pt> tmp, hull;
  set<pair<double,int>> mayRemove;
  double a1, a2;
  pair<bool,bool> ok={true,false};

  /*switch(option){
    case 'g': 
      hull=graham(pts);
      cout<<"1"<<endl;
    default: 
      hull=monotone(pts);
      cout<<"2"<<endl;
  }*/
  hull=monotone(pts);
  a1=getArea(hull);

  while(pts.size()>3 && ok.first){
    ok.first=false;
    for(int i=0;i<pts.size();i++){
      tmp=pts;
      tmp.erase(tmp.begin()+i);
      
      /*switch(option){
        case 'g': 
          hull=graham(pts);
          cout<<"3"<<endl;
        default: 
          hull=monotone(pts);
          cout<<"4"<<endl;
      }*/
      hull=monotone(tmp);
      a2=getArea(hull);

      //cout<<"1-a2/a1: "<<1.0-(a2/a1)<<endl;

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



