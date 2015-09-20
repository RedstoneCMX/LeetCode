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
这道题是经典的求最长回文子串的题。朴素算法很容易想到，但是时间复杂度是O(n^2)，会超时。这里使用的是manacher算法，时间复杂度可降为O(n)。
* 大家都知道,求回文串时需要判断其奇偶性,也就是求aba和abba的算法略有差距。然而,这个算法做了一个简单的处理,很巧妙地把奇数长度回文串与偶数长度回文串统一考虑,也就是在每个相邻的字符之间插入一个分隔符,串的首尾也要加,当然这个分隔符不能再原串中出现,一般可以用‘#’或者‘$’等字符。这样一来,原来的奇数长度回文串还是奇数长度,偶数长度的也变成以‘#’为中心的奇数回文串了。
* 这里我们用一个辅助数组help记录以每个字符为中心的最长回文半径,也就是 help[i]记录以s[i]字符为中心的最长回文串半径。help[i]最小为 1,此时回文串为 s[i]本身。我们可以证明help[i]-1就是以s[i]为中心的回文串在原串当中的长度：首先help[i]记录的是扩展之后的字符串s[i]的最长回文串半径，则对应其回文串长度应该是2help[i]-1，而实际回文串长度若为a，则2a+1 = 2help[i]-1，因此得出a = help[i]-1。
* 之后依次从前往后求得help数组就可以了,这里用到了DP(动态规划)的思想,也就是求help[i]的时候,前面的help[]值已经得到了,我们利用回文串的特殊性质可以进行一个大大的优化。为了防止求help[i]向两边扩展时可能数组越界,我们需要在数组最前面和最后面加一个特殊字符,令 P[0]='$'最后位置默认为'\0'不需要特殊处理。此外,我们用MaxId变量记录在求i之前的回文串中,延伸至最右端的位置,同时用id记录取这个MaxId的id值。通过下面这句话,算法避免了很多没必要的重复匹配。
```cpp
if(MaxId>i){help[i]=Min(help[2*id-i],MaxId-i);}
```

* j=2id-i即为i关于id的对称点,根据对称性,help[j]的回文串也是可以对称到i这边的,但是如果help[j]的回文串对称过来以后超过MaxId的话,
超出部分就不能对称过来了,所以这里help[i]为的下限为两者中的较小者,help[i]=Min(p[2*id-i],MaxId-i)。这样的话，在查找i的最长回文子串时就可以直接跳过help[i]个字符，再进行回文串的匹配，可以避免很多重复的比较。

##NO.6 ZigZag Conversion
这道题是关于Z字形的题，用一个字符串数组ans[rows]来存储通过Z字形排列之后的每一行，最后一拼接就是最终结果。
* 用一个变量count表示正向还是反向读取row。当通过遍历输入的字符串s，row初始为0，然后用ans[row]记录当前行的字符串串接结果，row加上count，直至加到row超过numRows，count变成-1，即反向增1，也就是减1。
* 继续添加串接ans[row]，直至row小于0，再将count变为1，即正向增1，也就是加1。通过这样遍历完整个字符串之后，ans这个字符串数组也就构造成功。
* 最后只需要将ans的每一个字符串拼接即可。

还有一些方法，在源代码中我还提供了一种方法，是我自己想的，但是有些复杂，不提倡使用。

##NO.7 Reverse Integer
这道题比较简单，就是一个整数反转的问题，但是简单题也会有陷阱，也不能小瞧。
这道题主要就是要考虑到int的溢出情况，溢出则输出0。对于int类型，范围是-2^31 - 2^31-1。

##NO.8 String to Integer
这个题就是一个字符串转int的问题，看起来虽然简单，但是有很多细节问题需要注意。
* 空格跳过;
* 正数负数的判断;
* 超出int范围的判断;
* 非数字字符的判断，如果在正负号之后还出现了非数字字符，那么就直接break，只输出之前合法的数字字符构成的数字。

