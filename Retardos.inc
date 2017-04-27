;Libreria con diferentes retardos para proposito general
;Timing = 6Tcy + [ (3Tcy*o + 5Tcy)*n + 7Tcy ]*m

RET2.56s:                ;retardo de 2.56s
    movlw   .0
    goto    start
RET2s:                ;retardo de 2s
    movlw   .200
    goto    start
RET1s:                ;retardo de 1s
    movlw   .100
    goto    start
RET500ms:                ;retardo de 500ms
    movlw   .50
    goto    start
RET400ms:                ;retardo de 400ms
    movlw   .40
    goto    start
RET300ms:                ;retardo de 300ms
    movlw   .30
    goto    start
RET200ms:                ;retardo de 200ms
    movlw   .20
    goto    start
RET100ms:                ;retardo de 100ms
    movlw   .10
    goto    start
RET90ms:                ;retardo de 90ms
    movlw   .9
    goto    start
RET80ms:                ;retardo de 80ms
    movlw   .8
    goto    start
RET70ms:                ;retardo de 70ms
    movlw   .7
    goto    start
RET60ms:                ;retardo de 60ms
    movlw   .6
    goto    start
RET50ms:                ;retardo de 50ms
    movlw   .5
    goto    start
RET40ms:                ;retardo de 40ms
    movlw   .4
    goto    start
RET30ms:                ;retardo de 30ms
    movlw   .3
    goto    start
RET20ms:                ;retardo de 20ms
    movlw   .2
    goto    start
RET10ms:                ;retardo de 10ms
    movlw   .1
    goto    start
start:
    movwf   m
    movlw   .29
    movwf   n
    movlw   .228
    movwf   o
    decfsz  o,1
        goto    $-1
    nop
    decfsz  n,1
        goto    $-6
    nop
    decfsz  m,1
        goto    $-.11
    nop
return

    RET2ms:                ;Retardo especial usado en la visualización estroboscopica
			   ;2.77ms para 8 MHz de reloj, la idea es refrescar a 60Hz 2.77ms*6 = 16.67ms = T de 60Hz
			   
    movlw   .1
    movwf   m
    movlw   .10
    movwf   n
    movlw   .183
    movwf   o
    decfsz  o,1
        goto    $-1
    nop
    decfsz  n,1
        goto    $-6
    nop
    decfsz  m,1
        goto    $-.11
    nop
return
