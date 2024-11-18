
+++
authors = ["grid47"]
title = "Leetcode 1405: Longest Happy String"
date = "2024-06-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1405: Longest Happy String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Greedy","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "8u-H6O_XQKE"
youtube_upload_date="2022-02-23"
youtube_thumbnail="https://i.ytimg.com/vi/8u-H6O_XQKE/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/longest-happy-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
        priority_queue<pair<int, char>, vector<pair<int, char>>, less<pair<int, char>>> pq;
        if(a > 0)
        pq.push({a, 'a'});
        if(b > 0)
        pq.push({b, 'b'});
        if(c > 0)
        pq.push({c, 'c'});
        
        string res = "";
        
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            res += string(min(2, it.first), it.second);
            it.first -= min(2, it.first);
            
            if(pq.empty()) break;
            auto it2 = pq.top();
            pq.pop();
            res += string(min(it.first > it2.first? 1: 2, it2.first), it2.second);
            it2.first -= min(it.first > it2.first? 1: 2, it2.first);
            
            if(it.first > 0) pq.push(it);
            if(it2.first > 0) pq.push(it2);
        }
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1405.md" >}}
---
{{< youtube 8u-H6O_XQKE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1409: Queries on a Permutation With Key](https://grid47.xyz/leetcode/solution-1409-queries-on-a-permutation-with-key/) |
| --- |
