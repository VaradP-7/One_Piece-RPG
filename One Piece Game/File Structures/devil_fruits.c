#include "devil_fruits.h"

struct Devil_Fruit fruits[] =
    {
        {"Magma-Magma",
         "Highly Offensive",
         100,
         20,
         {{"Dai Funka", 2.0, 10},
          {"Inumaki Guren", 2.5, 5},
          {"Meigō", 2.7, 5},
          {"Ryūsei Kazan", 3.0, 0}}},

        {"Flame-Flame",
         "Offensive",
         80,
         30,
         {{"Higan", 1.5, 15},
          {"Hiken", 2.0, 10},
          {"Enkai: Hibashira", 2.2, 5},
          {"Higan", 2.75, 0}}},

        {"Ice-Ice",
         "Balanced",
         60,
         60,
         {{"Ice Saber", 2.0, 10},
          {"Ice Ball", 2.0, 10},
          {"Ice Time", 2.0, 10},
          {"Ice Age", 2.0, 0}}},

        {"Gum-Gum",
         "Extremely Balanced",
         100,
         100,
         {
             {"Gomu Gomu no Pistol", 2.0, 10},
             {"Gomu Gomu no Bazooka", 2.0, 10},
             {"Gomu Gomu no Gatling", 2.0, 10},
             {"Gomu Gomu no Red Roc", 2.0, 0},
         }},

        {"Dark-Dark",
         "Highly Offensive",
         100,
         100,
         {
             {"Kurouzu", 2.0, 10},
             {"Liberation", 2.0, 10},
             {"Darkness", 2.0, 10},
             {"Black Hole", 2.0, 0},
         }},

        {"Glint-Glint",
         "Highly Offensive",
         100,
         100,
         {
             {"Ama no Murakumo", 2.0, 10},
             {"Kusanagi", 2.0, 10},
             {"Yata no Kagami", 2.0, 10},
             {"Yasakani no Magatama", 2.0, 0},
         }},

        {"Rumble-Rumble",
         "Highly Offensive",
         100,
         100,
         {
             {"El Thor", 2.0, 10},
             {"Sango", 2.0, 10},
             {"Kiten", 2.0, 10},
             {"Raigō", 2.0, 0},
         }},

        {"Sand-Sand",
         "Offensive",
         100,
         100,
         {
             {"Desert Spada", 2.0, 10},
             {"Ground Secco", 2.0, 10},
             {"Desert Girasole", 2.0, 10},
             {"Sables", 2.0, 0},
         }},

        {"Bird-Bird Fruit, Model: Phoenix",
         "Extremely Defensive",
         100,
         100,
         {
             {"Phoenix Brand", 2.0, 10},
             {"Bluebird", 2.0, 10},
             {"Phoenix Flight", 2.0, 10},
             {"Flame Heal", 2.0, 0},
         }},

        {"Fish-Fish Fruit, Model: Azure Dragon",
         "Balanced",
         100,
         100,
         {
             {"Tatsumaki Kaifu", 2.0, 10},
             {"Raimei Hakke", 2.0, 10},
             {"Kaifu", 2.0, 10},
             {"Bolo Breath", 2.0, 0},
         }}};

int df_count = 10;