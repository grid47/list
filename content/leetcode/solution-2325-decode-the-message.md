
+++
authors = ["grid47"]
title = "Leetcode 2325: Decode the Message"
date = "2024-03-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2325: Decode the Message in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "4XXD2in1hwk"
youtube_upload_date="2022-07-03"
youtube_thumbnail="https://i.ytimg.com/vi_webp/4XXD2in1hwk/maxresdefault.webp"
comments = true
+++



---
Given a cipher key and a secret message, decode the message by replacing each letter with the corresponding letter in the alphabet based on the first appearance of each letter in the key. Spaces in the message remain unchanged.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two strings: key, representing the cipher key, and message, representing the secret message to decode.
- **Example:** `key = "jumping over hills in the park", message = "swm tlnh dbe"`
- **Constraints:**
	- The key will contain all 26 lowercase English letters at least once.
	- The key may contain spaces, but they are ignored for decoding purposes.
	- 1 <= message.length <= 2000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the decoded message by applying the substitution table derived from the key.
- **Example:** `For key = "jumping over hills in the park" and message = "swm tlnh dbe", the output is "the quick fox".`
- **Constraints:**
	- The decoded message should be returned as a string.

{{< dots >}}
### Core Logic 🔍
**Goal:** To decode the message using the substitution table derived from the key.

- 1. Create a substitution table based on the first occurrence of each letter in the key.
- 2. Replace each letter in the message with the corresponding letter from the substitution table.
- 3. Return the decoded message, ensuring spaces remain unchanged.
{{< dots >}}
### Problem Assumptions ✅
- The key is a valid string of lowercase English letters containing all letters from 'a' to 'z'.
- The message is also valid, containing only lowercase English letters and spaces.
{{< dots >}}
## Examples 🧩
- **Input:** `key = "jumping over hills in the park", message = "swm tlnh dbe"`  \
  **Explanation:** Using the first occurrence of each letter in the key as a substitution table, we decode 'swm tlnh dbe' to 'the quick fox'.

- **Input:** `key = "smart minds solve problems", message = "jqjc bmcms wbs"`  \
  **Explanation:** Using the first occurrence of each letter in the key as a substitution table, we decode 'jqjc bmcms wbs' to 'the code works'.

{{< dots >}}
## Approach 🚀
The problem can be solved by creating a substitution table from the cipher key and applying it to decode the message.

### Initial Thoughts 💭
- We need to map each letter from the key to the alphabet using its first occurrence.
- This substitution table can then be applied to decode the message.
- We can use a simple mapping approach to replace each character in the message based on the substitution table.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees a non-empty message, so no need to handle empty inputs.
- The solution must handle message lengths up to 2000 efficiently.
- Key strings may have multiple spaces, which should be ignored when forming the substitution table.
- The message string will always have valid characters (lowercase letters and spaces).
{{< dots >}}
## Code 💻
```cpp
string decodeMessage(string key, string mess) {
    char m[128] = {}, cur = 'a';
    for (char k : key)
        if (isalpha(k) && m[k] == 0)
            m[k] = cur++;
    for (int i = 0; i < mess.size(); ++i)
        mess[i] = m[mess[i]] ?: mess[i];
    return mess;
}
```

This function decodes a given message based on a key, where each character in the key is mapped to a letter starting from 'a'. The function replaces characters in the message using this mapping.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	string decodeMessage(string key, string mess) {
	```
	Declare the `decodeMessage` function, which takes two arguments: `key` (the mapping key) and `mess` (the message to decode). The function will return the decoded message.

2. **Character Array Initialization**
	```cpp
	    char m[128] = {}, cur = 'a';
	```
	Initialize a character array `m[128]` to store the mappings for the characters. The variable `cur` is initialized to 'a' to start the mapping from 'a'.

3. **Key Iteration**
	```cpp
	    for (char k : key)
	```
	Loop through each character `k` in the `key` string.

4. **Character Mapping Check**
	```cpp
	        if (isalpha(k) && m[k] == 0)
	```
	Check if the character `k` is alphabetic and if it has not already been mapped (i.e., `m[k] == 0`).

5. **Character Mapping**
	```cpp
	            m[k] = cur++;
	```
	If the character `k` is alphabetic and not yet mapped, assign it the next available letter in the alphabet (starting from 'a') and increment `cur`.

6. **Message Decoding Loop**
	```cpp
	    for (int i = 0; i < mess.size(); ++i)
	```
	Loop through each character in the message `mess` and apply the character mapping to decode the message.

7. **Character Replacement**
	```cpp
	        mess[i] = m[mess[i]] ?: mess[i];
	```
	For each character in the message, replace it with the mapped character from `m` if a mapping exists. If no mapping exists (i.e., the character is not in `key`), retain the original character.

8. **Return Statement**
	```cpp
	    return mess;
	```
	Return the decoded message after all characters have been processed.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the message, as we need to iterate through both the key and the message once.

### Space Complexity 💾
- **Best Case:** O(26 + n)
- **Worst Case:** O(26 + n)

The space complexity is O(26 + n), where 26 accounts for the mapping and n is the space required for the decoded message.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/decode-the-message/description/)

---
{{< youtube 4XXD2in1hwk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
