
+++
authors = ["Crafted by Me"]
title = "Leetcode 1477: Find Two Non-overlapping Sub-arrays Each With Target Sum"
date = "2020-10-16"
description = "Solution to Leetcode 1477"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        unordered_map<int, int> mp;
        int sum = 0, lsize = INT_MAX, result = INT_MAX;
        mp[0] = -1;
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            mp[sum] = i;
        }
        sum = 0;
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if(mp.count(sum - target)) 
            lsize = min(lsize, i - mp[sum-target]);

            if(mp.count(sum + target) && lsize < INT_MAX)
            result = min(result, mp[sum + target] -i +lsize);


        }

        return result == INT_MAX ? -1: result;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

