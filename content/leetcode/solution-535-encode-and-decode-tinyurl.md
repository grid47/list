
+++
authors = ["grid47"]
title = "Leetcode 535: Encode and Decode TinyURL"
date = "2024-09-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 535: Encode and Decode TinyURL in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Design","Hash Function"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/535.webp"
youtube = "VyBOaboQLGc"
youtube_upload_date="2021-04-07"
youtube_thumbnail="https://i.ytimg.com/vi_webp/VyBOaboQLGc/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/encode-and-decode-tinyurl/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/535.webp" 
    alt="A URL being encoded into a short link, with each transformation step gently glowing to indicate the encoding process."
    caption="Solution to LeetCode 535: Encode and Decode TinyURL Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #537: Complex Number Multiplication](https://grid47.xyz/leetcode/solution-537-complex-number-multiplication/) |
| --- |
