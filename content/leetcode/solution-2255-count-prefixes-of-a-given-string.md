
+++
authors = ["grid47"]
title = "Leetcode 2255: Count Prefixes of a Given String"
date = "2024-03-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2255: Count Prefixes of a Given String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "ctp3MD4jiGg"
youtube_upload_date="2022-04-30"
youtube_thumbnail="https://i.ytimg.com/vi_webp/ctp3MD4jiGg/maxresdefault.webp"
comments = true
+++



---
Given a list of strings `words` and a target string `s`, count how many strings in `words` are prefixes of `s`. A prefix is defined as a substring starting from the beginning of a string and extending up to a given length. Note that duplicate strings in `words` should be counted separately.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string array `words` and a single string `s`.
- **Example:** `words = ["cat", "ca", "dog", "c"], s = "catapult"`
- **Constraints:**
	- 1 <= words.length <= 1000
	- 1 <= words[i].length, s.length <= 10
	- All strings in `words` and `s` consist of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the count of strings in `words` that are prefixes of the string `s`.
- **Example:** `Output: 3`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine how many strings in `words` match the prefix of `s` up to their length.

- Iterate through each string in `words`.
- Check if the length of the current string is less than or equal to `s`.
- Compare each character of the string with the corresponding character in `s`.
- If all characters match, increment the count.
- Return the total count of matches.
{{< dots >}}
### Problem Assumptions ✅
- Strings in `words` and `s` are non-empty.
- Duplicate strings in `words` contribute to the count separately.
{{< dots >}}
## Examples 🧩
- **Input:** `words = ["car", "ca", "dog", "c"], s = "caravan"`  \
  **Explanation:** The strings in `words` which are prefixes of `s` are "car", "ca", and "c". Thus, the result is 3.

- **Input:** `words = ["x", "xy", "xyz"], s = "abcdef"`  \
  **Explanation:** None of the strings in `words` are prefixes of `s`. Thus, the result is 0.

{{< dots >}}
## Approach 🚀
Iteratively compare each string in `words` with the prefix of `s` up to its length, ensuring efficient substring matching.

### Initial Thoughts 💭
- Prefix checking can be done by comparing the substring of `s` with the current word.
- The lengths of the words in `words` are relatively small, so the operations are manageable.
- A simple comparison using substring or a character-by-character match is sufficient for this problem.
{{< dots >}}
### Edge Cases 🌐
- If `words` is empty, return 0.
- Handle up to 1000 strings in `words` with maximum length 10 efficiently.
- If all strings in `words` are equal and match the prefix of `s`, count them all.
- Ensure that partial matches beyond the prefix length are not counted.
{{< dots >}}
## Code 💻
```cpp
int countPrefixes(vector<string>& words, string s) {
    int cnt = 0;
    for(string x: words) {
        if(x.size() > s.size()) continue;
        bool flag = true;
        for(int i = 0; i < x.size(); i++) {
            if(x[i] != s[i]) {
                flag = false;
                break;
            }
        }
        if(flag) cnt++;
    }
    return cnt;
}
```

This function counts how many words in the 'words' list are prefixes of the string 's'. It checks each word and compares it with the beginning of 's'. If a word matches the prefix of 's', the count is incremented.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int countPrefixes(vector<string>& words, string s) {
	```
	This defines the 'countPrefixes' function that takes a list of words and a string 's', and returns the number of words in 'words' that are prefixes of 's'.

2. **Variable Initialization**
	```cpp
	    int cnt = 0;
	```
	Here, 'cnt' is initialized to zero, and it will store the number of words that are prefixes of the string 's'.

3. **Loop Through Words**
	```cpp
	    for(string x: words) {
	```
	This loop iterates over each word 'x' in the 'words' vector to check if it is a prefix of the string 's'.

4. **Skip Long Words**
	```cpp
	        if(x.size() > s.size()) continue;
	```
	This condition skips words that are longer than the string 's', as they cannot be prefixes of 's'.

5. **Flag Initialization**
	```cpp
	        bool flag = true;
	```
	A boolean flag 'flag' is initialized to true. This flag will track whether the word 'x' is a valid prefix of 's'.

6. **Loop Through Characters**
	```cpp
	        for(int i = 0; i < x.size(); i++) {
	```
	This inner loop iterates through the characters of the word 'x' to compare each character with the corresponding character of the string 's'.

7. **Check Prefix Match**
	```cpp
	            if(x[i] != s[i]) {
	```
	This condition checks if the character at position 'i' of the word 'x' matches the corresponding character in 's'. If they don't match, 'flag' will be set to false.

8. **Flag Update**
	```cpp
	                flag = false;
	```
	If the characters don't match, 'flag' is set to false, indicating that 'x' is not a prefix of 's'.

9. **Break Loop**
	```cpp
	                break;
	```
	If a mismatch is found, the inner loop breaks early, as further checks are unnecessary for this word.

10. **Increment Count**
	```cpp
	        if(flag) cnt++;
	```
	If 'flag' remains true, meaning the word 'x' is a prefix of 's', the count 'cnt' is incremented.

11. **Return Result**
	```cpp
	    return cnt;
	```
	The function returns the final count 'cnt', which represents the number of words in 'words' that are prefixes of the string 's'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n * l)
- **Worst Case:** O(n * l)

n = number of strings in `words`, l = average length of strings in `words`.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

No additional space is used apart from the counter.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-prefixes-of-a-given-string/description/)

---
{{< youtube ctp3MD4jiGg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
