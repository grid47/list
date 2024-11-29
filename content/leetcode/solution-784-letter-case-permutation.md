
+++
authors = ["grid47"]
title = "Leetcode 784: Letter Case Permutation"
date = "2024-08-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 784: Letter Case Permutation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Backtracking","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/784.webp"
youtube = "qcWClV0FRTs"
youtube_upload_date="2020-05-17"
youtube_thumbnail="https://i.ytimg.com/vi/qcWClV0FRTs/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/784.webp" 
    alt="A string where letter case permutations are made, with each new permutation softly glowing as it’s generated."
    caption="Solution to LeetCode 784: Letter Case Permutation Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a string s, you can transform every letter individually to either lowercase or uppercase. Digits remain unchanged. Your task is to generate a list of all possible strings that can be created by changing the case of the letters in the string.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string s that contains lowercase English letters, uppercase English letters, and digits.
- **Example:** `Input: s = 'xYz1'`
- **Constraints:**
	- 1 <= s.length <= 12
	- s consists of lowercase English letters, uppercase English letters, and digits.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a list of all possible strings that can be created by changing the case of the letters in the input string.
- **Example:** `Output: ['xYz1', 'xYz1', 'XyZ1', 'XyZ1', 'xYZ1', 'xYZ1', 'XYz1', 'XYz1']`
- **Constraints:**
	- The output list contains all the possible case variations of the letters in the input string.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to generate all possible case combinations for each letter in the input string.

- Iterate over the string s and for each character, generate both the lowercase and uppercase versions if it is a letter.
- For digits, keep them unchanged.
- Use backtracking or recursive techniques to explore all possible combinations.
{{< dots >}}
### Problem Assumptions ✅
- The input string will not be empty and will contain at least one character.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: Input: s = 'xYz1'`  \
  **Explanation:** The string contains both uppercase and lowercase letters. We can change each letter to either uppercase or lowercase, generating all the possible combinations of these case changes.

- **Input:** `Example 2: Input: s = '9aB'`  \
  **Explanation:** In this case, digits remain unchanged, while the letters 'a' and 'B' can be transformed to 'A' and 'b' or 'a' and 'B', respectively. Therefore, we generate all combinations of the letter cases.

{{< dots >}}
## Approach 🚀
To solve this problem, we will explore each character of the input string, and for each character, we will consider both the lowercase and uppercase options if it is a letter. If it's a digit, we will leave it unchanged. We will generate all combinations recursively.

### Initial Thoughts 💭
- The problem is based on string manipulation and involves case transformations.
- Each letter in the string can be in one of two cases, so there are 2^n combinations for a string of length n.
- We can use a backtracking approach to recursively generate all combinations by considering each character's case options.
{{< dots >}}
### Edge Cases 🌐
- The string will always contain at least one character.
- If the string length is large (up to 12 characters), we will handle it by limiting the maximum number of recursive calls.
- If the string contains only digits, the result is simply the original string, as no case transformation is needed.
- The input string's length is constrained to a maximum of 12 characters.
{{< dots >}}
## Code 💻
```cpp
vector<string> letterCasePermutation(string s) {
    vector<string> ans;
    bt(ans, s, 0);
    return ans;
}

void bt(vector<string> &ans, string &s, int i) {
    if(i== s.size()) {
        ans.push_back(s);
        return;
    }
    
    bt(ans, s, i + 1);
    if(isalpha(s[i])) {
        s[i] ^= 1 << 5;
        bt(ans, s, i+1);
    }
    
}
```

This function generates all possible letter case permutations of a given string `s` using backtracking. It recursively explores both lowercase and uppercase options for each alphabetic character.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<string> letterCasePermutation(string s) {
	```
	Defines the function `letterCasePermutation`, which takes a string `s` and returns a vector of all possible case permutations of the string.

2. **Initialization**
	```cpp
	    vector<string> ans;
	```
	Initializes a vector `ans` to store the resulting letter case permutations.

3. **Backtracking Call**
	```cpp
	    bt(ans, s, 0);
	```
	Calls the helper function `bt` to start the backtracking process from the first character of the string.

4. **Return Result**
	```cpp
	    return ans;
	```
	Returns the vector `ans` containing all the letter case permutations of the string `s`.

5. **Helper Function Definition**
	```cpp
	void bt(vector<string> &ans, string &s, int i) {
	```
	Defines the helper function `bt` (backtracking), which recursively generates letter case permutations by modifying the string `s`.

6. **Base Case**
	```cpp
	    if(i== s.size()) {
	```
	Checks if the current index `i` has reached the end of the string `s`.

7. **Add Permutation**
	```cpp
	        ans.push_back(s);
	```
	Adds the current permutation of the string `s` to the result vector `ans`.

8. **End Base Case**
	```cpp
	        return;
	```
	Returns from the recursive call, ending the current branch of backtracking.

9. **Recursive Call**
	```cpp
	    bt(ans, s, i + 1);
	```
	Recursively calls the `bt` function with the next index `i + 1`, exploring the next character in the string.

10. **Toggle Case Check**
	```cpp
	    if(isalpha(s[i])) {
	```
	Checks if the current character `s[i]` is an alphabetic letter.

11. **Toggle Case**
	```cpp
	        s[i] ^= 1 << 5;
	```
	Toggles the case of the character `s[i]` using bitwise XOR. This flips between lowercase and uppercase.

12. **Recursive Call After Toggle**
	```cpp
	        bt(ans, s, i+1);
	```
	Recursively calls the `bt` function again with the case-toggled character at position `i`, exploring both case options.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(2^n), where n is the length of the input string, because each letter can either be in lowercase or uppercase, generating 2^n combinations.
- **Average Case:** O(2^n), as we need to process each possible combination of letter cases.
- **Worst Case:** O(2^n), as the worst case also involves generating all possible combinations of letter case transformations.

The time complexity is exponential in the size of the string due to the 2^n combinations for n letters.

### Space Complexity 💾
- **Best Case:** O(1), if the string has no letters and only digits.
- **Worst Case:** O(2^n), where n is the length of the input string, since we need to store all possible combinations.

The space complexity is exponential due to the storage required for all possible combinations.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/letter-case-permutation/description/)

---
{{< youtube qcWClV0FRTs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
