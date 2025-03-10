#include <iostream>
#include <vector>

std::vector<int> vi,wi;
int n,k;
int stolen(int index,int w,int v)
{
    if(index == n)
        return v;
    int item1=stolen(index+1,w,v);
    int item2 = (w >= wi[index]) ? stolen(index+1,w-wi[index],v+vi[index]) : v;
    return std::max(item1,item2);
}
int main()
{
    std::cin >> n >> k;
    vi.resize(n);
    wi.resize(n);
    for(int i=0;i<n;i++)
    {
        std::cin >> vi[i] >> wi[i];
    }
    int ans = stolen(0,k,0);
    std::cout << ans << "\n";
}