#include <iostream>
using namespace std;
using ll=long long;
const int MAX_N=1000005;
ll p[MAX_N];
int n;
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
            total+=p[i]-p[i-1];
        }
    }

    return total;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cout<<solve()<<endl;
    }
}