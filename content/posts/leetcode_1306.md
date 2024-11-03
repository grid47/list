
+++
authors = ["Crafted by Me"]
title = "Leetcode 1306: Jump Game III"
date = "2021-04-06"
description = "In-depth solution and explanation for Leetcode 1306: Jump Game III in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/jump-game-iii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        int n = arr.size();
        queue<int> q;
        q.push(start);

        while(!q.empty()) {
            int i = q.front();
            q.pop();

            if (arr[i] == 0)
                return true;
            int l = i - arr[i];
            int r = i + arr[i];
            arr[i] = -arr[i];
            if (l > -1 && arr[l] > -1) q.push(l);
            if (r < n  && arr[r] > -1) q.push(r);
        }
        
        return false;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1306.md" >}}
---
{{< youtube 9oUhzPLmLZQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1307: Verbal Arithmetic Puzzle](https://grid47.xyz/posts/leetcode_1307) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

