#include <stdint.h>

#define RCC_AHBENR *(volatile uint32_t *)(0x4002381C)
#define GPIOA_MODER *(volatile uint32_t *)(0x40020000)
#define GPIOA_ODR *(volatile uint32_t *)(0x40020014)

int main(void){
    RCC_AHBENR |= (0x1);
    __asm("nop");

    GPIOA_MODER &= ~(1<<10);
    GPIOA_MODER &= ~(1<<11);

    GPIOA_MODER |= (1<<10);

    while(1){
        GPIOA_ODR ^= (1<<5);
        for(uint32_t i=0; i<50000;i++);
    }
}