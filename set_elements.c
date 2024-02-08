/*
** EPITECH PROJECT, 2023
** set_elements.c
** File description:
** set_elements.c
*/

#include "include/my_hunt.h"

static void set_sound(sprites_stc *sprites, game_stc *stats)
{
    sfSoundBuffer *b1 = sfSoundBuffer_createFromFile("content/sound/fire.ogg");
    sfSoundBuffer *b2 = sfSoundBuffer_createFromFile("content/sound/dead.ogg");

    sprites->sm_music = sfMusic_createFromFile("content/sound/sm.ogg");
    sprites->g_music = sfMusic_createFromFile("content/sound/game.ogg");
    sprites->end_music = sfMusic_createFromFile("content/sound/end.ogg");
    sprites->dead_sound = sfSound_create();
    sprites->fire_sound = sfSound_create();
    sfSound_setBuffer(sprites->dead_sound, b2);
    sfSound_setBuffer(sprites->fire_sound, b1);
    sfMusic_setVolume(sprites->sm_music, 125);
    sfMusic_setVolume(sprites->g_music, 60);
    sfMusic_setVolume(sprites->end_music, 60);
    sfSound_setVolume(sprites->dead_sound, 75);
    sfSound_setVolume(sprites->fire_sound, 220);
    my_hunter(sprites, stats);
}

static void set_buttons(sprites_stc *sprites, game_stc *stats)
{
    SFVF rbtn_pos = {775, 550};
    SFVF btn_pos = {740, 400};
    SFVF rbtn_scale = {10, 10};
    SFVF btn_scale = {0.5, 0.5};
    char path[] = "content/startbtn.png";
    char path2[] = "content/ebtn.png";
    sfTexture *rb_texture = sfTexture_createFromFile(path2, NULL);
    sfTexture *sbtexture = sfTexture_createFromFile(path, NULL);

    sprites->rbutton = sfSprite_create();
    sprites->sbutton = sfSprite_create();
    sfSprite_setTexture(sprites->rbutton, rb_texture, sfTrue);
    sfSprite_setTexture(sprites->sbutton, sbtexture, sfTrue);
    sfSprite_setPosition(sprites->rbutton, rbtn_pos);
    sfSprite_setPosition(sprites->sbutton, btn_pos);
    sfSprite_setScale(sprites->rbutton, rbtn_scale);
    sfSprite_setScale(sprites->sbutton, btn_scale);
    set_sound(sprites, stats);
}

static void set_stats(sprites_stc *sprites)
{
    game_stc stats;

    stats.score = 0;
    stats.hp = 3;
    stats.anim = 0;
    stats.animb = 0;
    stats.game_pace = 10;
    stats.boss_hp = 100;
    stats.bossfigth = 0;
    stats.hightscore = 0;
    set_buttons(sprites, &stats);
}

static void set_text4(sprites_stc *sprites, sfFont *font)
{
    SFVF best_text_pos = {770, 450};

    sprites->best_txt = sfText_create();
    sfText_setFont(sprites->best_txt, font);
    sfText_setPosition(sprites->best_txt, best_text_pos);
    sfText_setFillColor(sprites->best_txt, sfWhite);
    sfText_setCharacterSize(sprites->best_txt, 75);
    sfText_setString(sprites->best_txt, "Best : ");
    set_stats(sprites);
}

static void set_text3(sprites_stc *sprites, sfFont *font)
{
    SFVF boss_text_pos = {610, 55};
    SFVF bscore_text_pos = {980, 450};

    sprites->boss_text = sfText_create();
    sfText_setFont(sprites->boss_text, font);
    sfText_setPosition(sprites->boss_text, boss_text_pos);
    sfText_setFillColor(sprites->boss_text, sfRed);
    sfText_setCharacterSize(sprites->boss_text, 150);
    sfText_setString(sprites->boss_text, "BOSSFIGHT");
    sprites->bscore_text = sfText_create();
    sfText_setFont(sprites->bscore_text, font);
    sfText_setPosition(sprites->bscore_text, bscore_text_pos);
    sfText_setFillColor(sprites->bscore_text, sfWhite);
    sfText_setCharacterSize(sprites->bscore_text, 75);
    set_text4(sprites, font);
}

