
+++
authors = ["grid47"]
title = "Leetcode 1668: Maximum Repeating Substring"
date = "2024-05-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1668: Maximum Repeating Substring in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","String Matching"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "glQm_MZJywk"
youtube_upload_date="2020-11-28"
youtube_thumbnail="https://i.ytimg.com/vi_webp/glQm_MZJywk/maxresdefault.webp"
comments = true
+++



---
You are given two strings: `sequence` and `word`. A string `word` is considered 'k-repeating' in `sequence` if `word` concatenated `k` times forms a substring of `sequence`. The task is to return the maximum value of `k` such that `word` repeated `k` times appears as a substring in `sequence`. If no such substring exists, return 0.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two strings, `sequence` and `word`.
- **Example:** `sequence = 'xyzxyzxyz', word = 'xyz'`
- **Constraints:**
	- 1 <= sequence.length <= 100
	- 1 <= word.length <= 100
	- Both `sequence` and `word` contain only lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum value of `k` such that `word` repeated `k` times forms a substring of `sequence`.
- **Example:** `3`
- **Constraints:**
	- If `word` is not a substring of `sequence`, return 0.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the highest value of `k` where `word` repeated `k` times is a substring of `sequence`.

- Start with the word and initialize the count of repetitions as 0.
- Keep concatenating `word` and check if the concatenated string exists in `sequence`.
- Stop when the concatenated string is no longer a substring, and return the count of repetitions.
{{< dots >}}
### Problem Assumptions ✅
- Both `sequence` and `word` are non-empty strings.
{{< dots >}}
## Examples 🧩
- **Input:** `sequence = 'xyzxyzxyz', word = 'xyz'`  \
  **Explanation:** The word 'xyz' can be repeated 3 times to form the substring 'xyzxyzxyz' in 'xyzxyzxyz'.

- **Input:** `sequence = 'abcdefg', word = 'xyz'`  \
  **Explanation:** Since 'xyz' does not exist in 'abcdefg', the maximum k-repeating value is 0.

{{< dots >}}
## Approach 🚀
To solve this problem, we will simulate the process of concatenating `word` multiple times and check if the resulting string is a substring of `sequence`.

### Initial Thoughts 💭
- We need to check for increasing repetitions of `word` in the `sequence`.
- Start by checking if the word itself exists in the sequence. Then, iteratively check for more repetitions of the word.
{{< dots >}}
### Edge Cases 🌐
- Both `sequence` and `word` will have at least one character, so empty inputs are not a concern.
- Ensure that the solution works efficiently for the maximum input sizes, up to 100 characters.
- If `word` does not appear in `sequence`, the result should be 0.
- The solution must handle cases where `word` appears multiple times or not at all.
{{< dots >}}
## Code 💻
```cpp
int maxRepeating(string sequence, string word) {
    int count=0;
    string temp=word;
    while(sequence.find(temp)!=string::npos)
    {
        count++;
        temp+=word;
    }
    return count;
}
```

This function determines the maximum number of times the string `word` can be concatenated and found as a substring within the string `sequence`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maxRepeating(string sequence, string word) {
	```
	Defines the function `maxRepeating` which takes a string `sequence` and a string `word`, and returns the maximum number of times `word` can repeat in `sequence`.

2. **Variable Initialization**
	```cpp
	    int count=0;
	```
	Initializes the variable `count` to keep track of the number of times `word` repeats in `sequence`.

3. **Variable Initialization**
	```cpp
	    string temp=word;
	```
	Initializes `temp` with the value of `word`. This string will be used to check for repeated concatenations of `word` in `sequence`.

4. **While Loop**
	```cpp
	    while(sequence.find(temp)!=string::npos)
	```
	Begins a loop that continues as long as `temp` is found as a substring in `sequence`.

5. **Counter Increment**
	```cpp
	        count++;
	```
	Increments the `count` variable each time `temp` is found in `sequence`.

6. **String Concatenation**
	```cpp
	        temp+=word;
	```
	Concatenates `word` to `temp` to check for the next repeated occurrence in `sequence`.

7. **Return Result**
	```cpp
	    return count;
	```
	Returns the total count of repeated occurrences of `word` in `sequence`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n * m)
- **Worst Case:** O(n * m)

The time complexity depends on how many times the word can be concatenated and checked as a substring, where `n` is the length of the sequence and `m` is the length of the word.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is mainly determined by the storage required to hold the concatenated word and the sequence.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-repeating-substring/description/)

---
{{< youtube glQm_MZJywk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
