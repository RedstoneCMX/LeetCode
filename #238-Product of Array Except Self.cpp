#include<iostream>
#include<vector>
using namespace std;
/*这道题给定我们一个数组，让我们返回一个新数组，对于每一个位置上的数是其他位置上数的乘积，
并且限定了时间复杂度O(n)，并且不让我们用除法。如果让用除法的话，那这道题就应该属于Easy，而且事实上有些元素可能为0，做除法并不是好方法。
那么我们只能另辟蹊径。我们可以先遍历一遍数组，每一个位置上存之前所有数字的乘积。
那么一遍下来，最后一个位置上的数字是之前所有数字之积，是符合题目要求的，只是前面所有的数还需要在继续乘。
我们这时候再从后往前扫描，每个位置上的数在乘以后面所有数字之积，对于最后一个位置来说，由于后面没有数字了，所以乘以1就行。
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int size = nums.size();
       	
       	vector<int> pes(size,1);
       	pes[0] = 1;
       	for(int i = 1; i < size; i++)
       	{
       		pes[i] = pes[i-1] * nums[i-1];
       	}

       	int right = 1;
       	for(int i = size-1; i >= 0; i--)
       	{
       		pes[i] = pes[i] * right;
       		right = right * nums[i];
       	}

        return pes;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	cout << "请输入整数个数: " << endl;
	int n;
	cin >> n;
	vector<int> nums;
	cout << "请输入各个整数: " << endl;
	for(int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}

	Solution solu;
	vector<int> pes = solu.productExceptSelf(nums);

	int size = pes.size();
	for(int i = 0; i < size; i++)
		cout << pes[i] << endl;
	return 0;
}