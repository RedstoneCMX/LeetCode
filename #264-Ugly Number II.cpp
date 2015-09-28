#include<iostream>
#include<vector>
using namespace std;
/*这个题是Ugly Number的升级版，求解第n个丑陋数，最直接的朴素算法是从1开始遍历，判断是不是丑陋数，直到第n个丑陋数。
这种方法会超时，因为非丑陋数很多，直接从1开始遍历，遍历次数太多，而且判断丑陋数也要占一部分时间。
比较好的一种算法是使用一个数组，用于从小到大顺序存储n个丑数，数组中的首项为1，即第一个丑数为1
设置三个变量index1、index2、index3存储下标，初始值都为0
找出数组uglyNumbers[index1]*2、uglyNumbers[index2]*3、uglyNumbers[index3]*5的最小值，
最小值即为下一个丑数，同时更新最小值对应的下标，下标加1，如果多个数字同时为最小值，则它们的下标都要加1。
*/
/*************************在leetcode上直接提交以下代码即可******************************/

class Solution 
{
public:
    int nthUglyNumber(int n) 
    {
        vector<int> unumbers;
        unumbers.push_back(1);
        int index1 = 0, index2 = 0, index3 = 0;
      
        while(--n)
        {

        	int min = Minnumber(unumbers[index1]*2,unumbers[index2]*3,unumbers[index3]*5);
        	unumbers.push_back(min);
        	if(min == unumbers[index1]*2)
        		index1++;
        	if(min == unumbers[index2]*3)
        		index2++;
        	if(min == unumbers[index3]*5)
        		index3++;
        }
        return unumbers[unumbers.size()-1]; 
    }

    int Minnumber(int n1, int n2, int n3)
    {
    	int min = n1;
    	if(min > n2)
    		min = n2;
    	if(min > n3)
    		min = n3;
    	return min;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	int n;
	cin >> n;
	Solution solu;
	int unumber = solu.nthUglyNumber(n);
	cout << unumber << endl;
	return 0;
}