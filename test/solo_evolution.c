#include "global.h"
#include "pokemon.h"
#include "starter_choose.h"
#include "test/test.h"

// Regression checks for the family's solo evolution policy.
TEST("Solo evolution: trade-only replacements require level 40")
{
    struct Pokemon mon;
    enum Species species = SPECIES_NONE, target = SPECIES_NONE;
    u32 level = 0;
    PARAMETRIZE { species = SPECIES_KADABRA; target = SPECIES_ALAKAZAM; level = 39; }
    PARAMETRIZE { species = SPECIES_KADABRA; target = SPECIES_ALAKAZAM; level = 40; }
    PARAMETRIZE { species = SPECIES_KADABRA; target = SPECIES_ALAKAZAM; level = 41; }
    PARAMETRIZE { species = SPECIES_MACHOKE; target = SPECIES_MACHAMP; level = 39; }
    PARAMETRIZE { species = SPECIES_MACHOKE; target = SPECIES_MACHAMP; level = 40; }
    PARAMETRIZE { species = SPECIES_MACHOKE; target = SPECIES_MACHAMP; level = 41; }
    PARAMETRIZE { species = SPECIES_GRAVELER; target = SPECIES_GOLEM; level = 39; }
    PARAMETRIZE { species = SPECIES_GRAVELER; target = SPECIES_GOLEM; level = 40; }
    PARAMETRIZE { species = SPECIES_GRAVELER; target = SPECIES_GOLEM; level = 41; }
    PARAMETRIZE { species = SPECIES_GRAVELER_ALOLA; target = SPECIES_GOLEM_ALOLA; level = 39; }
    PARAMETRIZE { species = SPECIES_GRAVELER_ALOLA; target = SPECIES_GOLEM_ALOLA; level = 40; }
    PARAMETRIZE { species = SPECIES_GRAVELER_ALOLA; target = SPECIES_GOLEM_ALOLA; level = 41; }
    PARAMETRIZE { species = SPECIES_HAUNTER; target = SPECIES_GENGAR; level = 39; }
    PARAMETRIZE { species = SPECIES_HAUNTER; target = SPECIES_GENGAR; level = 40; }
    PARAMETRIZE { species = SPECIES_HAUNTER; target = SPECIES_GENGAR; level = 41; }
    PARAMETRIZE { species = SPECIES_BOLDORE; target = SPECIES_GIGALITH; level = 39; }
    PARAMETRIZE { species = SPECIES_BOLDORE; target = SPECIES_GIGALITH; level = 40; }
    PARAMETRIZE { species = SPECIES_BOLDORE; target = SPECIES_GIGALITH; level = 41; }
    PARAMETRIZE { species = SPECIES_GURDURR; target = SPECIES_CONKELDURR; level = 39; }
    PARAMETRIZE { species = SPECIES_GURDURR; target = SPECIES_CONKELDURR; level = 40; }
    PARAMETRIZE { species = SPECIES_GURDURR; target = SPECIES_CONKELDURR; level = 41; }
    PARAMETRIZE { species = SPECIES_KARRABLAST; target = SPECIES_ESCAVALIER; level = 39; }
    PARAMETRIZE { species = SPECIES_KARRABLAST; target = SPECIES_ESCAVALIER; level = 40; }
    PARAMETRIZE { species = SPECIES_KARRABLAST; target = SPECIES_ESCAVALIER; level = 41; }
    PARAMETRIZE { species = SPECIES_SHELMET; target = SPECIES_ACCELGOR; level = 39; }
    PARAMETRIZE { species = SPECIES_SHELMET; target = SPECIES_ACCELGOR; level = 40; }
    PARAMETRIZE { species = SPECIES_SHELMET; target = SPECIES_ACCELGOR; level = 41; }
    PARAMETRIZE { species = SPECIES_PHANTUMP; target = SPECIES_TREVENANT; level = 39; }
    PARAMETRIZE { species = SPECIES_PHANTUMP; target = SPECIES_TREVENANT; level = 40; }
    PARAMETRIZE { species = SPECIES_PHANTUMP; target = SPECIES_TREVENANT; level = 41; }
    PARAMETRIZE { species = SPECIES_PUMPKABOO_AVERAGE; target = SPECIES_GOURGEIST_AVERAGE; level = 39; }
    PARAMETRIZE { species = SPECIES_PUMPKABOO_AVERAGE; target = SPECIES_GOURGEIST_AVERAGE; level = 40; }
    PARAMETRIZE { species = SPECIES_PUMPKABOO_AVERAGE; target = SPECIES_GOURGEIST_AVERAGE; level = 41; }
    PARAMETRIZE { species = SPECIES_PUMPKABOO_SMALL; target = SPECIES_GOURGEIST_SMALL; level = 39; }
    PARAMETRIZE { species = SPECIES_PUMPKABOO_SMALL; target = SPECIES_GOURGEIST_SMALL; level = 40; }
    PARAMETRIZE { species = SPECIES_PUMPKABOO_SMALL; target = SPECIES_GOURGEIST_SMALL; level = 41; }
    PARAMETRIZE { species = SPECIES_PUMPKABOO_LARGE; target = SPECIES_GOURGEIST_LARGE; level = 39; }
    PARAMETRIZE { species = SPECIES_PUMPKABOO_LARGE; target = SPECIES_GOURGEIST_LARGE; level = 40; }
    PARAMETRIZE { species = SPECIES_PUMPKABOO_LARGE; target = SPECIES_GOURGEIST_LARGE; level = 41; }
    PARAMETRIZE { species = SPECIES_PUMPKABOO_SUPER; target = SPECIES_GOURGEIST_SUPER; level = 39; }
    PARAMETRIZE { species = SPECIES_PUMPKABOO_SUPER; target = SPECIES_GOURGEIST_SUPER; level = 40; }
    PARAMETRIZE { species = SPECIES_PUMPKABOO_SUPER; target = SPECIES_GOURGEIST_SUPER; level = 41; }
    CreateMon(&mon, species, level, 0, OTID_STRUCT_PLAYER_ID);
    EXPECT_EQ(GetEvolutionTargetSpecies(&mon, EVO_MODE_NORMAL, ITEM_NONE, NULL, NULL, CHECK_EVO), level < 40 ? SPECIES_NONE : target);
}

