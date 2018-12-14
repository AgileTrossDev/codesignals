//You have a collection of coins, and you know the values of the coins and the quantity of each type of coin in it. You want to know how many distinct sums you can make from non-empty groupings of these coins.
//
//Example
//
//For coins = [10, 50, 100] and quantity = [1, 2, 1], the output should be
//possibleSums(coins, quantity) = 9.
//
//Here are all the possible sums:
//
//50 = 50;
//10 + 50 = 60;
//50 + 100 = 150;
//10 + 50 + 100 = 160;
//50 + 50 = 100;
//10 + 50 + 50 = 110;
//50 + 50 + 100 = 200;
//10 + 50 + 50 + 100 = 210;
//10 = 10;
//100 = 100;
//10 + 100 = 110.
//As you can see, there are 9 distinct sums that can be created from non-empty groupings of your coins.
//
//Input/Output
//
//[time limit] 500ms (cpp)
//[input] array.integer coins
//
//An array containing the values of the coins in your collection.
//
//Guaranteed constraints:
//1 ≤ coins.length ≤ 20,
//1 ≤ coins[i] ≤ 104.
//
//[input] array.integer quantity
//
//An array containing the quantity of each type of coin in your collection. quantity[i] indicates the number of coins that have a value of coins[i].
//
//Guaranteed constraints:
//quantity.length = coins.length,
//1 ≤ quantity[i] ≤ 105.
//
//It is guaranteed that (quantity[0] + 1) * (quantity[1] + 1) * ... * (quantity[quantity.length - 1] + 1) <= 106.
//
//[output] integer
//
//The number of different possible sums that can be created from non-empty groupings of your coins.
//
//[C++] Syntax Tips
//
//// Prints help message to the console
//// Returns a string
//std::string helloWorld(std::string name) {
//    std::cout << "This prints to the console when you Run Tests" << std::endl;
//    return "Hello, " + name;
//}


// Returns next value in queue and inserts back into the queue
int rotate_queue(std::queue<int> &work){
    int val=  work.front();
    work.pop();
    work.push(val);
    
    return val;
    
}
// Returns the result of a Set Insert
bool insert_sum(std::set<int> &sums, int sum) {
    bool ret_val = ((sums.insert(sum)).second);
    //cout << "INSERT: " << ret_val << endl;
    return ret_val;
}


int possibleSums(std::vector<int> coins, std::vector<int> quantity) {
    // BFS-like dynamic solution
    
   // Track unique sums 
    std::set<int> sums;
    
    // Track the work to calculate the sums
    std::queue<int> work;
    work.push(0); // Prime Queue with Zero Value
    
    int c = 0;  // Coin Index
    
    
    // Loop over all coins to process possible sums
    while (c < coins.size()){
        
        int nodes_to_be_worked = work.size();
        
        for (int i=0;i<nodes_to_be_worked;++i){
            // Get value to process
            int starting_sum = rotate_queue(work);
            
            // Calculate all possible new sums based
            // on the value being processed.  BFS
            // checking all possible node movements
            // with the coin indexed 
            for (int j=0;j<=quantity[c];++j){
                int sum = starting_sum + coins[c]*(j);
                //cout << "NEW SUM: " << sum << " " << sums.size() << endl;
                
                // IF sum is new to the set, then add it to the work queue
                // for future processing
                if (insert_sum(sums,sum)) { work.push(sum); }
            }
        }
        // Move to next Coin
        c++;
    }

    
  sums.erase(0);        // Zero is an invalid value
  return sums.size();   // Return the Queue
}
