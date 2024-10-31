
+++
authors = ["Crafted by Me"]
title = "Leetcode 1442: Count Triplets That Can Form Two Arrays of Equal XOR"
date = "2020-11-20"
description = "Solution to Leetcode 1442"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/)

---



**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countTriplets(vector<int>& nums) {

        int res = 0, n = nums.size();
        vector<int> arr(n+1,0);
        for(int i = 1; i < n + 1; i++)
            arr[i] = arr[i -1] ^ nums[i-1];
        for(int i = 0; i < n+1; i++) {
            for(int j = i + 1; j < n+1; j++)
                if(arr[i] == arr[j])
                res += j - i- 1;
            }
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

