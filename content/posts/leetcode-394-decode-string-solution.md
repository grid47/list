
+++
authors = ["grid47"]
title = "Leetcode 394: Decode String"
date = "2024-09-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 394: Decode String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Recursion"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/decode-string/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/394.webp" 
    alt="A string decoding into a sequence, with each decoded character softly illuminated."
    caption="Solution to LeetCode 394: Decode String Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return decode(s, i);
    }
    
    string decode(string &s, int &i) {
        
        
        string res = "";
        
        while(i < s.size() && s[i] != ']') {
            if(!isdigit(s[i]))
                res += s[i++];
            else {
                int n = 0;
                
                while(i < s.size() && isdigit(s[i]))
                    n = n * 10 + (s[i++] - '0');
                
                i++;
                string t = decode(s, i);
                i++;
                
                while(n--> 0) res += t;
            }
        }
        
        return res;
    }
    
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/394.md" >}}
---
{{< youtube kNW1SlfDuJY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #395: Longest Substring with At Least K Repeating Characters](https://grid47.xyz/posts/leetcode-395-longest-substring-with-at-least-k-repeating-characters-solution/) |
| --- |
