#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shell(int* items, int count) {
    int i, j, gap, k;
    int x, a[5] = {9, 5, 3, 2, 1};

    for (k = 0; k < 5; k++) {
        gap = a[k];
        for (i = gap; i < count; ++i) {
            x = items[i];
            for (j = i - gap; j >= 0 && items[j] > x; j -= gap) {
                items[j + gap] = items[j];
            }
            items[j + gap] = x;
        }
    }
}

void qs(int* items, int left, int right) {
    int i = left, j = right;
    int x = items[(left + right) / 2];
    int y;

    do {
        while (items[i] < x) i++;
        while (items[j] > x) j--;

        if (i <= j) {
            y = items[i];
            items[i] = items[j];
            items[j] = y;
            i++;
            j--;
        }
    } while (i <= j);

    if (left < j) qs(items, left, j);
    if (i < right) qs(items, i, right);
}

int main() {
    srand(time(NULL));
    clock_t starttime, endtime;
    int i = 0, max = 100, min = -100, c = 10000;
    int mas1[10000], mas2[10000], mas3[10000], mas4[10000];

    for (i = 0; i < c; i++) {
        mas1[i] = min + rand() % (max - min + 1);
        mas2[i] = i;
        mas3[i] = c - i;
        mas4[i] = (i <= c / 2) ? i : c - i;
    }

    starttime = clock();
    shell(mas1, c);
    endtime = clock();
    printf("shell1: %f\n", (float)(endtime - starttime) / CLOCKS_PER_SEC);

    for (i = 0; i < c; i++) {
        mas1[i] = min + rand() % (max - min + 1);
    }

    starttime = clock();
    qs(mas1, 0, c - 1);
    endtime = clock();
    printf("qs1: %f\n", (float)(endtime - starttime) / CLOCKS_PER_SEC);

    starttime = clock();
    shell(mas2, c);
    endtime = clock();
    printf("shell2: %f\n", (float)(endtime - starttime) / CLOCKS_PER_SEC);

    starttime = clock();
    qs(mas2, 0, c - 1);
    endtime = clock();
    printf("qs2: %f\n", (float)(endtime - starttime) / CLOCKS_PER_SEC);

    starttime = clock();
    shell(mas3, c);
    endtime = clock();
    printf("shell3: %f\n", (float)(endtime - starttime) / CLOCKS_PER_SEC);

    starttime = clock();
    qs(mas3, 0, c - 1);
    endtime = clock();
    printf("qs3: %f\n", (float)(endtime - starttime) / CLOCKS_PER_SEC);

    starttime = clock();
    shell(mas4, c);
    endtime = clock();
    printf("shell4: %f\n", (float)(endtime - starttime) / CLOCKS_PER_SEC);

    for (i = 0; i < c; i++) {
        mas4[i] = (i <= c / 2) ? i : c - i;
    }

    starttime = clock();
    qs(mas4, 0, c - 1);
    endtime = clock();
    printf("qs4: %f\n", (float)(endtime - starttime) / CLOCKS_PER_SEC);

    return 0;
}
