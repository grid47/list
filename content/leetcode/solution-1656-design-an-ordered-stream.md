
+++
authors = ["grid47"]
title = "Leetcode 1656: Design an Ordered Stream"
date = "2024-05-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1656: Design an Ordered Stream in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Design","Data Stream"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "lL7_8Eg1Q1s"
youtube_upload_date="2020-11-15"
youtube_thumbnail="https://i.ytimg.com/vi/lL7_8Eg1Q1s/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/design-an-ordered-stream/description/)

---
**Code:**

{{< highlight cpp >}}
class OrderedStream {
public:
vector<string> s;
int ptr = 1;
OrderedStream(int n) : s(n + 1) {}
vector<string> insert(int id, string value) {
    s[id] = value;
    vector<string> res;
    while (ptr < s.size() && !s[ptr].empty())
        res.push_back(s[ptr++]);
    return res;
}
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1656.md" >}}
---
{{< youtube lL7_8Eg1Q1s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1657: Determine if Two Strings Are Close](https://grid47.xyz/leetcode/solution-1657-determine-if-two-strings-are-close/) |
| --- |