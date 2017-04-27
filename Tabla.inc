
;Esta libreria contiene las tablas de los mensajes de visualización y los caracteres númericos utilizados
;Ubicada en pagina 1, contiene 5 mensajes, los números y lso caracteres del mensaje de espera.
org	0x0800	    ;0x1000
Tabla:
    addwf	PCL,1
    DT	0x3f		;0		b'00111111'
    DT	0x06		;1		
    DT	0x5b		;2		
    DT	0x4f		;3		
    DT	0x66		;4		
    DT	0x6d		;5		
    DT	0x7d		;6		
    DT	0x07		;7		
    DT	0x7f		;8		
    DT	0x67		;9
    DT	0x40		;Simbolo negativo   ;pos 10
    
    ;MENSAJE	1
    DT	0X00		;VACIO
    DT	0x6d		;S		
    DT	0X79		;E
    DT	0X00		;space
    DT	0X76		;H
    DT	0X77		;A
    DT	0X00		;space
    DT	0X71		;F
    DT	0X30		;I
    DT	0X54		;N
    
    DT	0X77		;A
    DT	0X38		;L
    DT	0X30		;I
    DT	0X5B		;Z
    DT	0X77		;A
    DT	0X5E		;D
    DT	0X5c		;O
    DT	0X00		;space
    DT	0X38		;L
    DT	0X77		;A
    
    DT	0X00		;space
    DT	0X79		;E
    DT	0x6d		;S
    DT	0X73		;P
    DT	0X79		;E
    DT	0X50		;R
    DT	0X77		;A
    DT	0X00		;space
    DT	0x6d		;5
    DT	0x3f		;0
    
    DT	0X00		;space
    DT	0x6d		;S		
    DT	0X79		;E
    DT	0X6F		;G
    DT	0X3E		;U
    DT	0X54		;N
    DT	0X5E		;D
    DT	0X5c		;O
    DT	0x6d		;S
    DT	0X00		;VACIO
    
    DT	0X00		;VACIO		;sumando 5 espacios m1, es decir extesión de 45
    DT	0X00		;VACIO
    DT	0X00		;VACIO
    DT	0X00		;VACIO
    DT	0X00		;VACIO
    DT	0X00		;VACIO
    DT	0X00		;VACIO
    DT	0X00		;VACIO
    DT	0X00		;VACIO
    DT	0X00		;VACIO	    
    
    ;MENSAJE 2
    DT	0X00		;VACIO
    DT	0X76		;H
    DT	0X77		;A
    DT	0X00		;space
    DT	0X39		;C
    DT	0X5c		;O
    DT	0X54		;N
    DT	0X39		;C
    DT	0X38		;L
    DT	0X3E		;U
    
    DT	0X30		;I
    DT	0X5E		;D
    DT	0X5c		;O
    DT	0X00		;space
    DT	0X38		;L
    DT	0X77		;A
    DT	0X00		;space
    DT	0X79		;E
    DT	0x6d		;S
    DT	0X73		;P
    
    DT	0X79		;E
    DT	0X50		;R
    DT	0X77		;A
    DT	0X00		;space
    DT	0x06		;1
    DT	0x3f		;0		
    DT	0x3f		;0
    DT	0X00		;space
    DT	0x6d		;S		
    DT	0X79		;E
    
    DT	0X6F		;G
    DT	0X3E		;U
    DT	0X54		;N
    DT	0X5E		;D
    DT	0X5c		;O
    DT	0x6d		;S
    DT	0X00		;VACIO
    DT	0X00		;VACIO
    DT	0X00		;VACIO
    DT	0X00		;VACIO
    
    DT	0X00		;VACIO	    ;Sumando 2 espacios a m2, extensión 42
    DT	0X00		;VACIO
    DT	0X00		;VACIO
    DT	0X00		;VACIO
    DT	0X00		;VACIO
    DT	0X00		;VACIO
    DT	0X00		;VACIO
    DT	0X00		;VACIO
    DT	0X00		;VACIO
    DT	0X00		;VACIO
    
    
