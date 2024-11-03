
+++
authors = ["Crafted by Me"]
title = "Leetcode 3121: Count the Number of Special Characters II"
date = "2016-04-17"
description = "In-depth solution and explanation for Leetcode 3121: Count the Number of Special Characters II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-the-number-of-special-characters-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> ch(26, 0);
        for(char x: word) {
            if(isupper(x)) {
                if(ch[x - 'A'] == -1) continue;
                if(ch[x - 'A'] != 1 && ch[x - 'A'] != 2)  {
                  ch[x - 'A'] = -1;
                    continue;  
                }
                ch[x - 'A'] = 2;
            } else {
                if(ch[x - 'a'] == -1) continue;                
                if(ch[x - 'a'] == 2) {
                  ch[x - 'a'] = -1;
                    continue;  
                } 
                ch[x - 'a'] = 1;
            }
            // cout << x << " ";
            // for(int i = 0; i < 26; i++) {
            //     cout << ch[i] << " ";
            // }
            // cout << "\n";
        }
        int cnt = 0;
        for(int i = 0; i < 26; i++) {
            // cout << ch[i] << " ";
            if(ch[i] == 2)
                cnt++;
        }
        return cnt;        
    }
};
{{< /highlight >}}


---

| Next : [LeetCode #3122: Minimum Number of Operations to Satisfy Conditions](https://grid47.xyz/posts/leetcode_3122) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

