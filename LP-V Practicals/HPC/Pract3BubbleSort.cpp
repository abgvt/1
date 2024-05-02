#include <iostream>
#include <stdlib.h>
#include <omp.h>
using namespace std;
void bubble(int *a, int n) {
for (int i = 0; i < n; i++) {
int first = i % 2;
#pragma omp parallel for shared(a, first)
for (int j = first; j < n - 1; j += 2) {
if (a[j] > a[j + 1]) {
swap(a[j], a[j + 1]);
}
}
}
}
int main() {
int *a, n;
cout << "Enter total no of elements: ";
cin >> n;
a = new int[n];
cout << "Enter elements: ";
for (int i = 0; i < n; i++) {
cin >> a[i];
}
bubble(a, n);
cout << "\nSorted array is: \n";
for (int i = 0; i < n; i++) {
cout << a[i] << " ";
}
cout << endl;
return 0;
}



/*
Output:
Enter total no of elements: 10
Enter elements: 10 9 3 4 2 1 8 6 7 5
Sorted array is:
1 2 3 4 5 6 7 8 9 10 */
