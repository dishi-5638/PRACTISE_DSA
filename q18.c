#include <stdio.h>
#include <stdlib.h>
//The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
// Function prototype
// after changes
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize);

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    *returnSize = nums1Size;
    int* a = (int*)malloc(nums1Size * sizeof(int));
    for(int i=0;i<nums1Size;i++){
int found = 0;
int nextGreater = -1;
for(int j =0;j<nums2Size;j++){

    if (nums1[i] == nums2[j]) { 
        found = 1;  // Found the element in nums2
    }
    if (found && nums2[j] > nums1[i]) { 
        nextGreater = nums2[j];
        break;  // Stop at first greater element
    }
}
a[i] = nextGreater;
    }
    return a;
}

int main() {
    int nums1[] = {4, 1, 2};
    int nums2[] = {1, 3, 4, 2};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
    int returnSize;
    
    int* result = nextGreaterElement(nums1, nums1Size, nums2, nums2Size, &returnSize);
    
    printf("Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i < returnSize - 1) printf(", ");
    }
    printf("]\n");

    free(result); // Free allocated memory
    return 0;
}


