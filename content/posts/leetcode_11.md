
+++
authors = ["Yasir"]
title = "Leetcode 11: Container With Most Water"
date = "2024-10-17"
description = "Solution to Leetcode 11"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/container-with-most-water/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int i = 0, j = height.size() -1;
        
        while(i < j) {
            res = max(res, min(height[i], height[j]) * (j - i));
            if(height[i] < height[j])
                i++;
            else j--;
        }
        return res;
    }
};
{{< /highlight >}}

