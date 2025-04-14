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

void solve(string &cad,map<char,char> &cambios){
    for(char co:cad){
        cout<<cambios[co];
    }
    cout<<"\n";
    
}
int main(){
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    map<char,char> cambios;
    cambios['1'] = '`';
    cambios['2'] = '1';
    cambios['3'] = '2';
    cambios['4'] = '3';
    cambios['5'] = '4';
    cambios['6'] = '5';
    cambios['7'] = '6';
    cambios['8'] = '7';
    cambios['9'] = '8';
    cambios['0'] = '9';
    cambios['-'] = '0';
    cambios['='] = '-';

    cambios['W'] = 'Q';
    cambios['E'] = 'W';
    cambios['R'] = 'E';
    cambios['T'] = 'R';
    cambios['Y'] = 'T';
    cambios['U'] = 'Y';
    cambios['I'] = 'U';
    cambios['O'] = 'I';
    cambios['P'] = 'O';
    cambios['['] = 'P';
    cambios[']'] = '[';
    cambios['\\'] = ']';

    cambios['S'] = 'A';
    cambios['D'] = 'S';
    cambios['F'] = 'D';
    cambios['G'] = 'F';
    cambios['H'] = 'G';
    cambios['J'] = 'H';
    cambios['K'] = 'J';
    cambios['L'] = 'K';
    cambios[';'] = 'L';
    cambios[(char)39] = ';';

    cambios['X'] = 'Z';
    cambios['C'] = 'X';
    cambios['V'] = 'C';
    cambios['B'] = 'V';
    cambios['N'] = 'B';
    cambios['M'] = 'N';
    cambios[','] = 'M';
    cambios['.'] = ',';
    cambios['/'] = '.';
    cambios[' '] = ' ';
    string s;
    while(getline(cin,s)){
        solve(s,cambios);
    }
}