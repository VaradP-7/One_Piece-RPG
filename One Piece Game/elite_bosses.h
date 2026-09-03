#ifndef ELITE_BOSSES_H
#define ELITE_BOSSES_H

struct Boss_Moveset
{
    char *move_name;
    int move_atk;
};

struct Elite_Bosses
{
    char *elite_boss_name;

    int spawn_player_level;
    int elite_boss_atk;
    int elite_boss_hp;

    int defeated;

    struct Boss_Moveset moves[3];
};

extern struct Elite_Bosses bosses[];
extern int boss_count;

#endif