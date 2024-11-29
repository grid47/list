
+++
authors = ["grid47"]
title = "Leetcode 1647: Minimum Deletions to Make Character Frequencies Unique"
date = "2024-05-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1647: Minimum Deletions to Make Character Frequencies Unique in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "h8AZEN49gTc"
youtube_upload_date="2023-09-12"
youtube_thumbnail="https://i.ytimg.com/vi/h8AZEN49gTc/maxresdefault.jpg"
comments = true
+++



---
Given a string s, determine the minimum number of deletions needed to make s 'good'. A string is 'good' if no two characters have the same frequency.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A string s.
- **Example:** `s = 'abc'`
- **Constraints:**
	- 1 <= s.length <= 10^5
	- s contains only lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of deletions needed to make the string good.
- **Example:** `Output: 3`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the minimum number of deletions needed, first calculate the frequency of each character in the string. Then, identify and delete characters with duplicate frequencies.

- Count the frequency of each character in the string.
- Use a set to track the frequencies that have already been used.
- If a frequency is repeated, decrement it and count the deletion.
- Return the total number of deletions.
{{< dots >}}
### Problem Assumptions ✅
- The input string will always be a valid non-empty string containing lowercase English letters.
{{< dots >}}
## Examples 🧩
- **Input:** `s = 'abc'`  \
  **Explanation:** Each character in the string 'abc' appears once, so no deletions are needed.

{{< dots >}}
## Approach 🚀
The approach involves counting the frequency of each character in the string and ensuring that no two characters have the same frequency by removing characters where necessary.

### Initial Thoughts 💭
- We can use a frequency map to track how many times each character appears.
- We need to track the frequencies that have already been used to avoid duplicates.
- To solve this, we need to use a set to keep track of the frequencies we've seen so far and ensure no duplicates.
{{< dots >}}
### Edge Cases 🌐
- The input string is not empty as per the constraints.
- The solution should efficiently handle strings with lengths up to 100,000.
- When all characters in the string are the same, the only possible deletion is reducing the frequency to 1.
- Ensure the solution handles the upper constraint where s.length is up to 100,000.
{{< dots >}}
## Code 💻
```cpp
int minDeletions(string s) {
    map<char, int> mp;
    int n= s.size();
    for(char x: s)
        mp[x]++;
    vector<pair<int, char>> arr;
    for(auto it: mp) {
        arr.push_back({it.second, it.first});
    }
    sort(arr.begin(), arr.end());
    n = arr.size();
    set<int> cnt;
    int del = 0;
    for(int i = 0; i < n; i++) {
        int tmp = arr[i].first;
        while(tmp > 0 && cnt.count(tmp)) {
            tmp--;
            del++;
        }
        if(tmp > 0) cnt.insert(tmp);
    }
    return del;
}
```

This function finds the minimum number of deletions required to make the frequency of each character in the string unique. It uses a frequency map, sorts the characters by frequency, and then iterates through them, reducing duplicate frequencies by deletion while keeping track of the number of deletions.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minDeletions(string s) {
	```
	This line defines the function `minDeletions` that takes a string `s` and returns the minimum number of deletions required to make the frequency of each character in `s` unique.

2. **Map Initialization**
	```cpp
	    map<char, int> mp;
	```
	A map `mp` is declared to store the frequency of each character in the string `s`.

3. **Size Calculation**
	```cpp
	    int n = s.size();
	```
	The variable `n` is initialized to the size of the string `s` to track the length of the string.

4. **Frequency Calculation**
	```cpp
	    for(char x: s)
	```
	A loop is used to iterate over each character `x` in the string `s`.

5. **Frequency Update**
	```cpp
	        mp[x]++;
	```
	For each character `x`, its frequency is incremented in the map `mp`.

6. **Array Initialization**
	```cpp
	    vector<pair<int, char>> arr;
	```
	A vector `arr` is declared to store pairs of frequency and corresponding character.

7. **Map Iteration**
	```cpp
	    for(auto it: mp) {
	```
	A loop is used to iterate over each element `it` in the frequency map `mp`.

8. **Array Population**
	```cpp
	        arr.push_back({it.second, it.first});
	```
	Each frequency and character pair from the map `mp` is added to the vector `arr`, where `it.second` is the frequency and `it.first` is the character.

9. **Sorting**
	```cpp
	    sort(arr.begin(), arr.end());
	```
	The vector `arr` is sorted based on the frequencies of the characters in ascending order.

10. **Array Size Update**
	```cpp
	    n = arr.size();
	```
	The variable `n` is updated to the size of the vector `arr`.

11. **Set Initialization**
	```cpp
	    set<int> cnt;
	```
	A set `cnt` is declared to track the unique frequencies that have been assigned.

12. **Deletion Count Initialization**
	```cpp
	    int del = 0;
	```
	The variable `del` is initialized to 0, which will keep track of the number of deletions made.

13. **Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	A loop is used to iterate over the sorted array `arr`.

14. **Frequency Access**
	```cpp
	        int tmp = arr[i].first;
	```
	The frequency of the current character is accessed from the first element of the pair in `arr`.

15. **Check for Duplicates**
	```cpp
	        while(tmp > 0 && cnt.count(tmp)) {
	```
	A while loop checks if the frequency `tmp` already exists in the set `cnt`. If it does, the frequency is reduced.

16. **Frequency Reduction**
	```cpp
	            tmp--;
	```
	If a duplicate frequency is found, the frequency `tmp` is reduced by 1.

17. **Deletion Increment**
	```cpp
	            del++;
	```
	Each time a frequency is reduced to avoid duplicates, the deletion count `del` is incremented.

18. **Insert Frequency**
	```cpp
	        if(tmp > 0) cnt.insert(tmp);
	```
	If the frequency `tmp` is still greater than 0 after the while loop, it is inserted into the set `cnt` to ensure it is unique.

19. **Return Statement**
	```cpp
	    return del;
	```
	The function returns the total number of deletions `del` made to ensure all frequencies are unique.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is O(n log n) because we need to sort the frequencies of the characters.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space used for storing the character frequencies and the set of frequencies.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/description/)

---
{{< youtube h8AZEN49gTc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
