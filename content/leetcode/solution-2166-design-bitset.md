
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
comments = true
+++



---
You are tasked with implementing a Bitset class that supports operations such as setting bits, clearing bits, flipping all bits, and querying the state of the bits (whether all bits are set to 1, at least one bit is set to 1, etc.).
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a list of operations to be performed on a Bitset object, starting with its initialization with a given size.
- **Example:** `["Bitset", "fix", "fix", "flip", "all", "unfix", "flip", "one", "unfix", "count", "toString"]`
- **Constraints:**
	- 1 <= size <= 10^5
	- 0 <= idx < size
	- At most 10^5 calls will be made in total to fix, unfix, flip, all, one, count, and toString.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a list of results corresponding to the operations performed, where each result matches the expected output for each method call.
- **Example:** `[null, null, null, null, false, null, null, true, null, 3, "01011"]`
- **Constraints:**
	- At least one call will be made to all, one, count, or toString.

{{< dots >}}
### Core Logic 🔍
**Goal:** Implement the `Bitset` class to efficiently support the operations on bits.

- Initialize the Bitset with all bits set to 0.
- Support methods to fix, unfix, flip, and query the state of the bits.
- Ensure that all methods run efficiently, with constant time complexity for individual operations.
{{< dots >}}
### Problem Assumptions ✅
- The size of the Bitset is always within the specified range.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: Input = ["Bitset", "fix", "fix", "flip", "all", "unfix", "flip", "one", "unfix", "count", "toString"]`  \
  **Explanation:** The Bitset is initialized with 5 bits. Several operations are performed such as fixing bits, flipping, and checking if all bits are set to 1, eventually returning the count and string representation of the Bitset.

{{< dots >}}
## Approach 🚀
The approach is to store the state of the Bitset using two strings: one for the actual bitset and one for the flipped version. This allows efficient bit manipulation and state queries.

### Initial Thoughts 💭
- The problem requires efficient manipulation and querying of bits.
- Using two strings to represent the Bitset and its flipped version ensures efficient bit flipping and checking.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs as the Bitset always has at least one bit.
- The solution must efficiently handle the maximum constraint of 10^5 bits.
- Handling cases where all bits are fixed or all are unfixes is important.
- Ensure that the solution works efficiently within the given constraints.
{{< dots >}}
## Code 💻
```cpp
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
```

This code implements a `Bitset` class with methods to fix, unfix, flip, check if all bits are set, check if one bit is set, count the set bits, and convert the bitset to a string representation.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int ones = 0, size = 0;
	```
	This line initializes two variables: `ones` to keep track of the number of bits set to 1, and `size` to store the size of the bitset.

2. **Access Specifier**
	```cpp
	public:
	```
	This is the access specifier marking the beginning of the public section of the class, where methods that can be accessed outside the class are defined.

3. **Constructor**
	```cpp
	Bitset(int size) {
	```
	This constructor initializes a `Bitset` object with the specified size, setting all bits to 0 initially.

4. **Initialization**
	```cpp
	    s = string(size, '0');
	```
	This line initializes the string `s` with the given size, filling it with '0' characters representing the unset bits.

5. **Initialization**
	```cpp
	    flipp = string(size, '1');
	```
	This line initializes the string `flipp` with the given size, filling it with '1' characters, which are used for flipping the bits.

6. **Initialization**
	```cpp
	    ones = 0;
	```
	This line initializes the `ones` counter to 0, as no bits are set initially.

7. **Initialization**
	```cpp
	    this->size = size;
	```
	This line sets the `size` of the bitset to the provided `size` argument.

8. **Method Definition**
	```cpp
	void fix(int idx) {
	```
	This method is used to set the bit at the specified index `idx` to 1, and updates the count of ones.

9. **Condition Check**
	```cpp
	    if(s[idx] == '0') ones++;
	```
	This checks if the bit at the given index is currently 0. If it is, the counter for `ones` is incremented.

10. **Modification**
	```cpp
	    s[idx] = '1';
	```
	This sets the bit at the specified index to 1.

11. **Modification**
	```cpp
	    flipp[idx] = '0';
	```
	This sets the corresponding bit in the `flipp` string to '0' indicating it is no longer in the flip state.

12. **End Method**
	```cpp
	}
	```
	The closing brace marks the end of the `fix` method.

13. **Method Definition**
	```cpp
	void unfix(int idx) {
	```
	This method is used to set the bit at the specified index `idx` to 0, and updates the count of ones.

14. **Condition Check**
	```cpp
	    if(s[idx] == '1') ones--;
	```
	This checks if the bit at the given index is currently 1. If it is, the counter for `ones` is decremented.

15. **Modification**
	```cpp
	    s[idx] = '0';
	```
	This sets the bit at the specified index to 0.

16. **Modification**
	```cpp
	    flipp[idx] = '1';
	```
	This sets the corresponding bit in the `flipp` string to '1' indicating it is now in the flip state.

17. **Method Definition**
	```cpp
	void flip() {
	```
	This method flips the entire bitset, changing each bit to its opposite (0 to 1 and vice versa).

18. **Modification**
	```cpp
	    ones = size - ones;
	```
	This updates the `ones` count after flipping by subtracting the current number of ones from the total size.

19. **Modification**
	```cpp
	    s.swap(flipp);
	```
	This swaps the contents of the `s` and `flipp` strings, effectively flipping the bits.

20. **Method Definition**
	```cpp
	bool all() {
	```
	This method checks if all bits in the bitset are set to 1.

21. **Condition Check**
	```cpp
	    return ones == size;
	```
	This returns true if the number of ones is equal to the total size, meaning all bits are set to 1.

22. **Method Definition**
	```cpp
	bool one() {
	```
	This method checks if at least one bit in the bitset is set to 1.

23. **Condition Check**
	```cpp
	    return ones > 0;
	```
	This returns true if the number of ones is greater than 0, meaning at least one bit is set.

24. **Method Definition**
	```cpp
	int count() {
	```
	This method returns the number of bits set to 1 in the bitset.

25. **Return Statement**
	```cpp
	    return ones;
	```
	This returns the value of `ones`, which represents the number of bits set to 1.

26. **Method Definition**
	```cpp
	string toString() {
	```
	This method converts the current bitset to a string.

27. **Return Statement**
	```cpp
	    return s;
	```
	This returns the string representation of the current bitset.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

Each operation (fix, unfix, flip, all, one, count, toString) runs in constant time.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage of two strings representing the Bitset.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/design-bitset/description/)

---
{{< youtube FWv-b_VITvA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
