
+++
authors = ["Crafted by Me"]
title = "Leetcode 2155: All Divisions With the Highest Score of a Binary Array"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2155: All Divisions With the Highest Score of a Binary Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;
        for(int i = 0; i < n; i++)
        if (nums[i] == 1) ones++;
        
        int mx = ones;
        vector<int> mxx;
        mxx.push_back(0);

        int zeros = 0;
        
        int prv, cur = mx;
        for(int i = 1; i < n + 1; i++) {
            zeros += ((nums[i - 1] == 0)? 1 : 0);
            ones  -= ((nums[i - 1] == 1)? 1 : 0);

            prv = mx;
            cur = zeros + ones;
            mx  = max(mx, cur);

                 if (mx == cur && cur == prv) mxx.push_back(i);
            else if (mx >  prv) {
                mxx.clear();
                mxx.push_back(i);
            }
        }
        
        return mxx;
    }
};
{{< /highlight >}}


---
{{< youtube jAn_1AC2VMo >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2156: Find Substring With Given Hash Value](https://grid47.xyz/posts/leetcode_2156) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

