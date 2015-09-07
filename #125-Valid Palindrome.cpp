#include<iostream>
using namespace std;
/*这个题主要就是判断回文串，但是是有干扰字符的回文串，如果先对字符串进行预处理，除去非字母数字的话会出现超时，
因为字符串可能会很长，而实际上它并不是回文串。因此不能对其进行预处理，应该直接对其进行操作，从头部尾部往中间查找匹配，非字母数字的跳过。

*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
	public:
    bool isPalindrome(string s) 
    {
        if(s== "")
            return 1;
        int i = 0, j = s.length() - 1;
        while(i<j) 
        {  
            while( !isValid(s[i]) && i<j) i++;  
            while( !isValid(s[j]) && i<j) j--;  
            if(i>=j) break;  
            if( s[i] != s[j] ) return false;  
            else 
            {  
                i++;  
                j--;  
            }  
        }

        return true;  
    }

    bool isValid( char & c) 
    {   
        if( c>='0' && c<='9' ) 
            return true;  
        if( c>='a' && c<='z' ) 
            return true;  
        if( c>='A' && c<='Z' ) 
        {
            c = c + 32;
            return true;
        }  
        return false;  
    }  
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	string s;
	getline(cin,s);
	Solution solu;
	bool bo = solu.isPalindrome(s);
	cout << bo << endl;
}