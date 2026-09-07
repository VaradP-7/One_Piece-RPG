#ifndef PLAYER_H
#define PLAYER_H

struct Player
{
    int player_faction;

    // Stats
    int player_atk;
    int player_hp;
    int player_max_hp;
    int player_defense;
    int player_speed;

};

extern struct Player faction[];

#endif