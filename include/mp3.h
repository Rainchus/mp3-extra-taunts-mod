/*
Here we create declarations for a few functions and variables in Mario Party 3 so they can be referenced from our C code.
Later we will tell armips their addresses by defining labels for them in mp3.asm.
*/

#define NULL 0

/* Buttons */

#define CONT_A      0x8000
#define CONT_B      0x4000
#define CONT_G	    0x2000
#define CONT_START  0x1000
#define CONT_UP     0x0800
#define CONT_DOWN   0x0400
#define CONT_LEFT   0x0200
#define CONT_RIGHT  0x0100
#define CONT_L      0x0020
#define CONT_R      0x0010
#define CONT_E      0x0008
#define CONT_D      0x0004
#define CONT_C      0x0002
#define CONT_F      0x0001

/* Nintendo's official button names */

#define A_BUTTON	CONT_A
#define B_BUTTON	CONT_B
#define L_TRIG		CONT_L
#define R_TRIG		CONT_R
#define Z_TRIG		CONT_G
#define START_BUTTON	CONT_START
#define U_JPAD		CONT_UP
#define L_JPAD		CONT_LEFT
#define R_JPAD		CONT_RIGHT
#define D_JPAD		CONT_DOWN
#define U_CBUTTONS	CONT_E
#define L_CBUTTONS	CONT_C
#define R_CBUTTONS	CONT_F
#define D_CBUTTONS	CONT_D

typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef unsigned short u16;
typedef char s8;
typedef unsigned char u8;

typedef struct playerMain {
/* 0x00 */ u8  unk_00;
/* 0x01 */ u8  cpu_difficulty;
/* 0x02 */ u8  controller_port_index;
/* 0x03 */ u8  characterID;
/* 0x04 */ u8  flags1; //value & 1 == Player is CPU
/* 0x05 */ char unk_05;
/* 0x06 */ s16 extraMinigameCoins; //extra coins collected in minigames
/* 0x08 */ s16 minigameCoins; //coins for winning current minigame
/* 0x0A */ s16 coins; //referenced as u16 and s16 (usually if u16 it's casted to s16)
/* 0x0C */ char unk_0C[2];
/* 0x0E */ s8  stars;
/* 0x0F */ u8  chainIndexCur;
/* 0x10 */ u8  spaceIndexCur;
/* 0x11 */ u8  chainIndexNext;
/* 0x12 */ u8  spaceIndexNext;
/* 0x13 */ u8  unk_13; //(Chain Index?)
/* 0x14 */ u8  unk_14; //(Space Index?)
/* 0x15 */ u8  chainIndexPrevious;
/* 0x16 */ u8  spaceIndexPrevious;
/* 0x17 */ u8  flags2;
/* 0x18 */ u8  items[3];
/* 0x1B */ u8  bowser_suit_flags;
/* 0x1C */ u8  turn_status; //space type landed on (blue, red, etc.)
/* 0x1D */ s8   playerIndex;
/* 0x1E */ char unk_1E[2]; //likely padding
/* 0x20 */ void* unk_20;
/* 0x24 */ void* player_obj; //ptr to struct 0x48 in size (things like model position, rotation, etc.)
/* 0x28 */ s16 minigameCoinsTotal; //for minigame star
/* 0x2A */ s16 coinsPeak; //most coins held at once for coin star
/* 0x2C */ s8 happeningSpacesLandedOn;
/* 0x2D */ s8 redSpacesLandedOn;
/* 0x2E */ s8 blueSpacesLandedOn;
/* 0x2F */ s8 chanceSpacesLandedOn;
/* 0x30 */ s8 bowserSpacesLandedOn;
/* 0x31 */ s8 battleSpacesLandedOn;
/* 0x32 */ s8 itemSpacesLandedOn;
/* 0x33 */ s8 bankSpacesLandedOn;
/* 0x34 */ s8 gameGuySpacesLandedOn;
/* 0x35 */ char unk_35[3]; //likely padding
} playerMain; //sizeof 0x38
//P1 = 0x800D1108
//P2 = 0x800D1140
//P3 = 0x800D1178
//P4 = 0x800D11B0

extern s16 	Player1HeldButtons; 	//0x800CCF7C
extern s16  PlayerPressedButtonsArray[4]; //0x800C9520
extern s16	Player1Pressedbuttons;	//0x800C9520
extern s16	Player2Pressedbuttons;	//0x800C9522
extern s16	Player3Pressedbuttons;	//0x800C9524
extern s16	Player4Pressedbuttons;	//0x800C9526
extern s32  inBoardPtr; //0x800CC3DC
extern playerMain* GetPlayerStruct(s32 playerIndex);

//functions
extern s32 GetCurrentPlayerIndex(void); //0x800F2130
extern void unknownDMAFunc(s32 romAddr, void* ramDestination, s32 size);
extern void PlaySound(s32 soundIndex);




