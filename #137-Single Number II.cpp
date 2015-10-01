#include<iostream>
#include<vector>
using namespace std;
/*这道题是136题的升级版，比136更难一些，而且并不能像136题那样直接做异或就能求出那个单数。
这里的非单数出现的次数为3，主要思路是将每个数以二进制形式来做，从第一位到第32位，
将每一个数相同的二进制位的1的数量求出来，如果求出的1的数量是3的倍数，说明那个单数对应的这一位是0，
如果不是3的倍数，那么那个单数对应的这一位就是1。
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        int size = nums.size();
        int snumber = 0;
        for(int i = 0; i < 32; i++)
        {
        	int digit = 1 << i;
        	int count = 0;
        	for(int j = 0; j < size; j++)
        	{
        		if(nums[j] & digit)
        			count++;
        	} 

        	if(count % 3)
        		snumber = snumber | digit;
        }

        return snumber;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	int n;
	cout << "请输入整数个数: " << endl;
	cin >> n;
	vector<int> nums;
	for(int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}

	Solution solu;
	int snumber = solu.singleNumber(nums);
	cout << snumber << endl;
	return 0;
}