#include<iostream>
#include<stack>

using std::cout;
using std::endl;
using std::stack;
using std::string;

typedef stack<char> tracker_t;


int get_left_word(tracker_t &word, string &input, int read_l){
  while(read_l < input.length() && input[read_l] !=' ') {
        word.push(input[read_l]);
        read_l++;
  }
  return ++read_l; // Points to start of next word past space
}


int get_right_word(tracker_t &word, string &input, int read_r) {
  while(read_r >= 0 && input[read_r] != ' ') {
    word.push(input[read_r]);
    read_r--;
  }
  return --read_r; // Points to start of next word past space
}


int right_write(tracker_t &word, string &input, int write_r) {
    if (write_r != input.length()-1) input[write_r--] = ' ';

    while (!word.empty()){
      input[write_r--] = word.top();
      word.pop();
    }
    return write_r;

}

int left_write(tracker_t &word, string &input, int write_l){
   if (write_l !=0) input[write_l++] = ' ';
 
   while (!word.empty()){
         input[write_l++] = word.top();
         word.pop();
   }
   return write_l;

}


void reverse(string &input){

  int read_l =0;
  int read_r =(int)input.length()-1;
  int write_l = read_l;
  int write_r = read_r;

  tracker_t left_word;
  tracker_t right_word;

   while(write_l< write_r){
       if (left_word.empty() && read_l < read_r) read_l = get_left_word(left_word,input,read_l);
       if (read_l > read_r) break;
       
       if (right_word.empty() && read_l < read_r) read_r = get_right_word(right_word,input,read_r);
    
       int read_right = (int)input.length()-1 - read_r;
       if (read_l < read_right)
             write_r = right_write(left_word,input,write_r);
       else
             write_l = left_write(right_word,input,write_l);
//      cout << input << " " << read_l << " " << read_right << " " << read_r << " " << left_word.empty() << " " << right_word.empty() <<  endl;

   }
    
   if (!left_word.empty()) write_r = right_write(left_word,input,write_r);
   if (!right_word.empty())  write_l = left_write(right_word,input,write_l);
   if (write_r >= 0) input[write_r] = ' ';
}


void test(string input) {
    cout << "BEFORE: |" << input << "|"  << endl;
    reverse(input);
    cout << "AFTER: |" << input <<"|" <<  endl;
}

int main(void) {
    test("SCOTT BOB JOE SAM JILL");
    test("SCOTT BOB SAM JILL");
    test("vault");
    test("two words");
    test("three words");
    test("multiple words same length");
    test("multiple words different lengths");
    test("empty string");
    //test("")
    //test("")
   


  
   


}


