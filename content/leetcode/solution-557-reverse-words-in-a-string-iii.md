
+++
authors = ["grid47"]
title = "Leetcode 557: Reverse Words in a String III"
date = "2024-09-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 557: Reverse Words in a String III in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/557.webp"
youtube = "_I57bpDMWnY"
youtube_upload_date="2022-06-27"
youtube_thumbnail="https://i.ytimg.com/vi/_I57bpDMWnY/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/557.webp" 
    alt="A string where the words are reversed, with each word glowing softly as it flips in place."
    caption="Solution to LeetCode 557: Reverse Words in a String III Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a string s that contains words separated by a single space. It is guaranteed that there are no leading or trailing spaces.
- **Example:** `Input: s = "Coding is fun"`
- **Constraints:**
	- 1 <= s.length <= 5 * 10^4
	- s contains printable ASCII characters.
	- s does not contain any leading or trailing spaces.
	- There is at least one word in s.
	- All the words in s are separated by a single space.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a string where each word is reversed, but the word order and spaces remain unchanged.
- **Example:** `Output: "gnidoC si nuf"`
- **Constraints:**
	- The returned string should preserve the spacing and order of the words.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to reverse the characters of each word in the input string while keeping the overall word order and spacing intact.

- Traverse through the input string word by word.
- For each word, reverse the characters and store the result.
- Join the reversed words back together with a single space between them.
- Return the resulting string.
{{< dots >}}
### Problem Assumptions ✅
- The input string is valid, containing words separated by a single space.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = "Coding is fun"`  \
  **Explanation:** Each word in the sentence is reversed, giving the output 'gnidoC si nuf', while the word order is preserved.

- **Input:** `Input: s = "Hello World"`  \
  **Explanation:** After reversing each word, the output is 'olleH dlroW'.

{{< dots >}}
## Approach 🚀
The approach involves splitting the string into words, reversing each word, and then reassembling the string while maintaining the order.

### Initial Thoughts 💭
- Reversing each word is a straightforward task that can be done by manipulating the string's characters.
- The challenge lies in maintaining the correct order of the words and spaces between them.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs, as the problem guarantees at least one word in the input string.
- The solution should handle large input strings efficiently.
- If the input contains a single word, that word will be reversed.
- The solution should not exceed time or space limits when processing input of size 5 * 10^4.
{{< dots >}}
## Code 💻
```cpp
string reverseWords(string s) {
    int n = s.size(), prv = 0;
    for(int i = 0; i < n; i++)
        if(s[i] == ' ')
            rev(s, prv, i - 1), prv = i + 1;
        else if(i == n - 1)
            rev(s, prv, i);        
    return s;
}

void rev(string &s, int i, int j) {
    while(i <= j)
        swap(s[i++], s[j--]);
}
```

This function reverses each word in a given string. It processes the string character by character, identifying words by spaces and reversing each word in-place using the helper function `rev`. The `rev` function swaps characters within a given range to reverse the word.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string reverseWords(string s) {
	```
	Defines the function `reverseWords`, which takes a string `s` and returns the string with each word reversed in place.

2. **Variable Initialization**
	```cpp
	    int n = s.size(), prv = 0;
	```
	Initializes the size of the string `n` and a variable `prv` to keep track of the starting index of the current word.

3. **Loop Through String**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	Starts a loop to iterate through each character of the string `s`.

4. **Word Boundary Detection**
	```cpp
	        if(s[i] == ' ')
	```
	Checks if the current character is a space, indicating the end of a word.

5. **Reverse Word**
	```cpp
	            rev(s, prv, i - 1), prv = i + 1;
	```
	Calls the `rev` function to reverse the word from index `prv` to `i-1`, and updates `prv` to point to the start of the next word.

6. **Final Word Handling**
	```cpp
	        else if(i == n - 1)
	```
	Checks if the current character is the last character in the string, indicating the end of the final word.

7. **Reverse Last Word**
	```cpp
	            rev(s, prv, i);        
	```
	Reverses the final word in the string, as there is no space after it.

8. **Return Result**
	```cpp
	    return s;
	```
	Returns the modified string with all words reversed.

9. **Helper Function Definition**
	```cpp
	void rev(string &s, int i, int j) {
	```
	Defines the helper function `rev`, which takes a string `s` and two indices `i` and `j`, and reverses the substring from index `i` to `j`.

10. **In-place Reversal**
	```cpp
	    while(i <= j)
	```
	Starts a while loop to reverse the characters of the substring as long as `i` is less than or equal to `j`.

11. **Swap Characters**
	```cpp
	        swap(s[i++], s[j--]);
	```
	Swaps the characters at indices `i` and `j`, then increments `i` and decrements `j` to continue swapping until the entire substring is reversed.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear in the size of the input string, as we process each character once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n), where n is the length of the input string, due to the storage of the words and the reversed string.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/reverse-words-in-a-string-iii/description/)

---
{{< youtube _I57bpDMWnY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
