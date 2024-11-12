
+++
authors = ["grid47"]
title = "Leetcode 1286: Iterator for Combination"
date = "2024-07-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1286: Iterator for Combination in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Backtracking","Design","Iterator"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/iterator-for-combination/description/)

---
**Code:**

{{< highlight cpp >}}
class CombinationIterator {
public:
    string str;
    int len;
    vector<string> ans;
    map<int, int> mp;
    void bt(int idx, string &tmp) {
        if(tmp.size() == len) {
            ans.push_back(tmp);
            return;
        }
        if(idx == str.size()) {
            return;
        }
        
        for(int i = idx; i < str.size(); i++) {
            tmp += str[i];
            bt(i + 1, tmp);
            tmp.pop_back();
        }
        
    }
    int idx = 0;
    CombinationIterator(string chars, int len) {
        this->len = len;
        sort(chars.begin(), chars.end());
        str = chars;
        string tmp = "";
        bt(0, tmp);
    }
    
    string next() {
        return ans[idx++];
    }
    
    bool hasNext() {
        if(idx < ans.size()) return true;
        return false;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1286.md" >}}
---
{{< youtube LzYlG_p1-zs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #1287: Element Appearing More Than 25% In Sorted Array](https://grid47.xyz/posts/leetcode-1287-element-appearing-more-than-25-in-sorted-array-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
