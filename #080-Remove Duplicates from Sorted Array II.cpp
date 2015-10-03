#include<iostream>
#include<vector>
using namespace std;
/*这道题方法还比较简单，使用一个指针pos记录当前更新的位置，然后使用一个变量count来记录当前连续相同的数的个数。
初始时pos=1，count=1。然后从i=1~i=size-1进行遍历：
如果nums[i]等于nums[i-1]则count++，并且判断count如果小于3则更新nums[pos]=nums[i]，并pos++。
如果nums[i]不等于nums[i-1]，说明进入了下一个数的判断了，那么此时count更新为1.nums[pos]=nums[i]，并pos++。

*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int size = nums.size();
        if(size <= 2)
        return size;

        int pos = 1;
        int count = 1;
        for(int i = 1; i < size; i++)
        {
        	if(nums[i] == nums[i-1])
        	{
        		count++;
        		if(count < 3)
        		{
        			nums[pos] = nums[i];
        			pos++;
        		}
        	}
        	else
        	{
        		count = 1;
        		nums[pos] = nums[i];
        		pos++;
        	}
        }

        return pos;
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
	int rd = solu.removeDuplicates(nums);
	cout << rd << endl;
	cout << endl;
	for(int i = 0; i < rd; i++)
	{
		cout << nums[i] << endl;
	}
	return 0;
}