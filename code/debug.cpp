#include <iostream>
#include <vector>
using namespace std;
typedef pair<double,double> pt;
/*********************************************************************
Print Stack
*********************************************************************/
void printStack(vector<pt> &s){
  cout<<"********************************************************"<<endl;
  for(int i=0;i<s.size();i++) cout<<"\t"<<s[i].first<<' '<<s[i].second<<endl;
  cout<<endl;
}

