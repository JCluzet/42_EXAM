#include "BrickWall.hpp"

BrickWall::BrickWall(): ATarget("Inconspicuous Red-brick Wall") {}
BrickWall::~BrickWall() {}

ATarget *BrickWall::clone() const
{
    return (new BrickWall());
}