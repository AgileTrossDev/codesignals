// You have a list of dishes. Each dish is associated with a list of ingredients
// used to prepare it. You want to group the dishes by ingredients, so that for
// each ingredient you'll be able to find all the dishes that contain it (if
// there are at least 2 such dishes).
// 
// Return an array where each element is a list with the first element equal to
// the name of the ingredient and all of the other elements equal to the names
// of dishes that contain this ingredient. The dishes inside each list should be
// sorted lexicographically. The result array should be sorted lexicographically
// by the names of the ingredients in its elements.
// 
// Example
// 
//     For
// 
//       dishes = [["Salad", "Tomato", "Cucumber", "Salad", "Sauce"],
//                 ["Pizza", "Tomato", "Sausage", "Sauce", "Dough"],
//                 ["Quesadilla", "Chicken", "Cheese", "Sauce"],
//                 ["Sandwich", "Salad", "Bread", "Tomato", "Cheese"]]
// 
//     the output should be
// 
//       groupingDishes(dishes) = [["Cheese", "Quesadilla", "Sandwich"],
//                                 ["Salad", "Salad", "Sandwich"],
//                                 ["Sauce", "Pizza", "Quesadilla", "Salad"],
//                                 ["Tomato", "Pizza", "Salad", "Sandwich"]]
// 
//     For
// 
//       dishes = [["Pasta", "Tomato Sauce", "Onions", "Garlic"],
//                 ["Chicken Curry", "Chicken", "Curry Sauce"],
//                 ["Fried Rice", "Rice", "Onions", "Nuts"],
//                 ["Salad", "Spinach", "Nuts"],
//                 ["Sandwich", "Cheese", "Bread"],
//                 ["Quesadilla", "Chicken", "Cheese"]]
// 
//     the output should be
// 
//       groupingDishes(dishes) = [["Cheese", "Quesadilla", "Sandwich"],
//                                 ["Chicken", "Chicken Curry", "Quesadilla"],
//                                 ["Nuts", "Fried Rice", "Salad"],
//                                 ["Onions", "Fried Rice", "Pasta"]]
// 
// Input/Output
// 
//     [time limit] 500ms (cpp)
// 
//     [input] array.array.string dishes
// 
//     An array of dishes. dishes[i] for each valid i contains information about
//     the ith dish: the first element of dishes[i] is the name of the dish and
//     the following elements are the ingredients of that dish. Both the dish
//     name and the ingredient names consist of English letters and spaces.
//     It is guaranteed that all dish names are different. It is also guaranteed
//     that ingredient names for one dish are also pairwise different.
// 
//     Guaranteed constraints:
//     1 ≤ dishes.length ≤ 500,
//     2 ≤ dishes[i].length ≤ 10,
//     1 ≤ dishes[i][j].length ≤ 50.
// 
//     [output] array.array.string
// 
//     The array containing the grouped dishes.


#include <iostream>
#include <vector>
#include <algorithm>

using std::string;
using std::cout;
using std::endl;

// ADTs Defs
typedef  std::vector<std::vector<std::string> >  hash_t;
typedef  std::vector<std::string>  string_vector_t;

typedef  std::vector<std::vector<std::string> >::iterator  hash_itr_t;
typedef  std::vector<std::string>::iterator  string_vector_iterator_t;

void disp(hash_t &start);


// Comparison Stuff...
//
// Compares the first string found in the vectors being compared
struct CompareStringVector {
      bool operator() (const string_vector_t & left,string_vector_t right) { return left[0] < right[0]; }
};




// Returns ture if 
struct FirstNodeMatches {
      std::string first_node ;
      FirstNodeMatches( std::string &input) : first_node(input) {};
      bool operator() ( std::vector<std::string> &input) { return first_node == input[0]; }
};

static bool LengthCheck (string_vector_t &i) {
      //cout << "Checking " << i[0] << endl;
      return (i.size()<=2);
}


