; File: toupper.asm last updated 09/26/2001
;
; Convert user input to upper case.
;
; Assemble using NASM:  nasm -f elf toupper.asm
; Link with ld:  ld toupper.o
;

%define STDIN 0
%define STDOUT 1
%define SYSCALL_EXIT  1
%define SYSCALL_READ  3
%define SYSCALL_WRITE 4
%define BUFLEN 256


        SECTION .data                   ; initialized data section

msg1:   db "Text to be analyzed: "    	; user prompt
len1:   equ $-msg1                      ; length of first message

msg2:   db "You entered: "            	; original string label
len2:   equ $-msg2                      ; length of second message

msg3:   db "There were "               ; There were
len3:   equ $-msg3

msg4:   db 10, "Read error", 10         ; error message
len4:   equ $-msg4

msg5:	dq " alphabetic characters.", 10 ;string for alphabet
len5:	equ $-msg5

msg6:	dq " numeric characters.", 10 	;string for numbers
len6:	equ $-msg6

msg7:	dq " other characters.", 10	;string for other
len7:	equ $-msg7

numAlph:	dq '0'
numNum:		dq '0'
numOther:	dq '0'
	

        SECTION .bss                    ; uninitialized data section
buf:    resb BUFLEN                     ; buffer for read
newstr: resb BUFLEN                     ; converted string
rlen:   resb 4                          ; length


        SECTION .text                   ; Code section.
        global  _start                  ; let loader see entry point

_start: nop                             ; Entry point.
start:                                  ; address for gdb

        ; prompt user for input
        ;
        mov     eax, SYSCALL_WRITE      ; write function
        mov     ebx, STDOUT             ; Arg1: file descriptor
        mov     ecx, msg1               ; Arg2: addr of message
        mov     edx, len1               ; Arg3: length of message
        int     080h                    ; ask kernel to write

        ; read user input
        ;
        mov     eax, SYSCALL_READ       ; read function
        mov     ebx, STDIN              ; Arg 1: file descriptor
        mov     ecx, buf                ; Arg 2: address of buffer
        mov     edx, BUFLEN             ; Arg 3: buffer length
        int     080h

        ; error check
        ;
        mov     [rlen], eax             ; save length of string read
        cmp     eax, 0                  ; check if any chars read
        jg      read_OK                 ; >0 chars read = OK
        mov     eax, SYSCALL_WRITE      ; ow print error mesg
        mov     ebx, STDOUT		; Arge1: file descriptor
        mov     ecx, msg4		; move in error message
        mov     edx, len4		; move in length of error message
        int     080h			; ask kernel to write
        jmp     exit                    ; skip over rest
read_OK:


        ; Loop for upper case conversion
        ; assuming rlen > 0
        ;
L1_init:
        mov     ecx, [rlen]             ; initialize count
        mov     esi, buf                ; point to start of buffer
        mov     edi, newstr             ; point to start of new string
	
	
L1_top:
	
        mov     al, [esi]               ; get a character
        inc     esi                     ; update source pointer

	cmp     al, '\n'		; compare kernel to next line
	je      L1_end			; if so, jump to end of program
	
	cmp     al, 10			; compare kernel to ascii next line
	je      L1_end			; if so, jump to end of program
	
	cmp     al, 'a'                 ; less than 'a'?
        jb      L1_upper		; if so, jump to upper case
        cmp     al, 'z'                 ; more than 'z'?
        ja      L1_upper		; this gives us lower case letters

	mov     eax, [numAlph]		; start letter counter at 0;
	sub	eax, '0'		; convert to ascii
	mov	ebx, '1'		; move 1 to ebx register
	sub	ebx, '0'		; convert to ascii
	add	eax, ebx		; add eax and ebx together
	add	eax, '0'		; convert to decimal
	mov     [numAlph], eax		; move back to variable
	jmp	L1_store		; jump back to beginning of loop
