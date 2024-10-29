
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2947: Count Beautiful Substrings I"
date = "2016-10-05"
description = "Solution to Leetcode 2947"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-beautiful-substrings-i/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    unordered_set<char> st{'a', 'e', 'i', 'o', 'u'};
    bool isVowel(char c) { return st.find(c) != st.end(); }
    int beautifulSubstrings(string s, int k) {
        int ans = 0;
        for(int i = 0; i < s.size(); ++i){
            int vow = 0, con = 0;
            for(int j = i; j < s.size(); ++j) {
                (isVowel(s[j]))? vow++: con++;
                if(vow == con && (vow*con)%k == 0) ans++;
            }
        }
        return ans;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

