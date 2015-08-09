#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

////////////////////////////解题思路///////////////////////////////////////////////////////
/*首先用一个结构数组记录整个数组的数以及其原本所在的位置，然后对这个数组进行升序排列，再对排序之后的数组同时从两头查找，
一头一尾相加，所得结果如果和目标整数和相等则即为找到，将之前记录的原本位置输出即可，如果相加之后的和大于目标整数和，
则将尾部指针向前移一个，继续执行判断指针所指位置两数之和。如果相加之后的和小于目标整数和，则将头部指针向后移一个，
继续执行判断指针所指位置两数之和。直到找到两数之和等于目标整数和为止。
*/
////////////////////////////解题思路///////////////////////////////////////////////////////

/*************************在leetcode上直接提交以下代码即可******************************/
//定义一个结构存放整数以及其原本位置
struct numNode{
	int num;
	int pos;
};

//sort排序的比较函数，升序排列
bool Comp(const numNode &a,const numNode &b)
{
    return a.num < b.num;
}


class Solution 
{
	public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> result;
        int count = nums.size();
        //用于记录整数以及其原本的位置
        vector<numNode> numpos;
        for(int i = 0; i < count; i++)
        {
        	numNode temp_numnode;
        	temp_numnode.num = nums[i];
        	temp_numnode.pos = i + 1;
        	numpos.push_back(temp_numnode);
        }
        //进行排序
        sort(numpos.begin(),numpos.end(),Comp);
        int index1 = 0, index2 = 0;
        //对存放了原本位置并重新排序的numpos进行遍历，从两头同时查找
        for(int i = 0,j = count - 1; i != j;)
        {
        	int sum = numpos[i].num + numpos[j].num;
        	if(target == sum)
        	{
        		index1 = numpos[i].pos;
        		index2 = numpos[j].pos;
        		if(index1 > index2)
        		{
        			result.push_back(index2);
        			result.push_back(index1);
        		}
        		else
        		{
        			result.push_back(index1);
        			result.push_back(index2);
        		}
        		break;
        		
        	}
        	else if(target > sum)
        	{
        		i++;
        	}
        	else
        	{
        		j--;
        	}
        }

        return result;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/

int main()
{

	int count = 0;
	int target = 0;
	int temp_num = 0;
	vector<int> nums;
	//输入数的个数
	cout << "请输入整数的个数："<<endl;
	cin >> count;
	cout << "请输入各个整数："<<endl;

	for(int i = 0; i < count; i++)
	{
		cin >> temp_num;
		nums.push_back(temp_num);
	}

	cout << "请输入目标整数和："<<endl;

	cin >> target;

	vector<int> result_twosum;
	Solution solu;
	result_twosum = solu.twoSum(nums, target);

	cout << result_twosum[0]<<endl<<result_twosum[1]<<endl;

}