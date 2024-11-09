
+++
authors = ["grid47"]
title = "Leetcode 22: Generate Parentheses"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 22: Generate Parentheses in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/generate-parentheses/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/22.jpeg" 
    alt="A swirl of parentheses gently unfolding, forming balanced pairs that radiate a sense of calm."
    caption="Solution to LeetCode 22: Generate Parentheses Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    void gen(string op, vector<string> &ans, int open, int closed, int n, int i) {
        if(i== 2*n) {
            ans.push_back(op);
            return;
        }
        
        if(open < n) {
            gen(op + "(", ans, open + 1, closed,n, i + 1);
        }
        if(open > closed) {
            gen(op + ")", ans, open, closed + 1,n, i + 1);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        gen("", ans, 0, 0, n, 0);
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/22.md" >}}
---
{{< youtube 7aSAbqCWhwE >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #23: Merge k Sorted Lists](https://grid47.xyz/posts/leetcode-23-merge-k-sorted-lists-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
