//
// Given an array of words and a length l, format the text such that each line has exactly l characters and
// is fully justified on both the left and the right. Words should be packed in a greedy approach; that is,
// pack as many words as possible in each line. Add extra spaces when necessary so that each line has exactly
// l characters.
// 
// Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line
// does not divide evenly between words, the empty slots on the left will be assigned more spaces than the
// slots on the right. For the last line of text and lines with one word only, the words should be left
// justified with no extra space inserted between them.
// 
// Example
// 
// For
// words = ["This", "is", "an", "example", "of", "text", "justification."]
// and l = 16, the output should be
// 
// textJustification(words, l) = ["This    is    an",
//                                "example  of text",
//                                "justification.  "]
 


#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

typedef std::vector<string> input_t;


void init_vector_of_strings(string arr[], int size, input_t &v) {
    v.clear();
    for (int i=0; i<size;i++)
        v.push_back(arr[i]);
    
}

void disp (input_t &v) {
    for (input_t::iterator itr = v.begin();itr!=v.end();++itr)
        cout << "|" << (*itr) << "|" << endl;
    
    cout << endl;
}





std::vector<std::string> textJustification(std::vector<std::string> words, int l) {

    // Return value
    std::vector<std::string>  result;
    
    // Two iterators traversing at the same time. front_itr is looking
    // for the end of the next line.  The back_itr is marking the start
    // of the new line
    std::vector<std::string>::iterator front_itr= words.begin();
    std::vector<std::string>::iterator back_itr= words.begin();
    
    // Loop until all words are formatted into lines.
    while (back_itr != words.end()) {
        
        // Add first word to the line here.  No need for spaces yet.
        int new_line_counter = (*front_itr).size();
        front_itr++;
        
        // Increment front_itr until we find the end of the line. Words are separated by a space,
        // so for every word we add, we also add a space to the line count.  The last word should
        // not have a trailing space. 
        while ((front_itr != words.end() && (new_line_counter + (*front_itr).size()+1)<=l)) {
            new_line_counter = new_line_counter +(*front_itr).size() +1;
            front_itr++;
        }
        
        // At this point we know the words in the next line and the unadjusted
        // size of the line with single spaces. Calculate the total number of
        // spaces we need to fill out the line.
        int num_of_words = std::distance(back_itr,front_itr);
        
        std::string tmp = "";
        if (front_itr == words.end()) {
            // Last line special formating, words only have 1 space and filler at end
            
            // Add first word
            tmp =  (*back_itr);
            back_itr++;
            
            // Add additional words with single spacing
             while (front_itr != back_itr){ 
                tmp = tmp+ " " +  (*back_itr);
                back_itr++;
             }
             
            // Fill remaining line
            std::string base_space_string ((l-tmp.size()),' ');
            tmp = tmp + base_space_string;
             
        } else if (num_of_words>1){
          
            int spaces = (l -new_line_counter)/(num_of_words-1) +1;  // Last word doesn't have spaces, but we account for min space counted above
            int greedy_spaces = (l -new_line_counter)%(num_of_words-1);
            std::string base_space_string (spaces,' ');
            
            cout << "S: " << spaces << " G:" << greedy_spaces << " |" << base_space_string << "|" << endl; 
        
            // Build a tmp string containing all the words in this set, plus
            // the necessary spaces to justify the line.    
            
            while (front_itr != back_itr){ 
                tmp = tmp+ (*back_itr);
                
                 // Step back_itr foward
                back_itr++;
                num_of_words--;
                
                if (num_of_words > 0){  
                    tmp = tmp + base_space_string;
                    if (greedy_spaces>0) {
                        tmp = tmp + " ";
                        greedy_spaces--;
                    }
                }
               
                
             }
         } else{
            tmp = (*back_itr);
            std::string base_space_string ((l-tmp.size()),' ');
            tmp = tmp + base_space_string;
            back_itr++;
         }
         
         // Stash the result, clear the tmp string for next round
        result.push_back(tmp);
        tmp.empty();
        
    }
    
    return result;
}



int main (void ){
    
    {
        
        string array[] = {"This", "is", "an", "example", "of", "text", "justification."};
        std::vector<std::string> input;
        init_vector_of_strings(array,7,input);
        disp(input);
        std::vector<std::string>  result = textJustification(input,16);
        disp(result);
        
    }
    
    
    
       {
        
        string array[] = {"a", "b", "c", "longword"};
        std::vector<std::string> input;
        init_vector_of_strings(array,4,input);
        disp(input);
        std::vector<std::string>  result = textJustification(input,9);
        disp(result);
        
    }
}