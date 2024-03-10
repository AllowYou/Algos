long long binpow(int a, int n, const int mod){
    long long ans = 1;
    while(n){
        if((n & 1))
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return ans;
}