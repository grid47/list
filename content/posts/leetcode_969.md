
+++
authors = ["Yasir"]
title = "Leetcode 969: Pancake Sorting"
date = "2022-03-04"
description = "Solution to Leetcode 969"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/pancake-sorting/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        
        
        // find next largest
        // flip its index so that largest come first
        // flip one more time, so that the first goes to end
        
        vector<int> res;
        int i;
        for(int x = arr.size(); x > 0; x--) {
            for(i = 0; arr[i] != x; i++) {};
            reverse(arr.begin(), arr.begin() + i + 1);
            res.push_back(i + 1);
            reverse(arr.begin(), arr.begin() + x);
            res.push_back(x);
        }
        
        return res;
    }
};
{{< /highlight >}}

