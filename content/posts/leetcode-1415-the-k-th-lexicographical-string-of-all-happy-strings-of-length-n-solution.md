
+++
authors = ["grid47"]
title = "Leetcode 1415: The k-th Lexicographical String of All Happy Strings of Length n"
date = "2024-06-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1415: The k-th Lexicographical String of All Happy Strings of Length n in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string ans = "";
    int cnt = 0;
    int k, n;
    
    string getHappyString(int n, int k) {
        this->k = k;
        this->n = n;
        string tmp = "";
        bt(-1, tmp);
        return ans;
    }
    
    void bt(int prv, string &tmp) {
        if(tmp.size() == n) {
            cnt++;
            if(cnt == k){
              ans = tmp;  
            } 
            return;
        }

        for(int i = 0; i < 3; i++) {
            if(prv == i) continue;
            if(i == 0) {
                tmp += 'a';
            } else if(i == 1) {
                tmp += 'b';
            } else if(i == 2) {
                tmp += 'c';
            }
            bt(i, tmp);
            tmp.pop_back();
        }
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1415.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1418: Display Table of Food Orders in a Restaurant](https://grid47.xyz/posts/leetcode-1418-display-table-of-food-orders-in-a-restaurant-solution/) |
| --- |
