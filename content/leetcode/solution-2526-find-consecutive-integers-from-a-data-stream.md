
+++
authors = ["grid47"]
title = "Leetcode 2526: Find Consecutive Integers from a Data Stream"
date = "2024-02-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2526: Find Consecutive Integers from a Data Stream in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Design","Queue","Counting","Data Stream"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "3VXPkJ8bInY"
youtube_upload_date="2023-01-07"
youtube_thumbnail="https://i.ytimg.com/vi_webp/3VXPkJ8bInY/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class DataStream {
public:
    int val, k, cnt = 0;
    DataStream(int value, int k) {
        val = value;
        this->k = k;
    }
    
    bool consec(int num) {
        if(val == num) cnt = min(k, cnt+1);
        else {
            cnt = 0;
        }
        return k == cnt;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
{{< /highlight >}}
---

### Problem Statement

The task is to design a class `DataStream` that is able to process a stream of integers. Specifically, the class must allow for checking if there are `k` consecutive occurrences of a given value `val` in the stream.

The problem boils down to:
1. **Initialization**: You are given an integer `val` (the value that we want to check for consecutive occurrences) and an integer `k` (the number of consecutive occurrences of `val` that must be seen in the stream).
2. **Stream Processing**: As the stream of integers is processed, for each integer `num`, you need to check if there have been `k` consecutive occurrences of `val` in the stream up to that point.

The class should support the following:
- **Initialization**: A constructor that takes the value `val` and the threshold `k` for consecutive occurrences.
- **Stream Processing**: A method `consec(int num)` that returns `true` if the current number `num` continues the streak of `k` consecutive occurrences of `val`, and `false` otherwise.

### Approach

To solve this problem, we need to maintain a count of how many consecutive occurrences of the value `val` we have encountered. The process can be broken down as follows:

1. **Initialization**:
   - We define a constructor that takes the target value `val` and the threshold `k`.
   - The constructor initializes two variables: 
     - `val` stores the target value that we are tracking.
     - `k` stores the number of consecutive occurrences of `val` that we need to detect.
     - `cnt` is initialized to 0 and keeps track of the current count of consecutive occurrences of `val` in the stream.

2. **Processing Stream**:
   - The method `consec(int num)` is invoked each time a new number from the stream is processed.
   - Inside `consec`, we first check if the current number `num` is equal to `val`:
     - If it is, we increment the `cnt` variable, ensuring that `cnt` does not exceed the value `k`. This is done using `min(k, cnt + 1)`.
     - If the current number `num` is not equal to `val`, we reset `cnt` to 0 because the streak is broken.
   - After updating `cnt`, we check if it equals `k`. If it does, this means we have encountered `k` consecutive occurrences of `val`, so we return `true`. Otherwise, we return `false`.

3. **Edge Case Handling**:
   - If the current number `num` is not equal to `val`, the consecutive streak is reset, and `cnt` is set back to 0.
   - If the stream continues and the count reaches `k`, `true` is returned to indicate that we have detected `k` consecutive occurrences of `val`.

### Code Breakdown (Step by Step)

#### 1. Class Definition and Constructor

```cpp
class DataStream {
public:
    int val, k, cnt = 0;
    DataStream(int value, int k) {
        val = value;
        this->k = k;
    }
```

- The `DataStream` class is defined with three member variables:
  - `val`: Stores the target value that we want to track for consecutive occurrences.
  - `k`: Stores the threshold for consecutive occurrences of `val`.
  - `cnt`: Keeps track of the current streak of consecutive occurrences of `val`. It is initialized to 0.

The constructor initializes `val` and `k` with the provided values and sets `cnt` to 0.

#### 2. Consecutive Occurrence Check Method

```cpp
    bool consec(int num) {
        if(val == num) cnt = min(k, cnt+1);
        else {
            cnt = 0;
        }
        return k == cnt;
    }
```

- The method `consec` is designed to process a new number `num` from the stream:
  - **Check if the number matches `val`**: 
    - If `num` equals `val`, we increment `cnt` by 1, ensuring that `cnt` does not exceed `k` using `min(k, cnt + 1)`.
    - If `num` is not equal to `val`, we reset `cnt` to 0 because the consecutive streak is broken.
  - **Return the result**: After updating `cnt`, we check if `cnt` equals `k`. If it does, it means we have seen `k` consecutive occurrences of `val`, so we return `true`. Otherwise, we return `false`.

#### 3. Object Instantiation and Method Usage

```cpp
/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
```

- The class `DataStream` is instantiated with a target value `val` and a threshold `k`.
- The method `consec(num)` is called on the `DataStream` object, passing the current number `num` from the stream to check if it results in `k` consecutive occurrences of `val`.

### Time Complexity

- **Constructor Complexity**: The constructor simply initializes three variables and takes constant time, i.e., \( O(1) \).
  
- **`consec` Method Complexity**: Each call to `consec` involves checking if the number `num` is equal to `val`, incrementing a counter, and performing a comparison, all of which are constant-time operations. Therefore, the time complexity of `consec(num)` is \( O(1) \).

- **Overall Complexity**: The overall time complexity of each operation is \( O(1) \), as both the constructor and method `consec` execute in constant time.

### Space Complexity

- The class uses a few integer variables (`val`, `k`, and `cnt`), all of which occupy constant space. Therefore, the space complexity of the `DataStream` class is \( O(1) \).

### Conclusion

This solution provides an efficient way to track consecutive occurrences of a given value in a data stream. By using a counter (`cnt`) to track the streak of consecutive values and resetting it whenever the streak is broken, the solution offers constant-time complexity for each stream processing step. The space complexity is also constant, making this a highly efficient approach for handling large streams of data. This class is ideal for scenarios where we need to track consecutive occurrences of a specific value in a stream in real-time.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream/description/)

---
{{< youtube 3VXPkJ8bInY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
