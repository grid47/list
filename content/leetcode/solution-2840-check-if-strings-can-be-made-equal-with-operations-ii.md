
+++
authors = ["grid47"]
title = "Leetcode 2840: Check if Strings Can be Made Equal With Operations II"
date = "2024-01-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2840: Check if Strings Can be Made Equal With Operations II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "yc9CXLWctOU"
youtube_upload_date="2023-09-02"
youtube_thumbnail="https://i.ytimg.com/vi_webp/yc9CXLWctOU/maxresdefault.webp"
comments = true
+++



---
You are given two strings s1 and s2, both of length n, consisting of lowercase English letters. You can perform the following operation on any of the two strings: choose any two indices i and j such that i < j and the difference j - i is even, then swap the two characters at those indices in the string. Return true if you can make s1 and s2 equal, and false otherwise.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two strings, s1 and s2, each containing n lowercase English letters.
- **Example:** `s1 = 'aceb', s2 = 'caeb'`
- **Constraints:**
	- s1 and s2 have the same length n.
	- 1 <= n <= 10^5.
	- s1 and s2 consist only of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if it's possible to make the two strings equal using the described operations, otherwise return false.
- **Example:** `true`
- **Constraints:**
	- The output should be a boolean value indicating whether the strings can be made equal or not.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine if s1 can be transformed into s2 using the allowed swap operations.

- For each character in s1 and s2, group them by their positions modulo 2 (even or odd indexed positions).
- Compare the counts of characters in corresponding groups for s1 and s2.
- If the counts match for both even and odd indexed positions, return true; otherwise, return false.
{{< dots >}}
### Problem Assumptions ✅
- The problem assumes that swapping characters is the only allowed operation.
- The strings can have repeated characters.
{{< dots >}}
## Examples 🧩
- **Input:** `s1 = 'aceb', s2 = 'caeb'`  \
  **Explanation:** We can swap characters at indices 0 and 2 and then swap characters at indices 1 and 3 to make s1 equal to s2.

- **Input:** `s1 = 'abe', s2 = 'bea'`  \
  **Explanation:** It's not possible to transform s1 into s2 since there is no valid swap that can achieve this.

{{< dots >}}
## Approach 🚀
The approach involves checking if we can group characters of s1 and s2 based on their even and odd indexed positions, and verify that the counts of each character match.

### Initial Thoughts 💭
- The problem involves swapping characters at specific indices, so checking the counts of characters in different indexed groups is key.
- By comparing character frequencies in the even and odd indexed groups of both strings, we can determine if it's possible to make the strings equal.
{{< dots >}}
### Edge Cases 🌐
- Empty strings are not allowed since the minimum length is 1.
- The solution should efficiently handle large strings with up to 10^5 characters.
- The strings may consist of identical characters or all distinct characters.
- Ensure the solution works efficiently within the given constraint of 1 <= n <= 10^5.
{{< dots >}}
## Code 💻
```cpp
bool checkStrings(string s1, string s2) {

int map[2][26] = {0}; // Initialize a 2D array with all elements set to 0

for (int i = 0; i < s1.length(); i++) {
map[i % 2][s1[i] - 'a']++;
map[i % 2][s2[i] - 'a']--;
}

for (int i = 0; i < 26; i++) {
if (map[0][i] != 0 || map[1][i] != 0) return false;
}

return true;}
```

This code checks if two strings can be made identical by swapping characters. It uses a 2D array to track character frequencies in both strings.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Initialization**
	```cpp
	bool checkStrings(string s1, string s2) {
	```
	Start of the function to check if two strings are identical by swapping characters.

2. **Array Setup**
	```cpp
	int map[2][26] = {0}; // Initialize a 2D array with all elements set to 0
	```
	Creates a 2D array to track character frequencies for both strings (two rows, 26 columns for each alphabet letter).

3. **Loop Through Strings**
	```cpp
	for (int i = 0; i < s1.length(); i++) {
	```
	Iterates through the characters of both strings simultaneously.

4. **Increment First String Frequency**
	```cpp
	map[i % 2][s1[i] - 'a']++;
	```
	Increments the frequency of the character in the first string (mapped to one of the rows in the array).

5. **Decrement Second String Frequency**
	```cpp
	map[i % 2][s2[i] - 'a']--;
	```
	Decrements the frequency of the character in the second string (mapped to the other row in the array).

6. **Final Check**
	```cpp
	for (int i = 0; i < 26; i++) {
	```
	Iterates through all the alphabet letters to check if the frequencies match.

7. **Check Frequency**
	```cpp
	if (map[0][i] != 0 || map[1][i] != 0) return false;
	```
	If any character's frequency is non-zero in either row, return false, meaning the strings cannot be made equal.

8. **End Function**
	```cpp
	return true;}
	```
	Returns true if all character frequencies match, meaning the strings can be made equal by swapping characters.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear, as we are processing the string once to count the character frequencies.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is linear, as we need to store the character frequencies for even and odd indexed positions.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/description/)

---
{{< youtube yc9CXLWctOU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
