
+++
authors = ["Crafted by Me"]
title = "Leetcode 2434: Using a Robot to Print the Lexicographically Smallest String"
date = "2018-03-05"
description = "In-depth solution and explanation for Leetcode 2434: Using a Robot to Print the Lexicographically Smallest String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    char low(vector<int> &frq) {
        for(int i = 0; i < 26; i++)
            if(frq[i] != 0) return 'a'+i;
        return 'z';
    }
    
    string robotWithString(string s) {
        
        vector<int> frq(26, 0);
        for(char c: s)
            frq[c - 'a']++;
        
        stack<int> t;
        string ans = "";
        
        for(char c : s) {
            t.push(c);
            frq[c - 'a']--;
            while(!t.empty() && t.top() <= low(frq)) {
                ans += t.top();
                t.pop();
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

