#include<iostream>
#include<vector>
#include<set>
using namespace std;
/*这道题本来是简单的，但是一开始使用的方法超时，时间复杂度有O(n*k)，之后换了一种方法，使用了STL中的set容器。
首先定义一个长度最大为k的滑动窗口，用一个set维护窗口内的数字判断是否出现重复，使用两个指针start和end标记滑动窗口的两端，
初始都是0，然后end不断进行扩展，扫描元素判断是否出现重复元素，直到发现end-start>k, 就开始移动start，并且在set中移除start位置的元素。
然后进行下一轮的比较。如果end扫描到数组末尾还没有发现重复元素，那就可以返回false。
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
	public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        int size = nums.size();
        if(size <= 1)
        	return 0;
        int start = 0, end = 0;
        set<int> s;
        while(end < size)
        {
            if(!s.count(nums[end]))
            {
                s.insert(nums[end]);
                end++;
            }
            else
                return 1;

            if(end - start > k)
            {
                s.erase(nums[start]);
                start++;
            }
        }
        return 0;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	int n;
	cout << "请输入整数个数: " << endl;
	cin >> n;
	vector<int> nums;
	cout << "请输入各整数: " << endl;
	for(int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}

	cout << "请输入k值: " << endl;
	int k;
	cin >> k;

	Solution solu;
	bool bo = solu.containsNearbyDuplicate(nums,k);
	cout << bo << endl;

	return 0;

}