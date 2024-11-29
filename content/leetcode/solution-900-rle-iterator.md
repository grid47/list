
+++
authors = ["grid47"]
title = "Leetcode 900: RLE Iterator"
date = "2024-08-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 900: RLE Iterator in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Design","Counting","Iterator"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "69UElCwk6B4"
youtube_upload_date="2023-01-19"
youtube_thumbnail="https://i.ytimg.com/vi/69UElCwk6B4/maxresdefault.jpg"
comments = true
+++



---
We are given a run-length encoded array where every even-indexed element specifies how many times the following odd-indexed element (a number) is repeated in the original sequence. Your task is to implement an iterator that can return the next 'n' elements from the decoded sequence when requested.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a run-length encoded array where encoding[i] gives the frequency of encoding[i+1] in the sequence. You need to create an iterator that can return the next 'n' elements when requested.
- **Example:** `Input: ['RLEIterator', 'next', 'next', 'next', 'next']
[[[2, 10, 1, 20, 3, 5]], [1], [2], [3], [4]]`
- **Constraints:**
	- 2 <= encoding.length <= 1000
	- encoding.length is even.
	- 0 <= encoding[i] <= 10^9
	- 1 <= n <= 10^9
	- At most 1000 calls will be made to next.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the value of the last element returned after exhausting the next 'n' elements from the sequence, or -1 if there are no more elements to exhaust.
- **Example:** `Output: [null, 20, 20, 5, -1]`
- **Constraints:**
	- The result for each next(n) call will be an integer or -1 if there are no more elements.

{{< dots >}}
### Core Logic 🔍
**Goal:** To create an iterator that processes run-length encoded data and efficiently returns the next 'n' elements in sequence.

- 1. Use an index to traverse the run-length encoded array.
- 2. For each next(n) call, decrement the count of the remaining elements in the current sequence while keeping track of the last number encountered.
- 3. Once the count of a sequence is exhausted, move to the next run-length encoded pair and continue.
- 4. If no more elements are available, return -1.
{{< dots >}}
### Problem Assumptions ✅
- The input encoding array will always have an even length.
- Each encoding pair will be a valid representation of a sequence of numbers.
- The solution should efficiently handle repeated calls to the 'next' method.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: ['RLEIterator', 'next', 'next', 'next', 'next']
[[[2, 10, 1, 20, 3, 5]], [1], [2], [3], [4]]`  \
  **Explanation:** The run-length encoded array [2, 10, 1, 20, 3, 5] represents the sequence [10, 10, 20, 5, 5, 5]. Calling next(1) returns 20, next(2) returns 20 again, next(3) returns 5, and next(4) returns -1 as the sequence is exhausted.

{{< dots >}}
## Approach 🚀
The approach involves iterating over the run-length encoded array, processing each 'run' of repeated values, and returning the appropriate number of elements in each next() call.

### Initial Thoughts 💭
- Since the encoded array is compact, iterating through it and extracting the required elements should be efficient if done incrementally.
- Efficient traversal is key, and handling large values for 'n' is important to prevent timeouts or excessive memory usage.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that encoding will not be empty, as the length is at least 2.
- Large inputs with values of 'n' up to 10^9 should be handled by efficiently skipping over the run-length sequences.
- Zero values in the encoding array should be handled gracefully.
- Efficient memory usage and computation time are necessary given the problem's constraints.
{{< dots >}}
## Code 💻
```cpp
int idx = 0;
public:
RLEIterator(vector<int>& encoding) {
    arr = encoding;
    idx = 0;
}

int next(int n) {
    while(idx < arr.size()) {
        if(n > arr[idx]) {
            n -= arr[idx];
            idx += 2;
        } else {
            arr[idx] -= n;
            return arr[idx + 1];
        }
    }
    return -1;
}
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
```

This code defines an `RLEIterator` class for handling a Run-Length Encoding (RLE) compressed array. It includes methods to initialize the iterator with encoded data and retrieve the next element based on the encoding.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	int idx = 0;
	```
	The variable `idx` is declared and initialized to 0, representing the current position in the encoded array.

