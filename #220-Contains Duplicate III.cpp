#include<iostream>
#include<vector>
#include<set>
using namespace std;
/*
这道题是219题的升级版，方法类似，首先定义一个长度最大为k的滑动窗口，用一个set维护窗口内的数字是否有相差在t内，
使用两个指针start和end标记滑动窗口的两端，初始都是0，然后end不断进行扩展，每次扩展就判断nums[end]和set中的元素，
查找nums[end]-t的lower_bound（二叉搜索树实现的？），第一个大于等于的元素，然后判断差值是否小于等于t，这样判断就能包括在-t~t的差值范围。
然后判断end-start>k, 就开始移动start，并且在set中移除start位置的元素。
然后进行下一轮的比较。如果end扫描到数组末尾还没有发现差值小于t的两个元素，那就可以返回false。
*/
class Solution 
{
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
    {
        int size = nums.size();
        if(size <= 1)
        	return 0;
        set<int> s;
        int start = 0, end = 0;
        while(end < size)
        {
        	set<int>::iterator lb = s.lower_bound(nums[end] - t);
            if (lb != s.end() && (*lb - nums[end]) <= t) 
            	return 1;
        	else
        	{
        		s.insert(nums[end]);
        		end++;
        	}
        	
        	if(end - start > k)
        	{
        		s.erase(nums[start]);
        		start++;
        	}
        }

        return 0;
    }

};
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
	cout << "请输入t值: " << endl;
	int t;
	cin >> t;
	Solution solu;
	bool bo = solu.containsNearbyAlmostDuplicate(nums, k, t);
	cout << bo << endl;
	return 0;
}