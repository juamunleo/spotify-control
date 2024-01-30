#include "unity.h"

extern void player_test_volume(void);
extern void player_test_random(void);
extern void player_test_play(void);

// Needed functions for test framework
void setUp(void){}
void tearDown(void){}

int main(void) {
    UNITY_BEGIN();
    
    RUN_TEST(player_test_volume);
    RUN_TEST(player_test_random);
    RUN_TEST(player_test_play);
    
    return UNITY_END();
}