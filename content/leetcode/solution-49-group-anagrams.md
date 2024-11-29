
+++
authors = ["grid47"]
title = "Leetcode 49: Group Anagrams"
date = "2024-11-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 49: Group Anagrams in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/49.webp"
youtube = "eDmxPfVa81k"
youtube_upload_date="2023-12-13"
youtube_thumbnail="https://i.ytimg.com/vi_webp/eDmxPfVa81k/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/49.webp" 
    alt="A series of floating words forming gentle clusters, swirling around each other."
    caption="Solution to LeetCode 49: Group Anagrams Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an array of strings. Group the strings that are anagrams of each other together and return them as a list of lists. An anagram is a word or phrase formed by rearranging the letters of another word or phrase.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is an array of strings, where each string is a lowercase English word.
- **Example:** `["listen", "silent", "enlist", "rat", "tar", "art"]`
- **Constraints:**
	- 1 <= strs.length <= 10^4
	- 0 <= strs[i].length <= 100
	- Each string in strs consists of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a list of lists, where each inner list contains strings that are anagrams of each other.
- **Example:** `[["listen", "silent", "enlist"], ["rat", "tar", "art"]]`
- **Constraints:**
	- The output should contain all anagram groups.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to group the strings that are anagrams of each other and return them in a list of lists.

- 1. Create a map to store groups of anagrams.
- 2. For each string, generate a signature (like a sorted version or a character count).
- 3. Use this signature as the key in the map and add the string to the corresponding list.
- 4. After processing all strings, return the list of values from the map.
{{< dots >}}
### Problem Assumptions ✅
- There will be no empty strings in the input unless explicitly stated (e.g., in Example 3).
{{< dots >}}
## Examples 🧩
- **Input:** `["listen", "silent", "enlist", "rat", "tar", "art"]`  \
  **Explanation:** In this example, the strings "listen", "silent", and "enlist" form one group of anagrams, while "rat", "tar", and "art" form another group.

- **Input:** `["cat", "dog", "god", "act"]`  \
  **Explanation:** Here, "cat" and "act" are anagrams of each other, while "dog" and "god" form a separate group.

{{< dots >}}
## Approach 🚀
The approach involves using a map to group the strings that are anagrams of each other based on a unique signature (e.g., sorted characters or character count).

### Initial Thoughts 💭
- Anagrams can be identified by sorting the characters in the string or by using a frequency count of characters.
- Using a frequency count or sorted string as a key in a map can efficiently group the anagrams.
{{< dots >}}
### Edge Cases 🌐
- If the input contains an empty string, it should be grouped separately.
- For larger inputs, the algorithm should still efficiently group anagrams within the constraints.
- Anagrams with only one character should be grouped together.
- The input strings contain only lowercase letters and have lengths between 0 and 100.
{{< dots >}}
## Code 💻
```cpp

string code(string x) {
    vector<int> q(26, 0);
    for(int i = 0; i < x.size(); i++) {
        q[x[i] - 'a']++;
    }
    stringstream ss;
    for(int i = 0; i < 26; i++) {
        if(i != 0) ss << ',';
        ss << q[i];
    }
    return ss.str();
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<string, vector<string>> ma;
    for(string x: strs) {
        string mask = code(x);
        ma[mask].push_back(x);
    }
    vector<vector<string>> ans;
    for(auto [key, val]: ma)
        ans.push_back(val);
    
    return ans;
}
```

This code groups anagrams in a given list of strings.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	string code(string x) {
	```
	This line declares a function named `code` that takes a string `x` as input and returns a string representing the character frequency of the input string.

2. **Array Initialization**
	```cpp
	    vector<int> q(26, 0);
	```
	This line initializes a vector `q` of size 26 to store the frequency of each lowercase letter.

3. **Character Frequency Calculation**
	```cpp
	    for(int i = 0; i < x.size(); i++) {
	```
	This loop iterates over each character in the input string `x`.

4. **Character Frequency Calculation**
	```cpp
	        q[x[i] - 'a']++;
	```
	The frequency of the current character `x[i]` is incremented in the corresponding index of the `q` vector.

5. **String Stream Initialization**
	```cpp
	    stringstream ss;
	```
	A string stream `ss` is initialized to construct the character frequency string.

6. **String Stream Manipulation**
	```cpp
	    for(int i = 0; i < 26; i++) {
	```
	This loop iterates over the frequency array `q`.

7. **String Stream Manipulation**
	```cpp
	        if(i != 0) ss << ',';
	```
	If it's not the first iteration, a comma is added to the string stream as a separator.

8. **String Stream Manipulation**
	```cpp
	        ss << q[i];
	```
	The frequency of the current character is appended to the string stream.

9. **Return Frequency String**
	```cpp
	    return ss.str();
	```
	The final string representation of the character frequencies is returned.

10. **Main Function**
	```cpp
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
	```
	This line declares the main function `groupAnagrams` that takes a vector of strings `strs` as input and returns a vector of vectors containing grouped anagrams.

11. **Map Initialization**
	```cpp
	    map<string, vector<string>> ma;
	```
	A map `ma` is initialized to store the character frequency string as the key and a vector of anagrams as the value.

12. **Iterate Over Strings**
	```cpp
	    for(string x: strs) {
	```
	This loop iterates over each string `x` in the input vector `strs`.

13. **Generate Character Frequency String**
	```cpp
	        string mask = code(x);
	```
	The `code` function is called to generate the character frequency string `mask` for the current string `x`.

14. **Group Anagrams**
	```cpp
	        ma[mask].push_back(x);
	```
	The current string `x` is added to the vector of anagrams associated with the `mask` key in the `ma` map.

15. **Result Vector Initialization**
	```cpp
	    vector<vector<string>> ans;
	```
	A 2D vector `ans` is initialized to store the grouped anagrams.

16. **Populate Result Vector**
	```cpp
	    for(auto [key, val]: ma)
	```
	This loop iterates over the key-value pairs in the `ma` map.

17. **Populate Result Vector**
	```cpp
	        ans.push_back(val);
	```
	The vector of anagrams associated with the current key is added to the `ans` vector.

18. **Return Result**
	```cpp
	    return ans;
	```
	The `ans` vector containing the grouped anagrams is returned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n * k log k)
- **Average Case:** O(n * k log k)
- **Worst Case:** O(n * k log k)

The time complexity is O(n * k log k), where n is the number of strings and k is the length of the longest string. Sorting each string takes O(k log k) time.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n * k)

The space complexity is O(n * k) where n is the number of strings and k is the average length of the strings, due to the space used by the map to store the anagram groups.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/group-anagrams/description/)

---
{{< youtube eDmxPfVa81k >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
