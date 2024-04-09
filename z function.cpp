vector<int> z_function(str &s){
    int n = len(s);
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i ++){
        if(i <= r)z[i] = min(r - i + 1, z[i - l]);
        while(s[i + z[i]] == s[z[i]] and i + z[i] < n)z[i] ++;
        if(i + z[i] - 1 > r){
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}