##NO.9 Palindrome Number
这个题就是一个判断int整数是否是回文整数。有两种解决方法。
* 直接对这个整数进行反转，就和第7题Reverse Integer一样，先求整数的反转整数，然后判断反转之后的整数是否和原整数相等。这里需要注意的是反转之后可能会出现整数溢出的情况，因此需要判断整数溢出的情况，而反转整数如果溢出说明原整数肯定不是回文整数，因为如果是回文整数，既然原整数未溢出，回文整数也必然未溢出。
* 第二种方法就是将该整数转换成字符串，然后通过讨论字符串长度，分奇数偶数两种情况进行考虑，判断其回文性。

##NO.10 Regular Expression Matching
这个题是一个关于正则表达式匹配的问题，这里只是匹配'.'和'\*'两种通配符。解题思路主要是递归，其实就是DFS，深度优先搜索的思想。
<br/>根据下一个字符是否是'\*'分情况判断。
* 1.如果是p的下一个'\*'，则当前s和p相等或者p='.'情况下，依次判断s和p[2]之后的字符串是否match；
* 2.如果p的下一个字符不是'*'，只需判断当前字符是否相等，或者p[cur]='.'且s不为空，递归处理s[1]和p[1]之后的字符串；

这里需要注意的一个地方是，题目中的测试用例中，isMatch("ab", ".\*") → true，这里可能会产生困惑，其实这里".\*"，'\*'是用来作用于'.'，
意思是说可以有0个或多个'.'，而'.'可以匹配任意单个字符。因此"ab"一定是匹配".\*"的。

##NO.11 Container With Most Water
这道题算是一道数学题，如果穷举所有可能的情况，时间复杂度是O(n^2)，会超时。
* 这道题的O(n)算法类似于two sum那道题，在height两头分别设一个指针，然后计算area，如果height[i] <= height[j]，那么i++。
* 如果height[i] > height[j]，那么j--。
* 因为在这里如果height[i] <= height[j]，移指针j的话，只会使得面积减少，决定盛水的高度是最矮的那个高度，而此时如果再移j指针，只会使得j-i宽度减少，那么面积肯定减少，因此需要j++，同理height[i] > height[j]的情况。

##NO.12 Integer to Roman
这道题是阿拉伯数字转罗马数字。首先罗马的单个基本数字共有7个，I(1), V(5), X(10), L(50), C(100), D(500), M(1000)
<br/>组合规则：
<br/>(1)基本数字Ⅰ、X、C 中的任何一个，自身连用构成数目，或者放在大数的右边连用构成数目，都不能超过三个；放在大数的左边只能用一个。
<br/>(2)不能把基本数字 V、L、D 中的任何一个作为小数放在大数的左边采用相减的方法构成数目；放在大数的右边采用相加的方式构成数目，只能使用一个。
<br/>(3)V 和 X 左边的小数字只能用Ⅰ。
<br/>(4)L 和 C 左边的小数字只能用X。
<br/>(5)D 和 M 左边的小数字只能用C。
<br/>有两种解法。
* 1.第一种就是把所有小数字在前的组合也作为基本数字，再做一个对应的数值表就可以解决问题了。对输入的需要转换的数字num从最大的基本数字1000开始比较，如果大于等于则添加一个对应的基本数字字符至结果字符串中，并将num减去对应的基本数字的值，然后继续判断。到小于这个基本数字就将基本数字降至更小的基本数字继续判断。
* 2.第二种方法就是将1-9，10-90，100-900，1000-3000这几个段内的数字全部用罗马数字表示并记录数组中。之后对输入的需要转换的数字num每次截取其低位的数字，并使用一个变量digit记录当前位数，找到对应该数字的罗马数字的表示，添加到结果字符串最最前面。然后将num除去低位数字，继续判断。

##NO.13 Roman to Integer
这道题是罗马数字转阿拉伯数字，相对于阿拉伯数字转罗马数字容易些。思路很简单，从前往后遍历罗马数字，如果某个数比前一个数小，则把该数加入到结果中；反之，则在结果中两次减去前一个数并加上当前这个数。

