
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---


### Problem Statement
The task is to determine if the number of occurrences of each element in an integer array is unique. Given an array of integers, we need to check if every integer appears a different number of times. For example, in the array `[1, 2, 2, 1, 1, 3]`, the integer `1` occurs three times, `2` occurs twice, and `3` occurs once. Since the counts (3, 2, and 1) are unique, the result should be `true`. Conversely, in the array `[1, 2]`, both integers occur once, leading to a result of `false`.

### Approach
To solve this problem, we will:
1. **Sort the Input Array**: This helps in grouping identical integers together, allowing for easier counting of occurrences.
2. **Count Occurrences**: Iterate through the sorted array to count how many times each integer appears.
3. **Store Counts**: Use a separate vector to store these counts of occurrences.
4. **Check Uniqueness**: After collecting the counts, we will sort this vector and check if any counts are repeated.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int i = 0;
        sort(arr.begin(), arr.end());
        vector<int> ans;
```
- **Lines 1-4**: The function starts by defining the class `Solution` and its method `uniqueOccurrences`. It accepts a vector of integers `arr`. We initialize an index `i` to zero and sort the array to facilitate the counting of occurrences.

```cpp
        while (i < arr.size()){
            int count = 1;
            for (int j = i + 1; j < arr.size(); j++){
                if (arr[i] == arr[j])
                    count++;
            }
            ans.push_back(count);
            i = i + count;
        }
```
- **Lines 5-12**: A `while` loop is used to iterate through the sorted array. The outer loop runs as long as `i` is less than the size of the array. Inside, we initialize a `count` variable to track the number of occurrences of the current element:
  - The inner `for` loop starts from the next position after `i` and counts how many times the current element `arr[i]` appears in the array.
  - Once counting is done, we push the count into the `ans` vector and update `i` to skip over all occurrences of the counted number.

```cpp
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size() - 1; i++){
            if (ans[i] == ans[i + 1])
                return false;
        }
```
- **Lines 13-18**: After counting, we sort the `ans` vector, which now contains the counts of each unique element:
  - We then iterate through the `ans` vector to check for duplicates. If any two consecutive counts are the same, we return `false`.

```cpp
        return true;        
    }
};
```
- **Lines 19-21**: If no duplicates were found in the counts, the function returns `true`, indicating that all occurrence counts are unique.

### Complexity
1. **Time Complexity**:
   - Sorting the input array takes \(O(n \log n)\), where \(n\) is the number of elements in `arr`. The counting process is \(O(n)\), and sorting the counts vector is \(O(m \log m)\), where \(m\) is the number of unique elements in `arr`. Thus, the overall time complexity is dominated by the sorting step, yielding an effective complexity of \(O(n \log n)\).

2. **Space Complexity**:
   - We use an additional vector `ans` to store the counts of occurrences, which in the worst case can be as large as the number of elements in `arr`. Thus, the space complexity is \(O(n)\).

### Conclusion
The `uniqueOccurrences` function effectively determines whether the counts of occurrences of integers in an array are unique by leveraging sorting and careful counting. This approach is straightforward and efficient, making it suitable for a wide range of input sizes. The use of sorting to group identical elements simplifies the counting process, while sorting the counts ensures an efficient way to check for uniqueness. Overall, this solution highlights the utility of classic algorithms in solving combinatorial problems, providing both clarity and efficiency in implementation.

[`Link to LeetCode Lab`](https://leetcode.com/problems/unique-number-of-occurrences/description/)

---
{{< youtube _NYimlZY1PE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
