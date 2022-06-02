#include <sys/mman.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

#define MMAP_SZ ((1000000000) * 2 * 4ULL + 4ULL)


bool containsDuplicate(int* nums, int numsSize)
{

        int i;
        uint64_t mmap_sz = 4096ULL * ((MMAP_SZ - 1)/4096) + 4096ULL;

        char *p = mmap(NULL, mmap_sz,
                        PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);


        int *a = (int *)p;

        a = &a[1000000000];

        i = 0;

        for (i = 0; i < numsSize; i++) {
            if (a[nums[i]]) {
                munmap(p, mmap_sz);
                return true;
            }

            a[nums[i]] = 1;
        }

        munmap(p, MMAP_SZ);
        return false;
}
