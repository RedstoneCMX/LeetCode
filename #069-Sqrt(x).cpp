#include<iostream>
#include<math.h>
using namespace std;
/*这道题如果直接从0到x遍历其平方求解必然会超时，这里主要采用的是两种方法，二分法和牛顿迭代法。
1.二分法就不用说了，时间复杂度是O(logn)
2.牛顿迭代法：计算x2 = n的解，令f(x)=x2-n，相当于求解f(x)=0的解。
首先取x0，如果x0不是解，做一个经过(x0,f(x0))这个点的切线，与x轴的交点为x1。
同样的道理，如果x1不是解，做一个经过(x1,f(x1))这个点的切线，与x轴的交点为x2。
以此类推。以这样的方式得到的xi会无限趋近于f(x)=0的解。
判断xi是否是f(x)=0的解有两种方法：
一是直接计算f(xi)的值判断是否为0，二是判断前后两个解xi和xi-1是否无限接近。
可求得迭代公式xi+1= (xi + n/xi) / 2
*/
/*************************在leetcode上直接提交以下代码即可******************************/
/*
class Solution 
{
	public:
    int mySqrt(int x) 
    {
    	unsigned long long result2;
    	unsigned long long start = 0, end = x;
    	unsigned long long mid = (start + end) / 2;
    	while(start < end)
    	{
    		
    		mid = (start + end) / 2;
    		result2 = mid * mid;
    		if(result2 < x)
    			start = mid + 1;

    		else if(result2 == x)
    			return mid;
    		else
    			end = mid - 1;
    			
    	}
        
    	result2 = end * end;
    	int result;
    	if(result2 > x)
    		result = end - 1;
        else
        	result = end;
        return result;
    }
};*/
/*************************在leetcode上直接提交以上代码即可******************************/

/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
	public:
    int mySqrt(int x) 
    {
    	if(x == 0)
    		return 0;
    	double pre;
    	double cur = 1;
    	while(fabs(cur - pre) > 1e-5)
    	{
    		pre = cur;
    		cur = (pre + x / pre) / 2.0;
    	}

    	int result = (int)cur;
    	return result;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	int x;
	cin >> x;
	Solution solu;
	int result = solu.mySqrt(x);
	cout << result << endl;
}