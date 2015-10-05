#include<iostream>
using namespace std;
/*这个题若不是看网上的解题思路，说实话我真的想不出如此巧妙的方法。
只有2和5相乘才会出现0，其中整十也可以看做是2和5相乘的结果，所以，可以在n之前看看有多少个2以及多少个5就行了，
又发现2的数量一定多于5的个数，于是我们只看n前面有多少个5就行了，于是n/5就得到了5的个数，还有一点要注意的就是25这种，
5和5相乘的结果，所以，还要看n/5里面有多少个5，也就相当于看n里面有多少个25，还有125，625。。
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
public:
    int trailingZeroes(int n) 
    {
    	int tz = 0;
    	while(n)
    	{
    		tz += n / 5;
    		n = n / 5;
    	}
    	return tz;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	int n;
	cin >> n;
	Solution solu;
	int tz = solu.trailingZeroes(n);
	cout << tz << endl;
	return 0;
}