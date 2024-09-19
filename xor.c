#include <stdio.h>
#include <limits.h>

#define MAX_BITS 20 // Since 2^20 > 10^6, 20 bits are enough

// Function to find the minimum XOR sum
unsigned long long find_minimum_xor_sum(int n, int* numbers) {
    int bit_count[MAX_BITS] = {0};
    unsigned long long result_sum = 0;

    // Count the number of 1s in each bit position
    for (int i = 0; i < n; i++) {
        for (int bit = 0; bit < MAX_BITS; bit++) {
            if (numbers[i] & (1 << bit)) {
                bit_count[bit]++;
            }
        }
    }

    // Calculate the minimum sum based on each bit position
    for (int bit = 0; bit < MAX_BITS; bit++) {
        unsigned long long bit_value = 1ULL << bit;
        unsigned long long count_1 = bit_count[bit];
        unsigned long long count_0 = n - count_1;
        
        // Calculate the contribution of this bit to the minimum sum
        if (count_0 * bit_value < count_1 * bit_value) {
            result_sum += count_0 * bit_value;
        } else {
            result_sum += count_1 * bit_value;
        }
    }

    return result_sum;
}

int main() {
    int n;
    scanf("%d", &n);

    int numbers[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    // Compute and print the result
    unsigned long long result = find_minimum_xor_sum(n, numbers);
    printf("%llu\n", result);

    return 0;
}
