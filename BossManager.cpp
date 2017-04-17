//
// Created by danielc on 15/04/17.
//

#include "BossManager.h"
BossManager::BossManager(){
};
void BossManager::BossInit(int level) {
    BossLevel=level;
    Bosslife=level*100;

}
bool BossManager::isdead() {
    bool result = false;
    if (Bosslife <= 0){
        result = true;
    }
    return result;
}