#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define FOR(i, n) for(int i = 1; i <= (int) n; i++)
#define cin(v) for (auto &i : v) cin >> i;
#define cout(v) for (auto &i : v) cout >> i;
#define WL(t) while(t --)
#define S second
#define PB push_back
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define runtime() cerr << ((double)clock() / CLOCKS_PER_SEC) << endl;
#define MP make_pair
#define llu unsigned long long
typedef long long ll;typedef long double ld;
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
const ll mod = 1e9+7, N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}


int n;
vvi v;
vector <bool> vis;
vector <int> v2, v3;


void dfs (int i)
{
    vis[i] = 1;
    v2.PB(i);
    for (auto &j : v[i])
    {
        if (!vis[j]) dfs(j);
    }
    if (*(v2.end()) == n)
    {
        for (auto & j : v2) cout << j << " ";
        cout << n;
        exit(0);
    }
    else v2.pop_back();
}


void solve()
{ 
    cin >> n;
    v.resize(n + 1), vis.resize(n + 1);
    int x;
    FOR (i, n - 1)
    {
        cin >> x;
        v[x].PB(i + 1);
    }
    //v2.PB(1);
    dfs(1);
    //v.clear(), v2.clear(), vis.clear();
}




signed main(){
    fast;
    //int t = 1;
    //cin >> t;
    solve();
    runtime();
    return 0;
}
