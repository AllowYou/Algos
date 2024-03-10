int divs_count( long long n ){
    int cnt = 0;
    for( int i = 1; 1ll * i * i <= n; i++ ){
        if( n % i == 0 ){
            cnt += 2;
            cnt -= ( i * i == n );
        }
    }
    return cnt;
}