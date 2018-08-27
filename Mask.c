#include <stdio.h>
#include <stdint.h>

typedef unsigned short u_short; 
typedef unsigned char u_char; 
    
void printBits(u_char word); 
void printSomeBits(); 
uint8_t copyBits(uint8_t val, int startBit, int stopBit); 

void main(){
    //printSomeBits();
    /*u_char test=0x80;
    u_char val = testFunction(test);
    printBits(val); */
    printSomeBits(); 
}

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

void printSomeBits () {
    /*if(val & mask){
        masked |= 16; 
    }

    mask = 1 << 3; //0000 1000
    if(val & mask){
        masked |=8 ; 
    }

    mask = 1 << 2; // 0000 0100
    if(val & mask){
        masked |= 4; 
    }
*/
    uint8_t masked;
    uint8_t val = 0xAF; 
    int numOfBits = 3; 
    int startPosition = 2;

    printf("Bitset to copy from:\n");
    printBits(val); 
    printf("\n"); 
    masked = copyBits(val, numOfBits, startPosition); 
    printf("\nCopied %d bits from position %d:\n", numOfBits, startPosition); 
    printBits(masked);
    printf("\n"); 
}

uint8_t copyBits(uint8_t bitSet, int numberOfBits, int position){
    uint8_t mask = ((1 << numberOfBits) - 1) << position;  // mask:  0001 1100
    printf("\nBitmask:\n");
    printBits(mask); 
    printf("\n"); //u_char mask2 = (1<<2) | (1<<3) |(1<<4);
    return mask & bitSet;// (masked & ~mask) | (val & mask);  // masked 0000 0000 val 10101111
}