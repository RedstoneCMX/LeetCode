# LeetCode
LeetCode程序
##NO.1 Two Sum
* 解题思路：首先用一个结构数组记录整个数组的数以及其原本所在的位置，然后对这个数组进行升序排列，再对排序之后的数组同时从两头查找，一头一尾相加，所得结果如果和目标整数和相等则即为找到，将之前记录的原本位置输出即可，如果相加之后的和大于目标整数和，则将尾部指针向前移一个，继续执行判断指针所指位置两数之和。如果相加之后的和小于目标整数和，则将头部指针向后移一个，继续执行判断指针所指位置两数之和。直到找到两数之和等于目标整数和为止。
* 注：时间复杂度是O(n)，线性时间。其他一些方法可能会超时。之前我使用了C++的vector的find和distance函数来查找vector中的元素以及元素所在位置，发现超时了，可能跟这两个函数的效率有关。

##NO.2 Add Two Numbers
这道题主要还是熟悉C++的链表操作，不算难。
* 1.首先同时遍历两个链表，对应位置的整数值相加，得到加和，如果加和小于10，则直接记录在新的加和链表中，如果加和大于等于10，则取个位数的值记录在新的加和链表中，并用一个变量carrybit作为进位标记，判断加和是否大于等于10，如果是，则计算carrybit，加法的进位最多也只能是1。如果加和小于10，则carrybit为0。carrybit用于下一位的加和，初始为0。
* 2.之后两个链表总有一个先遍历完成，或同时遍历完成。如果某个先遍历完成，那么还需要对另一个未遍历完的链表继续遍历，操作和第一步类似，只是变成了只有一个链表的值，但依然需要考虑进位carrybit。
* 3.在最后遍历完成之后，还需要注意的是，必须判断进位carrybit是否不为0，如果不为0，还需要在加和链表中增加一位。对应的测试用例可以是9999+1。

##NO.3 Longest Substring Without Repeating Characters
这道题是考查字符串操作的题。在本题中，其实使用hash的方法就完全可以做到时间复杂度O(n)，并没有网上一些解题方法那么复杂，当然使用动态规划应该也是一种方法，只是我还没有研究。
* 1.本题中，需要查找最长不重复子串，使用一个hash数组存储出现过的字符在s串中的位置，初始都为-1。此外使用两个指针，start和end记录当前判断的子串的开始和结束，初始都为0。还需要初始length和maxlength的值为0，分别用于记录当前判断子串长度和最长不重复子串长度。
* 2.之后便从end=0开始遍历整个s串，读取end位置处的字符，判断其是否在当前判断的子串中，如果不在则将hash数组中对应位置的值修改成end，end指针加1，向右移一位继续判断，如果在当前判断的子串中，则计算start和end的距离，就是当前判断的子串的最长不重复长度了，和maxlength比较，更新maxlength。同时将start指针移至重复的那个字符所在位置的后一位，继续end加1进行判断。
* 3.这里需要注意的是在判断至最后一个字符时，则直接计算当前子串的长度，通过strlength-start进行计算，然后和maxlength比较，更新maxlength。
* 4.2中提及的判断end位置处的字符是否在当前判断的子串中，这里是根据hash[tempchar] < start来判断，tempchar表示end处的字符，之所以这么判断是因为：小于start说明在当前记录的子串中并未出现，这里不能只判断hash值为-1的情况，因为hash值可能是记录之前的子串时记录的出现过的字符位置，在当前子串实际并未出现。

##NO.4 Median of Two Sorted Arrays
这道题说白了就是一个合并排序，给定了两个已经排序好的数组进行合并排序。要实现时间复杂度是O(m+n)应该还是很容易的。两个数组的长度分别是m,n。
* 这道题的思路其实就是对两个数组同时进行遍历，使用两个指针进行操作，初始时均指向数组开始位置，然后读取指针位置处的数进行比较。
* 如果一大一小，则将更小的数放入一个新的数组mergenums中，也就是存放合并后的数组，并将其指针往后移一位。如果两数相等，则将两个数分别放入mergenums中，并将两个数组的指针均同时向后移一位。
* 遍历之后可能出现某一个数组并未遍历完，因此还需要判断两个指针的位置将未遍历完的数继续放入mergenums中去。
* 对于两个数组长度之和如果是奇数，那么中位数就是合并排序之后的中间位置的数，如果是偶数，则中位数就是合并排序之后的中间两个位置的数的平均值。

