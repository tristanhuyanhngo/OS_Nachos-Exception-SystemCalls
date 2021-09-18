#include "syscall.h"
#include "copyright.h"

int main()
{
	char str[200];
	PrintString("Input 1 string:  ");
	ReadString(str, 200);
	PrintString("\n");
	PrintString("Your string: ");
	PrintString(str);
	PrintString("\n");
	Halt();
	return 0;
}
