
+++
authors = ["grid47"]
title = "Leetcode 2166: Design Bitset"
date = "2024-04-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2166: Design Bitset in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Design"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "FWv-b_VITvA"
youtube_upload_date="2022-02-06"
youtube_thumbnail="https://i.ytimg.com/vi_webp/FWv-b_VITvA/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Bitset {
    string s, flipp;
    int ones = 0, size = 0;
public:
    Bitset(int size) {
        s = string(size, '0');
        flipp = string(size, '1');
        ones = 0;
        this->size = size;
    }
    
    void fix(int idx) {
        if(s[idx] == '0') ones++;
        s[idx] = '1';
        flipp[idx] = '0';
    }
    
    void unfix(int idx) {
        if(s[idx] == '1') ones--;
        s[idx] = '0';
        flipp[idx] = '1';        
    }
    
    void flip() {
        ones = size - ones;
        s.swap(flipp);
    }
    
    bool all() {
        return ones == size;
    }
    
    bool one() {
        return ones > 0;
    }
    
    int count() {
        return ones;
    }
    
    string toString() {
        return s;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
{{< /highlight >}}
---

### Problem Statement
The task is to design and implement a `Bitset` class that supports a series of operations on a binary set of a fixed size. Each element in the `Bitset` can either be a '0' or '1'. The class should provide methods to fix specific bits, unfix them, flip all bits, check if all or any bits are set, count the number of set bits, and return the string representation of the bitset.

### Approach
The `Bitset` class uses two main string representations to manage bit states:
1. **`s`**: The actual string representing the current state of the bits.
2. **`flipp`**: An auxiliary string that represents the flipped version of `s`.

### Implementation Details
1. **Constructor `Bitset(int size)`**:
   - Initializes `s` as a string of '0's representing the bitset.
   - Initializes `flipp` as a string of '1's, which is the complement of `s`.
   - Initializes `ones` to track the number of bits currently set to '1'.
   - Stores `size` as the total number of bits in the bitset.

2. **`void fix(int idx)`**:
   - Sets the bit at index `idx` to '1'.
   - Increments `ones` only if the bit at `idx` was originally '0'.
   - Updates `flipp` by setting the bit at `idx` to '0'.

3. **`void unfix(int idx)`**:
   - Sets the bit at index `idx` to '0'.
   - Decrements `ones` only if the bit at `idx` was originally '1'.
   - Updates `flipp` by setting the bit at `idx` to '1'.

4. **`void flip()`**:
   - Swaps `s` with `flipp` to invert the bitset.
   - Updates the count of `ones` to `size - ones`, as all '1's become '0's and vice versa.

5. **`bool all()`**:
   - Returns `true` if all bits are set to '1', i.e., `ones == size`.

6. **`bool one()`**:
   - Returns `true` if at least one bit is set to '1', i.e., `ones > 0`.

7. **`int count()`**:
   - Returns the number of bits currently set to '1', tracked by `ones`.

8. **`string toString()`**:
   - Returns the string representation `s` of the current state of the bitset.

### Code Breakdown (Step by Step)
1. **Initialization**:
   - `s` is initialized to a string of '0's (e.g., "000...0").
   - `flipp` is initialized to a string of '1's (e.g., "111...1").
   - `ones` is initialized to `0`, indicating no '1's at the start.

2. **`fix(int idx)`**:
   - Checks if `s[idx]` is '0' to ensure `ones` is only incremented when a change occurs.
   - Changes `s[idx]` to '1' and `flipp[idx]` to '0'.

3. **`unfix(int idx)`**:
   - Checks if `s[idx]` is '1' to ensure `ones` is only decremented when a change occurs.
   - Changes `s[idx]` to '0' and `flipp[idx]` to '1'.

4. **`flip()`**:
   - Swaps `s` and `flipp` using the `swap()` function.
   - Updates `ones` to `size - ones`.

5. **`all()`**:
   - Returns `true` if `ones == size`, indicating all bits are '1'.

6. **`one()`**:
   - Returns `true` if `ones > 0`, indicating at least one bit is '1'.

7. **`count()`**:
   - Directly returns the value of `ones`.

8. **`toString()`**:
   - Returns the current bitset representation `s`.

### Complexity
- **Time Complexity**:
  - Constructor `Bitset(int size)`: O(n), where `n` is the size of the bitset.
  - `fix(int idx)`, `unfix(int idx)`: O(1), as only a single bit is updated.
  - `flip()`: O(1), due to swapping and basic arithmetic.
  - `all()`, `one()`, `count()`, `toString()`: O(1).

- **Space Complexity**:
  - O(n), where `n` is the size of the bitset, used by the `s` and `flipp` strings.

### Conclusion
The `Bitset` class provides a clear and efficient way to manage and manipulate bits. It includes methods to set, reset, flip, count, and check the state of the bits, all in O(1) time. This design is optimal for scenarios requiring frequent bit manipulations with minimal overhead, making it suitable for applications in simulations, binary operations, and problem-solving environments where bit-level control is necessary.

[`Link to LeetCode Lab`](https://leetcode.com/problems/design-bitset/description/)

---
{{< youtube FWv-b_VITvA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