TEST("Solo evolution: held-item replacements require and consume the correct item")
{
    struct Pokemon mon;
    enum Species species = SPECIES_NONE, target = SPECIES_NONE;
    enum Item item = ITEM_NONE, wrongItem = ITEM_POTION;
    PARAMETRIZE { species = SPECIES_POLIWHIRL; target = SPECIES_POLITOED; item = ITEM_KINGS_ROCK; }
    PARAMETRIZE { species = SPECIES_SLOWPOKE; target = SPECIES_SLOWKING; item = ITEM_KINGS_ROCK; }
    PARAMETRIZE { species = SPECIES_ONIX; target = SPECIES_STEELIX; item = ITEM_METAL_COAT; }
    PARAMETRIZE { species = SPECIES_RHYDON; target = SPECIES_RHYPERIOR; item = ITEM_PROTECTOR; }
    PARAMETRIZE { species = SPECIES_SEADRA; target = SPECIES_KINGDRA; item = ITEM_DRAGON_SCALE; }
    PARAMETRIZE { species = SPECIES_SCYTHER; target = SPECIES_SCIZOR; item = ITEM_METAL_COAT; }
    PARAMETRIZE { species = SPECIES_ELECTABUZZ; target = SPECIES_ELECTIVIRE; item = ITEM_ELECTIRIZER; }
    PARAMETRIZE { species = SPECIES_MAGMAR; target = SPECIES_MAGMORTAR; item = ITEM_MAGMARIZER; }
    PARAMETRIZE { species = SPECIES_PORYGON; target = SPECIES_PORYGON2; item = ITEM_UPGRADE; }
    PARAMETRIZE { species = SPECIES_PORYGON2; target = SPECIES_PORYGON_Z; item = ITEM_DUBIOUS_DISC; }
    PARAMETRIZE { species = SPECIES_FEEBAS; target = SPECIES_MILOTIC; item = ITEM_PRISM_SCALE; }
    PARAMETRIZE { species = SPECIES_DUSCLOPS; target = SPECIES_DUSKNOIR; item = ITEM_REAPER_CLOTH; }
    PARAMETRIZE { species = SPECIES_CLAMPERL; target = SPECIES_HUNTAIL; item = ITEM_DEEP_SEA_TOOTH; }
    PARAMETRIZE { species = SPECIES_CLAMPERL; target = SPECIES_GOREBYSS; item = ITEM_DEEP_SEA_SCALE; }
    PARAMETRIZE { species = SPECIES_SPRITZEE; target = SPECIES_AROMATISSE; item = ITEM_SACHET; }
    PARAMETRIZE { species = SPECIES_SWIRLIX; target = SPECIES_SLURPUFF; item = ITEM_WHIPPED_DREAM; }
    CreateMon(&mon, species, 40, 0, OTID_STRUCT_PLAYER_ID);
    EXPECT_EQ(GetEvolutionTargetSpecies(&mon, EVO_MODE_NORMAL, ITEM_NONE, NULL, NULL, CHECK_EVO), species == SPECIES_SLOWPOKE ? SPECIES_SLOWBRO : SPECIES_NONE);
    SetMonData(&mon, MON_DATA_HELD_ITEM, &wrongItem);
    EXPECT_EQ(GetEvolutionTargetSpecies(&mon, EVO_MODE_NORMAL, ITEM_NONE, NULL, NULL, CHECK_EVO), species == SPECIES_SLOWPOKE ? SPECIES_SLOWBRO : SPECIES_NONE);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_HELD_ITEM), wrongItem);
    SetMonData(&mon, MON_DATA_HELD_ITEM, &item);
    EXPECT_EQ(GetEvolutionTargetSpecies(&mon, EVO_MODE_NORMAL, ITEM_NONE, NULL, NULL, CHECK_EVO), target);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_HELD_ITEM), item);
    EXPECT_EQ(GetEvolutionTargetSpecies(&mon, EVO_MODE_NORMAL, ITEM_NONE, NULL, NULL, DO_EVO), target);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_HELD_ITEM), ITEM_NONE);
}

