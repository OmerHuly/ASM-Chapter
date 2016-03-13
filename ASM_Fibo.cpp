// ASM.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	__asm
	{
		jmp start

	ASM_Fibo:
		;get parameters:
		push ebp
		mov ebp, esp
		sub esp, 12
		push cx
		mov eax, [ebp + 8]	;eax = n'th fibonacci number

		;body:
		;in C:
		;int Fibonacci(int n)
		;{
		;	if (n <= 1) {
		;		return 1;
		;	}
		;	else {
		;		return (Fibonacci(n-1) + Fibonacci(n-2));
		;	}
		;} 

		cmp eax, 1		
		jbe PreFinish	;n <= 1?
		dec eax			;eax = n-1
		push eax		;save n-1
		call ASM_Fibo	;eax = ASM_Fibo(n-1)
		xchg eax, [esp]	;eax = n-1 <-> ASM_Fibo(n-1) is saved
		dec eax			;eax = n-2
		push eax		;save n-2
		call ASM_Fibo	;eax = ASM_Fibo(n-2)
		pop ecx			;get n-2 out!
		pop ecx			;ecx = ASM_Fibo(n-1)
		add eax, ecx	;eax = ASM_Fibo(n-1) + ASM_Fibo(n-2)
		jmp finish

	PreFinish:
		mov eax, 1		;return 1
	finish:
		;before returning:
		pop cx
		add esp, 12
		pop ebp
		ret	

	start:
		mov eax, 4		;n'th fibonacci number
		push eax
		call ASM_Fibo
		pop eax
	}
	return 0;
}