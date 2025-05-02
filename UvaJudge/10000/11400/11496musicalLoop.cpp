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

void solve(int n){
    vi nums(n);
    fore(i,0,n-1)cin>>nums[i];

    int sol = 0;
    fore(i,0,n-1){
        if(nums[i]>nums[(i+1)%n] && nums[i]>nums[(i-1+n)%n])sol++;
        if(nums[i]<nums[(i+1)%n] && nums[i]<nums[(i-1+n)%n])sol++;
    }
    cout<<sol<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    do{
        cin>>n;
        if(n==0)break;
        solve(n);
    }while(n!=0);
}