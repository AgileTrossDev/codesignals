std::vector<int> largestValuesInTreeRows(Tree<int> * t) {
  
  std::vector<int> ret_val;
  
  std::queue<Tree<int> * > work_q;
  work_q.push(t);
  int current =1,children=0,max=-1001;
  
  while (!work_q.empty()){
    
      // Increment the counters
      current--;
      
      // Get Next Node to process
      Tree<int> * index = work_q.front();
      work_q.pop();
    cout << index->value << " | " << current  <<    " | " <<endl;
      if (nullptr == index) continue;
      
      // Update max if necessary
      max = (max<index->value ? index->value : max);
      
      // Add Children to the work load
      if (nullptr != index->left) {
        work_q.push(index->left);
        children++;
      }

      if (nullptr != index->right) {
        work_q.push(index->right);
        children++;
      }
      
      // Level Complete
      if (current <=0) {
       ret_val.push_back(max);
       current = children;
       children =0;
       max=-1001;
      }
      
      
  } // loop
  
  return ret_val;

}
