bool is_prime(int n) {
  for(int i = 2; i <= n / 2; ++i)
    if(n % i == 0) return false;
  return true;
}


int greatestCommonPrimeDivisor(int a, int b) {
    int r =-1;
    int i = 2;
    while (i<min(a,b)/2) {
        if (is_prime(i) && a%i==0 && b%i==0) r=i;
        i++;
    }
            
    return r;
}

