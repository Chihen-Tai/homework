#include <iostream>
using namespace std;
using ll=long long;

ll p[1000005];

int n;

ll solve();

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cout<<solve()<<endl;
    }
}

ll solve()
{
    ll total=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    for(int i=1;i<n;i++)
    {
        if(p[i]>p[i-1])
        {
            total+=(p[i]-p[i-1]);
        }
    }

    return total;
}