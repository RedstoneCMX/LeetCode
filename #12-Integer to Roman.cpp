#include<iostream>
using namespace std;
/*这道题是阿拉伯数字转罗马数字
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
	public:
    string intToRoman(int num) 
    {
        string roman[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int value[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string str_roman = "";
        for(int i = 0; num != 0; i++)
        {
        	while(num >= value[i])
        	{
        		str_roman += roman[i];
        		num -= value[i];
        	}
        }

        return str_roman;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{	
	int num;
	cin >> num;
	Solution solu;
	string strroman = solu.intToRoman(num);

	cout << strroman << endl;
}