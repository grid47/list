
+++
authors = ["grid47"]
title = "Leetcode 2707: Extra Characters in a String"
date = "2024-02-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2707: Extra Characters in a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Dynamic Programming","Trie"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "ONstwO1cD7c"
youtube_upload_date="2023-09-02"
youtube_thumbnail="https://i.ytimg.com/vi/ONstwO1cD7c/maxresdefault.jpg"
comments = true
+++



---
You are given a string and a list of words. Your task is to break the string into one or more non-overlapping substrings such that each substring is a word from the given list. However, some characters of the string may not be used in any substring. Your goal is to minimize the number of unused characters.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string and a list of distinct words.
- **Example:** `Input: s = "codingrocks", dictionary = ["code", "rocks", "dog"]`
- **Constraints:**
	- 1 <= s.length <= 50
	- 1 <= dictionary.length <= 50
	- 1 <= dictionary[i].length <= 50
	- dictionary[i] and s consists of only lowercase English letters
	- dictionary contains distinct words

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the minimum number of unused characters left after breaking the string optimally into substrings from the dictionary.
- **Example:** `Output: 3`
- **Constraints:**
	- The number of unused characters should be minimized.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the minimum number of extra characters by breaking the string into substrings present in the dictionary.

- Step 1: Use dynamic programming to try and break the string into valid substrings from the dictionary.
- Step 2: For each possible break, check if the substring exists in the dictionary.
- Step 3: Minimize the number of unused characters after breaking the string.
{{< dots >}}
### Problem Assumptions ✅
- The dictionary contains distinct words.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = "helloworld", dictionary = ["hello", "world"]`  \
  **Explanation:** We can break the string into two substrings: "hello" and "world", using all characters from the string. There are no extra characters left, so the output is 0.

- **Input:** `Input: s = "codingrocks", dictionary = ["code", "rocks", "dog"]`  \
  **Explanation:** The string can be split into "code" and "rocks". The leftover characters are 'i' and 'n', so the output is 2.

{{< dots >}}
## Approach 🚀
To solve this problem, a dynamic programming approach is used where we break the string and attempt to match substrings with the dictionary words, minimizing the leftover characters.

### Initial Thoughts 💭
- The problem can be approached using dynamic programming (DP) to check all possible splits of the string.
- We should keep track of the minimum extra characters after each possible split.
{{< dots >}}
### Edge Cases 🌐
- The string will never be empty as per constraints.
- The solution should handle strings up to length 50 efficiently.
- If no valid breaks are possible, the solution should return the entire length of the string as leftover.
- Ensure efficient handling of all possible substrings within the given constraints.
{{< dots >}}
## Code 💻
```cpp
set<string> dic;
string str;
vector<int> memo;
int n;

int dp(int idx) {
    
    if(idx == n) return 0;
    
    if(memo[idx] != -1) return memo[idx];
    
    int ans = INT_MAX;
    
    int len = 1;
    for(int i = idx; i < n; i++) {
        
        string s = str.substr(idx, len);
        
        if(dic.count(s)) {
            ans = min(ans, dp(idx + len));
        } else {
            ans = min(ans, len + dp(idx + len));                
        }
        
        len++;
    }
    
    return memo[idx] = ans;
}

