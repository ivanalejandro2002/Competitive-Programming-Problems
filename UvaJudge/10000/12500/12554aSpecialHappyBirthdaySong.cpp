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
void solve(){
    vector<string> song = {
        "Happy",
        "birthday",
        "to",
        "you",
        "Happy",
        "birthday",
        "to",
        "you",
        "Happy",
        "birthday",
        "to",
        "Rujia",
        "Happy",
        "birthday",
        "to",
        "you"
    };
    int q = song.size();

    int n;
    cin>>n;
    int veces = (n+q-1)/q;
    vector<string> tipos(n);
    fore(i,0,n-1)cin>>tipos[i];

    fore(i,0,song.size()*veces-1){
        cout<<tipos[i%n]<<": "<<song[i%q]<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}