#include <atmel_start.h>
#include <stdlib.h>
#include "ftn_vip_lib/usbUART.h"
#include "ftn_vip_lib/clickUART.h"
#include "ftn_vip_lib/timer_1ms.h"

int main(void)
{
	//Inicijalizacija
	atmel_start_init();
	clickUARTinit();
	usbUARTinit();
	timer_1ms_init();

	char str[256];
	delay(3000);
	sprintf(str, "--- FTN-VIP NB-IoT ---\r\n");
	usbUARTputString(str);
	setLEDfreq(FREQ_1HZ);
	enableLED();

	setLEDfreq(FREQ_1HZ);

	//USB serial <-> Click serial
	while (1)
	{
		gpio_set_pin_level(CLICK_RST, !gpio_get_pin_level(BUTTON));
		
		if(usbUARTavailable())
		{
			delay(20);
			usbUARTgetString(str);
			clickUARTputString(str);
		}
		
		if(clickUARTavailable())
		{
			delay(20);
			clickUARTgetString(str);
			usbUARTputString(str);
		}
	}
}

