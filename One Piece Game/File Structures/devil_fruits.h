#ifndef DEVIL_FRUITS
#define DEVIL_FRUITS

struct Player_Moveset
{
    char *move_name;
    float move_atk_multiplier;
    int no_of_moves;
};

struct Devil_Fruit
{
    char *df_name;
    char *df_type;
    int df_atk;
    int df_hp;

    struct Player_Moveset player_moves [4];

};

extern struct Devil_Fruit fruits[];
extern int df_count;

#endif