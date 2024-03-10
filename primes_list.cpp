vector<int> primes_list( int n ){
    vector<int> primes, sieve( n + 1, 0 );
    for( int i = 2; i <= n; i++ ){
        if( !sieve[i] ){
            primes.push_back( i );
            if( 1ll * i * i <= n ){
                for( int j = i * i; j <= n; j += i ){
                    sieve[j] = 1;
                }
            }
        }
    }
    return primes;
}