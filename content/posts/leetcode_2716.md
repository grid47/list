
+++
authors = ["Crafted by Me"]
title = "Leetcode 2716: Minimize String Length"
date = "2017-05-26"
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



---

{{< youtube aMJ3T0K8LjI >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

