
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2680: Maximum OR"
date = "2017-06-29"
description = "Solution to Leetcode 2680"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-or/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) 
    {
        //prefix or
        //suffix or
        vector<long long>prefixor;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(i == 0) prefixor.push_back((1LL * nums[i]));
            else prefixor.push_back(((1LL*prefixor.back()) | (1LL*nums[i])));
        }    

        vector<long long>suffixor;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            if(i == (nums.size()-1))  suffixor.push_back((1LL * nums[i]));
            else suffixor.push_back(((1LL*suffixor.back()) | (1LL*nums[i])));
        }
        reverse(suffixor.begin(),suffixor.end());

        long long ans = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        { 
            long long int left = 0;
            long long int self;
            long long int right = 0;
            if((i-1) >= 0)
            {
                left = prefixor[i-1];
            }
            self = (nums[i] * pow(2,k));
            if((i+1) <= nums.size()-1)
            {
                right = suffixor[i+1];
            }
            ans = max(ans , left | self | right);
        }
        return ans;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
