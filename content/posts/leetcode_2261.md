
+++
authors = ["Yasir"]
title = "Leetcode 2261: K Divisible Elements Subarrays"
date = "2018-08-20"
description = "Solution to Leetcode 2261"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/k-divisible-elements-subarrays/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        
        int res = 0, n = nums.size();
        vector<int> cnt(201, 0); vector<long long> hash(201, 0);
        for (int sz = 0; sz < n; sz++) {
            unordered_set<int> s;
            for(int i = 0; i + sz < n; i++){

cnt[i] += ((nums[i + sz] % p) == 0);
            if(cnt[i] <= k) {
hash[i] = (hash[i] * 200 + nums[i + sz]) % 1000000007;
                res += s.insert(hash[i]).second;
            }
        }
        }
        
        return res;
    }
};
{{< /highlight >}}

