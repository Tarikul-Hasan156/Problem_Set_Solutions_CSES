//بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll int64_t
#define sp " "
#define endl '\n'
using namespace std;
     
void solve ()
{
    ll x,q;cin>>x>>q;
    vector<ll>vv(x);
    for (auto &x:vv)cin>>x;
    vector<ll>pre_xor(x+1);
    for (int i=1;i<=x;i++){
        pre_xor[i]=pre_xor[i-1]^vv[i-1];
    }
    while (q--){
        ll l,r;cin>>l>>r;
        cout<<(pre_xor[r]^pre_xor[l-1])<<endl;
    }
}
int main ()
{
    speed;
    // int tt;
    // cin>>tt;
    // while (tt--)
    // {
        solve ();
    // }
    return 0;
}