# leaning-Data-structure-and-algorithm




[我的LeetCode](https://leetcode-cn.com/u/zhenglin_li/)

[我发布的视频题解](https://space.bilibili.com/123906587)


写的不对的敬请指正
# 1 ｜ 动态规划
## 动态规划三要素：重叠子问题，最优子结构，状态转移方程
- 重叠子问题

![image.png](https://p1-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/ce3d4e3b2f594da48d91fc4568702267~tplv-k3u1fbpfcp-watermark.image?)
比如求解斐波那契数列，不带备忘录的递归方法中，画出递归树后，发现某些值（例如图中18和17等）要重复计算很多次，这就是重叠子问题

- 最优子结构
    - 子结构之间相互独立
    学高中集合时，大家一定听过这句话：不重不漏。</br></br>
    在动态规划中，简而言之：**一定满足不漏**，要把所有情况考虑在内；**某些问题**，例如求和等还要不重，但求最值的子结构就**可以重复**
    
    - 子结构的最优解可以推出原问题的最优解
    子结构的最优解可以推出原问题的最优解不是动态规划独有的
    
- 状态转移方程
    - 描述状态间的转化关系
    
## 动态规划解题五步
1. **确定DP数组的含义，包括数组下标和数组值的含义**
一般来说，`dp[i]`表示当输入数据为`i`时的问题答案

2. **确定状态转移方程**
当前位置的状态怎么转移而来？

3. **确定初始值**
也就是base case的值，不能由状态转移方程得到

4. **确定遍历顺序和得到答案方式**
遍历时，应该考虑状态转移方程中得到当前位置值依赖哪些位置的值，所依赖的状态必须在当前位置之前被计算出来</br></br>
得到答案的方式指的是，某些题目的答案为遍历最后一个位置，有些题目的答案则要求取遍历过程中每一个位置的最大值等等

5. **举例推导DP数组**
验证答案的正确性

# 2 ｜ 回溯算法

回溯算法的**本质是暴力枚举**，解决的是：某些问题想暴力遍历结果连代码都写不出来的问题</br></br>
回溯法解决的问题都可以抽象为树形结构，**遍历过程可以抽象为对决策树的遍历**</br></br>
## 需要思考三个问题：
- **终止条件**
决策树到叶子，此时的情况时没有选项可选或者路径已经不满足题目的要求
- **已走路径**
保存此时的已选项，一般情况下，到终止条件时直接把路径加到结果集合里就完事了
- **待选择列表**
可以选择的项目，这里关系到是否需要函数的参数列表是否需要`startIndex`和`for`循环中`i`的初始值
</br></br>
## 模板：

```java
    private List<List<Integer>> res = new ArrayList<>();
    
    public void solutionFuncion(){
        backtrack();
        return res;
    }

    private void backtrack(List<Integer> path){
        if (结束条件){
            res.add(path);
            return;
        }
        for (){
            // 选择
            backtrack();
            // 撤销选择
        }
    }
```

## 去重
- **选择列表去重**（树叶，同一层，横向）
需要排序和`used`数组，做选择和撤销选择时也要考虑`used`数组

```java
if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
    continue;
}
```
- **路径去重**（树枝，纵向）
需要在`for`循环中的递归函数传递`startIndex`时进行`+1`操作

# 3 ｜ 双指针
双指针的应用在数组和链表的题目中尤为常见
## 3 . 1  ｜ 快慢指针
一快一慢两个指针同向而行<br><br>
解决的问题：
- 判断链表是否成环
- 求出环入口
- 找链表中点
- 倒数第`k`个节点<br><br>
我的初始化习惯：一快一慢的指针从链表头和链表头下一个节点出发，快指针每次走两步，慢指针每次走一步
```java
ListNode slow = head, fast = head.next;
while (fast != null && fast.next != null){
    // do something
    slow = slow.next;
    fast = fast.next.next;
}
```

## 3 . 2  ｜左右指针
一左一右两个指针相向而行<br><br>
解决的问题：
- 二分查找
- 两数之和
- 反转数组

## 3 . 3  ｜二分查找
二分查找其实是左右指针的应用之一，但由于其**思想的简单和细节的困难**，值得单独注意<br>

以这题为例：[[704. 二分查找]](https://leetcode-cn.com/problems/binary-search/)


### 整形溢出
```java
        int a = Integer.MAX_VALUE;
        int b = Integer.MAX_VALUE;
        System.out.println((a + b) / 2);         // 错误，整形溢出
        System.out.println(a + (a - b) >> 1);    // 错误，位运算优先级最低
        System.out.println(a + (a - b) / 2);     // 正确
        System.out.println((a + b) >>> 1);       // 正确，>>> 就算溢出也能得到正确答案
```
<br>


### 循环不变量
循环不变量指的是在循环中我们应该保持的定义，理解循环不变量对二分的细节很重要！<br><br>
对窗口的定义是确定循环不变量的第一步，个人来说一半选择`左闭右闭`区间，即窗口是`[left, right]`
- 初始化 
因为`左闭右闭`区间的窗口是`[left, right]`，所以初始化

```java
int left = 0;
int right = nums.length - 1;
```

- 循环条件 
循环条件为窗口满足定义的状态，`left == right`时窗口内有一个元素，满足条件，很显然循环条件为

```java
while(left <= right)
```

- 循环中收缩方式
为什么是`left = middle + 1`和`right = middle - 1`呢？

我们知道，此时的`middle`不满足题目要求，所以要进行收缩，因为`middle`已经不满足被排除在外了，自然在`[middle + 1，rihgt]`和`[left，middle - 1]`内搜索就可以了

```java
if (nums[middle] == target) return middle;
else if (nums[middle] < target) left = middle + 1;
else if ((nums[middle] > target)) right = middle - 1;
```

- 循环结束时状态

根据循环结束条件，推出循环时不满足`left <= right`并且循环内的收缩方式是每次收缩一个方向的一位，所以循环结束时，有`left = right + 1`<br><br>
循环结束条件有时需要用于对答案的判断，不过二分查找倒是用不到


### 完整代码：

```java
class Solution {
    public int search(int[] nums, int target) {
        // 特殊条件提前返回
        if (target < nums[0] || target > nums[nums.length - 1]) 
            return -1;
        // 搜索区间为[left, right]，左闭右闭
        int left = 0, right = nums.length - 1;
        while (left <= right) {
            // 不能放溢出，但能防溢出出错
            int middle = (left + right) >>> 1;
            if (nums[middle] == target) 
                return middle;
            else if (nums[middle] < target) 
                left = middle + 1; // 注意
            else if (nums[middle] > target) 
                right = middle - 1; // 注意
        }
        return -1;
    }
}
```


```java
class Solution {
    public int search(int[] nums, int target) {
        if (target > nums[nums.length - 1] || target < nums[0])
            return -1;
        // now the window is [left, right)
        int left = 0, right = nums.length;
        // if left == right, no element in the window because of [)
        while (left < right){
            int middle = left +  (right - left) / 2;
            if (nums[middle] == target)
                return middle;
            else if (nums[middle] < target)
                left = middle + 1; // [left + 1, right]
            else if (nums[middle] > target)
                right = middle;  // [left, right)
        }
        return -1;
    }
}
```
### 变形
[33. 搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array)<br><br>
[34. 在排序数组中查找元素的第一个](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array)<br><br>
[35. 搜索插入位置](https://leetcode-cn.com/problems/search-insert-position)

## 3 . 4  ｜滑动窗口
思想：增大窗口，满足条件时，试图缩小窗口，直到条件不再满足，再增大窗口……<br><br>
`for`循环找可行解，`while`循环找最优解<br><br>
难点：窗口状态的维护和细节<br><br>
模板：
```java
int left = 0;
for (int right = 0; right < array.length; right++){
    char ch = array[right];
    /* 维护添加ch后的窗口状态 */
    // 因为是for循环所以不需要right++
    while (满足题目要求){
        char delete = array[left];
        /*  维护删除delete后的窗口状态 */
        left++;
    }
}
```
例题：[leetcode题解](https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/solution/zheng-zong-hua-dong-chuang-kou-by-zhengl-deue/)

# 4 ｜ DFS

再次理解二叉树的遍历：<br><br>
何为先序？对节点的处理在进入节点前<br><br>
何为后序？对节点的处理在出节点后<br><br>
之前说过，**回溯算法就是对决策树的遍历**，所有**做出选择在调用递归方程前**，**撤销选择在调用递归方程后**<br><br>
刷题这么久才领悟到这一点，实在惭愧


# 5 ｜ BFS

BFS的二叉树模板：

```java
public List<List<Integer>> levelOrder(TreeNode root) {
        Deque<TreeNode> queue = new ArrayDeque<>();
        if (root == null)
            return list;
        queue.offerLast(root);
        while (!queue.isEmpty()){
            // 一定要用零时遍历储存size，因为队列的大小是在动态变化的
            int size = queue.size();
            List<Integer> each = new ArrayList<>();
            for (int i = 0; i < size; i++){
                TreeNode node = queue.pollFirst();
                /*  对节点的处理  */
                // 例如 eachLevel.add(node.val);
                if (node.left != null)
                    queue.offerLast(node.left);
                if (node.right != null)
                    queue.offerLast(node.right);
            }
            /*  对层的处理  */
            // 例如 level++，res.add(eachLevel)等等
        }
        return list;
    }
```
理解：
- BFS适用于**找最短路径**，因为所有节点是**齐头并进**的，一旦某个节点找到了重点就可以停止<br><br>
- 如果是在**图**的BFS中，要用`visited`哈希表来**去重**，防止走回头路，但在二叉树中不需要因为没有子节点指向父节点的指针<br><br>
- 对于知道终点的BFS，可以优化为双向BFS来用空间换时间，不过渐进时间复杂度和空间复杂度都不变<br><br>
- 空间复杂度较高，为`O(n)`<br><br>
- DFS也可以找最短路径，空间复杂度为`O(lgn)`，因为递归产生的栈最多为二叉树的高度
