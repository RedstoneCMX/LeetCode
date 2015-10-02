#include<iostream>
#include<vector>
using namespace std;
/*这道题是136题的升级版，有多种方法，这里介绍两种：
1.将数组进行升序排列，然后就很容易查找非重复的数了。
2.另外一种方法就是使用位操作，首先先所有的数求一个异或值，就像136题一样，然后最终得到的肯定就是那两个单数的异或值。
然后求解digitone = result & (~(result-1))得到从低位到高位的第一个为1的位的值，也就是如果result为0110，经过该运算得到的是0010。
之后遍历将digitone和nums中的数进行与操作，结果非0和0区分开来进行异或，这样就可以将那两个单数区分开来，因为其他人任何数都是逢双出现，
那么和digitone与操作肯定结果一致，肯定就落到相同的区块进行异或了，最终肯定会异或除去。而只有这两个单数会根据digitone区分开来，一个为0，另一个非0。
*/
class Solution 
{
public:
  /*  vector<int> singleNumber(vector<int>& nums) 
    {
        int size = nums.size();
        vector<int> snumbers;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < size; i++)
        {
        	int j;
        	for(j = i;j < size-1 && nums[j] == nums[j+1];j++);
        	if(j == i)
        		snumbers.push_back(nums[j]);
        	i = j;
        }

        return snumbers;
    }*/

    vector<int> singleNumber(vector<int>& nums)
    {
    	int size = nums.size();
    	vector<int> snumbers(2,0);
    	int result = nums[0];
    	for(int i = 1; i < size; i++)
    	{
    		result = result ^ nums[i];
    	}

    	int digitone = result & (~(result-1));
    	for(int i = 0; i < size; i++)
    	{
    		if(digitone & nums[i])
    			snumbers[0] = snumbers[0] ^ nums[i];
    		else
    			snumbers[1] = snumbers[1] ^ nums[i];
    	}

    	return snumbers;
    }
};
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
	vector<int> snumbers = solu.singleNumber(nums);

	for(int i = 0; i < snumbers.size(); i++)
		cout << snumbers[i] << endl;
	return 0;
}