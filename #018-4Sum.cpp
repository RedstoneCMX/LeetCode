#include<iostream>
#include<vector>
using namespace std;
/*这是一道求解四个数的和为某个目标数的题。是3sum那道题的升级版。思路其实也和3sum那道题基本相同。
1.因为要求4个数，如果我们固定其中2个数，再用求“和为某值的2个数的组合”的解法，就能把剩下的2个数求出来。
2.因此，先对数组进行升序排列，这样整个数组的数就由小到大排列。通过两个循环来固定前面2个数，i的取值由0至n-4，
对每一个i，我们求当num[i]是解当中的其中一个数时，再设定j为解当中的第二个数，j从i+1到n-3取值。其他的2个数的确定，
设有指针p指向数组头(实际只要p从j+1开始)，q指向数组尾，sum = num[i]+num[j]+num[p]+num[q]，因为num[i]和sum[j]是一定在解中的，
所以如果sum < 0，因为num[q]已经不能增大，所以说明num[p]太小了，这时p需要向后移动，找一个更大的数。同理，sum > 0，
说明num[q]太大了，需要q向前移动。当sum == 0时，说明找到了一个解。但找到了一个解，并不说明解中有num[i]和num[j]的所有解都找到了，
因此p或q还需要跳过那些nums[p]与前一个相同以及nums[q]与后一个相同的值的情况，这样可以去掉重复的情况，继续移动寻找其他的解，
同时这里还需要直到p==q为止。
3.之后继续i和j循环以下一个位置作为固定位置，继续进行查找操作，但是这里也有两个去重操作，num[i]和num[j]去除前面相同的值，
遇到就跳过即可，防止求解到相同的组合对。
4.时间复杂度O(n^3)
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
public:
    vector< vector<int> > fourSum(vector<int>& nums, int target) 
    {
    	vector< vector<int> > listsum;
        int size = nums.size();
        //小于4个整数则直接返回空，因为没有四个整数不够组成四个整数和
        if(size < 4)
        	return listsum;
        //进行升序排列
        sort(nums.begin(),nums.end());
        int start, end = size - 1;
        for(int i = 0; i <= size-4; i++)
        {
        	if(i > 0 && nums[i] == nums[i-1])
	        		continue;
        	for(int j = i + 1; j <= size-3; j++)
        	{

        		if(j > i + 1 && nums[j] == nums[j-1])
	        		continue;
	        	start = j + 1;
	        	for(int p = start, q = end; p != q;)
	        	{
	        		int sum = nums[i] + nums[j] + nums[p] + nums[q];
	        		if(sum > target)
	        			q--;
	        		else if(sum < target)
	        			p++;	
	        		else
	        		{
	        			vector<int> onesum;
	        			onesum.push_back(nums[i]);
	        			onesum.push_back(nums[j]);
	        			onesum.push_back(nums[p]);
	        			onesum.push_back(nums[q]);
	        			listsum.push_back(onesum);
	        			//找到一个组合之后还需要继续查找，因为并不和twosum那道题那样只有一个解，
	        			//同时这里需要跳过那些相同的值的情况，nums[p]和nums[q]都需要跳过，去重操作。
	        			p++;
	        			while(p != q && nums[p] == nums[p-1])
	        				p++;
	        			if(p == q)
	        				break;
	        			q--; 
	        			while(p != q && nums[q] == nums[q+1])
	        				q--;
	        		}
	        	}
        	}
    	}

    	return listsum;

    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	cout << "输入整数的个数: "<< endl;
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
	vector<vector<int> > fs;
	fs = solu.fourSum(nums,target);

	int fs_size = fs.size();
	for(int i = 0; i < fs_size; i++)
	{
		vector<int> temp = fs[i];
		int temp_size = temp.size();
		cout << "(";
		for(int j = 0; j < temp_size; j++)
		{
			cout << temp[j];
			if(j < temp_size - 1)
				cout << ", ";
			else
				cout << ")";
		}
		cout << endl;
		
	}
}