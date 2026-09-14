#include "player.h"
#include "devil_fruits.h"

struct Player faction[2] =
    {
        {0, 50, 200, 100, 100},
        {1, 30, 300, 150, 100}};

void player_attack(int *player_damage, int player_atk, int enemy_def, int random_fruit, int move_choice, int *enemy_hp)
{
    // Player damage Formula
    *player_damage = (player_atk * fruits[random_fruit].player_moves[move_choice - 1].move_atk_multiplier) + rand() % 31;
    *player_damage = *player_damage * 100 / (100 + enemy_def);

    // Critical hit
    if (rand() % 10 == 0)
    {
        *player_damage *= 2;
        printf("\nCRITICAL HIT!\n");
    }

    *enemy_hp -= *player_damage;

    if (*enemy_hp < 0)
    {
        *enemy_hp = 0;
    }

    printf("You dealt %d damage!\n", *player_damage);
}
