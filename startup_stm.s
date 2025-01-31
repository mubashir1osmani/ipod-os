.syntax unified
.cpu cortex-m4
.thumb

.global Reset_Handler

Reset_Handler:
    LDR r0, =_estack
    MOV sp, r0
    BL  SystemInit
    BL  main
    B   .