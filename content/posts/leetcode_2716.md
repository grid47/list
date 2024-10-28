
+++
authors = ["Yasir"]
title = "Leetcode 2716: Minimize String Length"
date = "2017-05-23"
description = "Solution to Leetcode 2716"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimize-string-length/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int minimizedStringLength(string s) {
    unordered_set<char> st;
    for(auto c: s) st.insert(c);
    return st.size();
}
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

