#include <iostream>
#include <string>
#include <map>
using namespace std;

// 看字元是否為母音
bool isVowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
//數字串s中有多少母音
int count_vowel(string s)
{
    int count = 0;
    for(auto c:s)
    {
        if(isVowel(c))
        {
            count++;
        }
    }
    return count;
}

char last_vowel(string s)
{
    char last =' ';
    for(auto c:s)
    {
        if(isVowel(c))
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
    map<int ,map<char,int>> words;//words[母音數][最後一個母音]=出現次數
    //map is like dictionary in python
    cin>>n;
    while(n--)
    {
        cin>>s;
        words[count_vowel(s)][last_vowel(s)]++;
        //first pair same number
        //second pair same number same last vowel
    }
    //這裡開始在仔細思考(畫圖)
    //pair_first:有相同數量的母音相同的lase_vowel(只能當first pair)
    //part_both:有相同數量的母音不同的lase_vowel(可以當first_pair,second pair)
    int pair_first=0,pair_both=0;
    for(auto count:words)//count : pair<int,map<char,int>>
    {
        //temp:有相同數量的母音不同的lase_vowel
        int temp=0;
        //count : pair<int,map<char,int>>
        for(auto last:count.second)//last : pair<char,int>
        {   
            //last.first :  他們的最後一個母音 char 都一樣 
            //last.second : 出現次數 int
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