#include<iostream>
#include<vector>
using namespace std;
/*这道题非常简单，就是对数组进行一个排序，然后依次遍历排序后的数组，出现了重复数字即输出1，遍历完成之后若还没有重复，则最后输出0。时间复杂度是O(n)。
*/

/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
	public:
    bool containsDuplicate(vector<int>& nums) 
    {
        int size = nums.size();
        if(size <= 1)
        	return 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < size; i++)
        {
        	int j;
        	for(j = i; j < size-1 && nums[j] == nums[j+1];j++);
        	if(j > i)
        		return 1;
        }
        return 0;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	int n;
	cout << "请输入整数个数: " << endl;
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
	bool bo = solu.containsDuplicate(nums);
	cout << bo << endl;

	return 0;
}