#include <bits/stdc++.h>
#include <fstream>
#define fi first
#define se second
#define pb push_back
#define all(S) S.begin(),S.end()
#define LSOne(S) ((S)&(-S))
#define fore(V,L,R) for(int V = L; V<=R;V++)
using namespace std;
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
ll mini(vll &vacas, bool dir){
    if(vacas[0]==vacas[1]-1 && vacas[1]==vacas[2]-1)return 0;
    if(dir == 0){
        int extra = vacas[1]+1;
        if(vacas[2]==extra+1)return 1;
        return 2;
    }else{
        int extra = vacas[1]-1;
        if(vacas[0]==extra-1)return 1;
        return 2;
    }
}
ll maxi(vll &vacas, bool dir){
    if(vacas[0]==vacas[1]-1 && vacas[1]==vacas[2]-1)return 0;
    if(dir == 0){
        return max(0LL,vacas[2]-vacas[1]-1LL);
    }else{
        return max(0LL,vacas[1]-vacas[0]-1LL);
    }
}

ll maxix(vll &vacas, bool dir){
    if(vacas[0]==vacas[1]-1 && vacas[1]==vacas[2]-1)return 0;
    if(dir == 0){
        if(vacas[2] == vacas[1]+1)return 0;
        return vacas[2]-vacas[1]-1;
    }else{
        if(vacas[1]==vacas[0]+1)return 0;
        return vacas[1]-vacas[0]-1;
    }
}

void solve(){
    ifstream fin;
    ofstream fout;
    fin.open("herding.in");
    vll vacas(3);
    fore(i,0,2)fin>>vacas[i];
    sort(all(vacas));

    ll minimiza = min(mini(vacas,0),mini(vacas,1));
    ll maximiza = max(maxi(vacas,0),maxi(vacas,1));
    ll otmaxi = max(maxix(vacas,0),maxix(vacas,1));

    fout.open("herding.out");
    fout<<minimiza<<"\n"<<max(maximiza,otmaxi)<<"\n";

}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}