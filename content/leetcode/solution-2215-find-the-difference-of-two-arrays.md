
+++
authors = ["grid47"]
title = "Leetcode 2215: Find the Difference of Two Arrays"
date = "2024-03-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2215: Find the Difference of Two Arrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "oypp_RzI69w"
youtube_upload_date="2023-05-03"
youtube_thumbnail="https://i.ytimg.com/vi/oypp_RzI69w/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        set<int> s1, s2;
        for(int i = 0; i < nums1.size(); i++) {
            s1.insert(nums1[i]);
        }
        for(int i = 0; i < nums2.size(); i++) {
            s2.insert(nums2[i]);
        }
        for(int x: s1) {
            if(!s2.count(x))
                ans[0].push_back(x);
        }
        for(int x: s2) {
            if(!s1.count(x))
                ans[1].push_back(x);
        }        
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks for the difference between two arrays, `nums1` and `nums2`, where the difference is defined as elements that are present in one array but not the other. Specifically, the task is to return a list of two arrays:
1. The first array contains elements that are present in `nums1` but not in `nums2`.
2. The second array contains elements that are present in `nums2` but not in `nums1`.

The output should return the two lists in the order: `[unique to nums1, unique to nums2]`.

### Approach

This problem can be efficiently solved using **sets** due to their property of storing unique elements and providing fast operations to check for existence. The key idea is to:
1. **Convert the arrays to sets** to eliminate duplicates and enable fast membership checking.
2. **Iterate through the elements** of each set and check whether they exist in the other set.
3. **Populate the result arrays** with the unique elements found in each array.

### Detailed Steps

1. **Use Sets for Uniqueness**:
   - Since the arrays may contain duplicates, converting them to sets will help eliminate those duplicates and allow for efficient membership testing.
   
2. **Find the Unique Elements**:
   - For each set, we check whether an element is present in the other set.
   - If an element in `nums1` is not present in `nums2`, it will be added to the first result list.
   - Similarly, if an element in `nums2` is not present in `nums1`, it will be added to the second result list.

3. **Return the Result**:
   - Finally, we return the two result arrays: one for elements unique to `nums1` and one for elements unique to `nums2`.

### Code Breakdown (Step by Step)

#### Step 1: Initialize the Result Arrays and Sets
```cpp
vector<vector<int>> ans(2);
set<int> s1, s2;
```
- `ans` is a 2D vector that will store the final result: `ans[0]` will store elements unique to `nums1`, and `ans[1]` will store elements unique to `nums2`.
- `s1` and `s2` are sets that will hold the unique elements from `nums1` and `nums2` respectively.

#### Step 2: Populate the Sets with Elements from the Arrays
```cpp
for(int i = 0; i < nums1.size(); i++) {
    s1.insert(nums1[i]);
}
for(int i = 0; i < nums2.size(); i++) {
    s2.insert(nums2[i]);
}
```
- We iterate over each array and insert its elements into the corresponding set (`s1` for `nums1` and `s2` for `nums2`).
- Inserting into a set automatically handles duplicates because sets only store unique elements.

#### Step 3: Identify Elements Unique to `nums1`
```cpp
for(int x: s1) {
    if(!s2.count(x))
        ans[0].push_back(x);
}
```
- We iterate through each element `x` in set `s1`.
- For each element, we check if it is not present in set `s2` using `s2.count(x)`. The `count` function returns `0` if the element is not in the set, and `1` if it is present.
- If the element is not in `s2`, it is unique to `nums1`, so we add it to `ans[0]`.

#### Step 4: Identify Elements Unique to `nums2`
```cpp
for(int x: s2) {
    if(!s1.count(x))
        ans[1].push_back(x);
}
```
- Similarly, we iterate through each element `x` in set `s2` and check if it is not present in set `s1`.
- If the element is unique to `nums2`, it is added to `ans[1]`.

#### Step 5: Return the Final Result
```cpp
return ans;
```
- Finally, the method returns the `ans` array, which contains the two lists:
  - `ans[0]` for elements unique to `nums1`,
  - `ans[1]` for elements unique to `nums2`.

### Complexity Analysis

#### Time Complexity:
- **O(n + m)**, where `n` and `m` are the lengths of `nums1` and `nums2`, respectively.
  - Converting `nums1` and `nums2` into sets takes O(n) and O(m) time.
  - Checking if an element is present in a set (using `count`) takes O(1) on average, and we perform this operation for all elements in both sets.
  - The overall time complexity is O(n + m), making this approach very efficient for larger input sizes.

#### Space Complexity:
- **O(n + m)**, because we store the unique elements from both arrays in two sets (`s1` and `s2`).
  - The space complexity is linear in terms of the total number of unique elements across both arrays.

### Conclusion

This solution efficiently computes the difference between two arrays, `nums1` and `nums2`, using sets. By leveraging the properties of sets—automatic handling of duplicates and fast membership checks—we can solve the problem with a time complexity of O(n + m), where `n` and `m` are the lengths of the input arrays. This approach is not only optimal but also clean and easy to implement.

The solution is highly efficient for large inputs, as it processes the arrays in linear time with respect to their size. The space complexity is also linear, as we only store the unique elements from both arrays. This makes the solution scalable and well-suited for competitive programming or real-world applications where performance is crucial.

In conclusion, the approach using sets for this problem is a perfect fit due to its simplicity, efficiency, and clarity. It ensures that we can handle the task of finding the difference between two arrays in an optimal manner.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-difference-of-two-arrays/description/)

---
{{< youtube oypp_RzI69w >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
