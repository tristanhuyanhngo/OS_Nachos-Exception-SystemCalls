#include "syscall.h"
#include "copyright.h"

int main()
{
	int i = 0;
	PrintString("\n");
	PrintString("ASCII:\n");

	for (i; i <= 127; i++) {
		PrintInt(i);
		PrintString("\t");
		PrintChar(i);
		PrintString("\n");	
	}
	
	PrintString("THE END \n");

	Halt();

	return 0;
}
