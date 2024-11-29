
+++
authors = ["grid47"]
title = "Leetcode 2185: Counting Words With a Given Prefix"
date = "2024-04-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2185: Counting Words With a Given Prefix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","String Matching"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "8yMcHvAw2Q8"
youtube_upload_date="2022-02-27"
youtube_thumbnail="https://i.ytimg.com/vi_webp/8yMcHvAw2Q8/maxresdefault.webp"
comments = true
+++



---
You are given an array of strings and a target prefix. Your task is to count how many strings in the array start with this target prefix.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of strings and a string prefix.
- **Example:** `Input: words = ['train', 'truck', 'trip', 'track'], pref = 'tr'`
- **Constraints:**
	- 1 <= words.length <= 100
	- 1 <= words[i].length, pref.length <= 100
	- words[i] and pref consist of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of strings in the array that start with the given prefix.
- **Example:** `Output: 3`
- **Constraints:**
	- The prefix must match the beginning of the string exactly.

{{< dots >}}
### Core Logic 🔍
**Goal:** Count the strings in the array that begin with the specified prefix.

- Loop through each word in the array.
- For each word, check if it starts with the given prefix.
- Increment the count for each word that matches the condition.
{{< dots >}}
### Problem Assumptions ✅
- The input list is not empty.
- The input strings are valid lowercase words.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: words = ['apple', 'april', 'banana', 'appreciate'], pref = 'ap'`  \
  **Explanation:** The words that start with 'ap' are 'apple', 'april', and 'appreciate'. Hence, the result is 3.

- **Input:** `Input: words = ['dog', 'cat', 'doe', 'dong'], pref = 'do'`  \
  **Explanation:** The words that start with 'do' are 'dog', 'doe', and 'dong'. Hence, the result is 3.

{{< dots >}}
## Approach 🚀
We will use a simple approach to iterate through the list of words and check if each word starts with the given prefix.

### Initial Thoughts 💭
- The check for prefix can be easily done using string comparison methods.
- A simple iteration through the list of words and checking if each word starts with the prefix is sufficient.
{{< dots >}}
### Edge Cases 🌐
- If the words array is empty, the output should be 0.
- Handle cases with large arrays or long strings efficiently.
- The prefix length could be equal to or greater than the length of some words.
- Ensure that the prefix check works even if the prefix is longer than the word.
{{< dots >}}
## Code 💻
```cpp
int prefixCount(vector<string>& words, string s) {
    int cnt = 0;
    for(string x: words) {
        if(x.size() < s.size()) continue;
        bool flag = true;
        for(int i = 0; i < s.size(); i++) {
            if(x[i] != s[i]) {
                flag = false;
                break;
            }
        }
        if(flag) cnt++;
    }
    return cnt;        
}
```

This function counts how many strings in the `words` vector start with the prefix `s`. It iterates through the list of words and checks each word's prefix against the provided string `s`. If a match is found, it increments the counter.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int prefixCount(vector<string>& words, string s) {
	```
	This defines the function `prefixCount` which takes a vector of strings `words` and a string `s` as arguments. It returns an integer count of how many words in `words` start with the string `s`.

2. **Variable Declaration**
	```cpp
	    int cnt = 0;
	```
	The variable `cnt` is initialized to zero. This will hold the count of words in `words` that start with the prefix `s`.

3. **Loop**
	```cpp
	    for(string x: words) {
	```
	A for-loop is initiated to iterate through each string `x` in the vector `words`.

4. **Conditional Check**
	```cpp
	        if(x.size() < s.size()) continue;
	```
	This checks if the length of the current word `x` is shorter than the length of the prefix `s`. If so, it skips the current word as it cannot match the prefix.

5. **Flag Initialization**
	```cpp
	        bool flag = true;
	```
	A boolean flag `flag` is initialized to `true`. It will be used to track whether the current word `x` starts with the prefix `s`.

6. **Inner Loop**
	```cpp
	        for(int i = 0; i < s.size(); i++) {
	```
	An inner loop is used to iterate over each character of the string `s` (the prefix).

7. **Character Comparison**
	```cpp
	            if(x[i] != s[i]) {
	```
	This compares the `i`-th character of `x` with the `i`-th character of the prefix `s`. If they don't match, the flag is set to `false`.

8. **Flag Update**
	```cpp
	                flag = false;
	```
	If a mismatch is found, `flag` is set to `false`, indicating that the current word `x` does not start with the prefix `s`.

9. **Loop Break**
	```cpp
	                break;
	```
	This breaks the inner loop, as there's no need to check further characters in the current word `x`.

10. **Increment Count**
	```cpp
	        if(flag) cnt++;
	```
	If the flag is still `true` (i.e., the word starts with the prefix `s`), the counter `cnt` is incremented.

11. **Return Result**
	```cpp
	    return cnt;        
	```
	After iterating through all the words, the function returns the total count of words that start with the prefix `s`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) where n is the number of words, since we are iterating through each word and checking if it starts with the prefix.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1), as we only need a counter variable to track the number of valid words.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/counting-words-with-a-given-prefix/description/)

---
{{< youtube 8yMcHvAw2Q8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
