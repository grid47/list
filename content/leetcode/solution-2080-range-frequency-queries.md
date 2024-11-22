
+++
authors = ["grid47"]
title = "Leetcode 2080: Range Frequency Queries"
date = "2024-04-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2080: Range Frequency Queries in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Binary Search","Design","Segment Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "1gZinwGx3lk"
youtube_upload_date="2021-11-21"
youtube_thumbnail="https://i.ytimg.com/vi/1gZinwGx3lk/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class RangeFreqQuery {
public:
    map<int, vector<int>> mp;
    RangeFreqQuery(vector<int>& arr) {
        for(int i = 0; i < arr.size(); i++) {
            mp[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        return upper_bound(mp[value].begin(), mp[value].end(), right) -             
            lower_bound(mp[value].begin(), mp[value].end(), left);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
{{< /highlight >}}
---

### Problem Statement

The problem involves creating a data structure that allows for efficient range frequency queries. Given an array, we want to be able to quickly determine how many times a specific value appears within a specified range of indices. This functionality is particularly useful in applications where queries over static data need to be performed frequently, such as in statistical analysis or database queries.

### Approach

To solve this problem, we will implement a class called `RangeFreqQuery` that uses a hash map (specifically, a `std::map` in C++) to store the indices of each value in the array. By storing the indices, we can later use binary search to efficiently count occurrences of a value within any specified range.

1. **Data Structure**: Use a `std::map<int, vector<int>>` to store each unique value from the input array as a key, and a vector of indices where that value appears as the corresponding value.

2. **Constructor**: The constructor initializes the `RangeFreqQuery` object. It iterates over the input array and populates the map with the indices of each value.

3. **Query Method**: The `query` method takes three parameters: the left index, the right index, and the target value. It calculates the number of occurrences of the target value between the given indices using binary search (`upper_bound` and `lower_bound`).

### Code Breakdown (Step by Step)

Here’s a detailed breakdown of the code implementation:

```cpp
class RangeFreqQuery {
public:
    map<int, vector<int>> mp;  // Map to hold the indices of each value

    RangeFreqQuery(vector<int>& arr) {
```

1. **Class Definition**: The class `RangeFreqQuery` is defined with a public member, a map called `mp`, which maps integers to vectors of integers.

2. **Constructor**: The constructor accepts a vector of integers `arr`, which represents the initial array.

```cpp
        for(int i = 0; i < arr.size(); i++) {
            mp[arr[i]].push_back(i);  // Store indices of each value in the map
        }
    }
```

3. **Index Storage**: As we iterate through the array, for each element `arr[i]`, we push the index `i` into the vector associated with the key `arr[i]`. This builds the map such that we can later quickly retrieve all indices for any value.

```cpp
    int query(int left, int right, int value) {
```

4. **Query Method**: The `query` method is defined to handle the frequency count between the specified range.

```cpp
        return upper_bound(mp[value].begin(), mp[value].end(), right) -             
            lower_bound(mp[value].begin(), mp[value].end(), left);
    }
};
```

5. **Binary Search for Counting**:
   - `upper_bound(mp[value].begin(), mp[value].end(), right)`: This function finds the first position in the vector of indices where the value exceeds `right`. This gives us the count of indices less than or equal to `right`.
   - `lower_bound(mp[value].begin(), mp[value].end(), left)`: This function finds the first position in the vector where the index is not less than `left`, effectively providing the count of indices before `left`.
   - The difference between these two results gives the number of occurrences of `value` in the range `[left, right]`.

### Complexity

- **Time Complexity**:
  - **Constructor**: \(O(n \log n)\) where \(n\) is the number of elements in the input array, due to the operations involved in inserting into the map.
  - **Query**: \(O(\log m)\) where \(m\) is the number of indices stored for the queried value, due to the binary search operations.

- **Space Complexity**: \(O(n)\) for storing the indices of each unique element, where \(n\) is the total number of elements in the input array.

### Conclusion

The `RangeFreqQuery` class provides an efficient solution for handling frequency queries over a static array. By utilizing a map to store indices and employing binary search for query operations, we achieve a balance between space and time efficiency. 

This implementation is particularly beneficial in scenarios where numerous frequency queries need to be executed on a dataset, such as in statistical computations or data analysis applications. The ability to perform range queries in logarithmic time allows for rapid responses even in larger datasets, making it a versatile tool for developers dealing with dynamic data environments.

This technique of indexing values to their positions is a common strategy in many computational problems, demonstrating a powerful approach to optimizing search and retrieval operations. Understanding and implementing such data structures can significantly enhance performance in software applications that require quick access to frequently queried data.

[`Link to LeetCode Lab`](https://leetcode.com/problems/range-frequency-queries/description/)

---
{{< youtube 1gZinwGx3lk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
