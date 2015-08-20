#include<iostream>
#include<vector>
using namespace std;
/*这道题算是一道数学题，如果穷举所有可能的情况，时间复杂度是O(n^2)，会超时。
这道题的O(n)算法类似于two sum那道题，在height两头分别设一个指针，然后计算area，
如果height[i] <= height[j]，那么i++，如果height[i] > height[j]，那么j--。
因为在这里如果height[i] <= height[j]，移指针j的话，只会使得面积减少，
决定盛水的高度是最矮的那个高度，而此时如果再移j指针，只会使得j-i宽度减少，
那么面积肯定减少，因此需要j++，同理height[i] > height[j]的情况。
*/
/*************************在leetcode上直接提交以下代码即可******************************/
#define MIN(x,y)  ((x)<(y)? (x):(y))
class Solution 
{
	public:
    int maxArea(vector<int>& height) 
    {
    	int len = height.size();
    	int maxarea = 0;
    	for(int i = 0, j = len - 1; i != j ;)
    	{
    		//求面积
    		int area = (j - i) * MIN(height[i],height[j]);
    		if(area > maxarea)
        		maxarea = area;
        	if(height[i] <= height[j])
        		i++;
        	else
        		j--;
    	}
        return maxarea;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	int n = 0;
	cin >> n;
	vector<int> height;
	for(int i = 0; i < n ;i ++)
	{
		int temp_height = 0;
		cin >> temp_height;
		height.push_back(temp_height);
	}
	Solution solu;
	int maxarea = solu.maxArea(height);
	cout << maxarea << endl;
}
