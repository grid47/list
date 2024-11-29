
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
comments = true
+++


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
Design a URL shortening system where you can encode a long URL into a shortened URL and decode it back to the original URL. The system should guarantee that the original URL can always be retrieved using the shortened version.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a valid long URL (string) that needs to be encoded into a shortened version. The input string will contain a valid URL of length between 1 and 10^4 characters.
- **Example:** `Input: longUrl = "https://example.com/article/12345"`
- **Constraints:**
	- 1 <= longUrl.length <= 10^4
	- The URL will be a valid string containing a valid URL.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should return the encoded shortened URL, and when decoded, it should return the original URL.
- **Example:** `Output: "http://tinyurl.com/4e9iAk"`
- **Constraints:**
	- The returned shortened URL should be valid and unique.

{{< dots >}}
### Core Logic 🔍
**Goal:** To design a system that can encode and decode URLs efficiently while ensuring uniqueness of the shortened URLs.

- Use a random generation technique to create a unique short code for each long URL.
- Store the mapping between the original URL and the generated short URL in a data structure (e.g., a map).
- Use the short URL to look up and retrieve the corresponding original URL when decoding.
{{< dots >}}
### Problem Assumptions ✅
- The input URL is valid and properly formatted.
- The solution does not need to handle invalid URLs or URLs that exceed the length limits.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: longUrl = "https://example.com/article/12345"`  \
  **Explanation:** The long URL "https://example.com/article/12345" is encoded into a shorter version, such as "http://tinyurl.com/4e9iAk", which can be decoded back to the original URL.

{{< dots >}}
## Approach 🚀
To solve this problem, we can use a hashmap to store the original URL and its corresponding shortened URL. A random string generator will be used to ensure uniqueness for the shortened URLs.

### Initial Thoughts 💭
- A unique identifier (short code) needs to be generated for each long URL to ensure that each encoded URL maps to a unique decoded URL.
- Using a random character set will allow us to generate short and unique codes for each URL.
{{< dots >}}
### Edge Cases 🌐
- Ensure that empty URLs are handled properly. However, in this problem, the input will always be a valid URL.
- The system should handle long URLs up to 10^4 characters efficiently.
- Consider the case where multiple URLs map to the same shortened URL. This should not happen due to the uniqueness of the generated short codes.
- Make sure the system handles all edge cases, including valid URLs, large inputs, and properly handles the mappings.
{{< dots >}}
## Code 💻
```cpp
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
```

This class implements a URL shortener. It has two main methods: `encode` which takes a long URL and returns a shortened URL, and `decode` which takes a shortened URL and returns the original long URL. It uses a random string generation for encoding and a map for encoding-decoding operations.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Definition**
	```cpp
	class Solution {
	```
	Defines the `Solution` class which contains the encoding and decoding methods for URL shortening.

2. **Charset Definition**
	```cpp
	const string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	```
	Defines a constant string `charset` that contains all possible characters that can be used to generate the shortened URL.

3. **Random Device Initialization**
	```cpp
	random_device rd;
	```
	Declares a `random_device` object `rd` used for generating random numbers to ensure uniqueness in the encoded URL.

4. **Map Initialization**
	```cpp
	map<string, string> url_code, code_url;
	```
	Declares two maps: `url_code` which maps long URLs to shortened codes, and `code_url` which maps shortened codes back to long URLs.

5. **Access Control**
	```cpp
	public:
	```
	Declares the public access scope for the encoding and decoding methods.

6. **Encode Method Definition**
	```cpp
	string encode(string longUrl) {
	```
	Defines the `encode` method which takes a long URL as input and returns a shortened version of that URL.

7. **Variable Declaration**
	```cpp
	    string code;
	```
	Declares a string variable `code` to store the randomly generated shortened code for the long URL.

8. **Check if URL Already Encoded**
	```cpp
	    if(!url_code.count(longUrl)) {
	```
	Checks if the long URL is already encoded. If not, it proceeds to generate a new shortened URL.

9. **Random Code Generation**
	```cpp
	        for(int i = 0; i < 6; i++)
	```
	Generates a random 6-character string by selecting random characters from the `charset` string.

10. **Push Back Character to Code**
	```cpp
	            code.push_back(charset[rd()%charset.size()]);
	```
	Appends a random character from the `charset` string to the `code` string.

11. **Insert Long URL and Code**
	```cpp
	        url_code.insert(pair<string, string>(longUrl, code));
	```
	Inserts the pair of the long URL and its corresponding shortened code into the `url_code` map.

12. **Insert Code and Long URL**
	```cpp
	        code_url.insert(pair<string, string>(code, longUrl));                
	```
	Inserts the pair of the shortened code and the long URL into the `code_url` map.

13. **Else Case for Existing URL**
	```cpp
	    } else {
	```
	If the long URL is already encoded, the code simply retrieves the existing shortened code from the `url_code` map.

14. **Retrieve Existing Code**
	```cpp
	        code = url_code[longUrl];
	```
	Retrieves the existing shortened code for the long URL from the `url_code` map.

15. **Return Encoded URL**
	```cpp
	    return "http://tinyurl.com/" + code;
	```
	Returns the full shortened URL formed by concatenating the base URL with the generated shortened code.

16. **Decode Method Definition**
	```cpp
	string decode(string shortUrl) {
	```
	Defines the `decode` method which takes a shortened URL as input and returns the corresponding original long URL.

17. **Check URL Length and Validity**
	```cpp
	    if(shortUrl.size() != 25 || !code_url.count(shortUrl.substr(19,6)))
	```
	Checks if the shortened URL has a valid length and if the map `code_url` contains the shortened code extracted from the URL.

18. **Return Empty String for Invalid URL**
	```cpp
	    return "";
	```
	Returns an empty string if the shortened URL is invalid or if no matching code is found.

19. **Retrieve Original URL**
	```cpp
	    return code_url[shortUrl.substr(19,6)];
	```
	Retrieves the original long URL from the `code_url` map using the shortened code extracted from the shortened URL.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

The time complexity for both encoding and decoding is O(1), as hashmaps allow constant time retrieval and insertion.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n), where n is the number of unique URLs that have been encoded, as we need to store the mappings in hashmaps.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/encode-and-decode-tinyurl/description/)

---
{{< youtube VyBOaboQLGc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
