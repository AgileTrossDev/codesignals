int numberOf1Bits(int n) {
  int res = 0;
  while (n != 0) {
    int tmp = n&1;
    n= n >>1;
    if (!tmp) continue;
    res++;
  }
  return res;
}

