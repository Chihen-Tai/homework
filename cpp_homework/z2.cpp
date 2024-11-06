#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    int n;
    string op;
    set<int> myset;
    cin>>n;
    long long sum=0;
    while(n--)
    {
        cin>>op;
        if(op=="insert")
        {
            int x;
            cin>>x;
            if(myset.find(x)!=myset.end())
            {
                continue;
            }
            sum+=x;
            myset.insert(x);
        }
        else if(op=="print")
        {
            if(myset.empty())
            {
                continue;
            }
            for(auto it=myset.begin();it!=myset.end();it++)
            {
                if(it==myset.begin())
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
            if(myset.empty())
            {
                continue;
            }
            cout<<*myset.begin()<<endl;
        }
        else if(op=="range_erase")
        {
            int l,r;
            cin>>l>>r;

            auto L=myset.lower_bound(l);
            auto R=myset.upper_bound(r);
            for(auto it=L;it!=R;it++)
            {
                sum-=*it;
            }
            myset.erase(L,R);
        }
        else if(op=="sum")
        {
            cout<<sum<<endl;
        }
    }
}