##NO.14 Longest Common Prefix
这道题是一个最长相同前缀匹配的题。
<br/>解题思路是，先对整个string数组预处理一下，求一个最小长度（最长前缀肯定不能大于最小长度）。然后以第1个字符串作为参照，将最小长度作为初始长度，将最小长度的字符串作为初始字符串，从第二个字符串开始和第一个字符串进行匹配，直到找到相同前缀停止，然后将最长前缀字符串lcprefix更新，最小长度minlen更新，i++，匹配下一个字符串。

##NO.15 3sum
这是一道求解三个数的和为0的题。是twosum那道题的升级版吧，但还是有些不同的。
* 1.因为要求3个数，如果我们固定其中1个数，再用求“和为某值的2个数的组合”的解法，就能把剩下的2个数求出来。
* 2.因此，先对数组进行升序排列，这样整个数组的数就由小到大排列。i的取值由0至n-3，对每一个i，我们求当num[i]是解当中的其中一个数时，其他的2个数。
* 3.设有指针p指向数组头(实际只要p从i+1开始)，q指向数组尾，sum = num[i]+num[p]+num[q]，因为num[i]是一定在解中的，所以
    * 如果sum < 0，因为num[q]已经不能增大，所以说明num[p]太小了，这时p需要向后移动，找一个更大的数。
    * 同理，sum > 0，说明num[q]太大了，需要q向前移动。
    * 当sum == 0时，说明找到了一个解。但找到了一个解，并不说明解中有num[i]的所有解都找到了，因此p或q还需要跳过那些nums[p]与前一个相同以及nums[q]与后一个相同的值的情况，这样可以去掉重复的情况，继续移动寻找其他的解，同时这里还需要直到p==q为止。
* 4.之后i++，以下一个位置作为固定位置，继续进行查找操作，但是这里也有一个去重操作，当前固定位置如果和前一个固定位置的数值相同则直接跳过，因为这样求解出来的组合肯定是和前一个固定位置相同的。

##NO.16 3Sum Closest
这道题和上一道题类似，这里是求解与目标和最接近的三个数的组合的和。
* 思路和上一题类似，也是固定一个位置，然后从这个位置的下一个位置开始作为start，数组末尾作为end，查找另外两个数，通过twosum那道题的思路。
* 这里需要使用两个变量，一个记录已经查找过的三个数组合的和与目标和的最小差值，取值为正数，一个是记录最小差值对应的三个数组合的和。初始状态最小差值closest取一个最大值，对应和closestsum初始为0即可。
* 然后计算sum = nums[i] + nums[p] + nums[q];
      * 如果sum > target，计算与targe的差值sum-target，并将其与最小差值closest比较，如果比closest小则更新closest为sum-target，同时更新closestsum = sum。
      * 如果sum < target，计算与target的差值，target-sum，并将其与最小差值closest比较，如果比closest小则更新closest和closestsum。
      * 如果sum == target则直接返回target即可。
* 最后返回closestsum即为最终结果。

##NO.17 Letter Combinations of a Phone Number
这道题我主要还是用比较基础的方法，通过循环来求解。最直观的思路是播了多少位号码，就用多少个for循环，遍历每位号码对应的字符串。还有一种比较好的办法是通过递归，使用DFS深度优先搜索来做。
* 1.这里我是通过先将第一个数字对应的字符分割开来，作为初始的字符结合结果lc，然后将这个结果和剩下的数字对应的字符串进行组合，遍历从第二个开始的数字对应的字符串，和lc的字符组合，得到组合结果，更新lc。然后继续下一个数字对应的字符串进行组合。直至最后。
* 2.深度优先搜索DFS。深度优先搜索时间复杂度O(n!)，一般提高其效率的方法是剪枝。
* 3.两种方法的时间复杂度，应该都是O(n!)。

