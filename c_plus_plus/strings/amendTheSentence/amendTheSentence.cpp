std::string amendTheSentence(std::string s) {
    std::string ret_val ((s.length() *2),'_');
    
    int t = 0;
    ret_val[t++] = ((s[0] <= 'Z') ? (s[0] +32):s[0] );
    for (int i=1;i<s.length();++i){
       
        if (s[i] <= 'Z') { ret_val[t++] = ' ';}
        ret_val[t++] = ((s[i] <= 'Z') ? (s[i] +32):s[i] );
       
    }

    // trim the extra digits
    ret_val.erase( t,((s.length() *2)));
   
    return ret_val;
}
