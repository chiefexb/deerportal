#include "boardelem.h"

namespace efc {
sf::RectangleShape createNeighbour(int pos) {

    sf::RectangleShape rectangle(sf::Vector2f(efc::TILE_SIZE, efc::TILE_SIZE));
    sf::Vector2i cords(efc::transPosition(pos));

    rectangle.setFillColor(sf::Color(240, 240, 240,98));
    rectangle.setOutlineColor(sf::Color(24,24,24, 90));

    rectangle.setPosition(cords.x*efc::TILE_SIZE, cords.y*efc::TILE_SIZE);
    return rectangle;


}
}

efc::BoardElem::BoardElem(int pos, int type)
{
    this->pos = pos;
    this->type = type;
    sf::Vector2i cords = efc::transPosition(pos);
    int y_type = (int) type / efc::TILE_BOARD_SIZE;
    int x_type = type % efc::TILE_BOARD_SIZE;
    setPosition(cords.x*efc::TILE_SIZE,cords.y*efc::TILE_SIZE);
    setTextureRect(sf::IntRect(x_type*efc::TILE_SIZE, y_type*efc::TILE_SIZE, efc::TILE_SIZE, efc::TILE_SIZE));
    textureTiles = nullptr;
}


