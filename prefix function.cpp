vector<int> prefix_function(string &s){
    vector<int> p(s.size());
    for (int i = 1; i < s.size(); i++){
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j])
            j = p[j - 1];
        if (s[i] == s[j])
            j += 1;
        p[i] = j;
    }
    return p;
}
