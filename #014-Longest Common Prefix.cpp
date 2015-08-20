#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*这道题是一个最长相同前缀匹配的题。
解题思路是，先对整个string数组预处理一下，求一个最小长度（最长前缀肯定不能大于最小长度）。
然后以第1个字符串作为参照，将最小长度作为初始长度，将最小长度的字符串作为初始字符串，从第二个字符串开始和第一个字符串进行匹配，
直到找到相同前缀停止，然后将最长前缀字符串lcprefix更新，最小长度minlen更新，i++，匹配下一个字符串。
*/
/*************************在leetcode上直接提交以下代码即可******************************/
struct sprefix{
	int length;
	string str;
};

bool comp(const sprefix &a, const sprefix &b)
{
	return a.length < b.length;
}
class Solution 
{
	public:
    string longestCommonPrefix(vector<string>& strs) 
    {
  		int num = strs.size();
  		//注意处理空字符串数组的情况
  		if(num == 0)
  			return "";
  		if(num == 1)
  			return strs[0];
  		vector<sprefix> strps;
  		sprefix temp_sp;
  		for(int i = 0; i < num; i++)
  		{
  			temp_sp.length = strs[i].length();
  			temp_sp.str = strs[i];
  			strps.push_back(temp_sp);
  		}
  		//根据字符串长度进行排序
  		sort(strps.begin(),strps.end(),comp);
  		//将最小长度作为初始长度
  		int minlen = strps[0].length;
  		//将最小长度的字符串作为初始字符串
  		string lcprefix = strps[0].str;
  		//从第二个字符串开始和第一个字符串进行匹配
  		for(int i = 1; i < num; i++)
  		{
  			//和第i个字符串进行匹配，直到找到相同前缀停止，然后将最长前缀字符串lcprefix更新，最小长度minlen更新，i++，匹配下一个字符串
  			while(lcprefix != strps[i].str.substr(0,minlen))
  			{
  				minlen--;
  				lcprefix = strps[0].str.substr(0,minlen);
  			}
  			if(lcprefix == "")
  				return lcprefix;
  		}

  		return lcprefix;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/

int main()
{
	int num = 0;
	cin >> num;
	vector<string> strs;
	string input_str;
	for(int i = 0; i < num; i++)
	{
		cin >> input_str;
		strs.push_back(input_str);
	}

	Solution solu;
	string lcp = solu.longestCommonPrefix(strs);
	cout << lcp << endl;
}
