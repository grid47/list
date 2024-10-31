
+++
authors = ["Crafted by Me"]
title = "Leetcode 3005: Count Elements With Maximum Frequency"
date = "2016-08-10"
description = "Solution to Leetcode 3005"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-elements-with-maximum-frequency/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> frq;
        int mx = 0;
        for (int num : nums) {
            frq[num]++;
            mx = max(mx, frq[num]);
        }

        int cnt = 0;
        for (auto it : frq) {
            if (it.second == mx)
                cnt++;
        }

        int net = mx * cnt;

        return net;
    }
};
{{< /highlight >}}



---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

