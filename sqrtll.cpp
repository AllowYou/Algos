int sqrt_n( long long n ){
    int x = sqrt( ( long double ) n );
    while( 1ll * x * x < n ) x++;
    while( 1ll * x * x > n ) x--;
    return x;
}