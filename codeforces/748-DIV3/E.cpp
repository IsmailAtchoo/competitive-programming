#include <bits/stdc++.h>
#include <cstring>
 
#define F first
#define S second
#define pb push_back
#define pf push_front
#define popf pop_front
#define popb pop_back
#define MOD 1000000007
#define MOD2 998244353
#define vi vector<int>
#define vii vector<pair<int,int>>
#define pi pair<int,int>
 
using namespace std;
#define ll long long
int const MAX5 = 100000, MAX6 = 1000000;
/*

- leafs have deg = 1 => they can be defined by their neighbor
- the last node(s) ??


 jsut implemented te solution for this one even though it was Ez (sad noises)
 
*/
//printf("%.10lf\n",ans);
//cout<<fixed<<setprecision(20)<<ans<<endl;
//stoll string -> long long

void solve(){
  int n, k; cin >> n >> k;
  int u, v;
  int rem[n], layer[n];
  vi tree[n];
  queue<int> q;
  memset(rem, 0, sizeof(rem));
  memset(layer, 0, sizeof(layer));
  
  for(int i = 0; i < n-1; i++){
    cin >> u >> v;
    u--, v--;
    tree[u].pb(v);
    tree[v].pb(u);
    rem[u]++, rem[v]++;
  }

  for(int i = 0; i < n; i++)
    if(rem[i] == 1) q.push(i), layer[i] = 1;

  int curv;
  while(!q.empty()){
    curv = q.front();
    q.pop();

    for(auto neighv : tree[curv]){
      if(rem[neighv] != 1){
        rem[neighv]--;
        if(rem[neighv] == 1){
          layer[neighv] = layer[curv] + 1;
          q.push(neighv);
        }
      }
    }

  }

  int ans = 0;
  for(int i = 0; i < n; i++) ans += (layer[i] > k);
  cout << ans << endl;


}

int main(){
  // in & out files
  /*
  freopen("outofplace.in", "r", stdin);
  freopen("outofplace.out", "w", stdout);
*/
  // fast and furious io
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

// testcases
  int t = 1; cin >> t;
  while(t--){
    solve();
  }
  return 0;

}


