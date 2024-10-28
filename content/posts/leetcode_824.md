
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 824: Goat Latin"
date = "2022-07-28"
description = "Solution to Leetcode 824"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/goat-latin/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string toGoatLatin(string str) {
        stringstream iss(str), oss;
        set<char> s = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        string word;
        string a;
        while(iss >> word) {
            a.push_back('a');
            if(s.count(word[0])) {
                oss << ' ' << word << "ma" << a;
            } else {
                oss << ' ' << word.substr(1) << word[0]  << "ma" << a;                
            }
        }
        return oss.str().substr(1);
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

