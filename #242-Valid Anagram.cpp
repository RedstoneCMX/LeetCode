#include<iostream>
using namespace std;
/*这道题使用hash是非常简单的，而且时间复杂度为O(n)。
首先既然题目已经明说了只有小写字母，那么就定义一个hash表，长度是26，初始全为0，然后遍历第一个字符串，并更新hash表的值，
从i = 0开始，hash[s[i]-97]++。然后遍历第二个字符串t，hash[t[i]-97]--。
两个字符串都遍历完之后，hash表也更新完了，如果两个字符串是同字母异序词，那么最终hash表的值肯定还都是0。
那么只需要遍历这个hash表，只要出现了值不为0的情况就返回0，说明就不是同字母异序词。否则则返回1。
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
public:
    bool isAnagram(string s, string t) 
    {
    	int lens = s.length();
    	int lent = t.length();
    	if(lens != lent)
    		return 0;
        int hash[26];
        memset(hash,0,sizeof(hash));
        for(int i = 0; i < lens; i++)
        	hash[s[i]-97]++;
        for(int i = 0; i < lent; i++)
        	hash[t[i]-97]--;
        for(int i = 0; i < 26; i++)
        	if(hash[i] != 0)
        		return 0;
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
	bool bo = solu.isAnagram(s,t);
	cout << bo << endl;
	return 0;
}