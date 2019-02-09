int climbingStairs(int n) {
    // Bottom-up Approach
    //f(n) = f(n-1) + f(n-2)
    //f(1) = 1
    //f(2) = 2
    //(f3) = f(1) + f(2) = 3 
    //(f4) = (f3) + (f2) = 5
 
    int x = 0, y = 1,total = 0,index =1;
    while(index <= n) { 
        index++;
        total = (x)+(y);
        x = y;
        y= total;
    }
    return total;
  
}


int climbingStairs_bottom_up (int n) {
    // Bottom-up Approach
    //f(n) = f(n-1) + f(n-2)
    //f(1) = 1
    //f(2) = 2
    //(f3) = f(1) + f(2) = 3 
    //(f4) = (f3) + (f2) = 5
 
    int x = 0, y = 1,total = 0,index =1;
    while(index <= n) { 
        index++;
        total = (x)+(y);
        x = y;
        y= total;
    }
    return total;
  
}

int do_it(int n, std::vector<int> &tracking) {
  // Recursion termination
  if (n<3) return ((  n==1) ? 1 : 2 ); 

  // Step already calculated, no need to go further
  if (tracking[n] != 0) return tracking[n];

  // Calculate new step
  tracking[n] = do_it(n-1, tracking) + do_it(n-2,tracking);     
    
  // Return new calculation
  return tracking[n];
   
}

int climbingStairs(int n) {
    // Top Down Approach
    std::vector<int> tracking(n+1,0);
    int total = do_it(n,tracking);
    
   
    
    
    return total;
}
