# 217. Contains Duplicate

## Problem

Given an integer array `nums`, return `true` if any value appears at least twice in the array, and return `false` if every element is distinct.

## Problem Link

https://leetcode.com/problems/contains-duplicate/

## Approach

Use a `HashSet` to keep track of the numbers that have already been seen.

For each number in the array:

- Check whether the number already exists in the `HashSet`.
- If it exists, return `true` because a duplicate has been found.
- Otherwise, add the number to the `HashSet`.
- If no duplicates are found after checking the entire array, return `false`.

## Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

## Languages

- Java
