// ASM.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	__asm
	{
		xor eax, eax
		mov ecx, 100
	adding:
		add eax, ecx
		loop adding
	}
	return 0;
}

