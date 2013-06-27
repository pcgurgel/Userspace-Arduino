#include <virtual_main.h>

int main(void)
{
	init();
    printf("Returned to main!\n Calling setup() and init()...\n");
	setup();
    
	for (;;)
		loop();
        
	return 0;
}
