
+++
authors = ["grid47"]
title = "Leetcode 131: Palindrome Partitioning"
date = "2024-10-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 131: Palindrome Partitioning in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/131.webp"
youtube = "7GlqVABgjJU"
youtube_upload_date="2020-11-23"
youtube_thumbnail="https://i.ytimg.com/vi/7GlqVABgjJU/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/131.webp" 
    alt="A string being gently split into palindrome segments, with each partition glowing softly."
    caption="Solution to LeetCode 131: Palindrome Partitioning Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a string s. Partition the string into all possible substrings such that each substring is a palindrome.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a string s of lowercase English letters.
- **Example:** `'aab'`
- **Constraints:**
	- 1 <= s.length <= 16
	- s contains only lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a list of all possible palindromic partitions of the input string.
- **Example:** `[['a', 'a', 'b'], ['aa', 'b']]`
- **Constraints:**
	- The output will be a list of lists, where each list contains palindromic substrings.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find all partitions of the string such that each substring is a palindrome.

- 1. Perform a backtracking approach to explore all partitions of the string.
- 2. For each substring, check if it is a palindrome.
- 3. If it is a palindrome, add it to the current partition and proceed to partition the remaining part of the string.
- 4. If we reach the end of the string, add the partition to the result.
{{< dots >}}
### Problem Assumptions ✅
- The string s is non-empty and only contains lowercase letters.
{{< dots >}}
## Examples 🧩
- **Input:** `'aab'`  \
  **Explanation:** The string can be partitioned into ['a', 'a', 'b'] or ['aa', 'b'], as both are palindromes.

- **Input:** `'a'`  \
  **Explanation:** Since the string is just a single character, it is inherently a palindrome, and the only valid partition is ['a'].

{{< dots >}}
## Approach 🚀
We can use a backtracking approach to explore all possible partitions of the string, checking if each substring is a palindrome.

### Initial Thoughts 💭
- We need to check if substrings are palindromes.
- We will explore all possible partitions of the string.
- A backtracking approach works well because we can build the solution incrementally and backtrack when a non-palindromic substring is found.
{{< dots >}}
### Edge Cases 🌐
- If the input string is empty, return an empty list.
- The algorithm should be able to handle the maximum string length of 16.
- If the string consists of a single character, the result should just be that character in a list.
- The string will contain only lowercase English letters.
{{< dots >}}
## Code 💻
```cpp
vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> tmp;
    bt(ans, tmp, s, 0);
    return ans;
}

void bt(vector<vector<string>> &ans, vector<string> &tmp, string s, int idx) {
    if(idx == s.size()) {
        ans.push_back(tmp);
        return;
    }
    
    for(int i = idx; i < s.size(); i++) {
        if(isPal(s, idx, i)) {
          
            tmp.push_back(s.substr(idx, i - idx + 1));
            bt(ans, tmp, s, i + 1);
            tmp.pop_back();
        }
    }
}

bool isPal(string s, int i, int j) {
    while(i <= j) {
        if(s[i] != s[j])
            return false;
        i++, j--;
    }
    return true;
}
```

This solution finds all possible palindrome partitions of a given string using backtracking. It explores every possible split of the string and adds the partition to the result if each substring is a palindrome.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<vector<string>> partition(string s) {
	```
	Define the `partition` function, which takes a string `s` and returns all possible palindrome partitions of the string.

2. **Variable Declaration**
	```cpp
	    vector<vector<string>> ans;
	```
	Declare a 2D vector `ans` to store the resulting palindrome partitions.

3. **Variable Declaration**
	```cpp
	    vector<string> tmp;
	```
	Declare a temporary vector `tmp` to store the current palindrome partition while exploring.

4. **Backtracking Call**
	```cpp
	    bt(ans, tmp, s, 0);
	```
	Call the backtracking function `bt` to explore all possible partitions of the string starting from index 0.

5. **Return Statement**
	```cpp
	    return ans;
	```
	Return the resulting 2D vector `ans` containing all valid palindrome partitions.

6. **Backtracking Function Declaration**
	```cpp
	void bt(vector<vector<string>> &ans, vector<string> &tmp, string s, int idx) {
	```
	Define the `bt` function that performs backtracking to explore all possible palindrome partitions.

7. **Base Case Check**
	```cpp
	    if(idx == s.size()) {
	```
	Check if the current index has reached the end of the string, indicating a valid partition.

8. **Push Partition**
	```cpp
	        ans.push_back(tmp);
	```
	Add the current palindrome partition stored in `tmp` to the result vector `ans`.

9. **Return Statement**
	```cpp
	        return;
	```
	Return from the function since we have found a valid partition.

10. **Loop Through Substrings**
	```cpp
	    for(int i = idx; i < s.size(); i++) {
	```
	Loop through all possible substring endings starting from the current index `idx`.

11. **Palindrome Check**
	```cpp
	        if(isPal(s, idx, i)) {
	```
	Check if the current substring from `idx` to `i` is a palindrome using the `isPal` function.

12. **Add Substring to Partition**
	```cpp
	            tmp.push_back(s.substr(idx, i - idx + 1));
	```
	If the substring is a palindrome, add it to the temporary partition vector `tmp`.

13. **Recursive Call**
	```cpp
	            bt(ans, tmp, s, i + 1);
	```
	Recursively call the backtracking function `bt` to explore further partitions starting from the next index `i + 1`.

14. **Remove Last Substring**
	```cpp
	            tmp.pop_back();
	```
	Remove the last added substring from the temporary partition to explore other possible partitions.

15. **End Backtracking Function**
	```cpp
	}
	```
	End of the backtracking function `bt`.

16. **Palindrome Check Function Declaration**
	```cpp
	bool isPal(string s, int i, int j) {
	```
	Define the `isPal` function to check if a substring of `s` from index `i` to `j` is a palindrome.

17. **Loop for Palindrome Check**
	```cpp
	    while(i <= j) {
	```
	Use a loop to compare characters at both ends of the substring, moving towards the center.

18. **Character Comparison**
	```cpp
	        if(s[i] != s[j])
	```
	If characters at the current positions `i` and `j` don't match, return `false` since the substring is not a palindrome.

19. **Return False**
	```cpp
	            return false;
	```
	Return `false` if the substring is not a palindrome.

20. **Move Pointers**
	```cpp
	        i++, j--;
	```
	Move the pointers `i` and `j` towards the center of the substring.

21. **Return True**
	```cpp
	    return true;
	```
	Return `true` if the entire substring is a palindrome.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2), where n is the length of the string. In the best case, the string has no valid partitions and only the single character partitions are considered.
- **Average Case:** O(2^n), since there are potentially 2^n ways to partition the string.
- **Worst Case:** O(n^2 * 2^n), where n is the length of the string, because we check each substring for being a palindrome for each partition.

The time complexity arises from the recursive exploration of all partitions and palindrome checks.

### Space Complexity 💾
- **Best Case:** O(n), when only a few recursive calls are made.
- **Worst Case:** O(n), due to the recursive call stack in the backtracking approach.

The space complexity is dominated by the recursive stack and the space used to store the palindromic substrings.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/palindrome-partitioning/description/)

---
{{< youtube 7GlqVABgjJU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
