
+++
authors = ["Crafted by Me"]
title = "Leetcode 436: Find Right Interval"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 436: Find Right Interval in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-right-interval/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& iv) {
        map<int, int> mk;
        
        int n = iv.size();
        for(int i = 0; i < n; i++)
            mk[iv[i][0]] = i;
        
        vector<int> ans(n, -1);
        for(int j = 0; j < n; j++) {
            auto i= iv[j];
            if(mk.lower_bound(i[1]) != end(mk))
                ans[j] = mk.lower_bound(i[1])->second;
        }
        
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/436.md" >}}
---
{{< youtube VEBbumHmps8 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #437: Path Sum III](https://grid47.xyz/posts/leetcode_437) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

