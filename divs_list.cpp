vector<int> divs_list( long long n ){
    vector<int> divs;
    for( int i = 1; 1ll * i * i <= n; i++ ){
        if( n % i == 0 ){
            divs.push_back( i );
            if( i * i != n ) {
                divs.push_back( n / i );
            }
        }
    }
    sort( divs.begin(), divs.end() );
    return divs;
}