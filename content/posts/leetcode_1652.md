
+++
authors = ["Crafted by Me"]
title = "Leetcode 1652: Defuse the Bomb"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1652: Defuse the Bomb in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/defuse-the-bomb/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        
        int n = code.size();
        vector<int> ans(n, 0);
        
        if(k == 0) return ans;
        
        int sum = 0;
        if(k > 0) {
            for(int i = 1; i < k + 1; i++)
                sum += code[i];
            ans[0] = sum;
            for(int i = 1; i < n; i++) {
                sum += code[(i + k) % n];
                sum -= code[i];
                ans[i] = sum;
            }
            return ans;
        }

        for(int i = 0; i < abs(k); i++)
            sum += code[n - 1 - i];
        ans[0] = sum;
        for(int i = 1; i < n; i++) {
            sum += code[i - 1];
            sum -= code[(i - 1 - abs(k) + n) % n];
            ans[i] = sum;
        }
        return ans;        
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1652.md" >}}
---
{{< youtube r81OUfKmGtM >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1653: Minimum Deletions to Make String Balanced](https://grid47.xyz/posts/leetcode_1653) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

