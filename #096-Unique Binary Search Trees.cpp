#include<iostream>
#include<vector>
using namespace std;
/*这个题属于动态规划的题，大概思路就是任何一个数都可以作为root节点，因此只需要循环将每个数都作为一次root节点，然后在root节点左边只能放
比root节点数小的数，在root节点右边只能放比root节点数大的数，假设节点数为i，
则状态转移方程为：
nums[i] += nums[j-1] * nums[i-j]。j需要从1循环取到i，并且初始时nums[i] = 0。
需要注意的是nums[0]取1，没有实际意义，主要是为求解i = 1时方便。
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
public:
    int numTrees(int n) 
    {
    	vector<int> nums(n+1,0);
        nums[0] = 1;
        for(int i = 1; i <= n; i++)
        {
            if(i < 3)
                nums[i] = i;
            else
            {
                nums[i] = 0;
                for(int j = 1; j <= i; j++)
                    nums[i] += nums[j-1] * nums[i-j];
            }
        }

        return nums[n];
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	int n;
	cin >> n;
	Solution solu;
	int numtrees = solu.numTrees(n);
	cout << numtrees << endl;
	return 0;
}