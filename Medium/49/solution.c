#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// // normal (my approach)
// bool annagram(char* str1, char* str2, int len1, int len2) {
//     if (len1 != len2) {
//         return false;
//     }

//     int hash1[26] = {0};
//     int hash2[26] = {0};

//     for (int i = 0; i < len1; i++) {
//         hash1[str1[i] - 'a']++;
//         hash2[str2[i] - 'a']++;
//     }

//     for (int i = 0; i < 26; i++) {
//         if (hash1[i] != hash2[i]) {
//             return false;
//         }
//     }

//     return true;
// }

// char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
//     *returnSize = 0;
//     char*** ret_arr = (char***)malloc(strsSize * sizeof(char**));
//     *returnColumnSizes = (int*)malloc(strsSize * sizeof(int));
//     bool* visited = (bool*)calloc(strsSize, sizeof(bool));

//     for (int i = 0; i < strsSize; i++) {
//         if (visited[i]) {
//             continue;
//         }

//         visited[i] = true;
//         ret_arr[*returnSize] = (char**)malloc(strsSize * sizeof(char*));
//         int count = 0;

//         ret_arr[*returnSize][count++] = strs[i];

//         for (int j = i + 1; j < strsSize; j++) {
//             if (!visited[j]) {
//                 int len1 = strlen(strs[i]);
//                 int len2 = strlen(strs[j]);
//                 if (annagram(strs[i], strs[j], len1, len2)) {
//                     ret_arr[*returnSize][count++] = strs[j];
//                     visited[j] = true;
//                 }
//             }
//         }

//         (*returnColumnSizes)[*returnSize] = count;
//         (*returnSize)++;
//     }

//     free(visited);
//     return ret_arr;
// }



// optimised way: 

#define MAX_GROUPS 1000

// Helper function to sort a string
void sortStr(char* str, char* sorted) {
    strcpy(sorted, str);
    int len = strlen(sorted);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (sorted[i] > sorted[j]) {
                char temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
        }
    }
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    char*** ret_arr = (char***)malloc(sizeof(char**) * strsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * strsSize);
    char** keys = (char**)malloc(sizeof(char*) * strsSize);
    int* keyIndex = (int*)malloc(sizeof(int) * strsSize);

    int groupCount = 0;

    for (int i = 0; i < strsSize; i++) {
        char sorted[101];
        sortStr(strs[i], sorted);

        int found = -1;
        for (int j = 0; j < groupCount; j++) {
            if (strcmp(keys[j], sorted) == 0) {
                found = j;
                break;
            }
        }

        if (found == -1) {
            keys[groupCount] = strdup(sorted);
            ret_arr[groupCount] = (char**)malloc(sizeof(char*) * strsSize);
            ret_arr[groupCount][0] = strs[i];
            (*returnColumnSizes)[groupCount] = 1;
            groupCount++;
        } else {
            int idx = (*returnColumnSizes)[found];
            ret_arr[found][idx] = strs[i];
            (*returnColumnSizes)[found]++;
        }
    }

    *returnSize = groupCount;

    // Clean up
    for (int i = 0; i < groupCount; i++) {
        free(keys[i]);
    }
    free(keys);
    free(keyIndex);

    return ret_arr;
}