##NO.5 Longest Palindromic Substring
这道题是经典的求最长回文子串的题。朴素算法很容易想到，但是时间复杂度是O(n^2)，会超时。这里使用的是manacher算法，时间复杂度可将为O(n)。
* 大家都知道,求回文串时需要判断其奇偶性,也就是求aba和abba的算法略有差距。然而,这个算法做了一个简单的处理,很巧妙地把奇数长度回文串与偶数长度回文串统一考虑,也就是在每个相邻的字符之间插入一个分隔符,串的首尾也要加,当然这个分隔符不能再原串中出现,一般可以用‘#’或者‘$’等字符。这样一来,原来的奇数长度回文串还是奇数长度,偶数长度的也变成以‘#’为中心的奇数回文串了。
* 这里我们用一个辅助数组help记录以每个字符为中心的最长回文半径,也就是 help[i]记录以s[i]字符为中心的最长回文串半径。help[i]最小为 1,此时回文串为 s[i]本身。我们可以证明help[i]-1就是以s[i]为中心的回文串在原串当中的长度：首先help[i]记录的是扩展之后的字符串s[i]的最长回文串半径，则对应其回文串长度应该是2*help[i]-1，而实际回文串长度若为a，则2*a+1 = 2*help[i]-1，因此得出a = help[i]-1。
* 之后依次从前往后求得help数组就可以了,这里用到了DP(动态规划)的思想,也就是求help[i]的时候,前面的help[]值已经得到了,我们利用回文串的特殊性质可以进行一个大大的优化。为了防止求help[i]向两边扩展时可能数组越界,我们需要在数组最前面和最后面加一个特殊字符,令 P[0]='$'最后位置默认为'\0'不需要特殊处理。此外,我们用MaxId变量记录在求i之前的回文串中,延伸至最右端的位置,同时用id记录取这个MaxId的id值。通过下面这句话,算法避免了很多没必要的重复匹配。
```cpp
if(MaxId>i){help[i]=Min(help[2*id-i],MaxId-i);}
```

* j=2id-i即为i关于id的对称点,根据对称性,help[j]的回文串也是可以对称到i这边的,但是如果help[j]的回文串对称过来以后超过MaxId的话,
超出部分就不能对称过来了,所以这里help[i]为的下限为两者中的较小者,help[i]=Min(p[2*id-i],MaxId-i)。这样的话，在查找i的最长回文子串时就可以直接跳过help[i]个字符，再进行回文串的匹配，可以避免很多重复的比较。

##NO.7 Reverse Integer
这道题比较简单，就是一个整数反转的问题，但是简单题也会有陷阱，也不能小瞧。
这道题主要就是要考虑到int的溢出情况，溢出则输出0。对于int类型，范围是-2^31 - 2^31-1。

##NO.8 String to Integer
这个题就是一个字符串转int的问题，看起来虽然简单，但是有很多细节问题需要注意。
* 空格跳过;
* 正数负数的判断;
* 超出int范围的判断;
* 非数字字符的判断，如果在正负号之后还出现了非数字字符，那么就直接break，只输出之前合法的数字字符构成的数字。

##NO.8 Palindrome Number
这个题就是一个判断int整数是否是回文整数。有两种解决方法。
* 直接对这个整数进行反转，就和第7题Reverse Integer一样，先求整数的反转整数，然后判断反转之后的整数是否和原整数相等。这里需要注意的是反转之后可能会出现整数溢出的情况，因此需要判断整数溢出的情况，而反转整数如果溢出说明原整数肯定不是回文整数，因为如果是回文整数，既然原整数未溢出，回文整数也必然未溢出。
* 第二种方法就是将该整数转换成字符串，然后通过讨论字符串长度，分奇数偶数两种情况进行考虑，判断其回文性。
