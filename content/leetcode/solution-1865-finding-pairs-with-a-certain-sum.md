
+++
authors = ["grid47"]
title = "Leetcode 1865: Finding Pairs With a Certain Sum"
date = "2024-05-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1865: Finding Pairs With a Certain Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Design"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "T4yZIHISIYY"
youtube_upload_date="2021-05-16"
youtube_thumbnail="https://i.ytimg.com/vi_webp/T4yZIHISIYY/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class FindSumPairs {
public:
    vector<int> nums1, nums2;
    vector<vector<int>> mtx;
    map<int, int> mp;
    int m, n;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        m = nums2.size(), n = nums1.size();
        for(int i = 0; i < nums2.size(); i++) {
                mp[nums2[i]]++;
        }
    }
    
    void add(int index, int val) {
        int key = nums2[index];
        nums2[index] += val;
        mp[key]--;
        mp[nums2[index]]++;
    }
    
    int count(int tot) {
        int res = 0;
        for(int i = 0; i < n; i++) {
            res += mp[tot - nums1[i]];
        }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
{{< /highlight >}}
---

### Problem Statement

The task involves designing a class called `FindSumPairs` that allows us to efficiently manage two arrays (`nums1` and `nums2`) and to count how many pairs of elements from these two arrays sum up to a given target value. The class should support two primary operations:

1. **Adding a value** to an element in `nums2` at a specified index.
2. **Counting the pairs** from `nums1` and `nums2` that sum to a given target value.

This requires a structure that can dynamically update and query pairs efficiently.

### Approach

To solve this problem, we will take advantage of a hashmap (or dictionary) to store counts of elements in `nums2`. This allows for quick lookups when counting pairs. Here’s a step-by-step breakdown of our approach:

1. **Initialization**: Store the provided `nums1` and `nums2` in the class. Use a hashmap to count occurrences of each value in `nums2`. This will help us quickly determine how many times a particular value needed to reach the target exists in `nums2`.

2. **Adding Values**: When a value is added to an element in `nums2`, update both the original value’s count (decrement) and the new value’s count (increment) in the hashmap.

3. **Counting Pairs**: To count pairs that sum up to a target value, iterate through `nums1` and for each element, compute the value needed from `nums2` to reach the target. Look up this needed value in the hashmap to get its count, which represents how many valid pairs can be formed with that particular element from `nums1`.

### Code Breakdown (Step by Step)

1. **Class Definition**: The implementation starts with defining the `FindSumPairs` class.

    ```cpp
    class FindSumPairs {
    public:
    ```

2. **Member Variables**: The class has member variables to store the two arrays, the size of these arrays, a hashmap for counting occurrences in `nums2`, and a matrix placeholder that is not used in the current implementation.

    ```cpp
    vector<int> nums1, nums2;
    vector<vector<int>> mtx; // Not used in the current implementation
    map<int, int> mp; // Map to count occurrences in nums2
    int m, n; // Sizes of nums1 and nums2
    ```

3. **Constructor**: The constructor takes two integer vectors (`nums1` and `nums2`) as input. It initializes the class variables and populates the hashmap with the counts of each number in `nums2`.

    ```cpp
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        m = nums2.size();
        n = nums1.size();
        for(int i = 0; i < nums2.size(); i++) {
            mp[nums2[i]]++; // Count occurrences of each number in nums2
        }
    }
    ```

4. **Adding Values**: The `add` method allows modification of the `nums2` array. It updates the element at the specified index by adding a value to it, while also updating the hashmap to reflect the changes in counts.

    ```cpp
    void add(int index, int val) {
        int key = nums2[index]; // Original value at the index
        nums2[index] += val; // Update nums2
        mp[key]--; // Decrement the count of the old value
        mp[nums2[index]]++; // Increment the count of the new value
    }
    ```

5. **Counting Pairs**: The `count` method counts how many pairs from `nums1` and `nums2` sum to the specified total. For each element in `nums1`, it calculates the required counterpart from `nums2` and adds up the counts of how many times that counterpart exists.

    ```cpp
    int count(int tot) {
        int res = 0;
        for(int i = 0; i < n; i++) {
            res += mp[tot - nums1[i]]; // Add counts of the required counterpart
        }
        return res;
    }
    ```

6. **Class Usage Example**: The class can be instantiated and used as shown in the provided comment.

    ```cpp
    /**
     * Your FindSumPairs object will be instantiated and called as such:
     * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
     * obj->add(index, val);
     * int param_2 = obj->count(tot);
     */
    ```

### Complexity

The time complexity for the constructor is \(O(m)\), where \(m\) is the size of `nums2`, as we are populating the hashmap. The `add` method operates in \(O(1)\) time for the update operation, given that hashmap operations (insertions and deletions) are average \(O(1)\). The `count` method has a time complexity of \(O(n)\), where \(n\) is the size of `nums1`, since we iterate through all elements of `nums1` to compute the count.

In terms of space complexity, the storage for the hashmap is \(O(m)\) in the worst case (when all elements in `nums2` are unique).

### Conclusion

In conclusion, the `FindSumPairs` class provides an efficient way to manage two integer arrays and perform operations to count valid pairs that sum to a specific target. By leveraging a hashmap to store counts of elements in `nums2`, the implementation ensures quick updates and lookups, which is essential for maintaining performance. The approach is straightforward yet effective, demonstrating the usefulness of data structures in solving combinatorial problems efficiently. This solution is suitable for applications where dynamic updates and quick queries are required, making it a robust choice for similar problems in algorithm design and competitive programming. The clarity and organization of the code enhance its readability and maintainability, solidifying its value as a reference for similar implementations.

[`Link to LeetCode Lab`](https://leetcode.com/problems/finding-pairs-with-a-certain-sum/description/)

---
{{< youtube T4yZIHISIYY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
