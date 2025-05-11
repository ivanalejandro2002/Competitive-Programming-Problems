#include <bits/stdc++.h>
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

void query(vi &number, string &s){
    while(number.size()<s.size()+1)number.push_back(0);
    bool carry = 0;
    for(int i=0;i<number.size();i++){
        if(i<s.size())number[i]+=s[i]-'0';
        number[i]+=carry;
        carry = 0;
        if(number[i]>9){
            carry = 1;
            number[i]-=10;
        }
    }
    if(carry)number.pb(1);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vi number;

    string s;
    do{
        cin>>s;
        reverse(all(s));
        query(number,s);
    }while(s!="0");
    bool checado = 0;
    for(int i=number.size()-1;i>=0;i--){
        if(number[i]==0 && !checado)continue;
        checado = 1;
        cout<<number[i];
    }
    if(!checado){
        cout<<"0\n";
    }else cout<<"\n";
}