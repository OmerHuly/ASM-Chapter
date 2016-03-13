// ASM.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

char str1[] = "Hello";
char str2[] = "World";

int _tmain(int argc, _TCHAR* argv[])
{
	__asm
	{
		jmp start

	ASM_Strcmp:
		;get parameters:
		push ebp
		mov ebp, esp
		sub esp, 12
		push esi
		push edi
		mov esi, [ebp + 8]	;esi -> str1
		mov edi, [ebp + 12]	;edi -> str2

		;body:
		;return 0 if strings are equal
		;return 1 if string 1 is larger (string 2 is smaller) 
		;return -1 if string 1 is smaller (string 2 is larger)
	Check:
		mov al, [esi]
		cmp al, [edi]	;compare str1[i] with str2[i]
		jnz not_equal
		inc esi			;++i -> str1
		inc edi			;++i -> str2
		test al, al		;check for terminating char
		jnz Check

	equal:
		xor eax, eax	;return 0 if strings are equal		
		jmp finish	

	not_equal:
		sbb eax, eax	;eax = 0 if str1 is greater and -1 if str2 is greater
		or eax, 1		;eax = 1 if str1 is greater and -1 if str2 is greater
		jmp finish		

	finish:
		;before returning:
		pop edi
		pop esi
		add esp, 12
		pop ebp
		ret	

	start:
		lea ebx, str2	;str2
		lea eax, str1	;str1
		push ebx
		push eax
		call ASM_Strcmp
	}
	return 0;
}

