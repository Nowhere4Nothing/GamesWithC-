//
// Created by Will&Carm on 20/12/2023.
//
#include <cstdio>
#include <iostream>

void update(int *a,int *b) {
    // Complete this function
    int tempA = *a;
    int tempB = *b;

    *a = (*b + *a);

    if (tempA > tempB) {
        *b = (tempA - tempB);
    } else {
        *b = (tempB - tempA);
    }


}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;

    std::cout << "Please input 2 numbers" << std::endl;
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}