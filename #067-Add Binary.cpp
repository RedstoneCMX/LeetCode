#include<iostream>
using namespace std;
/*这道题比较简单，和第66题类似，只不过这里是算二进制的加法，并且是以字符串形式输入，还是要考虑进位的问题。
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
	public:
    string addBinary(string a, string b) 
    {
        string add = "";
        int len1 = a.length();
        int len2 = b.length();
        if(len1 == 0)
        	return b;
        if(len2 == 0)
        	return a;
        int pos1, pos2;
        int carrybit = 0;
        for(pos1 = len1 - 1, pos2 = len2 -1; pos1 >=0 && pos2 >= 0;pos1--, pos2--)
        {
        	int digit1 = a[pos1] - 48;
        	int digit2 = b[pos2] - 48;
        	if(digit1 > 1 || digit1 < 0 || digit2 > 1 || digit2 < 0)
        		return add;
        	int sum = digit1 + digit2 + carrybit;	
      	 	carrybit = sum / 2;
        	add = (char)(sum % 2 + 48) + add;
        }

        while(pos1 >= 0)
        {
        	int digit1 = a[pos1] - 48;
        	int sum = digit1 + carrybit;
        	carrybit = sum / 2;
        	add = (char)(sum % 2 + 48) + add;
        	pos1--;
        }
        while(pos2 >= 0)
        {
        	int digit2 = b[pos2] - 48;
        	int sum = digit2 + carrybit;
        	carrybit = sum / 2;
        	add = (char)(sum % 2 + 48) + add;
        	pos2--;
        }

        if(carrybit > 0)
        	add = (char)(carrybit + 48) + add;

        return add;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	string a, b;
	cin >> a;
	cin >> b;
	Solution solu;
	string add = solu.addBinary(a, b);
	cout << add << endl;
}