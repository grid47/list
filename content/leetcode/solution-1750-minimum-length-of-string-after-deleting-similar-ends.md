
+++
authors = ["grid47"]
title = "Leetcode 1750: Minimum Length of String After Deleting Similar Ends"
date = "2024-05-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1750: Minimum Length of String After Deleting Similar Ends in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "318hrWVr_5U"
youtube_upload_date="2024-03-05"
youtube_thumbnail="https://i.ytimg.com/vi/318hrWVr_5U/maxresdefault.jpg"
comments = true
+++



---
You are given a string `s` consisting of only the characters 'a', 'b', and 'c'. Your task is to repeatedly perform the following operation any number of times:

1. Pick a non-empty prefix from the string where all characters are equal.
2. Pick a non-empty suffix from the string where all characters are equal.
3. The prefix and suffix should not intersect, and the characters in both should be the same.
4. Remove the prefix and suffix.

Your goal is to find the minimum length of the string after performing the operation any number of times.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `s` of length `n`.
- **Example:** `Input: s = "aabbbbaaa"`
- **Constraints:**
	- 1 <= s.length <= 10^5
	- s only contains characters 'a', 'b', and 'c'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum possible length of the string after performing the operation any number of times.
- **Example:** `Output: 3`
- **Constraints:**
	- The resulting string will have a length greater than or equal to 0.

{{< dots >}}
### Core Logic 🔍
**Goal:** To minimize the string length by applying the operation to remove prefixes and suffixes.

- 1. Start from both ends of the string, and compare characters.
- 2. If characters match, attempt to remove the same characters from both the prefix and the suffix.
- 3. Continue until no more valid operations can be performed, and return the remaining length of the string.
{{< dots >}}
### Problem Assumptions ✅
- The string consists only of the characters 'a', 'b', and 'c'.
- The string may contain repetitive characters, but it will always be non-empty.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = "ca"`  \
  **Explanation:** No characters can be removed because there are no matching characters at both ends, so the minimum length is the original string length, which is 2.

- **Input:** `Input: s = "abccba"`  \
  **Explanation:** In this case, the prefix 'a' and suffix 'a' can be removed, then 'b' and 'b' can be removed, leaving 'cc', so the minimum length is 2.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to check for matching prefixes and suffixes, and iteratively remove them to minimize the string length.

### Initial Thoughts 💭
- The solution should avoid iterating through the entire string repeatedly. Instead, we should consider the matching characters at the beginning and end of the string.
- We can use a two-pointer approach to efficiently check and remove prefixes and suffixes from the string.
{{< dots >}}
### Edge Cases 🌐
- If the string is empty, the output should be 0.
- For very large inputs (up to 100,000 characters), ensure that the solution operates efficiently in linear time.
- If the string contains only one character repeated, the result will depend on how many matching prefixes and suffixes can be removed.
- Ensure the solution handles edge cases such as strings with no matching characters at both ends.
{{< dots >}}
## Code 💻
```cpp
int minimumLength(string s) {
    vector<int> pre(3, 0), suf(3, 0);
    
    int i = 0, j = s.size() - 1, len = s.size();
    while(i < j && s[i] == s[j]) {
        char c = s[i];
        while(i < j && s[i] == c) i++;
        while(i < j && s[j] == c) j--;

        len = min(len, j == i? s[i-1]!=s[j]: (j - i + 1));
    }
    return len;
}
```

The function computes the minimum length of a string after removing matching characters from both ends while preserving the non-matching core.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int minimumLength(string s) {
	```
	Declares a function to find the minimum length of the string `s` after performing specified operations.

2. **Variable Initialization**
	```cpp
	    vector<int> pre(3, 0), suf(3, 0);
	```
	Initializes two vectors for potential prefix and suffix counts. These are not actively used in this logic.

3. **Variable Initialization**
	```cpp
	    int i = 0, j = s.size() - 1, len = s.size();
	```
	Initializes two pointers `i` and `j` for traversal and a variable `len` to store the result.

4. **Loop**
	```cpp
	    while(i < j && s[i] == s[j]) {
	```
	Loops as long as the characters at both ends match and the pointers haven't crossed.

5. **Character Extraction**
	```cpp
	        char c = s[i];
	```
	Extracts the current matching character to use for comparisons in the loop.

6. **Loop**
	```cpp
	        while(i < j && s[i] == c) i++;
	```
	Moves the left pointer `i` forward as long as it matches the extracted character.

7. **Loop**
	```cpp
	        while(i < j && s[j] == c) j--;
	```
	Moves the right pointer `j` backward as long as it matches the extracted character.

8. **Conditional Update**
	```cpp
	        len = min(len, j == i? s[i-1]!=s[j]: (j - i + 1));
	```
	Updates the minimum length by checking if the pointers meet and ensuring the remaining characters differ.

9. **Return Statement**
	```cpp
	    return len;
	```
	Returns the computed minimum length of the string after the operations.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), as we must process every character in the string.
- **Average Case:** O(n), as we compare characters at both ends and process the string linearly.
- **Worst Case:** O(n), as we may need to check all characters in the worst case.

The time complexity is linear in relation to the length of the string.

### Space Complexity 💾
- **Best Case:** O(1), as no additional space is required.
- **Worst Case:** O(1), since only a few variables are used to track the pointers and operations.

The space complexity is constant because the solution uses only a few pointers.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/description/)

---
{{< youtube 318hrWVr_5U >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
