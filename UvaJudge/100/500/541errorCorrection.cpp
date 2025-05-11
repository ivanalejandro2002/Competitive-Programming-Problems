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

void solve(int n){
    int k;

    vi contX(n+1);
    vi contY(n+1);

    fore(i,1,n){
        fore(j,1,n){
            cin>>k;
            if(k==1){
                contY[j]++;
                contX[i]++;
            }
        }
    }

    int cx,cy;
    cx = cy = 0;
    int apx,apy;
    apx = apy = 0;

    fore(i,1,n)if((contX[i] &1)){cx++;apy = i;}
    fore(i,1,n)if((contY[i] &1)){cy++;apx = i;}
    if(cx+cy==0){
        cout<<"OK\n";
        return;
    }
    if(cx==1 && cy==1){
        cout<<"Change bit ("<<apy<<","<<apx<<")\n";
        return;
    }
    cout<<"Corrupt\n";
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