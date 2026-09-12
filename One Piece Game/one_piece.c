#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "File Structures/elite_bosses.h"
#include "File Structures/devil_fruits.h"
#include "File Structures/player.h"

void enemy_generation(int *enemy_hp, int *enemy_max_hp, int *enemy_atk, int *enemy_def, int *enemy_speed, int *player_level)
{
    *enemy_max_hp = 150 + rand() % 51 + (*player_level * 100);
    *enemy_hp = *enemy_max_hp;
    *enemy_atk = 20 + rand() % 11 + (*player_level * 10);
    *enemy_def = 100 + rand() % 21 + (*player_level * 30);
    *enemy_speed = 10 + rand() % 6 + (*player_level * 5);
}

// MAIN FUNCTION
int main()
{
    srand(time(0));

    // PLAYER
    int player_faction;
    int player_hp;
    int max_hp;
    int player_atk;
    int player_def;
    int player_speed;

    int parry_turns;

    // DEVIL FRUIT
    int df_atk;
    int df_hp;
    int df_def;
    int df_speed;

    // PROGRESSION
    int player_level = 1;
    int xp = 0;

    // ENEMY
    int enemy_hp;
    int enemy_atk;
    int enemy_max_hp;
    int enemy_def;
    int enemy_speed;
    int enemy_damage;
    int enemy_level;

    // ELITE BOSS

    // ATTACK
    int choice;
    int move_choice;
    int player_damage;

    int bounty = 0;

    printf("Choose your faction: \n");
    printf("1. Pirate \n");
    printf("2. Marine \n");
    printf("Enter choice: ");
    scanf("%d", &player_faction);

    if (player_faction == 1)
    {
        player_atk = faction[0].player_atk;
        max_hp = faction[0].player_max_hp;
        player_def = faction[0].player_def;
        player_speed = faction[0].player_speed;
        printf("You chose to become a Pirate! \n");
    }
    else if (player_faction == 2)
    {
        player_atk = faction[1].player_atk;
        max_hp = faction[1].player_max_hp;
        player_def = faction[1].player_def;
        player_speed = faction[1].player_speed;
        printf("You chose to become a Marine! \n");
    }
    else
    {
        printf("Invalid choice. You are a Pirate.\n");
        player_atk = faction[0].player_atk;
        max_hp = faction[0].player_max_hp;
        player_def = faction[0].player_def;
        player_speed = faction[0].player_speed;
        player_faction = faction[0].player_faction;
    }
    player_hp = max_hp;

    // DEVIL FRUIT

    int random_fruit = rand() % df_count;

    printf("\n=================================\n");
    printf("YOU GOT A DEVIL FRUIT!\n");
    printf("=================================\n");

    printf("Name: %s\n", fruits[random_fruit].df_name);
    printf("Type: %s\n", fruits[random_fruit].df_type);
    printf("Attack: %d\n", fruits[random_fruit].df_atk);
    printf("HP: %d\n", fruits[random_fruit].df_hp);
    printf("Defense: %d\n", fruits[random_fruit].df_def);
    printf("Speed: %d\n", fruits[random_fruit].df_speed);

    df_atk = fruits[random_fruit].df_atk + (player_level * 3);
    df_hp = fruits[random_fruit].df_hp + (player_level * 5);
    df_def = fruits[random_fruit].df_def + (player_level * 5);
    df_speed = fruits[random_fruit].df_speed + (player_level * 2);

    player_atk += df_atk;
    max_hp += df_hp;
    player_hp = max_hp;
    player_def = df_def;
    player_speed = df_speed;

    int remaining_moves[4];

    for (int i = 0; i < 4; i++)
    {
        remaining_moves[i] = fruits[random_fruit].player_moves[i].no_of_moves;
    }

    // player_atk += 2000; // testing

    // GAMEPLAY LOOP

    int game_over = 0;

    while (game_over == 0)
    {
        // BOSS FIGHT
        int boss_fight = 0;
        int boss_index = -1;

        for (int i = 0; i < boss_count; i++)
        {
            if (player_level == bosses[i].spawn_player_level && bosses[i].defeated == 0)
            {
                boss_fight = 1; // '1' means boss fight initiated
                boss_index = i;
                break;
            }
        }

        if (boss_fight == 1)
        {
            enemy_hp = bosses[boss_index].elite_boss_hp;
            enemy_max_hp = enemy_hp;
            enemy_atk = bosses[boss_index].elite_boss_atk;

            printf("\nELITE BOSS APPEARED!\n");
            printf("Boss: %s\n",
                   bosses[boss_index].elite_boss_name);
        }
        else
        { // Generate normal enemies
            enemy_generation(&enemy_hp, &enemy_max_hp, &enemy_atk, &enemy_def, &enemy_speed, &player_level);

            if (player_faction == 1)
            {
                int decision;
                decision = rand() % 2 + 1;
                if (decision == 1)
                {
                    printf("\n=================================\n");
                    printf("A NEW PIRATE HAS APPEARED!\n");
                    printf("Enemy HP: %d Enemy ATK: %d Enemy DEF: %d Enemy Speed: %d\n", enemy_hp, enemy_atk, enemy_def, enemy_speed);
                    printf("=================================\n");
                }
                else if (decision == 2)
                {
                    printf("\n=================================\n");
                    printf("A NEW MARINE HAS APPEARED!\n");
                    printf("Enemy HP: %d Enemy ATK: %d Enemy DEF: %d Enemy Speed: %d\n", enemy_hp, enemy_atk, enemy_def, enemy_speed);
                    printf("=================================\n");
                }
            }
            else if (player_faction == 2)
            {
                printf("=================================\n");
                printf("A NEW PIRATE HAS APPEARED!\n");
                printf("Enemy HP: %d Enemy ATK: %d Enemy DEF: %d Enemy Speed: %d\n", enemy_hp, enemy_atk, enemy_def, enemy_speed);
                printf("=================================\n");
            }
        }

        // BATTLE LOOP
        while (player_hp > 0 && enemy_hp > 0)
        {

            printf("\n---------------------------------\n");
            printf("Level: %d\n", player_level);
            printf("Your HP: %d/%d Your ATK: %d Your Def: %d Your Speed %d\n", player_hp, max_hp, player_atk, player_def, player_speed);
            printf("Enemy HP: %d/%d Enemy ATK: %d\n", enemy_hp, enemy_max_hp, enemy_atk);
            printf("---------------------------------\n");

            printf("1. Attack\n");
            printf("2. Dodge\n");
            printf("3. Parry\n");
            printf("4. Clear Screen\n");
            printf("5. Run\n");
            printf("Choose: ");
            scanf("%d", &choice);

            switch (choice)
            {

            case 1:
                // ATTACK
                printf("\n");
                printf("1. %s (%d/%d)\n", fruits[random_fruit].player_moves[0].move_name, remaining_moves[0], fruits[random_fruit].player_moves[0].no_of_moves);
                printf("2. %s (%d/%d)\n", fruits[random_fruit].player_moves[1].move_name, remaining_moves[1], fruits[random_fruit].player_moves[1].no_of_moves);
                printf("3. %s (%d/%d)\n", fruits[random_fruit].player_moves[2].move_name, remaining_moves[2], fruits[random_fruit].player_moves[2].no_of_moves);
                printf("4. %s (%d/%d)\n", fruits[random_fruit].player_moves[3].move_name, remaining_moves[3], fruits[random_fruit].player_moves[3].no_of_moves);
                printf("Choose: ");
                scanf("%d", &move_choice);

                remaining_moves[move_choice - 1]--;

                // Player damage Formula
                player_damage = (player_atk * fruits[random_fruit].player_moves[move_choice - 1].move_atk_multiplier) + rand() % 31;

                // Critical hit
                if (rand() % 10 == 0)
                {
                    player_damage *= 2;
                    printf("\nCRITICAL HIT!\n");
                }

                enemy_hp -= player_damage;

                if (enemy_hp < 0)
                {
                    enemy_hp = 0;
                }

                printf("You dealt %d damage!\n", player_damage);
                break;

            case 2:
                // DODGE
                if (rand() % 2)
                {
                    printf("\nYou dodged enemy's attack successfully.\n");
                    continue;
                }
                else
                {
                    printf("\nDodge failed.\n");
                }
                break;

            case 3:
                // PARRY
                if (rand() % 2)
                {
                    printf("\nYou successfully parried the enemy!\n");
                    printf("Enemy is stunned for 2 turns!\n");

                    parry_turns = 2;
                }
                else
                {
                    printf("\nParry failed.\n");
                }
                break;

            case 4:
                // CLEAR SCREEN
                system("cls");
                break;

            case 5:
                // RUN
                printf("\nYou ran away!\n");
                game_over = 1;
                break;

            default:
                printf("Invalid choice!\n");
                continue;
            }

            if (game_over == 1)
            {
                break;
            }

            // ---------------- ENEMY IS DEAD ----------------

            if (enemy_hp <= 0)
            {
                if (boss_fight == 1)
                {
                    bosses[boss_index].defeated = 1;

                    printf("\n=================================\n");
                    printf("     ELITE BOSS DEFEATED!\n");
                    printf("=================================\n");

                    xp += 100;

                    // Moves restored
                    for (int i = 0; i < 4; i++)
                    {
                        remaining_moves[i] = fruits[random_fruit].player_moves[i].no_of_moves;
                    }

                    printf("\nYou gained 100 XP!\n");
                    printf("Current XP: %d\n", xp);
                }
                else
                {
                    printf("\nYOU DEFEATED THE ENEMY!!\n");
                    xp += 50;

                    printf("You gained 50 XP!\n");
                    printf("Current XP: %d\n", xp);
                }

                // LEVELING

                if (xp >= player_level * 100)
                {
                    player_level++;

                    player_atk += 20;
                    max_hp += 50;
                    player_def += 50;
                    player_speed += 10;

                    player_hp = max_hp; // Most probably this will be removed

                    printf("\n*** LEVEL UP! ***\n");
                    printf("You are now level %d!\n", player_level);

                    printf("Attack increased by %d!\n", 20);
                    printf("Max HP increased by %d!\n", 50);
                    printf("Defense increased by %d!\n", 50);
                    printf("Speed increased by %d!\n", 10);
                }

                continue;
            }

            // ---------------- PARRY ----------------

            if (parry_turns > 0)
            {
                printf("\nEnemy is stunned and cannot attack!\n");

                parry_turns--;

                continue;
            }

            // ---------------- ENEMY ATTACK ----------------

            if (boss_fight == 1)
            {
                int special_chance = rand() % 100;

                // 70% normal attack
                if (special_chance < 75)
                {
                    enemy_damage = bosses[boss_index].elite_boss_atk + rand() % 30;

                    printf("Boss dealt %d damage!\n", enemy_damage);
                }

                // 25% chance of special attack
                else
                {
                    int random_move = rand() % 3;

                    enemy_damage = (bosses[boss_index].elite_boss_atk) * (bosses[boss_index].boss_moves[random_move].move_multiplier);

                    printf("\n%s USED %s!\n",
                           bosses[boss_index].elite_boss_name,
                           bosses[boss_index].boss_moves[random_move].move_name);

                    printf("Boss dealt %d enemy_damage!\n", enemy_damage);
                }

                player_hp -= enemy_damage;
            }
            else
            {
                // Normal enemy attack

                enemy_damage = enemy_atk + rand() % 30;

                printf("Enemy attacked you for %d enemy_damage!\n", enemy_damage);

                player_hp -= enemy_damage;
            }
        }

        // Player is dead

        if (player_hp <= 0)
        {
            printf("\n=================================\n");
            printf("          YOU DIED!\n");
            printf("=================================\n");

            game_over = 1;
        }
    }

    // ---------------- END ----------------

    printf("\n=================================\n");
    printf("             GAME OVER\n");
    printf("=================================\n");

    printf("Final Level: %d\n", player_level);
    printf("Final XP: %d\n", xp);

    return 0;
}
