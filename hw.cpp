#include <iostream> 
#include <vector>
const int INT_MAX = 2147483647;
std::vector<int> vi,wi;
int n,k;
int ans = INT_MAX;
void getval(int v,int w ,int index)
{
    if(index == n)
        return;
    if(v+vi[index] >= k)
    {
        ans = std::min(ans,w+wi[index]);
        getval(v,w,index+1);
        return;
    }
    getval(v+vi[index],w+wi[index],index+1);
    getval(v,w,index+1);  
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