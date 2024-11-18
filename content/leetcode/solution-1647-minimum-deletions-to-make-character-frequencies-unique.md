
+++
authors = ["grid47"]
title = "Leetcode 1647: Minimum Deletions to Make Character Frequencies Unique"
date = "2024-05-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1647: Minimum Deletions to Make Character Frequencies Unique in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "h8AZEN49gTc"
youtube_upload_date="2023-09-12"
youtube_thumbnail="https://i.ytimg.com/vi/h8AZEN49gTc/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minDeletions(string s) {
        map<char, int> mp;
        int n= s.size();
        for(char x: s)
            mp[x]++;
        vector<pair<int, char>> arr;
        for(auto it: mp) {
            arr.push_back({it.second, it.first});
        }
        sort(arr.begin(), arr.end());
        n = arr.size();
        set<int> cnt;
        int del = 0;
        for(int i = 0; i < n; i++) {
            int tmp = arr[i].first;
            while(tmp > 0 && cnt.count(tmp)) {
                tmp--;
                del++;
            }
            if(tmp > 0) cnt.insert(tmp);
        }
        return del;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1647.md" >}}
---
{{< youtube h8AZEN49gTc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1648: Sell Diminishing-Valued Colored Balls](https://grid47.xyz/leetcode/solution-1648-sell-diminishing-valued-colored-balls/) |
| --- |
