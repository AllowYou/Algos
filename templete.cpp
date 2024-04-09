#pragma GCC optimize("unroll-loops")
#pragma gcc optimize("Ofast")
#pragma GCC optimization("Ofast")
#pragma optimize(Ofast)
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define str string
#define fs first
#define ss second
#define all(a) a.begin(), a.end()

void __print(signed x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const str &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const array<int, 2> &x)
{
    cerr << '{';
    __print(x[0]);
    cerr << ',';
    __print(x[1]);
    cerr << '}';
}
template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.fs);
    cerr << ',';
    __print(x.ss);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &y : x)
        cerr << (f++ ? "," : ""), __print(y);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}

#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#ifdef ONLINE_JUDGE
#define debug(x...) 42
#endif

const int mod = 1e9 + 7;

void solve(){
    
}

signed main()
{
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}
