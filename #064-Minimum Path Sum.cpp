#include<iostream>
#include<vector>
using namespace std;
/*这道题是一道动态规划的题，还算简单。状态转移方程为：
minpath[0][0] = grid[0][0];
minpath[i][j] = minpath[i][j-1] + grid[i][j]; (i = 0 && j >= 1)
minpath[i][j] = minpath[i-1][j] + grid[i][j]; (j = 0 && i >= 1)
minpath[i][j] = min(minpath[i-1][j], minpath[i][j-1]) + grid[i][j]; (i >= 1 && j >= 1)
minpath[i][j]表示的是网格(i+1)*(j+1)的路径和的最小值，这里的minpath数组是从[0][0]开始的。

*/
/*************************在leetcode上直接提交以下代码即可******************************/ 
class Solution 
{
public:
    int minPathSum(vector<vector<int> >& grid) 
    {
        vector<vector<int> > minpath;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++)
        {
        	vector<int> row(n,0);
        	minpath.push_back(row);
        	if(i == 0)
        		minpath[0][0] = grid[0][0];

        	for(int j = 0; j < n; j++)
        	{
        		if(i == 0 && j >= 1)
        			minpath[i][j] = minpath[i][j-1] + grid[i][j];
        		else if(j == 0 && i >= 1)
        			minpath[i][j] = minpath[i-1][j] + grid[i][j];
        		else if(i >= 1 && j >= 1)
        		{
        			minpath[i][j] = min(minpath[i-1][j],minpath[i][j-1]) + grid[i][j];
        		}
        	}
        }

        return minpath[m-1][n-1];

    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	int m, n;
	cout << "请输入网格m*n的行数m: " << endl;
	cin >> m;
	cout << "请输入网格m*n的列数n: " << endl;
	cin >> n;
	vector<vector<int> > grid;
	for(int i = 0; i < m; i++)
	{
		vector<int> row;
		for(int j = 0; j < n; j++)
		{
			int num;
			cin >> num;
			row.push_back(num);
		}
		grid.push_back(row);
	}
	Solution solu;
	int min = solu.minPathSum(grid);
	cout << min << endl;
	return 0;
}