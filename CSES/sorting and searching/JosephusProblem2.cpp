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
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
void corte(int pos, vpii &bloques, vi &data){
    int i=0;
    vpii nuevo = {};
    while(bloques[i].second-bloques[i].first<pos){
        pos-=bloques[i].second-bloques[i].first;
        nuevo.pb(bloques[i]);
        i++;
    }
    cout<<data[bloques[i].first+pos-1]<<" ";
    //cout<<"__"<<pos<<"__";
    if(pos>1){
        nuevo.pb({bloques[i].first,bloques[i].first+pos-1});
    }
    if(bloques[i].second>bloques[i].first+pos){
        nuevo.pb({bloques[i].first+pos,bloques[i].second});
    }
    i++;
    while(i<bloques.size())nuevo.pb(bloques[i++]);
    swap(nuevo,bloques);
}
void solve(){
    int n,m,k;
    cin>>n>>k;
    k++;
    vi data(n);
    vi reacomodo;
    for(int i=0;i<n;i++)data[i]=i+1;
    vpii bloques={{0,n}};
    int ratio = sqrt(n);
    int veces = n;
    int act = 1;
    int vivos = n;
    do{
        for(int i=0;i<ratio && vivos>0;i++){
            veces--;
            act+=(k-1)%vivos;
            if(act>vivos)act-=vivos;
            corte(act,bloques,data);
            /*cout<<"\t";
            for(auto z:bloques){
                cout<<"{"<<z.first<<","<<z.second<<"}";
            }
            cout<<"\n";*/
            vivos--;
        }
        reacomodo.clear();
        for(auto z:bloques){
            for(int i=z.first;i<z.second;i++){
                reacomodo.pb(data[i]);
            }
        }
        swap(reacomodo,data);
        bloques.clear();
        bloques.pb({0,vivos});
        /*cout<<"[";
        for(int z:data){
            cout<<z<<",";
        }
        cout<<"]\n";*/
    }while(vivos>0);
}
int main(){
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}