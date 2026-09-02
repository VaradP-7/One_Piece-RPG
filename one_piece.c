#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void enemy_generation(int *enemy_hp, int *enemy_max_hp, int *enemy_atk, int *level)
{
    *enemy_max_hp = 150 + rand() % 51 + (*level * 50); // 150 - 200
    *enemy_hp = *enemy_max_hp;
    *enemy_atk = 20 + rand() % 11 + (*level * 10); // 20 - 30
}

// DF FUNCTIONS

struct Devil_Fruit
{
    char *df_name;
    char *df_type;
    int df_atk;
    int df_hp;
};

struct Player_Moveset
{
    char *move_name;
    char move_atk;
};

struct Boss_Moveset
{
    char *move_name;
    int move_atk;
};

struct Elite_Bosses
{
    char *elite_boss_name;

    int spawn_level;
    int elite_boss_atk;
    int elite_boss_hp;

    int defeated;

    struct Boss_Moveset moves[3];
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
    int level = 1;
    int xp = 0;

    // ENEMY
    int enemy_hp;
    int enemy_atk;
    int enemy_max_hp;
    int enemy_damage;

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

    struct Devil_Fruit fruits[10] =
        {
            {"Magma-Magma",
             "Highly Offensive",
             100,
             20},

            {"Flame-Flame",
             "Offensive",
             80,
             30},

            {"Ice-Ice",
             "Balanced",
             60,
             60},

            {"Gum-Gum",
             "Extremely Balanced",
             100,
             100},

            {"Dark-Dark",
             "Highly Offensive",
             100,
             100},

            {"Glint-Glint",
             "Highly Offensive",
             100,
             100},

            {"Rumble-Rumble",
             "Highly Offensive",
             100,
             100},

            {"Sand-Sand",
             "Offensive",
             100,
             100},

            {"Bird-Bird Fruit, Model: Phoenix",
             "Extremely Defensive",
             100,
             100},

            {"Fish-Fish Fruit, Model: Azure Dragon",
             "Balanced",
             100,
             100}

        };

    int random_fruit = rand() % 10;

    printf("\n=================================\n");
    printf("YOU GOT A DEVIL FRUIT!\n");
    printf("=================================\n");

    printf("Name: %s\n", fruits[random_fruit].df_name);
    printf("Type: %s\n", fruits[random_fruit].df_type);
    printf("Attack: %d\n", fruits[random_fruit].df_atk);
    printf("HP: %d\n", fruits[random_fruit].df_hp);

    player_atk += fruits[random_fruit].df_atk;
    player_hp += fruits[random_fruit].df_hp;
    player_hp = max_hp;

    player_atk += 1000; // testing

    // ELITE BOSSES

    struct Elite_Bosses bosses[30] =
        {
            {"Crocodile",
             10,
             200,
             1000,
             0,
             {
                 {},
                 {},
                 {},
             }},

            {"Enel",
             20,
             500,
             2000,
             0,
             {
                 {},
                 {},
                 {},
             }},

            {"Rob Lucci",
             30,
             1000,
             3000,
             0,
             {
                 {},
                 {},
                 {},
             }},

            {"Gecko Moria",
             35,
             1500,
             4000,
             0,
             {
                 {},
                 {},
                 {},
             }},

            {"Kizaru: Sabaody",
             40,
             1500,
             4500,
             0,

             {
                 {},
                 {},
                 {},
             }},

            {"Megellan",
             45,
             1600,
             5000,
             0,
             {
                 {},
                 {},
                 {},
             }},

            {"Kizaru: MarineFord",
             50,
             1800,
             5500,
             0,
             {
                 {},
                 {},
                 {},
             }},

            {"Kuzan",
             55,
             2000,
             6000,
             0,
             {
                 {},
                 {},
                 {},
             }},

            {"Akainu",
             60,
             3000,
             4000,
             0,
             {
                 {},
                 {},
                 {},
             }},

            {"Donquixote Doflamingo",
             65,
             2200,
             7000,
             0,
             {
                 {},
                 {},
                 {},
             }},

            {"Big Mom: Whole Cake Island",
             70,
             2400,
             7500,
             0,
             {
                 {},
                 {},
                 {},
             }},

            {"Kaido",
             80,
             2500,
             8000,
             0,
             {
                 {},
                 {},
                 {},
             }},

            {"Big Mom: Wano",
             85,
             2600,
             12000,
             0,
             {
                 {},
                 {},
                 {},
             }},
            {"Kaido: Hybrid",
             88,
             2700,
             10000,
             0,
             {
                 {},
                 {},
                 {},
             }},

            {"Kaido: Dragon",
             90,
             3200,
             7000,
             0,
             {
                 {},
                 {},
                 {},
             }},

            {"Kizaru: Egghead",
             95,
             2800,
             7500,
             0,
             {
                 {},
                 {},
                 {},
             }},

            {"Saint Jaygarcia Saturn",
             100,
             3000,
             16000,
             0,
             {
                 {},
                 {},
                 {},
             }},

            {"Saint Marcus Mars",
             105,
             3100,
             12000,
             0,
             {
                 {},
                 {},
                 {},
             }},

            {"Saint Topman Warcury",
             110,
             3100,
             14000,
             0,
             {
                 {},
                 {},
                 {},
             }},

            {"Saint Ethanbaron V. Nusjuro",
             115,
             3600,
             11000,
             0,
             {
                 {},
                 {},
                 {},
             }},

            {"Saint Shepherd Ju Peter",
             120,
             3000,
             13000,
             0,
             {
                 {},
                 {},
                 {},
             }},

            {"Saint Gunko",
             125,
             2800,
             9500,
             0,
             {
                 {},
                 {},
                 {},
             }},

            {"Saint Gunko: Imu",
             130,
             4200,
             16000,
             0,
             {
                 {},
                 {},
                 {},
             }},

            {"Saint Shepherd Sommers",
             135,
             3400,
             13500,
             0,
             {
                 {},
                 {},
                 {},
             }},

            {"Saint Rimoshifu Killingham",
             138,
             3300,
             13000,
             0,
             {
                 {},
                 {},
                 {},
             }},

            {"Imu: King of the World",
             150,
             50000,
             1000000,
             0,
             {
                 {},
                 {},
                 {},
             }},

        };

    // GAMEPLAY LOOP

    int game_over = 0;

    while (game_over == 0)
    {
        // BOSS FIGHT
        int boss_fight = 0;
        int boss_index = -1;
        int n = 26; // n = Number of Bosses

        for (int i = 0; i < n; i++)
        {
            if (level == bosses[i].spawn_level && bosses[i].defeated == 0)
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
            enemy_generation(&enemy_hp, &enemy_max_hp, &enemy_atk, &level);

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
            printf("Level: %d\n", level);
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

            // PARRY

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

                    xp += 500;
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

                // Level up

                if (xp >= level * 100)
                {
                    level++;

                    max_hp += 50;
                    player_atk += 20;

                    player_hp = max_hp;

                    printf("\n*** LEVEL UP! ***\n");
                    printf("You are now Level %d!\n", level);
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

    printf("Final Level: %d\n", level);
    printf("Final XP: %d\n", xp);

    return 0;
}
