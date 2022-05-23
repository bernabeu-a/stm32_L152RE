#include <stdint.h>

#define SRAM_START  (0x20000000U)
#define SRAM_SIZE   (80U * 1024U)   /* 80 kB */
#define SRAM_END    ((SRAM_START) + (SRAM_SIZE))
#define STACK_START SRAM_END

extern uint32_t _etext;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;
extern uint32_t _la_data;
// extern uint32_t _sidata;

void Reset_Handler(void);
__attribute__ ((weak, alias("Default_Handler"))) void NMI_Handler(void);       
__attribute__((weak, alias("Default_Handler")))void HardFault_Handler(void)    ;
__attribute__((weak, alias("Default_Handler")))void MemManage_Handler(void)    ;
__attribute__((weak, alias("Default_Handler")))void BusFault_Handler(void)    ;
__attribute__((weak, alias("Default_Handler")))void UsageFault_Handler(void)   ;
__attribute__((weak, alias("Default_Handler")))void SVC_Handler(void) ;
__attribute__((weak, alias("Default_Handler")))void DebugMon_Handler(void)   ;
__attribute__((weak, alias("Default_Handler")))void PendSV_Handler(void)   ;
__attribute__((weak, alias("Default_Handler")))void SysTick_Handler(void)    ;
__attribute__((weak, alias("Default_Handler")))void WWDG(void)    ;
__attribute__((weak, alias("Default_Handler")))void PVD(void)    ;
__attribute__((weak, alias("Default_Handler")))void TAMPER_STAMP(void)    ;
__attribute__((weak, alias("Default_Handler")))void RTC_WKUP(void) ;
__attribute__((weak, alias("Default_Handler")))void FLASH(void)  ;
__attribute__((weak, alias("Default_Handler")))void RCC(void)    ;
__attribute__((weak, alias("Default_Handler")))void EXTI0(void)   ;
__attribute__((weak, alias("Default_Handler")))void EXTI1(void)  ;
__attribute__((weak, alias("Default_Handler")))void EXTI2(void)  ;
__attribute__((weak, alias("Default_Handler")))void EXTI3(void) ;
__attribute__((weak, alias("Default_Handler")))void EXTI4(void)   ;
__attribute__((weak, alias("Default_Handler")))void DMA1_Channel1(void)  ;
__attribute__((weak, alias("Default_Handler")))void DMA1_Channel2(void)    ;
__attribute__((weak, alias("Default_Handler")))void DMA1_Channel3(void)   ;
__attribute__((weak, alias("Default_Handler")))void DMA1_Channel4(void)  ;
__attribute__((weak, alias("Default_Handler")))void DMA1_Channel5(void)  ;
__attribute__((weak, alias("Default_Handler")))void DMA1_Channel6(void)    ;
__attribute__((weak, alias("Default_Handler")))void DMA1_Channel7(void)   ;
__attribute__((weak, alias("Default_Handler")))void ADC1(void)   ;
__attribute__((weak, alias("Default_Handler")))void USB_HP(void)  ;
__attribute__((weak, alias("Default_Handler")))void USB_LP(void)   ;
__attribute__((weak, alias("Default_Handler")))void DAC(void)   ;
__attribute__((weak, alias("Default_Handler")))void COMP_CA(void)  ;
__attribute__((weak, alias("Default_Handler")))void EXTI9_5(void)   ;
__attribute__((weak, alias("Default_Handler")))void LCD(void)    ;
__attribute__((weak, alias("Default_Handler")))void TIM9(void)  ;
__attribute__((weak, alias("Default_Handler")))void TIM10(void)   ;
__attribute__((weak, alias("Default_Handler")))void TIM11(void)   ;
__attribute__((weak, alias("Default_Handler")))void TIM2(void)    ;
__attribute__((weak, alias("Default_Handler")))void TIM3(void)    ;
__attribute__((weak, alias("Default_Handler")))void TIM4(void)  ;
__attribute__((weak, alias("Default_Handler")))void I2C1_EV(void)   ;
__attribute__((weak, alias("Default_Handler")))void I2C1_ER(void)    ;
__attribute__((weak, alias("Default_Handler")))void I2C2_EV(void)  ;
__attribute__((weak, alias("Default_Handler")))void I2C2_ER(void)   ;
__attribute__((weak, alias("Default_Handler")))void SPI1(void)   ;
__attribute__((weak, alias("Default_Handler")))void SPI2(void)   ;
__attribute__((weak, alias("Default_Handler")))void USART1(void)   ;
__attribute__((weak, alias("Default_Handler")))void USART2(void)  ;
__attribute__((weak, alias("Default_Handler")))void USART3(void)   ;
__attribute__((weak, alias("Default_Handler")))void EXTI15_10(void)  ;
__attribute__((weak, alias("Default_Handler")))void RTC_Alarm(void)   ;
__attribute__((weak, alias("Default_Handler")))void USB_FS_WKUP(void)   ;
__attribute__((weak, alias("Default_Handler")))void TIM6(void)    ;
__attribute__((weak, alias("Default_Handler")))void TIM7(void)    ;
__attribute__((weak, alias("Default_Handler")))void SDIO(void)    ;
__attribute__((weak, alias("Default_Handler")))void TIM5(void)    ;
__attribute__((weak, alias("Default_Handler")))void SPI3(void);
__attribute__((weak, alias("Default_Handler")))void UART4(void);
__attribute__((weak, alias("Default_Handler")))void UART5(void);
__attribute__((weak, alias("Default_Handler")))void DMA2_CH1(void);
__attribute__((weak, alias("Default_Handler")))void DMA2_CH2(void);
__attribute__((weak, alias("Default_Handler")))void DMA2_CH3(void);
__attribute__((weak, alias("Default_Handler")))void DMA2_CH4(void);
__attribute__((weak, alias("Default_Handler")))void DMA2_CH5(void);
__attribute__((weak, alias("Default_Handler"))) void AES(void);
__attribute__((weak, alias("Default_Handler"))) void COMP_ACQ(void);

