
+++
authors = ["grid47"]
title = "Leetcode 859: Buddy Strings"
date = "2024-08-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 859: Buddy Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
You are given two strings, s and goal, consisting of lowercase letters. Your task is to determine whether you can swap exactly two characters in s so that the resulting string matches goal. If this is possible, return true, otherwise return false. The swap is defined as selecting two different indices i and j, and swapping the characters at those positions in s.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two strings, s and goal, both consisting of lowercase letters.
- **Example:** `Input: s = "cd", goal = "dc"`
- **Constraints:**
	- 1 <= s.length, goal.length <= 2 * 10^4
	- s and goal consist of lowercase letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if it is possible to swap two characters in s such that the string becomes equal to goal. Otherwise, return false.
- **Example:** `Output: true`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine if a valid swap exists such that s becomes goal.

- Step 1: If the lengths of s and goal are different, return false.
- Step 2: Count how many positions differ between s and goal. If more than two positions differ, return false.
- Step 3: If there are exactly two positions where s and goal differ, check if swapping these two characters will make the strings equal.
- Step 4: If the strings are already identical, check if any character repeats in s, as swapping identical characters will not change the string.
{{< dots >}}
### Problem Assumptions ✅
- The input strings s and goal will always contain lowercase English letters.
- The input strings will always be of valid lengths and contain only alphabetic characters.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = "xy", goal = "yx"`  \
  **Explanation:** In this example, we can swap the characters at indices 0 and 1 in s to get 'yx', which matches goal.

- **Input:** `Input: s = "xy", goal = "xy"`  \
  **Explanation:** In this example, s is already equal to goal, so the answer is false because no swap is necessary.

{{< dots >}}
## Approach 🚀
To determine if a valid swap is possible, we first compare the two strings and check the number of differing positions. Based on the result, we either check for a swap possibility or determine that a swap is not possible.

### Initial Thoughts 💭
- If the strings are already identical, no swap can be made to make them equal.
- If there are more than two differences, it's impossible to match the strings with just one swap.
- The solution involves counting the differing positions between s and goal, then checking if those positions can be swapped to match the two strings.
{{< dots >}}
### Edge Cases 🌐
- N/A: The inputs will always be valid strings of at least length 1.
- The solution must efficiently handle strings of length up to 2 * 10^4.
- If the strings are already identical, no swap is needed, so return false.
- If there are more than two differences between s and goal, return false.
- The lengths of s and goal are guaranteed to be within the given range, so large inputs will be handled efficiently.
{{< dots >}}
## Code 💻
```cpp
bool buddyStrings(string s, string goal) {
    if(s.size() != goal.size()) return false;
    int cnt = 0, fst = -1, scd = -1, cl = 0, fg = 0, t = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != goal[i]) {
            cnt++;
            if(fst == -1) fst = i;
            else if(scd == -1) scd = i;
        }
        if((fg >> (s[i] - 'a')) & 1) t = 1;
        fg |= (1 << (s[i] - 'a'));
    }
    
    if(cnt == 0) {
        if(t) return true;
        return false;
    }

    return (cnt == 2 && (s[fst] == goal[scd]) && (s[scd] == goal[fst]));
}
```

This function checks if two strings `s` and `goal` are buddy strings. It verifies if they can be made identical by swapping exactly two characters. The process includes checking string length, tracking mismatched characters, and validating swap conditions.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool buddyStrings(string s, string goal) {
	```
	This line defines the function `buddyStrings`, which takes two strings `s` and `goal` and returns a boolean indicating whether they can be made equal by swapping exactly two characters.

2. **Length Check**
	```cpp
	    if(s.size() != goal.size()) return false;
	```
	The function checks if the lengths of the two strings are equal. If they are not, the function returns `false` because they cannot be buddy strings.

3. **Variable Initialization**
	```cpp
	    int cnt = 0, fst = -1, scd = -1, cl = 0, fg = 0, t = 0;
	```
	Several variables are initialized: `cnt` counts mismatches, `fst` and `scd` store the indices of the first and second mismatched characters, `cl` is unused, `fg` tracks character frequencies, and `t` is a flag for duplicate characters.

4. **Loop Over Strings**
	```cpp
	    for(int i = 0; i < s.size(); i++) {
	```
	A loop starts to iterate over each character in the strings `s` and `goal`.

5. **Mismatch Detection**
	```cpp
	        if(s[i] != goal[i]) {
	```
	This condition checks if the characters at the current index `i` in `s` and `goal` are different. If they are, it counts as a mismatch.

6. **Increment Mismatch Count**
	```cpp
	            cnt++;
	```
	The `cnt` variable is incremented to keep track of the number of mismatched characters between `s` and `goal`.

7. **Track Mismatched Indices**
	```cpp
	            if(fst == -1) fst = i;
	```
	If the first mismatch is found (`fst == -1`), the index is stored in `fst`.

8. **Track Second Mismatch**
	```cpp
	            else if(scd == -1) scd = i;
	```
	If the second mismatch is found, its index is stored in `scd`.

9. **Frequency Check**
	```cpp
	        if((fg >> (s[i] - 'a')) & 1) t = 1;
	```
	This condition checks if the character `s[i]` has already appeared in the string using bitwise operations. If it has, the flag `t` is set to 1.

10. **Update Frequency**
	```cpp
	        fg |= (1 << (s[i] - 'a'));
	```
	The bitwise operation updates the `fg` variable to record the occurrence of the character `s[i]`.

11. **Mismatch Count Check**
	```cpp
	    if(cnt == 0) {
	```
	The function checks if there are no mismatches (`cnt == 0`). If there are no mismatches, it checks for duplicate characters.

12. **Duplicate Check**
	```cpp
	        if(t) return true;
	```
	If there are duplicate characters (indicated by `t`), the function returns `true` because the strings are already identical and can be considered buddy strings.

13. **Return False**
	```cpp
	        return false;
	```
	If there are no duplicates, the function returns `false` because the strings cannot be buddy strings.

14. **End Mismatch Check**
	```cpp
	    }
	```
	End of the mismatch count check block.

15. **Return Swap Condition Check**
	```cpp
	    return (cnt == 2 && (s[fst] == goal[scd]) && (s[scd] == goal[fst]));
	```
	The function checks if exactly two mismatches were found (`cnt == 2`), and if swapping the characters at the mismatched indices in `s` makes it equal to `goal`. If so, it returns `true`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the strings. This is the time required to compare the strings and check the number of differing positions.
- **Average Case:** O(n), as the comparison of strings takes linear time.
- **Worst Case:** O(n), where n is the length of the strings.



### Space Complexity 💾
- **Best Case:** O(1), since the space used does not depend on the size of the input strings.
- **Worst Case:** O(1), as no extra space is required other than a few variables for comparison.



**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/buddy-strings/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
