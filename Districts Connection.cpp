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
vector <vector <bool> > vis(5001, vector <bool> (5001));
bool flag = true;
vector <bool> val(5001);
vpii v2;
map <ll, vl> v;


void dfs (int i)
{
    val[i] = 1;
    if (!flag) return;
    FOR (j, n)
    {
        if (!vis[i][j] && !val[j])
        {
            if ((int)(v2.size()) == n - 2)
            {
                cout << "YES\n";
                for (auto x : v2) cout << x.F << " " << x.S << endl;
                cout << i << " " << j << endl;
                flag = false;
            }
            //cout << j << endl;
            v2.PB({i, j});
            dfs(j);
        } 
    }
    //cout << i << endl;
    //v2.PB(i);
}


void solve()
{
    cin >> n;
    int x;
    set <ll> v3;
    FOR (i, n)
    {
        cin >> x;
        v3.insert(x);
        if (v[x].empty()) v[x].PB(i);
        else 
        {
            v[x].PB(i);
            for (auto j : v[x])
            {
                vis[i][j] = vis[j][i] = true;
            }
        }
        //vis[i][x] = true;
    }
    FOR (i, n)
    {
        //cout << i << endl;
        if (!val[i]) dfs(i);
    } 
    //for (auto &i : v2) cout << i.F << " " << i.S << endl;   
    if (flag) cout << "NO\n";
    v2.clear();
    FOR (i, n)
    {
        FOR (j, n) vis[i][j] = 0;
        val[i] = 0;
    }
    for (auto &i : v3)
    {
        v[i].clear(); 
    }
    //val.clear();
    flag = true;
}




signed main(){
    fast;
    int t;
    cin >> t;
    while (t--)
    {
    	solve();
    }
    runtime();
    return 0;
}