TEST("Solo evolution: Ghost starters retain first evolution thresholds")
{
    struct Pokemon mon;
    enum Species species = SPECIES_NONE, target = SPECIES_NONE;
    u32 level = 0;
    PARAMETRIZE { species = SPECIES_GASTLY; target = SPECIES_HAUNTER; level = 25; }
    PARAMETRIZE { species = SPECIES_DUSKULL; target = SPECIES_DUSCLOPS; level = 37; }
    PARAMETRIZE { species = SPECIES_LITWICK; target = SPECIES_LAMPENT; level = 41; }
    CreateMon(&mon, species, level - 1, 0, OTID_STRUCT_PLAYER_ID);
    EXPECT_EQ(GetEvolutionTargetSpecies(&mon, EVO_MODE_NORMAL, ITEM_NONE, NULL, NULL, CHECK_EVO), SPECIES_NONE);
    CreateMon(&mon, species, level, 0, OTID_STRUCT_PLAYER_ID);
    EXPECT_EQ(GetEvolutionTargetSpecies(&mon, EVO_MODE_NORMAL, ITEM_NONE, NULL, NULL, CHECK_EVO), target);
}

TEST("Solo evolution: Lampent still requires a Dusk Stone")
{
    struct Pokemon mon;
    CreateMon(&mon, SPECIES_LAMPENT, 55, 0, OTID_STRUCT_PLAYER_ID);
    EXPECT_EQ(GetEvolutionTargetSpecies(&mon, EVO_MODE_NORMAL, ITEM_NONE, NULL, NULL, CHECK_EVO), SPECIES_NONE);
    EXPECT_EQ(GetEvolutionTargetSpecies(&mon, EVO_MODE_ITEM_CHECK, ITEM_FIRE_STONE, NULL, NULL, CHECK_EVO), SPECIES_NONE);
    EXPECT_EQ(GetEvolutionTargetSpecies(&mon, EVO_MODE_ITEM_CHECK, ITEM_DUSK_STONE, NULL, NULL, CHECK_EVO), SPECIES_CHANDELURE);
}

TEST("Solo evolution: Emerald starter choices are the Ghost trio")
{
    EXPECT_EQ(GetStarterPokemon(0), SPECIES_GASTLY);
    EXPECT_EQ(GetStarterPokemon(1), SPECIES_DUSKULL);
    EXPECT_EQ(GetStarterPokemon(2), SPECIES_LITWICK);
}

TEST("Solo evolution: level-5 starters have coverage against Normal types")
{
    struct Pokemon mon;
    enum Species species = SPECIES_NONE;
    enum Move move = MOVE_NONE;
    bool32 found = FALSE;
    PARAMETRIZE { species = SPECIES_GASTLY; move = MOVE_SMOG; }
    PARAMETRIZE { species = SPECIES_DUSKULL; move = MOVE_PURSUIT; }
    PARAMETRIZE { species = SPECIES_LITWICK; move = MOVE_EMBER; }
    CreateMon(&mon, species, 5, 0, OTID_STRUCT_PLAYER_ID);
    GiveMonInitialMoveset(&mon);
    for (u32 i = 0; i < MAX_MON_MOVES; i++)
        if (GetMonData(&mon, MON_DATA_MOVE1 + i) == move)
            found = TRUE;
    EXPECT(found);
}

TEST("Solo evolution: no species data still requires a trade")
{
    for (enum Species species = SPECIES_NONE; species < NUM_SPECIES; species++)
    {
        const struct Evolution *evolutions;
        if (!IsSpeciesEnabled(species))
            continue;
        evolutions = GetSpeciesEvolutions(species);
        if (evolutions == NULL)
            continue;
        for (u32 i = 0; evolutions[i].method != EVOLUTIONS_END; i++)
            EXPECT_NE(evolutions[i].method, EVO_TRADE);
    }
}
