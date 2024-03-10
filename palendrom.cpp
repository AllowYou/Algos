bool is_palendrom(string &a){
    for(int i = 0; i < a.size() / 2; i ++){
        if(a[i] != a[a.size() - i - 1]){
            return false;
        }
    }
    return true;
}