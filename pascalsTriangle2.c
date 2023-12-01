//Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
// Example 1:
// Input: rowIndex = 3
// Output: [1,3,3,1]
// Example 2:

// Input: rowIndex = 0
// Output: [1]

int* getRow(int rowIndex, int* returnSize) {
    if (rowIndex < 0) {
        *returnSize = 0;
        return NULL;
    }

    if (rowIndex == 0) {
        *returnSize = 1;
        int* result = (int*)malloc(sizeof(int));
        if (!result) {
            perror("Memory allocation error");
            exit(EXIT_FAILURE);
        }
        result[0] = 1;
        return result;
    }

    int** arr = (int**)malloc((rowIndex + 1) * sizeof(int*));
    if (!arr) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i <= rowIndex; i++) {
        arr[i] = (int*)malloc((i + 1) * sizeof(int));
        if (!arr[i]) {
            perror("Memory allocation error");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i <= rowIndex; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                arr[i][j] = 1;
            } else {
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
            }
        }
    }

    *returnSize = rowIndex + 1;
    int* result = (int*)malloc(*returnSize * sizeof(int));
    if (!result) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i <= rowIndex; i++) {
        result[i] = arr[rowIndex][i];
    }

    for (int i = 0; i <= rowIndex; i++) {
        free(arr[i]);
    }
    free(arr);

    return result;
}

// efficient code

int* getRow(int rowIndex, int* returnSize) {
    if (rowIndex < 0) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = rowIndex + 1;
    int* result = (int*)malloc(*returnSize * sizeof(int));
    if (!result) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    result[0] = 1;

    for (int i = 1; i <= rowIndex; i++) {
        // Use the previous element to calculate the current element
        result[i] = (int)((long long)result[i - 1] * (rowIndex - i + 1) / i);
    }

    return result;
}