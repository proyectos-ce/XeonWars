#include "entity.h"
Entity::Entity()
{

}

Entity::~Entity()
{
    delete motion;

}



void Entity::update(sf::RenderWindow &window, float time)
{
    sf::Vector2f newMove = motion->getNext(speed);
    sprite.move(newMove.x, newMove.y);
    animate(time);
}

void Entity::animate(float time)
{
    if (exploding) {
        updateTexture(currentTexture+1);

        if (currentTexture == 18) {
            sprite.move(0, 2000);
        }
    }
}

void Entity::render(sf::RenderWindow &window)
{
    window.draw(sprite);

}

void Entity::kill()
{
    //if(lifeFlag!=NULL)
    //{
    //    lifeFlag = false;
   // }
}

Motion *Entity::getMotion() const
{
    return motion;
}

void Entity::setMotion(Motion *value)
{
    motion = value;
}



/*void Entity::setTexture(sf::Texture value)
{
    texture = value;
    texture.setSmooth(true);
    sprite.setTexture(texture);
    updateTexture(0);
}
*/
sf::Sprite Entity::getSprite() const
{
    return sprite;
}

void Entity::setSprite(const sf::Sprite &value)
{
    sprite = value;
}

int Entity::getTexturesAmount() const
{
    return texturesAmount;
}

void Entity::setTexturesAmount(int value)
{
    texturesAmount = value;
    updateTexture(0);
}

void Entity::updateTexture(int value)
{
    if(value<texturesAmount){
    currentTexture=value;
    }
    else{
        currentTexture=0;
    }
    int rectX = (texture->getSize().x/texturesAmount), rectY = texture->getSize().y;
    sprite.setTextureRect(sf::IntRect(rectX*currentTexture,0 , rectX, rectY ));
}

void Entity::rotate(float angle)
{
    sprite.rotate(angle);
}

sf::Sprite *Entity::getSpriteReference()
{
    return &sprite;
}

sf::Texture *Entity::getTexture() const
{
    return texture;
}

void Entity::setTexture(sf::Texture *value)
{
    texture = value;
    sprite.setTexture(*texture);
    updateTexture(0);
}


float Entity::getSpeed() const
{
    return speed;
}

void Entity::setSpeed(float value)
{
    speed = value;
}

void Entity::setPosition(sf::Vector2f position)
{
    sprite.setPosition(position);
}

void Entity::setCenterPosition(sf::Vector2f position)
{
    sf::Vector2f centerPos;
    centerPos.x = sprite.getGlobalBounds().width/2+position.x;
    centerPos.y = sprite.getGlobalBounds().height/2+position.y;
    sprite.setPosition(centerPos);

}

sf::Vector2f Entity::getPosition()
{
    return sprite.getPosition();
}

sf::Vector2f Entity::getCenterPosition()
{
    sf::Vector2f position = sprite.getPosition();
    position.x+=(texture->getSize().x/texturesAmount/2);
    position.y+=(texture->getSize().y/texturesAmount/2);
    return position;

}

void Entity::setScale(float scale)
{
    sprite.setScale(scale, scale);
}




void Entity::explode() {
    if (!exploding) {
        setTexturesAmount(19);
        setTexture(SpritesManager::getInstance()->getExplosionTexture());
        exploding = true;
        setScale(0.6);
    }
}

bool Entity::isExploding() const {
    return exploding;
}


SpritesManager *SpritesManager::instance =NULL;


SpritesManager *SpritesManager::getInstance()
{
    if(!instance){
        instance = new SpritesManager;
    }
    return instance;
}

sf::Texture *SpritesManager::getJetTexture(){
    return &jetTexture;
}
sf::Texture *SpritesManager::getBomberTexture(){
    return &bomberTexture;
}
sf::Texture *SpritesManager::getTowerTexture(){
    return &towerTexture;
}
sf::Texture *SpritesManager::getMissileTowerTexture(){
    return &missileTowerTexture;
}
sf::Texture *SpritesManager::getKamikazeTexture(){
    return &kamikazeTexture;
}

sf::Texture *SpritesManager::getBossTexture()
{
    return &bossTexture;

}


sf::Texture *SpritesManager::getPlayerBulletTexture(){
    return &playerBulletTexture;
}

sf::Texture *SpritesManager::getFollowerBulletTexture(){
    return &followerBulletTexture;
}
sf::Texture *SpritesManager::getMissileTexture(){
    return &missileTexture;
}
sf::Texture *SpritesManager::getEnemyBulletTexture(){
    return &enemyBulletTexture;
}

sf::Texture *SpritesManager::getExplosionTexture() {
    return &explosionTexture;
}

sf::Texture *SpritesManager::getMissilePowerUpTexture() {
    return &missilePowerUpTexture;
}
sf::Texture *SpritesManager::getLaserPowerUpTexture() {
    return &laserPowerUpTexture;
}
sf::Texture *SpritesManager::getShieldPowerUpTexture() {
    return &shieldPowerUpTexture;
}

SpritesManager::SpritesManager()
{
    jetTexture.loadFromFile("Resources/Jet.png");
    bomberTexture.loadFromFile("Resources/Bomber.png");
    towerTexture.loadFromFile("Resources/Tower.png");
    missileTowerTexture.loadFromFile("Resources/MissileTower.png");
    kamikazeTexture.loadFromFile("Resources/Kamikaze.png");
    bossTexture.loadFromFile("Resources/Boss1.png");


    playerBulletTexture.loadFromFile("Resources/Bullets.png");
    followerBulletTexture.loadFromFile("Resources/FollowerBullet.png");
    missileTexture.loadFromFile("Resources/Missiles.png");
    enemyBulletTexture.loadFromFile("Resources/EnemyBullets.png");
    explosionTexture.loadFromFile("Resources/explosion.png");

    missilePowerUpTexture.loadFromFile("Resources/MissilePowerUp.png");
    laserPowerUpTexture.loadFromFile("Resources/LaserPowerUp.png");
    shieldPowerUpTexture.loadFromFile("Resources/ShieldPowerUp.png");
}


