#ifndef ENEMY_H
#define ENEMY_H

void enemy_generation(int *enemy_hp,
                      int *enemy_max_hp,
                      int *enemy_atk,
                      int *enemy_def,
                      int *enemy_speed,
                      int player_level);

void enemy_attack(int boss_fight,
                  int *enemy_damage, int enemy_atk,
                  int boss_index,
                  int player_def,
                  int *player_hp,
                  struct Elite_Bosses *bosses);

#endif