void connect(hash_t & hash, string ing, string dish){
  if (ing == "") return;
    //cout << "connecting: "  << ing << " "<< dish << endl;
  // Find ingredient record in hash
  hash_itr_t ing_itr = find_if( hash.begin(), hash.end(), FirstNodeMatches(ing));
   
   if (ing_itr == hash.end() ) {
      //cout << "New ingrediant: " << ing <<endl;
      
     // Ingredient is not part of hash, so create new a record
     string_vector_t new_ing;
     new_ing.push_back(ing);
     new_ing.push_back(dish);
     
     ing_itr = std::lower_bound(hash.begin(), hash.end(), new_ing, CompareStringVector());
     hash.insert(ing_itr,new_ing);

     
     

     
     // Add dish to record
     
     // Insert record into correct location in hash
     
  
   } else {
      
      // Found, so find location from 1..N in record to push dish into record      
      string_vector_iterator_t dish_itr = std::lower_bound (((*ing_itr).begin()+1), (*ing_itr).end(), dish);
      (*ing_itr).insert(dish_itr,dish);
  }


} 

std::vector<std::vector<std::string> > groupingDishes(std::vector<std::vector<std::string> > dishes) {

    
    
  // Hash of ingredients pointing to dishes
  std::vector<std::vector<std::string> > ret_hash;
  
  // Iterator over dishes
  for (hash_itr_t itr = dishes.begin();itr!=dishes.end();++itr){

    // Get the Dish name from the first element in record
    string_vector_iterator_t ing = (*itr).begin();
    string dish = ing[0];

    ing++;

    // Iterator over ingrediants
    for (;ing !=(*itr).end();++ing) {
      // match ingrediant and dish in return hash
      connect(ret_hash,(*ing),dish);
    } // ingrediant loop
  } // Dishes loop
  
  

  ret_hash.erase (std::remove_if (ret_hash.begin(), ret_hash.end(), LengthCheck),ret_hash.end());

  
  
  // Return the hash of ingredients pointing to dishes
  return ret_hash;
}


//------------------------------------------------------------------------------
// Helpers
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Helpers
//------------------------------------------------------------------------------

// This is very rudimentary, but it's a point to start.
template<typename T>
class array2d_ref {
  public:
    array2d_ref(T *p, std::size_t dim) : data_(p), dim_(dim) { }

    T *operator[](std::size_t i) { return &data_[i * dim_]; }

  private:
    T *data_;
    std::size_t dim_;
};

void init(string a[][5] ,int _x, int _y ,hash_t &input) {
      
      // MAGIC!!!!!
      //string (*a)[_y]  = (string(*)[_y]) _a;
      //array2d_ref<string> a(_a, _y);
      
      for(int x=0;x<_x;++x){
        string_vector_t sv;
        for(int y=0;y<_y;++y){
            sv.push_back(a[x][y]);
        }        
        input.push_back(sv);
      }
}


void disp(hash_t &start) {
  for (hash_itr_t o = start.begin();o!=start.end();++o){      
      for (string_vector_iterator_t i = (*o).begin();i!=(*o).end();++i){
            cout << (*i) << " ";
      }
       cout << endl;
  }
  //cout << endl;
  
}


int main(void) {
      
      {
       
         cout << "Test Case 1 Starting... " << endl;   
            string dishes[][5] = {{"Salad","Tomato","Cucumber","Salad","Sauce"}, 
                        {"Pizza","Tomato","Sausage","Sauce","Dough"}, 
                        {"Quesadilla","Chicken","Cheese","Sauce"}, 
                        {"Sandwich","Salad","Bread","Tomato","Cheese"}}; 
            
          hash_t input;
 

          init(dishes,4,5,input);
          
            disp(input);
            
          hash_t output=  groupingDishes(input);
          
          cout << "Test Case 1 Result:\n " << endl;
          disp(output);
          
          cout << "---\nDone" << endl;
      }
  

}
