#include "application.h"

int main(void) {
    
    app_setup();

    while(1) {
        app_loop();
    }

    return 0;
}