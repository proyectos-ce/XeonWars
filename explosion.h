#ifndef EXPLOSION_H
#define EXPLOSION_H
#include "entity.h"
#include "motion.h"

class Explosion : public Entity
{
public:
    Explosion(sf::Vector2f position);
    void animate(float passedTime);
    void update(sf::RenderWindow &window, float time);
    int getUpdateCont() const;
    void setUpdateCont(int value);
    bool finished();

private:
    int updateCont=0;
    float time=0;


};
namespace ExplosionFactory {
Explosion *createSimpleExplosion(sf::Vector2f position, int speed=2);

}
#endif // EXPLOSION_H
