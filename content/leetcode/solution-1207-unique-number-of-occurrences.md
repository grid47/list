
+++
authors = ["grid47"]
title = "Leetcode 1207: Unique Number of Occurrences"
date = "2024-07-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1207: Unique Number of Occurrences in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "_NYimlZY1PE"
youtube_upload_date="2019-12-06"
youtube_thumbnail="https://i.ytimg.com/vi_webp/_NYimlZY1PE/maxresdefault.webp"
comments = true
+++



---
Given an array of integers arr, return true if the number of occurrences of each value in the array is unique, and return false otherwise.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array arr of integers.
- **Example:** `Input: arr = [5,6,6,5,5,7]`
- **Constraints:**
	- 1 <= arr.length <= 1000
	- -1000 <= arr[i] <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if the number of occurrences of each value in the array is unique, otherwise return false.
- **Example:** `Output: true`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine if all frequency counts in the array are unique.

- Count the occurrences of each number in the array.
- Store the frequency of each number.
- Check if all frequency counts are unique.
{{< dots >}}
### Problem Assumptions ✅
- It is assumed that the input array is not empty, as the constraints guarantee at least one element.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: arr = [5,6,6,5,5,7]`  \
  **Explanation:** The number 5 occurs 3 times, 6 occurs 2 times, and 7 occurs once. These frequencies are distinct.

- **Input:** `Input: arr = [4,5]`  \
  **Explanation:** Both 4 and 5 occur once, so the counts are not unique.

- **Input:** `Input: arr = [0,1,2,0,1,2,2]`  \
  **Explanation:** The number 0 occurs twice, 1 occurs twice, and 2 occurs three times. These frequencies are distinct.

{{< dots >}}
## Approach 🚀
The approach is to count the occurrences of each number in the array, store those counts, and then check if the counts are unique.

### Initial Thoughts 💭
- We need to count occurrences of each element in the array.
- A hash map can be used to store the frequencies of the elements.
- We will use a frequency counter, then check for duplicates among the counts.
{{< dots >}}
### Edge Cases 🌐
- An empty array will not be valid according to the problem's constraints.
- Ensure that the solution works for large input arrays with up to 1000 elements.
- Handle cases where all elements have the same frequency.
- The array is guaranteed to have at least one element.
{{< dots >}}
## Code 💻
```cpp
bool uniqueOccurrences(vector<int>& arr) {
    int i = 0;
    sort(arr.begin(),arr.end());
    vector<int> ans;
    while (i < arr.size()){
        int count = 1;
        for (int j = i+1; j< arr.size(); j++){
            if (arr[i] == arr[j])
                count++;
        }
        ans.push_back(count);
        i = i + count;
    }
    sort(ans.begin(),ans.end());
    for (int i = 0; i < ans.size() - 1; i++){
        if (ans[i] == ans [i+1])
            return false;
    }
    return true;        
}
```

This function checks if the occurrences of each element in the input array `arr` are unique. It counts the frequency of each element and then checks if all the frequencies are distinct.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool uniqueOccurrences(vector<int>& arr) {
	```
	Define the function `uniqueOccurrences` which takes a vector `arr` and returns a boolean indicating whether all elements in `arr` have unique occurrences.

2. **Variable Initialization**
	```cpp
	    int i = 0;
	```
	Initialize the variable `i` to 0, which will be used to iterate through the array.

3. **Sorting**
	```cpp
	    sort(arr.begin(),arr.end());
	```
	Sort the array `arr` in non-decreasing order so that identical elements are adjacent to each other.

4. **Vector Initialization**
	```cpp
	    vector<int> ans;
	```
	Initialize an empty vector `ans` to store the frequency counts of each unique element in the array.

5. **While Loop**
	```cpp
	    while (i < arr.size()){
	```
	Start a while loop that will iterate through the array, processing each element.

6. **Frequency Count Initialization**
	```cpp
	        int count = 1;
	```
	Initialize the variable `count` to 1, which will track the number of occurrences of the current element.

7. **Nested Loop for Frequency Count**
	```cpp
	        for (int j = i+1; j< arr.size(); j++){
	```
	Start a nested for loop to count the occurrences of the current element starting from index `i`.

8. **Comparison of Adjacent Elements**
	```cpp
	            if (arr[i] == arr[j])
	```
	Check if the element at index `i` is equal to the element at index `j`.

9. **Increment Count**
	```cpp
	                count++;
	```
	If the elements are equal, increment the `count` to track the frequency of the element.

10. **Store Frequency Count**
	```cpp
	        ans.push_back(count);
	```
	Push the current frequency count `count` into the vector `ans`.

11. **Update Index**
	```cpp
	        i = i + count;
	```
	Update the value of `i` to skip over the elements that have been counted, moving to the next unique element.

12. **Sorting Frequencies**
	```cpp
	    sort(ans.begin(),ans.end());
	```
	Sort the frequency counts in the vector `ans` to compare adjacent frequencies.

13. **Loop to Compare Frequencies**
	```cpp
	    for (int i = 0; i < ans.size() - 1; i++){
	```
	Start a loop to compare adjacent elements in the sorted frequency vector `ans`.

14. **Check for Duplicates**
	```cpp
	        if (ans[i] == ans [i+1])
	```
	Check if two adjacent frequency counts are equal, indicating that a frequency is not unique.

15. **Return False for Duplicates**
	```cpp
	            return false;
	```
	If duplicate frequencies are found, return `false` to indicate that the occurrences are not unique.

16. **Return True**
	```cpp
	    return true;        
	```
	Return `true` if all frequencies are unique, meaning that no two elements in the array have the same occurrence count.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The counting operation is O(n), and checking for duplicates among counts requires sorting, which takes O(n log n).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space required for the hash map and frequency list.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/unique-number-of-occurrences/description/)

---
{{< youtube _NYimlZY1PE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
