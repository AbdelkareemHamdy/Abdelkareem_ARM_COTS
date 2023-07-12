#include "../inc/GPIO_interface.h"
#include "../inc/GPIO_prv.h"
#include "../../../Library/stm32f446xx.h"
#include <stdint.h>

uint8_t GPIO_u8PinInit(const PinConfig_t* PinConfig)
{
    switch (PinConfig->port)
    {
    case PORTA:
        /*mode I/P,O/P,A.F or Analog*/
        GPIOA->MODER &=~(0b11           <<(PinConfig->pin *2)); //bit masking
        GPIOA->MODER |=(PinConfig->mode <<(PinConfig->pin *2));
        if (ANALOG != PinConfig->mode)
        {
            /*no Pull , Pull up or Pull down o*/
            GPIOA->PUPDR &=~(0b11               <<(PinConfig->pin *2)); //bit masking
            GPIOA->PUPDR |=(PinConfig->PullType <<(PinConfig->pin *2));
            if (INPUT != PinConfig->mode)
            {
                /*Push Pull or Open drain*/
                GPIOA->OTYPER &=~(0b1                <<(PinConfig->pin)); //bit masking
                GPIOA->OTYPER |=(PinConfig->PullType <<(PinConfig->pin));
                /*Speed Low,Meduiem,fast or High*/
                GPIOA->OSPEEDR &=~(0b11             <<(PinConfig->pin *2)); //bit masking
                GPIOA->OSPEEDR |=(PinConfig->speed  <<(PinConfig->pin *2));
            }  
            
        }
        /*Alternate function*/
        GPIOA->AFR &=~(0b1111               <<(PinConfig->pin *4)); //bit masking
        GPIOA->AFR |=(PinConfig->AltFunc    <<(PinConfig->pin *4));

        break;
    case PORTB:
        /*mode I/P,O/P,A.F or Analog*/
        GPIOB->MODER &=~(0b11           <<(PinConfig->pin *2)); //bit masking
        GPIOB->MODER |=(PinConfig->mode <<(PinConfig->pin *2));
        if (ANALOG != PinConfig->mode)
        {
            /*no Pull , Pull up or Pull down o*/
            GPIOB->PUPDR &=~(0b11               <<(PinConfig->pin *2)); //bit masking
            GPIOB->PUPDR |=(PinConfig->PullType <<(PinConfig->pin *2));
            if (INPUT != PinConfig->mode)
            {
                /*Push Pull or Open drain*/
                GPIOB->OTYPER &=~(0b1                <<(PinConfig->pin)); //bit masking
                GPIOB->OTYPER |=(PinConfig->PullType <<(PinConfig->pin));
                /*Speed Low,Meduiem,fast or High*/
                GPIOB->OSPEEDR &=~(0b11             <<(PinConfig->pin *2)); //bit masking
                GPIOB->OSPEEDR |=(PinConfig->speed  <<(PinConfig->pin *2));
            }  
            
        }
        /*Alternate function*/
        GPIOB->AFR &=~(0b1111               <<(PinConfig->pin *4)); //bit masking
        GPIOB->AFR |=(PinConfig->AltFunc    <<(PinConfig->pin *4));

        break;
    case PORTC:
        /* code */        /*mode I/P,O/P,A.F or Analog*/
        GPIOC->MODER &=~(0b11           <<(PinConfig->pin *2)); //bit masking
        GPIOC->MODER |=(PinConfig->mode <<(PinConfig->pin *2));
        if (ANALOG != PinConfig->mode)
        {
            /*no Pull , Pull up or Pull down o*/
            GPIOC->PUPDR &=~(0b11               <<(PinConfig->pin *2)); //bit masking
            GPIOC->PUPDR |=(PinConfig->PullType <<(PinConfig->pin *2));
            if (INPUT != PinConfig->mode)
            {
                /*Push Pull or Open drain*/
                GPIOC->OTYPER &=~(0b1                <<(PinConfig->pin)); //bit masking
                GPIOC->OTYPER |=(PinConfig->PullType <<(PinConfig->pin));
                /*Speed Low,Meduiem,fast or High*/
                GPIOC->OSPEEDR &=~(0b11             <<(PinConfig->pin *2)); //bit masking
                GPIOC->OSPEEDR |=(PinConfig->speed  <<(PinConfig->pin *2));
            }  
            
        }
        /*Alternate function*/
        GPIOC->AFR &=~(0b1111               <<(PinConfig->pin *4)); //bit masking
        GPIOC->AFR |=(PinConfig->AltFunc    <<(PinConfig->pin *4));
        break;
    case PORTC:
        /*mode I/P,O/P,A.F or Analog*/
        GPIOC->MODER &=~(0b11           <<(PinConfig->pin *2)); //bit masking
        GPIOC->MODER |=(PinConfig->mode <<(PinConfig->pin *2));
        if (ANALOG != PinConfig->mode)
        {
            /*no Pull , Pull up or Pull down o*/
            GPIOC->PUPDR &=~(0b11               <<(PinConfig->pin *2)); //bit masking
            GPIOC->PUPDR |=(PinConfig->PullType <<(PinConfig->pin *2));
            if (INPUT != PinConfig->mode)
            {
                /*Push Pull or Open drain*/
                GPIOC->OTYPER &=~(0b1                <<(PinConfig->pin)); //bit masking
                GPIOC->OTYPER |=(PinConfig->PullType <<(PinConfig->pin));
                /*Speed Low,Meduiem,fast or High*/
                GPIOC->OSPEEDR &=~(0b11             <<(PinConfig->pin *2)); //bit masking
                GPIOC->OSPEEDR |=(PinConfig->speed  <<(PinConfig->pin *2));
            }  
            
        }
        /*Alternate function*/
        GPIOC->AFR &=~(0b1111               <<(PinConfig->pin *4)); //bit masking
        GPIOC->AFR |=(PinConfig->AltFunc    <<(PinConfig->pin *4));

        break;
    case PORTD:
        /*mode I/P,O/P,A.F or Analog*/
        GPIOD->MODER &=~(0b11           <<(PinConfig->pin *2)); //bit masking
        GPIOD->MODER |=(PinConfig->mode <<(PinConfig->pin *2));
        if (ANALOG != PinConfig->mode)
        {
            /*no Pull , Pull up or Pull down o*/
            GPIOD->PUPDR &=~(0b11               <<(PinConfig->pin *2)); //bit masking
            GPIOD->PUPDR |=(PinConfig->PullType <<(PinConfig->pin *2));
            if (INPUT != PinConfig->mode)
            {
                /*Push Pull or Open drain*/
                GPIOD->OTYPER &=~(0b1                <<(PinConfig->pin)); //bit masking
                GPIOD->OTYPER |=(PinConfig->PullType <<(PinConfig->pin));
                /*Speed Low,Meduiem,fast or High*/
                GPIOD->OSPEEDR &=~(0b11             <<(PinConfig->pin *2)); //bit masking
                GPIOD->OSPEEDR |=(PinConfig->speed  <<(PinConfig->pin *2));
            }  
            
        }
        /*Alternate function*/
        GPIOD->AFR &=~(0b1111               <<(PinConfig->pin *4)); //bit masking
        GPIOD->AFR |=(PinConfig->AltFunc    <<(PinConfig->pin *4));

        break;
    case PORTE:
        /*mode I/P,O/P,A.F or Analog*/
        GPIOE->MODER &=~(0b11           <<(PinConfig->pin *2)); //bit masking
        GPIOE->MODER |=(PinConfig->mode <<(PinConfig->pin *2));
        if (ANALOG != PinConfig->mode)
        {
            /*no Pull , Pull up or Pull down o*/
            GPIOE->PUPDR &=~(0b11               <<(PinConfig->pin *2)); //bit masking
            GPIOE->PUPDR |=(PinConfig->PullType <<(PinConfig->pin *2));
            if (INPUT != PinConfig->mode)
            {
                /*Push Pull or Open drain*/
                GPIOE->OTYPER &=~(0b1                <<(PinConfig->pin)); //bit masking
                GPIOE->OTYPER |=(PinConfig->PullType <<(PinConfig->pin));
                /*Speed Low,Meduiem,fast or High*/
                GPIOE->OSPEEDR &=~(0b11             <<(PinConfig->pin *2)); //bit masking
                GPIOE->OSPEEDR |=(PinConfig->speed  <<(PinConfig->pin *2));
            }  
            
        }
        /*Alternate function*/
        GPIOE->AFR &=~(0b1111               <<(PinConfig->pin *4)); //bit masking
        GPIOE->AFR |=(PinConfig->AltFunc    <<(PinConfig->pin *4));

        break;
    case PORTF:
        /*mode I/P,O/P,A.F or Analog*/
        GPIOF->MODER &=~(0b11           <<(PinConfig->pin *2)); //bit masking
        GPIOF->MODER |=(PinConfig->mode <<(PinConfig->pin *2));
        if (ANALOG != PinConfig->mode)
        {
            
            if (INPUT != PinConfig->mode)
            {
                /*Push Pull or Open drain*/
                GPIOF->OTYPER &=~(0b1                <<(PinConfig->pin)); //bit masking
                GPIOF->OTYPER |=(PinConfig->PullType <<(PinConfig->pin));
                /*Speed Low,Meduiem,fast or High*/
                GPIOF->OSPEEDR &=~(0b11             <<(PinConfig->pin *2)); //bit masking
                GPIOF->OSPEEDR |=(PinConfig->speed  <<(PinConfig->pin *2));
            }  
            /*no Pull , Pull up or Pull down o*/
            GPIOF->PUPDR &=~(0b11               <<(PinConfig->pin *2)); //bit masking
            GPIOF->PUPDR |=(PinConfig->PullType <<(PinConfig->pin *2));
        }
        /*Alternate function*/
        GPIOF->AFR &=~(0b1111               <<(PinConfig->pin *4)); //bit masking
        GPIOF->AFR |=(PinConfig->AltFunc    <<(PinConfig->pin *4));

        break;
    case PORTG:
        /*mode I/P,O/P,A.F or Analog*/
        GPIOG->MODER &=~(0b11           <<(PinConfig->pin *2)); //bit masking
        GPIOG->MODER |=(PinConfig->mode <<(PinConfig->pin *2));
        if (ANALOG != PinConfig->mode)
        {
            
            if (INPUT != PinConfig->mode)
            {
                /*Push Pull or Open drain*/
                GPIOG->OTYPER &=~(0b1                <<(PinConfig->pin)); //bit masking
                GPIOG->OTYPER |=(PinConfig->PullType <<(PinConfig->pin));
                /*Speed Low,Meduiem,fast or High*/
                GPIOG->OSPEEDR &=~(0b11             <<(PinConfig->pin *2)); //bit masking
                GPIOG->OSPEEDR |=(PinConfig->speed  <<(PinConfig->pin *2));
            }  
            /*no Pull , Pull up or Pull down o*/
            GPIOG->PUPDR &=~(0b11               <<(PinConfig->pin *2)); //bit masking
            GPIOG->PUPDR |=(PinConfig->PullType <<(PinConfig->pin *2));
        }
        /*Alternate function*/
        GPIOG->AFR &=~(0b1111               <<(PinConfig->pin *4)); //bit masking
        GPIOG->AFR |=(PinConfig->AltFunc    <<(PinConfig->pin *4));

        break;
    case PORTH:
        /*mode I/P,O/P,A.F or Analog*/
        GPIOH->MODER &=~(0b11           <<(PinConfig->pin *2)); //bit masking
        GPIOH->MODER |=(PinConfig->mode <<(PinConfig->pin *2));
        if (ANALOG != PinConfig->mode)
        {
            
            if (INPUT != PinConfig->mode)
            {
                /*Push Pull or Open drain*/
                GPIOH->OTYPER &=~(0b1                <<(PinConfig->pin)); //bit masking
                GPIOH->OTYPER |=(PinConfig->PullType <<(PinConfig->pin));
                /*Speed Low,Meduiem,fast or High*/
                GPIOH->OSPEEDR &=~(0b11             <<(PinConfig->pin *2)); //bit masking
                GPIOH->OSPEEDR |=(PinConfig->speed  <<(PinConfig->pin *2));
            }  
            /*no Pull , Pull up or Pull down o*/
            GPIOH->PUPDR &=~(0b11               <<(PinConfig->pin *2)); //bit masking
            GPIOH->PUPDR |=(PinConfig->PullType <<(PinConfig->pin *2));
        }
        /*Alternate function*/
        GPIOH->AFR &=~(0b1111               <<(PinConfig->pin *4)); //bit masking
        GPIOH->AFR |=(PinConfig->AltFunc    <<(PinConfig->pin *4));

        break;
    
    default:
        break;
    }
}

