//بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll int64_t
#define sp ' '
#define endl '\n'
using namespace std;

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
      x += 0x9e3779b97f4a7c15ULL;
      x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
      x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
      return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
      static const uint64_t FIXED_RANDOM =
          chrono::steady_clock::now().time_since_epoch().count();
      return splitmix64(x + FIXED_RANDOM);
  }
};

void solve ()
{
    ll x;cin>>x;
    vector<ll>vv(x),pre(x+1);
    for ( auto &x : vv)cin>>x;
    // for (int i = 1; i <= x; i++){
    //     pre[i] = pre[i-1] + vv[i-1];
    // }
    ll cnt=0;
    unordered_map<ll,ll,custom_hash>mp;
    mp[0]=1;
    ll sum=0;
    for (int i = 0; i < x; i++){
        sum+=vv[i];
        ll cla=(sum%x+x)%x;
        auto it=mp.find(cla);
        if (it!=mp.end())cnt+=mp[cla];
        mp[cla]++;
    }
    cout<<cnt<<endl;
}

int main ()
{
    speed;
    solve();
    return 0;
}