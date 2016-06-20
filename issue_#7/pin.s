	.file	"pin.cpp"
	.text
	.globl	_Z8functionv
	.type	_Z8functionv, @function
_Z8functionv:
.LFB5:
	.cfi_startproc
	orb	$4, 42
	orb	$4, 43
	ret
	.cfi_endproc
.LFE5:
	.size	_Z8functionv, .-_Z8functionv
	.ident	"GCC: (Ubuntu 5.3.1-14ubuntu2.1) 5.3.1 20160413"
	.section	.note.GNU-stack,"",@progbits