##NO.18 4Sum
这是一道求解四个数的和为某个目标数的题。是3sum那道题的升级版。思路其实也和3sum那道题基本相同。
* 1.因为要求4个数，如果我们固定其中2个数，再用求“和为某值的2个数的组合”的解法，就能把剩下的2个数求出来。
* 2.因此，先对数组进行升序排列，这样整个数组的数就由小到大排列。通过两个循环来固定前面2个数，i的取值由0至n-4，对每一个i，我们求当num[i]是解当中的其中一个数时，再设定j为解当中的第二个数，j从i+1到n-3取值。其他的2个数的确定，设有指针p指向数组头(实际只要p从j+1开始)，q指向数组尾，sum = num[i]+num[j]+num[p]+num[q]，因为num[i]和sum[j]是一定在解中的，所以:
      * 如果sum < 0，因为num[q]已经不能增大，所以说明num[p]太小了，这时p需要向后移动，找一个更大的数。
      * 同理，sum > 0，说明num[q]太大了，需要q向前移动。
      * 当sum == 0时，说明找到了一个解。
* 但找到了一个解，并不说明解中有num[i]和num[j]的所有解都找到了，因此p或q还需要跳过那些nums[p]与前一个相同以及nums[q]与后一个相同的值的情况，这样可以去掉重复的情况，继续移动寻找其他的解，同时这里还需要直到p==q为止。
* 3.之后继续i和j循环以下一个位置作为固定位置，继续进行查找操作，但是这里也有两个去重操作，num[i]和num[j]去除前面相同的值，遇到就跳过即可，防止求解到相同的组合对。
* 4.时间复杂度是O(n^3)。

##NO.19 Remove Nth Node From End of List
这是一道关于链表的题，容易题，还是主要是熟悉链表的操作。

##NO.20 Valid Parentheses
这是一道关于括号匹配的题，基本思路其实就是通过栈的思想来做，这里不仅使用stack实现，同时也通过vector来实现了栈的功能。
* 一个个读取括号字符串中的字符，然后在将字符压入栈之前判断即将加入栈中的字符与栈首的字符串是否是括号匹配，如果匹配则将栈首的字符退出栈，继续读取字符进行判断操作。
* 最后栈为空则说明括号全部匹配成功，返回1，否则返回0。

##NO.21 Merge Two Sorted Lists
这又是一道关于链表的题，主要还是熟悉链表操作，就是合并排序，比较简单。

##NO.22 Generate Parentheses
这又是一道括号匹配的题目，和第20题不一样，第20题是判断括号匹配是否合法的题，而这道题正好想法，需要将所有合法的括号匹配情况列出来。这里需要说明的是该问题解的个数就是卡特兰数，但是现在不是求个数，而是要将所有合法的括号排列打印出来。
```cpp
令h(0)=1,h(1)=1，catalan数满足递推式[1]：
h(n)= h(0)*h(n-1)+h(1)*h(n-2) + ... + h(n-1)h(0) (n>=2)
例如：h(2)=h(0)*h(1)+h(1)*h(0)=1*1+1*1=2
h(3)=h(0)*h(2)+h(1)*h(1)+h(2)*h(0)=1*2+1*1+2*1=5
```
这道题的基本思想就是递归。假设在位置k我们还剩余left个左括号和right个右括号，如果left>0，则我们可以直接打印左括号，而不违背规则。能否打印右括号，我们还必须验证left和right的值是否满足规则，如果left>=right，则我们不能打印右括号，因为打印会违背合法排列的规则，否则可以打印右括号。如果left和right均为零，则说明我们已经完成一个合法排列，可以将其打印出来。

##NO.23 Merge k Sorted Lists
* 这又是一道链表的题，对多个已排序的链表进行合并，一开始的时候使用的算法是对这k个链表同时查找当前位置的这k个值的最小值，然后将对应链表指针往下一个移。直到最后指针全部指向链表尾部空处。结果发现超时，算法时间复杂度为O(N^2)。
* 查了一下网上的方法，采用归并排序可将链表排序的时间复杂度缩减到的O(NlgN)。
* 所以借鉴归并排序的方法，自顶向下，先递归的对链表的前半部分和后半部分进行归并排序，最后再merge。