int minExtraChar(string s, vector<string>& dictionary) {
    
    n = s.size();
    str = s;
    memo.resize(n, -1);
    
    for(auto x: dictionary) {
        dic.insert(x);
    }
    
    return dp(0);
    
}
```

The `minExtraChar` function finds the minimum number of extra characters that need to be added to a string `s` so that it can be split into words from a given dictionary. It uses dynamic programming to solve the problem efficiently.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Set Initialization**
	```cpp
	set<string> dic;
	```
	A set `dic` is initialized to store the dictionary words for efficient look-up.

2. **String Initialization**
	```cpp
	string str;
	```
	A string `str` is initialized to store the input string `s`.

3. **Vector Initialization**
	```cpp
	vector<int> memo;
	```
	A vector `memo` is declared to store the computed results for dynamic programming. This helps to avoid recalculating results for overlapping subproblems.

4. **Integer Initialization**
	```cpp
	int n;
	```
	An integer `n` is declared to store the length of the input string `s`.

5. **Function Declaration**
	```cpp
	int dp(int idx) {
	```
	The `dp` function is declared. It takes an index `idx` and returns the minimum number of extra characters needed to split the substring starting at `idx` into valid words from the dictionary.

6. **Base Case - End of String**
	```cpp
	    if(idx == n) return 0;
	```
	Base case: if the index `idx` has reached the end of the string, return 0 as no extra characters are needed.

7. **Memoization Check**
	```cpp
	    if(memo[idx] != -1) return memo[idx];
	```
	Check if the result for the current index `idx` has already been computed. If so, return the stored result from the `memo` vector.

8. **Initialization**
	```cpp
	    int ans = INT_MAX;
	```
	Initialize a variable `ans` to store the minimum number of extra characters found for the current substring. It is initially set to the maximum possible value.

9. **Length Initialization**
	```cpp
	    int len = 1;
	```
	Initialize the variable `len` to 1, representing the length of the current substring being considered.

10. **For Loop**
	```cpp
	    for(int i = idx; i < n; i++) {
	```
	Start a for loop to iterate through the string starting at index `idx` and consider substrings of increasing length.

11. **Substring Extraction**
	```cpp
	        string s = str.substr(idx, len);
	```
	Extract a substring `s` from the string `str`, starting at index `idx` with length `len`.

12. **Dictionary Lookup**
	```cpp
	        if(dic.count(s)) {
	```
	Check if the substring `s` exists in the dictionary `dic`.

13. **Recursive Call - Valid Word**
	```cpp
	            ans = min(ans, dp(idx + len));
	```
	If `s` is a valid word in the dictionary, recursively call `dp` with the next index `idx + len` and update the answer `ans` with the minimum result.

14. **Else Block - Invalid Word**
	```cpp
	        } else {
	```
	If the substring `s` is not a valid word in the dictionary, handle the case where extra characters are needed.

15. **Recursive Call - Invalid Word**
	```cpp
	            ans = min(ans, len + dp(idx + len));
	```
	If `s` is not a valid word, add `len` (the length of the substring) to the result of the recursive call `dp(idx + len)` to account for extra characters.

16. **Increment Length**
	```cpp
	        len++;
	```
	Increment the length of the substring `len` for the next iteration.

17. **Return Statement**
	```cpp
	    return memo[idx] = ans;
	```
	Store the computed result `ans` in `memo[idx]` and return it.

18. **Function Declaration**
	```cpp
	int minExtraChar(string s, vector<string>& dictionary) {
	```
	The `minExtraChar` function is declared. It takes the input string `s` and the dictionary `dictionary` as parameters and returns the minimum number of extra characters.

19. **Initialize n**
	```cpp
	    n = s.size();
	```
	Set `n` to the length of the input string `s`.

20. **Assign String**
	```cpp
	    str = s;
	```
	Assign the string `s` to the global variable `str`.

21. **Resize Memo**
	```cpp
	    memo.resize(n, -1);
	```
	Resize the `memo` vector to size `n` and initialize all values to `-1` to indicate that no subproblem has been solved yet.

22. **Insert Dictionary Words**
	```cpp
	    for(auto x: dictionary) {
	```
	Iterate through the `dictionary` and insert each word into the `dic` set.

23. **Insert Word**
	```cpp
	        dic.insert(x);
	```
	Insert each word `x` from the dictionary into the set `dic`.

24. **Return Statement**
	```cpp
	    return dp(0);
	```
	Call the `dp` function starting at index `0` to calculate the result and return it.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The time complexity is O(n^2) due to checking all possible substrings against the dictionary.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) for storing the DP array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/extra-characters-in-a-string/description/)

---
{{< youtube ONstwO1cD7c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
