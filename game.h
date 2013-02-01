char iobuff[10];
int computer_score,player_score;


int ships_left()
{
  int ships=0;

  for(x=0;x<10;x++)
  {
    for(y=0;y<10;y++)
    {
      if(map[x][y]>0)
       ships++;
    }
  }
 return ships;
}

int win() //17 hits to win
{
  int hits=0;
  int out=0;

  for(x=0;x<10;x++)
  {
    for(y=0;y<10;y++)
    {
      if(hit_map[x][y]==1)
         hits++;
    }
  }
 
  if(hits>=17)
      out=1;
  
  return out;
}

int hit_scan(int id)
{
  int ships_left=0;
  for(x=0;x<10;x++)
  {
    for(y=0;y<10;y++)
    {
      if(map[x][y]==id)
         ships_left++;
    }
  }
 return ships_left;
}

char *getship(int shipid)
{
  return NULL; 
}

int confirm_hit(int x,int y)
{
  int shiphit=0;
  if(map[x][y]>0)
  {
    shiphit=map[x][y];
  }
 return shiphit;
}

void gethit()
{
  posX=0;
  posY=0;

  printf("x>");
  scanf("%i",&posX);
  printf("y>");
  scanf("%i",&posY);

  printf("%s","bullet fired ");
  if(confirm_hit(posX,posY)>0)
  {
      printf("%s\n","hit!");
      player_score++;
      map[posX][posY]=-1;
  }
  else
      printf("%s\n","miss!"); 

  
}

//hitmap values -1 is miss 1 is hit 0 is neather
void shoot() //defult tatics
{  
  posX=("%d\n",(rand()%10)+1);
  posY=("%d\n",(rand()%10)+1);
  printf("shooting at: %d,%d\n",posX,posY);
  printf("%s","y/n hit? >");
  scanf("%s",&iobuff);

  if(iobuff[0]=='y')
  {
    printf("%s\n","hit confirmed");
    hit_map[posX][posY]=1;
    computer_score++;
  }
  else if(iobuff[0]=='n')
  {
    printf("%s\n","miss confirmed");
    hit_map[posX][posY]=-1;
  }
  else
    printf("%s\n","unknown answer");
  
}


int ships_left();
int win();
int hit_scan(int id);
//finish prototypeing