##NO.24 Swap Nodes in Pairs
这又是一道链表的题，将相邻两个节点进行交换，不能是值的交换，必须做到两个节点的交换。不难，但是不能被指针指来指去弄晕了。

##NO.25 Reverse Nodes in k-Group
这又是一道链表的题，是第24题的升级版，有点难度。
* 采用的思路是递归，这里为了方便起见，对这个链表的头部添加了一个无用的-1节点。
* 在链表头部记录一个指针pos_ret，并pre_before = pos_ret，然后下一个位置再记录一个before，遍历k次得到要反转的尾部指针behind，然后将before和behind两个位置的指针反转，之后递归进行操作，此时k变为k-1，继续反转，直到k=2时停止。
* 然后再将pos_ret指针移至k次，至下一次操作。这里要注意如果pos_ret指针后面的节点个数小于k，不必反转。

##NO.26 Remove Duplicates from Sorted Array
这道题比较简单，去除重复数字，计算非重复数字的个数newlen，同时在原数组上前newlen个位置记录这newlen个非重复数字，不使用新的数组去接收。
* 解题思路很简单，首先初始newlen为0，之后只需要对原数组进行一次遍历，每次比较当前位置的数与前一个位置的数是否相同，
      * 如果不相同更新nums[newlen]的值为当前位置的值，newlen加1；
      * 如果相同则不进行任何操作，继续遍历执行。
* 时间复杂度为O(N)。

##NO.27 Remove Element
这道题其实也比较简单，题目意思就是要删除数组中为某个值的所有元素，同时计算删除了这些元素之后的数组长度newlen，并在原数组上的前newlen个位置记录所有未删除的元素，顺序不定。
* 基本思路也很简单，首先遍历一遍数组，求得newlen，并用一个数组pos[]记录所有需要删除的元素的位置。
* 之后再从数组的newlen位置开始遍历，直至数组末尾，判断当前位置的值是否是要删除的元素，如果是则跳过，如果不是则将newlen位置之前的需要删除的元素位置的值更新为该值。这里使用之前记录了删除元素位置的pos[]数组。
* 时间复杂度为O(N)

##NO.28 Implement strStr()
这道题是典型的模式串匹配的题，主要有两种解法:
* 一种是暴力求解，直接从原串第一个字符开始和模式串第一个字符匹配，匹配成功则原串第二个字符与模式串第二个字符匹配，如果匹配失败则将原串第二个字符串与模式串第二个字符匹配，依次进行下去。时间复杂度是O(mn)
* 另外一种高效的算法就是KMP算法。时间复杂度为O(m+n)

##NO.29 Divide Two Integers
* 这道题并不简单，一开始想的方法是直接用被除数减除数，直到减至小于除数，或者直接用除数去一个一个加，直到被除数被超过，这样会超时。
* 为了提高效率，初始的时候令sum等于除数，然后循环增加sum，每次都增加一倍，同时count也增加一倍，直到sum+sum大于了被除数，然后将被除数减去sum，再执行相同的操作。

##NO.31 Next Permutation
这道题就是一道字典序排列的题。其实可以求解全排列问题，把升序的排列（当然，也可以实现为降序）作为当前排列开始，然后依次计算当前排列的下一个字典序排列。
* 对当前排列从后向前扫描，找到一对为升序的相邻元素，记为i和j（i < j）。
* 如果不存在这样一对为升序的相邻元素，则所有排列均已找到，算法结束；
* 否则，重新对当前排列从后向前扫描，找到第一个大于i位置的元素k，交换i和k的值，然后对从j开始到结束的子序列反转，则此时得到的新排列就为下一个字典序排列。
* 这种方式实现得到的所有排列是按字典序有序的。

##NO.36 Valid Sudoku
这道题是关于数独的题，就是判断输入的不完整数独是否合法，并不需要其是否有解，其实就是分三种情况来判断：
* 1.判断每行不是空的格的数字是否是在1-9，并且没有重复。
* 2.判断每列不是空的格的数字是否是在1-9，并且没有重复。
* 3.判断每个九宫格的格的数字是否是在1-9，并且没有重复。

