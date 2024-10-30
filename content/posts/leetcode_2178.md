
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2178: Maximum Split of Positive Even Integers"
date = "2018-11-14"
description = "Solution to Leetcode 2178"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-split-of-positive-even-integers/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<long long> ans;
    vector<long long> maximumEvenSplit(long long sum) {
        vector<long long> tmp;
        if(sum % 2 == 1) return ans;
        
        int cur = 2;
        while(sum >= cur) {
            ans.push_back(cur);
            sum -= cur;
            cur += 2;
        }
        if(sum > 0) ans[ans.size() - 1] += sum;
        
        return ans;
    }
    
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

