#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;
//也可以用map<string,int>來存字串和出現次數
struct cmp
{
    bool operator()(const string &a, const string &b) const
    {
        if (a.size() != b.size())
        {
            return a.size() < b.size();
        }
        return a < b;
    }
    // a,b true b,a false
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    multiset<string,cmp> mst; // can store duplicate(同樣的) elements
    vector<string> v;
    int n;
    cin >> n;
    string op;
    int idx;
    string s;
    while (n--)
    {
        cin>>op;
        if(op=="insert")
        {
            cin>>s;
            mst.insert(s);
            v.push_back(s);
        }
        else if(op=="min")
        {
            if(!mst.empty())
            {
                cout<<*mst.begin()<<endl;
            }
        }
        else if(op=="max")
        {
            if(!mst.empty())
            {
                cout<<*(--mst.end())<<endl;//end is the iterator to the element after the last element
            }
        }
        else if(op=="find")
        {
            cin>>idx;
            if(idx<v.size())
            {
                cout<<v[idx-1]<<endl;
            }
        }
        else if(op=="amount")
        {
            cin>>s;
            cout<<mst.count(s)<<endl;
        }
    }

    return 0;
}