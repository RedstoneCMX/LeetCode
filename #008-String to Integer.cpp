#include<iostream>
#include<string>
using namespace std;
////////////////////////////解题思路///////////////////////////////////////////////////////
/*这个题就是一个字符串转int的问题，看起来虽然简单，但是有很多细节问题需要注意。
1.空格跳过
2.正数负数的判断
3.超出int范围的判断。
4.非数字字符的判断，如果在正负号之后还出现了非数字字符，那么就直接break，只输出之前合法的数字字符构成的数字。
*/
////////////////////////////解题思路///////////////////////////////////////////////////////
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
	public:
    int myAtoi(string str) 
    {
        int length = str.length();
        int i = 0;
        //跳过空格
        for(i = 0; i < length && str[i]==' '; i++);
        if(i == length)
        	return 0;
        int j = 0;
        //标记是负数还是正数
        int negflag = 1;

        const int max = 0x7fffffff;  //int最大值,2^31-1 
        const int min = 0x80000000;  //int最小值,-2^31 
        long long sum = 0;
        for( j = i; j < length; j++)
        {
        	char tempchar = str[j];      	
        	if(j == i && tempchar == '+')
        		negflag = 1;
        	else if(j == i && tempchar == '-')
        		negflag = -1;
        	else
        	{
        		if(tempchar >=48 && tempchar <= 57)
                {
                    int tempnum = negflag * (tempchar - 48);
                    sum = sum * 10 + tempnum;
                    if (sum > max || sum < min)   //溢出处理  
                    {  
                        sum = sum > 0 ? max:min;    
                        return sum;  
                    }  
                }
        		else
        			break;
        	}
        }
        return sum;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/

int main()
{
	string str;
	cin >> str;
	Solution solu;
	int strtoi = solu.myAtoi(str);

	cout << strtoi << endl;
}