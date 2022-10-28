void buildtree(int s, int e, int idx, vector<int> &arr, vector<int> &tree){
  if(s == e){
    tree[idx] = arr[s];
    return;
  }
  int mid = (s + e)/2;
  buildtree(s, mid, 2*idx, arr, tree);
  buildtree(mid + 1, e, 2*idx + 1, arr, tree);
  tree[idx] = min(tree[2*idx] , tree[2*idx + 1]);
  return;
}
 
int query(int ss, int se, int qs ,int qe,int idx, vector<int> &tree){
  if(ss >= qs && se <= qe){
    return tree[idx];
  }
 
  if(se < qs || qe < ss){
    return INT_MAX;
  }
 
  int mid = (ss + se) /2;
  int la = query(ss, mid , qs, qe, 2*idx, tree);
  int ra = query(mid + 1, se, qs, qe, 2*idx + 1, tree);
  return min(la, ra);
}
 
void update(int ss, int se, int i, int idx,int increment, vector<int> &tree){
  if(i < ss || i > se) return;
  if(ss == se){
    tree[idx] += increment;
    return;
  }
  int mid = (ss + se) /2;
  update(ss, mid, i, 2*idx,increment, tree);
  update(mid + 1, se, i , 2*idx + 1, increment, tree);
  tree[idx] = min(tree[2*idx], tree[2*idx + 1]);
  return; 
}