static void set_text2(sprites_stc *sprites)
{
    SFVF end_score_pos = {835, 275};
    SFVF score_pos = {10, 10};
    sfFont *font = sfFont_createFromFile("content/fonts/alagard.ttf");

    sprites->end_score = sfText_create();
    sfText_setFont(sprites->end_score, font);
    sfText_setPosition(sprites->end_score, end_score_pos);
    sfText_setFillColor(sprites->end_score, sfBlack);
    sfText_setCharacterSize(sprites->end_score, 150);
    sprites->score_text = sfText_create();
    sfText_setFont(sprites->score_text, font);
    sfText_setPosition(sprites->score_text, score_pos);
    sfText_setFillColor(sprites->score_text, sfBlack);
    sfText_setCharacterSize(sprites->score_text, 50);
    set_text3(sprites, font);
}

void set_text(sprites_stc *sprites)
{
    SFVF text_pos = {625, 10};
    SFVF restart_pos = {840, 615};
    sfFont *font = sfFont_createFromFile("content/fonts/Crang.ttf");

    sprites->restart_txt = sfText_create();
    sfText_setFont(sprites->restart_txt, font);
    sfText_setPosition(sprites->restart_txt, restart_pos);
    sfText_setFillColor(sprites->restart_txt, sfBlack);
    sfText_setString(sprites->restart_txt, "Restart");
    sfText_setCharacterSize(sprites->restart_txt, 35);
    sprites->game_name = sfText_create();
    sfText_setFont(sprites->game_name, font);
    sfText_setPosition(sprites->game_name, text_pos);
    sfText_setFillColor(sprites->game_name, sfYellow);
    sfText_setString(sprites->game_name, "Dragon Hunter");
    sfText_setCharacterSize(sprites->game_name, 75);
    set_text2(sprites);
}

void set_elements2(sprites_stc *sprites)
{
    char path[] = "content/Hearts/animated/heart_2.png";
    SFVF eb_scale = {0.36, 0.36};
    SFVF guie_pos = {650, 225};
    sfTexture *b_texture = sfTexture_createFromFile("content/land.png", NULL);
    sfTexture *be_texture = sfTexture_createFromFile("content/end.jpg", NULL);
    sfTexture *h_texture = sfTexture_createFromFile(path, NULL);

    sfSprite_setPosition(sprites->guie, guie_pos);
    sprites->end_background = sfSprite_create();
    sprites->health = sfSprite_create();
    sprites->background = sfSprite_create();
    sfSprite_setTexture(sprites->end_background, be_texture, sfTrue);
    sfSprite_setTexture(sprites->health, h_texture, sfFalse);
    sfSprite_setTexture(sprites->background, b_texture, sfTrue);
    sfSprite_setScale(sprites->end_background, eb_scale);
    set_text(sprites);
}

void set_elements1(void)
{
    sprites_stc sprites;
    SFVF b_scale = {2, 2};
    SFVF guie_scale = {12, 12};
    char pathd[] = "content/dragon/191x161/red.png";
    char pathb[] = "content/dragon/boss.png";
    char pathgui[] = "content/guie.png";
    sfTexture *d_texture = sfTexture_createFromFile(pathd, NULL);
    sfTexture *boss_texture = sfTexture_createFromFile(pathb, NULL);
    sfTexture *gui_texture = sfTexture_createFromFile(pathgui, NULL);

    sprites.guie = sfSprite_create();
    sprites.dragon = sfSprite_create();
    sprites.boss = sfSprite_create();
    sfSprite_setTexture(sprites.dragon, d_texture, sfFalse);
    sfSprite_setTexture(sprites.boss, boss_texture, sfFalse);
    sfSprite_setTexture(sprites.guie, gui_texture, sfFalse);
    sfSprite_setScale(sprites.boss, b_scale);
    sfSprite_setScale(sprites.guie, guie_scale);
    set_elements2(&sprites);
}
