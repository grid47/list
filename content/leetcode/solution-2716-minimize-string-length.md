
+++
authors = ["grid47"]
title = "Leetcode 2716: Minimize String Length"
date = "2024-02-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2716: Minimize String Length in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "aMJ3T0K8LjI"
youtube_upload_date="2023-06-11"
youtube_thumbnail="https://i.ytimg.com/vi/aMJ3T0K8LjI/maxresdefault.jpg"
comments = true
+++



---
You are given a string `s`. You can perform two types of operations: (1) Choose an index `i` and remove the closest occurrence of the character at `i` to the left of `i`. (2) Choose an index `i` and remove the closest occurrence of the character at `i` to the right of `i`. Minimize the length of the string `s` by performing these operations and return the final minimized length.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A string `s` consisting of lowercase English letters.
- **Example:** `s = "abbccaa"`
- **Constraints:**
	- 1 <= s.length <= 100
	- s consists only of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the length of the minimized string after performing the operations.
- **Example:** `3`
- **Constraints:**
	- The output is a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to minimize the length of the string by repeatedly applying the operations where possible.

- Identify the closest duplicate characters in the string.
- Remove one of the duplicates by performing one of the operations.
- Repeat this process until no duplicates are left.
{{< dots >}}
### Problem Assumptions ✅
- The input string is non-empty and contains only lowercase English letters.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1`  \
  **Explanation:** For the input 'abbccaa', applying the operations step-by-step reduces the string to 'bca' with length 3.

- **Input:** `Example 2`  \
  **Explanation:** For the input 'abc', no operations are performed, and the length of the string remains 3.

- **Input:** `Example 3`  \
  **Explanation:** For the input 'aabbbcc', applying the operations reduces the string to 'abc', with a final length of 3.

{{< dots >}}
## Approach 🚀
We can solve this problem by iterating through the string and finding duplicate characters. For each duplicate, we perform an operation to remove one of them and continue until no duplicates remain.

### Initial Thoughts 💭
- The string is reduced by removing duplicate characters.
- The operations only affect characters that have duplicates.
- The key observation is that the minimum string length is determined by the number of unique characters in the string.
{{< dots >}}
### Edge Cases 🌐
- An empty string is not a valid input.
- The string length is at most 100 characters, which can be handled efficiently.
- If the string has no repeated characters, no operations are needed.
- The solution must be efficient for strings with lengths up to 100.
{{< dots >}}
## Code 💻
```cpp
int minimizedStringLength(string s) {
unordered_set<char> st;
for(auto c: s) st.insert(c);
return st.size();
}
```

This function calculates the minimized string length by inserting unique characters from the input string into a set and then returning the size of the set, which represents the number of unique characters.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minimizedStringLength(string s) {
	```
	This line defines the function `minimizedStringLength`, which takes a string `s` as an argument and returns an integer value representing the count of unique characters in the string.

2. **Set Initialization**
	```cpp
	unordered_set<char> st;
	```
	An unordered set `st` is created to store unique characters from the input string `s`. The unordered set ensures that each character is stored only once.

3. **Loop Through String**
	```cpp
	for(auto c: s) st.insert(c);
	```
	A loop iterates through each character `c` in the string `s`, and each character is inserted into the unordered set `st`. If a character is already present in the set, it is not added again.

4. **Return Size**
	```cpp
	return st.size();
	```
	After processing all characters in the string, the size of the unordered set `st` is returned. This size represents the number of unique characters in the string.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The solution runs in linear time since we only need to traverse the string once and find unique characters.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) for storing unique characters in a set.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimize-string-length/description/)

---
{{< youtube aMJ3T0K8LjI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
