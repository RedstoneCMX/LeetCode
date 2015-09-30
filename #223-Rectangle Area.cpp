#include<iostream>
using namespace std;
/*这个题应该算比较简单的数学题，但是我都没能想出来，竟然稍微看了一眼别人的博客，哎。。。
这个题就是求两个矩形的所有覆盖面积，重点就是求解两个矩形的相交面积，如果有相交就要减去相交的面积。
求解相交面积就要求解相交的矩形的两个对角点，左下角和右上角：
int iA = max(A, E), iB = max(B, F);
int iC = min(C, G), iD = min(D, H);
这样(iA, iB)就是左下角的点，(iC, iD)就是右上角的点。
判断是否有相交的面积就是判断(iC, iD)是否在(iA, iB)的右上角，也就是iC>iA 且iD>iB，然后减去相交的面积即可。
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) 
    {
        int area1 = (C - A) * (D - B);
        int area2 = (G - E) * (H - F);
        int ret_area = area1 + area2;
        //求相交的面积
        int iA = max(A, E), iB = max(B, F);
        int iC = min(C, G), iD = min(D, H);
        if(iC > iA && iD > iB)
        {
        	int iarea = (iC-iA)*(iD-iB);
        	ret_area = ret_area - iarea;
        }
        
        return ret_area;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	int A, B, C, D, E, F, G, H;
	cin >> A;
	cin >> B;
	cin >> C;
	cin >> D;
	cin >> E;
	cin >> F;
	cin >> G;
	cin >> H;
	Solution solu;
	int area = solu.computeArea(A,B,C,D,E,F,G,H);
	cout << area << endl;
	return 0;
}