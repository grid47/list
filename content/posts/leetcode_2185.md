
+++
authors = ["Crafted by Me"]
title = "Leetcode 2185: Counting Words With a Given Prefix"
date = "2018-11-09"
description = "In-depth solution and explanation for Leetcode 2185: Counting Words With a Given Prefix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/counting-words-with-a-given-prefix/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int prefixCount(vector<string>& words, string s) {
        int cnt = 0;
        for(string x: words) {
            if(x.size() < s.size()) continue;
            bool flag = true;
            for(int i = 0; i < s.size(); i++) {
                if(x[i] != s[i]) {
                    flag = false;
                    break;
                }
            }
            if(flag) cnt++;
        }
        return cnt;        
    }
};
{{< /highlight >}}


---

| Next : [LeetCode #2186: Minimum Number of Steps to Make Two Strings Anagram II](https://grid47.xyz/posts/leetcode_2186) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

