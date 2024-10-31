#include <iostream>
#include <set>
#include <string>

int main()
{
    int n;
    std::string op;
    std::set<int> s;
    std::cin>>n;
    long long sum=0;
    while(n--)
    {
        std::cin>>op;
        if(op=="insert")
        {
            int x;
            std::cin>>x;
            if(s.find(x)!=s.end())
            {
                continue;
            }
            /*
            if(s.count(x)>0)
            {
                continue;
            }
            */
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
                    std::cout<<*it;
                }
                else
                {
                    std::cout<<" "<<*it;
                }
            }
            std::cout<<std::endl;
        }
        else if(op=="min")
        {
            if(s.empty())
            {
                continue;
            }
            std::cout<<*s.begin()<<std::endl;
        }
        else if(op=="range_erase")
        {
            int l,r;
            std::cin>>l>>r;

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
            std::cout<<sum<<std::endl;
        }
    }    
    
}