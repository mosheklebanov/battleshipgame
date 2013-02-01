int map[10][10],buffer[10][10],hit_map[10][10];
int x,y,posX,posY,i;

void inut_hitmap()
{
  for(x=0;x<10;x++)
  {
    for(y=0;y<10;y++)
    {
      hit_map[x][y]=0;
    }
  }
}

void show_map()
{
  for(y=0;y<10;y++)
  {
    for(x=0;x<10;x++)
     {
      if(map[x][y]>0 ||map[x][y]==-1)
      {
        printf("%i",map[x][y]);
      }
      else
      {
        printf(" ");
      }
    }
   printf("\n");
  }
}

void inut_map()
{
  for(x=0;x<10;x++)
  {
    for(y=0;y<10;y++)
    {
      map[x][y]=0;
    }
  }
}

void inut_buffer()
{
  for(x=0;x<10;x++)
  {
    for(y=0;y<10;y++)
    {
      buffer[x][y]=0;
    }
  }
}

void place_vert(int ship_id,int length)
{
  inut_buffer();  
  posX=("%d\n",(rand()%9)+1);
  posY=("%d\n",(rand()%9)+1);

  for(x=posX;x<posX+length;x++)
  {
    buffer[x][posY]=ship_id;

    if(x>9)
    {
      place_vert(ship_id,length);
    }

    if(map[x][posY]>0)
    {
      place_vert(ship_id,length);
    }
  }

  for(x=0;x<10;x++)
  {
    for(y=0;y<10;y++)
    {
      if(buffer[x][y]==ship_id)
      {
        map[x][y]=ship_id;
      }
    }
  }

}

void place_horz(int ship_id,int length)
{
  inut_buffer();  
  posX=("%d\n",(rand()%9)+1);
  posY=("%d\n",(rand()%9)+1);

  for(y=posY;y<posY+length;y++)
  {
    buffer[posX][y]=ship_id;
    
    if(y>9)
    {
      place_horz(ship_id,length);
    }

    if(map[posX][y]>0)
    {
      place_horz(ship_id,length);
    }
  }

  for(x=0;x<10;x++)
  {
    for(y=0;y<10;y++)
    {
      if(buffer[x][y]==ship_id)
      {
        map[x][y]=ship_id;
      }
    }
  }

}

void place_ships()
{
   srand(time(0));
   
  int pos[7];
  int i;
  for(i=0;i<6;i++)
  {
    pos[i]=("%d\n",(rand()%2)+1);
  }

  if(pos[0]==1)
     place_vert(1,2);
   else
     place_horz(1,2);

   if(pos[1]==1)
      place_vert(2,3);
    else
      place_horz(2,3);

    if(pos[2]==1)
      place_vert(3,3);
    else
      place_horz(3,3);

    if(pos[3]==1)
       place_vert(4,4);
    else
       place_horz(4,4);

    if(pos[5]==1)
       place_vert(5,5);
    else
       place_horz(5,5);

}

void place_ships();
void inut_hitmap();
void show_map();
void inut_map();
void inut_buffer();
void place_vert(int ,int);
void place_horz(int, int);
