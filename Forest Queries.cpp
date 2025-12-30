//بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll int64_t
#define sp ' '
#define endl '\n'
using namespace std;
const ll N=1e3+9;

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
vector<vector<ll>>vv(N,vector<ll>(N)),pre(N,vector<ll>(N));
ll n,q;
void solve ()
{
    cin>>n>>q;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            char ch;cin>>ch;
            if (ch=='.')vv[i][j]=0;
            else vv[i][j]=1;
        }
    }
    // for (int i=1;i<=n;i++){
    //     for (int j=1;j<=n;j++){
    //         cout<<vv[i][j]<<sp;
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            pre[i][j]=pre[i][j-1]+pre[i-1][j]-pre[i-1][j-1]+vv[i][j];
            // cout<<pre[i][j]<<sp;
        }
        // cout<<endl;
    }
    while (q--){
        int x1,x2,y1,y2;cin>>x1>>y1>>x2>>y2;
        // cout<<pre[x2][y2]<<endl;
        cout<<pre[x2][y2]-pre[x2][y1-1]-pre[x1-1][y2]+pre[x1-1][y1-1]<<endl;
    }
}

int main ()
{
    speed;
    solve();
    return 0;
}