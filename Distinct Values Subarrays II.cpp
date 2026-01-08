// بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
#define speed                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define ll int64_t
#define sp ' '
#define endl '\n'
using namespace std;
const ll N = 2e5 + 9;

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

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> vv(N);
    map<int,int>mp;
    for (int i = 1; i <= n; i++)
        cin >> vv[i];
    int l = 1, r = 1;
    ll ans = 0;
    bool flag=false;
    while (l <= n)
    {
        // cout<<l<<sp<<r<<endl;
        if (r<=n)
        mp[vv[r]]++;
        if (mp.size()<=k){
            if (r<=n)
            r++;
            else {
                ans+=r-l;
                mp[vv[l]]--;
                if (mp[vv[l]]==0)mp.erase(vv[l]);
                l++;
            }
            flag=true;
        }
        else{
            ans+=r-l;
            flag=false;
            mp[vv[l]]--;
            if (mp[vv[l]]==0)mp.erase(vv[l]);
            l++;
            // if (r<=n){
                mp[vv[r]]--;
                if (mp[vv[r]]==0)mp.erase(vv[r]);
            // }
            
        }

    }
    if (flag)ans+=r-l;
    cout<<ans<<endl;
}

int main()
{
    speed;
    solve();
    return 0;
}