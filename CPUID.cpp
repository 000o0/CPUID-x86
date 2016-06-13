#include "stdafx.h"

#include <stdio.h>

int* GetGPUID()
{
	__asm
	{
		mov eax,00h
		xor edx,edx
		cpuid
		mov dword ptr [ebp-4],edx
		mov dword ptr [ebp-8],eax

		mov eax,01h
		xor ecx,ecx
		xor edx,edx
		cpuid
		mov dword ptr [ebp-12],edx
		mov dword ptr [ebp-16],eax

		mov         eax,dword ptr [ebp-4]  
		mov         dword ptr [ebp-20],eax  
		mov         eax,dword ptr [ebp-8]  
		mov         dword ptr [ebp-24],eax  
		mov         eax,dword ptr [ebp-12]  
		mov         dword ptr [ebp-28],eax  
		mov         eax,dword ptr [ebp-16]  
		mov         dword ptr [ebp-32],eax  

		lea         eax, dword ptr[ebp-20]  
		pop         edi
		pop         esi
		pop         ebx
		mov         esp,ebp
		pop         ebp
		ret
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int* ptr = GetGPUID();
	int s1 = *ptr++;
	int s2 = *ptr++;
	int s3 = *ptr++;
	int s4 = *ptr;
	printf("%X%X%X%X", s1, s2, s3, s4);
	getchar();
	return 0;
}
