// A cryptarithm is a mathematical puzzle for which the goal is to find the correspondence
// between letters and digits, such that the given arithmetic equation consisting of letters
// holds true when the letters are converted to digits.
// 
// You have an array of strings crypt, the cryptarithm, and an an array containing the mapping
// of letters and digits, solution. The array crypt will contain three non-empty strings that
// follow the structure: [word1, word2, word3], which should be interpreted as the
// word1 + word2 = word3 cryptarithm.
// 
// If crypt, when it is decoded by replacing all of the letters in the cryptarithm with digits
// using the mapping in solution, becomes a valid arithmetic equation containing no numbers with
// leading zeroes, the answer is true. If it does not become a valid arithmetic solution, the
// answer is false.
// 
// Example
// 
// For crypt = ["SEND", "MORE", "MONEY"] and
// 
// solution = [['O', '0'],
//             ['M', '1'],
//             ['Y', '2'],
//             ['E', '5'],
//             ['N', '6'],
//             ['D', '7'],
//             ['R', '8'],
//             ['S', '9']]
// the output should be
// isCryptSolution(crypt, solution) = true.
// 
// When you decrypt "SEND", "MORE", and "MONEY" using the mapping given in crypt, you get
// 9567 + 1085 = 10652 which is correct and a valid arithmetic equation.
// 
// For crypt = ["TEN", "TWO", "ONE"] and
// 
// solution = [['O', '1'],
//             ['T', '0'],
//             ['W', '9'],
//             ['E', '5'],
//             ['N', '4']]
// the output should be
// isCryptSolution(crypt, solution) = false.
// 
// Even though 054 + 091 = 145, 054 and 091 both contain leading zeroes, meaning that this is not a valid solution.
// 
// Input/Output
// 
// [time limit] 500ms (cpp)
// [input] array.string crypt
// 
// An array of three non-empty strings containing only uppercase English letters.
// 
// Guaranteed constraints:
// crypt.length = 3,
// 1 ≤ crypt[i].length ≤ 14.
// 
// [input] array.array.char solution
// 
// An array consisting of pairs of characters that represent the correspondence between
// letters and numbers in the cryptarithm. The first character in the pair is an uppercase English
// letter, and the second one is a digit in the range from 0 to 9.
// 
// Guaranteed constraints:
// solution[i].length = 2,
// 'A' ≤ solution[i][0] ≤ 'Z',
// '0' ≤ solution[i][1] ≤ '9',
// solution[i][0] ≠ solution[j][0], i ≠ j,
// solution[i][1] ≠ solution[j][1], i ≠ j.
// 
// It is guaranteed that solution only contains entries for the letters present in crypt and that different letters have different values.
// 
// [output] boolean
// 
// Return true if the solution represents the correct solution to the cryptarithm crypt, otherwise return false.


#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>

using std::cout;
using std::endl;

typedef std::unordered_map<char,int> solution_map_t;

solution_map_t build_map(std::vector<std::vector<char> > &solution) {
    solution_map_t the_map;
    
    for (int i= 0;i<solution.size();++i){
        the_map.insert(std::make_pair (solution[i][0],(solution[i][1]-'0'))); 
    }
    
    return the_map;
}

bool check_for_leading_zeros(std::string s ,solution_map_t &map ){
   cout << s << " " << s[0] << " "<< map[(s[0])] << " " <<s.length() << " " << (s.length()==1 || map[(s[0])] != 0)<<  endl;
    return (s.length()==1 || map[(s[0])] != 0);
}

int convert(std::string s,solution_map_t &map){
    
    int place_mod = 1;
    int val = 0;
    for (int i = (s.size()-1); i>=0;--i ){
        val = val +(map[(s[i])] * place_mod);
        place_mod = place_mod*10;
    }
    return val;
    
}

bool valid(std::queue<int> & numbers) {
    int num1 = numbers.front();
    numbers.pop();
    
    int num2 = numbers.front();
    numbers.pop();
    
    int num3 = numbers.front();
    numbers.pop();

   // cout << "Checking: "<< num1 << "+" << num2 << "=" << num3 << endl;
    
    
    return ((num1+num2) == num3);
    
}


bool isCryptSolution(std::vector<std::string> crypt, std::vector<std::vector<char> > solution) {
    
    bool ret_val = false;
    solution_map_t sol_map = build_map(solution);
    
    std::queue<int>  numbers;
    for (int i=0;i<crypt.size();++i) {
        if (!check_for_leading_zeros(crypt[i],sol_map)) return false;
        numbers.push(convert(crypt[i],sol_map)) ;
    }
    return valid(numbers);
}

std::vector<std::string> build_string_array(std::string a[], int s =3) {
    std::vector<std::string> v;
    for(int i = 0; i<s;++i) {
        v.push_back(a[i]);
        
    }
    return v;
}


std::vector<std::vector<char> > build_solution_v(char a[][2],int size) {
    std::vector<std::vector<char> > v;
    
    for (int i=0;i<size;++i) {
         std::vector<char> tmp;
        for(int j=0;j<2;++j) {
            tmp.push_back(a[i][j]);
        }
        v.push_back(tmp);
        tmp.clear();
    }
            
    return v;
        
    
}


int main (void) {
    
    
     // TC Oa - Map check
    {
        
        std::string crypt_array[] = {"SEND", "MORE", "MONEY"};
        std::vector<std::string> crypt = build_string_array(crypt_array);
        
        char solution_array[][2] = {{'O', '0'},
            {'M', '1'},
            {'Y', '2'},
            {'E', '5'},
            {'N', '6'},
            {'D', '7'},
            {'R', '8'},
            {'S', '9'}};
            
        std::vector<std::vector<char> > solution = build_solution_v(solution_array,8);
        
        
        
    
        cout << "setup complete, starting..." << endl;
        solution_map_t map= build_map( solution) ;
        
        cout << map['O'] << endl;
        cout << map['E'] << endl;
        cout << check_for_leading_zeros("O", map) << endl;
        cout << check_for_leading_zeros("MYE", map) << endl;
        cout << check_for_leading_zeros("OMYE", map) << endl;
        cout << "VAL: " << convert("SEND",map) << endl;
        cout << "VAL: " << convert("MORE",map) << endl;
        cout << "VAL: " << convert("MONEY",map) << endl;
        
        
        
        cout << "TC Oa Result: "  << endl;

        
    
    } // TC 1
    
    // TC 1 - Nominal
    {
        
        std::string crypt_array[] = {"SEND", "MORE", "MONEY"};
        std::vector<std::string> crypt = build_string_array(crypt_array);
        
        
        char solution_array[][2] = {{'O', '0'},
            {'M', '1'},
            {'Y', '2'},
            {'E', '5'},
            {'N', '6'},
            {'D', '7'},
            {'R', '8'},
            {'S', '9'}};
            
        std::vector<std::vector<char> > solution = build_solution_v(solution_array,8);
    
        cout << "setup complete, starting..." << endl;
        bool res = isCryptSolution(crypt,solution);
        
        cout << "TC 1 Result: " << res << endl;

        
    
    } // TC 1
    
    // TC 2 - Zero case
    {
        
        std::string crypt_array[] = {"A", "A", "A"};
        std::vector<std::string> crypt = build_string_array(crypt_array);
        
        
        char solution_array[][2] = {{'A', '0'}};
            
        std::vector<std::vector<char> > solution = build_solution_v(solution_array,8);
    
        cout << "setup complete, starting..." << endl;
        bool res = isCryptSolution(crypt,solution);
        
        cout << "TC 2 Result: " << res << endl;

        
    
    } // TC 2
    
}