uint8_t GPIO_u8SetPinValue(Port_t Port,Pin_t PinNumber,PinVal_t PinVal)
{
   //(GPIOA+Port*0x400UL)->BSRR |=(0b1<<PinNumber);
    switch (Port)
    {
    case PORTA:
        if (LOW==PinVal)
        {
            GPIOA->BSRR = (0b1 << PinNumber+16);
        }
        else if (HIGH==PinVal)
        {
            GPIOA->BSRR = (0b1 << PinNumber);
        }
        break;
    case PORTB:
        if (LOW==PinVal)
        {
            GPIOB->BSRR = (0b1 << PinNumber+16);
        }
        else if (HIGH==PinVal)
        {
            GPIOB->BSRR = (0b1 << PinNumber);
        }
        break;
    case PORTC:
        if (LOW==PinVal)
        {
            GPIOC->BSRR = (0b1 << PinNumber+16);
        }
        else if (HIGH==PinVal)
        {
            GPIOC->BSRR = (0b1 << PinNumber);
        }
        break;
    case PORTD:
        if (LOW==PinVal)
        {
            GPIOD->BSRR = (0b1 << PinNumber+16);
        }
        else if (HIGH==PinVal)
        {
            GPIOD->BSRR = (0b1 << PinNumber);
        }
        break;
    case PORTE:
        if (LOW==PinVal)
        {
            GPIOE->BSRR = (0b1 << PinNumber+16);
        }
        else if (HIGH==PinVal)
        {
            GPIOE->BSRR = (0b1 << PinNumber);
        }
        break;
    case PORTF:
        if (LOW==PinVal)
        {
            GPIOF->BSRR = (0b1 << PinNumber+16);
        }
        else if (HIGH==PinVal)
        {
            GPIOF->BSRR = (0b1 << PinNumber);
        }
        break;
    case PORTG:
        if (LOW==PinVal)
        {
            GPIOG->BSRR = (0b1 << PinNumber+16);
        }
        else if (HIGH==PinVal)
        {
            GPIOG->BSRR = (0b1 << PinNumber);
        }
        break;
    case PORTH:
        if (LOW==PinVal)
        {
            GPIOH->BSRR = (0b1 << PinNumber+16);
        }
        else if (HIGH==PinVal)
        {
            GPIOH->BSRR = (0b1 << PinNumber);
        }
        break;
    
    default:
        break;
    }
}