2. **Access Specifier**
	```cpp
	public:
	```
	The access specifier `public` is used to indicate that the following methods are accessible outside the class.

3. **Constructor**
	```cpp
	RLEIterator(vector<int>& encoding) {
	```
	The constructor `RLEIterator` is defined to initialize the object with a reference to the encoded data array `encoding`.

4. **Array Initialization**
	```cpp
	    arr = encoding;
	```
	The constructor initializes the member variable `arr` with the provided encoding array.

5. **Index Initialization**
	```cpp
	    idx = 0;
	```
	The constructor initializes the index variable `idx` to 0, which will be used to traverse the encoding array.

6. **Constructor End**
	```cpp
	}
	```
	End of the constructor definition.

7. ****
	```cpp
	
	```
	

8. **Method Definition**
	```cpp
	int next(int n) {
	```
	The method `next(int n)` is defined to retrieve the next element in the RLE sequence based on the value `n`.

9. **While Loop**
	```cpp
	    while(idx < arr.size()) {
	```
	A while loop starts, which continues as long as the index `idx` is less than the size of the array `arr`.

10. **Condition Check**
	```cpp
	        if(n > arr[idx]) {
	```
	The condition checks if the remaining value `n` is greater than the current frequency value `arr[idx]`.

11. **Subtract Frequency**
	```cpp
	            n -= arr[idx];
	```
	If `n` is greater than the current frequency, subtract the current frequency `arr[idx]` from `n` and move to the next pair in the encoding.

12. **Index Update**
	```cpp
	            idx += 2;
	```
	The index `idx` is updated to the next element in the encoding (which is a pair of frequency and value, so the index moves by 2).

13. **Else Condition**
	```cpp
	        } else {
	```
	If `n` is not greater than the current frequency `arr[idx]`, the method proceeds to return the value corresponding to this frequency.

14. **Update Frequency**
	```cpp
	            arr[idx] -= n;
	```
	The frequency at the current index is reduced by `n`, which represents the number of times this value has been accessed.

15. **Return Value**
	```cpp
	            return arr[idx + 1];
	```
	The value corresponding to the current frequency (i.e., `arr[idx + 1]`) is returned.

16. **End Else Block**
	```cpp
	        }
	```
	End of the else block.

17. **End While Loop**
	```cpp
	    }
	```
	End of the while loop.

18. **Return -1**
	```cpp
	    return -1;
	```
	If no value can be returned (i.e., the encoding has been exhausted), the function returns -1.

19. **Method End**
	```cpp
	}
	```
	End of the `next` method.

20. **Class End**
	```cpp
	};
	```
	End of the `RLEIterator` class definition.

21. ****
	```cpp
	
	```
	

22. **Documentation**
	```cpp
	/**
	```
	The following section provides documentation on how to instantiate and use the `RLEIterator` class.

23. **Instantiation Example**
	```cpp
	 * Your RLEIterator object will be instantiated and called as such:
	```
	Example usage of the `RLEIterator` class.

24. **Object Creation**
	```cpp
	 * RLEIterator* obj = new RLEIterator(encoding);
	```
	This line shows how to instantiate an `RLEIterator` object with a given encoding vector.

25. **Method Call**
	```cpp
	 * int param_1 = obj->next(n);
	```
	This line shows how to call the `next` method to retrieve the next element in the sequence.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1) per next() call when there are enough elements left in the current 'run'.
- **Average Case:** O(1) per next() call, assuming the sequence is processed efficiently.
- **Worst Case:** O(n) per next() call in extreme cases when 'n' is large and needs to exhaust multiple 'runs'.

In the worst case, each next() call may require iterating over several elements of the encoded array.

### Space Complexity 💾
- **Best Case:** O(1) as the iterator operates in constant space.
- **Worst Case:** O(1) as no additional space is required beyond storing the encoded array.

The space complexity is constant, as we only need space to store the input and an index to traverse it.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/rle-iterator/description/)

---
{{< youtube 69UElCwk6B4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
