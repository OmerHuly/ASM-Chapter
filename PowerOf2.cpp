// ASM.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	__asm
	{
		jmp start

	Power_of_2:
		;get parameters:
		push ebp
		mov ebp, esp
		sub esp, 12
		push ebx	;keep ebx
		mov ecx, [ebp + 8]	;ecx = parm

		;body:
		xor eax, eax
		mov ebx, ecx
		mov ecx, 32
	Check:
		ror ebx, 1
		adc eax, 0
		loop Check
		sub eax, 1
		jz Finish
		mov eax, -1
	
	Finish:
		;before returning:
		pop ebx
		add esp, 12
		pop ebp
		ret

	start:
		call Power_of_2
	}
	return 0;
}

