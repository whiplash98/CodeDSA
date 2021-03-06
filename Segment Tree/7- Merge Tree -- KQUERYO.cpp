#include "bits/stdc++.h"
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int                      long long
#define ll                       long long
#define ld                       long double
#define ull                      unsigned long long
#define vi                       vector<int>
#define pii                      pair<int,int>
#define mod                      1000000007 //998244353

#define for0(i,n)                for(int i=0;i<n;++i)
#define fora(i,a,b)              for(int i=a;i<=b;++i)
#define rfor(i,a,b)              for(int i=a;i>=b;--i)
#define onlyunique(v)            v.erase(unique(all(v)), v.end()); //only for sorted vector
#define rev(v)                   reverse(v.begin(),v.end())

#define sz(tmp)                  (int)tmp.size()
#define def(v)                   memset(v, -1, sizeof(v));
#define def0(v)                  memset(v, 0, sizeof(v));
#define all(v)                   v.begin(), v.end()
#define rall(v)                  v.rbegin(), v.rend()
#define f                        first
#define s                        second
#define pb                       push_back
#define mp                       make_pair
#define pie                      (3.141592653589)
#define inf                      ((ll)7000000000000000000)
#define um                       unordered_map

#define ordered_set             tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
//0-based idxing, methods: find_by_order(k); & order_of_key(k);
//To make it an ordered_multiset, use pairs of (value, time_of_insertion)
//to distinguish values which are similar.

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using maxpq = priority_queue<T>;

#ifndef ONLINE_JUDGE
#define dbg(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {cerr << name << " : " << arg1 << endl;}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << "  ";
    __f(comma + 1, args...);
}
#else
#define dbg(...) 50
#endif


void ishan_pandey()
{   //input fastio
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}
int dxx[4] = { 0 , -1 , 0 , 1 };
int dyy[4] = { 1 ,  0 , -1 ,  0 };
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

const int maxn = 200010;
int a[maxn];

vector<int> v[maxn]; //st each node of segment tree we store a list: merge sort tree

//Memory O(nlogn)
//https://cp-algorithms.com/data_structures/segment_tree.html
int lastans = 0;
void build(int i, int l, int r)
{
    if (l == r)
    {
        v[i].pb(a[l]);
        return;
    }

    int mid = (l + r) >> 1;
    build(2 * i, l, mid);
    build(2 * i + 1, mid + 1, r);

    merge(all(v[2 * i]), all(v[2 * i + 1]), back_inserter(v[i]));
}


int query(int i, int ql, int qr, int l, int r, int k)
{
    //no overlap
    if (ql > r or qr < l)
    {
        //nothing greater
        return 0;
    }

    //total overlap:
    if (ql <= l and qr >= r)
    {
        int ans = (int)v[i].size() - (upper_bound(all(v[i]), k) - v[i].begin());
        return ans;
    }
    int mid = (l + r) >> 1;

    return query(2 * i, ql, qr, l, mid, k) + query(2 * i + 1, ql, qr, mid + 1, r, k);
}



void solve()
{
    int n; cin >> n;

    for0(i, n) cin >> a[i];

    //no updates in this problem
    build(1, 0, n - 1); //startnodeofst, l, r

    int q;
    cin >> q;

    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        //tell how many no in range of idx[l, r] greater than k
        // l = l ^ lastans;
        // r = r ^ lastans;
        // k = k ^ lastans;

        lastans = query(1, l - 1, r - 1, 0, n - 1, k);
        cout << lastans << endl;


    }


}

signed main()
{
    clock_t t1, t2;
    t1 = clock();

    ishan_pandey();
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve();
        // cout << "Case" << " " << "#" << i << ":" << " " << ans << endl;
    }

#ifndef ONLINE_JUDGE
    t2 = clock(); cerr << "time taken : " << (t2 - t1) / (ld)CLOCKS_PER_SEC;
#endif

    return 0;
}




