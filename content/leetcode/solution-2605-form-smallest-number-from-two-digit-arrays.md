
+++
authors = ["grid47"]
title = "Leetcode 2605: Form Smallest Number From Two Digit Arrays"
date = "2024-02-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2605: Form Smallest Number From Two Digit Arrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Enumeration"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "ZlVNO8BFBCY"
youtube_upload_date="2023-04-01"
youtube_thumbnail="https://i.ytimg.com/vi_webp/ZlVNO8BFBCY/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int num1 = nums1[0];
        set<int> cnt;
        int mn = 10;

        for(int i = 0; i < nums1.size(); i++) {
            cnt.insert(nums1[i]);
            num1 = min(nums1[i], num1);
        }
        
        int num2 = nums2[0];
        for(int i = 0; i < nums2.size(); i++) {
            if(cnt.count(nums2[i])) {
                mn = min(mn, nums2[i]);
            };
            num2 = min(nums2[i], num2);
        }
        if(mn < 10) return mn;
        if(num1 < num2) {
            return num1 * 10 + num2;
        } else {
            return num2 * 10 + num1;            
        }
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires finding the minimum possible number formed by selecting one element from each of two arrays, `nums1` and `nums2`. The task is to select one element from `nums1` and one element from `nums2` such that the resulting number is minimized. The number can either be formed by selecting two different numbers, or by selecting a common number if available in both arrays. If there is no common element between the two arrays, the result should be the smallest possible number formed by selecting one element from each array.

### Approach

The strategy is as follows:
1. **Track the smallest elements in both arrays**: The approach starts by determining the smallest element in `nums1` and `nums2`.
2. **Check for common elements**: If there are any common elements between `nums1` and `nums2`, we can form the smallest possible number by using one of these common elements.
3. **Form the smallest number**: If there are common elements, the minimum common element will form the smallest number. If no common element exists, we will form the number by choosing the smallest number from each array and combining them in a way that results in the smallest two-digit number.
4. **Edge handling**: The edge case where there is no common element will involve combining the smallest elements of both arrays in a way that minimizes the result.

### Code Breakdown (Step by Step)

#### 1. **Initialization**:
   ```cpp
   int num1 = nums1[0];
   set<int> cnt;
   int mn = 10;
   ```
   - `num1` stores the smallest number found in `nums1`. Initially, it is set to the first element of `nums1`.
   - `cnt` is a set that is used to store all the elements of `nums1`. This helps in quickly checking if any element of `nums2` exists in `nums1`.
   - `mn` is initialized to 10, which is greater than any valid number in the arrays. This will be used to track the smallest common element between `nums1` and `nums2`.

#### 2. **Storing the elements of `nums1` in a set**:
   ```cpp
   for(int i = 0; i < nums1.size(); i++) {
       cnt.insert(nums1[i]);
       num1 = min(nums1[i], num1);
   }
   ```
   - This loop iterates over the `nums1` array and inserts each element into the set `cnt`.
   - Additionally, `num1` is updated to track the smallest element in `nums1` as the loop progresses.

#### 3. **Processing `nums2` to find common elements and smallest numbers**:
   ```cpp
   int num2 = nums2[0];
   for(int i = 0; i < nums2.size(); i++) {
       if(cnt.count(nums2[i])) {
           mn = min(mn, nums2[i]);
       };
       num2 = min(nums2[i], num2);
   }
   ```
   - `num2` is initialized to the first element of `nums2`, which will help track the smallest element in `nums2`.
   - The loop iterates through `nums2` and checks if any element exists in the set `cnt` (i.e., if the element exists in both `nums1` and `nums2`). If a common element is found, it is compared with the current minimum `mn`, and `mn` is updated to the smaller of the two.
   - At the same time, `num2` is updated to track the smallest element in `nums2`.

#### 4. **Return the result based on common elements**:
   ```cpp
   if(mn < 10) return mn;
   if(num1 < num2) {
       return num1 * 10 + num2;
   } else {
       return num2 * 10 + num1;            
   }
   ```
   - If `mn` is less than 10, it means we found a common element in both arrays, and we return the smallest common element as the result.
   - If no common element exists (`mn` is still 10), we form a two-digit number by combining `num1` and `num2`. The smaller number is placed in the tens place to ensure the smallest possible two-digit number is returned.

### Complexity Analysis

- **Time Complexity**:
  - The time complexity of the solution is \(O(n + m)\), where \(n\) is the length of `nums1` and \(m\) is the length of `nums2`. This is because we:
    - Insert all elements of `nums1` into the set `cnt` in \(O(n)\) time.
    - Iterate over all elements of `nums2` to check for common elements and find the smallest element in \(O(m)\) time.
  - The operations in the main body of the function (set insertions and lookups, comparisons, and minimum calculations) all take constant time \(O(1)\).

- **Space Complexity**:
  - The space complexity is \(O(n)\) due to the set `cnt`, which stores all elements of `nums1`. The size of `cnt` is proportional to the size of `nums1`.

### Conclusion

This solution efficiently finds the smallest possible number formed by selecting one element from `nums1` and one element from `nums2` while considering the case where both arrays may share common elements. By using a set for fast lookup and keeping track of the smallest elements in both arrays, the algorithm operates with a time complexity of \(O(n + m)\), making it optimal for large input sizes. This approach ensures that we handle all cases, including when there are common elements and when the arrays need to be combined to form the smallest two-digit number.

[`Link to LeetCode Lab`](https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays/description/)

---
{{< youtube ZlVNO8BFBCY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
