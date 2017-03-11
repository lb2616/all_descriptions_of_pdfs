.text
.global _start
_start:
	b reset
	b undef
	b swi
	b abort_pre
	b abort_data
	b reserved
	b irq
	b fiq
reset:
	stmfd sp!,{r0-r12,lr}
	bl main
	ldmfd sp!,{r0-r12,pc}
undef:
	ldr sp,=0x30008000
	stmfd sp!,{r0-r12,lr}
	bl undef_handler
	ldmfd sp!,{r0-r12,pc}^
swi:
abort_pre:
abort_data:
reserved:
irq:
fiq:
