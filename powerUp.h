//
// Created by jimena on 3/25/17.
//

#ifndef XEONWARS_ITEM_H
#define XEONWARS_ITEM_H
enum powerUps {missile, shieldd, laser};

class powerUp{
public:
    powerUp(){

    }
    powerUp(powerUps powerType){
        type = powerType;
    }
    powerUps getType(){
        return type;
    }

private:
    powerUps type;
};


#endif //XEONWARS_ITEM_H
