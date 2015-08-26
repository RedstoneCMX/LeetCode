#include<iostream>
#include<vector>
using namespace std;
class Solution 
{
	public:
    vector<string> generateParenthesis(int n) 
    {
    	vector<string> gp;
    	if(n == 1)
    	{
    		string temp_p = "()";
    		gp.push_back(temp_p); 
    		return gp;
    	}

    	vector<string> mid_gp = generateParenthesis(n-1);
    	int mid_size = mid_gp.size();
    	for(int i = 0; i < mid_size; i++)
    	{
    		string temp_p = "(" + mid_gp[i] + ")";
    		string temp_p2 = mid_gp[i] + "()";
    		string temp_p3 = "()" + mid_gp[i];
    		gp.push_back(temp_p);
    		gp.push_back(temp_p2);
    		if(temp_p2 != temp_p3)
    			gp.push_back(temp_p3);
    	}
   		
   		return gp;

    }
};
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