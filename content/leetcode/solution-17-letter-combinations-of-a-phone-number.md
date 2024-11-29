
+++
authors = ["grid47"]
title = "Leetcode 17: Letter Combinations of a Phone Number"
date = "2024-11-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 17: Letter Combinations of a Phone Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/17.webp"
youtube = "F7EoBxhPmBk"
youtube_upload_date="2024-05-01"
youtube_thumbnail="https://i.ytimg.com/vi/F7EoBxhPmBk/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/17.webp" 
    alt="A swirling constellation of letters, with gentle connections forming phone number combinations."
    caption="Solution to LeetCode 17: Letter Combinations of a Phone Number Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a string of digits, return all possible letter combinations that the digits could represent based on the phone's number-to-letter mapping.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `digits` containing digits between 2 and 9.
- **Example:** `digits = "45"`
- **Constraints:**
	- 0 <= digits.length <= 4
	- digits[i] is a digit from the range ['2', '9']

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a list of strings where each string represents a letter combination corresponding to the given digits.
- **Example:** `Output: ["gj", "gk", "gl", "hj", "hk", "hl", "ij", "ik", "il"]`
- **Constraints:**
	- The output is a list of letter combinations.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find all possible letter combinations corresponding to the given digits.

- Use a map to associate each digit with its corresponding letters.
- Iterate over the digits and for each digit, expand the existing combinations by appending each letter mapped to that digit.
{{< dots >}}
### Problem Assumptions ✅
- Each digit corresponds to a set of characters as per the old mobile keypad mappings.
- The input string could be empty, in which case the output should be an empty list.
{{< dots >}}
## Examples 🧩
- **Input:** `digits = "45"`  \
  **Explanation:** The digit 4 maps to 'g', 'h', 'i' and the digit 5 maps to 'j', 'k', 'l'. The output combinations are formed by combining each letter from the first digit with each letter from the second digit.

{{< dots >}}
## Approach 🚀
The approach uses a map to represent the letter mappings for each digit, and iteratively constructs combinations using a loop or recursive function.

### Initial Thoughts 💭
- The problem is about generating combinations, which can be done using a backtracking approach or an iterative approach.
- We can initialize the result with the letters corresponding to the first digit and progressively build the combinations for each subsequent digit.
{{< dots >}}
### Edge Cases 🌐
- An empty string should return an empty list.
- Input strings of length 4 are the largest possible, and the solution should handle that case efficiently.
- Digits corresponding to the same set of letters (e.g., '2' or '3') should be handled as usual.
- The input length is constrained to 0 to 4 digits, ensuring the problem can be solved efficiently.
{{< dots >}}
## Code 💻
```cpp
vector<string> letterCombinations(string digits) {
    map<char, vector<string>> mp;
    mp['2'] = { "a", "b", "c" };
    mp['3'] = { "d", "e", "f" };
    mp['4'] = { "g", "h", "i" };
    mp['5'] = { "j", "k", "l" };
    mp['6'] = { "m", "n", "o" };
    mp['7'] = { "p", "q", "r", "s" };
    mp['8'] = { "t", "u", "v" };
    mp['9'] = { "w", "x", "y", "z" };
    
    vector<string> ans, tmp;
    ans = mp[digits[0]];
    for(int i = 1; i < digits.size(); i++) {
        tmp = ans;
        ans = {};
        for(int j = 0; j < mp[digits[i]].size(); j++) {
            for(int k = 0; k < tmp.size(); k++)
                ans.push_back(tmp[k] + mp[digits[i]][j]);
        }
    }

    return ans;
}
```

This code implements the `letterCombinations` function, which generates all possible letter combinations that the number sequence can represent.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<string> letterCombinations(string digits) {
	```
	Declare the `letterCombinations` function, which takes a string of digits `digits` as input and returns a vector of strings representing all possible letter combinations.

2. **Map Initialization**
	```cpp
	    map<char, vector<string>> mp;
	```
	Initialize a map `mp` to store the mapping of digits to their corresponding letters.

3. **Map Initialization**
	```cpp
	    mp['2'] = { "a", "b", "c" };
	```
	Map the digit '2' to the letters 'a', 'b', and 'c'.

4. **Map Initialization**
	```cpp
	    mp['3'] = { "d", "e", "f" };
	```
	Map the digit '3' to the letters 'd', 'e', and 'f'.

5. **Map Initialization**
	```cpp
	    mp['4'] = { "g", "h", "i" };
	```
	Map the digit '4' to the letters 'g', 'h', and 'i'.

6. **Map Initialization**
	```cpp
	    mp['5'] = { "j", "k", "l" };
	```
	Map the digit '5' to the letters 'j', 'k', and 'l'.

7. **Map Initialization**
	```cpp
	    mp['6'] = { "m", "n", "o" };
	```
	Map the digit '6' to the letters 'm', 'n', and 'o'.

8. **Map Initialization**
	```cpp
	    mp['7'] = { "p", "q", "r", "s" };
	```
	Map the digit '7' to the letters 'p', 'q', 'r', and 's'.

9. **Map Initialization**
	```cpp
	    mp['8'] = { "t", "u", "v" };
	```
	Map the digit '8' to the letters 't', 'u', and 'v'.

10. **Map Initialization**
	```cpp
	    mp['9'] = { "w", "x", "y", "z" };
	```
	Map the digit '9' to the letters 'w', 'x', 'y', and 'z'.

11. **Variable Initialization**
	```cpp
	    vector<string> ans, tmp;
	```
	Initialize two empty vectors `ans` and `tmp` to store the letter combinations.

12. **Array Access**
	```cpp
	    ans = mp[digits[0]];
	```
	Initialize `ans` with the letter combinations for the first digit.

13. **Loop Iteration**
	```cpp
	    for(int i = 1; i < digits.size(); i++) {
	```
	Start a loop to iterate through the digits from the second digit to the last digit.

14. **Variable Assignment**
	```cpp
	        tmp = ans;
	```
	Copy the current letter combinations in `ans` to `tmp`.

15. **Variable Initialization**
	```cpp
	        ans = {};
	```
	Clear the `ans` vector to store the new combinations.

16. **Nested Loops**
	```cpp
	        for(int j = 0; j < mp[digits[i]].size(); j++) {
	```
	Iterate through the letters corresponding to the current digit.

17. **Nested Loops**
	```cpp
	            for(int k = 0; k < tmp.size(); k++)
	```
	Iterate through the existing letter combinations in `tmp`.

18. **String Manipulation**
	```cpp
	                ans.push_back(tmp[k] + mp[digits[i]][j]);
	```
	Append the current letter from `mp[digits[i]]` to each combination in `tmp` and add the new combination to `ans`.

19. **Return Value**
	```cpp
	    return ans;
	```
	Return the final vector `ans` containing all possible letter combinations.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(3^n)
- **Worst Case:** O(4^n)

In the worst case, for 4 digits, we need to compute up to 4^4 combinations.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(4^n)

The space complexity is determined by the number of combinations generated.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/)

---
{{< youtube F7EoBxhPmBk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
