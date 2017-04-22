#ifndef FLYINGPOWERUP_H
#define FLYINGPOWERUP_H
#include "entity.h"
#include "motion.h"
#include "powerUp.h"

class FlyingPowerUp : public Entity
{
public:
    FlyingPowerUp(sf::Texture *texture, Motion *motion);
    powerUp getPowerup() const;
    void setPowerup(const powerUp &value);
    void animate(float passedTime);
    void update(sf::RenderWindow &window, float time);
private:
    powerUp powerup;
    float time=0;

};

namespace PowerUpFactory {
FlyingPowerUp *createMisilePU(sf::Vector2f position,int speed = 2);
FlyingPowerUp *createLaserPU(sf::Vector2f position,int speed = 2);
FlyingPowerUp *createShieldPU(sf::Vector2f position,int speed = 2);
}

#endif // FLYINGPOWERUP_H
