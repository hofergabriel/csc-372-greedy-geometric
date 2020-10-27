#include <vector>
typedef pair<double,double> pt; using namespace std;

/*********************************************************************
Despeckle Images
*********************************************************************/
void despeckle(vector<pt> & points, const double thresh){ 
  vector<pt> tmp, hull;
  double a1, a2;
  bool ok=true;

  hull=monotone(points);
  a1=getArea(hull);

  while(points.size()>3 && ok){
    ok=false;
    for(int i=0;i<points.size();i++){
      tmp=points;
      tmp.erase(tmp.begin()+i);
      
      hull=monotone(tmp);
      a2=getArea(hull);


      if(1.0-(a2/a1)>=thresh){ 
        cout<<"percentage: "<<1.0-(a2/a1)<<endl;
        cout<<"thresh: "<<thresh<<endl;
        cout<<"a1: "<<a1<<endl;
        cout<<"a2: "<<a2<<endl;




        points=tmp;
        a1=a2;
        ok=true;
        break; 
      }
    }
  }
}


