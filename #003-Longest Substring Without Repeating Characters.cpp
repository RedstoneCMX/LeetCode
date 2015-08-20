#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

////////////////////////////解题思路///////////////////////////////////////////////////////
/*这道题是考查字符串操作的题。在本题中，其实使用hash的方法就完全可以做到时间复杂度O(n)，并没有网上一些解题方法那么复杂，
当然使用动态规划应该也是一种方法，只是我还没有研究。
1.本题中，需要查找最长不重复子串，使用一个hash数组存储出现过的字符在s串中的位置，初始都为-1。此外使用两个指针，
start和end记录当前判断的子串的开始和结束，初始都为0。还需要初始length和maxlength的值为0，分别用于记录当前判断子串长度和最长不重复子串长度。
2.之后便从end=0开始遍历整个s串，读取end位置处的字符，判断其是否在当前判断的子串中，如果不在则将hash数组中对应位置的值修改成end，end指针加1，
向右移一位继续判断，如果在当前判断的子串中，则计算start和end的距离，就是当前判断的子串的最长不重复长度了，和maxlength比较，更新maxlength。
同时将start指针移至重复的那个字符所在位置的后一位，继续end加1进行判断。
3.这里需要注意的是在判断至最后一个字符时，则直接计算当前子串的长度，通过strlength-start进行计算，然后和maxlength比较，更新maxlength。
4.2中提及的判断end位置处的字符是否在当前判断的子串中，这里是根据hash[tempchar] < start来判断，tempchar表示end处的字符，之所以这么判断是因为：
小于start说明在当前记录的子串中并未出现，这里不能只判断hash值为-1的情况，因为hash值可能是记录之前的子串时记录的出现过的字符位置，在当前子串实际并未出现。
*/
////////////////////////////解题思路///////////////////////////////////////////////////////

/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
	public:
    int lengthOfLongestSubstring(string s) 
    {
        int length = 0, maxlength = 0;
        int hash[256];
        int start = 0;
        int strlength = s.length();
        //hash存储出现的字符在s串中的位置，初始全为-1
        memset(hash,-1,sizeof(hash));
        //遍历字符串s，查找最长不重复子串，只需要遍历一次，时间复杂度O(n)
       	for(int end = 0; end < strlength; end++)
       	{
          //判断当前字符
       		char tempchar = s[end];
          //判断该字符对应的hash是否小于start，小于start说明在当前记录的子串中并未出现，这里不能只判断hash值为-1的情况，
          //因为hash值可能是记录之前的子串时记录出现字符的位置，在当前子串实际并未出现。
       		if(hash[tempchar] < start)
       		{
            //在当前判断的子串中并未出现当前字符，因此将其位置记录在hash中，表示该字符已经在当前判断的子串中出现过了
       			hash[tempchar] = end;
            //如果已经判断至最后一个字符，则直接计算当前判断的子串的长度
       			if(end == strlength - 1)
       			{
       				length = strlength - start;
       				if(length > maxlength)
       					maxlength = length;
       			}
       		}
          //如果该字符对应的hash大于等于start，说明该字符在当前判断的子串中已经出现过，则当前判断的不重复子串已达最长，
          //则计算其长度，和maxlength进行比较，更新maxlength
       		else
       		{
       			length = end - start;
       			if(length > maxlength)
       				maxlength = length;
       			start = hash[tempchar] + 1;
       			hash[tempchar] = end;
       		}

       	}    
        return maxlength;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/

int main()
{
	string str;
	cin >> str;

	int length = 0;
	Solution solu;
	length = solu.lengthOfLongestSubstring(str);

	cout << str << endl;
	cout << length << endl;

}