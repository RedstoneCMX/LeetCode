#include<iostream>
#include<vector>
using namespace std;
/*这道题并没有想象中那么简单，一开始使用组合数来做，也就是每一行对应都有一个组合数的通项公式，第n行第k个是CnK。
这里n和k都是从0开始。这样做毫无悬念的溢出了，换成了uint64_t都没用。
之后在网上看到一个非常巧妙的方法，很不错，而且空间复杂度是O(k)。
就是在一个数组上进行操作，对于产生一个新的行用从后往前的方法来更新。每次都是getrow[j] = getrow[j-1] + getrow[j]。
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
public:
    vector<int> getRow(int rowIndex) 
    {
        vector<int> getrow(rowIndex+1);
        getrow[0] = 1;
        for(int i = 1; i <= rowIndex; i++)
        	for(int j = i; j > 0; j--)
        	{
        		if(j == i)
        			getrow[j] = 1;
        		else
        			getrow[j] = getrow[j-1] + getrow[j];
        	}
       
       	return getrow;
    }

};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	int rowindex;
	cin >> rowindex;
	Solution solu;
	vector<int> getrow = solu.getRow(rowindex);
	int size = getrow.size();
	for(int i = 0; i < size; i++)
		cout << getrow[i] << endl;
	
	return 0;
}