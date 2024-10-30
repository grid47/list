
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1423: Maximum Points You Can Obtain from Cards"
date = "2020-12-08"
description = "Solution to Leetcode 1423"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/)

---
{{< youtube TsA4vbtfCvo >}}
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

