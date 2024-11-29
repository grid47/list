
+++
authors = ["grid47"]
title = "Leetcode 2451: Odd String Difference"
date = "2024-03-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2451: Odd String Difference in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "mxdN0xJiJDc"
youtube_upload_date="2022-10-29"
youtube_thumbnail="https://i.ytimg.com/vi_webp/mxdN0xJiJDc/maxresdefault.webp"
comments = true
+++



---
You are given an array of strings where each string is of the same length. Each string can be converted into a difference array where each element represents the difference between two consecutive characters' positions in the alphabet. All strings in the array have the same difference array except for one. Your task is to identify the string that has a unique difference array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array `words` where each element is a string of lowercase English letters.
- **Example:** `words = ["xyz", "abb", "dcz"]`
- **Constraints:**
	- 3 <= words.length <= 100
	- 2 <= words[i].length <= 20
	- words[i] consists of lowercase English letters

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the string that has a different difference array compared to all other strings in the input array.
- **Example:** `Output: "abb"`
- **Constraints:**
	- There will be exactly one string with a unique difference array.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the string with the unique difference array.

- 1. Compute the difference array for each string in the input array.
- 2. Store the difference arrays in a hash map where the key is the difference array and the value is a list of corresponding strings.
- 3. Identify the difference array that is unique by checking the size of the list for each key in the hash map.
- 4. Return the string corresponding to the unique difference array.
{{< dots >}}
### Problem Assumptions ✅
- The difference array calculation is based on alphabetic positions starting from 'a' = 0 to 'z' = 25.
- The input array always has at least one string with a unique difference array.
{{< dots >}}
## Examples 🧩
- **Input:** `words = ["xyz", "abb", "dcz"]`  \
  **Explanation:** The difference array for 'xyz' is [1, 1], for 'abb' is [1, 1], and for 'dcz' is [1, -1]. The unique difference array is [1, -1], so 'dcz' is the string with a unique difference array.

- **Input:** `words = ["abc", "def", "xyz"]`  \
  **Explanation:** The difference array for 'abc' is [1, 1], for 'def' is [1, 1], and for 'xyz' is [1, 1]. No string has a unique difference array in this case.

{{< dots >}}
## Approach 🚀
We will calculate the difference array for each string and store it in a hash map. The string with a unique difference array will be found by checking which difference array is not repeated.

### Initial Thoughts 💭
- The problem is a comparison of difference arrays, which can be efficiently handled with a hash map.
- We can calculate the difference array in O(n) time for each string and use the hash map to store and track the frequency of each difference array.
{{< dots >}}
### Edge Cases 🌐
- Input will not be empty as per the problem constraints.
- With a large number of words, the solution should remain efficient, as each word's difference array is computed in linear time.
- Special cases such as all words having the same difference array will not occur based on problem constraints.
- The time complexity of the solution should be manageable for the given constraints (up to 100 words of length 20).
{{< dots >}}
## Code 💻
```cpp
class Solution {
string difference(string& s) {
    string d;
    
    for (int i = 0; i < s.size() - 1; i++) {
        d += s[i + 1] - s[i];
    }
    
    return d;
}
public:
string oddString(vector<string>& words) {
    int  n = words[0].size();
    unordered_map<string, vector<string>> mp;
    for (auto &it : words) {
        mp[difference(it)].push_back(it);
    }
    
    for (auto &it : mp) {
        if (it.second.size() == 1) return it.second[0];
    }
    
    return "";
}
```

This code defines a solution to find the odd string in a given list of strings. It compares the differences between consecutive characters in the strings to identify the unique string.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Definition**
	```cpp
	class Solution {
	```
	Defines the `Solution` class, which contains the function implementations for solving the problem.

2. **Difference Function**
	```cpp
	string difference(string& s) {
	```
	This function calculates the difference between consecutive characters in the string `s` and returns a string representing the differences.

3. **Variable Initialization**
	```cpp
	    string d;
	```
	Initializes an empty string `d` to store the differences between consecutive characters.

4. **Loop Setup**
	```cpp
	    for (int i = 0; i < s.size() - 1; i++) {
	```
	Starts a loop to iterate over the string `s`, excluding the last character.

5. **Difference Calculation**
	```cpp
	        d += s[i + 1] - s[i];
	```
	Calculates the difference between the ASCII values of consecutive characters `s[i + 1]` and `s[i]`, and appends the result to string `d`.

6. **Return Statement**
	```cpp
	    return d;
	```
	Returns the string `d`, which contains the differences between consecutive characters of the input string `s`.

7. **Public Access Modifier**
	```cpp
	public:
	```
	Specifies that the following function `oddString` is publicly accessible from outside the class.

8. **Odd String Function**
	```cpp
	string oddString(vector<string>& words) {
	```
	This function finds the 'odd' string in the list of words, which differs in its pattern of consecutive character differences.

9. **Variable Initialization**
	```cpp
	    int  n = words[0].size();
	```
	Initializes `n` to the length of the first word in the `words` list.

10. **Map Initialization**
	```cpp
	    unordered_map<string, vector<string>> mp;
	```
	Initializes an unordered map `mp` to store groups of words, where the key is the string of differences between consecutive characters.

11. **Map Population**
	```cpp
	    for (auto &it : words) {
	```
	Iterates through each word `it` in the list `words`.

12. **Difference and Map Update**
	```cpp
	        mp[difference(it)].push_back(it);
	```
	Calls the `difference` function for each word and stores the word in the map `mp` under the key corresponding to its character differences.

13. **Find Odd String**
	```cpp
	    for (auto &it : mp) {
	```
	Iterates through each entry in the map `mp`, where each entry contains a list of words with the same character differences.

14. **Return Odd String**
	```cpp
	        if (it.second.size() == 1) return it.second[0];
	```
	If a group in the map has only one word, it is the 'odd' string, so the function returns it.

15. **Return Empty String**
	```cpp
	    return "";
	```
	If no odd string is found, the function returns an empty string.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n * m)
- **Average Case:** O(n * m)
- **Worst Case:** O(n * m)

For each word (n words), we calculate the difference array in O(m) time, where m is the length of the word.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n * m)

The space complexity is determined by the number of words and the storage of their corresponding difference arrays.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/odd-string-difference/description/)

---
{{< youtube mxdN0xJiJDc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
