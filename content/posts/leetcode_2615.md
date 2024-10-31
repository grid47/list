
+++
authors = ["Crafted by Me"]
title = "Leetcode 2615: Sum of Distances"
date = "2017-09-04"
description = "Solution to Leetcode 2615"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-distances/description/)

---



**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        /*
        
        [1,3,1,1,2]
         0,1,2,3,4
        
         0
           0  
         2   2
         5   3 4
                 0
        */
        
        unordered_map<int, double> mp, cnt;
        int n = nums.size();
        vector<long long> arr(n, 0);
        for(int i = 0; i < n; i++) {
            arr[i] = cnt[nums[i]] * i - mp[nums[i]];
            mp[nums[i]] += i;
            cnt[nums[i]] += 1;
        }
        mp.clear(), cnt.clear();        
        for(int i = n - 1; i >= 0; i--) {
            arr[i] += mp[nums[i]] - cnt[nums[i]] * i;
            mp[nums[i]] += i;
            cnt[nums[i]] += 1;
        }
        return arr;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

