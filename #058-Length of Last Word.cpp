#include<iostream>
using namespace std;
/*这道题非常简单，但要注意的是输入的时候，不能用cin，因为cin是以空格分开的。需要使用getline进行输入。
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
	public:
    int lengthOfLastWord(string s) 
    {
        int len = s.length();
        if(len == 0)
        	return 0;
        int lenoflw = 0;
        for(int i = len-1; i >= 0; i--)
        {
        	if(i == len-1)
        	{
        		while(s[i] == ' ')
        			i--;
        	}
        	
        	if(s[i] == ' ')
        		break;
        	else if((s[i] >= 97 && s[i] <=122) || (s[i] >= 65 && s[i] <= 90))
        		lenoflw++;
        	else
        		lenoflw = 0;
        }

        return lenoflw;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	string s;
	//cin >> s;
	getline(cin,s); 
	Solution solu;
	int len = solu.lengthOfLastWord(s);
	cout << len << endl;
}