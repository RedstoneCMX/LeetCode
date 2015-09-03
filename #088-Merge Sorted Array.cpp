#include<iostream>
#include<vector>
using namespace std;
/*这道题和之前做过的两个有序链表合并(第21题)以及找两个有序数组的中位数(第4题)其实也差不多，只是这里可能涉及到更多的C++ vector的操作。
因为这里是在其中一个数组的基础上添加进另一个有序数组，需要在该数组上进行插入删除等操作。
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
	public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
    	
    	if(n == 0)
    		return ;
    	if(m == 0)
    	{
    		nums1 = nums2;
    		nums1.erase(nums1.begin()+n,nums1.end());
    		return ;
    	}

        vector<int>::iterator it1;
        it1 = nums1.begin();
        vector<int>::iterator it2;
        it2 = nums2.begin();
        int i1 = 0, i2 = 0;
        while(i1 < m && i2 < n)
        {
        	int num1 = *it1;
        	int num2 = *it2;
        	
        	if(num1 > num2)
        	{
                //返回值是指向插入的值的迭代器
        		it1 = nums1.insert(it1,num2);
        		it1++;
        		it2++;
        		i2++;
        	}
        	else
        	{
        		it1++;
        		i1++;
        	}
        }

        while(i2 < n)
        {
        	int num2 = *it2;
        	it1 = nums1.insert(it1,num2);
        	it1++;
        	it2++;
        	i2++;
        }

        nums1.erase(nums1.begin()+m+n,nums1.end());
    	return ;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	int M,m;
	vector<int> nums1;
	cout << "输入nums1的整数个数: " << endl;
	cin >> M;
	cout << "输入nums1各整数: " << endl;
	for(int i = 0; i < M; i++)
	{
		int temp_num;
		cin >> temp_num;
		nums1.push_back(temp_num);
	}
	cout << "输入m: " << endl;
	cin >> m;
	int N,n;
	vector<int> nums2;
	cout << "输入nums2的整数个数: " << endl;
	cin >> N;
	cout << "输入nums2各整数: " << endl;
	for(int i = 0; i < N; i++)
	{
		int temp_num;
		cin >> temp_num;
		nums2.push_back(temp_num);
	}
	cout << "输入n: " << endl;
	cin >> n;
	Solution solu;
	solu.merge(nums1,m,nums2,n);

	for(int i = 0; i < nums1.size(); i++)
		cout << nums1[i] << endl;

}