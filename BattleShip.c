/*
command line battle ship game

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ship.h"
#include "game.h"
#include "hunt_and_kill.h"

int main()
{
  printf("%s\n","BattleShip!");
  player_score=0;
  computer_score=0;
  srand(time(0));
  inut_hitmap();
  inut_map();
  inut_buffer(); 
  place_ships();
  
   while(1)
   {
     show_map();
     shoot();//defult shooting algerithm just shoots at random coordnets; really sucks as a player
     gethit();
     
     if(win()>1 || ships_left()<=0)
        break;
   }

   if(computer_score>player_score)
       printf("%s\n","computer wins");
   else if(computer_score<player_score)
       printf("%s\n","player wins");
   else if(computer_score==player_score)
       printf("%s\n","tie, howd that happen");  

}
