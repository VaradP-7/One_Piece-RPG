#ifndef ELITE_BOSSES_H
#define ELITE_BOSSES_H

struct Boss_Moveset
{
    char *move_name;
    float move_multiplier;
};

struct Elite_Bosses
{
    char *elite_boss_name;

    int spawn_player_level;
    int elite_boss_atk;
    int elite_boss_hp;
    int elite_boss_def;
    int elite_boss_speed;

    int defeated;

    struct Boss_Moveset boss_moves[3];
};

extern struct Elite_Bosses bosses[];
extern int boss_count;

#endif