
+++
authors = ["Crafted by Me"]
title = "Leetcode 1718: Construct the Lexicographically Largest Valid Sequence"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1718: Construct the Lexicographically Largest Valid Sequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int n;
    vector<int> constructDistancedSequence(int n) {
        this-> n = n;
        vector<int> ans(2 * n - 1, 0);
        
        vector<int> vis(n + 1, 0);
        
        bt(ans, vis, 0);
        
        return ans;
        
    }
    
    bool bt(vector<int> &ans, vector<int> &vis, int idx) {
        
        if(idx == ans.size()) return true;
        
        if(ans[idx] != 0) return bt(ans, vis, idx + 1);
        else {

            for(int i = n; i >= 1; i--) {

                if(vis[i]) continue;
                
                vis[i] = 1;
                ans[idx] = i;
                
                if(i == 1) {
                    if(bt(ans, vis, idx + 1)) return true;
                } else if (idx + i < ans.size() && ans[idx + i] == 0) {
                    ans[idx + i] = i;
                    if(bt(ans, vis, idx + 1)) return true;
                    ans[idx + i] = 0;                    
                }
                ans[idx] = 0;
                vis[i] = 0;
                
            }

        }
        return false;
        
    }
    
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1718.md" >}}
---
{{< youtube 3kRBmhoA9b8 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1719: Number Of Ways To Reconstruct A Tree](https://grid47.xyz/posts/leetcode_1719) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

