//
//  Moster.hpp
//  MonsterGame
//
//  Created by KevinLiu on 16/10/14.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#ifndef Moster_hpp
#define Moster_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <ctime> // for time()
#include <cstdlib> // for rand() and srand()
using namespace std;



class Moster
{
public:
    enum MonsterType
    {
        Dragon,
        Goblin,
        Ogre,
        Orc,
        Skeleton,
        Troll,
        Vampire,
        Zombie,
        MAX_MONSTER_TYPES
    };
    Moster(MonsterType,string,string,int);
    void print();
    string getTypeString();
private:
    MonsterType m_type;
    string m_name;
    string m_roar;
    int m_hitPoints;
};

class MonsterGenerator
{
public:
    static Moster generateMonster();
    // Generate a random number between min and max (inclusive)
    // Assumes srand() has already been called
    static int getRandomNumber(int min, int max)
    {
        static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
        // evenly distribute the random number across our range
        return static_cast<int>(rand() * fraction * (max - min + 1) + min);
    }
};

#endif /* Moster_hpp */
