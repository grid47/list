
+++
authors = ["grid47"]
title = "Leetcode 2336: Smallest Number in Infinite Set"
date = "2024-03-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2336: Smallest Number in Infinite Set in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Design","Heap (Priority Queue)","Ordered Set"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "_gGX_2ZNa2E"
youtube_upload_date="2022-07-10"
youtube_thumbnail="https://i.ytimg.com/vi/_gGX_2ZNa2E/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class SmallestInfiniteSet {
public:
    int cnt = 1;
    set<int> s;
    SmallestInfiniteSet() {
        s.clear();
        cnt = 1;
    }
    
    int popSmallest() {
        if(!s.empty()) {
            int tmp = *s.begin() ;
                s.erase(tmp);
            return tmp;            
        }
        return cnt++;
    }
    
    void addBack(int num) {
        if(num < cnt)
        s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
{{< /highlight >}}
---

### Problem Statement

The problem asks us to implement a class `SmallestInfiniteSet` that simulates an infinite set of positive integers, starting from 1. We need to be able to perform two operations on this set:
1. **popSmallest**: Return and remove the smallest integer from the set.
2. **addBack**: Add a previously removed integer back to the set if it’s less than the current largest number in the set.

The primary challenge lies in maintaining an efficient way to find and remove the smallest integer, while also being able to add back integers in a way that preserves the smallest set order.

### Approach

We are asked to create a class that efficiently manages two key operations:
1. **Popping the smallest element**: In an infinite set, the smallest element can always be defined as the smallest integer not yet removed.
2. **Adding an element back**: Once an integer has been popped from the set, it may be added back to the set in the future, but only if it’s smaller than the current "largest" number in the set (tracked by the `cnt` variable).

We will use two core components to solve this:
- **A set**: The set will be used to store numbers that have been removed (i.e., popped) from the smallest infinite set. This allows for efficient operations to check and remove the smallest element.
- **A counter `cnt`**: This counter keeps track of the next integer to be returned when the set is empty, ensuring we always return the smallest possible integer when the set is empty.

### Code Breakdown (Step by Step)

#### 1. **Class Initialization**
```cpp
class SmallestInfiniteSet {
public:
    int cnt = 1;
    set<int> s;
    SmallestInfiniteSet() {
        s.clear();
        cnt = 1;
    }
```
- **`cnt`**: This integer is initialized to 1 and tracks the next smallest integer to be returned if the set is empty. Each time we call `popSmallest()`, if the set `s` is empty, the value of `cnt` is returned, and `cnt` is incremented.
- **`s`**: A set data structure is used to hold the numbers that were added back into the set. Sets provide efficient insertion and removal, and they keep the elements sorted, so we can easily access the smallest element.

#### 2. **`popSmallest` Method**
```cpp
    int popSmallest() {
        if(!s.empty()) {
            int tmp = *s.begin();
            s.erase(tmp);
            return tmp;            
        }
        return cnt++;
    }
```
- The `popSmallest()` method returns the smallest integer in the set and removes it.
- **`if(!s.empty())`**: If the set `s` is not empty, the smallest integer is obtained using `*s.begin()`, and then it is removed from the set using `s.erase(tmp)`.
- **`return cnt++`**: If the set is empty, we return the current value of `cnt` and then increment `cnt` by 1. This ensures that we are always returning the smallest possible number when the set is empty.

#### 3. **`addBack` Method**
```cpp
    void addBack(int num) {
        if(num < cnt)
            s.insert(num);
    }
};
```
- **`addBack(int num)`**: This method is used to add an integer back to the set. The integer can only be added back if it is less than the current `cnt`, ensuring that we are not re-adding numbers that have already been "used" (i.e., numbers greater than or equal to `cnt`).
- **`s.insert(num)`**: If the integer is less than `cnt`, it is inserted back into the set `s`.

#### 4. **Usage Example**
```cpp
/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
```
- We instantiate the `SmallestInfiniteSet` object, then use the `popSmallest()` method to get the smallest number from the set and the `addBack()` method to return numbers back into the set.

### Complexity

#### Time Complexity:
- **`popSmallest()`**: The time complexity is **O(log N)**, where N is the number of elements in the set `s`. This is because finding and removing the smallest element from a set requires logarithmic time.
- **`addBack()`**: The time complexity for adding an element back is **O(log N)**, since inserting into a set also requires logarithmic time to maintain the sorted order of the elements.

Thus, both methods are efficient, with logarithmic time complexity relative to the number of elements in the set.

#### Space Complexity:
- The space complexity is **O(N)**, where N is the number of elements in the set `s`. The space is used to store the numbers that have been added back into the set.

### Conclusion

The `SmallestInfiniteSet` class offers an efficient way to manage an infinite set of numbers, where we can:
1. Return the smallest available number (`popSmallest`).
2. Add previously popped numbers back into the set (`addBack`).

By utilizing a set to store removed elements and a counter to track the smallest possible number when the set is empty, we can efficiently handle both operations. The time complexity of both operations is logarithmic with respect to the number of elements in the set, ensuring that the solution is scalable for large numbers of operations.

[`Link to LeetCode Lab`](https://leetcode.com/problems/smallest-number-in-infinite-set/description/)

---
{{< youtube _gGX_2ZNa2E >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
