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
ll n,x;
vector<pair<ll,bool>>vv;
void solve ()
{

    // most important  and the most funnyest problem that i solve so far

    cin>>n>>x;
    // vv.resize(n);
    for (int i=0;i<n;i++){
        ll temp;cin>>temp;
        vv.push_back({temp,true});
    }
    sort(vv.begin(),vv.end());
    ll cnt=0;
    for (int i=0;i<n;i++){
        auto [val,flag]=vv[i];
        // cout<<val<<boolalpha<<flag<<endl;
        if (flag){
            // level1:
            ll need=x-val;
            ll ans=-1;
            ll l=0,r=n-1,index=-1;
            while (l<=r){
                ll mid=(l+r)/2;
                auto [val1,flag1]=vv[mid];
                if (val1<=need and flag1){
                    ans=val1;
                    index=mid;
                    l=mid+1;
                }else r=mid-1;
            }
            if (ans==-1){
                cnt++;
                vv[i].second=false;
            }else{
                // val+=ans;
                cnt++;
                vv[index].second=false;
                // goto level1;
            }
        }
    }
    cout<<cnt<<endl;
}

int main ()
{
    speed;
    solve();
    return 0;
}