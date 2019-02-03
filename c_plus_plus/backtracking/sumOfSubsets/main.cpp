typedef std::vector<std::vector<int>> result_t;
typedef std::vector<int> iv_t;




void solve (iv_t &arr, int i, int n, result_t &r, iv_t &t, int s_sum) {
    
    
    while (i< arr.size() && arr[i]<=n) {
        if (s_sum + arr[i] > n)  return;
        t.push_back(arr[i]);
        s_sum += arr[i];
        
       
        if (s_sum == n) {
            r.push_back(t);
        } else {
            solve (arr, i+1, n,  r, t ,s_sum);
        }
        
        s_sum = s_sum-arr[i];
        t.pop_back();
        while(arr[i]== arr[i+1]) i++;
        i++;
        
        
    }
    
    
    
    
    
    
}


std::vector<std::vector<int>> sumSubsets(std::vector<int> arr, int num) {
    result_t r;
    iv_t t;
    solve (arr, 0, num,  r, t ,0);
    if (r.empty()) r = {{}};
    return r;

}

