
+++
authors = ["grid47"]
title = "Leetcode 1880: Check if Word Equals Summation of Two Words"
date = "2024-05-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1880: Check if Word Equals Summation of Two Words in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "XdgS7eqwF2M"
youtube_upload_date="2021-05-30"
youtube_thumbnail="https://i.ytimg.com/vi_webp/XdgS7eqwF2M/maxresdefault.webp"
comments = true
+++



---
You are given three strings: 'firstWord', 'secondWord', and 'targetWord'. Each string contains only lowercase English letters from 'a' to 'j'. The value of each letter corresponds to its position in the alphabet starting from 'a' as 0 ('a' -> 0, 'b' -> 1, ..., 'j' -> 9). The value of a string is the concatenation of the values of its letters, which is then interpreted as an integer. Your task is to check if the sum of the values of 'firstWord' and 'secondWord' equals the value of 'targetWord'. Return true if it does, and false otherwise.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given three strings 'firstWord', 'secondWord', and 'targetWord'. Each string consists of lowercase letters from 'a' to 'j'.
- **Example:** `firstWord = 'acb', secondWord = 'cba', targetWord = 'cdb'`
- **Constraints:**
	- 1 <= firstWord.length, secondWord.length, targetWord.length <= 8
	- firstWord, secondWord, and targetWord consist of lowercase English letters from 'a' to 'j' inclusive.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if the sum of the numerical values of 'firstWord' and 'secondWord' equals the numerical value of 'targetWord'. Otherwise, return false.
- **Example:** `true`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Convert each word to its numerical value and check if the sum of the values of 'firstWord' and 'secondWord' equals 'targetWord'.

- For each word, convert each character to its corresponding value and concatenate them to form an integer.
- Check if the sum of the first and second word values equals the target word value.
{{< dots >}}
### Problem Assumptions ✅
- The input strings contain only lowercase English letters from 'a' to 'j'.
- The values of the words are formed by concatenating the positions of the characters in the alphabet.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: firstWord = 'acb', secondWord = 'cba', targetWord = 'cdb'`  \
  **Explanation:** The numerical value of 'acb' is 21, the value of 'cba' is 210, and the value of 'cdb' is 231. The sum of 21 and 210 equals 231, so the result is true.

- **Input:** `Example 2: firstWord = 'aaa', secondWord = 'a', targetWord = 'aab'`  \
  **Explanation:** The numerical value of 'aaa' is 0, the value of 'a' is 0, and the value of 'aab' is 1. The sum of 0 and 0 does not equal 1, so the result is false.

- **Input:** `Example 3: firstWord = 'aaa', secondWord = 'a', targetWord = 'aaaa'`  \
  **Explanation:** The numerical value of 'aaa' is 0, the value of 'a' is 0, and the value of 'aaaa' is 0. The sum of 0 and 0 equals 0, so the result is true.

{{< dots >}}
## Approach 🚀
Convert each word to its numerical value by iterating over each character and using its position in the alphabet to form the corresponding number. Then, compare the sum of the first two words' values with the value of the target word.

### Initial Thoughts 💭
- Each word can be transformed into an integer by processing each letter and using its alphabetical value.
- The solution requires simple arithmetic comparison after converting the words to their numerical values.
- This approach works efficiently given the constraints, as the maximum length of the strings is 8.
{{< dots >}}
### Edge Cases 🌐
- The input will never be empty, as the length is guaranteed to be at least 1.
- Input strings will be of length at most 8, which ensures the operations are fast.
- If all words are 'a', the sum will be 0.
- Handle cases where the sum of two words equals or does not equal the third word.
{{< dots >}}
## Code 💻
```cpp
bool isSumEqual(string firstWord, string secondWord, string targetWord) {
    int first=0,second=0,target=0;
    for(int i=0;i<firstWord.size();i++)
        first=first*10 + (firstWord[i]-'a');
    
    for(int i=0;i<secondWord.size();i++)
        second=second*10 +(secondWord[i]-'a');
    
    for(int i=0;i<targetWord.size();i++)
        target=target*10 +(targetWord[i]-'a');
    
    
    return first+second == target;
}
```

This function converts string representations of numbers (using letters as digits) into integers and checks if the sum of two integers equals the third.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool isSumEqual(string firstWord, string secondWord, string targetWord) {
	```
	Defines a function to check if the sum of two word-based integers equals the third.

2. **Variable Initialization**
	```cpp
	    int first=0,second=0,target=0;
	```
	Initializes integers to store numerical representations of the input strings.

3. **Loop and Conversion**
	```cpp
	    for(int i=0;i<firstWord.size();i++)
	```
	Iterates through the firstWord to convert it into a numeric value.

4. **Conversion**
	```cpp
	        first=first*10 + (firstWord[i]-'a');
	```
	Converts each character of firstWord into a digit and appends it to the numeric value.

5. **Loop and Conversion**
	```cpp
	    for(int i=0;i<secondWord.size();i++)
	```
	Iterates through the secondWord to convert it into a numeric value.

6. **Conversion**
	```cpp
	        second=second*10 +(secondWord[i]-'a');
	```
	Converts each character of secondWord into a digit and appends it to the numeric value.

7. **Loop and Conversion**
	```cpp
	    for(int i=0;i<targetWord.size();i++)
	```
	Iterates through the targetWord to convert it into a numeric value.

8. **Conversion**
	```cpp
	        target=target*10 +(targetWord[i]-'a');
	```
	Converts each character of targetWord into a digit and appends it to the numeric value.

9. **Validation**
	```cpp
	    return first+second == target;
	```
	Checks if the sum of the first and second integers equals the target integer.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the longest string.
- **Average Case:** O(n), where n is the length of the longest string.
- **Worst Case:** O(n), where n is the length of the longest string.

In the worst case, we iterate over each string once, processing each character.

### Space Complexity 💾
- **Best Case:** O(1), as no extra space is needed apart from storing intermediate results.
- **Worst Case:** O(1), as we use a constant amount of extra space.

The space complexity is constant since we only need to store a few integer variables.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-word-equals-summation-of-two-words/description/)

---
{{< youtube XdgS7eqwF2M >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
