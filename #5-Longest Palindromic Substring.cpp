#include<iostream>
using namespace std;

////////////////////////////解题思路///////////////////////////////////////////////////////
/*这道题是经典的求最长回文子串的题。朴素算法很容易想到，但是时间复杂度是O(n^2)，会超时。这里使用的是manacher算法，时间复杂度可将为O(n)。
大家都知道,求回文串时需要判断其奇偶性,也就是求aba和abba的算法略有差距。然而,这个算法做了一个简单的处理,
很巧妙地把奇数长度回文串与偶数长度回文串统一考 虑,也就是在每个相邻的字符之间插入一个分隔符,串的首尾也要加,
当然这个分隔符不能 再原串中出现,一般可以用‘#’或者‘$’等字符。这样一来,原来的奇数长度回文串还是奇数长度,
偶数长度的也变成以‘#’为中心的奇数回文串了。
这里我们用一个辅助数组help记录以每个字符为中心的最长回文半径,也就是 help[i]记录以 s[i]字符为中心的最长回文串半径。
help[i]最小为 1,此时回文串为 s[i] 本身。
我们可以证明help[i]-1就是以s[i]为中心的回文串在原串当中的长度：首先help[i]记录的是扩展之后的字符串s[i]的最长回文串半径，
则对应其回文串长度应该是2*help[i]-1，而实际回文串长度若为a，则2*a+1 = 2*help[i]-1，因此得出a = help[i]-1。

之后依次从前往后求得help数组就可以了,这里用到了DP(动态规划)的思想,也就是求help[i]的时候,前面的help[]值已经得到了,
我们利用回文串的特殊性质可以进行一个大大的优化。为了防止求help[i]向两边扩展时可能数组越界,我们需要在数组最前面和最后面加一个特殊字符,
令 P[0]='$'最后位置默认为'\0'不需要特殊处理。此外,我们用MaxId变量记录在求i之前的回文串中,延伸至最右端的位置,同时用id记录取这个MaxId的id值。
通过下面这句话,算法避免了很多没必要的重复匹配。if(MaxId>i){help[i]=Min(help[2*id-i],MaxId-i);}
j=2*id-i即为i关于id的对称点,根据对称性,help[j]的回文串也是可以对称到i这边的,但是如果help[j]的回文串对称过来以后超过MaxId的话,
超出部分就不能对称过来了,所以这里 help[i]为的下限为两者中的较小者,help[i]=Min(p[2*id-i],MaxId-i)。
这样的话，在查找i的最长回文子串时就可以直接跳过help[i]个字符，再进行回文串的匹配，可以避免很多重复的比较。
*/
////////////////////////////解题思路///////////////////////////////////////////////////////

/*************************在leetcode上直接提交以下代码即可******************************/
#define MIN(x,y)  ((x)<(y)? (x):(y))

class Solution 
{
	public:
    string longestPalindrome(string s) 
    {
        int len = s.length();

        char *expand_s = new char[2*len + 3];
        expand_s[0] = '$';
        expand_s[1] = '#';
        int p = 0, q = 0;
        for(p=0,q=2; p < len; p++,q+=2)
		{
			expand_s[q] = s[p];
			expand_s[q+1] = '#';
		}
		expand_s[2*len + 2] = '\0';

		int *help = new int[2*len + 2];
		int maxid = 0, n = 2*len+2;
		int id, i;
		//求解辅助数组help
		for(i=1; i < n; i++)
		{
			if(maxid > i)
				help[i] = MIN(help[2*id-i],maxid-i);
			else
				help[i] = 1;

			for(;expand_s[i+help[i]] == expand_s[i-help[i]]; help[i]++);
			
			if(help[i]+i > maxid)
			{
				maxid = help[i] + i;
				id = i;
			}

		}
		//查找辅助数组的最大值，找到最长回文子串的长度以及其在串中的位置
		int max = 0, pos = 0;
		for(i=1; i<n; i++)
		{
			if(max < help[i])
			{
				max = help[i];
				pos = i;
			}
				
		}
		
		//找到了最长回文子串的长度和位置，再遍历得到原回文子串，跳过#字符
		char *lps = new char[max];

		for(int j = pos-max+1, k = 0; j <= pos+max-1; j++)
		{
			if(expand_s[j] != '#')
			{
				lps[k] = expand_s[j];
				k++;
			}
			
		}
		lps[max-1] = '\0';

		string lpstr = lps;

		return lpstr;


    }
};
/*************************在leetcode上直接提交以上代码即可******************************/

int main()
{
	string s;
	cin >> s;
	Solution solu;
	string lpstr = solu.longestPalindrome(s);

	cout << lpstr << endl;
}