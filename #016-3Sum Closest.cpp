#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*这道题和上一道题类似，这里是求解与目标和最接近的三个数的组合的和。
思路和上一题类似，也是固定一个位置，然后从这个位置的下一个位置开始作为start，数组末尾作为end，查找另外两个数，通过twosum那道题的思路，
这里需要使用两个变量，一个记录已经查找过的三个数组合的和与目标和的最小差值，取值为正数，一个是记录最小差值对应的三个数组合的和。
初始状态最小差值closest取一个最大值，对应和closestsum初始为0即可。
然后计算sum = nums[i] + nums[p] + nums[q];如果sum > target，计算与targe的差值sum-target，并将其与最小差值closest比较，
如果比closest小则更新closest为sum-target，同时更新closestsum = sum。如果sum < target，计算与target的差值，target-sum，
并将其与最小差值closest比较，如果比closest小则更新closest和closestsum。如果sum == target则直接返回target即可。
最后返回closestsum即为最终结果。
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
	public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        int size = nums.size();
        if(size < 3)
        	return 0;
        sort(nums.begin(),nums.end());
        int start, end = size - 1;
        int closest = 0x7fffffff;//取一个最大值
        int closestsum = 0;
        //固定一个位置，然后从这个位置的下一个位置开始作为start，数组末尾作为end，查找另外两个数，通过twosum那道题的思路，
        for(int i = 0; i <= size - 3; i++)
        {
        	start = i + 1;
        	for(int p = start, q = end; p != q ;)
        	{
        		int sum = nums[i] + nums[p] + nums[q];
        		if(sum > target)
        		{
        			int temp_closest = sum - target;
        			if(temp_closest < closest)
        			{
        				closest = temp_closest;
        				closestsum = sum;
        			}		
        			q--;
        		}	
        		else if(sum < target)
        		{
        			int temp_closest = target - sum;
        			if(temp_closest < closest)
        			{
        				closest = temp_closest;
        				closestsum = sum;
        			}
        			p++;
        		}
        		else
        			return target;
        	}
        }

        return closestsum;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/

int main()
{
	cout << "输入整数的个数:"<< endl;
	int size = 0;
	cin >> size;
	vector<int> nums;
	int input_num;
	cout <<"输入各整数: "<< endl;
	for(int i = 0; i < size; i++)
	{
		cin >> input_num;
		nums.push_back(input_num);
	}

	cout << "输入target: "<< endl;
	int target;
	cin >> target;
	Solution solu;
	int tsc = solu.threeSumClosest(nums,target);
	cout << tsc << endl;
}