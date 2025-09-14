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

void printBinary(ll n)
{
    for(ll i=10;i>=0;i--)
    {
        cerr<<((n>>i) & 1);
    }
    cerr<<endl;
}

ll fastExpo(ll a,ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b&1)
        {
            ans = ans * a;
        }
        a = a * a;
        b>>=1;
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

vector<int> bfsOfGraph(int V, vector<int> adj[]) 
{
    int vis[V] = {0}; 
    vis[0] = 1; 
    queue<int> q;
     
    q.push(0); 
    vector<int> bfs; 
       
    while(!q.empty()) 
    {
       
        int node = q.front(); 
        q.pop(); 
        bfs.push_back(node); 
           
        for(auto it : adj[node]) 
        {
               
            if(!vis[it]) {
                vis[it] = 1; 
                q.push(it); 
            }
        }
    }
    return bfs; 
}

void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls) 
{
        /*
        node - start node
        adj - graph 
        vis - visited 
        ls - final vector containing dfs
        */
        vis[node] = 1; 
        ls.push_back(node); 
        for(auto it : adj[node]) 
        {
            if(!vis[it]) 
            {
                dfs(it, adj, vis, ls); 
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
    
vector<ll> dfsvector;
void DFS(int n,map<ll,vector<ll>> &mp,vector<ll> &visited,ll node)
{
    //first declarea  queue

    
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

void kahnsAlgo(map<ll,vector<ll>> &mp,ll nodes)
{
    queue<ll> que;

    vector<ll> indegree(nodes,0);
    for(auto pr:mp)
    {
        ll node = pr.first;
        vector<ll> v = pr.second;
        for(auto x:v)
        {
            indegree[x]++;
        }
    }

    for(ll i=0;i<nodes;i++)
    {
        if(indegree[i]==0)
        {
            que.push(i);
        }
    }
    debug(indegree);
    vector<ll> topoOrder;

    while(!que.empty())
    {
        ll node = que.front();
        topoOrder.push_back(node);
        que.pop();

        vector<ll> v = mp[node];

        for(auto x:v)
        {
            indegree[x]--;
            if(indegree[x]==0)
            {
                que.push(x);
            }
        }
    }

    debug(topoOrder);


}




void solve()
{   
    map<ll,vector<ll>> mp;
    ll n;
    cin>>n;

    set<ll> st;
    for(ll i=0;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        mp[x].push_back(y);
        st.insert(x);
        st.insert(y);
    }

    ll nodes = st.size();
    debug(mp);

    kahnsAlgo(mp,nodes);




}

int main() 
{
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    ll t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}