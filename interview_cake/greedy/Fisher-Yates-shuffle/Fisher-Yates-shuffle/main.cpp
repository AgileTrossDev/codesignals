//
//  main.cpp
//  Fisher-Yates-shuffle
//
//  Created by Scott Jackson on 3/13/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <random>
#include <vector>

using std::vector;
using std::cout;
using std::endl;


using namespace std;
void printVector(const char* title, const vector<int>& v);

// NAMED: Fisher-Yates shuffle algoirthm

size_t getRandom(size_t floor, size_t ceiling)
{
    static random_device rdev;
    static default_random_engine generator(rdev());
    static uniform_real_distribution<double> distribution(0.0, 1.0);
    double value = distribution(generator);
    return static_cast<size_t>(value * (ceiling - floor + 1)) + floor;
}

void shuffle(vector<int>& v)
{
    // if it's 1 or 0 items, just return
    if (v.size() <= 1) {
        return;
    }
    
    
    // shuffle the input in place
    for (size_t i = 0; i<v.size();i++ ){
        size_t x = getRandom(i, v.size()-1);
        
        int tmp = v[i];
        v[i] = v[x];
        v[x] = tmp;
        
    }
    
}

void printVector(const char* title, const vector<int>& v)
{
    cout << title << ": [";
    bool isFirst = true;
    for (int value: v) {
        if (isFirst) {
            isFirst = false;
        } else {
            cout << ", ";
        }
        cout << value;
    }
    cout << ']' << endl;
}

int main(int argc, char** argv)
{
    const vector<int> initial {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> shuffled(initial);
    shuffle(shuffled);
    printVector("initial vector", initial);
    printVector("shuffled vector", shuffled);
    return 0;
}


