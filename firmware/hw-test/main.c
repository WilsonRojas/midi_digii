/**
 * 
 */

#include "soc-hw.h"
void irq_handler(uint32_t pending);

void irq_handler(uint32_t pending)
{
	irq_disable();	
	gpio_set_out(0xFF);
        //irq_enable();
}


int main()
{
	char veloc;//velocidad constante 100 en data2
	char heig;//nota grabe 0 to 127	

        gpio_set_dir(0xF0);
	
        irq_enable();
        irq_set_mask(0x04);
	msleep(5);

	veloc=0x64;
	heig=0x1F;
	midi_start();
	midi_note_on(heig, veloc);
	midi_note_off();
	//uint32_t a2 = 4;
	/*while (gpio0 -> gpio_dir = 0xFF){
		
	gpio0 -> gpio_in;	
	gpio0->gpio_o = 0x01;
	nsleep(5);
	gpio0 -> gpio_in;
	gpio0->gpio_o = 0x00;
	nsleep(5);
}*/ 

uint8_t a ;	
uint8_t b ;	
char c;// = gpio_get_in();
char m;
	
	while (1){
        
	spi_set_cs(spi0, ~0x00);
	//msleep(100);
	spi_set_cs(spi0, ~0xFF);
	//msleep(100);			
	spi_set_mosi(spi0, 0xA0);

	spi_set_cs(spi1, ~0x00);
	//msleep(200);
	spi_set_cs(spi1, ~0xFF);
	//msleep(200);			
	spi_set_mosi(spi1, 0x0A);

	
	
	a= gpio_get_in();
	nsleep(5);
	gpio_set_out(a);
	nsleep(5);
	b = a << 4;
	gpio_set_out(b);
	nsleep(5);
	
	irq_set_mask(0x00);
	
	irq_set_mask(0x02);
	
	irq_set_mask(0x04);
	
	irq_set_mask(0x08);
	
	
	if (a == 0x0F){
	uart_putstr("lo ke sea: \n");
	
	}
}

/*int i=0;	
for(i=0; i<1000000; i++){
	if(i<500000){
		gpio_set_out(0xFF);	
	}
	else{
	gpio_set_out(0x00);
		}

*/	


	/*char id = uart_getchar ();
	
	switch (id) {
		case 'n':
			uart_putstr("su nombre\n");
		break;

		case 'p':
			uart_putstr("su apellido\n");
		break;

		case 'c':
			uart_putstr("su nombre\n");
		break;

		default:
			uart_putstr("ingrese un dato\n");
			}*/
	/*spi_set_cs(~0x00);
	msleep(100);
	spi_set_cs(~0xFF);
	msleep(100);	
	spi_set_mosi(0xAA);*/
}

