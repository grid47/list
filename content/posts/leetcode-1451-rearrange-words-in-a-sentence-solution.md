
+++
authors = ["grid47"]
title = "Leetcode 1451: Rearrange Words in a Sentence"
date = "2024-06-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1451: Rearrange Words in a Sentence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/rearrange-words-in-a-sentence/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string arrangeWords(string txt) {
        
        int n = txt.size();
        vector<vector<int>> arr;
        map<int, string> mp;
        int prv = 0, cnt = 0;
        for(int i = 0; i < n; i++) {
            if(txt[i] == ' ' || i == n - 1) {
                string str;
                int len;
                if(i == n - 1) {
                    len = i + 1 - prv;
                } else {
                    len = i - prv;
                }
                str = txt.substr(prv, len);
                if(prv == 0) str[0] = str[0] - 'A' + 'a';
                cnt++;
                mp[cnt] = str;
                arr.push_back({len, cnt});
                prv = i + 1;
            }
        }
        sort(arr.begin(), arr.end());
        string res = "";
        for(int i = 0; i < arr.size(); i++) {
            res += mp[arr[i][1]];
            if(i != arr.size() - 1) res += ' ';
        }
        res[0] = res[0] - 'a' + 'A';
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1451.md" >}}
---
{{< youtube ZMdBEJX3gog >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1452: People Whose List of Favorite Companies Is Not a Subset of Another List](https://grid47.xyz/posts/leetcode-1452-people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list-solution/) |
| --- |
