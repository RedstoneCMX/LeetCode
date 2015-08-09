# LeetCode
LeetCode程序
##NO.1 Two Sum
解题思路：首先用一个结构数组记录整个数组的数以及其原本所在的位置，然后对这个数组进行升序排列，再对排序之后的数组同时从两头查找，一头一尾相加，所得结果如果和目标整数和相等则即为找到，将之前记录的原本位置输出即可，如果相加之后的和大于目标整数和，则将尾部指针向前移一个，继续执行判断指针所指位置两数之和。如果相加之后的和小于目标整数和，则将头部指针向后移一个，继续执行判断指针所指位置两数之和。直到找到两数之和等于目标整数和为止。
##NO.2 Add Two Numbers
这道题主要还是熟悉C++的链表操作，不算难。
* 1.首先同时遍历两个链表，对应位置的整数值相加，得到加和，如果加和小于10，则直接记录在新的加和链表中，如果加和大于等于10，则取个位数的值记录在新的加和链表中，并用一个变量carrybit作为进位标记，判断加和是否大于等于10，如果是，则计算carrybit，加法的进位最多也只能是1。如果加和小于10，则carrybit为0。carrybit用于下一位的加和，初始为0。
* 2.之后两个链表总有一个先遍历完成，或同时遍历完成。如果某个先遍历完成，那么还需要对另一个未遍历完的链表继续遍历，操作和第一步类似，只是变成了只有一个链表的值，但依然需要考虑进位carrybit。
* 3.在最后遍历完成之后，还需要注意的是，必须判断进位carrybit是否不为0，如果不为0，还需要在加和链表中增加一位。对应的测试用例可以是9999+1。
