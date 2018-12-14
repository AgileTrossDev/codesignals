// Sudoku is a number-placement puzzle. The objective is to fill a 9 × 9 grid with numbers in such a way that
// each column, each row, and each of the nine 3 × 3 sub-grids that compose the grid all contain all of the
// numbers from 1 to 9 one time.
// 
// Implement an algorithm that will check whether the given grid of numbers represents a valid Sudoku puzzle
// according to the layout rules described above. Note that the puzzle represented by grid does not have to be
// solvable.
// 
// Example
// 
// For
// 
// grid = [['.', '.', '.', '1', '4', '.', '.', '2', '.'],
//         ['.', '.', '6', '.', '.', '.', '.', '.', '.'],
//         ['.', '.', '.', '.', '.', '.', '.', '.', '.'],
//         ['.', '.', '1', '.', '.', '.', '.', '.', '.'],
//         ['.', '6', '7', '.', '.', '.', '.', '.', '9'],
//         ['.', '.', '.', '.', '.', '.', '8', '1', '.'],
//         ['.', '3', '.', '.', '.', '.', '.', '.', '6'],
//         ['.', '.', '.', '.', '.', '7', '.', '.', '.'],
//         ['.', '.', '.', '5', '.', '.', '.', '7', '.']]
// the output should be
// sudoku2(grid) = true;
// 
// For
// 
// grid = [['.', '.', '.', '.', '2', '.', '.', '9', '.'],
//         ['.', '.', '.', '.', '6', '.', '.', '.', '.'],
//         ['7', '1', '.', '.', '7', '5', '.', '.', '.'],
//         ['.', '7', '.', '.', '.', '.', '.', '.', '.'],
//         ['.', '.', '.', '.', '8', '3', '.', '.', '.'],
//         ['.', '.', '8', '.', '.', '7', '.', '6', '.'],
//         ['.', '.', '.', '.', '.', '2', '.', '.', '.'],
//         ['.', '1', '.', '2', '.', '.', '.', '.', '.'],
//         ['.', '2', '.', '.', '3', '.', '.', '.', '.']]
// the output should be
// sudoku2(grid) = false.
// 
// The given grid is not correct because there are two 1s in the second column. Each column, each row,
// and each 3 × 3 subgrid can only contain the numbers 1 through 9 one time.
// 
// Input/Output
// 
// [time limit] 500ms (cpp)
// [input] array.array.char grid
// 
// A 9 × 9 array of characters, in which each character is either a digit from '1' to '9' or a period '.'.
// 
// [output] boolean
//
//Return true if grid represents a valid Sudoku puzzle, otherwise return false.


#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::string;

bool check_counter (std::vector<std::vector<int> > &c,int x, int y) {
    if ((++c[x][y]) == 2) {
        cout << "Counter Check Fail " << x << " " << y << endl;
        
        return false;
    } else {
       // cout << c[x][y] << endl;
        
    }
    
    return true;
}


// Operation that validates a 3x3 sub_grid of the 9x9 Matrix
// The upper right corner is passed to this operation and the
// grid is travered until an error is found.  3 Types of errors
// can occur.  Grid, Row, or collumn.   This is when a value
// appears twice unde these conditions.  Row counters and
// Collumn counters are updated accors multiple grids, where
// the Grid counter is only applicable to a single grid.
bool sub_grid (std::vector<std::vector<char> > &grid, int x, int y, std::vector<std::vector<int> > &rc,  std::vector<std::vector<int> > &cc) {
   //cout << "Sub Grid: " << x << "," << y << endl;
   
    bool ret_val=true;
    std::vector<int> counter(9,0); 
  
    // Loop over the next 3 rows
    int end_line= x+3;
    for (;x<end_line;++x) {
        
        // Loop over the next 3 columns in this row.
        for (int i= y;i<(y+3);++i) {
            
            // Update Counters
            if (grid[x][i] == '.')  continue;  // No counter
            
            cout << "CHedking: " << x << "," << i << " "<<  grid[x][i] << endl;
            
            if ((++counter[(grid[x][i] -'1')]) == 2) {
                cout << "Grid Counter failure: " << counter[(grid[x][i]-1)] << " " << grid[x][i] << endl;
                return false;
            }
            if (!check_counter(rc,x,(grid[x][i] -'1'))) {
                cout << "Row Counter failure" << endl;
                return false;
            }
            if (!check_counter(cc,i,(grid[x][i] -'1'))) {
                cout << "Col Counter failure" << endl;
                return false;
            }
            
        }
    }
         
    return true;
}



bool sudoku2(std::vector<std::vector<char> > grid) {
    // cout << "working..." << endl;
    bool ret_val=true;
    
    std::vector<std::vector<int> > row_counter(9,std::vector<int>(9,0));
    std::vector<std::vector<int> > col_counter(9,std::vector<int>(9,0));
    for (int x=0;x<9;x=x+3) 
        for (int y=0;y<9;y=y+3){
            if (!sub_grid(grid,x,y,row_counter,col_counter)) return false ;
            
        }
    
    return ret_val;
    
}

