#include<iostream>
#include<vector>
using namespace std;
/*这道题是关于数独的题，就是判断输入的不完整数独是否合法，并不需要其是否有解，其实就是分三种情况来判断：
1.判断每行不是空的格的数字是否是在1-9，并且没有重复
2.判断每列不是空的格的数字是否是在1-9，并且没有重复
3.判断每个九宫格的格的数字是否是在1-9，并且没有重复。
*/
/*************************在leetcode上直接提交以下代码即可******************************/ 
class Solution 
{
	public:
    bool isValidSudoku(vector<vector<char> >& board) 
    {
        int flag_board[10];
        for(int i = 0; i < 9; i++)
        {
        	memset(flag_board,0,sizeof(flag_board));
        	for(int j = 0; j < 9; j++)
        	{
        		if(board[i][j] != '.')
        		{
        			if(board[i][j] >= '1' && board[i][j] <= '9')
        			{
        				if(flag_board[board[i][j] - 48] == 1)
        					return 0;
        				else
        					flag_board[board[i][j] - 48] = 1;
        			}
        			else
        				return 0;

        		}
        	}
        }

        for(int j = 0; j < 9; j++)
        {
        	memset(flag_board,0,sizeof(flag_board));
        	for(int i = 0; i < 9; i++)
        	{
        		if(board[i][j] != '.')
        		{
        			if(board[i][j] >= '1' && board[i][j] <= '9')
        			{
        				if(flag_board[board[i][j] - 48] == 1)
        					return 0;
        				else
        					flag_board[board[i][j] - 48] = 1;
        			}
        			else
        				return 0;

        		}
        	}
        }

        for(int i = 0; i < 3; i++)
        	for(int j = 0; j < 3; j++)
        	{
        		memset(flag_board,0,sizeof(flag_board));
        		for(int p = 3*i; p < 3*i+3; p++)
        			for(int q = 3*j; q < 3*j+3; q++)
        			{
        				if(board[p][q] != '.')
		        		{
		        			if(board[p][q] >= '1' && board[p][q] <= '9')
		        			{
		        				if(flag_board[board[p][q] - 48] == 1)
		        					return 0;
		        				else
		        					flag_board[board[p][q] - 48] = 1;
		        			}
		        			else
		        				return 0;

		        		}
        			}
        	}

        return 1;    	
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	vector<vector<char> > board;
	for(int i = 0; i < 9; i++)
	{
		vector<char> rowboard;
		for(int j = 0; j < 9; j++)
		{
			char ch;
			cin >> ch;

			rowboard.push_back(ch);
		}
		board.push_back(rowboard);
	}

	Solution solu;
	bool bo = solu.isValidSudoku(board);
	cout << bo << endl;
		
}