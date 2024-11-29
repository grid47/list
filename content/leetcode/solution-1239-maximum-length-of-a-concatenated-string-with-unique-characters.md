
+++
authors = ["grid47"]
title = "Leetcode 1239: Maximum Length of a Concatenated String with Unique Characters"
date = "2024-07-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1239: Maximum Length of a Concatenated String with Unique Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Backtracking","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "d4SPuvkaeoo"
youtube_upload_date="2021-09-22"
youtube_thumbnail="https://i.ytimg.com/vi/d4SPuvkaeoo/maxresdefault.jpg"
comments = true
+++



---
You are given an array of strings arr. Return the maximum possible length of a string s formed by concatenating a subsequence of arr such that all characters in s are unique.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array of strings arr.
- **Example:** `arr = ["ab", "cd", "ef"]`
- **Constraints:**
	- 1 <= arr.length <= 16
	- 1 <= arr[i].length <= 26
	- arr[i] contains only lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum possible length of a string formed by concatenating a subsequence of arr with unique characters.
- **Example:** `6`
- **Constraints:**
	- The output is the length of the longest valid concatenation of strings with unique characters.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the maximum length of a string formed by concatenating strings from the array with unique characters.

- Initialize an array or list to store the bitmask representation of valid strings.
- Iterate through each string in arr and convert it into a bitmask of its characters.
- For each string, check if it can be added to the current subsequence without repeating any characters.
- Update the maximum length accordingly.
{{< dots >}}
### Problem Assumptions ✅
- Each string in arr has at most 26 characters and contains only lowercase letters.
- The input strings are non-empty.
{{< dots >}}
## Examples 🧩
- **Input:** `arr = ["ab", "cd", "ef"]`  \
  **Explanation:** The valid concatenation is 'abcdef' which has a length of 6.

{{< dots >}}
## Approach 🚀
We can use bitmasking to efficiently check whether a set of characters is unique and form the maximum length string.

### Initial Thoughts 💭
- Bitmasking can be used to represent the set of characters of a string.
- By iterating over all strings and maintaining a record of unique character sets, we can generate the longest possible string.
{{< dots >}}
### Edge Cases 🌐
- Not applicable since arr contains at least one string.
- If arr contains 16 strings, the solution needs to efficiently handle the potentially large number of combinations.
- If all strings in arr contain duplicate characters, the maximum length may be smaller than the sum of their lengths.
- Ensure that the algorithm handles the maximum input sizes efficiently.
{{< dots >}}
## Code 💻
```cpp
int maxLength(vector<string>& arr) {
    vector<bitset<26>> dp = {bitset<26>()};
    int res = 0;
    for(auto &s: arr) {
        bitset<26> a;
        for(char x: s)
            a.set(x-'a');
        int n = a.count();
        if(n < s.size()) continue;
        for(int i = dp.size() -1; i >= 0; i--) {
            bitset c = dp[i];
            if ((c&a).any()) continue;
            dp.push_back(c|a);
            res = max(res, (int) c.count()+n);
            
        }
    }
    return res;
}
```

This function calculates the maximum length of a unique string that can be formed by concatenating strings from the input array `arr`. It uses bitsets to represent the unique characters in each string and dynamically tracks the maximum length by checking character overlaps using bitwise operations.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maxLength(vector<string>& arr) {
	```
	The function `maxLength` is defined to calculate the maximum length of a concatenated string with unique characters from the input array `arr`.

2. **Bitset Initialization**
	```cpp
	    vector<bitset<26>> dp = {bitset<26>()};
	```
	A vector of bitsets `dp` is initialized with an empty bitset, which will be used to track the unique characters in the strings as they are processed.

3. **Result Initialization**
	```cpp
	    int res = 0;
	```
	An integer `res` is initialized to 0. This will hold the maximum length of the concatenated string with unique characters.

4. **Loop Over Strings**
	```cpp
	    for(auto &s: arr) {
	```
	A loop is set up to iterate through each string `s` in the input array `arr`.

5. **Bitset Creation**
	```cpp
	        bitset<26> a;
	```
	A bitset `a` is created to represent the characters in the current string `s`. Each character is mapped to a bit in the bitset.

6. **Character Processing**
	```cpp
	        for(char x: s)
	```
	A loop is used to iterate over each character `x` in the current string `s`.

7. **Set Bit**
	```cpp
	            a.set(x-'a');
	```
	For each character `x`, the corresponding bit in the bitset `a` is set to 1, representing the presence of that character in the string.

8. **Count Unique Characters**
	```cpp
	        int n = a.count();
	```
	The number of unique characters in the string `s` is counted by calling `a.count()`, which returns the number of set bits in the bitset.

9. **Skip Invalid Strings**
	```cpp
	        if(n < s.size()) continue;
	```
	If the number of unique characters `n` is less than the length of the string `s`, it means the string contains duplicate characters, and it is skipped.

10. **Loop Over Previous Results**
	```cpp
	        for(int i = dp.size() -1; i >= 0; i--) {
	```
	A loop iterates over the previous bitsets in `dp` (which represent previously considered strings), starting from the most recent.

11. **Retrieve Previous Bitset**
	```cpp
	            bitset c = dp[i];
	```
	A copy of the bitset `c` is made from the current bitset in `dp`.

12. **Check for Character Overlap**
	```cpp
	            if ((c&a).any()) continue;
	```
	If the bitwise AND of `c` and `a` has any set bits, it means there is an overlap of characters between the two strings, and the current combination is skipped.

13. **Update DP and Result**
	```cpp
	            dp.push_back(c|a);
	```
	If no overlap is found, the new combination of characters (represented by the union of `c` and `a`) is added to `dp`.

14. **Update Maximum Length**
	```cpp
	            res = max(res, (int) c.count()+n);
	```
	The result `res` is updated to the maximum of its current value and the sum of the count of unique characters in `c` and `a`.

15. **Return Result**
	```cpp
	    return res;
	```
	The function returns the final result `res`, which contains the maximum length of a string with unique characters formed by concatenating strings from the input array.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(2^n)
- **Average Case:** O(2^n)
- **Worst Case:** O(2^n)

In the worst case, we have to check all combinations of subsequences of the input strings.

### Space Complexity 💾
- **Best Case:** O(2^n)
- **Worst Case:** O(2^n)

Space complexity is driven by the storage of bitmask representations of valid subsequences.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/)

---
{{< youtube d4SPuvkaeoo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
