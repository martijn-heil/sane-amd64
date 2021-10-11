%define NULL 0
%define false 0
%define true 1

%macro saveregs 0
  push r10
  push r11
  push r12
  push r13
  push r14
  push r15
%endmacro

%macro restoreregs 0
  pop r15
  pop r14
  pop r13
  pop r12
  pop r11
  pop r10
%endmacro


;  More sane register names. Helps dealing with the cognitive load of register allocation.
;  The main downside is with very specific instructions which change specific registers,
;  but those are not used extremely often anyway.
;
;  This is unconventional but I don't really give a damn, especially considering
;  this is a private hobby project.
;
;  The logic of this comes from the System V ABI for amd64.
;  The first six integer or pointer arguments are passed in
;  the registers RDI, RSI, RDX, RCX, R8, R9 (all old style);
;  so with these new definitions that would now be  r1, r2, r3, r4, r5, r6.
;
;  The return value is put in r8. If the return value is 128 bits in size then
;  the high 64 bits go in rdx(old style), which is now r3
;
;
;  r10(old style) in System V ABI is a static chain pointer, now that register is called r7
;  following on the last function argument register.
;
;  The registers r10, r11, r12, r13, r14, r15 are callee-saved.
;
;
;  Linux system calls don't quite use the same argument passing convention as the System V ABI does,
;  The order of arguments for linux system calls will now be r1, r2, r3, r7(!), r5, r6
;
;
;  the RSP (stack pointer) register is unchanged as it is not a general purpose register.
;  What was previously RBP is now r11
;
;  Personally I think this clears up the register naming a lot, and you don't have to
;  remember the seemingly random order for argument passing.


; Function argument registers
%define r1  RDI
%define r1d EDI
%define r1w DI
%define r1b DL

%define r2  RSI
%define r2d ESI
%define r2w SI
%define r2b SL

%define r3  RDX
%define r3d EDX
%define r3w DX
%define r3b DL

%define r4  RCX
%define r4d ECX
%define r4w CX
%define r4b CL

%define r5  R8
%define r5d R8D
%define r5w R8W
%define r5b R8B

%define r6  R9
%define r6d R9D
%define r6w R9W
%define r6b R9B

; Static chain pointer and used for some Linux system calls as argument register
; inbetween RCX and R8
%define r7  R10
%define r7d R10D
%define r7w R10W
%define r7b R10B

; Return value
%define r8  RAX
%define r8d EAX
%define r8w AX
%define r8b AL

; Remaining registers
%define r9  R11
%define r9d R11D
%define r9w R11W
%define r9b R11B

; The following  are all callee-saved

%define r10  RBX
%define r10d EBX
%define r10w BX
%define r10b BL

%define r11  RBP
%define r11d EBP
%define r11w BP
%define r11b BL
; Registers r12, r13, r14 and r15 stay the same, also callee-saved
