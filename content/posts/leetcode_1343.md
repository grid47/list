
+++
authors = ["Crafted by Me"]
title = "Leetcode 1343: Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold"
date = "2021-02-28"
description = "In-depth solution and explanation for Leetcode 1343: Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1343.md" >}}
---


"| 1344: Angle Between Hands of a Clock |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

