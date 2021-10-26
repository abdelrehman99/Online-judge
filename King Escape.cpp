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

int n, b = 0;
int ax, ay, bx, by, cx, cy;
vvi v;
vector < vector <bool > > valid;


bool is(int i, int j)
{
    return i > 0 && j > 0 && i <= n && j <= n && ((ax - i) + j != ay) && ((ax - i) + ay != j) && (ax != i) && (ay != j) && !valid[i][j];
}

vi dx = {0, -1, 1, 0, 0, 1, -1, 1, -1};
vi dy = {0, 0, 0, 1, -1, 1, -1, -1, 1};

void dfs(int i, int j)
{
    valid[i][j] = true;
    for (int k = 0; k <= 8; k++)
    {
        int nwi = i + dx[k], nwj = j + dy[k];
        if (is(nwi, nwj)) 
        {
            if (nwi == cx && nwj == cy)
            {
                cout << "YES\n";
                exit(0);
            }
            dfs(nwi, nwj);
        }
    }
}


void solve()
{ 
    {
        cin >> n;
        v.resize(n + 1, vi (n + 1));
        valid.resize(n + 1, vector <bool> (n + 1));
        cin >> ax >> ay >> bx >> by >> cx >> cy;
        if (bx == cx && cy == by)
        {
            cout << "YES\n";
            return;
        }
        dfs(bx, by);
        cout << "NO";
        cout << endl;
    }
}




signed main(){
    fast;
    int t = 1;
    WL(t)
    {
    	solve();
        runtime();
    }
    return 0;
}
