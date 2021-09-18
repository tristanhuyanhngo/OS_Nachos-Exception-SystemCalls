#include "syscall.h"
#include "copyright.h"

int main()
{
	int MAX_ARRAY = 101;
	int A[MAX_ARRAY];
	int n = 0;
	int temp = 0;
	int i = 0;
	int j = 0;
	
	PrintString("\n");

	// Length of Array
	while (n <= 0 || n > 100) {
		PrintString("How many element(s) that you want to create (0 < n <= 100) ? ");
		n = ReadInt();
	}
	
	// Input Array
	for (i = 0; i < n; i++) {
		A[i] = ReadInt();
	}
	
	// Bubble Sort
	for (i = 1; i < n; i++) {
		for (j = n - 1; j >= i; j--) {
			if (A[j] < A[j - 1]) {
				temp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = temp;
			}
		}
	}
	
	// Output
	PrintString("Array after sorted ! \n");

	for (i = 0; i < n; i++) {
		PrintInt(A[i]);
		PrintString("\t");
	}	
	
	PrintString("\n");
	Halt();

	return 0;
}
