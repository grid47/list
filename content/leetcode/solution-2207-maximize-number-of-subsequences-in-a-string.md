
+++
authors = ["grid47"]
title = "Leetcode 2207: Maximize Number of Subsequences in a String"
date = "2024-03-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2207: Maximize Number of Subsequences in a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Greedy","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "uTt6XMDPPIg"
youtube_upload_date="2022-03-19"
youtube_thumbnail="https://i.ytimg.com/vi_webp/uTt6XMDPPIg/maxresdefault.webp"
comments = true
+++



---
You are given a string text and another string pattern of length 2, consisting of lowercase English letters. Your task is to insert one of the characters from pattern into text exactly once, and then return the maximum number of times pattern appears as a subsequence in the modified text.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string text and a string pattern of length 2.
- **Example:** `text = 'abdcdbc', pattern = 'ac'`
- **Constraints:**
	- 1 <= text.length <= 10^5
	- pattern.length == 2
	- text and pattern consist only of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum number of times pattern can appear as a subsequence of the modified text after adding one of the characters from pattern to text.
- **Example:** `For input text = 'abdcdbc', pattern = 'ac', the output is 4.`
- **Constraints:**
	- The output should be an integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** Maximize the number of subsequences of the pattern in the modified text after one character is inserted.

- Initialize counters to track subsequences of pattern[0] and pattern[1].
- Iterate over the text and count occurrences of pattern[0] and pattern[1].
- Add the maximum possible count of subsequences after inserting either pattern[0] or pattern[1].
- Return the final result.
{{< dots >}}
### Problem Assumptions ✅
- The length of text is at least 1.
- The length of pattern is fixed at 2 characters.
{{< dots >}}
## Examples 🧩
- **Input:** `text = 'abdcdbc', pattern = 'ac'`  \
  **Explanation:** By inserting 'a' in the correct position, we can form up to 4 subsequences of 'ac'.

- **Input:** `text = 'aabb', pattern = 'ab'`  \
  **Explanation:** Adding 'a' to the string 'aabb' results in 6 subsequences of 'ab'.

{{< dots >}}
## Approach 🚀
To solve this problem, we can iterate through the string and keep track of how many subsequences of the pattern appear. We then calculate the effect of adding either character from pattern and maximize the count of subsequences.

### Initial Thoughts 💭
- The insertion of a character can be done at any position, and the goal is to find the optimal position.
- By counting the occurrences of pattern[0] and pattern[1] in the original string, we can determine the best place to insert one of these characters.
{{< dots >}}
### Edge Cases 🌐
- The input string text cannot be empty.
- For very large text lengths, efficient iteration and counting are needed.
- If the text already contains multiple subsequences of pattern, inserting the other character might not increase the count.
- The solution should handle text strings with lengths up to 10^5.
{{< dots >}}
## Code 💻
```cpp
long long maximumSubsequenceCount(string text, string pattern) {
    
    long long cnt1 = 0, cnt2 = 0, res = 0, n = text.length();
    
    for(int i = 0; i < n; i++) {
        if(text[i] == pattern[1]) {
            cnt2++;
            res += cnt1;
        }
        if(text[i] == pattern[0]) cnt1++;
    }

    res += max(cnt1, cnt2);
    
    return res;
}
```

This function calculates the total count of subsequences in the input string `text` that match the pattern `pattern`. It iterates through the text and keeps track of the counts of occurrences of each character in the pattern.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	long long maximumSubsequenceCount(string text, string pattern) {
	```
	Define the function that calculates the number of subsequences of a given pattern in a string.

2. **Variable Declaration**
	```cpp
	    long long cnt1 = 0, cnt2 = 0, res = 0, n = text.length();
	```
	Declare and initialize variables: cnt1 and cnt2 for counting occurrences of characters in the pattern, res for storing the result, and n for the length of the input text.

3. **For Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Start the loop to iterate through each character in the text.

4. **Condition Check 1**
	```cpp
	        if(text[i] == pattern[1]) {
	```
	Check if the current character in the text matches the second character of the pattern.

5. **Increment Counter 2**
	```cpp
	            cnt2++;
	```
	Increment the counter for the second character of the pattern.

6. **Update Result**
	```cpp
	            res += cnt1;
	```
	Add the count of the first character occurrences to the result.

7. **Condition Check 2**
	```cpp
	        if(text[i] == pattern[0]) cnt1++;
	```
	Check if the current character in the text matches the first character of the pattern and increment the counter.

8. **Final Calculation**
	```cpp
	    res += max(cnt1, cnt2);
	```
	Add the maximum count of the first or second character to the result to account for any remaining subsequences.

9. **Return Statement**
	```cpp
	    return res;
	```
	Return the computed result of the maximum subsequence count.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear in the length of the input text.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant since only a few variables are used for counting.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/description/)

---
{{< youtube uTt6XMDPPIg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
