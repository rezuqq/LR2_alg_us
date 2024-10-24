#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shell(int* items, int count);
void qs(int* items, int left, int right);
int cmp(const void* a, const void* b);

int main() {
    int z = 0, volume = 200000;
    long int start_time = 0, end_time = 0, compare_time = 0;
    int* a = (int*)malloc(volume * sizeof(int));
    int* b = (int*)malloc(volume * sizeof(int));
    int* c = (int*)malloc(volume * sizeof(int));

    printf("now sorting randomized arrays\n");
    srand(time(NULL));

    for (int i = 0; i < volume; i++) {
        a[i] = rand() % 100 + 1;
        b[i] = rand() % 100 + 1;
        c[i] = rand() % 100 + 1;
    }

    printf("shell() sort\n");
    start_time = clock();
    shell(a, volume);
    end_time = clock();
    compare_time = end_time - start_time;
    printf("sort time: %.3f\n\n", compare_time / 1000.0);

    printf("qs() sort\n");
    start_time = clock();
    qs(b, 0, volume - 1);
    end_time = clock();
    compare_time = end_time - start_time;
    printf("sort time: %.3f\n\n", compare_time / 1000.0);

    printf("qsort() sort\n");
    start_time = clock();
    qsort(c, volume, sizeof(int), cmp);
    end_time = clock();
    compare_time = end_time - start_time;
    printf("sort time: %.3f\n", compare_time / 1000.0);
    z++;

    printf("----------------------\n\n");

    printf("now sorting arrays consisting of increasing sequence\n");
    for (int i = 0; i < volume; i++) {
        a[i] = i;
        b[i] = i;
        c[i] = i;
    }

    printf("shell() sort\n");
    start_time = clock();
    shell(a, volume);
    end_time = clock();
    compare_time = end_time - start_time;
    printf("sort time: %.3f\n\n", compare_time / 1000.0);

    printf("qs() sort\n");
    start_time = clock();
    qs(b, 0, volume - 1);
    end_time = clock();
    compare_time = end_time - start_time;
    printf("sort time: %.3f\n\n", compare_time / 1000.0);

    printf("qsort() sort\n");
    start_time = clock();
    qsort(c, volume, sizeof(int), cmp);
    end_time = clock();
    compare_time = end_time - start_time;
    printf("sort time: %.3f\n", compare_time / 1000.0);
    z++;

    printf("----------------------\n\n");

    printf("now sorting arrays consisting of decreasing sequence\n");
    for (int i = 0, j = volume - 1; i < volume; i++, j--) {
        a[i] = j;
        b[i] = j;
        c[i] = j;
    }

    printf("shell() sort\n");
    start_time = clock();
    shell(a, volume);
    end_time = clock();
    compare_time = end_time - start_time;
    printf("sort time: %.3f\n\n", compare_time / 1000.0);

    printf("qs() sort\n");
    start_time = clock();
    qs(b, 0, volume - 1);
    end_time = clock();
    compare_time = end_time - start_time;
    printf("sort time: %.3f\n\n", compare_time / 1000.0);

    printf("qsort() sort\n");
    start_time = clock();
    qsort(c, volume, sizeof(int), cmp);
    end_time = clock();
    compare_time = end_time - start_time;
    printf("sort time: %.3f\n", compare_time / 1000.0);
    z++;

    printf("----------------------\n\n");

    printf("now sorting half-increasing and half-decreasing sequence of numbers arrays\n");
    for (int i = 0, j = volume - 1; i < volume; i++, j--) {
        if (i <= volume / 2 - 1) {
            a[i] = i;
            b[i] = i;
            c[i] = i;
        }
        else {
            a[i] = j;
            b[i] = j;
            c[i] = j;
        }
    }

    printf("shell() sort\n");
    start_time = clock();
    shell(a, volume);
    end_time = clock();
    compare_time = end_time - start_time;
    printf("sort time: %.3f\n\n", compare_time / 1000.0);

    printf("qs() sort\n");
    start_time = clock();
    qs(b, 0, volume - 1);
    end_time = clock();
    compare_time = end_time - start_time;
    printf("sort time: %.3f\n\n", compare_time / 1000.0);

    printf("qsort() sort\n");
    start_time = clock();
    qsort(c, volume, sizeof(int), cmp);
    end_time = clock();
    compare_time = end_time - start_time;
    printf("sort time: %.3f\n");

    free(a);
    free(b);
    free(c);
    z++;

    printf("----------------------\n\n");

    printf("done!\n");
}

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void shell(int* items, int count) {
    int i, j, gap, k;
    int x, a[5] = { 9, 5, 3, 2, 1 };

    for (k = 0; k < 5; k++) {
        gap = a[k];
        for (i = gap; i < count; ++i) {
            x = items[i];
            for (j = i - gap; (j >= 0) && (x < items[j]); j -= gap) {
                items[j + gap] = items[j];
            }
            items[j + gap] = x;
        }
    }
}

void qs(int* items, int left, int right) {
    while (left < right) {
        int i = left, j = right;
        int x = items[(left + right) / 2], y;

        do {
            while (items[i] < x) i++;
            while (x < items[j]) j--;

            if (i <= j) {
                y = items[i];
                items[i] = items[j];
                items[j] = y;
                i++;
                j--;
            }
        } while (i <= j);
        if (j - left < right - i) {
            qs(items, left, j);
            left = i;
        }
        else {
            qs(items, i, right);
            right = j;
        }
    }
}
