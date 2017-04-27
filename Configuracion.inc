
;En est� secci�n se realizan las principales configuraciones necesarias para el correcto funcionamiento 
;del microcontrolador algunas de estas configuraciones son frecuencia del oscilador, Configuraci�n de los puertos
;y la inicializaci�n de las variables utilizadas en el programa
;adicionalemte se encuentra las palabras de condiguraci�n
    
__CONFIG _CONFIG1,   0XE3F4
__CONFIG _CONFIG2,   0XFEFF 
    
;Config_osc contiene la configuraci�n del oscilador
Conf_osc:
   bsf	    STATUS,RP0
   movlw    0xF1
   movwf    OSCCON
   bcf	    STATUS,RP0
return
   
;Esta rutina realiza la configuraci�n de los puertos de la siguiente manera:
;PORTA = 7 downto 1 para datos de 7 segment, 0 para entrada de inicio e iniciar la visualizaci�n del mensaje
;PORTE = Selecci�n de la temporizaci�n
;PORTC = habilitadores de los displays
Conf_P:
    ;0 salida, 1 entrada tristX X es el puerto
    bsf	    STATUS,RP0
    movlw   0x07
    movwf   TRISE
    movlw   0x80	;7 downto 1 para datos de 7segment, 0 para entrada de inicio
    movwf   TRISA
    movlw   0Xc0	;Habilitadores de displays
    movwf   TRISC
    
    ;'1' ANALOG, '0' DIGITAL  Ansel y anselh
    bsf     STATUS,RP1
    ;	BANKSEL	ANSEL
    ;	bsf	    STATUS,RP0
    ;	bsf	    STATUS,RP1
    clrf    ANSEL
    clrf    ANSELH
    bcf     STATUS,RP0
    bcf     STATUS,RP1
    clrf    PORTA
    clrf    PORTC
 return
  
;inicializa todas las variables presentes en el programa a ejecutar mediante el uso de direccionamiento indirecto
 val_inic:
    movlw   0x20
    movwf   FSR
    CLRF    INDF
    incf    FSR,1
    MOVLW   0x35
    XORWF   FSR,0
    BTFSS   STATUS,Z
        GOTO    $-5
return
    