
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1343: Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold"
date = "2021-02-26"
description = "Solution to Leetcode 1343"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int th) {
        int cnt = 0, sum = 0;
        th = th * k;
        for(int i = 0; i < k; i++) {
            sum += arr[i];
        }
        cnt += sum >= th;
        for(int i = k; i < arr.size(); i++) {
            sum += arr[i];
            sum -= arr[i - k];
            if(sum >= th) cnt++;
        }
        return cnt;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