##NO.58 Length of Last Word
这道题非常简单，但要注意的是输入的时候，不能用cin，因为cin是以空格分开的。需要使用getline进行输入。

##NO.61 Rotate List
这道题是链表操作的题，和旋转数组那道题(189题)类似，只是这里是对链表进行旋转。这里对输入的k值进行了处理，首先求出链表的节点个数，然后将k对节点个数len取余，因为如果输入的k值超过了链表的实际节点个数，实际上只需要轮转k%len次即可。

##NO.66 Plus One
这道题比较简单，主要就注意加1之后的进位问题。

##NO.67 Add Binary
这道题比较简单，和第66题类似，只不过这里是算二进制的加法，并且是以字符串形式输入，还是要考虑进位的问题。

##NO.69 Sqrt(x)
这道题如果直接从0到x遍历其平方求解必然会超时，这里主要采用的是两种方法，二分法和牛顿迭代法。
* 1.二分法就不用说了，时间复杂度是O(logn)
* 2.牛顿迭代法：
      * 计算x2 = n的解，令f(x)=x2-n，相当于求解f(x)=0的解。首先取x0，如果x0不是解，做一个经过(x0,f(x0))这个点的切线，与x轴的交点为x1。
      * 同样的道理，如果x1不是解，做一个经过(x1,f(x1))这个点的切线，与x轴的交点为x2。以此类推。以这样的方式得到的xi会无限趋近于f(x)=0的解。
      * 判断xi是否是f(x)=0的解有两种方法：一是直接计算f(xi)的值判断是否为0，二是判断前后两个解xi和xi-1是否无限接近。
      * 可求得迭代公式xi+1= (xi + n/xi) / 2

##NO.70 Climbing Stairs
这道题其实很常见，一般的解法有两种，一种是递归求解，一种是动态规划。
* 递归的求解方法很容易超时。
* 而动态规划的解法效率高，典型的空间换时间。状态转移方程非常简单：
```cpp
nums[i] = nums[i-1]+nums[i-2];
```
##NO.82 Remove Duplicates from Sorted List II
这道题和第83题其实是属于相似题，第83题是删除重复值，重复值留一个，而这道题所有重复值节点全部删除，不留任何有重复值的节点。为了方便起见，在链表头部添加一个无用节点-1，初始时before指针指向-1，behind指针指向head，循环判断behind指针是否为空，分两种情况讨论：
* 1.behind的下一节点不空且behind节点的值与下一节点的值不等或者下一节点为空，则直接将before和behind两个指针往后移一个位置即可。
* 2.如果不是第1种情况，则循环查找，直至behind指针指到非重复值的节点位置，然后将before指针的next指向behind。

然后重复操作1和2步骤即可，直至behind为空。最终的返回结果是最初的before指针的next。这里用一个result指针记录了。

##NO.83 Remove Duplicates from Sorted List
这道题是链表操作的题，其实和第26题基本一样，只是一个是数组，一个是链表，这里链表的操作的话也还是比较简单的，只需要在开头设置两个指针，一个before一个behind，然后循环将behind指向与前面节点值不一样的节点，也就是跳过相同值的节点，之后则将before的next指向behind，这样就将中间重复的值的节点删去了。之后将before设置为当前的behind，继续执行相同的操作，删除下一个重复值的节点。

##NO.88 Merge Sorted Array
这道题和之前做过的两个有序链表合并(第21题)以及找两个有序数组的中位数(第4题)其实也差不多，只是这里可能涉及到更多的C++ vector的操作。因为这里是在其中一个数组的基础上添加进另一个有序数组，需要在该数组上进行插入删除等操作。

##NO.100 Same Tree
这道题是关于二叉树的题，非常基础的题，递归思路。这道题主要就是熟悉二叉树的相关操作，这里给出了一个前序输入二叉树的函数。

##NO.101 Symmetric Tree
这道题是关于二叉树的题，判断一棵二叉树是否是对称二叉树，非常基础的题，递归思路。

