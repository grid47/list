
+++
authors = ["grid47"]
title = "Leetcode 423: Reconstruct Original Digits from English"
date = "2024-09-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 423: Reconstruct Original Digits from English in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Math","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/423.webp"
youtube = "cGgG0A__wNQ"
youtube_upload_date="2021-03-28"
youtube_thumbnail="https://i.ytimg.com/vi/cGgG0A__wNQ/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/423.webp" 
    alt="A sequence of English words forming digits, with each word gently transforming into its corresponding digit."
    caption="Solution to LeetCode 423: Reconstruct Original Digits from English Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a string representing an out-of-order English representation of digits from 0 to 9. Your task is to rearrange the characters of the string in such a way that you can extract the digits in ascending order. The string will only contain valid letters corresponding to the English representations of digits.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a string s that contains characters representing the out-of-order English words for digits 0-9.
- **Example:** `Input: s = "enionzotwo"
`
- **Constraints:**
	- 1 <= s.length <= 10^5
	- s[i] is one of the characters from a predefined set representing the letters in digit words.
	- The input string will always be valid and contain only characters from the English digit words.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a string containing the digits, sorted in ascending order, as a result of extracting the digits from the input string.
- **Example:** `Output: "012"`
- **Constraints:**
	- The output string should contain the digits in ascending order.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to extract the digits from the scrambled string based on their English word representations, utilizing the distinct characters in each word to identify and count the digits.

- Identify the distinct characters that can be used to determine the presence of certain digits (e.g., 'z' for zero, 'w' for two, etc.).
- Count the occurrences of each character in the input string.
- Using the character counts, determine how many of each digit appears in the string.
- Rebuild the string by adding the digits in ascending order.
{{< dots >}}
### Problem Assumptions ✅
- The input string will always be valid and contain only the necessary letters to form digit words.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: Input: s = "owoztneoer"`  \
  **Explanation:** In this case, the string contains the letters for the words 'zero', 'one', and 'two'. Extracting these gives the digits '0', '1', and '2', resulting in the output "012".

{{< dots >}}
## Approach 🚀
We solve the problem by counting the occurrences of specific characters that are unique to certain digits. This allows us to determine the number of each digit and then sort them in ascending order.

### Initial Thoughts 💭
- Certain digits have unique characters that can help identify them (e.g., 'z' for zero, 'w' for two).
- Once we identify and count the digits, we can arrange them in ascending order.
- Using the frequency of characters, we can iteratively determine which digits are present in the string and construct the result.
{{< dots >}}
### Edge Cases 🌐
- The input string will not be empty, as per the constraints.
- For large strings with many repeated characters, ensure that the solution is efficient enough to handle the input size.
- Ensure that the solution correctly handles inputs with all digits from 0 to 9.
- The solution should handle inputs with a length up to 100,000 characters efficiently.
{{< dots >}}
## Code 💻
```cpp
string originalDigits(string s) {
    vector<string> words = {"zero", "two", "four", "six", "eight", "one", "three", "five", "seven", "nine"};
    vector<int> nums = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
    vector<int> distinct_char = {'z', 'w', 'u', 'x', 'g', 'o', 'r', 'f', 'v', 'i'};
    vector<int> counts(26, 0);
    string result;
    for(auto ch : s){ counts[ch-'a']++;}
    for(int i = 0; i < 10; i++){
        int count = counts[distinct_char[i]-'a'];
        for(int j = 0; j < words[i].size(); j++)
            counts[words[i][j]-'a'] -= count;
        while(count--)
            result += to_string(nums[i]);
    }
    sort(result.begin(), result.end());
    return result;
}
```

The function `originalDigits` takes a string of characters and returns a string representing the digits (0-9) that can be formed by rearranging the characters. It utilizes a set of distinct characters to identify digits and subtracts character occurrences to form the result.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	string originalDigits(string s) {
	```
	This line declares the function `originalDigits`, which accepts a string `s` as input and will return a string containing the digits formed from the characters in `s`.

2. **Word List Initialization**
	```cpp
	    vector<string> words = {"zero", "two", "four", "six", "eight", "one", "three", "five", "seven", "nine"};
	```
	This line initializes a vector `words` that contains the string representations of the numbers 0 to 9.

3. **Number List Initialization**
	```cpp
	    vector<int> nums = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
	```
	Here, a vector `nums` is initialized with the digits corresponding to the numbers represented in the `words` vector.

4. **Distinct Character List Initialization**
	```cpp
	    vector<int> distinct_char = {'z', 'w', 'u', 'x', 'g', 'o', 'r', 'f', 'v', 'i'};
	```
	This vector `distinct_char` contains the distinct characters that help identify each number from 0 to 9 in the string `s`.

5. **Count Array Initialization**
	```cpp
	    vector<int> counts(26, 0);
	```
	This initializes a vector `counts` of size 26 to store the frequency of each character in the input string `s`.

6. **Result String Initialization**
	```cpp
	    string result;
	```
	A string `result` is initialized to store the final digits that will be returned.

7. **Character Frequency Count**
	```cpp
	    for(auto ch : s){ counts[ch-'a']++;}
	```
	This loop iterates over each character in the string `s` and increments its corresponding count in the `counts` array.

8. **Main Loop for Digit Construction**
	```cpp
	    for(int i = 0; i < 10; i++){
	```
	This loop iterates over the 10 digits (0-9), processing each one by identifying the number of occurrences of its distinct characters.

9. **Count Extraction**
	```cpp
	        int count = counts[distinct_char[i]-'a'];
	```
	This line extracts the count of the distinct character associated with the current digit, which indicates how many times this digit can be formed from `s`.

10. **Character Removal**
	```cpp
	        for(int j = 0; j < words[i].size(); j++)
	```
	This loop iterates over each character in the corresponding word (e.g., 'zero', 'one') for the current digit.

11. **Character Frequency Update**
	```cpp
	            counts[words[i][j]-'a'] -= count;
	```
	This updates the `counts` array by decrementing the frequency of each character in the current digit's word, as those characters are now used.

12. **Digit Addition**
	```cpp
	        while(count--)
	```
	This loop adds the current digit to the `result` string as many times as it was identified in the input string `s`.

13. **Result Update**
	```cpp
	            result += to_string(nums[i]);
	```
	This line converts the current digit (from `nums[i]`) to a string and appends it to the `result` string.

14. **Result Sorting**
	```cpp
	    sort(result.begin(), result.end());
	```
	This sorts the `result` string in ascending order to ensure the digits are returned in a lexicographically sorted order.

15. **Return Statement**
	```cpp
	    return result;
	```
	This returns the final string `result`, which contains the digits in sorted order.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the input string.
- **Average Case:** O(n), as we process each character in the string and identify digits in a single pass.
- **Worst Case:** O(n), as the solution requires only a few linear scans over the input string.

The time complexity is linear because we only process the string a constant number of times.

### Space Complexity 💾
- **Best Case:** O(1), since the space complexity does not depend on the input size.
- **Worst Case:** O(1), as the space used for counting the characters is constant.

The space complexity is constant because we only need a fixed amount of space to store the counts of characters.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/reconstruct-original-digits-from-english/description/)

---
{{< youtube cGgG0A__wNQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
