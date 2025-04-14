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
 
int solve(int n){
    int sol = 0;
    int k;
    fore(i,1,n){
        cin>>k;
        if(k==0)sol--;
        else sol++;
    }
    return sol;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    int i=1;
    do{
        cin>>n;
        if(n==0)break;
        cout<<"Case "<<i<<": "<<solve(n)<<"\n";
        i++;
    }while(n!=0);
}