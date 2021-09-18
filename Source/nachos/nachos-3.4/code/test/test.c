#include "syscall.h"
#include "copyright.h"

int main()
{
	int number;
	PrintString("Enter a number: ");
	number = ReadInt();
	PrintString("\n");
	PrintString("Your number: ");
	PrintInt(number);
	PrintString("\n");
	Halt();
	return 0;
}
