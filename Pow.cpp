// ASM.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	__asm
	{
		jmp start

	Pow:
		;get parameters:
		push ebp
		mov ebp, esp
		sub esp, 12
		push ebx
		push ecx
		mov eax, [ebp + 8]	;eax = base
		mov ecx, [ebp + 12]	;ebx = exponent

		;body:
		mov ebx, eax
		dec ecx
	expo:
		mul ebx
		loop expo

		;before returning:
		pop ecx
		pop ebx
		add esp, 12
		pop ebp
		ret

	start:
		mov ebx, 8	;exponent
		mov eax, 2	;base
		push ebx
		push eax
		call Pow
	}
	return 0;
}