;MENSAJE    3
    DT	0X00		;space
    DT	0x06		;1		
    DT	0x6d		;5
    DT	0x3f		;0
    DT	0X00		;space
    DT	0x6d		;S		
    DT	0X79		;E
    DT	0X6F		;G
    DT	0X3E		;U
    DT	0X54		;N
    
    DT	0X5E		;D
    DT	0X5c		;O
    DT	0x6d		;S
    DT	0X00		;space
    DT	0X76		;H
    DT	0X77		;A
    DT	0X54		;N
    DT	0X00		;space
    DT	0X78		;T  		
    DT	0X50		;R
    
    DT	0X77		;A
    DT	0X54		;N
    DT	0x6d		;S
    DT	0X39		;C
    DT	0X3E		;U
    DT	0X50		;R
    DT	0X50		;R
    DT	0X30		;I
    DT	0X5E		;D
    DT	0X5c		;O
    
    DT	0X00		;space
    DT	0X6F		;G
    DT	0X73		;P
    DT	0x6d		;S
    DT	0X00		;space
    DT	0X00		;space
    DT	0X00		;space
    DT	0X00		;space
    DT	0X00		;space
    DT	0X00		;space		;extension normal
    
    ;mensaje	4
    
    DT	0X00		;space
    DT	0X77		;A
    DT	0X50		;R
    DT	0X30		;I
    DT	0X6F		;G
    DT	0X77		;A
    DT	0X78		;T
    DT	0X5c		;O
    DT	0X00		;space
    DT	0x5b		;2
    
    DT	0x3f		;0		
    DT	0x3f		;0
    DT	0x6d		;S		
    DT	0X79		;E
    DT	0X6F		;G
    DT	0X3E		;U
    DT	0X54		;N
    DT	0X5E		;D
    DT	0X5c		;O
    DT	0x6d		;S
    
    DT	0X00		;space
    DT	0X78		;T  		
    DT	0X50		;R
    DT	0X77		;A
    DT	0X54		;N
    DT	0x6d		;S
    DT	0X39		;C
    DT	0X3E		;U
    DT	0X50		;R
    DT	0X50		;R
    
    DT	0X30		;I
    DT	0X5E		;D
    DT	0X5c		;O
    DT	0x6d		;S
    DT	0X00		;space
    DT	0X00		;space
    DT	0X00		;space
    DT	0X00		;space
    DT	0X00		;space
    DT	0X00		;space		    ;extension normal
    
    ;mensaje	5
    
    DT	0X00		;space
    DT	0X71		;F
    DT	0X30		;I	
    DT	0X54		;N
    DT	0X77		;A
    DT	0X38		;L
    DT	0X00		;space
    DT	0X5E		;D		
    DT	0X79		;E
    DT	0X00		;space
    
    DT	0X38		;L
    DT	0X77		;A
    DT	0X00		;space
    DT	0X79		;E
    DT	0x6d		;S
    DT	0X73		;P
    DT	0X79		;E
    DT	0X50		;R
    DT	0X77		;A
    DT	0X00		;space
    
    DT	0x5b		;2
    DT	0x6d		;5		
    DT	0x3f		;0
    DT	0x6d		;S		
    DT	0X79		;E
    DT	0X6F		;G
    DT	0X3E		;U
    DT	0X54		;N
    DT	0X5E		;D
    DT	0X5c		;O
    
    DT	0x6d		;S
    DT	0X00		;space
    DT	0X00		;space
    DT	0X00		;space
    DT	0X00		;space
    DT	0X00		;space
    DT	0X00		;space
    DT	0X00		;space
    DT	0X00		;space
    DT	0X00		;space	    ;extensión normal
    
    ;ESPERA
    
    DT	0X79		;E
    DT	0x6d		;S
    DT	0X73		;P
    DT	0X79		;E
    DT	0X50		;R
    DT	0X77		;A