uint8_t GPIO_u8TogglePinValue(Port_t Port,Pin_t PinNumber)
{
    switch (Port)
    {
    case PORTA:
        GPIOA->OTYPER ^= (0b1 << PinNumber);
        break;
    case PORTB:
       GPIOB->OTYPER ^= (0b1 << PinNumber);
        break;
    case PORTC:
        GPIOC->OTYPER ^= (0b1 << PinNumber);
        break;
    case PORTD:
        GPIOD->OTYPER ^= (0b1 << PinNumber);
        break;
    case PORTE:
        GPIOE->OTYPER ^= (0b1 << PinNumber);
        break;
    case PORTF:
        GPIOF->OTYPER ^= (0b1 << PinNumber);
        break;
    case PORTG:
        GPIOG->OTYPER ^= (0b1 << PinNumber);
        break;
    case PORTH:
        GPIOH->OTYPER ^= (0b1 << PinNumber);
        break;
    
    default:
        break;
    }
}
uint8_t GPIO_u8GetPinValue(Port_t Port,Pin_t PinNumber,PinVal_t* PinVal)
{
    switch (Port)
    {
    case PORTA:
        *PinVal = (GPIOA->IDR>>PinNumber) & 1;

        break;
    case PORTB:
        *PinVal = (GPIOB->IDR>>PinNumber) & 1;
        
        break;
    case PORTC:
        *PinVal = (GPIOC->IDR>>PinNumber) & 1;
        
        break;
    case PORTD:
        *PinVal = (GPIOD->IDR>>PinNumber) & 1;
        
        break;
    case PORTE:
        *PinVal = (GPIOE->IDR>>PinNumber) & 1;
        
        break;
    case PORTF:
        *PinVal = (GPIOF->IDR>>PinNumber) & 1;
        
        break;
    case PORTG:
        *PinVal = (GPIOG->IDR>>PinNumber) & 1;
        
        break;
    case PORTH:
        *PinVal = (GPIOH->IDR>>PinNumber) & 1;
    
        break;
    
    default:
        break;
    }
}