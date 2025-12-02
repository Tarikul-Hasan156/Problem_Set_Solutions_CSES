//بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll int64_t
#define sp ' '
#define endl '\n'
using namespace std;

// struct custom_hash {
//   static uint64_t splitmix64(uint64_t x) {
//       x += 0x9e3779b97f4a7c15ULL;
//       x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
//       x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
//       return x ^ (x >> 31);
//   }
//
//   size_t operator()(uint64_t x) const {
//       static const uint64_t FIXED_RANDOM =
//           chrono::steady_clock::now().time_since_epoch().count();
//       return splitmix64(x + FIXED_RANDOM);
//   }
// };

void solve ()
{
    ll x;cin>>x;
    vector<pair<ll,ll>>pr;
    for (int i=0;i<x;i++){
        ll temp1,temp2;cin>>temp1>>temp2;
        pr.push_back({temp1,temp2});
    }
    sort(pr.begin(),pr.end(),[](const pair<ll,ll>&a, const pair<ll,ll>&b){
        if (a.first!=b.first)return a.first<b.first;
        return a.second>b.second;
    });
    ll finish=0;
    ll ans=0;
    for(auto [duration,dead]:pr){
        finish+=duration;
        ans+=dead-finish;
    }
    cout<<ans<<endl; 
}

int main ()
{
    speed;
    // int tt;
    // cin >> tt;
    // while (tt--)
    // {
        solve();
    // }
    return 0;
}