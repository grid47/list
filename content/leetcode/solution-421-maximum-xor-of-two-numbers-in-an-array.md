
+++
authors = ["grid47"]
title = "Leetcode 421: Maximum XOR of Two Numbers in an Array"
date = "2024-09-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 421: Maximum XOR of Two Numbers in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Bit Manipulation","Trie"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/421.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++



[`Problem Link`](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/421.webp" 
    alt="A glowing sequence of numbers where the XOR result is softly highlighted, showing the maximum possible value."
    caption="Solution to LeetCode 421: Maximum XOR of Two Numbers in an Array Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #423: Reconstruct Original Digits from English](https://grid47.xyz/leetcode/solution-423-reconstruct-original-digits-from-english/) |
| --- |