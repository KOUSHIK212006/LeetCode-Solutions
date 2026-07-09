# Two Sum

## Problem
https://leetcode.com/problems/two-sum

Given an integer array `nums` and an integer `target`, find the indices of two numbers whose sum equals the target.

### Example

```text
Input: nums = [2, 7, 11, 15], target = 9
Output: [0, 1]
```

## Approach

Use a `HashMap` to store each visited number and its index.

For every element:

1. Calculate the complement:

```text
complement = target - nums[i]
```

2. Check if the complement already exists in the HashMap.
3. If it exists, return its index and the current index.
4. Otherwise, store the current number and its index.

## Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(n)`

## Key Learning

Using a HashMap allows us to find the required complement efficiently instead of checking every pair using nested loops.
