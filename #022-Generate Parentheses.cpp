#include<iostream>
#include<vector>
using namespace std;
/*这又是一道括号匹配的题目，和第20题不一样，第20题是判断括号匹配是否合法的题，而这道题正好想法，需要将所有合法的括号匹配情况列出来。
这里需要说明的是该问题解的个数就是卡特兰数，但是现在不是求个数，而是要将所有合法的括号排列打印出来。
令h(0)=1,h(1)=1，catalan数满足递推式[1]：
h(n)= h(0)*h(n-1)+h(1)*h(n-2) + ... + h(n-1)h(0) (n>=2)
例如：h(2)=h(0)*h(1)+h(1)*h(0)=1*1+1*1=2
h(3)=h(0)*h(2)+h(1)*h(1)+h(2)*h(0)=1*2+1*1+2*1=5
这道题的基本思想就是递归。
假设在位置k我们还剩余left个左括号和right个右括号，如果left>0，则我们可以直接打印左括号，而不违背规则。
能否打印右括号，我们还必须验证left和right的值是否满足规则，如果left>=right，则我们不能打印右括号，
因为打印会违背合法排列的规则，否则可以打印右括号。如果left和right均为零，则说明我们已经完成一个合法排列，可以将其打印出来。
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
private:
    vector<string> gp;
	public:
    void generate(int leftnum, int rightnum, string s)
    {
        if(leftnum == 0 && rightnum == 0)
        {
            gp.push_back(s);
            return ;
        }

        if(leftnum > 0)
            generate(leftnum-1,rightnum,s+"(");
        
        if(rightnum > 0 && leftnum < rightnum)
            generate(leftnum,rightnum-1,s+")");
        
    }
    vector<string> generateParenthesis(int n) 
    {
        string s="";
    	generate(n,n,s);
        return gp;

    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	int n;
	cin >> n;
	Solution solu;
	vector<string> gp;
	gp = solu.generateParenthesis(n);
	int size = gp.size();
	for(int i = 0;i < size; i++)
		cout << gp[i] << endl;
	
}