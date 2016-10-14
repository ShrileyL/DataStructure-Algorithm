//
//  Moster.cpp
//  MonsterGame
//
//  Created by KevinLiu on 16/10/14.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#include "Moster.hpp"

Moster::Moster(MonsterType type,string name,string roar,int n)
{
    m_type = type;
    m_name = name;
    m_roar = roar;
    m_hitPoints = n;
}

string Moster::getTypeString()
{
    switch (m_type) {
        case Dragon:
            return "Dragon";
        case Goblin:
            return "Goblin";
        case Ogre:
            return "Ogre";
        case Orc:
            return "orc";
        case Skeleton:
            return "Skeleton";
        case Troll:
            return "Troll";
        case Vampire:
            return "Vampire";
        case Zombie:
            return "Zombie";
    }
    return "???";
}

void Moster::print()
{
    cout << m_name <<" the " << getTypeString() << " has " << m_hitPoints << " hit points and says " << m_roar <<endl;

}

Moster MonsterGenerator::generateMonster()
{
    Moster::MonsterType type = static_cast<Moster::MonsterType>(getRandomNumber(0, Moster::MAX_MONSTER_TYPES - 1));
    int hitPoint = getRandomNumber(1, 100);
    
    static string s_names[6]{ "Blarg", "Moog", "Pksh", "Tyrn", "Mort", "Hans" };
    static string s_roars[6]{ "*ROAR*", "*peep*", "*squeal*", "*whine*", "*hum*", "*burp*"};
    
    return Moster(type, s_names[getRandomNumber(0, 5)], s_roars[getRandomNumber(0, 5)], hitPoint);
}
