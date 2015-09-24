#include<iostream>
using namespace std;
/*这道题比较简单。
只需要对num分别除去含2，3，5的因子，若最后是1，说明num就只有2，3，5这三个素数因子。
对于除去含2，3，5的因子，就是直接循环判断num是否被2整除，若是则继续除去2，直到不被2整除，再进行3和5的因子的除去操作。
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
public:
    bool isUgly(int num) 
    {
    	if(num == 0)
    		return 0;
        if(num == 1)
        	return 1;

        while(num % 2 == 0)
        	num = num / 2;
       
       	while(num % 3 == 0) 
        	num = num / 3;
        while(num % 5 == 0) 
        	num = num / 5;
        
        if(num == 1)
        	return 1;
        return 0;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	int num;
	cin >> num;
	Solution solu;
	bool bo = solu.isUgly(num);
	cout << bo << endl;
	return 0;
}