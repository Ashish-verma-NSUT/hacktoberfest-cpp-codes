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
