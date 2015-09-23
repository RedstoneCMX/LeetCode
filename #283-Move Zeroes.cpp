#include<iostream>
#include<vector>
using namespace std;
/*这道题本来是简单的，但是今天不知道怎么了，脑子锈掉了，这么简单的题都做了半天。
昨天，学长还说他面试面了这题，这要是我面试岂不是完全跪了，这么简单的题都做不出来了。哎。。。
这道题最简单的思路就是直接在当前数组操作，用一个标记pos，初始为0，将非0的数全部移到前面，移完之后再将0补全，直到pos = size-1。
泪奔啊，这么简单的题啊。
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
public:
	/*
    void moveZeroes(vector<int>& nums) 
    {
  		int size = nums.size();
  		
  		int start = 0;
  		int end = size;
  		while(start < end)
  		{
  			if(nums[start] == 0)
  			{
  				for(int i = start; i < end-1; i++)
  					nums[i] = nums[i+1];
  				nums[end-1] = 0;
  				end--;
  			}
  			else
  				start++;
  		}

    }

    void moveZeroes(vector<int>& nums) 
    {
  		int size = nums.size();
  		int i = 0, j = 0;
  		for(i = 0; i < size; i++)
  		{
  			if(nums[i] != 0)
  			{
  				if(j != i)
  				{
  					nums[j] = nums[i];
  					nums[i] = 0;
  				}
  				j++;
  			}
  		}
    }
	*/
    void moveZeroes(vector<int>& nums) 
    {
  		int size = nums.size();
  		int i, pos = 0;
  		for(i = 0; i < size; i++)
  		{
  			if(nums[i] != 0)
  			{
  				nums[pos] = nums[i];
  				pos++;
  			}
  		}

  		while(pos < size)
  		{
  			nums[pos] = 0;
  			pos++;
  		}

  		return ;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	int n;
	cout << "请输入数组个数: " << endl;
	cin >> n;
	cout << "请输入各整数: " << endl;
	vector<int> nums;
	for(int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}

	Solution solu;
	solu.moveZeroes(nums);

	for(int i = 0; i < nums.size(); i++)
		cout << nums[i] << endl;
	return 0;
}