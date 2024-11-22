
+++
authors = ["grid47"]
title = "Leetcode 2592: Maximize Greatness of an Array"
date = "2024-02-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2592: Maximize Greatness of an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "p1njSkWtg2U"
youtube_upload_date="2023-03-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/p1njSkWtg2U/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        // 1 1 1 2 3 3 5
        sort(nums.begin(), nums.end());
        int n = nums.size();
        map<int, int> pos;
        pos[-1] = -1;
        for(int i = 0; i < n; i++) {
            auto it = upper_bound(nums.begin() + pos[i - 1] + 1, nums.end(), nums[i]);
            if(it == nums.end()) break;
            int idx = it - nums.begin();
            pos[i] = idx;
            if(idx == n - 1) break;
        }
        return pos.size() - 1;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to maximize the greatness of an array by rearranging its elements. Specifically, for a given array, the greatness is defined as the number of pairs of indices `(i, j)` such that `i < j` and `nums[i] < nums[j]` after rearranging the array. Our task is to determine how to arrange the elements in such a way that the number of valid pairs is maximized.

### Approach

To maximize the number of valid pairs, we need to rearrange the elements such that for each index `i`, the value `nums[i]` is less than some `nums[j]` where `j > i`. The key observation is that sorting the array first allows us to compare each element against its potential future positions in the array. By keeping track of the positions in the sorted array, we can determine how many valid pairs we can form while maintaining a running check on the order of the elements.

The approach works by iterating through the sorted array and using a `map` to track the positions where elements can be placed, ensuring that we always try to place each element in a position where it forms the maximum number of valid pairs.

### Code Breakdown

#### Step 1: Sorting the Array
```cpp
sort(nums.begin(), nums.end());
```
- The first step is to sort the given array. Sorting the array helps in efficiently identifying valid pairs because if `nums[i] < nums[j]` and `i < j`, then after sorting the array, this relationship will naturally hold. Sorting ensures that each element has potential greater elements available later in the array, which is crucial for maximizing the number of valid pairs.

#### Step 2: Initializing the Tracking Map
```cpp
map<int, int> pos;
pos[-1] = -1;
```
- A `map` named `pos` is initialized. This map is used to keep track of the valid indices in the sorted array. The map stores the index of the last placed element, and its key represents the position in the original array from where the element was placed. The initialization of `pos[-1] = -1` ensures that the first comparison will always succeed. It represents the last placed index before the first element in the sorted array.

#### Step 3: Iterating Over the Sorted Array
```cpp
for(int i = 0; i < n; i++) {
    auto it = upper_bound(nums.begin() + pos[i - 1] + 1, nums.end(), nums[i]);
    if(it == nums.end()) break;
    int idx = it - nums.begin();
    pos[i] = idx;
    if(idx == n - 1) break;
}
```
- **Iteration**: The loop iterates through each element `i` of the sorted array `nums`. For each element, the function attempts to find the first element greater than `nums[i]` that comes after the position of the previously placed element.
- **Upper Bound Search**: `upper_bound(nums.begin() + pos[i - 1] + 1, nums.end(), nums[i])` is used to find the first element that is greater than `nums[i]`. The `upper_bound` function performs a binary search and returns an iterator pointing to the first element in the range that is strictly greater than `nums[i]`. This ensures that we are always considering valid pairs.
- **Break Condition**: If no valid element is found (`it == nums.end()`), we break out of the loop because further pairs cannot be formed.
- **Position Update**: If a valid element is found, we calculate the index `idx` of this element and store it in the map `pos`. The map keeps track of the positions where elements are placed so that the next elements can be compared against the correct positions.
- **Termination Condition**: If we reach the last element (`idx == n - 1`), we stop, as we have exhausted all valid pairs that can be formed.

#### Step 4: Return the Result
```cpp
return pos.size() - 1;
```
- After the loop, the size of the map `pos` represents the number of valid elements that have been placed in positions where they can form valid pairs. We subtract 1 from this value because the initial entry `pos[-1] = -1` does not count as a valid placement.

### Example Walkthrough

#### Input:
```cpp
vector<int> nums = {1, 3, 5, 2, 1, 3};
```
1. **Sort the Array**: The first step is to sort the array.
   - Sorted array: `[1, 1, 2, 3, 3, 5]`
   
2. **Initialization**:
   - `pos[-1] = -1`: Initializing the map to track positions.
   
3. **First Iteration (i = 0)**:
   - We look for the first element greater than `nums[0] = 1`. Using `upper_bound`, we find that the first element greater than 1 is `2`, at index 2.
   - Update map: `pos[0] = 2`.

4. **Second Iteration (i = 1)**:
   - We look for the first element greater than `nums[1] = 1` starting from index 3. The first element greater than 1 is `2`, at index 2.
   - Since the element is already placed at index 2, we continue to the next index and find the next available greater element at index 3 (`3`).
   - Update map: `pos[1] = 3`.

5. **Continue the Iteration**:
   - We repeat the process for each element, trying to place it in a valid position where it forms the maximum number of valid pairs. Eventually, the valid placements are determined for each element.

6. **Final Result**:
   - The final result, after processing all elements, is the size of the `pos` map minus 1, which represents the total number of valid placements.

#### Output:
```cpp
return 4;  // The maximum number of valid pairs is 4.
```

### Time Complexity

- **Time Complexity**: \(O(n \log n)\)
  - The sorting of the array takes \(O(n \log n)\).
  - For each element, we perform a binary search (`upper_bound`) which takes \(O(\log n)\), and we do this for all \(n\) elements. Therefore, the overall time complexity is \(O(n \log n)\).

### Space Complexity

- **Space Complexity**: \(O(n)\)
  - The map `pos` stores the positions of each element, requiring \(O(n)\) space. Additionally, the sorted array requires \(O(n)\) space.

### Conclusion

This solution efficiently maximizes the number of valid pairs by sorting the array and using a binary search approach to find the optimal placements of elements. By leveraging the properties of sorted arrays and maintaining a map to track valid positions, the solution ensures that the greatest number of valid pairs is formed. The algorithm runs in \(O(n \log n)\) time, making it suitable for handling larger inputs within acceptable time limits.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximize-greatness-of-an-array/description/)

---
{{< youtube p1njSkWtg2U >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
