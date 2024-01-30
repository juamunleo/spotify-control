#include "unity.h"
#include "player.h"

#define PLAYER_VOLUME_STEP 5

void player_test_volume(void) {
    player_init();
    
    uint8_t initVolume = player_getVolume();
    player_volUp();
    TEST_ASSERT_EQUAL(initVolume+PLAYER_VOLUME_STEP, player_getVolume());

    initVolume = player_getVolume();
    player_volDown();
    TEST_ASSERT_EQUAL(initVolume-PLAYER_VOLUME_STEP, player_getVolume());

    player_vol(150);
    TEST_ASSERT_EQUAL(100, player_getVolume());

    player_vol(100);
    player_volUp();
    TEST_ASSERT_EQUAL(100, player_getVolume());

    player_vol(0);
    player_volDown();
    TEST_ASSERT_EQUAL(0, player_getVolume());
}

void player_test_random(void) {
    player_init();

    player_toggleRandom();
    TEST_ASSERT_TRUE(player_isRandomEnabled());

    player_toggleRandom();
    TEST_ASSERT_FALSE(player_isRandomEnabled());
}

void player_test_play(void) {
    player_init();

    player_togglePlay();
    TEST_ASSERT_TRUE(player_isPlaying());

    player_togglePlay();
    TEST_ASSERT_FALSE(player_isPlaying());
}