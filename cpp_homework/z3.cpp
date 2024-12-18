#include <iostream>
#include <string>
#include <map>

using namespace std;;

bool isvowel(char c)
{
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}

int count_vowel(string s)
{
    int count=0;
    for(auto c:s)
    {
        if(isvowel(c))
        {
            count++;
        }
    }
    return count;
}

char last_vowel(string s)
{
    char last=' ';
    for(auto c:s)
    {
        if(isvowel(c))
        {
            last=c;
        }
    }
    return last;
}

int main()
{
    int n;
    string s;
    map<int,map<char,int>> words;
    cin>>n;
    while(n--)
    {
        cin>>s;
        words[count_vowel(s)][last_vowel(s)]++;
    }

    int pair_first=0;
    int pair_both=0;

    for(auto count:words)
    {
        int temp=0;
        for(auto last:count.second)
        {
            pair_both+=last.second/2;
            temp+=last.second%2;
        }
        pair_first+=temp/2;
    }

    int ans=min(pair_first,pair_both);
    int diff=pair_both-pair_first;
    if(diff>=2)
    {
        ans+=diff/2;
    }
    cout<<ans<<endl;
}