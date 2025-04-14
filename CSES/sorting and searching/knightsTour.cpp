#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define LSOne(S) ((S)&(-S))
#define all(S) S.begin(),S.end()
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
vvi mapa = {
    {0,0 ,0 ,0 ,0 , 0 , 0 , 0 , 0 },
    {0,63,14,37,24,	51,	26,	35,	10},
    {0,22,39,62,13,	36,	11,	50,	27},
    {0,15,64,23,38,	25,	52,	 9,	34},
    {0,40,21,16,61,	12,	33,	28,	49},
    {0,17,60, 1,44,	29,	48,	53,	 8},
    {0,2 ,41,20,57,	 6,	55,	32,	47},
    {0,59,18,43, 4,	45,	30,	 7,	54},
    {0,42, 3,58,19,	56,	 5,	46,	31}
};
void solve(){
    int x,y;
    cin>>x>>y;
    int inicio = mapa[y][x];

    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            cout<<((mapa[i][j]-inicio)+64)%64+1<<" ";
        }
        cout<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}