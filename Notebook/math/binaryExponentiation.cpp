int POW(int a, int b, int m){
  if(b == 0)
    return 1;
  if((b & 1) == 0)
    return POW((a % m * a % m) % m, b >> 1, m);
  return (POW((a % m * a % m) % m,b >> 1, m) * a % m) % m;
}
ll POW1(int a, int b, int m){
  ll ans = 1;
  while(b){
    if(b & 1)
      ans = (ans % m * a % m) % m;
    b >>= 1;
    a = (a % m * a % m) % m;
  }
  return ans;
}
