#include <iostream>
#include <set>
#include <string>

using namespace std;
int main()
{
    int n;
    string op;
    set<int> s;
    cin>>n;
    long long sum =0;
    while(n--)
    {
        cin>>op;
        if(op=="insert")
        {
            int x;
            cin>>x;
            if(s.find(x)!=s.end())
            {
                continue;
            }
            sum+=x;
            s.insert(x);
        }
        else if(op=="print")
        {
            if(s.empty())
            {
                continue;
            }
            for(auto it=s.begin();it!=s.end();it++)
            {
                if(it==s.begin())
                {
                    cout<<*it;
                }
                else
                {
                    cout<<" "<<*it;
                }
                cout<<endl;
            }
        }
        else if(op=="min")
        {
            if(s.empty())
            {
                continue;
            }
            cout<<*s.begin()<<endl;
        }
        else if(op=="range_erase")
        {
            int l,r;
            cin>>l>>r;
            auto L=s.lower_bound(l);
            auto R=s.upper_bound(r);
            for(auto it=L;it!=R;it++)
            {
                sum-=*it;
            }
            s.erase(L,R);
        }
        else if(op=="sum")
        {
            cout<<sum<<endl;
        }
    }
}