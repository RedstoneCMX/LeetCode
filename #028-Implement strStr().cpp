#include<iostream>
using namespace std;
/*这道题是典型的模式串匹配的题，主要有两种解法，一种是暴力求解，直接从原串第一个字符开始和模式串第一个字符匹配，
匹配成功则原串第二个字符与模式串第二个字符匹配，如果匹配失败则将原串第二个字符串与模式串第二个字符匹配，依次进行下去。时间复杂度是O(mn)
另外一种高效的算法就是KMP算法。
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
	public:
    int strStr(string haystack, string needle) 
    {
        int len = haystack.length();
        int len_need = needle.length();
        if(len_need == 0)
        	return 0;
        if(len == 0 || len < len_need)
        	return -1;
        for(int i = 0; i < len; i++)
        {
        	string substr = haystack.substr(i,len_need);
        	if(substr == needle)
        		return i;
        }

        return -1;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	string haystack, needle;

	cout << "输入原串: " << endl;
	cin >> haystack;
	cout << "输入需要查找的字符串: " << endl;
	cin >> needle;
	Solution solu;
	int index = solu.strStr(haystack,needle);
	cout << index << endl;
}