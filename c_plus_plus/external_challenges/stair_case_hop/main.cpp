/*
Dynamic Programming approach to solving this problem.

You can make 1,2, or 3 hops at a time, with a goal of getting to N.

N can be reached from N-1, N-2,N-3

So theoritically we can solve for N by repeating the process until the basecase.

Let's establish the basecase as 0 as 1 hop.

So we repeatedly solve until 0.   A negative case is out of bounds and isn't included.
 
Anything N larger than 1 hop, we add  N-3 + N-2 + N-1.

So bottom-up
0 -> 1
1 -> 1
2 -> 2
3 -> 4
4 -> 7
5 -> 13


So this bottom-up chart is indicating that this might be a good canditate,
for a memo due to the nature of the fact that we are constantly solving
for the same value.  In fact, I was essentially memo-ing the result.  This 
chart above actually spells out what the memo should look like, the keys
will be sequential.  So instead of using a map, we can just create an array
to optimize.



*/

#include <iostream>
using std::cout;
using std::endl;

int hop (int n) {
  if (n <0) 
    return 0;
  else if (n ==0)
    return 1;
  else
    return hop(n-1) + hop(n-2) + hop(n-3);

} 

int hop_memo(int n, int memo[]) { 
  cout << "N: " << n << endl;
  if (n<0)  {
    return 0;
  } else if (n== 0 ) { 
    return 1;
  } else if (memo[n] > -1) {
   cout << "PRE CALC " << n << " : " << memo[n] << endl;
   return memo[n];
  } else {
     memo[n] = hop_memo(n-1, memo) + hop_memo(n-2,memo) + hop_memo(n-3,memo);
     cout << "NEW CALC: " << n << " "  << memo[n] << endl;
     return memo[n];
  }
   

}


int main(void) {
  cout << "RESULT: " << hop(5) << endl;
  
  int n =5;
  int * memo = new int[n+1];
  memset(memo,-1,(n+1)*sizeof(int));
  cout << memo[0] << " " << memo[1] << " " << memo[3] << endl;  

  cout << "RESULT: |" << hop_memo(n,memo) << "|" << endl;
  delete [] memo;
}


