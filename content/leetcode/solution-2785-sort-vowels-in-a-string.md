
+++
authors = ["grid47"]
title = "Leetcode 2785: Sort Vowels in a String"
date = "2024-02-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2785: Sort Vowels in a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "ESF0Q-rrol0"
youtube_upload_date="2023-07-22"
youtube_thumbnail="https://i.ytimg.com/vi/ESF0Q-rrol0/maxresdefault.jpg"
comments = true
+++



---
You are given a string s. The task is to permute s such that all consonants remain in their original places, and the vowels are sorted in the nondecreasing order of their ASCII values.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string s containing only English letters (uppercase and lowercase).
- **Example:** `Input: s = 'ReAcTivE'`
- **Constraints:**
	- 1 <= s.length <= 10^5
	- s consists only of letters of the English alphabet in uppercase and lowercase.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the new string where the consonants remain in their original places and the vowels are sorted in non-decreasing ASCII order.
- **Example:** `Output: 'ReACTivE'`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Sort the vowels in the string while leaving consonants in place.

- Extract the vowels from the string and store them in a list.
- Sort the list of vowels based on their ASCII values.
- Reconstruct the string by replacing the vowels in their original positions with the sorted vowels.
{{< dots >}}
### Problem Assumptions ✅
- The input string may contain both uppercase and lowercase vowels.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: 'ReAcTivE'`  \
  **Explanation:** The vowels in 'ReAcTivE' are 'e', 'A', 'i'. After sorting them based on their ASCII values, the new string becomes 'ReACTivE'.

- **Input:** `Input: 'hEllOWoRlD'`  \
  **Explanation:** The vowels 'e', 'O', 'O' are sorted, resulting in 'hElLOOWrLD'.

{{< dots >}}
## Approach 🚀
Extract the vowels, sort them, and reinsert them into the original string in place of the vowels.

### Initial Thoughts 💭
- Only the vowels need to be rearranged. Consonants stay in their places.
- Sorting the vowels based on their ASCII values is straightforward.
- I will extract vowels, sort them, and replace them in the original positions.
{{< dots >}}
### Edge Cases 🌐
- Input: ''. Output: ''
- Input: 'a' repeated 10^5 times. Output: 'a' repeated 10^5 times.
- Input: 'bCdfgh' (no vowels). Output: 'bCdfgh'.
- The solution should handle up to 10^5 characters efficiently.
{{< dots >}}
## Code 💻
```cpp
bool isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'o'|| ch == 'u'|| ch == 'i';
}
string sortVowels(string s) {
    string v;
    copy_if(begin(s), end(s), back_inserter(v), [&](char ch){ 
        return isVowel(tolower(ch)); 
    });
    sort(begin(v), end(v));
    for (int i = 0, j = 0; i < s.size(); ++i)
        if (isVowel(tolower(s[i])))
            s[i] = v[j++];
    return s;
}
```

The code consists of two functions: `isVowel`, which checks if a character is a vowel, and `sortVowels`, which sorts all the vowels in a string in ascending order while maintaining the position of consonants.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool isVowel(char ch) {
	```
	This function `isVowel` takes a character `ch` as input and checks if it is one of the vowels ('a', 'e', 'o', 'u', 'i'). It returns true if the character is a vowel, and false otherwise.

2. **Vowel Check**
	```cpp
	    return ch == 'a' || ch == 'e' || ch == 'o'|| ch == 'u'|| ch == 'i';
	```
	This line compares the input character `ch` against the five vowels ('a', 'e', 'o', 'u', 'i') and returns true if the character matches any of them.

3. **Function Declaration**
	```cpp
	string sortVowels(string s) {
	```
	This function `sortVowels` takes a string `s` as input and returns a new string with the vowels sorted in ascending order, while keeping the consonants in their original positions.

4. **Variable Initialization**
	```cpp
	    string v;
	```
	A string `v` is initialized to hold all the vowels extracted from the input string `s`.

5. **Copying Vowels**
	```cpp
	    copy_if(begin(s), end(s), back_inserter(v), [&](char ch){ 
	```
	The `copy_if` function iterates over the string `s` and copies each character that is a vowel (determined by the `isVowel` function) into the string `v`.

6. **Vowel Check**
	```cpp
	        return isVowel(tolower(ch)); 
	```
	This lambda function checks if the character `ch` (converted to lowercase using `tolower`) is a vowel by calling the `isVowel` function.

7. **Sorting Vowels**
	```cpp
	    sort(begin(v), end(v));
	```
	This line sorts the string `v` in ascending order so that the vowels are arranged alphabetically.

8. **Looping Through String**
	```cpp
	    for (int i = 0, j = 0; i < s.size(); ++i)
	```
	This for loop iterates through each character of the string `s`. The variable `i` is the index for the original string, and `j` is used to track the position in the sorted `v` string.

9. **Vowel Replacement**
	```cpp
	        if (isVowel(tolower(s[i])))
	```
	This condition checks if the current character in the string `s` (converted to lowercase) is a vowel.

10. **Replacing Character**
	```cpp
	            s[i] = v[j++];
	```
	If the character is a vowel, it is replaced by the next vowel in the sorted string `v`, and the index `j` is incremented.

11. **Returning Result**
	```cpp
	    return s;
	```
	After all vowels are replaced with the sorted vowels, the modified string `s` is returned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The most time-consuming operation is sorting the vowels, which takes O(n log n) time.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

We store the vowels and need extra space proportional to the size of the string.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/sort-vowels-in-a-string/description/)

---
{{< youtube ESF0Q-rrol0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
