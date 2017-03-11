.text
.global _start
_start:
	b reset
	b undef
	b swi
	b abort_pre
	b abort_data
	b irq
	b fiq
reset:
	stmfd sp!,{r0-r12,lr}
	mrs r0,cpsr
	bic r0,r0,#0x80  @清除 clear to 0,enable MCU irq
	bl main
	ldmfd sp!,{r0-r12,pc}
undef:

swi:	
abort_pre:
abort_data:
reserved:
irq:
	ldr sp,=0x30008000
	stmfd sp!,{r0-r12,lr}
	bl irq_handler
	ldmfd sp!,{r0-r12,pc}^
	subs pc,lr,#4
fiq:

