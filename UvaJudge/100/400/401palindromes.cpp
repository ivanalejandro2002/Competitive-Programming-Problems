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

string solve(string s,map<char,char> &mirror){
    bool palindrome = 1;
    bool mirrored = 1;

    for(int i=0;i<s.size();i++){
        if(s[s.size()-i-1]!=s[i])palindrome = 0;
    }

    for(int i=0;i<s.size();i++){
        if(s[s.size()-i-1]!=mirror[s[i]])mirrored = 0;
    }

    if(palindrome && mirrored)return "is a mirrored palindrome";
    if(!palindrome && !mirrored)return "is not a palindrome";
    if(palindrome)return "is a regular palindrome";
    return "is a mirrored string";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    map<char,char> mirror;
    mirror['A'] = 'A';
    mirror['E'] = '3';
    mirror['H'] = 'H';
    mirror['I'] = 'I';
    mirror['J'] = 'L';
    mirror['L'] = 'J';
    mirror['M'] = 'M';
    mirror['O'] = 'O';
    mirror['S'] = '2';
    mirror['2'] = 'S';
    mirror['T'] = 'T';
    mirror['U'] = 'U';
    mirror['V'] = 'V';
    mirror['W'] = 'W';
    mirror['X'] = 'X';
    mirror['Y'] = 'Y';
    mirror['Z'] = '5';
    mirror['1'] = '1';
    mirror['2'] = 'S';
    mirror['3'] = 'E';
    mirror['5'] = 'Z';
    mirror['8'] = '8';
    while(cin>>s){
        cout<<s<<" -- "<<solve(s,mirror)<<".\n\n";
    }
}