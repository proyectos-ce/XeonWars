#ifndef FLYINGPOWERUP_H
#define FLYINGPOWERUP_H
#include "entity.h"
#include "motion.h"
#include "powerUp.h"

class FlyingPowerUp :Entity
{
public:
    FlyingPowerUp(sf::Texture *texture, Motion *motion);
    powerUps getPowerup() const;
    void setPowerup(const powerUps &value);
    void animate(float passedTime);
    void update(sf::RenderWindow &window, float time);
private:
    powerUps powerup;
    float time=0;

};

namespace PowerUpFactory {
FlyingPowerUp *createMisilePU();
FlyingPowerUp *createLaserPU();
FlyingPowerUp *createShieldPU();


}

#endif // FLYINGPOWERUP_H
