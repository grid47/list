
+++
authors = ["grid47"]
title = "Leetcode 2490: Circular Sentence"
date = "2024-03-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2490: Circular Sentence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "9Ty_eRjoDNM"
youtube_upload_date="2024-11-02"
youtube_thumbnail="https://i.ytimg.com/vi/9Ty_eRjoDNM/maxresdefault.jpg"
comments = true
+++



---
You are given a sentence where words are separated by spaces. A sentence is considered circular if the last character of each word matches the first character of the next word, and the last character of the last word matches the first character of the first word.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a string, where words are separated by spaces and consist of only uppercase and lowercase English letters.
- **Example:** `sentence = 'hello ox oxo awesome endo'`
- **Constraints:**
	- 1 <= sentence.length <= 500
	- sentence consists of lowercase and uppercase English letters and spaces.
	- Words in sentence are separated by a single space.
	- There are no leading or trailing spaces.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return 'true' if the sentence is circular, otherwise return 'false'.
- **Example:** `Output: true`
- **Constraints:**
	- The sentence will always be non-empty.

{{< dots >}}
### Core Logic 🔍
**Goal:** To check if the sentence satisfies the circular condition where the last character of each word matches the first character of the next word.

- 1. Split the sentence into words.
- 2. Compare the last character of each word with the first character of the next word.
- 3. Also compare the last character of the last word with the first character of the first word.
{{< dots >}}
### Problem Assumptions ✅
- Words in the sentence are non-empty.
- Words consist only of uppercase and lowercase English letters.
{{< dots >}}
## Examples 🧩
- **Input:** `sentence = 'hello ox oxo awesome endo'`  \
  **Explanation:** In this example, 'hello' ends with 'o' which matches the first character of 'ox', 'ox' ends with 'x' which matches 'oxo's first character 'x', and so on, forming a circular sentence.

- **Input:** `sentence = 'Leetcode is amazing'`  \
  **Explanation:** In this case, 'Leetcode' ends with 'e' but 'is' starts with 'i', so the sentence is not circular.

- **Input:** `sentence = 'ax aa a'`  \
  **Explanation:** Here, 'ax' ends with 'x' but the next word 'aa' starts with 'a', and the pattern does not satisfy the circular condition.

{{< dots >}}
## Approach 🚀
We check whether each word's last character matches the next word's first character and the first word's first character matches the last word's last character.

### Initial Thoughts 💭
- We need to check each word and compare the last character with the first character of the next word.
- We also need to ensure the first word and the last word match circularly.
- A simple iteration through the words should allow us to compare adjacent words, with special handling for the first and last word.
{{< dots >}}
### Edge Cases 🌐
- The sentence will always be non-empty, so no need to handle empty sentences.
- Ensure the solution works efficiently for sentences close to the maximum length of 500 characters.
- The sentence may consist of just one word, in which case we check if the first and last character of the word match.
- Handle sentences of varying lengths, ensuring they adhere to the space and character constraints.
{{< dots >}}
## Code 💻
```cpp
bool isCircularSentence(string s) {
    
    int n = s.size();
    if((s[0]) != (s[n - 1]))
        return false;
    for(int i = 1; i < s.size() - 1; i++) {
        if(s[i] == ' ') {
            if((s[i - 1]) != (s[i + 1]))
                return false;                
        }
    }
    return true;
}
```

This function checks if a given sentence is circular, where the first and last characters are the same, and words between spaces are matched by their adjacent words.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool isCircularSentence(string s) {
	```
	This line declares the function `isCircularSentence` which takes a string `s` as input and returns a boolean indicating whether the sentence is circular.

2. **Variable Declaration**
	```cpp
	    int n = s.size();
	```
	This line calculates the size of the string `s` and stores it in the variable `n`.

3. **Initial Check**
	```cpp
	    if((s[0]) != (s[n - 1]))
	```
	This conditional checks if the first character of the string `s` is not equal to the last character. If they are not the same, the function returns false.

4. **Early Return**
	```cpp
	        return false;
	```
	If the first and last characters do not match, the sentence is not circular, and the function returns `false`.

5. **Loop Through Sentence**
	```cpp
	    for(int i = 1; i < s.size() - 1; i++) {
	```
	This loop iterates through the string starting from the second character and ends before the last character, checking for spaces and their adjacent characters.

6. **Check for Spaces**
	```cpp
	        if(s[i] == ' ') {
	```
	This line checks if the current character is a space.

7. **Space Validation**
	```cpp
	            if((s[i - 1]) != (s[i + 1]))
	```
	If the current character is a space, this line checks if the character before the space is not equal to the character after the space. If they are not the same, the function returns `false`.

8. **Early Return**
	```cpp
	                return false;                
	```
	If the adjacent characters to the space are not equal, the sentence is not circular, and the function returns `false`.

9. **Return True**
	```cpp
	    return true;
	```
	If the entire string passes the checks, the function returns `true`, indicating the sentence is circular.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) where n is the number of characters in the sentence. We process each character once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage of the words in the sentence, but it could be reduced to O(1) if we modify the sentence in place.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/circular-sentence/description/)

---
{{< youtube 9Ty_eRjoDNM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
