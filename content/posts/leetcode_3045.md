
+++
authors = ["Crafted by Me"]
title = "Leetcode 3045: Count Prefix and Suffix Pairs II"
date = "2016-07-02"
description = "In-depth solution and explanation for Leetcode 3045: Count Prefix and Suffix Pairs II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-prefix-and-suffix-pairs-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:

    struct TrieNode {
        unordered_map<int, TrieNode*> next;
        int count = 0;
    };

    long long countPrefixSuffixPairs(vector<string>& words) {
        TrieNode* root = new TrieNode();
        long long res = 0;
        for (const string& w : words) {
            TrieNode* x = root;
            for (int i = 0, n = w.size(); i < n; ++i) {
                x = x->next.insert({w[i] * 128 + w[n - 1 - i], new TrieNode()}).first->second;
                res += x->count;
            }
            x->count++;
        }

        return res;
    }

};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

