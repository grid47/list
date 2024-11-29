
+++
authors = ["grid47"]
title = "Leetcode 3081: Replace Question Marks in String to Minimize Its Value"
date = "2024-01-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3081: Replace Question Marks in String to Minimize Its Value in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Greedy","Sorting","Heap (Priority Queue)","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "dYPKJ4Kelxw"
youtube_upload_date="2024-03-16"
youtube_thumbnail="https://i.ytimg.com/vi_webp/dYPKJ4Kelxw/maxresdefault.webp"
comments = true
+++



---
You are given a string `s` consisting of lowercase English letters and question marks (`?`). Your task is to replace all occurrences of `?` with any lowercase English letter in such a way that the total cost of the resulting string is minimized. The cost of a string is the sum of how many times each character has appeared before its current position. If there are multiple solutions with the same minimal cost, return the lexicographically smallest one.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `s` of length `n`, where `1 <= n <= 10^5`, and each character is either a lowercase English letter or `?`.
- **Example:** `s = "a?a?"`
- **Constraints:**
	- 1 <= s.length <= 10^5
	- s[i] is either a lowercase English letter or '?'

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a string where all occurrences of '?' are replaced with lowercase English letters in a way that minimizes the total cost. If there are multiple strings with the same minimal cost, return the lexicographically smallest one.
- **Example:** `Output: "abac"`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Minimize the cost of the resulting string by replacing '?' characters.

- Iterate over the string and maintain a frequency count of the letters already seen.
- For each '?', select the smallest letter that has appeared the least number of times so far.
- Replace '?' with this letter and update the frequency count.
{{< dots >}}
### Problem Assumptions ✅
- The string can be large, so the solution must be efficient.
- The string only contains lowercase English letters or '?' characters.
{{< dots >}}
## Examples 🧩
- **Input:** `s = "a?a?"`  \
  **Explanation:** In this case, replacing the '?' with 'b' and 'c' results in the string 'abac', which has a minimal cost of 1.

- **Input:** `s = "???"`  \
  **Explanation:** Replacing the '?' with 'a', 'b', and 'c' results in the string 'abc', which has a minimal cost of 0.

{{< dots >}}
## Approach 🚀
To solve this problem efficiently, we need to replace the '?' characters with the lexicographically smallest possible letters while ensuring that the resulting string has the minimal cost.

### Initial Thoughts 💭
- Replacing '?' with letters that minimize the cost requires tracking the frequency of each letter in the string.
- We need to ensure that we minimize the cost while maintaining the lexicographical order.
{{< dots >}}
### Edge Cases 🌐
- If the string contains only '?', the solution will replace each '?' with the smallest unused letters.
- For strings with the maximum length, the solution should be optimized to run in O(n) time.
- Strings that already have distinct letters or no '?' should be handled correctly.
- The solution should handle strings up to 10^5 characters efficiently.
{{< dots >}}
## Code 💻
```cpp
string minimizeStringValue(string s) {
    vector<int> frq(26, 0), taken;

    int n = s.size();
    for(char c: s) if(c != '?') frq[c - 'a']++;

    for(int i = 0; i < n; i++) {
        if(s[i] != '?') continue;

        int mn = 0;
        for(int j = 0; j < 26; j++)
            if(frq[j] < frq[mn]) mn = j;

        taken.push_back(mn);
        frq[mn]++;
    }

    sort(taken.begin(), taken.end());

    int idx = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '?')
        s[i] = taken[idx++] + 'a';
    }

    return s;
}
```

This function replaces all '?' characters in the input string `s` with the lexicographically smallest characters such that no character appears more times than any other character.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string minimizeStringValue(string s) {
	```
	Defines the function `minimizeStringValue` which takes a string `s` and returns a modified string where '?' characters are replaced with the lexicographically smallest characters.

2. **Variable Initialization**
	```cpp
	    vector<int> frq(26, 0), taken;
	```
	Declares a vector `frq` to track the frequency of each letter ('a' to 'z') in the string `s`. The `taken` vector will store the indices of characters to replace '?' with.

3. **Size Calculation**
	```cpp
	    int n = s.size();
	```
	Calculates the length of the string `s` and stores it in `n`.

4. **Frequency Count**
	```cpp
	    for(char c: s) if(c != '?') frq[c - 'a']++;
	```
	Loops through the string `s`, counting the frequency of each non-'?' character and storing it in the `frq` vector.

5. **Loop Through String**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Begins a loop through the string `s` to process each character.

6. **Skip Non-'?' Characters**
	```cpp
	        if(s[i] != '?') continue;
	```
	Skips the iteration if the current character is not a '?'.

7. **Find Minimum Frequency**
	```cpp
	        int mn = 0;
	```
	Initializes `mn` to 0, which will track the index of the character with the smallest frequency.

8. **Find Smallest Frequency Character**
	```cpp
	        for(int j = 0; j < 26; j++)
	```
	Loops through all 26 lowercase English letters to find the character with the smallest frequency in `frq`.

9. **Update Minimum Index**
	```cpp
	            if(frq[j] < frq[mn]) mn = j;
	```
	Updates `mn` to the index `j` if the frequency of the character at index `j` is smaller than the current minimum frequency.

10. **Store Chosen Character**
	```cpp
	        taken.push_back(mn);
	```
	Adds the index of the character with the smallest frequency to the `taken` vector.

11. **Update Frequency**
	```cpp
	        frq[mn]++;
	```
	Increments the frequency of the character chosen in the previous step.

12. **Sort Taken Characters**
	```cpp
	    sort(taken.begin(), taken.end());
	```
	Sorts the `taken` vector in ascending order, ensuring the characters are replaced lexicographically.

13. **Initialize Index**
	```cpp
	    int idx = 0;
	```
	Initializes `idx` to 0, which will be used to track the index of the next character to place in the string.

14. **Replace '?' Characters**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Loops through the string `s` again to replace '?' characters with the chosen characters from the `taken` vector.

15. **Replace Character**
	```cpp
	        if(s[i] == '?')
	```
	Checks if the current character is a '?' that needs to be replaced.

16. **Assign Smallest Character**
	```cpp
	        s[i] = taken[idx++] + 'a';
	```
	Replaces the '?' character with the corresponding character from the `taken` vector and increments `idx`.

17. **Return Statement**
	```cpp
	    return s;
	```
	Returns the modified string `s` with all '?' characters replaced.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The solution iterates over the string once, making the time complexity O(n), where n is the length of the string.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) since the frequency count array has a fixed size of 26 for the 26 lowercase English letters.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/replace-question-marks-in-string-to-minimize-its-value/description/)

---
{{< youtube dYPKJ4Kelxw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
