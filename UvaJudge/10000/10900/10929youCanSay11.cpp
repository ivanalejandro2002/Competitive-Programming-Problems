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

bool query(string &s){
    if(s.size()<2)return false;
    
    int carry = s[0]-'0';
    fore(i,1,s.size()-1){
        if(s[i]-'0' >=carry){
            carry = s[i]-'0' - carry;
        }else{
            carry = 10+s[i]-'0'-(carry-1);
        }
    }
    return carry == 0;
}
void solve(string &s){
    bool sol = query(s);
    (sol)?cout<<s<<" is a multiple of "<<11<<".\n":cout<<s<<" is not a multiple of "<<11<<".\n";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    do{
        cin>>s;
        if(s=="0")break;
        solve(s);
    }while(s!="0");
}