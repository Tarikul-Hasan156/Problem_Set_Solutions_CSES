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

//   size_t operator()(uint64_t x) const {
//       static const uint64_t FIXED_RANDOM =
//           chrono::steady_clock::now().time_since_epoch().count();
//       return splitmix64(x + FIXED_RANDOM);
//   }
// };

void solve ()
{
    ll n,target;cin>>n>>target;
    vector<pair<ll,ll>>pr;
    pr.push_back({0,0});
    for (int i=1;i<=n;i++){
        ll temp;cin>>temp;
        pr.push_back({temp,i});
    }
    sort(pr.begin(),pr.end());
    for(int i=1;i<=n;i++){
        ll val=target-pr[i].first;
        if (val<0)continue;
        ll l=1,r=n;
        while (l<=r){
            ll mid=(l+r)/2;
            if (pr[mid].first==val and pr[i].second!=pr[mid].second){
                cout<<pr[i].second<<sp<<pr[mid].second<<endl;
                return;
            }else if (pr[mid].first<val){
                l=mid+1;
            }else r=mid-1;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
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