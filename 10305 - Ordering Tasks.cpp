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


int n, m;
vvi v;
vector <bool> vis;
vi v2;


void dfs (int i)
{
    vis[i] = 1;
    for (auto &j : v[i])
    {
        if (!vis[j]) dfs(j);
    }
    //cout << i << endl;
    v2.PB(i);
}


void solve()
{ 
    v.resize(n + 1), vis.resize(n + 1), v2.resize(n + 1);
    int x, y;
    FOR (i, m)
    {
        cin >> x >> y;
        v[x].PB(y);
    }
    FOR (i, n)
    {
        if (!vis[i]) dfs(i);
    }
    reverse(all(v2));
    for (int i = 0; i < n; i++)
    {
        cout << v2[i];
        if (i != n - 1) cout << " ";
        else cout << endl;
    }
    v.clear(), v2.clear(), vis.clear();
}




signed main(){
    fast;
    //int t = 1;
    //cin >> t;
    while (cin >> n && cin >> m && (n != 0 || m != 0)){
    	solve();
    }
    runtime();
    return 0;
}
