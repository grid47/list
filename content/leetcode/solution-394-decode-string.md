
+++
authors = ["grid47"]
title = "Leetcode 394: Decode String"
date = "2024-09-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 394: Decode String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Recursion"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/394.webp"
youtube = "kNW1SlfDuJY"
youtube_upload_date="2019-10-17"
youtube_thumbnail="https://i.ytimg.com/vi/kNW1SlfDuJY/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/394.webp" 
    alt="A string decoding into a sequence, with each decoded character softly illuminated."
    caption="Solution to LeetCode 394: Decode String Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a string that is encoded using the pattern k[encoded_string], where the substring inside the square brackets is repeated exactly k times. Your task is to decode the string by expanding it according to the given encoding rule.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a string encoded using the pattern k[encoded_string], where the encoded_string inside the square brackets is repeated exactly k times.
- **Example:** `Input: 2[ab]3[c]`
- **Constraints:**
	- 1 <= s.length <= 30
	- s consists of lowercase English letters, digits, and square brackets '[]'.
	- All integers in s are in the range [1, 300].

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a string representing the decoded version of the input encoded string.
- **Example:** `Output: ababc`
- **Constraints:**
	- The decoded string must follow the encoding rule exactly.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to decode the given string by expanding the encoded substrings based on the provided encoding pattern.

- Iterate over the input string character by character.
- When encountering a digit, parse the full number to determine how many times to repeat the enclosed substring.
- Recursively process the substring inside the brackets, and concatenate it according to the repetition count.
- Repeat the process until the entire string has been decoded.
{{< dots >}}
### Problem Assumptions ✅
- The input string is always valid and well-formed.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: 2[ab]3[c]`  \
  **Explanation:** The pattern '2[ab]' means 'ab' is repeated 2 times to form 'abab', and '3[c]' means 'c' is repeated 3 times to form 'ccc'. Combining these gives the final output 'ababccc'.

- **Input:** `Input: 2[a2[b]]`  \
  **Explanation:** First, decode 'a2[b]' where 'b' is repeated 2 times to form 'bb', so 'a2[b]' becomes 'abb'. Repeating this 2 times gives 'abbabb'.

{{< dots >}}
## Approach 🚀
The approach involves iterating over the string, decoding the substrings inside brackets, and repeating them according to the specified number of repetitions.

### Initial Thoughts 💭
- The problem involves parsing numbers and substrings, so a stack-based or recursive approach would be effective.
- A recursive approach can work well, where we decode each substring and repeat it according to the number.
{{< dots >}}
### Edge Cases 🌐
- The input string is guaranteed to have a length of at least 1, so no need to handle empty inputs.
- The solution must efficiently handle strings up to 30 characters long.
- Ensure correct handling of nested brackets and repeated substrings.
- The solution must be designed to handle all edge cases, including nested brackets and large numbers for repetitions.
{{< dots >}}
## Code 💻
```cpp
string decodeString(string s) {
    int i = 0;
    return decode(s, i);
}

string decode(string &s, int &i) {
    
    
    string res = "";
    
    while(i < s.size() && s[i] != ']') {
        if(!isdigit(s[i]))
            res += s[i++];
        else {
            int n = 0;
            
            while(i < s.size() && isdigit(s[i]))
                n = n * 10 + (s[i++] - '0');
            
            i++;
            string t = decode(s, i);
            i++;
            
            while(n--> 0) res += t;
        }
    }
    
    return res;
}

```

This code defines two functions to decode a string that follows a pattern where a substring is repeated a certain number of times. The main function is `decodeString` which calls a helper function `decode` to recursively process the string and decode it.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string decodeString(string s) {
	```
	Define the main function `decodeString` that takes a string `s` and returns the decoded string.

2. **Variable Initialization**
	```cpp
	    int i = 0;
	```
	Initialize an integer variable `i` to track the current position in the string `s` during decoding.

3. **Recursive Call**
	```cpp
	    return decode(s, i);
	```
	Call the helper function `decode`, passing the string `s` and the current position `i` as arguments, and return the result.

4. **Function Definition**
	```cpp
	string decode(string &s, int &i) {
	```
	Define the helper function `decode`, which is responsible for decoding the string recursively.

5. **Variable Initialization**
	```cpp
	    string res = "";
	```
	Initialize an empty string `res` to accumulate the decoded characters.

6. **While Loop**
	```cpp
	    while(i < s.size() && s[i] != ']') {
	```
	Start a `while` loop that processes the string until a closing bracket `]` is encountered.

7. **Character Handling**
	```cpp
	        if(!isdigit(s[i]))
	```
	Check if the current character is not a digit (i.e., a literal character that should be added to the result).

8. **Character Addition**
	```cpp
	            res += s[i++];
	```
	Add the current character to the result string `res` and increment the position `i`.

9. **Else Block for Number Processing**
	```cpp
	        else {
	```
	If the current character is a digit, it indicates the start of a repeat count, so enter the processing block for numbers.

10. **Variable Initialization**
	```cpp
	            int n = 0;
	```
	Initialize an integer `n` to store the repeat count extracted from the digits in the string.

11. **While Loop for Number Extraction**
	```cpp
	            while(i < s.size() && isdigit(s[i]))
	```
	Start a loop to process digits and construct the repeat count `n`.

12. **Number Calculation**
	```cpp
	                n = n * 10 + (s[i++] - '0');
	```
	Update the repeat count `n` by processing each digit one by one and adjusting the current value of `n`.

13. **Skip Bracket**
	```cpp
	            i++;
	```
	Increment `i` to skip the opening bracket `[` after extracting the repeat count.

14. **Recursive Call for Substring**
	```cpp
	            string t = decode(s, i);
	```
	Recursively call `decode` to process the substring enclosed in the brackets and get the decoded substring `t`.

15. **Skip Closing Bracket**
	```cpp
	            i++;
	```
	Increment `i` to skip the closing bracket `]` after processing the substring.

16. **Repeat and Append**
	```cpp
	            while(n--> 0) res += t;
	```
	Repeat the decoded substring `t`, `n` times and append it to the result string `res`.

17. **Return Statement**
	```cpp
	    return res;
	```
	Return the fully decoded string `res` after all characters and substrings have been processed.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) as each character is processed once during the decoding.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) in the worst case due to recursion and string concatenation.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/decode-string/description/)

---
{{< youtube kNW1SlfDuJY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
