#include "utils.h"
#include "stdlib.h"

void* (* Abilities[4])(void* x) = {RotateMatrix, DecodeString, InvertArray, KillPlayer};

char *fromEnumtoString(PlayerRoles playerRole)
{
	char *str = calloc(MAX_LEN_STR_ATR, sizeof(char));
	if(!str) {
		return NULL;
	}
	switch(playerRole)
	{
		case Rotator:
			str = strcpy(str, "Rotator");
			break;
		case Decoder:
			str = strcpy(str, "Decoder");
			break;
		case Invertor:
			str = strcpy(str, "Invertor");
			break;
		case Impostor:
			str = strcpy(str, "Impostor");
			break;
	}
	return str;
}

// Task 1
void *RotateMatrix(void *input)
{
	int n = *(int *)input;
    int i, j, length = 0;

    int digits = 1, copy = n;
    while(copy > 9){
        digits++;
        copy /= 10;
    }

    char *string = (char *)malloc(n * n * (digits * 2 + 1));
    if(!string) {
    	return NULL;
    }

    for(i = 1; i <= n; i++){
        for(j = n; j >= 2; j--)
            length += sprintf(string + length, "%d%d ", j, i);
        length += sprintf(string + length, "%d%d\n", j, i);
    }

    string[strlen(string) - 1] = 0;
	return (void*)string;
}

// Task 2
void *DecodeString(void *input)
{
    char *cpy_str = (char *)malloc(strlen((char*)input));
    if(!cpy_str) {
    	return NULL;
    }
    strcpy(cpy_str, (char *)input);
    char *last = (char *)cpy_str, *curr;
    int sum = 0;

    while(curr != NULL){
        curr = strchr(last, '_');
        if(curr)
            *curr = 0;
        sum += atoi(last);
        if(curr)
            last = curr + 1;
    }

    int digits = 1, cpy = sum;

    while(cpy > 9){
        digits++;
        cpy /= 10;
    }

    char *string = (char *)malloc(digits + 1);
    if(!string) {
    	free(cpy_str);
    	return NULL;
    }

    sprintf(string, "%d", sum);

    free(cpy_str);
	return (void*)string;
}

//Task 3
void *InvertArray(void *input)
{
	int *arr = (int *)input;
    int num = arr[0];
    int i, max = 0;

    if(num%2 == 0){
        for(i = 1; i < num; i += 2){
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;

            if(temp > max)
               max = temp;
        } 
    }
    else{
        for(i = 1; i <= num/2; i++){
            int temp = arr[num - i + 1];
            arr[num - i + 1] = arr[i];
            arr[i] = temp;
           
            if(temp > max)
               max = temp;
        }
    }

    int digits = 1;
    while(max > 9){
        digits++;
        max /= 10;
    }

    char *string = (char *)malloc(num * digits + num); // num elem*cifre + space
    if(!string) {
    	return NULL;
    }
    int length = 0;

    for(i = 1; i < num; i++)
        length += sprintf(string + length, "%d ", arr[i]);
    sprintf(string + length, "%d", arr[num]);
	
    return (void *)string;
}

//Task 4
Player *allocPlayer()
{
	Player *player = (Player *)malloc(sizeof(Player));
	if(!player) {
		return NULL;
	}
    player->name = (char *)malloc(MAX_LEN_STR_ATR);
    if(!player->name) {
    	free(player);
    	return NULL;
    }
    player->color = (char *)malloc(MAX_LEN_STR_ATR);
    if(!player->color) {
		free(player->name);
		free(player);
		return NULL;
	}
    player->hat = (char *)malloc(MAX_LEN_STR_ATR);
    if(!player->hat) {
		free(player->color);
		free(player->name);
		free(player);
		return NULL;
	}
    player->alive = 1;
	return player;
}

//Task 4
Game *allocGame()
{
	Game *game = (Game *)malloc(sizeof(Game));
	if(!game) {
		return NULL;
	}
    game->name = (char *)malloc(MAX_LEN_STR_ATR);
    if(!game->name) {
    	free(game);
    	return NULL;
    }
	return game;
}

//Task 5
Player *ReadPlayer(FILE *inputFile)
{
	// TODO
	return NULL;
}

// Task 5
Game *ReadGame(FILE *inputFile)
{
	// TODO
	return NULL;
}

// Task 6
void WritePlayer(Player *player, FILE *outputFile)
{
	// TODO
	return;
}

// Task 6
void WriteGame(Game *game, FILE *outputFile)
{
	// TODO
	return;
}

//Task 7
void *KillPlayer(void *input)
{
	// TODO
	return NULL;
}

// Task 8
void CalcuateNextCycleOfGame(Game *game, FILE *outputFile, void **inputMatrix)
{
	// TODO
	return;
}

// Task 9
void FreePlayer(Player *player)
{
	// TODO
	return;
}

// Task 9
void FreeGame(Game *game)
{
	// TODO
	return;
}