
+++
authors = ["grid47"]
title = "Leetcode 1807: Evaluate the Bracket Pairs of a String"
date = "2024-05-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1807: Evaluate the Bracket Pairs of a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "HiEzscFAxc4"
youtube_upload_date="2021-03-28"
youtube_thumbnail="https://i.ytimg.com/vi_webp/HiEzscFAxc4/maxresdefault.webp"
comments = true
+++



---
You are given a string `s` containing several bracket pairs with non-empty keys. You are also provided a 2D array `knowledge` where each element is a key-value pair. Your task is to evaluate the string by replacing the keys inside the bracket pairs with their corresponding values. If a key is unknown, replace it with a question mark `?`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `s` and a 2D array `knowledge` containing key-value pairs.
- **Example:** `s = "(user)likes(cats)", knowledge = [["user","Alice"], ["cats","dogs"]]`
- **Constraints:**
	- 1 <= s.length <= 10^5
	- 0 <= knowledge.length <= 10^5
	- knowledge[i].length == 2
	- 1 <= keyi.length, valuei.length <= 10
	- The string `s` contains lowercase English letters and round brackets `(` and `)`.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the resulting string after evaluating all the bracket pairs in `s`.
- **Example:** `Output: "Alicelikesdogs"`
- **Constraints:**
	- The output should be a string where each key in a bracket pair is replaced by its corresponding value or `?` if unknown.

{{< dots >}}
### Core Logic 🔍
**Goal:** To evaluate all bracket pairs in the string and replace keys with their corresponding values or `?` if unknown.

- Initialize a map to store the key-value pairs from `knowledge`.
- Iterate over the string `s` and whenever a bracket pair is encountered, extract the key.
- Check if the key is in the map, and replace it with its corresponding value or `?` if not found.
- Continue processing the string and append the modified parts to the result string.
{{< dots >}}
### Problem Assumptions ✅
- The input string `s` will always contain valid bracket pairs.
- All keys in `knowledge` are unique.
{{< dots >}}
## Examples 🧩
- **Input:** `s = "(user)likes(cats)", knowledge = [["user","Alice"], ["cats","dogs"]]`  \
  **Explanation:** The key "user" has a value of "Alice" and "cats" has a value of "dogs", so the final output is "Alicelikesdogs".

- **Input:** `s = "hello(name)", knowledge = [["name","Bob"]]`  \
  **Explanation:** The key "name" has a value of "Bob", so replace the bracket pair with the value and the result is "hellobob".

{{< dots >}}
## Approach 🚀
We can iterate over the string `s` and for each bracket pair, we check if the key exists in the `knowledge` map. If it does, replace it with the value; otherwise, replace it with a question mark.

### Initial Thoughts 💭
- The string `s` can be large, so we need an efficient solution to process the input in linear time.
- Using a map to store the key-value pairs from `knowledge` ensures that lookups for the keys are efficient (O(1) time complexity).
{{< dots >}}
### Edge Cases 🌐
- If `knowledge` is empty, all bracket pairs will be replaced by '?' in the output.
- For large values of `s` and `knowledge`, the solution must handle the input efficiently within the time and space limits.
- Consider edge cases like when the string `s` has no brackets or when all keys are unknown.
- Ensure the solution processes the string and map efficiently in O(n) time.
{{< dots >}}
## Code 💻
```cpp
string evaluate(string s, vector<vector<string>>& knowledge) {
    map<string, string> mp;
    for(auto e: knowledge)
    mp[e[0]] = e[1];
    string res = "";
    int i = 0;
    while(i < s.size()) {
        if(s[i] == '(') {
            i++;
            string key = "";
            while(s[i] != ')') {
                key += s[i];
                i++;
            }

            if(mp.count(key)) {
                res += mp[key];
                // mp.erase(key);
            }
            else res += '?';
            i++;
        } else res += s[i++];
    }
    return res;
}
```

This code defines a function `evaluate` that takes a string `s` and a `knowledge` vector (containing pairs of strings). It replaces placeholders (within parentheses) in `s` with the corresponding values from the knowledge vector. If a key is not found, it appends a `?`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string evaluate(string s, vector<vector<string>>& knowledge) {
	```
	This line defines the `evaluate` function which takes a string `s` and a reference to a vector of vector of strings `knowledge`.

2. **Map Initialization**
	```cpp
	    map<string, string> mp;
	```
	Here, a map `mp` is declared, where each key-value pair will represent a mapping between a key (string) and its corresponding value (string) from the `knowledge` vector.

3. **Map Population**
	```cpp
	    for(auto e: knowledge)
	```
	This loop iterates through each element `e` in the `knowledge` vector.

4. **Map Assignment**
	```cpp
	    mp[e[0]] = e[1];
	```
	Each element `e` in `knowledge` is a pair where `e[0]` is the key and `e[1]` is the value. This line adds them to the map `mp`.

5. **Result Initialization**
	```cpp
	    string res = "";
	```
	A string `res` is initialized as an empty string to store the result of the evaluation.

6. **Index Initialization**
	```cpp
	    int i = 0;
	```
	An integer variable `i` is initialized to 0, which will be used to iterate through the string `s`.

7. **While Loop**
	```cpp
	    while(i < s.size()) {
	```
	This while loop continues until `i` reaches the size of string `s`.

8. **Parenthesis Check**
	```cpp
	        if(s[i] == '(') {
	```
	If the character at position `i` in the string `s` is an opening parenthesis, we enter this block of code to handle the placeholder.

9. **Increment i**
	```cpp
	            i++;
	```
	Move to the next character in the string after the opening parenthesis.

10. **Key Initialization**
	```cpp
	            string key = "";
	```
	A string `key` is initialized to an empty string. It will be used to store the key found inside the parentheses.

11. **Extract Key**
	```cpp
	            while(s[i] != ')') {
	```
	This inner while loop continues extracting characters from the string until the closing parenthesis is encountered.

12. **Add Character to Key**
	```cpp
	                key += s[i];
	```
	Each character encountered inside the parentheses is appended to the `key` string.

13. **Increment i (Key Extraction)**
	```cpp
	                i++;
	```
	Move to the next character in the string during key extraction.

14. **End of Key Extraction**
	```cpp
	            }
	```
	End of the while loop that extracts the key inside the parentheses.

15. **Check if Key Exists in Map**
	```cpp
	            if(mp.count(key)) {
	```
	Check if the `key` exists in the map `mp`.

16. **Add Value to Result**
	```cpp
	                res += mp[key];
	```
	If the key exists in the map, append the corresponding value from the map to the result string `res`.

17. **Add '?' for Missing Key**
	```cpp
	            else res += '?';
	```
	If the key is not found in the map, append `?` to the result string `res`.

18. **Increment i (End of Parentheses)**
	```cpp
	            i++;
	```
	Move past the closing parenthesis after processing the key.

19. **Handle Non-Parenthesized Characters**
	```cpp
	        } else res += s[i++];
	```
	If the character is not an opening parenthesis, simply append the character to the result string `res`.

20. **Return Final Result**
	```cpp
	    return res;
	```
	Return the final result string `res` after all the placeholders are processed.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The solution involves iterating through the string `s` and performing constant-time lookups for each key, leading to O(n) time complexity.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n + m)

The space complexity arises from storing the string `s` and the map of `knowledge`, where n is the length of the string and m is the number of key-value pairs in `knowledge`.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/description/)

---
{{< youtube HiEzscFAxc4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
