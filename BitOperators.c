/* 
Bitoperatorer i C: 

~ Complemennt (invert all bits)
<< Left Shift
>> Right Shift 
& AND, bitvis 
^ XOR, bitvis (Exclusive OR, antingen eller men inte båda)
| OR, bitvis (Inclusive OR, antingen eller eller båda)
$x $y ($x or $y) ($x xor $y)
0  0    0          0
1  0    1          1
0  1    1          1
1  1    1          0

Logikoperatorer (verkar på logikvärden, dvs 0 eller 1): 
! NOT 
&& AND 
|| OR 

*/ 
typedef unsigned char u_char; 

#include<stdio.h>
#include<stdint.h>
void printHexadecimal(); 
void printBits(u_char word); 
void setBits(); 
void maskBits(); 

uint8_t stuff(); 

int main(int argc, char** argv) {

    setBits(); 
    /*uint8_t masked = stuff(); 
    printBits(masked); 
    printf("printed"); */
    return 0;
}

union union_t { //unions lagrar olika datatyper på samma minnesplats
    uint32_t i;
    uint8_t a[8];
};

void printHexadecimal(){ 
    union union_t u; 
    u.i = 0xdeadbeef; //0xDEADBEEF är hexadecimal representation av 32-bits 3735928559

    printf("0x%02X\n", u.a[4]);
    printf("0x%x", u.a);
    printf("\n");
    printf("0x%x", u.i);
    
    /* %02X betyder print at least two digits, prepend it with '0' if there's less.
    x refererar till integer i hexadecimalt format till skillnad från d som 
    refererar till integer i decimalt format. 
    lx och ld för long. 
    */ 
   
}

void setBits(){
    uint8_t val; 
    printBits(val);
    printf("\n"); 
    val |= 8; 
    printBits(val);
    val &= ~0x8; 
    printf("\n"); 
    printBits(val);
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

uint8_t stuff() {
  uint8_t mask = 0x0f;   // 00001111b
  uint8_t value = 0x55;  // 01010101b
  return mask & value;
}