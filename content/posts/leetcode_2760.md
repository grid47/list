
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2760: Longest Even Odd Subarray With Threshold"
date = "2017-04-11"
description = "Solution to Leetcode 2760"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-even-odd-subarray-with-threshold/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
  int longestAlternatingSubarray(vector<int>& n, int threshold) {
    int res = 0;
    for (int l = 0, cnt = 0; l < n.size(); ++l) {
        if (n[l] <= threshold)
            cnt = cnt == 0 ?
                n[l] % 2 == 0 :
                n[l] % 2 == n[l - 1] % 2 ? n[l] % 2 == 0 : cnt + 1;
        else
            cnt = 0;
        res = max(res, cnt);
    }
    return res;
  }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

