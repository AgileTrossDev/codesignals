//
//  main.cpp
//  duplicate_files
//
//  Created by Scott Jackson on 3/12/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>

class FilePaths
{
public:
    string duplicatePath_;
    string originalPath_;
    
    FilePaths(const string& duplicatePath, const string& originalPath) :
    duplicatePath_(duplicatePath),
    originalPath_(originalPath)
    {
    }
    
    string toString() const
    {
        ostringstream str;
        str  << "(original: " << filePaths.originalPath_
        << ", duplicate: " << filePaths.duplicatePath_ << ")";
        return str.str();
    }
};




int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
