#include<iostream>
#include<vector>
using namespace std;
/*这道题比较简单，提倡多种方法求解。目前使用的就是利用vector相关操作，按照规则做一遍实现的。
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
	public:
    void rotate(vector<int>& nums, int k) 
    {
        int size = nums.size();
        if(size == 0)
        	return ;
        while(k--)
        {
        	int temp = nums[size-1];
        	nums.insert(nums.begin(),temp);
        	nums.erase(nums.end()-1);
        }
        return ;
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
		int num;
		cin >> num;
		nums.push_back(num);
	}

	cout << "请输入k值: " << endl;
	int k;
	cin >> k;
	Solution solu;
	solu.rotate(nums,k);

	for(int i = 0; i < n; i++)
		cout << nums[i] << endl;
}