#include <virtual_main.h>

int main(void)
{
	init();

	setup();
    
	for (;;)
		loop();
        
	return 0;
}

