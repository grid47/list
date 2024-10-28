
+++
authors = ["Yasir"]
title = "Leetcode 658: Find K Closest Elements"
date = "2023-01-10"
description = "Solution to Leetcode 658"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-k-closest-elements/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size() -k;
        while(l < r) {
            int m = (l + r) / 2;
            if(x - arr[m] > arr[m + k] - x) {
                l = m + 1;
            } else r = m;
        }
        
        return vector<int>(arr.begin() + l, arr.begin() + l + k);
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

