.extern main, _crt_init, _crt_deinit
.extern md407_runtime_uartinit, md407_runtime_portinit, md407_runtime_clockinit

.section .start_section
startup:
    LDR R0,=__stack_top      @ set stack pointer
    MOV SP,R0
    BL md407_runtime_clockinit
    BL md407_runtime_portinit
    BL md407_runtime_uartinit
    BL _crt_init            @ init C-runtime
    BL main                 @ call main 
    BL _crt_deinit          @ deinit C-runtime
.L1: 
    B .L1                   @ never return
