#include<iostream>
#include<vector>
using namespace std;
/*这个题非常简单的方法就是将所有数进行异或，出现两次的数进行异或就变成0了，只出现一次的数最终就会留下。
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        int size = nums.size();
        int snumber = nums[0];
        for(int i = 1; i  < size; i++)
        {
        	snumber = snumber ^ nums[i];
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