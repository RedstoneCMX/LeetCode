#include<iostream>
using namespace std;
/*这道题是罗马数字转阿拉伯数字
*/

/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
	public:
    int romanToInt(string s) 
    {
    	string roman = "IVXLCDM";
     	int value[] = {1,5,10,50,100,500,1000};
    	int roman2int[100];
    	for(int i = 0; i < 7; i++)
    		roman2int[roman[i]] = value[i];
    	
        int len = s.length();
        int pre = roman2int[s[0]];

        int result = pre;
        for(int i = 1; i < len; i++)
        {
        	int cur = roman2int[s[i]];
        	if(cur > pre)
        		result = result - 2*pre + cur;
        	else
        		result += cur;
        	pre = cur;
        }

        return result;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	string s;
	cin >> s;
	Solution solu;
	int num = solu.romanToInt(s);
	cout << num << endl;
}