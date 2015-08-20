#include<iostream>
#include<string>
using namespace std;
////////////////////////////解题思路///////////////////////////////////////////////////////
/*这道题是关于Z字形的题，用一个字符串数组ans[rows]来存储通过Z字形排列之后的每一行，最后一拼接就是最终结果。
用一个变量count表示正向还是反向读取row。当通过遍历输入的字符串s，row初始为0，然后用ans[row]记录当前行的字符串串接结果，
row加上count，直至加到row超过numRows，count变成-1，即反向增1，也就是减1。继续添加串接ans[row]，直至row小于0，
再将count变为1，即正向增1，也就是加1。通过这样遍历完整个字符串之后，ans这个字符串数组也就构造成功，
只需要将ans的每一个字符串拼接即可。
*/
////////////////////////////解题思路///////////////////////////////////////////////////////

/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
	public:
    string convert(string s, int numRows) 
    {     
        int len = s.length();  
        if (len == 0 || numRows <= 1) 
            return s;  
          
        string *ans = new string[numRows];
        for(int i = 0; i < numRows; i++)
            ans[i] = "";
        int row = 0, count = 1;
        for(int i = 0; i < len; i++)
        {
            ans[row] += s[i];
            row += count;
            if(row >= numRows)
            {
                row -= 2;
                count = -1; 
            }
            else if(row < 0)
            {
                row += 2;
                count = 1;
            }
        }
        string convert_s = "";
        for(int i = 0;i < numRows; i++)
            convert_s += ans[i];
        return convert_s; 

/////////以下是另外一种方法，较复杂，不宜推荐
/*        int length = s.length();
    	if(length == 0 || numRows <= 1)
    		return s;
    	char s_arrange[1000][1000];
    	int count = 0;
    	int i = 0;
    	int x = 0, y = 0;
    	memset(s_arrange,0,sizeof(s_arrange));

    	for(i=1; i <= numRows - 1; i++)
    	{
    		int si = count*(numRows - 1) + (i-1);
    		if(si >= length)
    			break;
    		char temp_char = s.at(si);
    		if(count % 2 == 0)
    		{
    			x = i;
    			y = count/2 + 1 + (numRows - 2) * count/2;
    			s_arrange[x][y] = temp_char;

    		}
    		else
    		{
    			x = numRows - i + 1;
    			y = (count - 1)/2 + 1 + (numRows - 2)*(count - 1)/2 + (i - 1);
    			s_arrange[x][y] = temp_char;
    		}

    		if(i == numRows - 1)
            {
    			count ++;
    			i = 0;
    		}
    	}
        //通过遍历这个二维数组，得到对应的Z字形按行读取的字符串排列
    	string str_convert = "";
    	int convert_num = 0;
    	for(x = 1; x <= numRows; x++)
    	{
    		for(y = 1; y < 1000; y++)
    		{
    			if(s_arrange[x][y] != 0)
                {
    				str_convert += s_arrange[x][y];
    				convert_num++;
    			}
    			if(convert_num == length)
    				break;	
    		}

    		if(convert_num == length)
    				break;
    	} 	
    	return str_convert;*/
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/

int main()
{
	string str;
	cin >> str;
	int numrows = 0;
	cin >> numrows;
	Solution solu;
	string con_str = solu.convert(str,numrows);

	cout << con_str << endl;
}