int factorial(int n){
    int ans = 1;
    for(int i = 1; i <= n; i++)
        ans = (ans * i) % mod;
    return ans;
}