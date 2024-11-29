
+++
authors = ["grid47"]
title = "Leetcode 1758: Minimum Changes To Make Alternating Binary String"
date = "2024-05-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1758: Minimum Changes To Make Alternating Binary String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "9vAQdmVU2ds"
youtube_upload_date="2023-12-24"
youtube_thumbnail="https://i.ytimg.com/vi_webp/9vAQdmVU2ds/maxresdefault.webp"
comments = true
+++



---
You are given a string `s` consisting only of the characters '0' and '1'. The string is considered alternating if no two adjacent characters are the same. Your task is to determine the minimum number of operations needed to make the string alternating, where in one operation, you can change any '0' to '1' or vice versa.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a string `s` which only contains the characters '0' and '1'.
- **Example:** `Input: s = '1001'`
- **Constraints:**
	- 1 <= s.length <= 10^4
	- s[i] is either '0' or '1'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of operations needed to make `s` alternating.
- **Example:** `Output: 1`
- **Constraints:**
	- The number of operations should be minimized.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to minimize the number of changes required to convert the given string into an alternating string.

- 1. Traverse the string `s` and check each adjacent pair of characters.
- 2. If two adjacent characters are the same, a change is needed.
- 3. Calculate the number of changes required for both possible alternating patterns: '010101...' and '101010...'.
- 4. Return the minimum of these two values.
{{< dots >}}
### Problem Assumptions ✅
- The string `s` is not empty and contains only '0' or '1'.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = '1001'`  \
  **Explanation:** To make the string alternating, change the second '0' to '1' or the last '1' to '0'. The minimum number of operations needed is 1.

- **Input:** `Input: s = '1101'`  \
  **Explanation:** Here, the first two '1's are adjacent and need to be altered to make the string alternating. Two changes are required.

{{< dots >}}
## Approach 🚀
The approach is to calculate the number of operations required for both alternating patterns: '010101...' and '101010...'. For each pattern, count how many characters need to be changed and then choose the minimum number of changes.

### Initial Thoughts 💭
- The problem is about comparing the string to two alternating patterns and finding the minimum number of changes needed.
- Since there are only two possible alternating patterns, we can compare the string to each pattern and count the differences.
{{< dots >}}
### Edge Cases 🌐
- If the string is empty, return 0 (no changes needed).
- Ensure the solution can handle strings of length up to 10^4 efficiently.
- If the string is already alternating, the result is 0.
- The solution should be optimized to handle the maximum string length.
{{< dots >}}
## Code 💻
```cpp
int minOperations(string s) {
    int zero = 0, one = 0, zf = false, of = false;
    for(int i = 0; i < s.size(); i++) {
        if(zf   && s[i] == '0') zero++;
        if(!zf  && s[i] == '1') zero++;
        if(!of   && s[i] == '0') one++;
        if(of  && s[i] == '1') one++;
        zf = !zf, of = !of;
    }
    return min(zero, one);
}
```

The function calculates the minimum number of operations to make a binary string alternate between 0 and 1 by counting mismatches for two possible patterns.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int minOperations(string s) {
	```
	Declares the function to calculate the minimum operations for an alternating binary string.

2. **Variable Initialization**
	```cpp
	    int zero = 0, one = 0, zf = false, of = false;
	```
	Initializes counters and flags for tracking mismatches with alternating patterns.

3. **Loop**
	```cpp
	    for(int i = 0; i < s.size(); i++) {
	```
	Iterates over the characters of the input string to count mismatches.

4. **Condition Check**
	```cpp
	        if(zf   && s[i] == '0') zero++;
	```
	Checks if the current character matches the '0' expectation for the first pattern.

5. **Condition Check**
	```cpp
	        if(!zf  && s[i] == '1') zero++;
	```
	Checks if the current character matches the '1' expectation for the first pattern.

6. **Condition Check**
	```cpp
	        if(!of   && s[i] == '0') one++;
	```
	Checks if the current character matches the '0' expectation for the second pattern.

7. **Condition Check**
	```cpp
	        if(of  && s[i] == '1') one++;
	```
	Checks if the current character matches the '1' expectation for the second pattern.

8. **Flag Update**
	```cpp
	        zf = !zf, of = !of;
	```
	Flips the flags to alternate the expected pattern for the next iteration.

9. **Return Statement**
	```cpp
	    return min(zero, one);
	```
	Returns the minimum of the two mismatch counts as the result.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the string.
- **Average Case:** O(n), as each character is checked against both alternating patterns.
- **Worst Case:** O(n), where n is the length of the string.

The time complexity is linear, as the string is traversed once.

### Space Complexity 💾
- **Best Case:** O(1), as no additional space is needed regardless of the input.
- **Worst Case:** O(1), since only a few variables are used for comparison.

The space complexity is constant, as only a few counters are used.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/description/)

---
{{< youtube 9vAQdmVU2ds >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
