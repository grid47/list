
+++
authors = ["grid47"]
title = "Leetcode 2530: Maximal Score After Applying K Operations"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2530: Maximal Score After Applying K Operations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximal-score-after-applying-k-operations/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        long long ans = 0;
        while(k--) {
            int tmp = pq.top();
            cout << tmp << " ";
            ans += tmp;
            pq.pop();
            pq.push(ceil(tmp/3.0));
            
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2530.md" >}}
---
{{< youtube nsOipmYbRlc >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2531: Make Number of Distinct Characters Equal](https://grid47.xyz/posts/leetcode-2531-make-number-of-distinct-characters-equal-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}