#ifndef GAME_H
#define GAME_H
#include <stdlib.h>
#include <iostream>
#include <time.h>       /* time */

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "command.h"
#include "tilemap.h"
#include "selector.h"
#include "playerhud.h"
#include "textureholder.h"
#include "hover.h"
#include "guichoosebuilding.h"
#include "guiwindow.h"
#include "rounddice.h"
#include "guirounddice.h"
#include "grouphud.h"
#include "animatedsprite.h"
#include "character.h"
#include "rotateelem.h"
#include "boarddiamondseq.h"
#include "soundfx.h"
#include "cardsdeck.h"

//class Command;

namespace efc {

extern int initScreenX;
extern int initScreenY;


class Game
{

private:
    sf::Vector2i screenSize;

public:
    Game();
    sf::RenderWindow window;
    sf::View viewFull;
    sf::View viewGui;
    sf::View viewTiles;
    BoardDiamondSeq boardDiamonds;
    PlayerHud players[4];

private:
    void initBoard();
    void loadAssets();
    void drawPlayersGui();
    void drawSquares();

    void drawMenu();

    sf::Vector2f getMousePos();

    enum states {
        state_init,
        state_menu,
        state_lets_begin,
        state_roll_dice,
        state_game,

        state_gui_elem,
        state_select_building,
        state_gui_end_round,
        state_end_game,
        state_quit
    };

    states currentState;

    sf::Texture textureBackground;
    sf::Sprite spriteBackground;
    sf::Sprite gameBackground;
    sf::Sprite spriteBackgroundDark;

    sf::Sprite spriteLestBegin;

    sf::Texture textureBackgroundArt;
    sf::Sprite spriteBackgroundArt;

    sf::Texture textureTiles;
    sf::Texture textureFaces;
    sf::Font gameFont;
    sf::Font menuFont;
    sf::Text menuTxt;



    TileMap map;

    int mapSize;
    int level[256];
    int levelElems[256];
    TextureHolder textures;
    std::set<int> currentNeighbours;
    void command(std::string command);
    int selectedPos;
    Selector selector;
    GuiChooseBuilding guiSelectBuilding;
    Character character;

    int turn;
    void update(sf::Time frameTime);
    void render();

    std::string gameTitle;

    RoundDice roundDice;
    int roundNumber;


    GuiRoundDice guiRoundDice;
    void setCurrentNeighbours ();
    void nextPlayer();

    void nextRound();


    sf::Sprite menuBackground;
    sf::Sprite seasons[4];
    //int currentSeason = 0;

    sf::Music musicGame;
    sf::Music musicBackground;
    sf::Music musicMenu;

    sf::SoundBuffer sfxClickBuffer;
    sf::Sound sfxClick;

    sf::SoundBuffer sfxDoneBuffer;
    sf::Sound sfxDone;

    void showMenu();

    void hideMenu();
    void showGameBoard();
    void hideGameBoard();


    GroupHud groupHud;

    /*!
     * \brief showPlayerBoardElems defines if show mouse hover for the player
     */
    bool showPlayerBoardElems;

    void drawBaseGame();
    int month;

    Animation walkingAnimationDown;
    Animation walkingAnimationUp;
    Animation walkingAnimationLeft;
    Animation walkingAnimationRight;
    Animation* currentAnimation;
    AnimatedSprite animatedSprite;

    void drawCharacters();
    void handleLeftClick(sf::Vector2f pos,
                         sf::Vector2f posGui, sf::Vector2f posFull, int mousePos);

    std::set<int> busyTiles;

    int diceResultPlayer;
    int numberFinishedPlayers;
    RotateElem nextRotateElem;
    RotateElem prevRotateElem;
    void endGame();

    SoundFX sfx;
    float downTimeCounter;
    Command commandManager;
    CardsDeck cardsDeck;

};
}
#endif // GAME_H
