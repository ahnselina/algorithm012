### 第四周学习内容
本周主要复习如下内容：
* 深度优先搜索（DFS）和广度优先搜索(BFS)
* 贪心算法
* 二分查找


#### 深度优先搜索（DFS）和广度优先搜索(BFS)
常见的实现方式是使用递归实现
非递归版本：
* DFS可以用一个栈来实现
* BFS可以用一个队列来实现

树的DFS
```
def dfs(node): 
 
if node in visited: 
# already visited 
return
 visited.add(node) 
 # process current node 
# ... # logic here 
 dfs(node.left) 
 dfs(node.right)
```

一般情况下的DFS（图也可以用）
```
visited = set() 
def dfs(node, visited): 
if node in visited: # terminator 
# already visited 
return 
 visited.add(node) 
# process current node here. 
...
for next_node in node.children(): 
 if not next_node in visited: 
 dfs(next_node, visited)
```

#### 贪心算法

贪心算法是一种在每一步选择中都采取在当前状态下最好或最优（即最有
利）的选择，从而希望导致结果是全局最好或最优的算法。   
贪心算法与动态规划的不同在于它对每个子问题的解决方案都做出选择，**不能回退**。  
动态规划则会保存以前的运算结果，并根据以前的结果对当前进行
选择，**有回退功能**。


贪心法可以解决一些最优化问题，如：求图中的最小生成树、求哈夫曼编码
等。然而对于工程和生活中的问题，贪心法一般不能得到我们所要求的答
案。  
   **局部最优解未必是全局最优解**  
一旦一个问题可以通过贪心法来解决，那么贪心法一般是解决这个问题的最
好办法。由于贪心法的高效性以及其所求得的答案比较接近最优结果，贪心
法也可以用作辅助算法或者直接解决一些要求结果不特别精确的问题。


#### 二分查找

非递归实现
```c++
using namespace std;
// 二分查找法,在有序数组arr中,查找target
// 如果找到target,返回相应的索引index
// 如果没有找到target,返回-1
template<typename T>
int binarySearch(T a[], int n, T target)
{
    int l = 0;
    int r = n-1;
    //在[l, r]中查找
    while(l <= r)
    {
        // 防止极端情况下的整形溢出，使用下面的逻辑求出mid
        int mid = l+(r-l)/2;
        if(target < a[mid])
        {
            r = mid-1;
        }
        else if(target > a[mid])
        {
            l = mid+1;
        }
        else
        {
            return mid;
        }
    }

    //没有找到target，返回-1
    return -1;
}
```

递归实现
```c++
template<typename T>
int __binarySearch(T a[], int l, int r, T target)
{
    if(l > r)
    {
        return -1;
    }

    int mid = l+(r-l)/2;
    if(target == a[mid])
    {
        return mid;
    }
    else if(target < a[mid])
    {
        return __binarySearch(a, l, mid-1, target);
    }
    else
    {
        return __binarySearch(a, mid+1, r, target);
    }
}

template<typename T>
int binarySearchR(T a[], int n, T target)
{
    __binarySearch(a, 0, n-1, target);
}
```