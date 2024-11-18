
+++
authors = ["grid47"]
title = "Leetcode 2716: Minimize String Length"
date = "2024-02-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2716: Minimize String Length in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "aMJ3T0K8LjI"
youtube_upload_date="2023-06-11"
youtube_thumbnail="https://i.ytimg.com/vi/aMJ3T0K8LjI/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/minimize-string-length/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimizedStringLength(string s) {
    unordered_set<char> st;
    for(auto c: s) st.insert(c);
    return st.size();
}
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2716.md" >}}
---
{{< youtube aMJ3T0K8LjI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2717: Semi-Ordered Permutation](https://grid47.xyz/leetcode/solution-2717-semi-ordered-permutation/) |
| --- |
