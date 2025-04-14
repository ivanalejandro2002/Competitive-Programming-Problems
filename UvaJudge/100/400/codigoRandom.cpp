#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/// la suma se puede pasar

const ll maxn = 100005;
ll n;
string s[maxn];
string t[maxn];
ll p[maxn];
ll a[maxn];

ll bit[maxn][2];

void update(ll pos, ll val, ll tipo){
    for(ll i = pos; i <= 100000; i+= i & (-i)){
        bit[i][tipo]+= val;
    }
}

ll q(ll pos, ll tipo){
    ll sum = 0;
    for(ll i = pos; i > 0; i -= i & (-i)){
        sum+= bit[i][tipo];
    }
    return sum;
}

ll query(ll L, ll R, ll tipo){
    return q(R, tipo) - q(L - 1, tipo);
}

priority_queue<pair<ll, ll> > sell; /// menor a mayor
priority_queue<pair<ll, ll> > buy;

vector<tuple<ll, ll, ll> > ans;

void simular(){
    while(1){
        if(sell.size() == 0 || buy.size() == 0) break;
        pair<ll, ll> se = sell.top(); sell.pop();
        pair<ll, ll> bu = buy.top(); buy.pop();
        se.first*=-1; se.second*=-1;
        bu.second*=-1;
        if(se.first < bu.first){
            /// a ambos les quito el minimo
            ll quito = min(a[se.second], a[bu.second]);
            ans.push_back({se.second, bu.second, quito});
            update(se.second, -quito, 0);
            update(bu.second, -quito, 1);


            a[se.second]-= quito;
            a[bu.second]-= quito;
            if(a[se.second] > 0){
                sell.push({-p[se.second], -se.second}); /// siempre quiero el de indice menor
            }
            if(a[bu.second] > 0){
                buy.push({p[bu.second], -bu.second});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    map<ll, ll> mp;
    vector<ll> aux;
    ll sig = 0;
    for(ll i = 1; i <= n; ++i){
        cin >> s[i] >> t[i] >> p[i] >> a[i];
        aux.push_back(p[i]);
    }
    sort(aux.begin(), aux.end());
    for(ll v: aux){
        if(mp[v] == 0) mp[v] = ++sig;
    }
    for(ll i = 1; i <= n; ++i){
        p[i] = mp[p[i]];
    }
    /// hasta aca ya esta bien

    for(ll i = 1; i <= n; ++i){
        bool meto = true;
        if(t[i] == "normal"){
            if(s[i] == "sell"){
                sell.push({-p[i], -i}); /// siempre quiero el de indice menor
                update(p[i], a[i], 0);
            }else{
                buy.push({p[i], -i});
                update(p[i], a[i], 1);
            }
            simular();
        }else{
            if(t[i] == "fok"){
                ll aux;
                if(s[i] == "buy"){
                    aux = query(1, p[i], 0);
                }else{
                    aux = query(p[i], 100000, 1);
                }
                if(aux >= a[i]){
                    /// entonces aqui si se wpuede simular
                    while(a[i] > 0){
                        if(s[i] == "buy"){
                            pair<ll, ll> se = sell.top(); sell.pop();
                            se.first*=-1; se.second*=-1;
                            ll quito = min(a[se.second], a[i]);
                            ans.push_back({se.second, i, quito});

                            update(se.second, -quito, 0);
                            a[se.second]-= quito;
                            a[i]-= quito;

                            if(a[se.second] > 0){
                                sell.push({-p[se.second], -se.second}); /// siempre quiero el de indice menor
                            }
                        }else{
                            pair<ll, ll> bu = buy.top(); buy.pop();
                            bu.second*=-1;
                            ll quito = min(a[bu.second], a[i]);
                            ans.push_back({i, bu.second, quito});
                            update(bu.second, -quito, 0);
                            a[bu.second]-= quito;
                            a[i]-= quito;

                            if(a[bu.second] > 0){
                                buy.push({p[bu.second], -bu.second});
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans.size() << "\n";
    for(auto [u, v, k] : ans){
        cout << u << ' ' << v << ' ' << k << "\n";
    }
    return 0;
}