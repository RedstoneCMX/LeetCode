#include<iostream>
using namespace std;
/*这道题还是比较简单。按照题目意思进行计算判断是否为happy number，如果是happy number最终会得到1，
如果计算出现了之前的数则说明进入了无限循环中，没有1。
*/

/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
	public:
    bool isHappy(int n) 
    {  	
    	int record[1000];
    	memset(record,0,sizeof(record));
    	record[0] = n;
    	int count = 1;
        while(1)
        {
        	int sum = 0;
        	int temp_n = n;
        	while(temp_n)
        	{
        		sum += (temp_n % 10) * (temp_n % 10);
        		temp_n = temp_n / 10;
        	}

        	if(sum == 1)
        		return 1;
        	else if(findnum(record,sum,count))
        		return 0;
        	else
        	{
        		record[count] = sum;
        		count++;
        		n = sum;
        	}
        }
    }

    bool findnum(int record[], int num, int n)
    {
    	for(int i = 0; i < n; i++)
    		if(num == record[i])
    			return 1;
    	return 0;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	int n;
	cin >> n;
	Solution solu;
	bool bo = solu.isHappy(n);
	cout << bo << endl;
}