#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*这是一道关于括号匹配的题，基本思路其实就是通过栈的思想来做，这里不仅使用stack实现，同时也通过vector来实现了栈的功能，一个个读取括号字符串中的字符，
然后在压入栈中判断即将加入栈中的字符与栈首的字符串是否是括号匹配，如果匹配则将栈首的字符退出栈，继续读取字符进行判断操作。
最后栈为空则说明括号全部匹配成功，返回1，否则返回0。
*/
/*************************在leetcode上直接提交以下代码即可******************************/
/*class Solution 
{
public:
    bool isValid(string s) 
    {
        vector<char> vchar;
        int len = s.length();
        for(int i = 0; i < len; i++)
        {
        	int size = vchar.size();
       		if(size != 0)
       		{
       			if(isCorrectorder(vchar[size - 1], s[i]))
       				vchar.pop_back();
       			else
       				vchar.push_back(s[i]);
       		}
       		else
       			vchar.push_back(s[i]);
        }

        if(vchar.size() == 0)
        	return 1;
        else
        	return 0;
    }

    bool isCorrectorder(char a, char b)
    {
    	if((a== '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']'))
    		return 1;
    	return 0;
    }
};*/
/*************************在leetcode上直接提交以上代码即可******************************/

/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
public:
    bool isValid(string s) 
    {
        stack<char> schar;
        int len = s.length();
        for(int i = 0; i < len; i++)
        {
          if(!schar.empty())
          {
            if(isCorrectorder(schar.top(), s[i]))
              schar.pop();
            else
              schar.push(s[i]);
          }
          else
            schar.push(s[i]);
        }

        if(schar.empty())
          return 1;
        else
          return 0;
    }

    bool isCorrectorder(char a, char b)
    {
      if((a== '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']'))
        return 1;
      return 0;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	string s;
	cin >> s;
	Solution solu;
	bool bo = solu.isValid(s);
	cout << bo << endl;
}