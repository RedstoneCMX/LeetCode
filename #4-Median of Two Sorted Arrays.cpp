#include<iostream>
#include<vector>
using namespace std;

////////////////////////////解题思路///////////////////////////////////////////////////////
/*这道题说白了就是一个合并排序，给定了两个已经排序好的数组进行合并排序。要实现时间复杂度是O(m+n)应该还是很容易的。两个数组的长度分别是m,n。
这道题的思路其实就是对两个数组同时进行遍历，使用两个指针进行操作，初始时均指向数组开始位置，然后读取指针位置处的数进行比较，如果一大一小，
则将更小的数放入一个新的数组mergenums中，也就是存放合并后的数组，并将其指针往后移一位。如果两数相等，则将两个数分别放入mergenums中，
并将两个数组的指针均同时向后移一位。遍历之后可能出现某一个数组并未遍历完，因此还需要判断两个指针的位置将未遍历完的数继续放入mergenums中去。
对于两个数组长度之和如果是奇数，那么中位数就是合并排序之后的中间位置的数，如果是偶数，则中位数就是合并排序之后的中间两个位置的数的平均值。
*/
////////////////////////////解题思路///////////////////////////////////////////////////////


/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
	public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int count1 = nums1.size();
        int count2 = nums2.size();
        int sumcount = count1 + count2;
        int middlecount = sumcount / 2;
        double median = 0;
        int i = 0, j = 0;
        vector<int> mergenums;
        //对两个数组进行同时遍历，也就是相当于使用两个指针i和j进行操作，初始时i,j都为0
        for(i=0,j=0; i<count1 && j<count2; )
        {
        	//根据当前指针位置分别读取两个数组中的值
        	int num1 = nums1[i];
        	int num2 = nums2[j];
        	//判断两个数的大小
        	//如果一大一小，则将更小的数放入mergenums中，并将其指针往后移一位
        	if(num1 < num2)
        	{
        		mergenums.push_back(num1);
        		i++;
        	}
        	else if(num1 > num2)
        	{
        		mergenums.push_back(num2);
        		j++;
        	}
        	//如果两数相等，则将两个数分别放入mergenums中，并将两个数组的指针均同时向后移一位
        	else
        	{
        		mergenums.push_back(num1);
        		mergenums.push_back(num2);
        		i++;
        		j++;
        	}
        }
        //遍历之后可能出现某一个数组并未遍历完，因此还需要判断两个指针的位置将未遍历完的数继续放入mergenums中去
        if(i < count1)
        {
        	for( ;i < count1; i++)
        	{
        		int num1 = nums1[i];
        		mergenums.push_back(num1);
        	}
        }
        if(j < count2)
        {
        	for( ;j < count2; j++)
        	{
        		int num2 = nums2[j];
        		mergenums.push_back(num2);
        	}	
        }
        //对于两个数组长度之和如果是奇数，那么中位数就是合并排序之后的中间位置的数
        if(sumcount % 2 != 0)
        	median = mergenums[middlecount];
        //如果是偶数，则中位数就是合并排序之后的中间两个位置的数的平均值
        else
        	median = (mergenums[middlecount - 1] + mergenums[middlecount])*1.0/2;

        return median;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/

int main()
{
	int count1 = 0, count2 = 0;
	int temp_num = 0;
	vector<int> nums1;
	vector<int> nums2;
	cout << "请输入第一个数组的长度："<< endl;
	cin >> count1;
	cout << "请输入第一个数组所有整数："<< endl;
	for(int i = 0; i < count1; i++)
	{
		cin >> temp_num;
		nums1.push_back(temp_num);
	}
	cout << "请输入第二个数组的长度："<< endl;
	cin >> count2;
	cout << "请输入第二个数组所有整数："<< endl;
	for(int i = 0; i < count2; i++)
	{
		cin >> temp_num;
		nums2.push_back(temp_num);
	}

	Solution solu;
	double median = solu.findMedianSortedArrays(nums1, nums2);
	cout << median << endl;
}