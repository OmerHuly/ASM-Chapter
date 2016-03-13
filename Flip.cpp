// ASM.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	__asm
	{
		jmp start

	Flip:
		;get parameters:
		push ebp
		mov ebp, esp
		sub esp, 12
		push ebx	;keep ebx
		push ecx	;keep eax
		mov eax, [ebp + 8]	;ecx = parm

		;body:
		;eax = 0x12345678
		mov cl, 4
		ror al, cl	;eax = 0x12345687
		mov cl, 8
		ror ax, cl	;eax = 0x12348756
		mov cl, 4
		ror al, cl	;eax = 0x12348765
		mov cl, 16
		rol eax, cl ;eax = 0x87651234
		mov cl, 4
		ror al, cl	;eax = 0x87651243
		mov cl, 8
		ror ax, cl	;eax = 0x87654312
		mov cl, 4
		ror al, cl	;eax = 0x87654321
	
	Finish:
		;before returning:
		pop ecx
		pop ebx
		add esp, 12
		pop ebp
		ret

	start:
		call Flip
	}
	return 0;
}

