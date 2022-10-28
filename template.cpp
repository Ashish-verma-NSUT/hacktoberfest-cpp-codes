#include<bits/stdc++.h>
using namespace std;
 
//<------------------------------FOR USING PBDS------------------------------->
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
using namespace __gnu_pbds;
 
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
//ordered_multiset<int> s;
 
//Declaring ordered_set
typedef tree<int, null_type, less<int>, rb_tree_tag,
      tree_order_statistics_node_update>
  ordered_set;
 
ordered_set s;
 
//<-------------------------------PBDS ENDS HERE----------------------------->
 
 
//#pragma GCC optimize "trapv"
#define loop(i,j,k,in)              for(int i=j; i<k; i+=in)
#define rloop(i,j,k,in)             for(int i=j; i>=k; i-=in)
#define mem(a,b)                    memset(a, b, sizeof(a))
#define mod                         1000000007
#define pub                         push_back
#define pob                         pop_back
#define endl                        "\n"
#define w(t)                        int t; cin >> t; while(t--)
 
typedef pair<int,int>               pii;
typedef vector<int>                 vi;
typedef vector<char>                vc;
typedef vector<string>              vs;
typedef vector<pii>                 vii;
typedef map<int,int>                mii;
typedef set<int>                    si;
typedef long long int               ll;
typedef unsigned long long int      ull;
 
 
//---------------------SEGMENT TREE IMPLEMENTATION(RANGE MIN QUERY)---------------------->
 
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
 
//----------------------------SEGMENT TREE ENDS HERE-------------------------------
 
 
 
 
 
//--------------------------------CALCULATE POWER HERE------------------------
int fastpow(int a, int b, int m)
{
  long long res = 1;
  while (b)
  {
    if (b & 1)
      res = res * a;
    res %= m;
    a = (1ll * a * a) % m;
    b = b >> 1;
  }
  return res;
}
 
 
//------------------CALCULATE MODULO INVERSE USING FERMET'S LITTLE THEOREM-----
int inverse(int a, int m){
  return fastpow(a, m-2, m);
}
 
 
//-----------------DISJOINT SET UNION-------------------------------------
class DSU
{
public:
  vector<int> parent;
  vector<int> rank;
  int cc;
  DSU(int n)
  {
    parent.resize(n);
    rank.resize(n);
    cc = n;
    for (int i = 0; i < n; i++)
    {
      parent[i] = i;
      rank[i] = 1;
    }
  }
  int get(int x)
  {
    return parent[x] = parent[x] == x ? x : get(parent[x]);
  }
  void merge(int l, int r)
  {
    l = get(l);
    r = get(r);
    if (l == r)
      return;
    if (rank[l] == rank[r])
      rank[l]++;
    if (rank[l] > rank[r])
      parent[r] = l;
    else
      parent[l] = r;
    cc--;
    return;
  }
};

class point{
public:
	int x, y;
};

int dot(point &p, point &q, point &r){
	int x1= q.x - p.x;
	int y1 = q.y - p.y;
	int x2 = r.x - q.x;
	int y2 = r.y - q.y;
	return x1 * x2 + y1 * y2;
}

int cross(point &p, point &q, point &r){
	int x1= q.x - p.x;
	int y1 = q.y - p.y;
	int x2 = r.x - q.x;
	int y2 = r.y - q.y;
	return x1 * y2 - y1 * x2;
}




 
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // #ifndef ONLINE_JUDGE
	 //  freopen("input.txt","r",stdin);
	 //  freopen("output.txt","w",stdout);
  // #endif
  
  w(t){
  	
  }
  
  

  return 0;
}
