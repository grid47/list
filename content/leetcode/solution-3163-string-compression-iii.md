
+++
authors = ["grid47"]
title = "Leetcode 3163: String Compression III"
date = "2023-12-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3163: String Compression III in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "RWQ8Q_ID23c"
youtube_upload_date="2024-05-26"
youtube_thumbnail="https://i.ytimg.com/vi/RWQ8Q_ID23c/maxresdefault.jpg"
comments = true
+++



---
You are given a string `word`. Compress the string using the following algorithm:

Begin with an empty string `comp`. While `word` is not empty, perform the following operation:
1. Remove the longest prefix from `word` that consists of the same character repeating up to 9 times.
2. Append the length of this prefix followed by the character to `comp`.
Return the resulting string `comp`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `word` that contains only lowercase English letters.
- **Example:** `Example 1:
Input: word = "xyz"
Output: "1x1y1z"`
- **Constraints:**
	- 1 <= word.length <= 2 * 10^5
	- word consists only of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the string `comp` which is the compressed version of the input string `word`.
- **Example:** `Example 1:
Input: word = "xyz"
Output: "1x1y1z"`
- **Constraints:**
	- The output will be a string.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compress the string by iterating through it, identifying prefixes, and appending their length and character to the result.

- Initialize an empty string `comp`.
- Iterate through the string `word`.
- For each group of consecutive identical characters (up to 9), append the length of the group followed by the character to `comp`.
- Return the resulting compressed string `comp`.
{{< dots >}}
### Problem Assumptions ✅
- The input string will not be empty.
- The input string contains only lowercase English letters.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1:`  \
  **Explanation:** For `word = "xyz"`, since there are no repeating characters, each character is treated as a separate group of length 1. Hence, the output is `"1x1y1z"`.

- **Input:** `Example 2:`  \
  **Explanation:** For `word = "aaaaaaaaaaaaaabb"`, we compress the string by grouping consecutive 'a's and 'b's. The first group has 9 'a's, the second has 5 'a's, and the last group has 2 'b's. Thus, the output is `"9a5a2b"`.

{{< dots >}}
## Approach 🚀
The approach is to iterate over the string, count the consecutive identical characters, and append the count and character to the result string. Continue this process until the entire string is compressed.

### Initial Thoughts 💭
- We need to ensure that we correctly handle sequences of repeated characters, especially those that repeat more than 9 times.
- By iterating over the string and counting consecutive characters, we can easily build the compressed string.
{{< dots >}}
### Edge Cases 🌐
- There will never be an empty string as input.
- The solution should handle strings with lengths up to 200,000 efficiently.
- Ensure the solution works with strings that have many repeated characters (e.g., 'aaaaaaaaaaaaaaaaaaaaaaaaaaa').
- Ensure that the solution works within time and space constraints for large inputs.
{{< dots >}}
## Code 💻
```cpp
string compressedString(string word) {
    
    int i = 0, n = word.size();
    char cur;
    
    string res = "";
    while(i < n) {
        int cnt = 0;
        cur = word[i];
        while(i < n && cnt < 9 && cur == word[i])
            cnt++, i++;
        res += to_string(cnt) + cur;
    }
    return res;
    
}
```

This function 'compressedString' compresses a given string by counting consecutive occurrences of characters, appending the count followed by the character to the result string.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string compressedString(string word) {
	```
	Defines the function 'compressedString' that accepts a string 'word' and returns its compressed form.

2. **Variable Initialization**
	```cpp
	    int i = 0, n = word.size();
	```
	Initializes the index 'i' to 0 and 'n' to the length of the input string 'word'.

3. **Character Declaration**
	```cpp
	    char cur;
	```
	Declares a variable 'cur' of type char to store the current character during the iteration.

4. **Result String Initialization**
	```cpp
	    string res = "";
	```
	Initializes an empty string 'res' to store the result of the compressed string.

5. **Outer While Loop**
	```cpp
	    while(i < n) {
	```
	Starts a while loop that runs as long as 'i' is less than the length of the string 'n'.

6. **Count Initialization**
	```cpp
	        int cnt = 0;
	```
	Initializes a counter 'cnt' to 0 to keep track of consecutive occurrences of a character.

7. **Character Assignment**
	```cpp
	        cur = word[i];
	```
	Assigns the current character at position 'i' in the string 'word' to the variable 'cur'.

8. **Inner While Loop**
	```cpp
	        while(i < n && cnt < 9 && cur == word[i])
	```
	Starts a nested while loop that continues as long as the character at 'i' is the same as 'cur' and 'cnt' is less than 9.

9. **Counter Increment**
	```cpp
	            cnt++, i++;
	```
	Increments the counter 'cnt' and the index 'i' as long as the current character matches 'cur'.

10. **Result String Update**
	```cpp
	        res += to_string(cnt) + cur;
	```
	Appends the count 'cnt' (converted to a string) followed by the character 'cur' to the result string 'res'.

11. **Return Statement**
	```cpp
	    return res;
	```
	Returns the compressed string 'res' as the output.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where `n` is the length of the string `word`. We traverse the string once, processing each character.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) because we store the compressed string `comp` which could have a length up to the input string length in the worst case.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/string-compression-iii/description/)

---
{{< youtube RWQ8Q_ID23c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