L1_upper:

	cmp	al, 'A'			; less than 'A'?
	jb	L1_numer		; if so, jump to numbers
	cmp	al, 'Z'			; more than 'Z'?
	ja	L1_numer		; this is upper case letters

	mov     eax, [numAlph]		; start letter counter at 0;
	sub	eax, '0'		; convert to ascii
	mov	ebx, '1'		; move 1 to ebx register
	sub	ebx, '0'		; convert to ascii
	add	eax, ebx		; add numbers together
	add	eax, '0'		; convert to decimal
	mov     [numAlph], eax		; move back to variable
	jmp	L1_store		; jump back to beginning of loop
	
L1_numer:	

	cmp	al, '0'			; less than '0'?
	jb	L1_other		; if so, jump to others
	cmp	al, '9'			; more than '9'?
	ja	L1_other		; these are numbers

	mov     eax, [numNum]		; start letter counter at 0;
	sub	eax, '0'		; convert to ascii
	mov	ebx, '1'		; move 1 to ebx register
	sub	ebx, '0'		; convert to ascii
	add	eax, ebx		; add numbers together
	add	eax, '0'		; convert to decimal
	mov     [numNum], eax		; move back to variable
	jmp	L1_store		; jump to top of loop
	
L1_other:	

	mov     eax, [numOther]		; start letter counter at 0;
	sub	eax, '0'		; convert to ascii
	mov	ebx, '1'		; move 1 to ebx register
	sub	ebx, '0'		; convert to ascii
	add	eax, ebx		; add numbers togher
	add	eax, '0'		; convert to decimal
	mov     [numOther], eax		; move back to variable
	
L1_store:	
	 mov     [edi], al		; store char in new string
	 inc     edi			; update dest pointer
	 dec     ecx			; update char count
	 jnz     L1_top			; loop to top if more chars 
	
L1_end:


        ; print out user input for feedback
        ;
        mov     eax, SYSCALL_WRITE      ; write message
        mov     ebx, STDOUT		
        mov     ecx, msg2		; move msg2 into register 
        mov     edx, len2
        int     080h			; ask kernel to write	 

        mov     eax, SYSCALL_WRITE      ; write user input
        mov     ebx, STDOUT
        mov     ecx, buf		; move user input into register
        mov     edx, [rlen]
        int     080h			; ask kernel to write

        ; print out converted string
        ;
        mov     eax, SYSCALL_WRITE      ; write message
        mov     ebx, STDOUT
        mov     ecx, msg3
        mov     edx, len3
        int     080h

        mov     eax, SYSCALL_WRITE      ; write out string
        mov     ebx, STDOUT
        mov     ecx, numAlph
        mov     edx, 1
        int     080h

	mov     eax, SYSCALL_WRITE ; write out string
	mov     ebx, STDOUT
	mov     ecx, msg5
	mov     edx, len5
        int     080h

	mov     eax, SYSCALL_WRITE ; write message
	mov     ebx, STDOUT
	mov     ecx, msg3
	mov     edx, len3
	int     080h

	mov     eax, SYSCALL_WRITE ; write out string
	mov     ebx, STDOUT
	mov     ecx, numNum
	mov     edx, 1
	int     080h

	mov     eax, SYSCALL_WRITE ; write out string
	mov     ebx, STDOUT
	mov     ecx, msg6
	mov     edx, len6
	int     080h

	mov     eax, SYSCALL_WRITE ; write message
	mov     ebx, STDOUT
	mov     ecx, msg3
	mov     edx, len3
	int     080h

	mov     eax, [numOther]	   ; start letter counter at 0;
	mov     eax, SYSCALL_WRITE ; write out string
	mov     ebx, STDOUT
	mov     ecx, numOther
	mov     edx, 1
	int     080h

	mov     eax, SYSCALL_WRITE ; write out string
	mov     ebx, STDOUT
	mov     ecx, msg7
	mov     edx, len7
	int     080h

        ; final exit
        ;
exit:   mov     eax, SYSCALL_EXIT       ; exit function
        mov     ebx, 0                  ; exit code, 0=normal
        int     080h                    ; ask kernel to take over