__attribute__ ((used,section(".vectors_table")))
uint32_t vectors[] = {
    STACK_START, 
    (uint32_t) &Reset_Handler,
    (uint32_t) &NMI_Handler,
    (uint32_t) &HardFault_Handler,
    (uint32_t) &MemManage_Handler,
    (uint32_t) &BusFault_Handler,
    (uint32_t) &UsageFault_Handler,
    0,
    0,
    0,
    0,
    (uint32_t) &SVC_Handler,
    (uint32_t) &DebugMon_Handler,
    0,
    (uint32_t) &PendSV_Handler,
    (uint32_t) &SysTick_Handler,
    (uint32_t) &WWDG,
    (uint32_t) &PVD,
    (uint32_t) &TAMPER_STAMP,
    (uint32_t) &RTC_WKUP,
    (uint32_t) &FLASH,
    (uint32_t) &RCC,
    (uint32_t) &EXTI0,
    (uint32_t) &EXTI1,
    (uint32_t) &EXTI2,
    (uint32_t) &EXTI3,
    (uint32_t) &EXTI4,
    (uint32_t) &DMA1_Channel1,
    (uint32_t) &DMA1_Channel2,
    (uint32_t) &DMA1_Channel3,
    (uint32_t) &DMA1_Channel4,
    (uint32_t) &DMA1_Channel5,
    (uint32_t) &DMA1_Channel6,
    (uint32_t) &DMA1_Channel7,
    (uint32_t) &ADC1,
    (uint32_t) &USB_HP,
    (uint32_t) &USB_LP,
    (uint32_t) &DAC,
    (uint32_t) &COMP_CA,
    (uint32_t) &EXTI9_5,
    (uint32_t) &LCD,
    (uint32_t) &TIM9,
    (uint32_t) &TIM10,
    (uint32_t) &TIM11,
    (uint32_t) &TIM2,
    (uint32_t) &TIM3,
    (uint32_t) &TIM4,
    (uint32_t) &I2C1_EV,
    (uint32_t) &I2C1_ER,
    (uint32_t) &I2C2_EV,
    (uint32_t) &I2C2_ER,
    (uint32_t) &SPI1,
    (uint32_t) &SPI2,
    (uint32_t) &USART1,
    (uint32_t) &USART2,
    (uint32_t) &USART3,
    (uint32_t) &EXTI15_10,
    (uint32_t) &RTC_Alarm,
    (uint32_t) &USB_FS_WKUP,
    (uint32_t) &TIM6,
    (uint32_t) &TIM7,
    (uint32_t) &SDIO,
    (uint32_t) &TIM5,
    (uint32_t) &SPI3,
    (uint32_t) &UART4,
    (uint32_t) &UART5,
    (uint32_t) &DMA2_CH1,
    (uint32_t) &DMA2_CH2,
    (uint32_t) &DMA2_CH3,
    (uint32_t) &DMA2_CH4,
    (uint32_t) &DMA2_CH5,
    (uint32_t) &AES,
    (uint32_t) &COMP_ACQ

};

int main(void);

void Reset_Handler(void){
    /* Copy .data section to SRAM */
    uint32_t size = (uint32_t) &_edata - (uint32_t) &_sdata;

    uint8_t *pSrc = (uint8_t *) &_edata;
    uint8_t *pDst = (uint8_t *) &_la_data;

    for (uint32_t i=0; i<size; i++){
        *pDst++ = *pSrc++;
    }

    /* Initialize .bss to 0 */
    size = (uint32_t) &_ebss - (uint32_t) &_sbss;

    pDst = (uint8_t *) &_sbss;

    for(uint32_t i=0; i<size; i++){
        *pDst++ = 0;
    }

    main();

    while(1);
}

void Default_Handler(void){
    while(1);
}

