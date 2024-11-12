
+++
authors = ["grid47"]
title = "Leetcode 1423: Maximum Points You Can Obtain from Cards"
date = "2024-06-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1423: Maximum Points You Can Obtain from Cards in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sliding Window","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n = card.size();
        vector<int> frt, bck;
        frt.push_back(0);
        bck.push_back(0);
        for(int i = 0; i < n; i++) {

        frt.push_back(frt.back() + card[i]);
 bck.push_back(bck.back() + card[n - 1 - i]);

        }

        int ans = bck[k];
        for(int i = 1; i <= k; i++) {
            
            ans = max(ans, frt[i] + bck[k - i]);
            }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1423.md" >}}
---
{{< youtube TsA4vbtfCvo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #1424: Diagonal Traverse II](https://grid47.xyz/posts/leetcode-1424-diagonal-traverse-ii-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
