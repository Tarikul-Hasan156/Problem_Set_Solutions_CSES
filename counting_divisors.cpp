//بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll int64_t
#define sp " "
#define endl '\n'
using namespace std;
const ll N=1e6;
vector<ll>vv(N+1);
void solve ()
{
    ll x;cin>>x;
    cout<<vv[x]<<endl;
}
int main ()
{
    speed;
    for (int i=1;i<=N;i++){
        for (int j=i;j<=N;j+=i){
            vv[j]++;
        }
    }
    int tt;
    cin>>tt;
    while (tt--)
    {
        solve ();
    }
    return 0;
}