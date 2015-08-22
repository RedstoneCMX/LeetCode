#include<iostream>
#include<vector>
using namespace std;
/*这道题我主要还是用比较基础的方法，通过循环来求解。最直观的思路是播了多少位号码，就用多少个for循环，遍历每位号码对应的字符串。
还有一种比较好的办法是通过递归，使用DFS深度优先搜索来做。
1.这里我是通过先将第一个数字对应的字符分割开来，作为初始的字符结合结果lc，然后将这个结果和剩下的数字对应的字符串进行组合，
遍历从第二个开始的数字对应的字符串，和lc的字符组合，得到组合结果，更新lc。然后继续下一个数字对应的字符串进行组合。直至最后。
2.深度优先搜索DFS。
3.两种方法的时间复杂度？
*/
/*************************在leetcode上直接提交以下代码即可******************************/
/*
class Solution 
{
	public:
    vector<string> letterCombinations(string digits) 
    {
     	string  digit2letter[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
     	int len_digits = digits.length();
     	vector<string> lc;
     	if(len_digits == 0)
     		return lc;

     	int digit = digits[0] - 48;
     	int len_digit = digit2letter[digit].length();
     	for(int i = 0; i < len_digit; i++)
     	{
     		string temp_str = "";
     		temp_str += digit2letter[digit][i];
     		lc.push_back(temp_str);
     	}

     	if(len_digits == 1)
     		return lc;

     	vector<string> temp_lc;
     	int len_lc = lc.size();
     	for(int i = 1; i < len_digits; i++)
     	{
     		//清空容器，重新填充
     		temp_lc.clear();
     		vector <string>().swap(temp_lc); 
     		len_lc = lc.size();
     		digit = digits[i] - 48;
     		len_digit = digit2letter[digit].length();

     		for(int p = 0; p < len_lc; p++)
     			for(int q = 0; q < len_digit; q++)
     			{
     				string temp_str = lc[p] + digit2letter[digit][q];
     				temp_lc.push_back(temp_str);
     			}
     		//清空容器重新填充
     		lc.clear();
     		vector <string>().swap(lc); 
     		lc = temp_lc;
     	}

     	return lc;
    }
};*/
/*************************在leetcode上直接提交以上代码即可******************************/

//DFS的方法
class Solution 
{
private:
     string  digit2letter[10];
     vector<string> lc;
public:
     void createdigit2letter()
     {
          digit2letter[0] = "";
          digit2letter[1] = "";
          digit2letter[2] = "abc";
          digit2letter[3] = "def";
          digit2letter[4] = "ghi";
          digit2letter[5] = "jkl";
          digit2letter[6] = "mno";
          digit2letter[7] = "pqrs";
          digit2letter[8] = "tuv";
          digit2letter[9] = "wxyz";
     }
     //深度优先搜索
     void dfs(int dep, int maxdep, string &s, string ans)
     {
          if(dep == maxdep)
          {
               lc.push_back(ans);
               return;
          }
          for(int i = 0; i < digit2letter[s[dep]-48].length(); i++)
          {
               dfs(dep + 1, maxdep, s, ans+digit2letter[s[dep]-48][i]);
          }
     }
     vector<string> letterCombinations(string digits) 
     {
          if(digits.length() == 0)
            return lc;
          createdigit2letter();

          dfs(0,digits.length(),digits,"");
          return lc;
     }
};

int main()
{
	string digits;
	cin >> digits;
	Solution solu;
	vector<string> lc = solu.letterCombinations(digits);
	int size = lc.size();
	for(int i = 0; i < size; i++)
	{
		cout << lc[i] << endl;
	}

}