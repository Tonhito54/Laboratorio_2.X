;Rutina que se encarga de la temporización, para ello decrementa como lo haría temporizador normal
;minutos y segundos desde 59 hasta 0 y horas desde 99 hasta 0 (Máximo 100 horas de temporización)
;En esta rutina se inicia evaluando el peso más bajo de todos, si es cero se decrementa el siguiente peso
;y este se inicializa con su valor máximo, pero si sigue este también es cero se decremente el siguiente peso y este
; se inicializa con el mayor peso y esto se repite hasta cumplir con el número de datos a decrementar
; por ejemplo si tenemos 55:00, se va a decrementa el peso más bajo, es decir 0, sin embargo es 0, por tanto cargamos
;Cargamos un 9 y decrementamos el siguiente, sin embargo vuelve a ser 0, por esa razón se carga un 5 y se decrementa el 
;siguiente peso, es decir 5, obteniendose como resultado 54:59
Decremento:
    call	Test_Z
    movlw	0x20
    movwf	FSR 
    btfsc	flag,0
	goto	$+3
    decf	INDF,1
return
    btfsc	flag,1
	goto	$+6
    movlw	.9
    movwf	INDF
    incf	FSR,1
    decf	INDF,1
return
    btfsc	flag,2
	goto	$+9
    movlw	.9
    movwf	INDF
    incf	FSR,1
    movlw	.5
    movwf	INDF
    incf	FSR,1
    decf	INDF,1
return
    btfsc	flag,3
	goto	$+.12
    movlw	.9
    movwf	INDF
    incf	FSR,1
    movlw	.5
    movwf	INDF
    incf	FSR,1
    movlw	.9
    movwf	INDF
    incf	FSR,1
    decf	INDF,1
return
    btfsc	flag,4
	goto	$+.15
    movlw	.9
    movwf	INDF
    incf	FSR,1
    movlw	.5
    movwf	INDF
    incf	FSR,1
    movlw	.9
    movwf	INDF
    incf	FSR,1
    movlw	.5
    movwf	INDF
    incf	FSR,1
    decf	INDF,1
return
    btfsc	flag,5
	goto	$+.18
    movlw	.9
    movwf	INDF
    incf	FSR,1
    movlw	.5
    movwf	INDF
    incf	FSR,1
    movlw	.9
    movwf	INDF
    incf	FSR,1
    movlw	.5
    movwf	INDF
    incf	FSR,1
    movlw	.9
    movwf	INDF
    incf	FSR,1
    decf	INDF,1
return
    bsf		flag,6
return
    
;EValua los registros de conteo para averiguar si son 0 o no y retorna un vector de 6 pocisiones
;con los ceros del conteo
Test_Z:
    clrf	flag
    clrf	i
    movlw	0x25
    movwf	FSR 
    movf	INDF,1
    btfss	STATUS,Z
	goto	$+3
    bsf	    STATUS,C
	goto	$+2
    bcf		STATUS,C
    rlf		flag,1
    incf	i,1
    decf	FSR,1
    movlw	.6
    xorwf	i,0
    btfss	STATUS,Z
	goto	$-.12
    return
    
;Rutina encargado del incremento. Sigue proceso secuencia similar al de decremento, sin embargo
;ahora se evalua el dato máximo de cada registro contantemente y si se desborda se inicializa en 0 y se incrementa el
;siguiente peso
;por ejemplo se tiene el número 4:59, al incrementar el primer byte (número 9), se tiene un 10, el cual es un dato de 
;desborde, por tanto se carga un 0 y se incrementa el siguiente, es decir el numero 5, sin embargo, este también 
;se desborda por tanto se carga un 0 y se incrementa el siguiente peso. El resultado es el número 5:00
;cumpliendo con el estandar de los relojs tipo crónometro
Incremento:
    btfsc	flag,7
	return
    clrf	flag
    clrf	j
    movlw	0x20
    movwf	FSR
I1: incf	INDF,1
    movlw	.10
    xorwf	INDF,0
    btfss	STATUS,Z
	return
    clrf	INDF
    incf	FSR,1
    incf	INDF,1
    movlw	.6
    xorwf	INDF,0
    btfss	STATUS,Z
	return
    clrf	INDF
    incf	FSR,1
    incf	j,1
    movlw	.2
    xorwf	j,0
    btfss	STATUS,Z
	goto	I1
    incf	INDF,1
    movlw	.10
    xorwf	INDF,0
    btfss	STATUS,Z
	return
;    clrf	INDF		;habilitar para contar 100 horas, si no cuenta hasta 10 horas
;    incf	FSR,1
;    incf	INDF,1
;    movlw	.10
;    xorwf	INDF,0
;    btfss	STATUS,Z
;	return
    movlw	.9  
    movwf	0x24
    movwf	0x22
    movwf	0x20
    movlw	.5
    movwf	0x21
    movwf	0x23
    bsf		flag,7
return
    
