#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
#else
#define debug(x)
#endif
 
template <class T, class V> void _print(pair <T, V> p) {cerr << "{ "; _print(p.first); cerr << ", "; _print(p.second); cerr << " }";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
bool checkSet(ll n,ll i)
{
    return ((n & (1<<i)) != 0);
}
 
bool checkPowerOfTwo(ll n)
{
    return (n && !(n & (n-1)));
}
 
ll setBit(ll n,ll i)
{
    return (n | (1<<i));
}
 
ll unsetBit(ll n,ll i)
{
    return (n & (~(1<<i)));
}
 
ll toggleBit(ll n,ll i)
{
    return (n ^ (1<<i));
}

ll fastExpo(ll a, ll b, ll mod = MOD)
{
    ll ans = 1;
    a %= mod;  
    while(b)
    {
        if(b & 1)
        {
            ans = (ans * a) % mod;  
        }
        a = (a * a) % mod;          
        b >>= 1;
    }
    return ans;
}
 
bool checkPrime(ll n)
{
    if(n==1 || n==0) return false;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0) return false;
    }
    return true;
}
 
vector<ll> primeFactors;
void primeFactorization(ll n)
{
    for(ll i=2;i*i<=n;i++)
    {
        while(n%i==0)
        {
            primeFactors.push_back(i);
            n = n/i;
        }
    }
    if(n>1)
    {
        primeFactors.push_back(n);
    }
}
 
int isPrime[1000001];
void Sieve()
{
    ll maxN = 1000002;
    for(int i=1;i<maxN;i++)
    {
        isPrime[i] = 1;
    }
    isPrime[0] = 0;
    isPrime[1] = 0;
 
    for(ll i=2;i*i<=maxN;i++)
    {
        if(isPrime[i])
        {
            for(ll j=i*i;j<=maxN;j=j+i)
            {
                isPrime[j] = 0;
            }
        }
    }
 
}
vector<ll> BFS(int n,map<ll,vector<ll>> &mp,vector<ll> &visited,ll startNode)
{
    vector<ll> bfsvector;
    queue<ll> que;
 
    que.push(startNode);
    visited[startNode] = 1;
 
    while(!que.empty())
    {
        ll x = que.front();
        que.pop();
        vector<ll> v = mp[x];
 
        bfsvector.push_back(x);
        for(auto ele:v)
        {
            if(!visited[ele])
            {
                visited[ele] = 1;
                que.push(ele);
            }
        }
    }
 
    return bfsvector;
 
 
 
}
vector<ll> dfsvector;
void DFS(int n,map<ll,vector<ll>> &mp,vector<ll> &visited,ll node)
{    
    visited[node] = 1;
    dfsvector.push_back(node);
    vector<ll> v = mp[node];
 
    for(auto ele:v)
    {
        if(!visited[ele])
        {
            DFS(n,mp,visited,ele);
        }
    }
 
 
}
 
 
 
void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}
 
ll N = 100; 
// ll Arr[100];
vector<ll> fact(N+1,0);
vector<ll> inv_fact(N+1,0);
 
 
void factorials() 
{
    fact[0] = 1;
 
    for(ll i = 1;i <= N;i++) fact[i] = (fact[i - 1] * i) % MOD;
 
    inv_fact[N] = fastExpo(fact[N], MOD - 2);
 
    for(ll i = N - 1;i >= 0;i--) inv_fact[i] =  (inv_fact[i + 1] * (i + 1)) % MOD;
}
 
ll ncr(int n, int k) 
{
    return (fact[n] * ((inv_fact[k] * inv_fact[n - k]) % MOD)) % MOD;
}
 
ll npr(int n,int k)
{
    return ((fact[n]*inv_fact[n-k])%MOD);
}

// Segment tree basic imlimentaiton


vector<ll> v(100000);
vector<ll> sgt(4*100000);

void build(ll s, ll e, ll index)
{
    if(s==e) //leaf node
    {
        sgt[index] = v[s];
        return;
    }

    ll mid = (s+e)/2;
    build(s,mid,2*index);
    build(mid+1,e,(2*index)+1);

    // combination logic (as per the problem statement)
    sgt[index] = sgt[2*index] + sgt[(2*index)+1];
} 

void update(ll s,ll e,ll index, ll update_index, ll update_value)
{
    if(s==e)
    {
        sgt[index] = update_value;
        return;
    }

    ll mid = (s+e)/2;
    
    if(mid>=update_index)
    {
        update(s,mid,2*index,update_index,update_value);
    }
    else
    {
        update(mid+1,e,(2*index)+1,update_index,update_value);
    }

    sgt[index] = sgt[2*index] + sgt[(2*index)+1];
}

ll query(ll s, ll e, ll index , ll l , ll r)
{
    // no overlap
    if(s>r || e<l)
    {
        return 0;
    }
    // complete overlap
    if(s>=l && e<=r)
    {
        return sgt[index];
    }
    // partial overlap

    ll mid = (s+e)/2;
    ll leftContri = query(s,mid,2*index,l,r);
    ll rightContri = query(mid+1,e,(2*index)+1,l,r);

    return (leftContri+rightContri);


}

void solve()
{
    ll n;
    cin>>n;

    for(ll i=0;i<n;i++)
    {
        cin>>v[i];
    }


    build(0,n-1,1);

    // build will take the start , end and the node number

    //handling queries

    ll q;
    cin>>q;

    while(q--)
    {
        ll type;
        cin>>type;

        if(type==1)
        {
            ll index, x;
            cin>>index>>x;
            update(0,n-1,1,index-1,x);
        }
        else
        {
            ll l,r;
            cin>>l>>r;
            cout<<query()
        }
    }









        

    
}


int main() 
{
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    
    ll t;
    cin>>t;

    factorials();

    debug(fact);
    debug(inv_fact);
    while(t--)
    {
        solve();
    }
 
    return 0;
}