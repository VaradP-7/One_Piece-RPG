#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "elite_bosses.h"
#include "devil_fruits.h"

void enemy_generation(int *enemy_hp, int *enemy_max_hp, int *enemy_atk, int *player_level)
{
    *enemy_max_hp = 150 + rand() % 51 + (*player_level * 50); // 150 - 200
    *enemy_hp = *enemy_max_hp;
    *enemy_atk = 20 + rand() % 11 + (*player_level * 10); // 20 - 30
}

struct Player_Moveset
{
    char *move_name;
    char move_atk;
};

// MAIN FUNCTION
int main()
{
    srand(time(0));

    // PLAYER
    int player_faction;
    int player_hp;
    int max_hp;
    int player_atk;

    // DEVIL FRUIT
    int df_atk;
    int df_hp;

    // PROGRESSION
    int player_level = 1;
    int xp = 0;

    // ENEMY
    int enemy_hp;
    int enemy_atk;
    int enemy_max_hp;
    int enemy_damage;
    int enemy_level;

    // ELITE BOSS

    // ATTACK
    int choice;
    int atk_choice;
    int player_damage;

    int bounty;

    printf("Choose your faction: \n");
    printf("1. Pirate \n");
    printf("2. Marine \n");
    printf("Enter choice: ");
    scanf("%d", &player_faction);

    if (player_faction == 1)
    {
        player_atk = 50;
        max_hp = 200;
        printf("You chose to become a Pirate! \n");
    }
    else if (player_faction == 2)
    {
        player_atk = 30;
        max_hp = 250;
        printf("You chose to become a Marine! \n");
    }
    else
    {
        printf("Invalid choice. You are a Pirate.\n");
        max_hp = 100;
        player_atk = 100;
        player_faction = 1;
    }
    player_hp = max_hp;

    // DEVIL FRUIT

    int random_fruit = rand() % 10;

    printf("\n=================================\n");
    printf("YOU GOT A DEVIL FRUIT!\n");
    printf("=================================\n");

    printf("Name: %s\n", fruits[random_fruit].df_name);
    printf("Type: %s\n", fruits[random_fruit].df_type);
    printf("Attack: %d\n", fruits[random_fruit].df_atk);
    printf("HP: %d\n", fruits[random_fruit].df_hp);

    fruits[random_fruit].df_atk += (player_level * 2);
    fruits[random_fruit].df_hp += (player_level * 5);

    player_atk += fruits[random_fruit].df_atk;
    player_hp += fruits[random_fruit].df_hp;
    player_hp = max_hp;

    player_atk += 1000; // testing

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
            enemy_generation(&enemy_hp, &enemy_max_hp, &enemy_atk, &player_level);

            if (player_faction == 1)
            {
                int decision;
                decision = rand() % 2 + 1;
                if (decision == 1)
                {
                    printf("\n=================================\n");
                    printf("A NEW PIRATE HAS APPEARED!\n");
                    printf("Enemy HP: %d Enemy ATK: %d\n", enemy_hp, enemy_atk);
                    printf("=================================\n");
                }
                else if (decision == 2)
                {
                    printf("\n=================================\n");
                    printf("A NEW MARINE HAS APPEARED!\n");
                    printf("Enemy HP: %d Enemy ATK: %d\n", enemy_hp, enemy_atk);
                    printf("=================================\n");
                }
            }
            else if (player_faction == 2)
            {
                printf("=================================\n");
                printf("A NEW PIRATE HAS APPEARED!\n");
                printf("Enemy HP: %d Enemy ATK: %d\n", enemy_hp, enemy_atk);
                printf("=================================\n");
            }
        }

        // BATTLE LOOP
        while (player_hp > 0 && enemy_hp > 0)
        {
            printf("\n---------------------------------\n");
            printf("Level: %d\n", player_level);
            printf("Your HP: %d/%d Your ATK: %d\n", player_hp, max_hp, player_atk);
            printf("Enemy HP: %d/%d Enemy ATK: %d\n", enemy_hp, enemy_max_hp, enemy_atk);
            printf("---------------------------------\n");

            printf("1. Attack\n");
            printf("2. Dodge\n");
            printf("3. Parry\n");
            printf("4. Run\n");
            printf("Choose: ");
            scanf("%d", &choice);

            // ATTACK
            if (choice == 1)
            {
                player_damage = player_atk + rand() % 11;

                // Critical hit
                if (rand() % 5 == 0)
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
            }

            // DODGE
            if (choice == 2)
            {
            }

            // PARRY
            if (choice == 3)
            {
            }

            // RUN
            else if (choice == 4)
            {
                printf("\nYou ran away!\n");
                game_over = 1;
                break;
            }

            else
            {
                printf("Invalid choice!\n");
                continue;
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
                    printf("\nYou gained 500 XP!\n");
                    printf("Current XP: %d\n", xp);
                }
                else
                {
                    printf("\nYOU DEFEATED THE ENEMY!!\n");
                    xp += 50;

                    printf("You gained 50 XP!\n");
                    printf("Current XP: %d\n", xp);
                }

                // player_level up

                if (xp >= player_level * 100)
                {
                    player_level++;

                    max_hp += 50;
                    player_atk += 20;

                    player_hp = max_hp;

                    printf("\n*** player_level UP! ***\n");
                    printf("You are now player_level %d!\n", player_level);
                    printf("Max HP increased!\n");
                    printf("Attack increased!\n");
                }

                break;
            }

            // ---------------- ENEMY ATTACK ----------------

            enemy_damage = enemy_atk + rand() % 6;

            player_hp -= enemy_damage;

            if (player_hp < 0)
            {
                player_hp = 0;
            }

            printf("Enemy attacked you for %d damage!\n", enemy_damage);

            // Player is dead

            if (player_hp <= 0)
            {
                printf("\n=================================\n");
                printf("          YOU DIED!\n");
                printf("=================================\n");

                game_over = 1;
            }
        }
    }

    // ---------------- END ----------------

    printf("\n=================================\n");
    printf("             GAME OVER\n");
    printf("=================================\n");

    printf("Final player_level: %d\n", player_level);
    printf("Final XP: %d\n", xp);

    return 0;
}
