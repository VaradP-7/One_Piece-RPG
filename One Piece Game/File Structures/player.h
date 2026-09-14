#ifndef PLAYER_H
#define PLAYER_H

struct Player
{
    int player_faction;

    // Stats
    int player_atk;
    int player_max_hp;
    int player_def;
    int player_speed;
};

extern struct Player faction[];

void player_attack(int *player_damage,
                   int player_atk,
                   int enemy_def,
                   int random_fruit,
                   int move_choice,
                   int *enemy_hp);

#endif