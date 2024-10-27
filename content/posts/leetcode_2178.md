
+++
authors = ["Yasir"]
title = "Leetcode 2178: Maximum Split of Positive Even Integers"
date = "2018-11-11"
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

**Code:**

{{< highlight html >}}
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

