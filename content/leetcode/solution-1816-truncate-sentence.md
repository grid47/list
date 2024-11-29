
+++
authors = ["grid47"]
title = "Leetcode 1816: Truncate Sentence"
date = "2024-05-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1816: Truncate Sentence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "2_B2ZUBRYQQ"
youtube_upload_date="2021-04-04"
youtube_thumbnail="https://i.ytimg.com/vi_webp/2_B2ZUBRYQQ/maxresdefault.webp"
comments = true
+++



---
Given a sentence with words separated by a space, truncate the sentence to contain only the first k words. Return the truncated sentence.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a sentence s and an integer k.
- **Example:** `s = "Sunshine and rainbows are beautiful", k = 3`
- **Constraints:**
	- 1 <= s.length <= 500
	- k is in the range [1, the number of words in s].
	- s consists of only lowercase and uppercase English letters and spaces.
	- The words in s are separated by a single space.
	- There are no leading or trailing spaces in s.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the sentence containing only the first k words.
- **Example:** `Output: "Sunshine and rainbows"`
- **Constraints:**
	- The output should be a string representing the truncated sentence.

{{< dots >}}
### Core Logic 🔍
**Goal:** Truncate the sentence to contain only the first k words.

- Split the sentence into words.
- Select the first k words.
- Join the selected words into a new sentence and return it.
{{< dots >}}
### Problem Assumptions ✅
- The sentence contains at least one word.
- The value of k is always valid and within the range of words in the sentence.
{{< dots >}}
## Examples 🧩
- **Input:** `s = "Sunshine and rainbows are beautiful", k = 3`  \
  **Explanation:** The first 3 words are "Sunshine", "and", "rainbows".

- **Input:** `s = "Learn to code at any time", k = 5`  \
  **Explanation:** The sentence contains exactly 5 words, so the entire sentence is returned.

{{< dots >}}
## Approach 🚀
The problem can be solved by splitting the sentence into words and selecting the first k words.

### Initial Thoughts 💭
- We can split the sentence by spaces to get the individual words.
- Then, we can simply join the first k words together.
- This problem has a simple solution using basic string operations.
{{< dots >}}
### Edge Cases 🌐
- The input string will not be empty.
- The function should handle strings of length up to 500 characters efficiently.
- When k equals the total number of words, the entire sentence is returned.
- The solution must handle various string lengths and word counts within the problem's constraints.
{{< dots >}}
## Code 💻
```cpp
string truncateSentence(string s, int k) {
    int count =0;
    string ans="";
    for(auto x:s)
    {
        if(x==' ')
            count++;
        if(count==k)
            break;
        ans+=x;
    }
    
    return ans;
}
```

The function `truncateSentence` truncates the sentence `s` after the k-th word. It iterates over each character in the string `s` and counts the number of spaces encountered. Once the k-th space is encountered, the loop breaks, returning the sentence up to that point.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string truncateSentence(string s, int k) {
	```
	This defines the function `truncateSentence` which takes a string `s` and an integer `k` as input, and returns the string truncated after the k-th word.

2. **Variable Initialization**
	```cpp
	    int count =0;
	```
	A variable `count` is initialized to 0. It will be used to count the number of spaces encountered in the string `s`.

3. **Variable Initialization**
	```cpp
	    string ans="";
	```
	A string `ans` is initialized as an empty string. It will store the result of the truncated sentence.

4. **Loop Over String**
	```cpp
	    for(auto x:s)
	```
	This loop iterates over each character `x` in the string `s`.

5. **Space Detection**
	```cpp
	        if(x==' ')
	```
	This checks if the current character `x` is a space.

6. **Count Space**
	```cpp
	            count++;
	```
	If the character is a space, `count` is incremented by 1 to track the number of spaces encountered.

7. **Check k-th Word**
	```cpp
	        if(count==k)
	```
	This checks if `count` has reached the value of `k`, indicating that the k-th word has been encountered.

8. **Break Loop**
	```cpp
	            break;
	```
	If the k-th space is encountered, the loop is terminated using `break`, effectively truncating the sentence at the k-th word.

9. **Accumulate Character**
	```cpp
	        ans+=x;
	```
	This appends the current character `x` to the string `ans`, effectively building the truncated sentence.

10. **Return Statement**
	```cpp
	    return ans;
	```
	The function returns the string `ans`, which contains the truncated sentence.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) where n is the length of the string, as we need to split the string into words and then join them.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) as we need to store the split words temporarily before joining them.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/truncate-sentence/description/)

---
{{< youtube 2_B2ZUBRYQQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
