#include <vector>
typedef pair<double,double> pt; using namespace std;

/*********************************************************************
Despeckle Images
*********************************************************************/
void despeckle(vector<pt> & points, const double thresh){ 
  vector<pt> tmp, h1, h2;
  double a1, a2;

  h1=monotone(points);
  a1=getArea(h1);

  while(){
    for(int i=0;i<points.size();i++){
      tmp=points;
      tmp.erase(tmp.begin()+i);
      
      h2=monotone(tmp);
      a2=getArea(h2);

      if(1-(a2/a1)>thresh){ 
        points=tmp;
        a1=a2;
        break; 
      }
    }
  }
}


