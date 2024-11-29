
+++
authors = ["grid47"]
title = "Leetcode 451: Sort Characters By Frequency"
date = "2024-09-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 451: Sort Characters By Frequency in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Sorting","Heap (Priority Queue)","Bucket Sort","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/451.webp"
youtube = "JTdpTHaGQoA"
youtube_upload_date="2020-05-22"
youtube_thumbnail="https://i.ytimg.com/vi/JTdpTHaGQoA/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/451.webp" 
    alt="A string where characters are sorted by frequency, with the most frequent characters glowing brightly."
    caption="Solution to LeetCode 451: Sort Characters By Frequency Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a string, sort its characters based on their frequency of occurrence in descending order. If multiple solutions are possible, any valid answer is acceptable. The frequency of each character refers to how many times it appears in the string.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string 's' containing uppercase and lowercase English letters and digits.
- **Example:** `"banana"`
- **Constraints:**
	- 1 <= s.length <= 5 * 10^5
	- s consists of uppercase and lowercase English letters and digits.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a string where the characters are sorted in decreasing order based on their frequency. Characters with higher frequencies should appear first in the string.
- **Example:** `"aaannb"`
- **Constraints:**
	- The output should be a valid sorted string based on character frequency.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to sort the string based on the frequency of characters in decreasing order.

- 1. Count the frequency of each character in the string.
- 2. Group the characters based on their frequencies.
- 3. Sort the characters in descending order of frequency.
- 4. Construct the resulting string based on the sorted frequencies.
{{< dots >}}
### Problem Assumptions ✅
- The input string contains English letters and digits.
- The length of the string is manageable within the given constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `"banana"`  \
  **Explanation:** The character 'a' appears 3 times, 'n' appears 2 times, and 'b' appears once. So the result must have 'a' repeated 3 times, 'n' repeated 2 times, and 'b' once.

- **Input:** `"abcd"`  \
  **Explanation:** Since all characters appear exactly once, the output can be in any order.

- **Input:** `"apple"`  \
  **Explanation:** 'p' appears twice, 'a' and 'l' appear once. The correct answer could be 'ppale' or 'pplea'.

{{< dots >}}
## Approach 🚀
We will first calculate the frequency of each character in the string. Then we will group the characters by their frequencies and sort them in descending order. Finally, we will concatenate the characters based on their sorted frequencies to form the resulting string.

### Initial Thoughts 💭
- We need to count the frequency of characters efficiently.
- We will need a way to group characters by their frequencies.
- Using a hash map to count frequencies and a bucket sort approach to group characters by frequency would be an efficient solution.
{{< dots >}}
### Edge Cases 🌐
- Handle the case where the string is empty (although the constraints ensure this won't happen).
- The solution should efficiently handle strings of length up to 5 * 10^5.
- Ensure that both lowercase and uppercase letters are handled distinctly.
- The algorithm must perform efficiently within the time and space constraints.
{{< dots >}}
## Code 💻
```cpp
string frequencySort(string s) {
    unordered_map<char,int> freq;
    vector<string> bucket(s.size()+1, "");
    string res;
    
    //count frequency of each character
    for(char c:s) freq[c]++;
    //put character into frequency bucket
    for(auto& it:freq) {
        int n = it.second;
        char c = it.first;
        bucket[n].append(n, c);
    }
    //form descending sorted string
    for(int i=s.size(); i>0; i--) {
        if(bucket[i].size())
            res.append(bucket[i]);
    }
    return res;
}
```

This function sorts the characters of the string based on their frequencies in descending order. It uses a frequency map and a bucket sort approach to achieve the sorting.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string frequencySort(string s) {
	```
	The `frequencySort` function takes a string `s` as input and returns a string sorted by the frequency of characters in descending order.

2. **Variable Declaration**
	```cpp
	    unordered_map<char,int> freq;
	```
	Declares an unordered map `freq` to store the frequency of each character in the string.

3. **Bucket Initialization**
	```cpp
	    vector<string> bucket(s.size()+1, "");
	```
	Creates a vector of strings `bucket`, with size equal to `s.size() + 1`, to group characters by their frequencies.

4. **Result Variable**
	```cpp
	    string res;
	```
	Declares a string `res` to store the final sorted result.

5. **Frequency Count Loop**
	```cpp
	    for(char c:s) freq[c]++;
	```
	Loops through each character in the string `s` and increments its corresponding count in the `freq` map.

6. **Bucket Sorting Loop**
	```cpp
	    for(auto& it:freq) {
	```
	Loops through the `freq` map to process each character-frequency pair.

7. **Character Frequency**
	```cpp
	        int n = it.second;
	```
	Extracts the frequency `n` of the character `it.first` from the `freq` map.

8. **Character Assignment**
	```cpp
	        char c = it.first;
	```
	Extracts the character `c` from the `freq` map.

9. **Bucket Update**
	```cpp
	        bucket[n].append(n, c);
	```
	Appends the character `c` `n` times to the `bucket[n]` string.

10. **End Bucket Loop**
	```cpp
	    }
	```
	End of the loop that places characters into their respective frequency buckets.

11. **Descending Bucket Loop**
	```cpp
	    for(int i=s.size(); i>0; i--) {
	```
	Loops through the `bucket` vector in descending order of frequency (from highest to lowest).

12. **Bucket Size Check**
	```cpp
	        if(bucket[i].size())
	```
	Checks if there are any characters in the `bucket[i]` (i.e., if the bucket for this frequency is non-empty).

13. **Result Update**
	```cpp
	            res.append(bucket[i]);
	```
	Appends the characters in `bucket[i]` to the result string `res`.

14. **Return Statement**
	```cpp
	    return res;
	```
	Returns the result string `res`, which contains the characters sorted by frequency in descending order.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n + k log k)
- **Average Case:** O(n + k log k)
- **Worst Case:** O(n + k log k)

The time complexity is dominated by the sorting step, which is O(k log k), where k is the number of unique characters. Counting frequencies takes O(n), where n is the length of the string.

### Space Complexity 💾
- **Best Case:** O(n + k)
- **Worst Case:** O(n + k)

Space complexity is O(n + k), where n is the length of the string and k is the number of unique characters due to the hash map and the bucket array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/sort-characters-by-frequency/description/)

---
{{< youtube JTdpTHaGQoA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
