#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define LSOne(S) ((S)&(-S))
#define all(S) S.begin(),S.end()
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
struct nodo{
    int ini;
    int fin;
    int pos;
    int asignado;
    bool operator < (const nodo &otra){
        if(ini<otra.ini)return true;
        if(ini>otra.ini)return false;
        return fin<otra.fin;
    }
};

struct ura{
    int fin;
    int pos;

};
bool operator < (ura a, ura b){
    return a.fin > b.fin;
}
void solve(){
    int n,m,k;
    cin>>n;
    vector<nodo> rangos(n);
    for(int i = 0;i < n;i++){
        cin>>rangos[i].ini>>rangos[i].fin;
        rangos[i].pos = i;
    }
    sort(all(rangos));

    int resp = 0;
    vi acomodo(n);

    set<int> disponibles;
    priority_queue<ura> porQuitar;

    for(int i=0;i<n;i++){
        while(!porQuitar.empty() && porQuitar.top().fin<rangos[i].ini){
            disponibles.insert(acomodo[porQuitar.top().pos]);
            porQuitar.pop();
        }
        if(disponibles.empty()){
            resp++;
            disponibles.insert(resp);
        }
        
        acomodo[rangos[i].pos]=*disponibles.begin();

        disponibles.erase(*disponibles.begin());
        porQuitar.push({rangos[i].fin,rangos[i].pos});
        
    }

    cout<<resp<<"\n";
    for(int i=0;i<n;i++){
        cout<<acomodo[i]<<" ";
    }
    cout<<"\n";

}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}