#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*这是一道求解三个数的和为0的题。是twosum那道题的升级版吧，但还是有些不同的。
1.因为要求3个数，如果我们固定其中1个数，再用求“和为某值的2个数的组合”的解法，就能把剩下的2个数求出来。
2.因此，先对数组进行升序排列，这样整个数组的数就由小到大排列。i的取值由0至n-3，对每一个i，我们求当num[i]是解当中的其
中一个数时，其他的2个数。设有指针p指向数组头(实际只要p从i+1开始)，q指向数组尾，sum = num[i]+num[p]+num[q]，因为num[i]
是一定在解中的，所以如果sum < 0，因为num[q]已经不能增大，所以说明num[p]太小了，这时p需要向后移动，找一个更大的数。
同理，sum > 0，说明num[q]太大了，需要q向前移动。当sum == 0时，说明找到了一个解。但找到了一个解，并不说明解中有num[i]的
所有解都找到了，因此p或q还需要跳过那些nums[p]与前一个相同以及nums[q]与后一个相同的值的情况，这样可以去掉重复的情况，
继续移动寻找其他的解，同时这里还需要直到p==q为止。
3.之后i++，以下一个位置作为固定位置，继续进行查找操作，但是这里也有一个去重操作，当前固定位置如果和前一个固定位置的数值相同则直接跳过，
因为这样求解出来的组合肯定是和前一个固定位置相同的。
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
	public:
    vector< vector<int> > threeSum(vector<int>& nums) 
    {
    	vector< vector<int> > listsum;
    	int size = nums.size();
    	//小于3个整数则直接返回空，因为没有三个整数不够组成三个整数和
    	if(size < 3)
    		return listsum;
    	//进行升序排列
        sort(nums.begin(),nums.end());
        int start, end = size - 1;
        //固定一个位置，然后从这个位置的下一个位置开始作为start，数组末尾作为end，查找另外两个数，通过twosum那道题的思路，
        //但是这里还需要进行去重。因为会有相同的数字。
        for(int i = 0; i <= size - 3; i++)
        {
        	//在选择固定位置的时候，需要去重，当前固定位置如果和前一个固定位置的数值相同则直接跳过，因为这样求解出来的组合肯定是相同的。
        	if(i > 0 && nums[i] == nums[i - 1])
        		continue;
        	start = i + 1;
        	for(int p = start, q = end; p != q ;)
        	{
        		int sum = nums[i] + nums[p] + nums[q];
        		if(sum > 0)
        			q--;
        		else if(sum < 0)
        			p++;
        		else
        		{
        			vector<int> onesum;
        			onesum.push_back(nums[i]);
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
        return listsum;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	int num = 0;
	cin >> num;
	vector<int> nums;
	int input_num;
	for(int i = 0; i < num; i++)
	{	
		cin >> input_num;
		nums.push_back(input_num);
	}

	Solution solu;

	vector< vector<int> > list_sum;
	list_sum = solu.threeSum(nums);

	int listsize = list_sum.size();
	//cout << listsize << endl;
	for(int i = 0; i < listsize; i++)
	{
		vector<int> temp = list_sum[i];
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