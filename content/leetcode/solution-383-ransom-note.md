
+++
authors = ["grid47"]
title = "Leetcode 383: Ransom Note"
date = "2024-09-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 383: Ransom Note in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/383.webp"
youtube = "i3bvxJyUB40"
youtube_upload_date="2024-04-19"
youtube_thumbnail="https://i.ytimg.com/vi_webp/i3bvxJyUB40/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/383.webp" 
    alt="A sequence of letters forming a ransom note, with the available letters glowing to form the required note."
    caption="Solution to LeetCode 383: Ransom Note Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine. Each letter in magazine can only be used once.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two strings, ransomNote and magazine.
- **Example:** `ransomNote = 'hello', magazine = 'ohelloll'`
- **Constraints:**
	- 1 <= ransomNote.length, magazine.length <= 10^5
	- ransomNote and magazine consist of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a boolean value: true if ransomNote can be constructed from the letters in magazine, false otherwise.
- **Example:** `Output: true for ransomNote = 'hello' and magazine = 'ohelloll'`
- **Constraints:**
	- The result should be a boolean indicating whether it's possible to construct ransomNote from magazine.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to verify if each letter in ransomNote appears enough times in magazine.

- Create a frequency map for characters in the magazine.
- Iterate over the ransomNote string and check if each character is available in the magazine's frequency map.
- If any character in ransomNote is missing or insufficient in magazine, return false.
- If all characters are found with sufficient frequency, return true.
{{< dots >}}
### Problem Assumptions ✅
- Both ransomNote and magazine are non-empty strings.
- There are no special characters, only lowercase English letters.
{{< dots >}}
## Examples 🧩
- **Input:** `ransomNote = 'g', magazine = 'h'`  \
  **Explanation:** In this case, the letter 'g' is not present in the magazine, so the answer is false.

- **Input:** `ransomNote = 'gg', magazine = 'g'`  \
  **Explanation:** Here, the letter 'g' appears only once in the magazine, so it's impossible to construct the ransomNote, and the answer is false.

- **Input:** `ransomNote = 'hello', magazine = 'ohelloll'`  \
  **Explanation:** In this case, all letters in ransomNote are available in magazine in sufficient quantities, so the answer is true.

{{< dots >}}
## Approach 🚀
The approach involves counting the frequency of characters in the magazine and then verifying if those frequencies are sufficient for constructing the ransomNote.

### Initial Thoughts 💭
- The problem requires checking character availability in a string.
- Using a frequency map for the magazine allows us to efficiently check if the ransomNote can be constructed.
{{< dots >}}
### Edge Cases 🌐
- Both ransomNote and magazine are non-empty as per the constraints.
- The solution must handle the case where the length of ransomNote and magazine is up to 10^5 efficiently.
- Ensure that the solution works for edge cases where the magazine has exactly the required number of letters or where ransomNote and magazine are identical.
- The solution should be linear in time complexity, i.e., O(n + m), where n is the length of ransomNote and m is the length of magazine.
{{< dots >}}
## Code 💻
```cpp
bool canConstruct(string ransomNote, string magazine) {
    map<char, int> mp;
    for(int x: magazine)
        mp[x]++;
    
    for(int j = 0; j < ransomNote.size(); j++) {
        if(!mp.count(ransomNote[j])) return false;
        else {
            mp[ransomNote[j]]--;
            if(mp[ransomNote[j]] == 0) mp.erase(ransomNote[j]);
        }
    }
    return true;
}
```

This function checks if it is possible to construct the `ransomNote` from the `magazine` string by counting the frequency of characters and ensuring that each character in the ransom note can be found in the magazine with at least the same frequency.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool canConstruct(string ransomNote, string magazine) {
	```
	This line defines the function `canConstruct`, which takes two string arguments: `ransomNote` and `magazine`. It returns a boolean value indicating if the ransom note can be constructed using characters from the magazine.

2. **Map Initialization**
	```cpp
	    map<char, int> mp;
	```
	A map `mp` is created to store the frequency of each character in the `magazine` string, with characters as keys and their respective counts as values.

3. **Iterating Through Magazine**
	```cpp
	    for(int x: magazine)
	```
	This `for` loop iterates over each character `x` in the `magazine` string.

4. **Updating Frequency Map**
	```cpp
	        mp[x]++;
	```
	For each character `x` in the `magazine`, its count in the map `mp` is incremented by 1.

5. **Iterating Through Ransom Note**
	```cpp
	    for(int j = 0; j < ransomNote.size(); j++) {
	```
	This `for` loop iterates through each character in the `ransomNote` string.

6. **Checking Character Availability**
	```cpp
	        if(!mp.count(ransomNote[j])) return false;
	```
	This condition checks if the current character in the `ransomNote` is not present in the map `mp`. If it's not found, the function returns `false`, indicating that the ransom note cannot be constructed.

7. **Character Removal**
	```cpp
	        else {
	```
	If the character is found in the map `mp`, the function proceeds to reduce its count.

8. **Decrementing Character Count**
	```cpp
	            mp[ransomNote[j]]--;
	```
	The count of the current character in `ransomNote` is decremented by 1 in the map `mp`.

9. **Removing Zero Counted Characters**
	```cpp
	            if(mp[ransomNote[j]] == 0) mp.erase(ransomNote[j]);
	```
	If the count of the current character in the map reaches 0, the character is erased from the map to save space.

10. **End of Ransom Note Loop**
	```cpp
	    }
	```
	This marks the end of the loop that iterates through the `ransomNote` string.

11. **Return Statement**
	```cpp
	    return true;
	```
	If the loop completes without returning `false`, it means the ransom note can be constructed, so the function returns `true`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n + m)
- **Average Case:** O(n + m)
- **Worst Case:** O(n + m)

The time complexity is linear with respect to the lengths of the ransomNote and magazine.

### Space Complexity 💾
- **Best Case:** O(k)
- **Worst Case:** O(k)

The space complexity depends on the number of unique characters in the magazine, which is at most 26 for lowercase English letters.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/ransom-note/description/)

---
{{< youtube i3bvxJyUB40 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
