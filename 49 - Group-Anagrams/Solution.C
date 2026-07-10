#define TABLE_SIZE 20011

typedef struct Bucket {
    int count[26];
    int* indices;
    int size;
    int capacity;
    struct Bucket* next;
} Bucket;

static unsigned int hashCount(int* count) {
    unsigned int h = 0;
    for (int i = 0; i < 26; i++) {
        h = h * 131 + (unsigned int)count[i];
    }
    return h;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    Bucket** table = (Bucket**)calloc(TABLE_SIZE, sizeof(Bucket*));
    Bucket** order = (Bucket**)malloc(strsSize * sizeof(Bucket*));
    int groupCount = 0;

    for (int i = 0; i < strsSize; i++) {
        int count[26] = {0};
        for (char* p = strs[i]; *p; p++) {
            count[*p - 'a']++;
        }

        unsigned int h = hashCount(count) % TABLE_SIZE;

        Bucket* b = table[h];
        while (b != NULL) {
            if (memcmp(b->count, count, sizeof(count)) == 0) break;
            b = b->next;
        }

        if (b == NULL) {
            b = (Bucket*)malloc(sizeof(Bucket));
            memcpy(b->count, count, sizeof(count));
            b->capacity = 4;
            b->size = 0;
            b->indices = (int*)malloc(b->capacity * sizeof(int));
            b->next = table[h];
            table[h] = b;
            order[groupCount++] = b;
        }

        if (b->size == b->capacity) {
            b->capacity *= 2;
            b->indices = (int*)realloc(b->indices, b->capacity * sizeof(int));
        }
        b->indices[b->size++] = i;
    }

    char*** result = (char***)malloc(groupCount * sizeof(char**));
    int* colSizes = (int*)malloc(groupCount * sizeof(int));

    for (int g = 0; g < groupCount; g++) {
        Bucket* b = order[g];
        result[g] = (char**)malloc(b->size * sizeof(char*));
        for (int j = 0; j < b->size; j++) {
            result[g][j] = strs[b->indices[j]]; // reuse original pointers, no strdup needed
        }
        colSizes[g] = b->size;
    }

    *returnSize = groupCount;
    *returnColumnSizes = colSizes;

    for (int i = 0; i < TABLE_SIZE; i++) {
        Bucket* b = table[i];
        while (b != NULL) {
            Bucket* next = b->next;
            free(b->indices);
            free(b);
            b = next;
        }
    }
    free(table);
    free(order);

    return result;
}