#include<iostream>
#include<vector>
using namespace std;
/*这道题其实也比较简单，题目意思就是要删除数组中为某个值的所有元素，同时计算删除了这些元素之后的数组长度newlen，
并在原数组上的前newlen个位置记录所有未删除的元素，顺序不定。
基本思路也很简单，首先遍历一遍数组，求得newlen，并用一个数组pos[]记录所有需要删除的元素的位置。
之后再从数组的newlen位置开始遍历，直至数组末尾，判断当前位置的值是否是要删除的元素，如果是则跳过，
如果不是则将newlen位置之前的需要删除的元素位置的值更新为该值。这里使用之前记录了删除元素位置的pos[]数组。
时间复杂度为O(N)
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
	public:
    int removeElement(vector<int>& nums, int val) 
    {
     	int newlen = 0;
     	int len = nums.size();
     	int *pos = new int[len];
     	int valnum = 0;
     	for(int i = 0; i < len; i++)
     	{
     		if(nums[i] == val)
     		{
     			pos[valnum] = i;
     			valnum++;
     			continue;
     		}
     			
     		else
     			newlen++;
     	}

     	for(int i = newlen, j = 0; i < len; i++)
     	{
     		if(nums[i] != val)
     		{
     			nums[pos[j]] = nums[i];
     			j++;
     		}

     	}

     	return newlen;   
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	int len;
	cout << "输入数组长度: "<< endl;
	cin >> len;
	vector<int> nums;
	cout << "输入数组各整数: "<< endl;
	for(int i = 0; i < len; i++)
	{
		int temp_num;
		cin >> temp_num;
		nums.push_back(temp_num);
	}
	cout << "输入要删除的整数: " << endl;
	int val;
	cin >> val;
	Solution solu;
	int newlen = solu.removeElement(nums,val);
	cout << newlen << endl;
	for(int i = 0; i < newlen; i++)
		cout << nums[i] << endl;
}