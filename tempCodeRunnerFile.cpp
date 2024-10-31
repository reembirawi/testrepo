#include <bits/stdc++.h>
using namespace std;
#define fs first
#define sec second
#define pii pair<int, int>
#define pdd pair<double, double>
#define ll long long
#define MOD 1000000007

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> v(n), mul(m + 1);
  vector<ll> add(n + 1);
  vector<array<int, 3>> a(m);

  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  for (int i = 0; i < m; i++) {
    int l, r, c;
    cin >> l >> r >> c;
    l--;

    a[i] = {l, r, c};
  }

  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    l--;

    mul[l]++, mul[r]--;
  }

  ll val = 0;
  for (int i = 0; i < m; i++) {
    val += mul[i];

    add[a[i][0]] += val * a[i][2];
    add[a[i][1]] -= val * a[i][2];
  }

  val = 0;
  for (int i = 0; i < n; i++) {
    val += add[i];
    cout << v[i] + val << " ";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}