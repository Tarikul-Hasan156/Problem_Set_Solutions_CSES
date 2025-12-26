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
    unordered_map<ll,ll,custom_hash>mp;
    mp[0]=1;
    ll x,val;cin>>x>>val;
    vector<ll>vv(x),pre(x+1);
    // vector<pair<ll,ll>>pr(x+1);
    for (auto &x:vv)cin>>x;
    mp[0]=1;
   ll cnt=0,sum=0;
   for (int i=0;i<x;i++){
        sum+=vv[i];
        ll need=sum-val;
        auto it=mp.find(need);
        if (it!=mp.end())cnt+=mp[need];
        mp[sum]++;
   }
    // sort(pr.begin(),pr.end());
    // ll l=1,r=x;
    // for (auto[value,index]:pr){
    //     if (val==value){
    //         cnt++;
    //     }else if (value<val){
    //         continue;
    //     }else {
    //         ll need=value-val;
    //         ll l=1,r=x;
    //         ll ans=-1;
    //         while (l<=r){
    //             ll mid=(l+r)/2;
    //             if (need==pr[mid].first){
    //                 // cnt++;
    //                 // break;
    //                 if (pr[mid].second<index){
    //                     cnt++;
    //                     break;
    //                 }else{
    //                     r=mid-1;
    //                 }
    //             }else if (pr[mid].first>need){
    //                 r=mid-1;
    //             }else l=mid+1;
    //         }
    //     }
    // }
    cout<<cnt<<endl;
}

int main ()
{
    speed;
    solve();
    return 0;
}