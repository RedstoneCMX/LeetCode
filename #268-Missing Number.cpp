#include<iostream>
#include<vector>
using namespace std;
/*这道题非常简单，就是找到那个0~n那个缺失的数字，首先求解0~n的所有数的和，然后再求解整个nums数组的和，两者相减就得到那个缺失的数字了。
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
public:
    int missingNumber(vector<int>& nums) 
    {
        int size = nums.size();
        int umiss_sum = 0;
        for(int i = 0; i <= size; i++)
        	umiss_sum += i;
        int miss_sum = 0;
        for(int i = 0; i < size; i++)
        	miss_sum += nums[i];
        return umiss_sum - miss_sum;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	cout << "请输入整数个数: " << endl;
	int n;
	cin >> n;
	vector<int> nums;
	for(int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}

	Solution solu;
	int mnumber = solu.missingNumber(nums);
	cout << mnumber << endl;
	return 0;

}