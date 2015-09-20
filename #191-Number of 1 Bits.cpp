#include<iostream>
using namespace std;
/*这道题比较简单，就是求一个整数转化为二进制之后1的个数。按照求解一个整数的二进制表示法进行计算，得到1则计数加1即可。
*/

/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
public:
    int hammingWeight(uint32_t n) 
    {
        int count = 0;
        while(n)
        {
        	int m = n % 2;
        	if(m)count++;
        	n = n /2;
        }

        return count;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	uint32_t n;
	cin >> n;
	Solution solu;
	int hamming = solu.hammingWeight(n);
	cout << hamming << endl;
}