
+++
authors = ["Yasir"]
title = "Leetcode 2541: Minimum Operations to Make Array Equal II"
date = "2017-11-13"
description = "Solution to Leetcode 2541"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-operations-to-make-array-equal-ii/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if(k == 0) {
        for(int i = 0; i < nums1.size(); i++) {
            if(nums1[i] != nums2[i]) return -1;
        }
            return 0;
        }
        for(int i = 0; i < nums1.size(); i++) {
            nums1[i] -= nums2[i];
            if(nums1[i] % k != 0) return -1;
        }
        cout << "hi";
        long long res = 0, sum = 0;
        for(int i = 0; i < nums1.size(); i++) {
            cout << nums1[i] << " ";
            if(nums1[i] > 0) res += nums1[i] / k;
            sum += nums1[i];
        }
        if(sum != 0) return -1;
        return res;
    }
};
{{< /highlight >}}

