#include<iostream>
#include<vector>
using namespace std;
/*这个题比较简单，就是求解帕斯卡三角形，最简单的动态规划思路。
状态转移方程：pascaltriangle[i][j]=pascaltriangle[i-1][j-1]+pascaltriangle[i-1][j]
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
public:
    vector<vector<int> > generate(int numRows) 
    {
        vector<vector<int> > pascaltriangle;
        for(int i = 0; i < numRows; i++)
        {
        	vector<int> inrow;
        	for(int j = 0; j <= i; j++)
        	{
        		if(j == 0 || j == i)
        			inrow.push_back(1);
        		else
        			inrow.push_back(pascaltriangle[i-1][j-1]+pascaltriangle[i-1][j]);
        	}
        	pascaltriangle.push_back(inrow);
        }

        return pascaltriangle;
        	
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	int numrows;
	cin >> numrows;
	 Solution solu;
	 vector<vector<int> > pascaltriangle;
	 pascaltriangle = solu.generate(numrows);
	 int size = pascaltriangle.size();
	 for(int i = 0; i < size; i++)
	 {
	 	int insize = pascaltriangle[i].size();
	 	for(int j = 0; j < insize; j++)
	 		cout << pascaltriangle[i][j] << " ";
	 	cout << endl;
	 }
	 return 0;
}