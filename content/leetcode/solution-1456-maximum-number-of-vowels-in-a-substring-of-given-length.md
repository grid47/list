
+++
authors = ["grid47"]
title = "Leetcode 1456: Maximum Number of Vowels in a Substring of Given Length"
date = "2024-06-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1456: Maximum Number of Vowels in a Substring of Given Length in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "tal8tKUr6dU"
youtube_upload_date="2023-05-06"
youtube_thumbnail="https://i.ytimg.com/vi/tal8tKUr6dU/maxresdefault.jpg"
comments = true
+++



---
You are given a string `s` consisting of lowercase English letters and an integer `k`. Your task is to find the maximum number of vowels in any substring of length `k`. Vowels in English are 'a', 'e', 'i', 'o', and 'u'.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `s` and an integer `k`.
- **Example:** `Input: s = "programming", k = 4`
- **Constraints:**
	- 1 <= s.length <= 100,000
	- s consists of only lowercase English letters.
	- 1 <= k <= s.length

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum number of vowels in any substring of `s` with length `k`.
- **Example:** `Output: 2`
- **Constraints:**
	- The output must be a single integer representing the maximum count of vowels.
	- If there are multiple substrings with the same maximum count, return the count as a single value.

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine the maximum number of vowels present in any substring of length `k`.

- Define a helper function to identify vowels efficiently.
- Use a sliding window approach to count vowels in substrings of length `k`.
- Adjust the count dynamically as the window moves forward in the string.
- Track and update the maximum count of vowels encountered.
{{< dots >}}
### Problem Assumptions ✅
- The input string and integer are valid and meet the constraints.
- Substrings of length `k` are always possible as `k <= s.length`.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = "basketball", k = 5`  \
  **Explanation:** Output: 2. The substring "asket" contains 2 vowels ('a' and 'e').

- **Input:** `Input: s = "university", k = 3`  \
  **Explanation:** Output: 2. Substring "uni" contains 2 vowels ('u' and 'i').

- **Input:** `Input: s = "robot", k = 4`  \
  **Explanation:** Output: 1. The substring "obot" contains 1 vowel ('o').

{{< dots >}}
## Approach 🚀
Utilize a sliding window approach to efficiently count vowels in each substring of length `k`.

### Initial Thoughts 💭
- Vowels are a small, fixed subset of characters, so membership checks can be done using a set.
- Sliding window helps avoid recomputing the vowel count for overlapping substrings.
- Efficient implementation requires linear time complexity.
- Use a sliding window to maintain a running count of vowels as we traverse the string.
{{< dots >}}
### Edge Cases 🌐
- Not applicable as `s` is guaranteed to have at least one character.
- Input: s with length 100,000 and k close to s.length. Verify performance.
- Input: s = "aaaaa", k = 3 -> Output: 3. Handles case with all vowels.
- Input: s = "bcdfg", k = 2 -> Output: 0. Handles case with no vowels.
- Ensure the function handles edge cases like `k = 1` or `k = s.length` gracefully.
{{< dots >}}
## Code 💻
```cpp
int vowels[26] = {  1,0,0,0,1, 0,0,0,1,0, 
                    0,0,0,0,1, 0,0,0,0,0, 
                    1,0,0,0,0, 0 };
int maxVowels(string s, int k) {
    int mx = 0;
    for(int i = 0, cur = 0; i < s.size(); i++) {
        cur += vowels[s[i] - 'a'];
        if(i >= k) cur -= vowels[s[i-k] - 'a'];
        mx = max(cur, mx);
    }
    return mx;
}
```

This function 'maxVowels' calculates the maximum number of vowels in any substring of length 'k' from the string 's'. An auxiliary array 'vowels' is used to mark the vowel letters in the alphabet.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Array Initialization**
	```cpp
	int vowels[26] = {  1,0,0,0,1, 0,0,0,1,0, 
	```
	This array 'vowels' is used to mark the presence of vowels in the alphabet. Each element corresponds to a letter, where vowels are marked with a '1' and consonants with a '0'.

2. **Array Initialization**
	```cpp
	                    0,0,0,0,1, 0,0,0,0,0, 
	```
	Continues the initialization of the 'vowels' array. This ensures that the vowels (a, e, i, o, u) are marked with '1' while other letters are marked with '0'.

3. **Array Initialization**
	```cpp
	                    1,0,0,0,0, 0 };
	```
	Finalizes the 'vowels' array initialization, ensuring that all vowels are marked as '1'.

4. **Function Declaration**
	```cpp
	int maxVowels(string s, int k) {
	```
	The function 'maxVowels' is declared. It takes a string 's' and an integer 'k', and returns an integer representing the maximum number of vowels in any substring of length 'k'.

5. **Variable Initialization**
	```cpp
	    int mx = 0;
	```
	The variable 'mx' is initialized to zero, which will later hold the maximum number of vowels encountered in any substring of length 'k'.

6. **Loop**
	```cpp
	    for(int i = 0, cur = 0; i < s.size(); i++) {
	```
	A loop starts, iterating through each character in the string 's'. The variable 'cur' keeps track of the current count of vowels in the current sliding window of length 'k'.

7. **Vowel Count Update**
	```cpp
	        cur += vowels[s[i] - 'a'];
	```
	The 'cur' variable is updated by adding 1 if the current character 's[i]' is a vowel (as determined by the 'vowels' array).

8. **Sliding Window Adjustment**
	```cpp
	        if(i >= k) cur -= vowels[s[i-k] - 'a'];
	```
	If the index 'i' is greater than or equal to 'k', the character that is sliding out of the window (at position 'i-k') is subtracted from 'cur'.

9. **Max Vowel Update**
	```cpp
	        mx = max(cur, mx);
	```
	The variable 'mx' is updated to store the maximum value between 'cur' (the current count of vowels in the window) and the previous maximum count.

10. **Return Statement**
	```cpp
	    return mx;
	```
	The function returns the value of 'mx', which is the maximum number of vowels found in any substring of length 'k'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The sliding window traverses the string once, making it linear in terms of `n`, the length of the string.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

Only a fixed amount of space is used for tracking the count and vowel set.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/)

---
{{< youtube tal8tKUr6dU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
