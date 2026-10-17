.model small
.stack 100h

.DATA
MSG1 db 'Enter The First Variable: ','$' 
MSG2 db 'Enter The Second Variable: ','$'
MSG3 db 'Addition Of Both The Both Variables: ','$'
MSG4 db 'Subtraction Both The Both Variables: ','$'

VAR1 db 0 
VAR2 db 0
VAR3 db 0
VAR4 db 0

.CODE 
main proc             
    MOV ax,@DATA
    MOV DS,ax
             
    MOV AH,9   ; STRING OUTPUT                
    lea dx,MSG1
    int 21h
    
    MOV AH,1  ;INPUT
    INT 21H
    MOV VAR1,AL
    
    MOV ah,2    ; NEW LINE                
    MOV DL,0DH
    int 21h  
    
    MOV ah,2    ; NEW LINE INVOKE                
    MOV DL,0AH
    int 21h
                     
    MOV AH,9   ; STRING OUTPUT                
    lea dx,MSG2
    int 21h
    
    MOV AH,1  ;INPUT
    INT 21H
    MOV VAR2,AL
    
    MOV ah,2    ; NEW LINE                
    MOV DL,0DH
    int 21h  
    
    MOV ah,2    ; NEW LINE INVOKE                
    MOV DL,0AH
    int 21h
    
    
    MOV AH, VAR1
    SUB AH, 30H
    MOV BH, VAR2
    SUB BH, 30H
    ADD AH, BH
    ADD AH, 30H
    MOV VAR3, AH
    
        
    MOV AH, VAR1
    SUB AH, 30H
    MOV BH, VAR2
    SUB BH, 30H
    SUB AH, BH
    ADD AH, 30H
    MOV VAR4, AH
    
    MOV AH,9   ; STRING OUTPUT                
    lea dx,MSG3
    int 21h
     
    MOV ah,2    ; SINGLE KEY OUTPUT                
    MOV DL,VAR3
    int 21h
    
    MOV ah,2    ; NEW LINE                
    MOV DL,0DH
    int 21h  
    
    MOV ah,2    ; NEW LINE INVOKE                
    MOV DL,0AH
    int 21h 
    
    MOV AH,9   ; STRING OUTPUT                
    lea dx,MSG3
    int 21h
    
    MOV ah,2    ; SINGLE KEY OUTPUT                
    MOV DL,VAR4
    int 21h
        
    mov ah,4ch  ;RETURN TO OS
    int 21h
    
    main endp
end main
