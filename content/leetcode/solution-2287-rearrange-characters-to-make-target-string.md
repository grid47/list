
+++
authors = ["grid47"]
title = "Leetcode 2287: Rearrange Characters to Make Target String"
date = "2024-03-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2287: Rearrange Characters to Make Target String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "Mgtl8CIIWX4"
youtube_upload_date="2022-05-29"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Mgtl8CIIWX4/maxresdefault.webp"
comments = true
+++



---
You are given two strings, s and target. Your task is to determine the maximum number of times you can rearrange the characters of s to form the string target. A character from s can only be used once in the target string, and the letters must be rearranged to form a new target string each time.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two strings, s and target, where s represents a string of available characters, and target is the string you are trying to form. Both strings consist of lowercase English letters.
- **Example:** `Input: s = "helloworld", target = "low"`
- **Constraints:**
	- 1 <= s.length <= 100
	- 1 <= target.length <= 10
	- s and target consist of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum number of times the string target can be formed by rearranging letters from s.
- **Example:** `Output: 1`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate how many full copies of the target string can be formed using characters from s.

- Step 1: Count the frequency of each character in the target string.
- Step 2: Count the frequency of each character in the string s.
- Step 3: For each character in the target string, check how many times it can be used from s and keep track of the minimum count across all characters.
- Step 4: Return the minimum count as the result, which represents the maximum number of target strings that can be formed.
{{< dots >}}
### Problem Assumptions ✅
- The strings consist only of lowercase English letters.
- All characters in the target string must be present in the source string s, and we can't reuse characters from s.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = "helloworld", target = "low"`  \
  **Explanation:** In this case, we can use 'l', 'o', and 'w' from s to form one copy of the target string 'low'. We can only form one copy as the string 'low' requires a specific combination of characters, and there are no extra 'w' or 'o' left to form another copy.

- **Input:** `Input: s = "aabbcc", target = "abc"`  \
  **Explanation:** Here, we can form one copy of the string 'abc' as we have exactly one 'a', one 'b', and one 'c'. The result is 1.

{{< dots >}}
## Approach 🚀
To solve this problem, we'll count the frequency of characters in both s and target, then calculate how many full target strings can be formed based on the availability of each character.

### Initial Thoughts 💭
- This problem is similar to counting the frequency of characters and comparing how many full sets can be made.
- The key is to keep track of how many times each character appears in both s and target.
- We need to calculate the minimum number of target strings that can be formed, which is determined by the character in the target string that is the most limiting.
{{< dots >}}
### Edge Cases 🌐
- Both s and target will not be empty as per the problem constraints.
- The algorithm should efficiently handle strings of length up to 100 for s.
- If s contains more characters than target, it does not affect the number of full target strings that can be formed.
- We only need to consider lowercase English letters.
{{< dots >}}
## Code 💻
```cpp
int rearrangeCharacters(string s, string target) {
    unordered_map<char,int> targetFreq ; 
    for(auto a : target) {
         targetFreq[a] ++;
    }
    unordered_map<char , int> sentFreq ; 
    for(auto a : s) {
        sentFreq[a] ++ ; 
    }
    int mn = INT_MAX  ; 
    for(auto a : targetFreq ) {
         mn = min(mn , sentFreq[a.first]/a.second); 
    }
    return mn ; 
}
```

This function calculates the maximum number of times the characters from the string `target` can be rearranged using characters from the string `s`. It works by counting the frequency of characters in both strings and determining the minimum number of complete rearrangements possible.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int rearrangeCharacters(string s, string target) {
	```
	The function `rearrangeCharacters` is declared, which takes two strings `s` and `target` as input and returns an integer representing the maximum number of times the `target` string can be formed from the characters of `s`.

2. **Initialize Target Frequency Map**
	```cpp
	    unordered_map<char,int> targetFreq ; 
	```
	An unordered map `targetFreq` is initialized to store the frequency of each character in the `target` string.

3. **Iterate Over Target String**
	```cpp
	    for(auto a : target) {
	```
	A `for` loop iterates over each character in the `target` string to count its frequency.

4. **Update Target Frequency Map**
	```cpp
	         targetFreq[a] ++;
	```
	For each character `a` in the `target` string, the frequency of that character is incremented in the `targetFreq` map.

5. **Initialize Sent Frequency Map**
	```cpp
	    unordered_map<char , int> sentFreq ; 
	```
	An unordered map `sentFreq` is initialized to store the frequency of each character in the `s` string.

6. **Iterate Over Sent String**
	```cpp
	    for(auto a : s) {
	```
	A `for` loop iterates over each character in the `s` string to count its frequency.

7. **Update Sent Frequency Map**
	```cpp
	        sentFreq[a] ++ ; 
	```
	For each character `a` in the `s` string, the frequency of that character is incremented in the `sentFreq` map.

8. **Initialize Minimum Count**
	```cpp
	    int mn = INT_MAX  ; 
	```
	The variable `mn` is initialized to `INT_MAX` to track the minimum number of times the `target` string can be formed from the characters in `s`.

9. **Check for Minimum Rearrangement**
	```cpp
	    for(auto a : targetFreq ) {
	```
	A `for` loop iterates over each character-frequency pair in the `targetFreq` map.

10. **Update Minimum Count**
	```cpp
	         mn = min(mn , sentFreq[a.first]/a.second); 
	```
	For each character in `targetFreq`, the minimum number of times the character can be rearranged is calculated by dividing the frequency in `sentFreq` by the required frequency in `targetFreq`. The result is stored in `mn`.

11. **Return the Result**
	```cpp
	    return mn ; 
	```
	The function returns the value of `mn`, which represents the maximum number of times the `target` string can be formed using characters from `s`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n + m)
- **Average Case:** O(n + m)
- **Worst Case:** O(n + m)

The time complexity is O(n + m), where n is the length of s and m is the length of target, as we need to count the frequency of each character in both strings.

### Space Complexity 💾
- **Best Case:** O(n + m)
- **Worst Case:** O(n + m)

The space complexity is O(n + m), where n is the length of s and m is the length of target, due to the frequency maps used for both strings.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/rearrange-characters-to-make-target-string/description/)

---
{{< youtube Mgtl8CIIWX4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
