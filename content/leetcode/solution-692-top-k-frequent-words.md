
+++
authors = ["grid47"]
title = "Leetcode 692: Top K Frequent Words"
date = "2024-08-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 692: Top K Frequent Words in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Trie","Sorting","Heap (Priority Queue)","Bucket Sort","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "jEm_HfkIk9s"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/692.webp"
+++



[`Problem Link`](https://leetcode.com/problems/top-k-frequent-words/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/692.webp" 
    alt="A list of words where the most frequent ones glow softly, indicating their popularity."
    caption="Solution to LeetCode 692: Top K Frequent Words Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
using tup_t = tuple<int, string>;
class cmp {
public:
    bool operator() (const tup_t &p1, const tup_t &p2) {
        if(get<0>(p1) == get<0>(p2)) return get<1>(p1) > get<1>(p2);
        else return get<0>(p1) < get<0>(p2);
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(string str: words)
            mp[str]++;

        priority_queue<tup_t, vector<tup_t>, cmp> pq;
        for(auto it: mp) {
            auto tp = make_tuple(it.second, it.first);
            pq.push(tp);
        }
        vector<string> ans;
        while(k-- > 0) {
            auto e = pq.top();
            ans.push_back(get<1>(e));
            pq.pop();
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/692.md" >}}
---
{{< youtube jEm_HfkIk9s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #695: Max Area of Island](https://grid47.xyz/leetcode/solution-695-max-area-of-island/) |
| --- |
