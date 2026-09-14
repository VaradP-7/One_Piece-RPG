#include "enemy.h"
#include "elite_bosses.h"

void enemy_generation(int *enemy_hp, int *enemy_max_hp, int *enemy_atk, int *enemy_def, int *enemy_speed, int player_level)
{
    *enemy_max_hp = 150 + rand() % 51 + (player_level * 100);
    *enemy_hp = *enemy_max_hp;
    *enemy_atk = 20 + rand() % 11 + (player_level * 10);
    *enemy_def = 50 + rand() % 21 + (player_level * 5);
    *enemy_speed = 10 + rand() % 6 + (player_level * 5);
}

void enemy_attack(int boss_fight, int *enemy_damage, int enemy_atk, int boss_index, int player_def, int *player_hp, struct Elite_Bosses *bosses)
{
    if (boss_fight == 1)
    {
        int special_chance = rand() % 100;

        // 70% normal attack
        if (special_chance < 75)
        {
            *enemy_damage = bosses[boss_index].elite_boss_atk + rand() % 30;
            *enemy_damage = *enemy_damage * 100 / (100 + player_def);

            printf("Boss dealt %d damage!\n", *enemy_damage);
        }

        // 25% chance of special attack
        else
        {
            int random_move = rand() % 3;

            *enemy_damage = (bosses[boss_index].elite_boss_atk) * (bosses[boss_index].boss_moves[random_move].move_multiplier);

            printf("\n%s USED %s!\n", bosses[boss_index].elite_boss_name, bosses[boss_index].boss_moves[random_move].move_name);

            *enemy_damage = *enemy_damage * 100 / (100 + player_def);

            printf("Boss dealt %d damage!\n", *enemy_damage);
        }

        *player_hp -= *enemy_damage;
    }
    else
    {
        // Normal enemy attack

        *enemy_damage = enemy_atk + rand() % 30;
        *enemy_damage = *enemy_damage * 100 / (100 + player_def);

        printf("Enemy dealt %d damage!\n", *enemy_damage);

        *player_hp -= *enemy_damage;
    }
}