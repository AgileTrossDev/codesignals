#include <iostream>

using namespace std;

long repeatedString(string s, long n) {
    long cnt = 0;
    for (int i = 0; i< (min((long)s.length(),n)) ;i++) 
        if (s[i] == 'a') cnt++;
    
    if (n <= s.length()) return cnt;

    long repeats = n/(long)s.length()  ;
    int partial =  n % (long)s.length();
    cout << "R: " << repeats << " " << partial << endl;
    cnt = repeats * cnt;

    for (int i = 0; i< partial ;i++) {
        if (s[i] == 'a') cnt++;
    }


    return cnt;

}


int main(void) {
   cout << repeatedString("a",1000000000000) << endl;
}
