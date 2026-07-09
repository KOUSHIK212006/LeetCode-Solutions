#include <stdlib.h>

typedef struct {
    int key;
    int value;
    int used;
} HashNode;

int hash(int key, int size) {
    if (key < 0) key = -key;
    return key % size;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int size = numsSize * 2 + 1;
    HashNode* table = (HashNode*)calloc(size, sizeof(HashNode));

    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];

        int idx = hash(complement, size);
        while (table[idx].used) {
            if (table[idx].key == complement) {
                result[0] = table[idx].value;
                result[1] = i;
                free(table);
                return result;
            }
            idx = (idx + 1) % size;
        }

        idx = hash(nums[i], size);
        while (table[idx].used) {
            idx = (idx + 1) % size;
        }

        table[idx].used = 1;
        table[idx].key = nums[i];
        table[idx].value = i;
    }

    free(table);
    *returnSize = 0;
    return NULL;
}
