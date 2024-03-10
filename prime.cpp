bool is_prime(long long n ) {
    if(n <= 4) return ( n == 2 || n == 3 ); 
    if(n % 2 == 0 || n % 3 == 0 ) return false;
    for(long long i = 5; i * i <= n; i += 6 ) 
        if( n % i == 0 || n % ( i + 2 ) == 0 )
            return 0; 
    return 1;
}