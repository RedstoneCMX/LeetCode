#include<iostream>
#include<vector>
#include<sstream>
using namespace std;
/*这个题还是比较简单的，遍历数组即可，出现相同或者连续的整数便继续往后遍历，直到出现当前整数和下一个整数相差超过1则停止遍历，
并将一头一尾的整数以a->b的字符串形式存入string容器中，如果一头一尾整数相同则只存入该整数对应的字符串。之后便继续往下遍历。
时间复杂度为O(n)。
这里主要是对整数转字符串的操作需要注意一下，这里我使用了stringstream来进行操作。
在C++中可以使用stringstream来很方便的进行类型转换，字符串串接，不过注意重复使用同一个stringstream对象时要先继续清空，
而清空很容易想到是clear方法，而在stringstream中这个方法实际上是清空stringstream的状态（比如出错等），真正清空内容需要使用.str(“”)方法。
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
    	int size = nums.size();
    	vector<string> summary_r;
    	if(size == 0)
    		return summary_r;
    	
        for(int i = 0; i < size; i++)
        {
        	int j;
        	for(j = i; j < size-1 && (nums[j]==nums[j+1]||nums[j]+1==nums[j+1]); j++);
        	//定义一个stringstream类对象进行int对字符串的转换	
        	stringstream sstr;
        	
        	if(nums[i] == nums[j])
        	{
        		sstr.str("");
        		string str = "";
				sstr << nums[i];
        		str += sstr.str();
	    		summary_r.push_back(str);
	    		
        	}	
        	else
        	{
        		sstr.str("");
        		string str = "";
        		sstr << nums[i];
        		str += sstr.str();
        		str += "->";
                sstr.str("");
       			sstr << nums[j];
        		str += sstr.str();
        		summary_r.push_back(str);
        	}
        	i = j;	
        }

        return summary_r;
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
	vector<string> summary_r = solu.summaryRanges(nums);
	for(int i = 0; i < summary_r.size(); i++)
		cout << summary_r[i] << endl;
	return 0;
}