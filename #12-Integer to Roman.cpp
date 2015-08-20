#include<iostream>
using namespace std;
/*这道题是阿拉伯数字转罗马数字。
首先罗马的单个基本数字共有7个，I(1), V(5), X(10), L(50), C(100), D(500), M(1000)
组合规则：
(1)基本数字Ⅰ、X、C 中的任何一个，自身连用构成数目，或者放在大数的右边连用构成数目，都不能超过三个；放在大数的左边只能用一个。
(2)不能把基本数字 V、L、D 中的任何一个作为小数放在大数的左边采用相减的方法构成数目；放在大数的右边采用相加的方式构成数目，只能使用一个。
(3)V 和 X 左边的小数字只能用Ⅰ。
(4)L 和 C 左边的小数字只能用X。
(5)D 和 M 左边的小数字只能用C。
有两种解法。
1.第一种就是把所有小数字在前的组合也作为基本数字，再做一个对应的数值表就可以解决问题了。对输入的需要转换的数字num从最大的基本数字1000开始比较，
如果大于等于则添加一个对应的基本数字字符至结果字符串中，并将num减去对应的基本数字的值，然后继续判断。
到小于这个基本数字就将基本数字降至更小的基本数字继续判断。
2.第二种方法就是将1-9，10-90，100-900，1000-3000这几个段内的数字全部用罗马数字表示并记录数组中。
之后对输入的需要转换的数字num每次截取其低位的数字，并使用一个变量digit记录当前位数，找到对应该数字的罗马数字的表示，添加到结果字符串最最前面。
然后将num除去低位数字，继续判断。
*/
/*************************在leetcode上直接提交以下代码即可******************************/
/*class Solution 
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
};*/

class Solution
{
public:
    string intToRoman(int num)
    {
        string roman[] = {"","I","II","III","IV","V","VI","VII","VIII","IX","","X","XX","XXX","XL","L","LX","LXX","LXXX","XC","","C","CC","CCC","CD","D","DC","DCC","DCCC","CM","","M","MM","MMM"};
        string str_roman = "";
        int digit = 0;
        while(num)
        {
            int remain = num % 10;
            str_roman = roman[digit * 10 + remain] + str_roman;
            digit++;
            num = num / 10;
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