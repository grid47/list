
+++
authors = ["grid47"]
title = "Leetcode 2182: Construct String With Repeat Limit"
date = "2024-04-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2182: Construct String With Repeat Limit in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Greedy","Heap (Priority Queue)","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "PZT5c2SFAYs"
youtube_upload_date="2022-02-20"
youtube_thumbnail="https://i.ytimg.com/vi/PZT5c2SFAYs/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/construct-string-with-repeat-limit/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);
        for(char ch: s) freq[ch - 'a']++;
        priority_queue<pair<char, int>> pq;

        for(int i = 0; i < 26; i++)
        if(freq[i] > 0) pq.push(make_pair((char) 'a' + i, freq[i]));

        string ans = "";
        while(!pq.empty()) {
            pair<char, int> p = pq.top();
            pq.pop();
            int cnt = p.second;
            for(int i = 0; i < repeatLimit && cnt-- > 0; i++) ans.push_back(p.first);

            if(cnt > 0 && !pq.empty()) {
                pair<char, int> sp = pq.top();
                pq.pop();
                ans.push_back(sp.first);
                if(sp.second > 1) {
                    sp.second--;
                    pq.push(sp);
                }
                p.second = cnt;
                pq.push(p);
            }
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2182.md" >}}
---
{{< youtube PZT5c2SFAYs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2185: Counting Words With a Given Prefix](https://grid47.xyz/leetcode/solution-2185-counting-words-with-a-given-prefix/) |
| --- |