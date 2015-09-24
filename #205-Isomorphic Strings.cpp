#include<iostream>
using namespace std;
/*这道题有点和242题同字母异序词的方法类似。也是使用一个hash表来处理。
对于两个字符串s，t。首先hash数组初始化为0，然后对s进行遍历，如果对应hash[s[i]]为0，说明对应的hash值还未更新，那么就可以将其更新为t[i]进行标记。
在后续中s字符串中若出现了相同的字符，则直接可得到其对应的hash值，将该hash值和当前的t[i]进行比较，如果相等则继续遍历，如果不等则说明不满足要求，直接输出false。
这里对s进行了操作之后，还需要对t进行相同的操作，并且hash数组需要重新初始化为0。
之所以要这么做是因为可能出现s是ab，t是aa这样的情况，也就是说s出现的不同字符数比t多，这样更新hash数组的话会出现a和b对应的值都为a，这样还是会返回true，而事实上是false。
而如果换成对t遍历，则可以解决这个问题。
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
public:
    bool isIsomorphic(string s, string t) 
    {
       int lens = s.length();
       int lent = t.length(); 
       if(lens != lent)
       	return 0;
       int hash[256];
       memset(hash,0,sizeof(hash));
       for(int i = 0; i < lens; i++)
       {
       		if(hash[s[i]] == 0)
       			hash[s[i]] = t[i];
       		else
       		{
       			if(hash[s[i]] != t[i])
       				return 0;
       		}
       }
       memset(hash,0,sizeof(hash));
       for(int i = 0; i < lent; i++)
       {
       		if(hash[t[i]] == 0)
       			hash[t[i]] = s[i];
       		else
       		{
       			if(hash[t[i]] != s[i])
       				return 0;
       		}
       }

       return 1;

    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	string s, t;
	cin >> s;
	cin >> t;
	Solution solu;
	bool bo = solu.isIsomorphic(s,t);
	cout << bo << endl;
	return 0;
}