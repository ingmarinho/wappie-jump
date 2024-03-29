#pragma once

// Window size
#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1024

#define SPLASH_STATE_SHOW_TIME 3.0f

// Text strings to be shown in-game
#define GAME_QUOTE_TEXT                         "Breek zoveel mogelijk IC-bedden!"
#define PAUSE_TITLE_TEXT                        "PAUSED"
#define GAME_OVER_TEXT                          "YOU DIED!"

#define SCORE_TEXT                              "SCORE: "
#define HIGHSCORE_TEXT                          "HIGHSCORE: "

#define SETTINGS_TEXT                           "SETTINGS"
#define LOW_SOUND_TEXT                          "LOW"
#define MEDIUM_SOUND_TEXT                       "MEDIUM"
#define HARD_SOUND_TEXT                         "HARD"

#define DIFFICULTY_EASY_TEXT                    "EASY"
#define DIFFICULTY_MEDIUM_TEXT                  "NORMAL"
#define DIFFICULTY_HARD_TEXT                    "HARD"

////////////////////// FILEPATHS //////////////////////////////
#define SPEEDOMETER_FILEPATH                    "Resources/res/speedometer.png"

#define SELECT_BUTTON_FILEPATH                  "Resources/res/select.png"              

// Backgrounds
#define SPLASH_SCENE_BACKGROUND_FILEPATH        "Resources/res/hu.png"
#define MAIN_MENU_BACKGROUND_FILEPATH           "Resources/res/space.png"
#define CHARACTER_SELECTION_BACKGROUND_FILEPATH "Resources/res/PickStateBackground.png"
#define GAME_BACKGROUND_FILEPATH                "Resources/res/space.png"
#define GAME_OVER_BACKGROUND_FILEPATH           "Resources/res/mark.png"
#define PAUSE_BACKGROUND_FILEPATH               "Resources/res/space.png"

// Power-ups and -downs
#define CORONA_FILEPATH                         "Resources/res/corona.png"
#define VACCINE_POWERUP_FILEPATH                "Resources/res/vaccine.png"

// Main menu buttons and titles
#define GAME_TITLE_FILEPATH                     "Resources/res/title.png"
#define PLAY_BUTTON_FILEPATH                    "Resources/res/play.png"
#define PLAY_BUTTON_DOWN_FILEPATH               "Resources/res/play_down.png"

// Character selection screen buttons and titles
#define CHARACTER_SELECTION_TITLE_FILEPATH      "Resources/res/title.png"
#define ARROW_LEFT_FILEPATH                     "Resources/res/Arrow_left_2.png"
#define ARROW_RIGHT_FILEPATH                    "Resources/res/Arrow_right_2.png"
#define SETTINGS_BUTTON_FILEPATH                "Resources/res/settingsButton.png"

// Pause screen buttons and titles
#define RESUME_BUTTON_FILEPATH                  "Resources/res/resume.png"
#define HOME_BUTTON_FILEPATH                    "Resources/res/main_menu.png"
#define PAUSE_BUTTON_FILEPATH                   "Resources/res/PauseButton.png"

// Game over screen buttons
#define PLAY_AGAIN_BUTTON_FILEPATH              "Resources/res/newGame.png"
#define MAIN_MENU_BUTTON_FILEPATH               "Resources/res/return.png"

// Settings screen buttons and titles
#define MUTE_SOUND_BUTTON_FILEPATH              "Resources/res/soundButtonMute.png"
#define SOUND_BUTTON_FILEPATH                   "Resources/res/soundButton.png"
#define DIFFICULTY_BUTTON_FILEPATH              "Resources/res/vaccineFlipped.png"
#define SETTINGS_RETURN_BUTTON_FILEPATH         "Resources/res/return_settings.png"

// Platforms
#define PLATFORM_FILEPATH                       "Resources/res/platform.png"
#define BOOSTER_PLATFORM_FILEPATH               "Resources/res/vaccine.png"
#define BREAKING_PLATFORM_FILEPATH              "Resources/res/platform_breaking.png"
#define MOVING_PLATFORM_FILEPATH                "Resources/res/platform_moving.png"

// Characters
#define CHAR1_FILEPATH                          "Resources/res/char1.png"
#define CHAR2_FILEPATH                          "Resources/res/char2.png"
#define CHAR3_FILEPATH                          "Resources/res/char3.png"
#define CHAR4_FILEPATH                          "Resources/res/char4.png"
#define CHAR5_FILEPATH                          "Resources/res/char5.png"
#define CHAR6_FILEPATH                          "Resources/res/char6.png"
#define CHAR7_FILEPATH                          "Resources/res/char7.png"
#define CHAR8_FILEPATH                          "Resources/res/char8.png"

// Fonts
#define FONT_FILEPATH                           "Resources/fonts/normal.otf"

// Audio
#define HIT_SOUND_FILEPATH                      "Resources/audio/Hit.wav"
#define JUMP_SOUND_FILEPATH                     "Resources/audio/Jump.wav"
#define BOOSTER_SOUND_FILEPATH                  "Resources/audio/Vaccine.wav"
#define MONSTER_SOUND_FILEPATH                  "Resources/audio/MonsterHit.wav"
#define GAME_OVER_SOUND_FILEPATH                "Resources/audio/Gameover.wav"
#define BUTTON_PRESS_FILEPATH                   "Resources/audio/buttonPress.wav"
#define BREAKING_BED_FILEPATH                   "Resources/audio/BreakingBed.wav"
///////////////////////////////////////////////////////////////


// Game configuration
#define PLATFORM_MOVEMENT_SPEED         5.0f
#define BREAKING_PLATFORM_FALL_SPEED    5.0f 
#define MAX_PLATFORMS                   25

#define PLAYER_VELOCITY_Y               20.0f
#define BOOSTER_VELOCITY_Y              50.0f
#define PLAYER_ACCELERATION_X           2.0f
#define PLAYER_VELOCITY_X_MAX           10.0f

#define GRAVITY                         0.7f

#define SCORE_X                         _scoreText.getGlobalBounds().width
#define SCORE_Y                         10

#define SCOREBOARD_X                    _scoreText.getGlobalBounds().width
#define SCOREBOARD_Y                    10

#define SOUND_VOLUME                    50

#define DIFFICULTY_LEVEL                100          // 1-100 (lower = harder)