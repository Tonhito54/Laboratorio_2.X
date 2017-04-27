
;   Programa temporizador que muestra mensajes tipo Publik con el uso de displays de 7 Segmentos.
;   Presenta por Alejandro Antonio Núñez Bonilla y Jimy Alejandro Corredor Alvarez
;   Códigos 201220574 y 2012011407
    
list p=16F887
    
#include    "p16f887.inc"
    
CBLOCK	0x20
    Time:6          ;0x20,0x21  seg, 0x22,0x23  min, 0x24,0x25  hora en modo de temporización,
		    ;Además son los apuntadores de las tablas de cada display
    flag            ;(0 up to 5) zero en los números a descontar, b6, acabo la temporización, b7, no se puede
		    ;incrementar más
    flag2	    ;0, acabo el mensaje a visualizar
    m		    ;usado en la libreria de retardos
    n               ;usado en la libreria de retardos
    o		    ;usado en la libreria de retardos
    Dat_sel         ;selección del temporizador
    i		    ;contador auxiliar de Test_Z
    j		    ;Usado como contador en la rutina incremento
    Hab_reg	    ;registro habilitador (contiene los datos de la siguiente habilitación por puerto C)
    Apunt_tab	    ;apuntador de la tabla
    con_Main	    ;contador del main para vis estrob
    Cnt_vis	    ;usado en la rutina de visualización del mensaje como referencia
    Cnt_vis_aux	    ;usado en la rutina de visualización del mensaje como decrementador
    Lim_tab	    ;limite superior de la tabla en cada tipo de mensaje usado
    Sum_Tab	    ;apuntador sup de la tabla
ENDC	
    
ORG .0
;Algunas configuraciones iniciales
call	Conf_osc
call	Conf_P
GOTO	Main
ORG .5	    ;Se evita ocupar el vector de interrupciones
Main:
    ;inicialización de registros 
    call	val_inic
    call	ini_reg		;inicializa los registros con la posición de espera
    ;Se toma la desición para iniciar la temporización, si no se inicia se realiza visualización estroboscopica 
    ;de , se esperan 20ms para evitar confusiones con el ruido
    ;mecanico
    call	Vis_Estrob	
    btfsc	PORTA,7		
	goto	    $-2
    call	RET20ms
    btfsc	PORTA,7
	goto	    $-4
;inicializa los apuntadores de la tabla (temporización) para evitar futuros errores en lso decrementos.
    call	val_inic
;inicializacion de datos del temporizador
    call	Charge_data
M_2:btfsc	flag,6	    ;bandera de la finalización de la temporización (incluye el 0), aquí se evalua si hay que
			    ;comenzar el conteo negativo
	goto	    Fin_temp
    clrf	con_Main	;se borran los datos del registro contador de la visualización estroboscopia
M_1:call	Vis_Estrob	;Visualización estroboscopica con duración de 16.67ms
    incf	con_Main,1	; se cuentan 60 visualizaciones estroboscopicas para contar con un tiempo de 
				;espera de 1s
    movlw	.60			;--------------------
    xorwf	con_Main,0
    btfss	STATUS,Z
	goto	$+3
    call	Decremento	;Rutina que decrementa el tiempo temporizado
    goto	M_2
    goto	M_1
Fin_temp:		;Aquí ya se ha acabado la temporización, por tanto se evalua frecuentemente
			;el boton que habilita el inicio de la muestra del mensaje
    call	Incremento	;Rutina que cronometriza de forma "negativa" (Máximo 10 horas)
    clrf	con_Main
    movlw	.10		;Se carga el dato de la posición del signo negativo a Time[5] 
    movwf	0x25
M_3:call	Vis_Estrob	;visualización estroboscopica
    ;Evaluación para iniciar la muestra del mensaje que evita el ruido mecanico
    btfsc	PORTA,7
	goto	    M_5
    call	RET20ms
    btfsc	PORTA,7
	goto	    M_5
    ;--------Rutina de visulización de mensajes-
    call	Vis_mensaje
    goto	Fin
    ;-------------------------------------------
    ; se hacen 6 visualizaciones estroboscopicas para un total de 1s
M_5:incf	con_Main,1
    movlw	.60		;-------------------------
    xorwf	con_Main,0
    btfss	STATUS,Z
	goto	M_4
    goto	Fin_temp
M_4:goto	M_3
Fin:   
    goto    Main
#include    "Configuracion.inc"  
#include    "Retardos.inc"
#include    "Rutinas_Temp.inc"
#include    "Tabla.inc"
end    
    


    


		    

