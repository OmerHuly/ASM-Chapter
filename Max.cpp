// ASM.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	__asm
	{
		jmp start

	Max:
		;get parameters:
		push ebp
		mov ebp, esp
		mov eax, [ebp + 8]	;eax = parm1
		mov ebx, [ebp + 12]	;ebx = parm2
		mov ecx, [ebp + 16]	;ecx = parm3

		;body:
	Check1:	
		cmp eax, ecx
		jnc Check2
		mov eax, ecx
	Check2:
		cmp eax, ebx
		jnc Finished
		mov eax, ebx
	Finished:

		;before returning:
		pop ebp
		ret

	start:
		call Max
	}
	return 0;
}

