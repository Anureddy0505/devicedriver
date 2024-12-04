//RCC
#define RCC_AHB1ENR *((int *)0x40023830)
#define RCC_APB2ENR *((int *)0x40023844)
	
//NVIC
#define NVIC_ISER0 *((int *)0xE000E100)
#define NVIC_ISER1 *((int *)0xE000E104)
#define NVIC_ISER2 *((int *)0xE000E108)
	
// GPIO MODER
#define GPIOA_MODER *((int *)0x40020000)
#define GPIOB_MODER *((int *)0x40020400)
#define GPIOC_MODER *((int *)0x40020800)
	
//GPIO PUPDR
#define GPIOA_PUPDR *((int *)0x4002000C)
#define GPIOB_PUPDR *((int *)0x4002040C)
#define GPIOC_PUPDR *((int *)0x4002080C)
	
// GPIO ODR
#define GPIOA_ODR   *((int *)0x40020014)
#define GPIOB_ODR   *((int *)0x40020414)
#define GPIOC_ODR   *((int *)0x40020814)

// GPIO IDR
#define GPIOA_IDR   *((int *)0x40020010)
#define GPIOB_IDR   *((int *)0x40020410)
#define GPIOC_IDR   *((int *)0x40020810)
	
//GPIO ALTERNATE REGISTER 
#define GPIOA_AFRH  *((int *)0x40020024)
#define GPIOB_AFRH  *((int *)0x40020424)
#define GPIOC_AFRH  *((int *)0x40020824)
	
#define GPIOA_AFRL  *((int *)0x40020020)
#define GPIOB_AFRL  *((int *)0x40020420)
#define GPIOC_AFRL  *((int *)0x40020820)
	
//ADC
#define ADC_SR *((int *)0x40012000)
#define ADC_CR1 *((int *)0x40012004)
#define ADC_CR2 *((int *)0x40012008)
#define ADC_SMPR1 *((int *)0x4001200C)
#define ADC_SQR3 *((int *)0x40012034)
#define ADC_DR *((int *)0x4001204C)
	
// USART6
#define USART6_SR   *((int *)0x40011400)
#define USART6_DR   *((int *)0x40011404)
#define USART6_CR1  *((int *)0x4001140c)
#define USART6_BRR  *((int *)0x40011408)

// USART1
#define USART1_SR   *((int *)0x40011000)
#define USART1_DR   *((int *)0x40011004)
#define USART1_CR1  *((int *)0x4001100c)
#define USART1_BRR  *((int *)0x40011008)

//SYSTICK CONTROLLER
#define STK_CTRL *((int *)0xE000E010)
#define STK_LOAD *((int *)0xE000E014)
#define STK_VAL *((int *)0xE000E018)
	
#define MASK(p) (0x01<<p)

void init(void);
void config(void);
void operation(void);
void UART2_TX_OutChar (unsigned char);
void USART1_IRQHandler(void);
char receive_data;
int main()
{
	init();
	config();
	operation();
}

void init(void)
{
	RCC_AHB1ENR|=0x01; //set 0th bit position to enable port A CLK
	RCC_APB2ENR|=MASK(4); //set 4th bit position to enable USART 1 CLK
}

void config(void)
{
	GPIOA_MODER|=0x00280000; //load 1010 in 21-18 bit postion to config to alternate mode
	GPIOA_AFRH|=0x00000770; //load 01110111 in 11-4 bit postion to enable alternate function
	USART1_BRR|=0x683; //load 9600 for set baud rate
	USART1_CR1|=MASK(2); //set 2nd bit to enable receiver
	USART1_CR1|=MASK(5); //set 5th bit to enable interrupt for receiver
	USART1_CR1|=MASK(3); //set 3rd bit to enable transmitter
	USART1_CR1|=MASK(13); //set 13th bit to enable USART1
	NVIC_ISER1|=MASK(5); //set 5th bit to enable interrupt for USART1
}
void operation(void)
{
	while(1)
		UART2_TX_OutChar('A');

}

void UART2_TX_OutChar(unsigned char character)
{
	while(!(USART1_SR&MASK(7)));
	USART1_DR=character;
}

void USART1_IRQHandler(void)
{
	receive_data=USART1_DR;
}

