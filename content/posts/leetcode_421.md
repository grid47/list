
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 421: Maximum XOR of Two Numbers in an Array"
date = "2023-09-04"
description = "Solution to Leetcode 421"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

