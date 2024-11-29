
+++
authors = ["grid47"]
title = "Leetcode 1657: Determine if Two Strings Are Close"
date = "2024-05-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1657: Determine if Two Strings Are Close in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Sorting","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "-jXQK-UeChU"
youtube_upload_date="2020-12-14"
youtube_thumbnail="https://i.ytimg.com/vi/-jXQK-UeChU/maxresdefault.jpg"
comments = true
+++



---
Two strings are considered transformable into each other if you can convert one into the other by performing a series of operations. These operations include swapping any two characters or transforming all occurrences of one character into another.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two strings, `word1` and `word2`. Each string consists of lowercase English letters.
- **Example:** `word1 = "abc", word2 = "bca"`
- **Constraints:**
	- 1 <= word1.length, word2.length <= 10^5
	- word1 and word2 contain only lowercase English letters

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if `word1` and `word2` can be transformed into each other through the specified operations, otherwise return false.
- **Example:** `true`
- **Constraints:**
	- The result will be either true or false.

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine if `word1` and `word2` can be transformed into each other through a sequence of swaps and character transformations.

- Check if the lengths of both strings are the same. If not, return false.
- Check if both strings contain the same set of unique characters. If they do not, return false.
- Compare the frequencies of characters in both strings. If the frequency distribution matches, return true, otherwise return false.
{{< dots >}}
### Problem Assumptions ✅
- Both strings are valid lowercase English strings.
- The strings may have different lengths, but you must check their transformation potential.
{{< dots >}}
## Examples 🧩
- **Input:** `word1 = "abc", word2 = "bca"`  \
  **Explanation:** In this case, it is possible to transform `word1` into `word2` by swapping characters. After applying two swap operations, we get the string `bca`.

- **Input:** `word1 = "a", word2 = "aa"`  \
  **Explanation:** In this case, it's impossible to convert `word1` into `word2` since `word2` has more characters than `word1`, making it impossible to apply the given operations.

{{< dots >}}
## Approach 🚀
We will compare the character distributions and sets of the two strings to determine if they can be transformed into each other.

### Initial Thoughts 💭
- If two strings contain different characters, they can never be transformed into each other.
- The operations only allow swaps and transformations, which means the structure of the strings' characters must be identical.
- Start by checking if the lengths of the strings are the same. If not, return false immediately.
- Then, check the frequency of characters in both strings. If the frequencies match, they can be transformed into each other.
{{< dots >}}
### Edge Cases 🌐
- If one string is empty and the other is not, return false.
- For large input strings, ensure that the solution efficiently compares characters without redundant operations.
- If both strings consist of the same repeated character, they should be transformable into each other.
- Be mindful of time complexity when processing large inputs.
{{< dots >}}
## Code 💻
```cpp
bool closeStrings(string w1, string w2) {
    if(w1.size() != w2.size()) return false;
    int n = w1.size();
    map<char, int> m1, m2;
    int mask1 = 0, mask2 = 0;
    for(int i = 0; i < n; i++) {
        m1[w1[i]]++;
        m2[w2[i]]++;
        mask1 |= (1 << (w1[i] - 'a'));
        mask2 |= (1 << (w2[i] - 'a'));          
    }
    if(mask1 != mask2) return false;
    vector<int> arr, nums;
    for(auto it: m1) {
        arr.push_back(it.second);
    }
    sort(arr.begin(), arr.end());
    // for(int x: arr)
    //     cout << x << " ";
    // cout << "\n";
    for(auto it: m2) {
        nums.push_back(it.second);
    }
    sort(nums.begin(), nums.end());        
    // for(int x: nums)
    //     cout << x << " ";
    cout << "\n";        
    return nums == arr;
}
```

This function determines if two strings are close, meaning they can be transformed into each other by reordering characters and replacing characters while maintaining character frequencies.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool closeStrings(string w1, string w2) {
	```
	Defines the function `closeStrings` that takes two strings as input and returns a boolean.

2. **Size Check**
	```cpp
	    if(w1.size() != w2.size()) return false;
	```
	Checks if the two strings have the same length. If not, they cannot be close.

3. **Variable Initialization**
	```cpp
	    int n = w1.size();
	```
	Initializes the variable `n` to store the size of the strings for later use.

4. **Map Initialization**
	```cpp
	    map<char, int> m1, m2;
	```
	Initializes two maps to count the frequency of characters in each string.

5. **Variable Initialization**
	```cpp
	    int mask1 = 0, mask2 = 0;
	```
	Initializes two integer masks to track the unique characters in the strings.

6. **Looping**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Loops through each character of the strings to update the maps and masks.

7. **Map Update**
	```cpp
	        m1[w1[i]]++;
	```
	Increments the frequency of the current character in the first map.

8. **Map Update**
	```cpp
	        m2[w2[i]]++;
	```
	Increments the frequency of the current character in the second map.

9. **Bit Manipulation**
	```cpp
	        mask1 |= (1 << (w1[i] - 'a'));
	```
	Updates the bitmask for the first string to track its unique characters.

10. **Bit Manipulation**
	```cpp
	        mask2 |= (1 << (w2[i] - 'a'));          
	```
	Updates the bitmask for the second string to track its unique characters.

11. **Condition Check**
	```cpp
	    if(mask1 != mask2) return false;
	```
	Checks if the sets of unique characters in the two strings are different. If so, they cannot be close.

12. **Vector Initialization**
	```cpp
	    vector<int> arr, nums;
	```
	Initializes two vectors to store the frequency counts from the maps.

13. **Map Iteration**
	```cpp
	    for(auto it: m1) {
	```
	Iterates through the first map to extract character frequencies.

14. **Vector Update**
	```cpp
	        arr.push_back(it.second);
	```
	Appends the frequency of a character from the first map to the first vector.

15. **Sorting**
	```cpp
	    sort(arr.begin(), arr.end());
	```
	Sorts the frequencies in the first vector to prepare for comparison.

16. **Map Iteration**
	```cpp
	    for(auto it: m2) {
	```
	Iterates through the second map to extract character frequencies.

17. **Vector Update**
	```cpp
	        nums.push_back(it.second);
	```
	Appends the frequency of a character from the second map to the second vector.

18. **Sorting**
	```cpp
	    sort(nums.begin(), nums.end());        
	```
	Sorts the frequencies in the second vector to prepare for comparison.

19. **Return**
	```cpp
	    return nums == arr;
	```
	Compares the sorted frequency vectors. If they are equal, the strings are close.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The best-case time complexity occurs when the strings are already identical or trivially transformable. The worst case arises from sorting the frequency distributions of characters.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage of character frequencies and other intermediate data structures.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/determine-if-two-strings-are-close/description/)

---
{{< youtube -jXQK-UeChU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
