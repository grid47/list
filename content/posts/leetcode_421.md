
+++
authors = ["Crafted by Me"]
title = "Leetcode 421: Maximum XOR of Two Numbers in an Array"
date = "2023-09-08"
description = "In-depth solution and explanation for Leetcode 421: Maximum XOR of Two Numbers in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/)

---

**Code:**

{{< highlight cpp >}}
class TrieNode {
    TrieNode* children[2] = {};
public:    
    void add(int num) {
        TrieNode* cur = this;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (cur->children[bit] == nullptr)
                cur->children[bit] = new TrieNode();
            cur = cur->children[bit];
        }
    }

    int max(int num) {
        TrieNode* cur = this;
        int ans = 0;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (cur->children[1 - bit] != nullptr) {
                cur = cur->children[1 - bit];
                ans |= (1 << i);
            } else  cur = cur->children[bit];
        }
        return ans;
    }    
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        int n = nums.size();
        for(int i = 0; i < n; i++)
            root->add(nums[i]);
        
        int res = 0;
        for(int i = 0; i < n; i++)
            res = max(res, root->max(nums[i]));
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/421.md" >}}
---


| Next : [LeetCode #422: Valid Word Square](grid47.xyz/leetcode_422) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

