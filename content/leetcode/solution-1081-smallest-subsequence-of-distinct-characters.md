
+++
authors = ["grid47"]
title = "Leetcode 1081: Smallest Subsequence of Distinct Characters"
date = "2024-07-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1081: Smallest Subsequence of Distinct Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Greedy","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
You are given a string s, and your task is to return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once. The subsequence must be in the same order as the original string, but the characters should not repeat.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string s that contains lowercase English letters.
- **Example:** `Input: s = "zabcde"`
- **Constraints:**
	- 1 <= s.length <= 1000
	- s consists of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the lexicographically smallest subsequence containing all the distinct characters of s exactly once.
- **Example:** `Output: "abcde"`
- **Constraints:**
	- The subsequence should preserve the order of the original string.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the lexicographically smallest subsequence of the string containing each distinct character exactly once while maintaining the order.

- 1. Count the last occurrence index of each character in the string.
- 2. Traverse the string and construct the result by considering whether to add each character based on its lexicographical order and ensuring that it doesn't repeat.
{{< dots >}}
### Problem Assumptions ✅
- The input string is non-empty and contains lowercase English letters.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = "bcabc"`  \
  **Explanation:** In this example, the lexicographically smallest subsequence that contains all the distinct characters exactly once is "abc".

- **Input:** `Input: s = "cbacdcbc"`  \
  **Explanation:** In this case, the lexicographically smallest subsequence is "acdb".

{{< dots >}}
## Approach 🚀
We can solve this problem using a greedy algorithm that ensures the lexicographically smallest subsequence. By keeping track of the characters we have seen and the last occurrence of each character, we can decide which character to add to the result at each step.

### Initial Thoughts 💭
- We need to ensure that each character appears only once in the subsequence and that the subsequence is the lexicographically smallest.
- Using a stack can help us maintain the order and ensure the smallest lexicographical subsequence.
{{< dots >}}
### Edge Cases 🌐
- If the string is empty, return an empty string.
- The solution must handle large strings (up to 1000 characters) efficiently.
- If the string consists of the same repeated character, the result should be that character alone.
- The solution should be optimized to handle the input string within the provided constraints.
{{< dots >}}
## Code 💻
```cpp
string smallestSubsequence(string s) {
    int n = s.size();
    string res = "";

    vector<int> in(26, 0), seen(26, 0);
    for (int i = 0; i < n; i++)
        in[s[i] - 'a'] = i;

    vector<int> stk;
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        if (seen[c]++ > 0) continue;
        while (!stk.empty() && stk.back() > c && i < in[stk.back()]) {
            seen[stk.back()] = 0;
            stk.pop_back();
        }
        stk.push_back(c);
    }

    for (int i = 0; i < stk.size(); i++)
        res += ('a' + stk[i]);

    return res;
}
};
```

The `smallestSubsequence` function returns the lexicographically smallest subsequence of characters from the given string, ensuring that each character appears exactly once.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string smallestSubsequence(string s) {
	```
	This line defines the function `smallestSubsequence`, which takes a string `s` as input and will return the smallest subsequence of characters from `s`.

2. **Variable Initialization**
	```cpp
	    int n = s.size();
	```
	The size of the string `s` is stored in the variable `n`.

3. **Result Initialization**
	```cpp
	    string res = "";
	```
	An empty string `res` is initialized to build the result subsequence.

4. **Vector Initialization**
	```cpp
	    vector<int> in(26, 0), seen(26, 0);
	```
	Two vectors are initialized: `in` stores the last occurrence index of each character, and `seen` tracks whether a character is already in the result subsequence.

5. **Loop - Storing Last Occurrence**
	```cpp
	    for (int i = 0; i < n; i++)
	```
	This loop iterates over each character in the string `s`.

6. **Store Last Occurrence**
	```cpp
	        in[s[i] - 'a'] = i;
	```
	For each character in `s`, the index of its last occurrence is stored in the `in` vector.

7. **Vector Initialization - Stack**
	```cpp
	    vector<int> stk;
	```
	An empty vector `stk` is initialized to act as a stack for the characters that will form the smallest subsequence.

8. **Loop - Main Logic**
	```cpp
	    for (int i = 0; i < n; i++) {
	```
	This loop processes each character in the string `s`.

9. **Character Calculation**
	```cpp
	        int c = s[i] - 'a';
	```
	This line calculates the index `c` of the character `s[i]` relative to 'a', where 'a' corresponds to 0, 'b' to 1, and so on.

10. **Skip Duplicates**
	```cpp
	        if (seen[c]++ > 0) continue;
	```
	This checks if the character `s[i]` has already been added to the result subsequence. If it has, it skips the current iteration.

11. **Remove Ineligible Characters**
	```cpp
	        while (!stk.empty() && stk.back() > c && i < in[stk.back()]) {
	```
	This while loop removes characters from the stack if they are lexicographically larger than the current character `c` and can still appear later in the string.

12. **Reset Seen for Popped Characters**
	```cpp
	            seen[stk.back()] = 0;
	```
	This resets the `seen` status for the character that is being removed from the stack.

13. **Pop Character from Stack**
	```cpp
	            stk.pop_back();
	```
	This removes the character from the stack as it is no longer needed in the result subsequence.

14. **Push Current Character**
	```cpp
	        stk.push_back(c);
	```
	The current character `c` is pushed onto the stack for inclusion in the subsequence.

15. **Build Result Subsequence**
	```cpp
	    for (int i = 0; i < stk.size(); i++)
	```
	This loop iterates over the stack to build the result subsequence from the characters stored in the stack.

16. **Construct Result String**
	```cpp
	        res += ('a' + stk[i]);
	```
	For each character in the stack, its corresponding character (using the index) is added to the result string `res`.

17. **Return Result**
	```cpp
	    return res;
	```
	The resulting subsequence `res` is returned as the output.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The algorithm processes each character of the string once, making the time complexity linear in terms of the length of the string.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(26)

The space complexity is O(26) because the maximum number of distinct characters is 26, corresponding to the lowercase English alphabet.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