##NO.102 Binary Tree Level Order Traversal
这道题是关于二叉树的题，递归思路，其实就是深度优先搜索DFS。

##NO.125 Valid Palindrome
这个题主要就是判断回文串，但是是有干扰字符的回文串，如果先对字符串进行预处理，除去非字母数字的话会出现超时，因为字符串可能会很长，而实际上它并不是回文串。因此不能对其进行预处理，应该直接对其进行操作，从头部尾部往中间查找匹配，非字母数字的跳过。

##NO.169 Majority Element
这道题比较简单，思路很简单，就是对数组进行一个升序排列即可，然后找到出现次数最多的数，时间复杂度为O(n)。

##NO.189 Rotate Array
这道题比较简单，提倡多种方法求解。目前使用的就是利用vector相关操作，按照规则做一遍实现的。

##NO.202 Happy Number
这道题还是比较简单。按照题目意思进行计算判断是否为happy number，如果是happy number最终会得到1，如果计算出现了之前的数则说明进入了无限循环中，没有1。

##NO.203 Remove Linked List Elements
这道题是链表操作的题，就是删除指定值的节点，比较简单。为方便起见，在链表头部添加了一个额外的节点-1。

##NO.217 Contains Duplicate
这道题非常简单，就是对数组进行一个排序，然后依次遍历排序后的数组，出现了重复数字即输出1，遍历完成之后若还没有重复，则最后输出0。时间复杂度是O(n)。

##NO.219 Contains Duplicate II
这道题本来是简单的，但是一开始使用的方法超时，时间复杂度有O(n*k)，之后换了一种方法，使用了STL中的set容器。写这个程序是首次学习C++ STL的set容器。
* 首先定义一个长度最大为k的滑动窗口，用一个set维护窗口内的数字判断是否出现重复，使用两个指针start和end标记滑动窗口的两端，
初始都是0，然后end不断进行扩展，扫描元素判断是否出现重复元素，直到发现end-start>k,就开始移动start，并且在set中移除start位置的元素。
* 然后进行下一轮的比较。如果end扫描到数组末尾还没有发现重复元素，那就可以返回false。

##NO.226 Invert Binary Tree
这道题是关于二叉树的题，左右倒置二叉树，非常基础的题，递归思路，交换左右子树。

##NO.231 Power of Two
这道题是目前写过的最短的程序了。判断一个整数n是否是2的n次方，一个非常巧妙和简单方法是，将n减去1，
然后将减去1之后的数与n进行与操作，若结果为0，则说明是2的n次方。
其原理是：一个数若是2的n次方，表示成二进制，则是100...00,如果减去1就是111...11，比n少一位，若两个数进行与操作，则得到的结果肯定为0。

##NO.234 Palindrome Linked List
这道题是链表操作的题，求一个链表是否是回文。有两种解决办法。
* 1.遍历一遍链表，并将节点的值存入数组中，然后对数组进行判断，这样就和判断回文串一样了。这种方法时间复杂度是O(n)，空间复杂度也是O(n)。
* 2.将链表从中间断开，分成两个链表，对后半段链表进行翻转，然后遍历两个链表依次比较节点的值。这种方法时间复杂度是O(n)，空间复杂度是O(1)。

##NO.237 Delete Node in a Linked List
这道题是链表操作的题，比较简单。但是这里有一个疑问，链表或者二叉树初始化时，
通过传参至一个函数或方法中去初始化，到底传参传普通参数还是引用或指针的指针呢？好像直接传指针的普通参数也可以啊。
<br/>
疑问解答：
* void f(NODE \*S)传了一个指针参数，这个参数是一个临时的变量在栈中，因此它的改变是不会改变指针的值(即实参的值)，但是由于是一个指针它可以改变S所指向的变量的值通过\*S或S->。
* void f(NODE\* &S)传了一个指针参数，但是是引用类型（其实引用类型就是为了代替C中的指针使其少用指针）引用类型相当于一个别名和操作实参是一样的，其改变会反映到实参因此这个指针值本身是可以改变的可以指向另一变量，当然可以通过它修改它所指向的对象的值。
