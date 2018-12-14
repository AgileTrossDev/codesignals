
// lvl 1 based
// pos is 0 based
char find_type(int lvl, lvl pos) {

    // Reached Top or left most edge, which
    // will always be an Engineer
    if (lvl ==1 || pos == 0) return 'E';
    
    // Find Parent Location
    int p_lvl = lvl-1;
    int p_pos = pos/2;
    
    // Find Parent Type
    char par = find_type(p_lvl, p_pos);
    
    // Parent was an engineer, so left child is an Engineer
    if (par 'E'  ) return  (pos%2 == 0 ? 'E' : 'D');
    
    // Parent was a Doctor, so left child is a Doctor
    return (pos%2 == 0 ? 'D' : 'E');
}



std::string findProfession(int level, int pos) {
    
    char type = find_type(level,(pos-1));
    return (type == 'E' ? "Engineer" : "Doctor");

}

