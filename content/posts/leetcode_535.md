
+++
authors = ["Yasir"]
title = "Leetcode 535: Encode and Decode TinyURL"
date = "2023-05-13"
description = "Solution to Leetcode 535"
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

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

