#include<iostream>
#include<vector>
using namespace std;
/*这道题比较简单，去除重复数字，计算非重复数字的个数newlen，同时在原数组上前newlen个位置记录这newlen个非重复数字，不使用新的数组去接收。
解题思路很简单，首先初始newlen为0，之后只需要对原数组进行一次遍历，每次比较当前位置的数与前一个位置的数是否相同，如果不相同更新nums[newlen]
的值为当前位置的值，newlen加1；如果相同则不进行任何操作，继续遍历执行。
时间复杂度为O(N)
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
	public:
    int removeDuplicates(vector<int>& nums) 
    {
        int newlen = 0;
        int len = nums.size();
        if(len == 0)
        	return newlen;
        newlen++;
        for(int i = 1; i < len; i++)
        {
        	if(nums[i] == nums[i-1])
        		continue;
        	else
        	{
        		nums[newlen] = nums[i];
        		newlen++;
        	}
        		
        }

        return newlen;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	int len;
	cin >> len;
	vector<int> nums;
	for(int i = 0; i < len; i++)
	{
		int temp_num;
		cin >> temp_num;
		nums.push_back(temp_num);
	}

	Solution solu;
	int newlen = solu.removeDuplicates(nums);
	cout << newlen << endl;
	for(int i = 0; i < newlen; i++)
		cout << nums[i] << endl;
}