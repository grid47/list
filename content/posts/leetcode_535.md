
+++
authors = ["Crafted by Me"]
title = "Leetcode 535: Encode and Decode TinyURL"
date = "2023-05-17"
description = "In-depth solution and explanation for Leetcode 535: Encode and Decode TinyURL in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/encode-and-decode-tinyurl/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
    const string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    random_device rd;
    map<string, string> url_code, code_url;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string code;
        if(!url_code.count(longUrl)) {
            for(int i = 0; i < 6; i++)
                code.push_back(charset[rd()%charset.size()]);
            url_code.insert(pair<string, string>(longUrl, code));
            code_url.insert(pair<string, string>(code, longUrl));                
        } else {
            code = url_code[longUrl];
        }
        return "http://tinyurl.com/" + code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        if(shortUrl.size() != 25 || !code_url.count(shortUrl.substr(19,6)))
        return "";
        return code_url[shortUrl.substr(19,6)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/535.md" >}}
---
{{< youtube VyBOaboQLGc >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #536: Construct Binary Tree from String](https://grid47.xyz/posts/leetcode_536) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

