#include <stdint.h>

#define RCC_AHBENR *(volatile uint32_t *)(0x4002381CUL)
#define RCC_APB2ENR *(volatile uint32_t *)(0x40023820UL)

#define GPIOA_MODER *(volatile uint32_t *)(0x40020000UL)
#define GPIOA_ODR *(volatile uint32_t *)(0x40020014UL)

#define GPIOC_MODER *(volatile uint32_t *) (0x40020800UL)
#define GPIOC_PUPDR *(volatile uint32_t *) (0x4002080CUL)
#define GPIOC_IDR *(volatile uint32_t *) (0x40020810UL)

#define SYSCFG_EXTICR4 *(volatile uint32_t *) (0x40010014UL)

#define EXTI_IMR *(volatile uint32_t *) (0x40010400UL)
#define EXTI_RTSR *(volatile uint32_t *) (0x40010408UL)
#define EXTI_FTSR *(volatile uint32_t *) (0x4001040CUL)
#define EXTI_PR *(volatile uint32_t *) (0x40010414UL)

#define NVIC_ISER1 *(volatile uint32_t *) (0xE000E104UL)

// button PC13
int main(void){
    // Clock GPIOA (led LD2)
    RCC_AHBENR |= (1<<0);
    __asm("nop");
    // Clock GPIOC (button B1)
    RCC_AHBENR |= (1<<2);
    __asm("nop");

    // Setup LD2 as output
    GPIOA_MODER &= ~(1<<10);
    GPIOA_MODER &= ~(1<<11);
    GPIOA_MODER |= (1<<10);
    
    // Setup B1 as input pullup
    GPIOC_MODER &= ~(1<<26);
    GPIOC_MODER &= ~(1<<27);
    GPIOC_PUPDR |= (1<<26);

    // Clock SYSCFG
    RCC_APB2ENR |= (1<<0);
    __asm("nop");

    // PC13 (button B1)
    SYSCFG_EXTICR4 |= (1<<5);
    // Unmask Line 13
    EXTI_IMR = (1<<13);
    // Disable the 'rising edge' trigger (button release).
    EXTI_RTSR |= (1 << 13);
    // Enable the 'falling edge' trigger (button press).
    EXTI_FTSR &=  ~(1 << 13);
    // Interrupt Enable 
    NVIC_ISER1 = 0x100;

    while(1){

    }
}

void EXTI15_10(void){
    // XOR led if interrupt from line 13
    if(EXTI_PR & (1<<13)){
        GPIOA_ODR ^= (1<<5);
    }
    // Ack interrupt
    EXTI_PR = 0x2000;
}