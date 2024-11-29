
+++
authors = ["grid47"]
title = "Leetcode 763: Partition Labels"
date = "2024-08-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 763: Partition Labels in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Two Pointers","String","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/763.webp"
youtube = "B7m8UmZE-vw"
youtube_upload_date="2021-10-26"
youtube_thumbnail="https://i.ytimg.com/vi_webp/B7m8UmZE-vw/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/763.webp" 
    alt="A string where partitions are made, each partition softly glowing as it is formed."
    caption="Solution to LeetCode 763: Partition Labels Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a string s. Your task is to divide the string into the maximum number of parts such that each letter appears in at most one part. The resulting parts, when concatenated in order, should form the original string.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string s.
- **Example:** `Input: s = "abcacbadefgh"`
- **Constraints:**
	- 1 <= s.length <= 500
	- s consists of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a list of integers where each integer represents the length of one part after dividing the string.
- **Example:** `Output: [6, 7]`
- **Constraints:**
	- The result list should contain the maximum number of partitions possible.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to divide the string into the maximum number of parts such that each letter appears in only one part.

- First, find the last occurrence of each character in the string.
- Then, iterate over the string, keeping track of the rightmost position where the current partition can end.
- If the current position is equal to the last occurrence of any character in the current partition, finalize the current partition and start a new one.
{{< dots >}}
### Problem Assumptions ✅
- The string is non-empty and contains only lowercase letters.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: Input: s = "abcacbadefgh"`  \
  **Explanation:** In this example, the string is divided into two parts: "abcacb" and "adefgh", with no characters repeating across the parts.

{{< dots >}}
## Approach 🚀
We can solve this problem by iterating through the string and keeping track of the last occurrence of each character. As we move through the string, we will try to form partitions based on these last occurrences.

### Initial Thoughts 💭
- We can use a map to store the last occurrence index of each character.
- We can iterate through the string and dynamically adjust the end of the current partition.
- The key to solving this problem is to recognize when to finalize a partition by checking the farthest position of the characters in the partition.
{{< dots >}}
### Edge Cases 🌐
- The string is not empty, but if the length is 1, the output should be a single partition of length 1.
- Ensure that the solution works efficiently even for the maximum string length of 500 characters.
- Strings with no repeating characters will have one partition for the entire string.
- Handle strings with repeated characters correctly, ensuring the partitioning respects the rule that each character appears in at most one part.
{{< dots >}}
## Code 💻
```cpp
vector<int> partitionLabels(string s) {
    map<char, int> mp;
    for(int i = 0; i < s.size(); i++)
        mp[s[i]] = i;
    
    vector<int> res;
    int prv = -1, mx = mp[s[0]];
    for(int i = 0; i < s.size(); i++) {
        mx = max(mx, mp[s[i]]);
        if(i == mx || i == s.size() - 1) {
            res.push_back(i - prv);
            prv = mx;
        }
    }
    return res;
}
```

This code defines a function that takes a string and partitions it into substrings such that no letter appears in more than one substring. It returns the sizes of those substrings.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> partitionLabels(string s) {
	```
	This line defines the function 'partitionLabels' which takes a string 's' and returns a vector of integers representing the sizes of the partitions.

2. **Map Initialization**
	```cpp
	    map<char, int> mp;
	```
	This initializes a map 'mp' where each character from the string will be mapped to its last occurrence index in the string.

3. **First Loop**
	```cpp
	    for(int i = 0; i < s.size(); i++)
	```
	This loop iterates over each character in the string 's' to record the last occurrence index of each character in the 'mp' map.

4. **Map Population**
	```cpp
	        mp[s[i]] = i;
	```
	This updates the map 'mp' with the index of the current character 's[i]'. This ensures that the map stores the last occurrence of each character.

5. **Result Vector Initialization**
	```cpp
	    vector<int> res;
	```
	This initializes an empty vector 'res' which will store the sizes of the partitions created.

6. **Variables Initialization**
	```cpp
	    int prv = -1, mx = mp[s[0]];
	```
	This initializes two variables: 'prv' to -1 (the previous partition's end index) and 'mx' to the last occurrence index of the first character in the string.

7. **Second Loop**
	```cpp
	    for(int i = 0; i < s.size(); i++) {
	```
	This loop iterates over the string 's' again to determine the boundaries of the partitions.

8. **Maximum Index Update**
	```cpp
	        mx = max(mx, mp[s[i]]);
	```
	This updates the variable 'mx' to store the maximum index between the current 'mx' and the last occurrence index of the current character.

9. **Partition Boundary Check**
	```cpp
	        if(i == mx || i == s.size() - 1) {
	```
	This checks if the current index 'i' has reached the end of a partition. A partition ends when 'i' equals 'mx' (the last occurrence of the current characters in the partition) or when 'i' is the last index in the string.

10. **Push Partition Size**
	```cpp
	            res.push_back(i - prv);
	```
	If a partition boundary is found, this line adds the size of the partition (difference between the current index 'i' and the previous partition's end 'prv') to the result vector 'res'.

11. **Update Partition End**
	```cpp
	            prv = mx;
	```
	This updates 'prv' to 'mx', marking the end of the current partition.

12. **Return Statement**
	```cpp
	    return res;
	```
	This returns the 'res' vector, which contains the sizes of the partitions.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n) when the string is already partitioned optimally.
- **Average Case:** O(n) where n is the length of the string, as we traverse the string twice.
- **Worst Case:** O(n) as we traverse the string and map the last occurrence of each character.

The time complexity is linear as we process each character of the string twice.

### Space Complexity 💾
- **Best Case:** O(1) for space used in the map.
- **Worst Case:** O(1) for storing the last occurrences, as we only store information for 26 characters (lowercase English letters).

The space complexity is constant as we only need to store a fixed number of characters.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/partition-labels/description/)

---
{{< youtube B7m8UmZE-vw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
