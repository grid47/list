
+++
authors = ["Crafted by Me"]
title = "Leetcode 2947: Count Beautiful Substrings I"
date = "2016-10-08"
description = "In-depth solution and explanation for Leetcode 2947: Count Beautiful Substrings I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

