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

int solve(int t){
    string cad,query;
    cin>>cad>>query;

    vb hechos(cad.size());
    int faltan = cad.size();

    set<char> existen;
    for(char co:cad)existen.insert(co);
    int malas = 0;

    for(char co: query){
        if(!existen.count(co)){
            malas++;
            if(malas == 7)return -1;
        }
        for(int i=0;i<cad.size();i++){
            if(hechos[i])continue;
            if(co == cad[i]){
                hechos[i]=1;
                faltan--;
                if(faltan == 0)return 1;
            }
        }
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    do{
        cin>>n;
        if(n==-1)break;
        int s = solve(n);
        cout<<"Round "<<n<<"\n";
        if(s==-1){
            cout<<"You lose.\n";
        }else if(s==1){
            cout<<"You win.\n";
        }else{
            cout<<"You chickened out.\n";
        }
    }while(n!=-1);
}