void populate (std::vector<std::vector<char> > &grid, std::string line) {
    
     std::vector< char> tmp;
    
    
    const char* values=line.c_str();
    const char* end = values + strlen( values );

    tmp.insert( tmp.end(), values, end );

    
    
    grid.push_back(tmp);
}

std::string thanks_alot (std::string array[]) {
    
    
    std::string ret_val = "";
    
    for (int x=0;x<9;++x)
        ret_val = ret_val + array[x];
    cout << ret_val << endl;
    return ret_val;
}


 
int main (void)  {
    
    // TC 1 - sub-grid check
    {
        std::vector<std::vector<char> > grid;
            std::vector<std::vector<int> > rc(9,std::vector<int>(9,0));
    std::vector<std::vector<int> > cc(9,std::vector<int>(9,0));
        
        
        {                         
            std::string array[] = {".",".",".","1","4",".",".","2","."};
            std::string wow = thanks_alot(array);
            populate(grid, wow);
        }
        {
            std::string array[] = {".",".","6",".",".",".",".",".","."};
            std::string wow = thanks_alot(array);
            populate(grid, wow);
        }
        
        {
            std::string array[] = {".",".",".",".",".",".",".",".","."};
            std::string wow = thanks_alot(array);
             populate(grid, wow);
        }
        
        bool res = sub_grid(grid,0,0,rc,cc);
        cout << "\nRES: " << res << "\n\n" << endl;
    }
    
    // TC 1a - sub-grid check failure
    {
        std::vector<std::vector<char> > grid;
        std::vector<std::vector<int> > rc(9,std::vector<int>(9,0));
        std::vector<std::vector<int> > cc(9,std::vector<int>(9,0));
        
        
        {                         
            std::string array[] = {"6",".",".","1","4",".",".","2","."};
            std::string wow = thanks_alot(array);
            populate(grid, wow);
        }
        {
            std::string array[] = {".",".","6",".",".",".",".",".","."};
            std::string wow = thanks_alot(array);
            populate(grid, wow);
        }
        
        {
            std::string array[] = {".",".",".",".",".",".",".",".","."};
            std::string wow = thanks_alot(array);
             populate(grid, wow);
        }
        
        bool res = sub_grid(grid,0,0,rc,cc);
        cout << "\nTC1a RES: " << res << "\n\n" << endl;
    } // TC1a
    
    // TC 2 - True Result
    {
        std::vector<std::vector<char> > grid;
        
        
        {                          
            std::string array[] = {".",".",".","1","4",".",".","2","."};
            std::string wow = thanks_alot(array);
            populate(grid, wow);
        }
    
        
        {
            std::string array[] = {".",".","6",".",".",".",".",".","."};
            std::string wow = thanks_alot(array);
             populate(grid, wow);
        }
        
            {
            std::string array[] = {".",".",".",".",".",".",".",".","."};
            std::string wow = thanks_alot(array);
             populate(grid, wow);
        }
        
            {
            std::string array[] = {".",".","1",".",".",".",".",".","."};
            std::string wow = thanks_alot(array);
             populate(grid, wow);
        }
        
            {
            std::string array[] = {".","6","7",".",".",".",".",".","9"};
            std::string wow = thanks_alot(array);
             populate(grid, wow);
        }
        
            {
            std::string array[] = {".",".",".",".",".",".","8","1","."};
            std::string wow = thanks_alot(array);
             populate(grid, wow);
        }
        
            {
            std::string array[] = {".","3",".",".",".",".",".",".","6"};
            std::string wow = thanks_alot(array);
             populate(grid, wow);
        }
        
            {
            std::string array[] = {".",".",".",".",".","7",".",".","."};
            std::string wow = thanks_alot(array);
             populate(grid, wow);
        }
        
        {
            std::string array[] = {".",".",".","5",".",".",".","7","."};
            std::string wow = thanks_alot(array);
             populate(grid, wow);
        }
        
        cout << "starting..." << endl;
        bool res = sudoku2(grid);
      
        cout << "\n\nTC2 RESULT: "<< res << endl;
    }
        
    // TC3 - Row Failure
    {
      cout << "\n\nTC3..." << endl;
      std::vector<std::vector<char> > grid;
      

      
      // Line 1
      {                          
          std::string array[] = {".",".",".",".","2",".",".","9","."};
          std::string wow = thanks_alot(array);
          populate(grid, wow);
      }
  
      // Line 2
      {
          std::string array[] = {".",".",".",".","6",".",".",".","."};
          std::string wow = thanks_alot(array);
           populate(grid, wow);
      }
      
          {
          std::string array[] = {"7","1",".",".","7","5",".",".","."};
          std::string wow = thanks_alot(array);
           populate(grid, wow);
      }
      
          {
          std::string array[] = {".","7",".",".",".",".",".",".","."};
          std::string wow = thanks_alot(array);
           populate(grid, wow);
      }
      
          {
          std::string array[] = {".",".",".",".","8","3",".",".","."};
          std::string wow = thanks_alot(array);
           populate(grid, wow);
      }
      
          {
          std::string array[] = {".",".","8",".",".","7",".","6","."};
          std::string wow = thanks_alot(array);
           populate(grid, wow);
      }
      
          {
          std::string array[] = {".",".",".",".",".","2",".",".","."};
          std::string wow = thanks_alot(array);
           populate(grid, wow);
      }
      
          {
          std::string array[] = {".","1",".","2",".",".",".",".","."};
          std::string wow = thanks_alot(array);
           populate(grid, wow);
      }
      
          {
          std::string array[] = {".","2",".",".","3",".",".",".","."};
          std::string wow = thanks_alot(array);
           populate(grid, wow);
      }
      
      cout << "starting..." << endl;
      bool res = sudoku2(grid);
      
      cout << "\n\nTC3 RESULT: "<< res << endl;
        
        
    } // TC3

    // TC4 - Column Failure
    {
      cout << "\n\nTC4..." << endl;
      std::vector<std::vector<char> > grid;
      

      
      // Line 1
      {                          
          std::string array[] = {".",".",".",".","2",".",".","9","."};
          std::string wow = thanks_alot(array);
          populate(grid, wow);
      }
  
      // Line 2
      {
          std::string array[] = {".",".",".",".","6",".",".",".","."};
          std::string wow = thanks_alot(array);
           populate(grid, wow);
      }
      
          {
          std::string array[] = {"7","1",".",".","7","5",".",".","."};
          std::string wow = thanks_alot(array);
           populate(grid, wow);
      }
      
          {
          std::string array[] = {".","7",".",".",".",".",".",".","."};
          std::string wow = thanks_alot(array);
           populate(grid, wow);
      }
      
          {
          std::string array[] = {".",".",".",".","8","3",".",".","."};
          std::string wow = thanks_alot(array);
           populate(grid, wow);
      }
      
          {
          std::string array[] = {".",".","8",".",".","7",".","6","."};
          std::string wow = thanks_alot(array);
           populate(grid, wow);
      }
      
          {
          std::string array[] = {".",".",".",".",".","2",".",".","."};
          std::string wow = thanks_alot(array);
           populate(grid, wow);
      }
      
          {
          std::string array[] = {".","1",".","2",".",".",".",".","."};
          std::string wow = thanks_alot(array);
           populate(grid, wow);
      }
      
          {
          std::string array[] = {".","2",".",".","3",".",".",".","."};
          std::string wow = thanks_alot(array);
           populate(grid, wow);
      }
      
      cout << "starting..." << endl;
      bool res = sudoku2(grid);
      
      cout << "\n\nTC4 RESULT: "<< res << endl;
        
        
    } // TC4
    
     // TC5 - Column Failure
    {
      cout << "\n\nTC5..." << endl;
      std::vector<std::vector<char> > grid;
      

      
        // Line 1
        {                          
          std::string array[] = {".",".","4",".",".",".","6","3","."};
          std::string wow = thanks_alot(array);
          populate(grid, wow);
        }
  
        // Line 2
        {
          std::string array[] = {".",".",".",".",".",".",".",".","."};
          std::string wow = thanks_alot(array);
           populate(grid, wow);
        }
      
        
        // Line 3
        {
          std::string array[] = {"5",".",".",".",".",".",".","9","."};
          std::string wow = thanks_alot(array);
           populate(grid, wow);
        }
      
        // Line 4
        {
          std::string array[] = {".",".",".","5","6",".",".",".","."};
          std::string wow = thanks_alot(array);
           populate(grid, wow);
        }
      
        // Line 5
        {
          std::string array[] = {"4",".","3",".",".",".",".",".","1"};
          std::string wow = thanks_alot(array);
           populate(grid, wow);
        }
      
        // Line 6
        {
            std::string array[] = {".",".",".","7",".",".",".",".","."};
            std::string wow = thanks_alot(array);
            populate(grid, wow);
        }
      
        // Line 7
        {
          std::string array[] = {".",".",".","5",".",".",".",".","."};
          std::string wow = thanks_alot(array);
           populate(grid, wow);
        }
      
        // Line 8
        {
            std::string array[] = {".",".",".",".",".",".",".",".","."};
            std::string wow = thanks_alot(array);
            populate(grid, wow);
        }
      
        // Line 9
        {
          std::string array[] = {".",".",".",".",".",".",".",".","."};
          std::string wow = thanks_alot(array);
           populate(grid, wow);
        }
      
        cout << "starting..." << endl;
        bool res = sudoku2(grid);
        
        cout << "\n\nTC5 RESULT: "<< res << endl;
        
        
    } // TC5





} // Main