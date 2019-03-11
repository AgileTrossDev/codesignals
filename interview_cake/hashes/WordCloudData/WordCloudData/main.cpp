//
//  main.cpp
//  WordCloudData
//
//  Created by Scott Jackson on 3/11/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <unordered_map>

using std::unordered_map;
using std::string;
using std::cout;
using std::endl;


typedef unordered_map<string, size_t> result_t;

class WordCloudData
{
private:
    unordered_map<string, size_t> wordsToCounts_;
    
    
    int process_word(const string& inputString, int word_start, int word_length ) {
        
        if (word_length==0) return word_start;
        
        string cur = inputString.substr(word_start, word_length);
        
        if (cur[0] < 'a' ) {
            // First letter is upper case
            cur[0] = tolower(cur[0]);
            if (wordsToCounts_.end() == wordsToCounts_.find(cur)) {
                // No lower case version, so add it as an upper case
                cur[0] = toupper(cur[0]);
                if (wordsToCounts_.end() == wordsToCounts_.find(cur)) {
                    wordsToCounts_[cur] = 1;
                } else {
                    wordsToCounts_[cur] = wordsToCounts_[cur] +1;
                }
            } else {
                // lower case exists, so update total
                wordsToCounts_[cur] = wordsToCounts_[cur] +1;
                string lc = cur;
                
                // And then correct
                cur[0] = toupper(cur[0]);
                wordsToCounts_[lc] = wordsToCounts_[lc] + wordsToCounts_[cur];
                wordsToCounts_.erase(cur);
            }
            
        }  else {
            cur[0] = toupper(cur[0]);
            if (wordsToCounts_.end() == wordsToCounts_.find(cur)) {
                // No upper case version, so add to lower case cnt
                cur[0] = tolower(cur[0]);
                if (wordsToCounts_.end() == wordsToCounts_.find(cur)) {
                    wordsToCounts_[cur] = 1;
                } else {
                    wordsToCounts_[cur] = wordsToCounts_[cur] +1;
                }
            } else {
                // upper case exists, so correct
                string uc = cur;
                cur[0] = tolower(cur[0]);
                wordsToCounts_[cur] = wordsToCounts_[cur] + 1 +  wordsToCounts_[uc];
                wordsToCounts_.erase(uc);
            }
        }
        
        // Reset  index/counters for next word.  Accoubnt for spaces and
        // punctuation
        word_start = word_start + word_length + 1;
        while (!isalpha(inputString[word_start]))  word_start++;
        return word_start;
        
    }
    
    void populateWordsToCounts(const string& inputString)
    {
        // count the frequency of each word
        int word_start =0;
        int word_length = 0;
        
        for (int i = 0; i< inputString.length(); i++) {
            if (isalpha(inputString[i])) {
                word_length++;
            } else if (inputString[i] == '\'')  {
                word_length++;
            } else if (inputString[i] == '-' && isalpha(inputString[i-1]) && isalpha(inputString[i+1]))  {
                word_length++;
            } else { // End of a word marked by space or punctuation
                word_start = process_word(inputString, word_start, word_length);
                word_length = 0;
            }
        }
        process_word(inputString, word_start, word_length);
    }
    
public:
    WordCloudData (const string& inputString)
    {
        populateWordsToCounts(inputString);
    }
    
    const unordered_map<string, size_t> getWordsToCounts() const
    {
        return wordsToCounts_;
    }
};




void disp_cloud(WordCloudData& data) {
    cout << "WORD CLOUD: " << endl;
    result_t res = data.getWordsToCounts();
    
    for (result_t::iterator itr = res.begin(); itr!=res.end(); itr++) {
        
        cout << itr->first << ": " << itr->second << endl;
    }
    
    cout << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    WordCloudData tc2 ("Strawberry short cake? Yum!");
    disp_cloud(tc2);
    
    
    WordCloudData tc6 ("Allie's Bakery: Sasha's Cakes");
    disp_cloud(tc6);
    
    WordCloudData tc5 ("Mmm...mmm...decisions...decisions");
    disp_cloud(tc5);
    
    return 0;
}
