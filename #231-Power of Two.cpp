#include<iostream>
using namespace std;
/*这道题是目前写过的最短的程序了。判断一个整数n是否是2的n次方，一个非常巧妙和简单方法是，将n减去1，
然后将减去1之后的数与n进行与操作，若结果为0，则说明是2的n次方。
其原理是：一个数若是2的n次方，表示成二进制，则是100...00,如果减去1就是111...11，比n少一位，若两个数进行与操作，则得到的结果肯定为0。
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
public:
    bool isPowerOfTwo(int n) 
    {

        if(n <= 0)
            return 0;
    	int minus_n = n - 1;
        int add = n & minus_n;
        if(add == 0)
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
	bool bo = solu.isPowerOfTwo(n);
	cout << bo << endl;

}