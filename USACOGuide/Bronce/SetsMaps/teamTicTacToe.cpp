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

bool gana(vector<string> &gato,char X,char Y){
    
    for(int i=0;i<3;i++){
        bool hecho = 1;
        for(int j=0;j<3;j++){
            if(gato[i][j]!=X && gato[i][j]!=Y)hecho=0;
        }
        if(hecho)return true;
        hecho = 1;
        for(int j=0;j<3;j++){
            if(gato[j][i]!=X && gato[j][i]!=Y)hecho=0;
        }
        if(hecho)return true;
    }
    bool hecho = 1;
    for(int i=0;i<3;i++){
        if(gato[i][i]!=X && gato[i][i]!=Y)hecho=0;
    }
    if(hecho)return true;
    
    hecho = 1;
    for(int i=0;i<3;i++){
        if(gato[i][2-i]!=X && gato[i][2-i]!=Y)hecho=0;
    }
    if(hecho)return true;
    return false;
}

bool ganan(vector<string> &gato,char X,char Y){
    
    for(int i=0;i<3;i++){
        bool hecho = 1;
        for(int j=0;j<3;j++){
            if(gato[i][j]!=X && gato[i][j]!=Y)hecho=0;
        }
        if(gato[i][0] == gato[i][1] && gato[i][1]==gato[i][2])hecho=0;
        if(hecho)return true;
        hecho = 1;
        for(int j=0;j<3;j++){
            if(gato[j][i]!=X && gato[j][i]!=Y)hecho=0;
        }
        if(gato[0][i] == gato[1][i] && gato[1][i]==gato[2][i])hecho=0;
        if(hecho)return true;
    }
    bool hecho = 1;
    for(int i=0;i<3;i++){
        if(gato[i][i]!=X && gato[i][i]!=Y)hecho=0;
    }
    if(gato[0][0] == gato[1][1] && gato[1][1]==gato[2][2])hecho=0;
    if(hecho)return true;
    
    hecho = 1;
    for(int i=0;i<3;i++){
        if(gato[i][2-i]!=X && gato[i][2-i]!=Y)hecho=0;
    }
    if(gato[0][2] == gato[1][1] && gato[1][1]==gato[2][0])hecho=0;
    if(hecho)return true;
    return false;
}
void solve(){
    int n,m,k;
    ifstream fin;
    fin.open("tttt.in");
    ofstream fout;
    fout.open("tttt.out");
    vector<string> gato(3);
    fore(i,0,2)fin>>gato[i];
    int solo = 0;
    int equipo = 0;
    
    for(char co= 'A';co<='Z';co++){
        bool s = gana(gato,co,'@');
        solo+=s;
    }
    for(char co='A';co<='Z';co++){
        for(char ca=co+1;ca<='Z';ca++){
            bool s =ganan(gato,co,ca);
            /*if(s){
                cout<<co<<","<<ca<<"\n";
            }*/
            equipo+=s;
        }
    }
    fout<<solo<<"\n"<<equipo<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}