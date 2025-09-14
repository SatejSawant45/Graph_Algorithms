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
    

vector<ll> BFS(int n,map<ll,vector<ll>> &mp,vector<ll> &visited,ll startNode)
{
    //first declarea  queue

    vector<ll> bfsvector;
    queue<ll> que;

    que.push(startNode);
    visited[startNode] = 1;
    // bfsvector.push_back(startNode);

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

ll find(ll node,vector<ll> &parent)
{
    if(parent[node]==node)
    {
        return node;
    }

    parent[node] = find(parent[node],parent);

    return parent[node];
}

void Union(ll node1,ll node2,vector<ll> &parent,vector<ll> &rank)
{
    ll p1 = find(node1,parent);
    ll p2 = find(node2,parent);

    if(rank[p1]==rank[p2])
    {
        parent[p1] = p2;
        rank[p2]++;
    }
    else if(rank[p1]>rank[p2])
    {
        parent[p2] = p1;
    }
    else
    {
        parent[p1] = p2;
    }
}

ll krushkals(map<ll,vector<pair<ll,ll>>> &mp,ll src)
{
    vector<vector<ll>> edges;

    ll n = mp.size();

    vector<ll> parent(n,0);
    vector<ll> rank(n,0);

    for(int i=0;i<n;i++)
    {
        parent[i] = i;
    }

    

    ll cost = 0;

    for(auto pr:mp)
    {
        vector<pair<ll,ll>> vp = pr.second;
        ll node = pr.first;

        for(auto ele:vp)
        {
            ll destination = ele.first;
            ll wt = ele.second;

            edges.push_back({wt,node,destination});
        }
    }

    sort(edges.begin(),edges.end());


    for(auto v:edges)
    {
        ll source = v[1];
        ll destination = v[2];
        ll wt = v[0];

        ll prtSource = find(source,parent);
        ll prtDestination = find(destination,parent);

        if(prtSource!=prtDestination)
        {
            cost += wt;

            Union(source,destination,parent,rank);
        }



    }

    return cost;
}


void solve()
{   
    map<ll,vector<pair<ll,ll>>> mp;
    ll m,n;
    cin>>m>>n;

    for(ll i=0;i<m;i++)
    {
        ll x,y,w;
        cin>>x>>y>>w;
        mp[x].push_back({y,w});
        mp[y].push_back({x,w});
    }

    
    
    

    
    
    
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