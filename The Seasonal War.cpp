#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define FOR(i, n) for(int i = 0; i < (int) n; i++)
#define cin(v) for (auto &i : v) cin >> i;
#define cout(v) for (auto &i : v) cout >> i;
#define WL(t) while(t --)
#define S second
#define PB push_back
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define runtime() cerr << ((double)clock() / CLOCKS_PER_SEC)
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

int n, c = 0;
vector < string > v;
vector < vector <bool > > valid;


bool is(int i, int j)
{
    return i >= 0 && j >= 0 && i < n && j < n && v[i][j] == '1' && !valid[i][j];
}

vi dx = {1, -1, 0, 1, -1, 1, -1, 0, 0};
vi dy = {1, -1, 0, -1, 1, 0, 0, -1, 1};

void dfs(int i, int j)
{
    valid[i][j] = true;
    FOR (k, 9)
    {
        int nwi = i + dx[k], nwj = j + dy[k];
        if (is(nwi, nwj)) 
        {
            //cout << nwi << " " << nwj << endl;
            dfs(nwi, nwj);
        }
    }
    //c++; 
}


void solve()
{ 
    for (int k = 1; cin >> n; k++)
    {
        //cout << n << endl;
        v.resize(n);
        valid.resize(n, vector <bool> (n));
        FOR (i, n)
        {
            cin >> v[i];
        } 
        FOR (i, n)
        {
            FOR (j, n)
            {
                if (is(i, j))
                {
                    dfs(i, j);
                    c++;
                }
            }
        }
        cout << "Image number " << k << " contains " << c << " war eagles." << endl;
        v.clear();
        valid.clear();
        c = 0;
    }
}




signed main(){
    fast;
    int t = 1;
    //cin >> t;
    WL(t){
    	solve();
        runtime();
    }
    return 0;
}
