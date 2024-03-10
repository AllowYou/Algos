vector<int> sieve( int n ){
    vector<int> p( n + 1, 0 );
    p[0] = p[1] = 1;
    for( int i = 2; i <= n; i++ ){
        if( !p[i] ){
            p[i] = i;
            if( 1ll * i * i <= n ){
                for( int j = i * i; j <= n; j += i ){
                    p[j] = i;
                }
            }
        }
    }
    return p;
}