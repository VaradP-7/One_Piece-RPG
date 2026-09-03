#ifndef DEVIL_FRUITS
#define DEVIL_FRUITS

struct Devil_Fruit
{
    char *df_name;
    char *df_type;
    int df_atk;
    int df_hp;
};

extern struct Devil_Fruit fruits[];
extern int df_count;

#endif