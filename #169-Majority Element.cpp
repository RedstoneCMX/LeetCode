#include<iostream>
#include<vector>
using namespace std;
/*这道题比较简单，思路很简单，就是对数组进行一个升序排列即可，然后找到出现次数最多的数，时间复杂度为O(n)。
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int size = nums.size();
        int majornum = 0;
        int maxcount = 0;
        int mid = size / 2;
        for(int i = 0; i < size; i++)
        {
        	int count = 1;
        	int j;
        	for(j = i; j+1 < size && nums[j] == nums[j+1]; j++)
        		count ++;
        	
        	if(count > maxcount)
        	{
        		majornum = nums[j];
        		maxcount = count;
        	}

        	i = j;
        }

        return majornum;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	vector<int> nums;
	int n;
	cout << "输入数组个数: " << endl;
	cin >> n;
	cout << "输入各整数: " << endl;
	for(int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}
	Solution solu;
	int me = solu.majorityElement(nums);
	cout << me << endl;
}