
+++
authors = ["Crafted by Me"]
title = "Leetcode 2530: Maximal Score After Applying K Operations"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2530: Maximal Score After Applying K Operations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
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


---
{{< youtube nsOipmYbRlc >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2531: Make Number of Distinct Characters Equal](https://grid47.xyz/posts/leetcode_2531) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

