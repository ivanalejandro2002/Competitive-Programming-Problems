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
typedef long long int ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

int solve(int n){
    string s;
    cin>>s;

    int antR=-1,antF = -1;
    int mejor = s.size();
    fore(i,0,s.size()-1){
        char co = s[i];
        if(co=='Z')mejor = 0;
        if(co=='R'){
            antR = i;
            if(antF>=0)mejor = min(mejor,i-antF);
        }else if(co=='D'){
            antF = i;
            if(antR>=0)mejor = min(mejor,i-antR);
        }
    }

    return mejor;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    do{
        cin>>n;
        if(n==0)break;
        cout<<solve(n)<<"\n";
    }while(n!=0);
}