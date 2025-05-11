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

int kadaneAlgorithm(vector<int>& temp) {
    int rows = temp.size();
  int currSum = 0;
  int maxSum = INT_MIN;

  for (int i = 0; i < rows; i++) {
      currSum += temp[i];

      if (maxSum < currSum) {
          maxSum = currSum;
      }

      if (currSum < 0) {
          currSum = 0;
      }
  }

  return maxSum;
}

int maxSumRectangle(vector<vector<int>> &mat) {
  int rows = mat.size();
  int cols = mat[0].size();

  int maxSum = INT_MIN;

  vector<int> temp(rows);

  for (int left = 0; left < cols; left++) {
      for (int i = 0; i < rows; i++)
          temp[i] = 0;

      for (int right = left; right < cols; right++) {
          for (int row = 0; row < rows; row++) {
              temp[row] += mat[row][right];
          }

          int sum = kadaneAlgorithm(temp);

          maxSum = max(maxSum, sum);
      }
  }

  return maxSum;
}

int solve(){
    int n;
    cin>>n;
    vvi mat(n,vi(n));
    fore(i,0,n*n-1){
        cin>>mat[i/n][i%n];
    }
    return maxSumRectangle(mat);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cout<<solve()<<"\n";
}