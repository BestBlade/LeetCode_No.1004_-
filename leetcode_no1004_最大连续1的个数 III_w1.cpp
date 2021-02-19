/* ------------------------------------------------------------------|
给定一个由若干 0 和 1 组成的数组 A，我们最多可以将 K 个值从 0 变成 1 。

返回仅包含 1 的最长（连续）子数组的长度。

 

示例 1：

输入：A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
输出：6
解释：
[1,1,1,0,0,1,1,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 6。
示例 2：

输入：A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
输出：10
解释：
[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 10。
 

提示：

1 <= A.length <= 20000
0 <= K <= A.length
A[i] 为 0 或 1 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-consecutive-ones-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	滑动窗口双指针法
*
*	执行用时：56 ms, 在所有 C++ 提交中击败了90.52%的用户
*	内存消耗：50.1 MB, 在所有 C++ 提交中击败了83.14%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

int longestOnes(vector<int>& A, int K) {
    int l = 0;
    int r = 0;
    while (r < A.size()) {
        //K大于0时总是扩大窗口
        if (!A[r++]) {
            K--;
        }
        //K小于0时总是平移窗口，根据A[l]的情况选择是否变动K的值
        if (K < 0 && !A[l++]) {
            K++;
        }
    }
    return r - l;
    //此为上面的详细版
    //while (r < A.size()) {
    //    //如果A[r]为1就扩展窗口
    //    if (A[r]) {
    //        r++;
    //    }
    //    //否则减去K值继续扩展最大窗口
    //    else {
    //        K--;
    //        r++;
    //    }
    //    //当K为-1时
    //    if (K < 0) {
    //        //A[l]为1并不能回填K,同时又要保持当前的最大窗口，因此将l和上面的r一样同步+1
    //        if (A[l]) {
    //            l++;
    //        }
    //        //当A[l]为0时，就可以去除A[l]并将K回增1
    //        else {
    //            K++;
    //            l++;
    //        }
    //    }
    //}
    //return r - l;
}

int main() {
    vector<int> A = { 1,1,1,0,0,0,1,1,1,1,0 };
    longestOnes(A, 2);
}