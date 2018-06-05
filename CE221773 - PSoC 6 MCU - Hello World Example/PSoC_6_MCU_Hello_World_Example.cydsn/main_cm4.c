/******************************************************************************
* File Name: main_cm4.c
*
* Version: 1.00
*
* Description: This is the source code for the PSoC_6_MCU_Hello_World_Example
*
* Related Document: CE221773_PSoC_6_MCU_Hello_World_Example.pdf
*
* Hardware Dependency: 
*                   CE221773_PSoC_6_MCU_Hello_World_Example.pdf
*                      
*******************************************************************************
* Copyright (2018), Cypress Semiconductor Corporation. All rights reserved.
*******************************************************************************
* This software, including source code, documentation and related materials
* (“Software”), is owned by Cypress Semiconductor Corporation or one of its
* subsidiaries (“Cypress”) and is protected by and subject to worldwide patent
* protection (United States and foreign), United States copyright laws and
* international treaty provisions. Therefore, you may use this Software only
* as provided in the license agreement accompanying the software package from
* which you obtained this Software (“EULA”).
*
* If no EULA applies, Cypress hereby grants you a personal, nonexclusive,
* non-transferable license to copy, modify, and compile the Software source
* code solely for use in connection with Cypress’s integrated circuit products.
* Any reproduction, modification, translation, compilation, or representation
* of this Software except as specified above is prohibited without the express
* written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND, 
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED 
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress 
* reserves the right to make changes to the Software without notice. Cypress 
* does not assume any liability arising out of the application or use of the 
* Software or any product or circuit described in the Software. Cypress does 
* not authorize its products for use in any products where a malfunction or 
* failure of the Cypress product may reasonably be expected to result in 
* significant property damage, injury or death (“High Risk Product”). By 
* including Cypress’s product in a High Risk Product, the manufacturer of such 
* system or application assumes all risk of such use and in doing so agrees to 
* indemnify Cypress against all liability.
*******************************************************************************/
#include "project.h"

/*******************************************************************************
* Macros
********************************************************************************/
#define LED_ON    (0)
#define LED_OFF   (!LED_ON)

/*******************************************************************************
* Function Prototypes
********************************************************************************/
void UartInit(void);
void TimerInit(void);
void Isr_Timer(void);

/*******************************************************************************
* Global Variables
********************************************************************************/
bool LEDupdateFlag = false;

/*******************************************************************************
* Function Name: main
********************************************************************************
* Summary: 
* This is the main function for CM4 CPU. It enables the UART and TCPWM 
* peripherals. The TCPWM is configured as timer which generates an interrupt
* every second. On each interrupt the LED state is toggled.
*
* Parameters:
*  void
*
* Return:
*  int
*
*******************************************************************************/
int main(void)
{
    /* Start the UART peripheral */
    UartInit();
    
    /* Enable global interrupts. */
    __enable_irq(); 
    
    /* \x1b[2J\x1b[;H - ANSI ESC sequence for clear screen */
    Cy_SCB_UART_PutString(UART_HW, "\x1b[2J\x1b[;H");
    
    Cy_SCB_UART_PutString(UART_HW, "******************CE221773 - PSoC 6 MCU:"\
                   " Hello World! Example******************\r\n\n");
    
    Cy_SCB_UART_PutString(UART_HW, "Hello World!!!\r\n\n");
    
    Cy_SCB_UART_PutString(UART_HW, "Press Enter key to start blinking the LED\r\n\n");
    
    /* Wait for the user to Press Enter key */
    while(Cy_SCB_UART_Get(UART_HW) != '\r');
    
    /* Start the TCPWM peripheral. TCPWM is configured as a Timer */
    TimerInit();
    
    Cy_SCB_UART_PutString(UART_HW, "Observe the LED blinking on the kit!!!\r\n");
     
    for(;;)
    {
        if(LEDupdateFlag)
        {
            /* Clear the flag */
            LEDupdateFlag = false;
            
            /* Invert the LED state*/
            Cy_GPIO_Inv(Pin_GreenLED_0_PORT, Pin_GreenLED_0_NUM);
        }
    }
}

/*******************************************************************************
* Function Name: UartInit
********************************************************************************
* Summary:
* This function initializes the UART peripheral with UART configuration settings
* defined in the UART_config structure. It also enables the UART peripheral.  
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void UartInit(void)
{
    /* Configure the UART peripheral.
       UART_config structure is defined by the UART_PDL component based on 
       parameters entered in the Component configuration*/
    Cy_SCB_UART_Init(UART_HW, &UART_config, &UART_context);
    
    /* Enable the UART peripheral */
    Cy_SCB_UART_Enable(UART_HW);
}

/*******************************************************************************
* Function Name: TimerInit
********************************************************************************
* Summary:
* This function configures and enables the TCPWM peripheral as a Timer. It also 
* configures and maps the TCPWM interrupt to the CM4 CPU.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void TimerInit(void)
{
    /* Configure the TCPWM peripheral.
       Counter_config structure is defined based on the parameters entered 
       in the Component configuration */
    Cy_TCPWM_Counter_Init(Timer_HW, Timer_CNT_NUM, &Timer_config);
    
    /* Enable the initialized counter */
    Cy_TCPWM_Counter_Enable(Timer_HW, Timer_CNT_NUM);
    
    /* Start the enabled counter */
    Cy_TCPWM_TriggerStart(Timer_HW, Timer_CNT_MASK);
    
    /* Configure the ISR for the TCPWM peripheral*/
    Cy_SysInt_Init(&Isr_Timer_cfg, Isr_Timer);
    
    /* Enable interrupt in NVIC */   
    NVIC_EnableIRQ((IRQn_Type)Isr_Timer_cfg.intrSrc);
}

/*******************************************************************************
* Function Name: Isr_Timer
********************************************************************************
* Summary:
* This is the interrupt handler function for the TCPWM interrupt.  
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void Isr_Timer(void)
{
    /* Clear the TCPWM peripheral interrupt */
    Cy_TCPWM_ClearInterrupt(Timer_HW, Timer_CNT_NUM, CY_TCPWM_INT_ON_TC );
    
    /* Clear the CM4 NVIC pending interrupt for TCPWM */
    NVIC_ClearPendingIRQ(Isr_Timer_cfg.intrSrc);
	
	LEDupdateFlag = true;
}

/* [] END OF FILE */
