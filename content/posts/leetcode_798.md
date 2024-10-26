
+++
authors = ["Yasir"]
title = "Leetcode 798: Smallest Rotation with Highest Score"
date = "2022-08-21"
description = "Solution to Leetcode 798"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/smallest-rotation-with-highest-score/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:

    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        vector<int> change(n, 0);
        for(int i = 0; i < n; i++) {
            change[(i - nums[i] + 1 + n) % n]--;
        }
        for(int i = 1; i < n; i++) {
            change[i] += change[i - 1] + 1;
        }
        return distance(change.begin(), max_element(change.begin(), change.end()));
    }
};
{{< /highlight >}}

