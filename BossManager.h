//
// Created by danielc on 15/04/17.
//

#ifndef XEONWARS_BOSSMANAGER_H
#define XEONWARS_BOSSMANAGER_H


class BossManager {
public:
    BossManager();
    int Bosslife;
    void BossInit(int level);
    int BossLevel;
    bool isdead();
private:
};


#endif //XEONWARS_BOSSMANAGER_H
