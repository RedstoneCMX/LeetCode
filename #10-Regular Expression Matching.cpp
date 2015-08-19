#include<iostream>
using namespace std;

/*这个题是一个关于正则表达式匹配的问题，这里只是匹配'.'和'*'两种通配符。解题思路主要是递归，其实就是DFS，深度优先搜索的思想。
根据下一个字符是否是'*'分情况判断。
1.如果是p的下一个'*'，则当前s和p相等或者p='.'情况下，依次判断s和p[2]之后的字符串是否match；
2.如果p的下一个字符不是'*'，只需判断当前字符是否相等，或者p[cur]='.'且s不为空，递归处理s[1]和p[1]之后的字符串；

这里需要注意的一个地方是，题目中的测试用例中，isMatch("ab", ".*") → true，这里可能会产生困惑，其实这里".*"，'*'是用来作用于'.'，
意思是说可以有0个或多个'.'，而'.'可以匹配任意单个字符。因此"ab"一定是匹配".*"的。
*/

/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
public:
    bool isMatch(string s, string p) {  
        
        if(p == "")
        	return s == "";

        if (p[1] == '*') // 模式串的下一个字符是'*'  
        {  
            while(p[0] == s[0] || (p[0] == '.' && s != ""))  
            {  
                //字符串与模式串匹配0/1/2...个字符的情况  
                if (isMatch(s, p.substr(2)))  
                    return true;  
                s = s.substr(1);
            }  
            //字符串与模式串不能匹配  
            return isMatch(s, p.substr(2));  
        }  
        else  
        {  
            if (p[0] == s[0] || (p[0] == '.' && s != "")) 
                return isMatch(s.substr(1), p.substr(1));  
            return false;  
        }  
    } 
};
/*************************在leetcode上直接提交以上代码即可******************************/

int main()
{
	string s, p;
	cin >> s;
	cin >> p;
	Solution solu;
	bool bo = solu.isMatch(s,p);

	cout << bo << endl;
}
