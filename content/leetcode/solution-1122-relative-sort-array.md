
+++
authors = ["grid47"]
title = "Leetcode 1122: Relative Sort Array"
date = "2024-07-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1122: Relative Sort Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting","Counting Sort"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "OPvcR1e4lfg"
youtube_upload_date="2024-06-11"
youtube_thumbnail="https://i.ytimg.com/vi/OPvcR1e4lfg/maxresdefault.jpg"
comments = true
+++



---
You are given two arrays: `arr1` and `arr2`. The elements of `arr2` are distinct, and all elements in `arr2` exist in `arr1`. The task is to sort the elements of `arr1` such that the relative ordering of elements in `arr1` matches the order of elements in `arr2`. Elements in `arr1` that are not present in `arr2` should be placed at the end of `arr1` in ascending order.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two integer arrays, `arr1` and `arr2`. The length of `arr1` and `arr2` can range from 1 to 1000, and all elements in `arr2` are distinct and exist in `arr1`.
- **Example:** `Input: arr1 = [5, 6, 1, 3, 9, 1, 7], arr2 = [3, 1, 7]`
- **Constraints:**
	- 1 <= arr1.length, arr2.length <= 1000
	- 0 <= arr1[i], arr2[i] <= 1000
	- All elements of arr2 are distinct.
	- Each element of arr2 is present in arr1.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be an array where the elements in `arr1` are sorted such that the relative order of elements from `arr2` is preserved, and elements not in `arr2` appear at the end of the array in ascending order.
- **Example:** `Output: [3, 1, 7, 5, 6, 9]`
- **Constraints:**
	- The elements in arr1 should be sorted in the specified order as per arr2.

{{< dots >}}
### Core Logic 🔍
**Goal:** Sort the elements of `arr1` based on their position in `arr2`, and place the remaining elements at the end in ascending order.

- Create a mapping for the elements in `arr2` to track their order.
- Sort the elements of `arr1` by using this mapping to prioritize the order of `arr2` elements.
- For elements not in `arr2`, sort them in ascending order and append them at the end of the array.
{{< dots >}}
### Problem Assumptions ✅
- Each element of `arr2` exists at least once in `arr1`.
- Elements of `arr1` that are not present in `arr2` should be sorted and placed at the end.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: arr1 = [4, 3, 1, 2], arr2 = [3, 1]`  \
  **Explanation:** In this case, the output should be `[3, 1, 2, 4]` because the order of elements in `arr1` matching `arr2` (3 first, then 1) is preserved, and the remaining elements (2, 4) are placed at the end in ascending order.

- **Input:** `Input: arr1 = [10, 5, 7, 6], arr2 = [5, 6]`  \
  **Explanation:** The output should be `[5, 6, 7, 10]` as `arr1` elements in `arr2` (5, 6) are placed first, and the remaining elements (7, 10) are sorted and placed at the end.

{{< dots >}}
## Approach 🚀
The approach is to first create a mapping of the order of elements in `arr2`, then sort `arr1` such that elements in `arr2` come first. Elements in `arr1` that are not in `arr2` will be sorted and appended at the end.

### Initial Thoughts 💭
- The order of elements in `arr1` should respect the order specified in `arr2`.
- By creating a mapping for `arr2`, we can sort `arr1` accordingly and handle the remaining elements by sorting them in ascending order.
{{< dots >}}
### Edge Cases 🌐
- If either `arr1` or `arr2` is empty, return an empty array.
- The solution should efficiently handle arrays of size up to 1000.
- If all elements in `arr1` are already in `arr2`, the output should be exactly the same as `arr2`.
- The solution must ensure that sorting is done in linear time for the elements that are in `arr2`, and the remaining elements are sorted in ascending order.
{{< dots >}}
## Code 💻
```cpp
vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    int n1=arr1.size(), n2=arr2.size();
    int a2i[1001];

    fill(a2i, end(a2i), n2);
    for(int i=0; i<n2; i++)
        a2i[arr2[i]]=i;

    sort(arr1.begin(), arr1.end(), [&](int x, int y){
        if (a2i[x]==a2i[y]) return x<y;
        return a2i[x]<a2i[y];
    });
    return arr1;
}
```

This code defines the function `relativeSortArray`, which sorts `arr1` based on the order of elements in `arr2` and places remaining elements of `arr1` in ascending order. The function first creates an index array `a2i` to map elements in `arr2` to their respective indices, then uses this mapping to customize the sorting logic in `arr1`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
	```
	Declares the function `relativeSortArray` that takes two input arrays, `arr1` and `arr2`, and returns a sorted `arr1` based on the order defined by `arr2`.

2. **Variable Initialization**
	```cpp
	    int n1=arr1.size(), n2=arr2.size();
	```
	Initializes variables `n1` and `n2` to store the sizes of `arr1` and `arr2` respectively.

3. **Array Declaration**
	```cpp
	    int a2i[1001];
	```
	Declares an integer array `a2i` with 1001 elements, which will be used to map the values in `arr2` to their respective indices.

4. **Initialization**
	```cpp
	
	```
	This section is left empty to highlight initialization steps done later in the code.

5. **Array Initialization**
	```cpp
	    fill(a2i, end(a2i), n2);
	```
	Fills the entire `a2i` array with the value `n2` (the size of `arr2`), which ensures that elements not present in `arr2` will be considered as the largest value during sorting.

6. **Loop**
	```cpp
	    for(int i=0; i<n2; i++)
	```
	Begins a loop over `arr2` to populate the `a2i` array with the correct indices for each element in `arr2`.

7. **Array Mapping**
	```cpp
	        a2i[arr2[i]]=i;
	```
	Maps each element `arr2[i]` to its index `i` in the `a2i` array. This will help to sort the elements of `arr1` based on their index in `arr2`.

8. **Sorting Function**
	```cpp
	
	```
	This section is left empty to emphasize the use of sorting functions to arrange the elements of `arr1`.

9. **Sorting Logic**
	```cpp
	    sort(arr1.begin(), arr1.end(), [&](int x, int y){
	```
	Begins the sorting of `arr1` using a custom comparator function that compares elements based on their positions in `arr2`.

10. **Comparison Logic**
	```cpp
	        if (a2i[x]==a2i[y]) return x<y;
	```
	If two elements `x` and `y` from `arr1` have the same index in `arr2`, they are compared using their natural order (`x < y`).

11. **Comparison Logic**
	```cpp
	        return a2i[x]<a2i[y];
	```
	If two elements `x` and `y` from `arr1` have different indices in `arr2`, they are compared based on the order defined by their indices in `arr2`.

12. **End Sorting**
	```cpp
	    });
	```
	Ends the custom sorting function, applying the comparator to the entire `arr1`.

13. **Return Statement**
	```cpp
	    return arr1;
	```
	Returns the sorted `arr1` array, which is now ordered according to the positions of its elements in `arr2` and any remaining elements sorted in ascending order.

14. **Function End**
	```cpp
	}
	```
	Marks the end of the `relativeSortArray` function.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting operations. Sorting `arr1` based on the order from `arr2` takes O(n log n), where `n` is the size of `arr1`.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the extra space used for storing the mapping of `arr2` and sorting elements.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/relative-sort-array/description/)

---
{{< youtube OPvcR1e4lfg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
