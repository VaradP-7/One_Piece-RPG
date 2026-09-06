#ifndef PLAYER
#define PLAYER

struct Player_Moveset
{
    char *move_name;
    float move_atk_multiplier;
};

struct Player
{
    int player_faction;

    // Stats
    int player_atk;
    int player_hp;
    int player_max_hp;
    int player_defense;
    int player_speed;

    // Moveset
    struct Player_Moveset player_moves[4];
};

extern struct Player faction[];
extern moveset_count;

#endif