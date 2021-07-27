// exception.cc 
//	Entry point into the Nachos kernel from user programs.
//	There are two kinds of things that can cause control to
//	transfer back to here from user code:
//
//	syscall -- The user code explicitly requests to call a procedure
//	in the Nachos kernel.  Right now, the only function we support is
//	"Halt".
//
//	exceptions -- The user code does something that the CPU can't handle.
//	For instance, accessing memory that doesn't exist, arithmetic errors,
//	etc.  
//
//	Interrupts (which can also cause control to transfer from user
//	code into the Nachos kernel) are handled elsewhere.
//
// For now, this only handles the Halt() system call.
// Everything else core dumps.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
#include "syscall.h"

//----------------------------------------------------------------------
// ExceptionHandler
// 	Entry point into the Nachos kernel.  Called when a user program
//	is executing, and either does a syscall, or generates an addressing
//	or arithmetic exception.
//
// 	For system calls, the following is the calling convention:
//
// 	system call code -- r2
//		arg1 -- r4
//		arg2 -- r5
//		arg3 -- r6
//		arg4 -- r7
//
//	The result of the system call, if any, must be put back into r2. 
//
// And don't forget to increment the pc before returning. (Or else you'll
// loop making the same system call forever!
//
//	"which" is the kind of exception.  The list of possible exceptions 
//	are in machine.h.
//----------------------------------------------------------------------

void IncreasePC()
{
	int counter = machine->ReadRegister(PCReg);		//read the contents of current PCregister and assign into counter variable
	machine->WriteRegister(PrevPCReg, counter);		//store counter variable into previous PCregister
	counter = machine->ReadRegister(NextPCReg);		//read the contents of next PCregister and assign into counter variable
	machine->WriteRegister(PCReg, counter);			//store counter variable into current PCregister
	machine->WriteRegister(NextPCReg, counter + 4);	//store counter + 4 variable into next PCregister
	return;
}

void ExceptionHandler(ExceptionType which)
{
    int type = machine->ReadRegister(2);

	switch (which)
	{
	case SyscallException:
		switch (type)
		{
		case SC_Halt:
			DEBUG('a', "Shutdown, initiated by user program.\n"); // utility.cc
			interrupt->Halt();
			break;
		case SC_Exit:
			interrupt->Halt();
			IncreasePC();
			break;
		case SC_Exec:
			interrupt->Halt();
			IncreasePC();
			break;
		case SC_Join:
			interrupt->Halt();
			IncreasePC();
			break;
		case SC_Create:
			interrupt->Halt();
			IncreasePC();
			break;
		case SC_Open:
			interrupt->Halt();
			IncreasePC();
			break;
		case SC_Read:
			interrupt->Halt();
			IncreasePC();
			break;
		case SC_Write:
			interrupt->Halt();
			IncreasePC();
			break;
		case SC_Close:
			interrupt->Halt();
			IncreasePC();
			break;
		case SC_Fork:
			interrupt->Halt();
			IncreasePC();
			break;
		case SC_Yield:
			interrupt->Halt();
			IncreasePC();
			break;
		}
		break;

	// Tra quyen dieu khien ve cho he dieu hanh
	case NoException:
		return;

	// Hien thi ra thong bao loi va Halt he thong
	case PageFaultException:
		printf("PageFault Error - No valid translation found !");
		interrupt->Halt();
		break;
	case ReadOnlyException:
		printf("ReadOnly Error - Write attempted to page marked read-only !");
		interrupt->Halt();
		break;
	case BusErrorException:
		printf("Bus Error - Translation resulted in an invalid physical address !");
		interrupt->Halt();	
		break;
	case AddressErrorException:
		printf("Address Error - Unaligned reference or one that was beyond the end of the address space");
		interrupt->Halt();
		break;
	case OverflowException:
		printf("Overflow Error - Integer overflow in add or sub !");
		interrupt->Halt();
		break;
	case IllegalInstrException:
		printf("Illegal In Str Error - Unimplemented or reserved instr !");
		interrupt->Halt();
		break;
	case NumExceptionTypes:
		printf("Num Types Error ! ");
		interrupt->Halt();
		break;
	default:
		printf("Unexpected user mode exception %d %d\n", which, type);
		ASSERT(FALSE);
	}

}
