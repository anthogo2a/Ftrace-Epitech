/*
** EPITECH PROJECT, 2021
** linked
** File description:
** list
*/

#include "../include/include.h"

Liste *create_list()
{
    Liste *liste = malloc(sizeof(*liste));
    Sys *sys = malloc(sizeof(*sys));
    if (liste == NULL || sys == NULL)
        exit(84);
    sys->adr = 0;
    sys->name = NULL;
    sys->next = NULL;
    liste->premier = sys;
    return liste;
}

void create(Liste *liste, int addresse, char *name)
{
    Sys *new = malloc(sizeof(*new));
    if (new == NULL)
        exit(84);
    new->adr = addresse;
    new->name = name;
    new->next = NULL;
    Sys *actuel = liste->premier;
    while (actuel->next != NULL)
        actuel = actuel->next;
    actuel->next = new;
}

void DispListeAt(Liste *liste, int pos)
{
    int count = 0;
    Sys *actuel = liste->premier;
    while (actuel != NULL) {
        if (count == pos) {
            printf("0x%08lx ", actuel->adr);
            printf("%s\n", actuel->name);
        }
        count++;
        actuel = actuel->next;
    }
    printf("NULL\n");
}

void DispListe(Liste *liste)
{
    Sys *actuel = liste->premier;
    int count = 0;
    while (actuel != NULL) {
        if (count > 0) {
            printf("0x%08lx ", actuel->adr);
            printf("%s\n", actuel->name);
        }
        count++;
        actuel = actuel->next;
    }
    printf("NULL\n");
}

long unsigned int compListoStr(Liste *liste, const char *str)
{
    int count = 0;
    for (Sys *actuel = liste->premier; actuel != NULL; actuel = actuel->next) {
        if (count != 0) {
            // printf("%d ", actuel->adr);
            // printf("%s\n", actuel->name);
            if (strcmp(actuel->name, str) == 0) {
                return (actuel->adr);
            }
        }
        count++;
    }
    return 0;
}
