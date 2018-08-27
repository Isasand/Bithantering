/* Bit is atomic: the smallest unit of storage
A bit stores just 0 or 1 
Anything with two separate states can store 1 bit 
In a chip: electric charge = 0/1
In a hard drive: spots of North/ South magnetism = 0/1 
A bit is to small to be much use
Group 8 bits together to make 1 byte 

A byte can store one character

In general: add 1 bit, double the number of patterns
1 bit - 2 patterns
2 bits - 4
3 bits - 8
4 bits - 16
5 bits - 32
6 bits - 64
7 bits - 128
8 bits - 256 - one byte
Mathematically: n bits yields 2n patterns (2 to the nth power)
*/ 


/*
man vill bara använda unsigned när man jobbar med bitar för om man 
för tar en en vanlig integer som är 32 bitar lång så kommer den första biten 
vara en nolla eller etta. 
är det en etta betyder det att talet som följer är negativt och är det en nolla
betyder det att det är negativt
vi använder alltså en bit i char och int för att säga om den är positivt eller negativt 
utan då använder vi alla bitar för att visa hur stort ordet är 
behöver man inte negativa tal så funkar det bra
då kan man lagra dubbelt så stora tal
*/



typedef unsigned short u_short; 
typedef unsigned char u_char; 


void printBits(u_char word); 
u_short packBits(u_char c1, u_char c2); 
void unpackBits(u_short number, u_char *c1, u_char *c2); 
void printTest(); 


//skrivs ut från plats 9 i arrayen 
#include <stdio.h>
int main(int argc, char** argv) {
    u_char c1 = 'A', c2 = 'B', tkn1, tkn2; 
    u_short number; 

    printf("Utskrift av 0x4D: "); 
    printBits(0x4D);

    printf("\nc1 (%c): ", c1); 
    printBits(c1); 
    printf("\nc2 (%c): ", c2);
    printBits(c2); 

    number = packBits(c1, c2); 
    printf("\n\nPackat: "); 
    printBits(number); 
    printf("%c %c", c1, c2); 

    unpackBits(number, &tkn1, &tkn2); 
    printf("\n\nUppackat: "); 
    printf("C1: %c %d, C2; %c %d", tkn1, tkn1, tkn2, tkn2);
    printf("\n");
    printf("Bitar: ");
    printf("\n");
    printBits(c1);
    printf("\n");
    printBits(c2); 

    return 0;
}


void printTest(){
    char string[] = "this is a test\n";
    char *ptr = string;
    ptr += 8;
    printf("%s\n", ptr);
}
/*
0x betyder atyt ett hexadecimalt tal följer
vi kan bilda ett hexadecimalt tal med fyra bitar, för att kunna räkna upp till sexton.
*/


void printBits(u_char word){
    u_char mask = 0x80; //8 bitar med en 1a i yttersta positionen 1000 0000
    // sexton bitar skull ebli 8000
    for(int i = 0; i!=8; i++){
        if(mask & word)
            printf("1");
        else
            printf("0"); 
        mask >>= 1;  
        
    }
}

u_short packBits( u_char c1, u_char c2){
    u_short temp; //en short är 16 bitar så den rymmer två chars 
    temp = c1; //lagra c1 i temp 0000 xxxx
    temp <<= 8; //bitskifta vår temp 8 steg till vänster xxxx 0000
    temp |= c2; //vi årar c2 in till temp 

    return temp; 
}

void unpackBits(u_short number, u_char *c1, u_char *c2){ 
    //eftersom vi inte kan returnera två saker från en funktion så tar vi emot två pekare 
    *c1 = number; //tilldela number till c1 (de första 8 bitarna)
    number >>= 8; //sen skiftar vi 8 bitar till höger så högerdelen innehåller vårt andra tecken
    *c2 = number; //sen tilldelar vi de sista 8 bitarna till c2
}


