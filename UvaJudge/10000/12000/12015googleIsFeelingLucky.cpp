#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define LSOne(S) ((S)&(-S))
#define all(S) S.begin(),S.end()
#define fore(V,I,F) for(int V=I;V<=F;V++)
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

struct page{
    string name;
    int relevance;
    int idx;
    const bool operator <(const page &otro)const{
        if(relevance>otro.relevance)return true;
        if(relevance<otro.relevance)return false;
        return idx<otro.idx;
    }
};

void solve(){
    vector<page> paginas(10);
    string s;
    int r;
    fore(i,0,9){
        cin>>paginas[i].name>>paginas[i].relevance;
        paginas[i].idx = i;
    }

    sort(all(paginas));
    int obj = paginas[0].relevance;

    fore(i,0,9){
        if(obj == paginas[i].relevance){
            cout<<paginas[i].name<<"\n";
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    fore(i,1,t){
        cout<<"Case #"<<i<<":\n";
        solve();
    }
}