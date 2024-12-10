#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct cmp
{
    bool operator()(const string &a,const string &b) const
    {
        if(a.size()!=b.size())
        {
            return a.size()<b.size();
        }
        return a<b;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    multiset<string,cmp> mst;
    vector<string> v;
    int n;
    cin>>n;
    string op;
    int idx;
    string s;
    while(n--)
    {
        cin>>op;
        if(op=="insert")
        {
            cin>>s;
            mst.insert(s);
            v.push_back(s);
        }
        if(op=="min")
        {
            if(!mst.empty())
            {
                cout<<*mst.begin()<<endl;
            }
        }
        if(op=="max")
        {
            if(!mst.empty())
            {
                cout<<*(--mst.end())<<endl;
            }
        }
        if(op=="find")
        {
            cin>>idx;
            if(idx<v.size())
            {
                cout<<v[idx-1]<<endl;
            }
        }
        if(op=="amount")
        {
            cin>>s;
            cout<<mst.count(s)<<endl;
        }
    }
    return 0;
}