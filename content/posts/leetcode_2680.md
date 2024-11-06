
+++
authors = ["Crafted by Me"]
title = "Leetcode 2680: Maximum OR"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2680: Maximum OR in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Bit Manipulation","Prefix Sum"]
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


---
{{< youtube XiaXIrEHFEY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2681: Power of Heroes](https://grid47.xyz/posts/leetcode_2681) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

