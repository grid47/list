
+++
authors = ["grid47"]
title = "Leetcode 2148: Count Elements With Strictly Smaller and Greater Elements "
date = "2024-04-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2148: Count Elements With Strictly Smaller and Greater Elements  in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "V3SamYLfPtg"
youtube_upload_date="2022-01-23"
youtube_thumbnail="https://i.ytimg.com/vi_webp/V3SamYLfPtg/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0, l = -1, r = -1, n = nums.size();
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i - 1]) {
              l = i;
              break;
            }
        }
        for(int i = n - 1; i > 0; i--) {
            if(nums[i] > nums[i - 1]) {
              r = i;
              break;
            }
        }
        if(l < r) return r - l;
        return 0;
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to count the number of elements in an array that are strictly between the minimum and maximum values of that array. In other words, we need to identify all elements that are greater than the minimum element and less than the maximum element. If there are no such elements, the function should return `0`.

### Approach

To solve this problem, we can break down the approach into the following steps:

1. **Sort the Array**: First, sort the input array. This allows us to easily identify the minimum and maximum values and to find elements that lie strictly between them.

2. **Identify the Left and Right Indices**: Traverse the sorted array to find the first element that is greater than the minimum and the last element that is less than the maximum. This will help in determining the range of elements that lie strictly between the minimum and maximum.

3. **Count Elements**: If we have found valid indices, the count of elements between the minimum and maximum can be computed by subtracting these indices. If no such indices are found, return `0`.

4. **Return the Result**: Finally, return the calculated count of elements that meet the criteria.

### Code Breakdown (Step by Step)

1. **Function Definition**:
   ```cpp
   int countElements(vector<int>& nums) {
   ```
   - The function `countElements` takes a vector of integers `nums` as input.

2. **Sorting the Array**:
   ```cpp
   sort(nums.begin(), nums.end());
   ```
   - We use the `sort` function to sort the elements of the array in non-decreasing order. This is crucial as it allows us to easily identify the minimum and maximum values and the elements between them.

3. **Variable Initialization**:
   ```cpp
   int res = 0, l = -1, r = -1, n = nums.size();
   ```
   - Here, we initialize `res` to `0`, which will hold the final count of elements. The variables `l` and `r` are initialized to `-1` to indicate that we have not found any valid indices yet. The variable `n` holds the size of the array.

4. **Finding the Left Index**:
   ```cpp
   for(int i = 1; i < n; i++) {
       if(nums[i] > nums[i - 1]) {
           l = i;
           break;
       }
   }
   ```
   - We iterate through the sorted array starting from the second element (index `1`). The goal is to find the first index `l` where an element is greater than its predecessor, indicating that it is greater than the minimum value. Once found, we break out of the loop.

5. **Finding the Right Index**:
   ```cpp
   for(int i = n - 1; i > 0; i--) {
       if(nums[i] > nums[i - 1]) {
           r = i;
           break;
       }
   }
   ```
   - This loop runs from the end of the array back to the first element, looking for the last index `r` where an element is greater than its predecessor, indicating it is less than the maximum value. Again, we break out of the loop once we find this index.

6. **Counting Elements**:
   ```cpp
   if(l < r) return r - l;
   return 0;
   ```
   - If `l` is less than `r`, it means we have valid indices, and the count of elements between the minimum and maximum is calculated as `r - l`. This expression effectively counts the elements that lie strictly between the two indices. If no such indices exist (i.e., all elements are the same or there's only one unique value), we return `0`.

7. **Function Return**:
   ```cpp
   }
   ```
   - The function ends, returning the count of elements found.

### Complexity Analysis

- **Time Complexity**: \(O(n \log n)\)
  - The most time-consuming operation in this solution is sorting the array, which has a time complexity of \(O(n \log n)\). The subsequent operations to find the left and right indices only require linear scans, resulting in an overall time complexity dominated by the sorting step.

- **Space Complexity**: \(O(1)\)
  - We are using a constant amount of space for our variables (`res`, `l`, `r`, `n`). The sorting operation may use additional space in terms of internal handling, but since we're only using a few variables, we can consider the space complexity as \(O(1)\) in terms of our own usage.

### Conclusion

The `countElements` function provides an efficient means to count the number of elements in a list that are strictly between the smallest and largest values. By leveraging sorting, we can quickly identify these boundaries and effectively calculate the required count.

This solution exemplifies fundamental algorithm design techniques, such as sorting and linear traversal, which are commonly employed in array manipulation problems. Understanding this method equips developers with essential skills for tackling similar problems in various programming contexts, reinforcing the importance of combining algorithmic efficiency with clear logic. The function not only achieves its purpose with clarity but also adheres to optimal performance standards, making it an exemplary implementation in competitive programming and coding interviews.

[`Link to LeetCode Lab`](https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/description/)

---
{{< youtube V3SamYLfPtg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
