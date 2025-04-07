#include<bits/stdc++.h>
#define fi fist
#define se second
#define LSOne(S) ((S)&(-S))
#define pb push_back
#define all(S) S.begin(),S.end()
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
using namespace std;



struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

int tipo_camisa(string &orig){
    if(orig=="XS")return 1;
    if(orig=="S")return 2;
    if(orig=="M")return 3;
    if(orig=="L")return 4;
    if(orig=="XL")return 5;
    if(orig=="XXL")return 6;
    return -1;
}

void solve(){
    int n,m,u;
    string cad;
    cin>>n>>m;
    n/=6;
    Dinic flujo(m+6+2,0,m+7);
    for(int i=1;i<=m;i++){
        flujo.add_edge(0,i,1);
    }
    for(int i=1;i<=6;i++){
        flujo.add_edge(m+i,m+7,n);
    }
    for(int i=1;i<=m;i++){
        cin>>cad;
        u = tipo_camisa(cad);
        flujo.add_edge(i,m+u,1);
        cin>>cad;
        u = tipo_camisa(cad);
        flujo.add_edge(i,m+u,1);
    }
    int z = flujo.flow();
    if(z==m){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}