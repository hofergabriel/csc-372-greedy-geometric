
/*********************************************************************
Sort points by polar angle
*********************************************************************/
void polarSort(vector<pair<int,int>> &v){
  sort(v.begin(),v.end()); // find v[0]
  set<pair<double,pair<int,int>>> s;
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
vector<pair<int,int>> graham(vector<pair<int,int>> &points){
  vector<pair<int,int>> stack;
  polarSort(points);
  for(int i=0;i<points.size();i++){
    while(stack.size()>1 && ccw(stack[stack.size()-2], stack.back(), points[i]) <= 0)
      stack.pop_back();
    stack.push_back(points[i]);
  }
  return stack;
}

