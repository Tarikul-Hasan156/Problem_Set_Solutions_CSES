//بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll int64_t
#define sp ' '
#define endl '\n'
using namespace std;
const ll N=2e5+9;

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
    vector<int>vv(N);
    int n;cin>>n;
    for (int i=1;i<=n;i++)cin>>vv[i];
    unordered_map<int,int,custom_hash>mp;
    mp[vv[1]]++;
    int l=1,r=2;
    ll ans=1,temp=1;
    while (l<=n and r<=n){
        if (mp[vv[r]]==0){
            // cout<<vv[r]<<endl;
            // temp++;
            mp[vv[r]]++;r++;
        }else{
            ans=max(ans,(ll)r-l);
            // cout<<vv[l]<<endl;
            mp.erase(vv[l]);
            l++;

        }
    }
    cout<<max(ans,(ll)r-l)<<endl;
}

int main ()
{
    speed;
    solve();
    return 0;
}