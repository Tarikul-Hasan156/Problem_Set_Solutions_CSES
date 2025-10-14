//بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll int64_t
#define sp ' '
#define endl '\n'
using namespace std;
     
void solve ()
{
    ll x; cin>>x;
    vector<ll>vv(x);
    for (auto&x:vv)cin>>x;
    ll temp=INT_MIN, ans=INT_MIN;
    for (int i=0;i<x;i++){
        temp+=vv[i];
        temp=max(temp,vv[i]);
        ans=max(ans,temp);
    }
    cout<<ans<<endl;
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