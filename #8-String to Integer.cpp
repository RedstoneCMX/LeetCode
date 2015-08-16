#include<iostream>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
	public:
    int myAtoi(string str) 
    {
        int length = str.length();

        vector<int> number;

        int i = 0;
        //跳过空格
        for(i = 0; i < length && str[i]==' '; i++);
        if(i == length)
        	return 0;

        int j = 0;
        //标记是负数还是正数
        int negflag = 1;
        for( j = i; j < length; j++)
        {
        	char tempchar = str[j];
        	
        	if(j == i && tempchar == '+')
        	{
        		negflag = 1;
        	}
        	else if(j == i && tempchar == '-')
        	{
        		negflag = -1;
        	}

        	else
        	{
        		if(tempchar >=48 && tempchar <= 57)
        		{

        			number.push_back(tempchar - 48);
        		}
        		else{
        			break;
        		}
        	}

        }
        const int max = 0x7fffffff;  //int最大值,2^31-1 
        const int min = 0x80000000;  //int最小值,-2^31 
        int real_num = number.size();
        if(real_num > 10 && negflag == 1)
        {
        	return max;
        }
        if(real_num > 10 && negflag == -1)
        {
        	return min;
        }

        long long sum = 0;
        for(int k = 0; k < real_num; k ++)
        {
        	long long tempnum = negflag * number[k] * pow(10, (real_num - k - 1));
        	sum += tempnum;
        	if (sum > max || sum < min)   //溢出处理  
            {  
                sum = sum > 0 ? max:min;    
                return sum;  
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