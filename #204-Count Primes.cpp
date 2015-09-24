#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
/*这道题若是使用最直观简单的算法去实现时间复杂度将会是O(n^2)。最直观简单的算法就是循环遍历比n小的数，判断其是不是素数，
而判断是不是素数又需要从2到sqrt(i)进行遍历，判断是否有可以整除i的。
解题方法就在第二个提示埃拉托斯特尼筛法Sieve of Eratosthenes中，
我们从2开始遍历到根号n，先找到第一个质数2，然后将其所有的倍数全部标记出来，然后到下一个质数3，
标记其所有倍数，依次类推，直到根号n，此时数组中未被标记的数字就是质数。我们需要一个n-1长度的bool型数组来记录每个数字是否被标记，
长度为n-1的原因是题目说是小于n的质数个数，并不包括n。
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
public:

	int countPrimes(int n) 
    {
    	vector<bool> boolnum(n-1,false);
    	boolnum[0] = true;
    	int limit = sqrt(n);
    	for(int i = 2; i <= limit; i++)
    	{
    		if(!boolnum[i-1])
    		{
    			for(int j = i*i; j < n; j += i)
    				boolnum[j-1] = true;
    		}
    	}

    	int count = 0;
    	for(int i = 0; i < n-1; i++)
    		if(!boolnum[i])
    			count++;
    	return count;
    }
    
};
/*************************在leetcode上直接提交以上代码即可******************************/

int main()
{
	int n;
	cin >> n;
	Solution solu;
	int countprimes = solu.countPrimes(n);
	cout << countprimes << endl;
	return 0;
}