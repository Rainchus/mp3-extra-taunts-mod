#include "../include/mp3.h"

s16 characterVoiceBase[] = {
0x2AC, //despair 1 (c-right)
0x287, //despair 2 (c-left)
0x2B5, //good choice (c-down)
0x26C, //lose mini (c-up)
0x2BE, //taunt (L)
0x2C5, //super star (Z and L??)
0x290, //win mini (dpad right)
0x263, //win star (dpad left)
0x275, //win item (dpad down)
0x27E, //win game (dpad up)
};

s16 tauntButtonsArray[] = {
R_CBUTTONS, //despair 1 (c-right)
L_CBUTTONS, //despair 2 (c-left)
D_CBUTTONS, //good choice (c-down)
U_CBUTTONS, //lose mini (c-up)
L_TRIG, //taunt (L)
(Z_TRIG & L_TRIG), //super star (Z and L??)
R_JPAD, //win mini (dpad right)
L_JPAD, //win star (dpad left)
D_JPAD, //win item (dpad down)
U_JPAD, //win game (dpad up)
};

void playPlayerSadVoice(s32 playerIndex) {
    playerMain* player = GetPlayerStruct(playerIndex);
    PlaySound(player->characterID + 0x287); //should play current player sad voice
}

playerMain* getPlayerStructCustom(s32 playerIndex) {
	return (playerMain*)0x800D1108 + playerIndex;
}

void checkPlayerTaunt(s32 playerIndex) { //check if current player in loop should taunt
	playerMain* player = getPlayerStructCustom(playerIndex);
	if (!(player->flags1 & 1)) { //if player is not cpu
		s16 currentVoiceOffset = -1;
		if ((PlayerPressedButtonsArray[player->controller_port_index] & 0xFFFFFFFF) != 0) { //player has pressed *something*, check what
			for (s32 j = 0; j < sizeof(tauntButtonsArray) / sizeof(s16); j++) { //check what button was pressed
				if (PlayerPressedButtonsArray[player->controller_port_index] == tauntButtonsArray[j]) {
					currentVoiceOffset = j;
					break;
				} else {
					currentVoiceOffset = -1;
				}
			}

			if (currentVoiceOffset != -1) {
				PlaySound(characterVoiceBase[currentVoiceOffset] + player->characterID);
			}
		}
	}
}

void playerTauntsMain() {
	if (globalTaunt == 1) {
		for (s32 i = 0; i < 4; i++) { //iterate over 4 players
			checkPlayerTaunt(i);
		}
	} else {
		if (inBoardPtr != NULL) { //if in board
			if (canTauntDuringYourTurn == 1) {
				for (s32 i = 0; i < 4; i++) { //iterate over 4 players
					checkPlayerTaunt(i);
				}
			} else {
				for (s32 i = 0; i < 4; i++) { //iterate over 4 players
					if (GetCurrentPlayerIndex() != i) { //if not current player
						checkPlayerTaunt(i);
					}
				}
			}
		}
	}
}

void mainCFunction() {
	playerTauntsMain();
}

