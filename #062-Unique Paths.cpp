#include<iostream>
#include<vector>
using namespace std;
/*这道题是一道动态规划的题，还算简单。状态转移方程为：
path[i][j] = path[i-1][j] + path[i][j-1];
i和j表示的是i*j的网格从左上角到右下角的路径数量。
并且初始的时候path[i][j]都为1。
为方便起见，这里我从path[1][1]开始，表示1*1的网格的路径数量，不从0开始。
*/
/*************************在leetcode上直接提交以下代码即可******************************/ 
class Solution 
{
public:
    int uniquePaths(int m, int n) 
    {
        vector<vector<int> > path;
        for(int i = 0; i < m+1; i++)
        {
        	vector<int> row(n+1,1);
        	path.push_back(row);
        }
        for(int i = 2; i <=m; i++)
        	for(int j = 2; j <=n; j++)
        	{
        		path[i][j] = path[i-1][j] + path[i][j-1];
        	}
        return path[m][n];
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	int m, n;
	cin >> m;
	cin >> n;
	Solution solu;
	int upath = solu.uniquePaths(m,n);
	cout << upath << endl;
	return 0;
}
