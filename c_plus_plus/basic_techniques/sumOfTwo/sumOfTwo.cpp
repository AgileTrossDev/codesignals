// Takes Two unsorted arrays and sees if the value V is the sum 
// of any pair of values in the vectors.  


bool sumOfTwo(std::vector<int> a, std::vector<int> b, int v) {
    
 unordered_set<int> look_up;
 
  for (int i=0;i<a.size();++i)
   look_up.insert(a[i]);
 
 
  for (int j=0;j<b.size();++j)
   if ( look_up.find((v-b[j])) != look_up.end() )
    return true;
  
  
 return false;
}
  
