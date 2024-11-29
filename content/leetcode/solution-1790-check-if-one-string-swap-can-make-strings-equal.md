
+++
authors = ["grid47"]
title = "Leetcode 1790: Check if One String Swap Can Make Strings Equal"
date = "2024-05-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1790: Check if One String Swap Can Make Strings Equal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "n4pxnAHTfeU"
youtube_upload_date="2021-03-14"
youtube_thumbnail="https://i.ytimg.com/vi/n4pxnAHTfeU/maxresdefault.jpg"
comments = true
+++



---
You are given two strings, s1 and s2, of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices. Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two strings, s1 and s2, both of equal length.
- **Example:** `Input: s1 = "abc", s2 = "bca"`
- **Constraints:**
	- 1 <= s1.length, s2.length <= 100
	- s1.length == s2.length
	- s1 and s2 consist of only lowercase English letters

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if it is possible to make both strings equal with at most one swap, otherwise return false.
- **Example:** `Output: true`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** We need to check if it's possible to make both strings equal by performing at most one swap on one of the strings.

- First, check if both strings already match. If they do, return true.
- If they do not match, check if exactly two characters are different between the strings.
- Ensure that swapping the two different characters results in equal strings.
{{< dots >}}
### Problem Assumptions ✅
- The strings are always of equal length.
- Both strings consist of only lowercase English letters.
{{< dots >}}
## Examples 🧩
- **Input:** `s1 = "abc", s2 = "bca"`  \
  **Explanation:** By swapping the first and third characters of s2, we can make both strings equal.

- **Input:** `s1 = "hello", s2 = "holle"`  \
  **Explanation:** The strings can be made equal by swapping the second and fourth characters of s2.

- **Input:** `s1 = "abc", s2 = "xyz"`  \
  **Explanation:** It is impossible to make the strings equal with a single swap, so the result is false.

{{< dots >}}
## Approach 🚀
The problem can be solved by first checking the difference between the two strings and evaluating if exactly one swap can make them equal.

### Initial Thoughts 💭
- The two strings must have exactly two different characters to be swappable into equality.
- If they are already equal, no swap is needed.
- Check if the strings already match. If they do, return true.
- If not, check if exactly two characters are different and if swapping them would make the strings equal.
{{< dots >}}
### Edge Cases 🌐
- There should not be any empty strings as per the constraints.
- The solution should work efficiently for strings of length up to 100.
- Both strings can be identical without requiring any swap.
- Strings should only contain lowercase English letters.
{{< dots >}}
## Code 💻
```cpp
bool areAlmostEqual(string s1, string s2) {
    int chg = 0, cnt = 0;
    vector<int> frq1(26, 0), frq2(26, 0);
    for(int i = 0; i < s1.size(); i++) {
        frq1[s1[i] - 'a']++;
        frq2[s2[i] - 'a']++;
        if(s1[i] != s2[i]) cnt++;
    }

    return frq1 == frq2 && (cnt == 2 || cnt == 0);
}
```

This function checks if two strings can be made equal by swapping exactly two characters. It counts the frequency of characters and the number of mismatches, then verifies if the strings have the same frequency distribution and two or zero mismatched characters.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool areAlmostEqual(string s1, string s2) {
	```
	Define the function `areAlmostEqual`, which takes two strings `s1` and `s2` as input and returns a boolean indicating whether the two strings can be made equal by swapping exactly two characters.

2. **Variable Initialization**
	```cpp
	    int chg = 0, cnt = 0;
	```
	Initialize variables `chg` (to count the number of changes required) and `cnt` (to count the number of mismatched characters between `s1` and `s2`).

3. **Frequency Arrays**
	```cpp
	    vector<int> frq1(26, 0), frq2(26, 0);
	```
	Initialize two frequency arrays `frq1` and `frq2` to store the frequency of characters in `s1` and `s2`, respectively. Each array has 26 slots, corresponding to the 26 letters of the alphabet.

4. **Loop through Strings**
	```cpp
	    for(int i = 0; i < s1.size(); i++) {
	```
	Iterate through each character in the strings `s1` and `s2`.

5. **Frequency Count for s1**
	```cpp
	        frq1[s1[i] - 'a']++;
	```
	Increment the frequency count for the character in string `s1` at position `i`.

6. **Frequency Count for s2**
	```cpp
	        frq2[s2[i] - 'a']++;
	```
	Increment the frequency count for the character in string `s2` at position `i`.

7. **Mismatch Count**
	```cpp
	        if(s1[i] != s2[i]) cnt++;
	```
	If the characters at position `i` in `s1` and `s2` do not match, increment the `cnt` variable to track the number of mismatched characters.

8. **Return Result**
	```cpp
	    return frq1 == frq2 && (cnt == 2 || cnt == 0);
	```
	Return true if the frequency distributions of the characters in `s1` and `s2` are identical and there are exactly two or zero mismatched characters. Otherwise, return false.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), when the strings are already equal.
- **Average Case:** O(n), where n is the length of the strings.
- **Worst Case:** O(n), since we only need to compare the two strings once.

The time complexity is linear as we just iterate over both strings once.

### Space Complexity 💾
- **Best Case:** O(1), since no extra space is needed.
- **Worst Case:** O(1), as no extra space is needed aside from a few variables.

The space complexity is constant as we do not require additional space that grows with the input size.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/description/)

---
{{< youtube n4pxnAHTfeU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
