#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void print(char*, ...);

int main() {
    
    print("hola %s %s %s World %s %s %s example", "mundo", "!!", "Hello", "!!", "Jorge", "Muñoz", "Aguado");
}

void print(char* cadena, ...) {

    char *aux;
    char *prf;
    int size = 0;
    int i = 0, ii;
    int last = 0;
    va_list valist;

    size = 1;
    va_start(valist, size);

    while (cadena[i]) {
        
        if (cadena[i] == '%') {
            
            prf = (char*) malloc ((i - last + 6) * sizeof(char));
    
            prf[0] = 'e';
            prf[1] = 'c';
            prf[2] = 'h';
            prf[3] = 'o';
            prf[4] = ' ';
            
            for (ii = 0; cadena[ii]; ii++) {
            
                if (cadena[ii + last] == '%') break;
                prf[ii + 5] = cadena[ii + last];
            }
            
            prf[ii + 5] = 0;
            
            system(prf);
            
            free(prf);
            
            i++;
            last = i;
            
            switch (cadena[i]) {
                
                case 's':
                    
                    last++;
                    
                    aux = va_arg(valist, char*);
                
                    for (ii = 0; aux[ii]; ii++);
    
                    prf = (char*) malloc ((ii + 6) * sizeof(char));
                    
                    prf[0] = 'e';
                    prf[1] = 'c';
                    prf[2] = 'h';
                    prf[3] = 'o';
                    prf[4] = ' ';
                    
                    for (ii = 0; aux[ii]; ii++) {
                        prf[ii + 5] = aux[ii];
                    }
                    prf[ii + 5] = 0;
                    
                    system(prf);
                    
                    free(prf);
                    
                    break;  
            }
            
        }
        
        i++;
    }
    
    if (i > last) {
    
        prf = (char*) malloc ((i - last + 6) * sizeof(char));
        
        prf[0] = 'e';
        prf[1] = 'c';
        prf[2] = 'h';
        prf[3] = 'o';
        prf[4] = ' ';
        
        for (ii = 0; cadena[ii + last]; ii++) {
        
            prf[ii + 5] = cadena[ii + last];
        }
        
        prf[ii + 5] = 0;

        system(prf);
        
        free(prf);
    }
    
    va_end(valist);
}