;Esta rutina evalua el datao ingresado por PORTE para cargar los valores correspondientes a los registros
; que se decrementaran en la futura ejecución del programa
Charge_data:
    MOVF    PORTE,0
    MOVWF   Dat_sel
    
    movlw   .00
    xorwf   Dat_sel,0
    btfss   STATUS,Z
        GOTO    TEMP_1
    MOVLW   0X20
    MOVWF   FSR
    CLRF    INDF
    INCF    FSR,1
    MOVLW   .5
    MOVWF   INDF
    return

    TEMP_1:
    movlw   .01
    xorwf   Dat_sel,0
    btfss   STATUS,Z
        GOTO    TEMP_2
    MOVLW   0X20
    MOVWF   FSR
    CLRF    INDF
    INCF    FSR,1
    MOVLW   .4
    MOVWF   INDF
    INCF    FSR,1
    MOVLW   .1
    MOVWF   INDF
    return

    TEMP_2:
    movlw   .02
    xorwf   Dat_sel,0
    btfss   STATUS,Z
        GOTO    TEMP_3
    MOVLW   0X20
    MOVWF   FSR
    CLRF    INDF
    INCF    FSR,1
    MOVLW   .3
    MOVWF   INDF
    INCF    FSR,1
    MOVLW   .2
    MOVWF   INDF
    return

    TEMP_3:
    movlw   .03
    xorwf   Dat_sel,0
    btfss   STATUS,Z
        GOTO    TEMP_4
    MOVLW   0X20
    MOVWF   FSR
    CLRF    INDF
    INCF    FSR,1
    MOVLW   .2
    MOVWF   INDF
    INCF    FSR,1
    MOVLW   .3
    MOVWF   INDF
    return

    TEMP_4:
    MOVLW   0X20
    MOVWF   FSR
    CLRF    INDF
    INCF    FSR,1
    MOVLW   .1
    MOVWF   INDF
    INCF    FSR,1
    MOVLW   .4
    MOVWF   INDF
    return

;Realiza la visualización estroboscopia. En ella se buscan los datos de los apuntadores (Dato apuntado de 
;cada display), se cargan por turnos al PORTA y se habilita el PORTC
Vis_Estrob:
    clrf	Hab_reg
    bsf		STATUS,C
    rlf		Hab_reg,1
    movlw	Time
    movwf	FSR
    movlw	0x08	    ;0x10
    movwf	PCLATH
    movf	INDF,0
    call	Tabla
    clrf	PCLATH
    movwf	PORTA
    movf	Hab_reg,0
    movwf	PORTC
    bcf		STATUS,C
    rlf		Hab_reg,1
    incf	FSR,1
    call	RET2ms
    clrf	PORTC
    btfss	Hab_reg,6
	goto	   $-.14	    ;-.13 si se quita el tag
    clrf	PORTC
RETURN
    
    ;Esta rutina se encarga de la gestión para la visualización de mensajes
    ;Las tablas tienen 50-40 posiciones para visualización
    Vis_mensaje:
    clrf    Lim_tab	    ;limite superior de la tabla
    clrf    Sum_Tab    
    clrf    flag2
    clrf    Cnt_vis
    clrf    Cnt_vis_aux
    ;Toma de decicion de que datos se debe cargar para la inicialización del mensaje
    movlw   .00
    xorwf   Dat_sel,0
    btfss   STATUS,Z
        GOTO    TABL_1 
    movlw	.11
    call	Inicio_banks
    movlw	.50	    ;limite 50
    movwf	Lim_tab
    ;Visualización común utilizada después de cargarse los datos de la selección hecha en puerto E
T_1:btfsc	flag2,0
	return
    clrf	con_Main
T_2:call	Vis_Estrob
    incf	con_Main,1
    movlw	.60		;----------------
    xorwf	con_Main,0
    btfsc	STATUS,Z
	goto	$+2
    goto	T_2
    call	Vis_dat
    goto	T_1
    
    TABL_1:
    movlw   .01
    xorwf   Dat_sel,0
    btfss   STATUS,Z
        GOTO    TABL_2
    movlw	.61
    call	Inicio_banks 
    movlw	.50
    movwf	Lim_tab
    goto	T_1
    
    TABL_2:
    movlw   .02
    xorwf   Dat_sel,0
    btfss   STATUS,Z
        GOTO    TABL_3
    movlw	.111
    call	Inicio_banks
    movlw	.40
    movwf	Lim_tab
    goto	T_1

    TABL_3:
    movlw   .03
    xorwf   Dat_sel,0
    btfss   STATUS,Z
        GOTO    TABL_4
    movlw	.151
    call	Inicio_banks
    movlw	.40
    movwf	Lim_tab
    goto	T_1

    TABL_4:
    movlw	.191
    call	Inicio_banks
    movlw	.40
    movwf	Lim_tab
    goto	T_1
    
;Rutina que cuenta hasta 6, luego no cuenta más
inc_Cnt_vis:
	movlw	    .6
	xorwf	    Cnt_vis,0
	btfss	    STATUS,Z
	    incf    Cnt_vis,1
return
	
;carga W a todos los registros apuntadores de la tabla (referentes a cada display)
Inicio_banks:
    movwf	0x20
    movwf	0x21
    movwf	0x22
    movwf	0x23
    movwf	0x24
    movwf	0x25
return
    
;Rutina que se encarga de hacer los incrementos de los registros apuntadores que contienes los datos a cargar
; en los display, este incremento se hace de forma secuencial, es decir, la primera vez se aumenta 1 registro,
; en la segunda ocasión se incrementan 2 registros, para ello se hace uso de la rutina inc_Cnt_vis, la cual permite 
; saber hasta que registro se puede iniciar    
Vis_dat:
    call	inc_Cnt_vis
    movf	Cnt_vis,0
    movwf	Cnt_vis_aux
    movlw	0x20
    movwf	FSR
    incf	INDF,1
    incf	FSR,1
    decfsz	Cnt_vis_aux,1
	goto	    $-3
    incf	Sum_Tab,1
    movf	Lim_tab,0
    xorwf	Sum_Tab,0
    btfsc	STATUS,Z
	bsf	flag2,0
    return
	
; inicialización de registros con mensaje de espera
ini_reg:    
    movlw	.231
    movwf	0x25
    movlw	.232
    movwf	0x24
    movlw	.233
    movwf	0x23
    movlw	.234
    movwf	0x22
    movlw	.235
    movwf	0x21
    movlw	.236
    movwf	0x20
return