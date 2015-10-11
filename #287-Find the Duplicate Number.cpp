#include<iostream>
#include<vector>
using namespace std;
/*这道题其实是一道二分搜索的题，查找数组中的重复元素，而且不能更改元素。
思路还算简单，就是使用两个指针，一个low，一个high，初始的时候low=1，high=n，整数个数为n+1。
1.mid = (high+low) / 2，使用一个计数的变量count，遍历一遍数组nums，计算出小于等于mid的数的个数count。
2.如果count > mid，说明重复的数肯定在low和mid之间，则更新high= mid-1。否则说明重复的数肯定在mid和high之间，则更新low=mid+1。
3.判断low是否小于等于high，若是则继续1步骤，否则跳出循环。此时low即为所求。
*/
/*************************在leetcode上直接提交以下代码即可******************************/ 
class Solution 
{
public:
    int findDuplicate(vector<int>& nums) 
    {
        int low = 1, high = nums.size()-1;
        while(low <= high)
        {
        	int mid = (high+low) / 2;
        	int count = 0;
        	for(int i = 0; i < nums.size(); i++)
        	{
        		if(nums[i] <= mid)
        			count++;
        	}

        	if(count > mid)
        		high = mid - 1;
        	else
        		low = mid + 1;
        }

        return low;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	cout << "请输入整数个数: " << endl;
	int n;
	cin >> n;
	vector<int> nums;
	cout << "请输入各整数: " << endl;
	for(int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}

	Solution solu;
	int dnum = solu.findDuplicate(nums);
	cout << dnum << endl;
	return 0;
}