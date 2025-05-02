#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define LSOne(S) ((S)&(-S))
#define all(S) S.begin(),S.end()
#define fore(V,I,F) for(int V=I;V<=F;V++)
typedef long long int ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

bool validate(string &orig, string &cad){
    int times = 0;
    for(int i=0;i<cad.size();i++){
        if(cad[i]!=orig[i])times++;
    }

    return times<=1;
}

void solve(){
    int n;
    cin>>n;
    vector<string> nums(n);

    fore(i,0,n-1)cin>>nums[i];

    string normal;
    cin>>normal;

    fore(i,0,n-1){
        if(validate(nums[i],normal))cout<<nums[i]<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    fore(i,1,t){
        cout<<"Case "<<i<<":\n";
        solve();
    }
}