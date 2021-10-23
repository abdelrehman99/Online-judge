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
const ll mod = 1e9+7, N = 2e6+7, M = 10000001, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}

vector <ll> sei(M, 1);
//vector<ll> primes;
vector <ll> v(M);

void seive(){
    sei[0] = 0;
    sei[1] = 0;
	for (ll i = 2; i<=M; i++){
		if (sei[i]) for (ll j = 2*i; j<=M; j+=i) sei[j] = 0;
	}
    for (ll i = 2; i <= M; i++)
    {
        v[i] = v[i - 1] + sei[i];
    }
}


void solve()
{ 
    ll x, y, c = 0;
    cin >> x >> y;
    if(x==1 && y==2)
    {
        cout << 1 << "\n";
        return;
    } 
    if(x==1 && y==3)
    {
        cout << 2 << "\n";
        return;
    }
    if(x==2 && y==3)
    {
        cout << 1 << "\n";
        return;
    }
    ll ans = y - x;
    ans = ans - (v[y] - v[x]);
    if(sei[x+1])
    {
        ans = ans + 1;
    }
    cout << ans << "\n";
}



signed main()
{
    fast;
    seive();
    int t = 1;
    cin >> t;
    WL(t){
    	solve();
    }
    runtime();
    return 0;
}
