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
