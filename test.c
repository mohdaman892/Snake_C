#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>



int width=20;
int height=20;
int x,y,Fruitx,Fruity,score;
int Gameover=0;
int flag=0;
int tailx[100];
int taily[100];
int tailcount=0;
int prevx;
int prevy;
int k;
int i,j;

void draw(){
    int i,j;
    system("cls");
    for(i=0;i<width;i++){
        for(j=0;j<height;j++){
            if((i==0&&j<=height)||(j==0&&i<=width))
               printf("*");
            else if((j==height-1&&i<=width)||(i==width-1&&j<=height))
               printf("*");
            else if(i==x&&j==y)
               printf("0");
            else if(i==Fruitx&&j==Fruity)
               printf("F");
            else{
                int ch=0;
               for(k=0;k<tailcount;k++){
                  if(i==tailx[k]&&j==taily[k]){
                    printf("o");
                    ch=1;
                    }
               }
               if(ch==0)
                 printf(" ");}
            
        }
        printf("\n");
    }
   printf("SCORE =  %d\n\n",score);
   printf("Press W to go upwards\n");
   printf("Press S to go downwards\n");
   printf("Press D to go right\n");
   printf("Press A to go left\n");
   printf("Press Q anytime to exit!\n");
}


void setup(){
    x=height/2;
    y=width/2;
    label1:
      Fruitx=rand()%20;
      if(Fruitx==0)
        goto label1;
    label2:
      Fruity=rand()%20;
      if(Fruity==0)
        goto label2;
}


void input(){
    if(kbhit()==1){
   //  printf("%c",key);
    switch(getch()){
        case 'a':
           flag=1;
           break;
        case 'd':
           flag=2;
           break;
        case 'w':
           flag=3;
           break;
        case 's':
           flag=4;
           break;
        case 'q':
            Gameover=1;
        default:
          break;
    }}
}

void MakeLogic(){
   int i;
   int prevx=tailx[0];
   int prevy=taily[0];
   int prev2x;int prev2y;
   tailx[0]=x;
   taily[0]=y;

   for(i=1;i<tailcount;i++){
      prev2x=tailx[i];
      prev2y=taily[i];
      tailx[i]=prevx;
      taily[i]=prevy;
      prevx=prev2x;
      prevy=prev2y;
   }
   switch(flag){
      case 1:
         y--;
         break;
      case 2:
         y++;
         break;
      case 3:
         x--;
         break;
      case 4:
         x++;
         break;
      default:
        break;
   }

   if(x<=width&&y==0)
     Gameover=1;
   else if(y==height-1&&x<=width)
     Gameover=1;
   else if(x==0&&y<=height)
    Gameover=1;
   else if(x==width-1&&y<=height)
    Gameover=1;

   for(k=0;k<tailcount;k++){
      if(x==tailx[k]&&y==taily[k]){
         Gameover=1;
         break;}
   }


   if(x==Fruitx&&y==Fruity){
     score+=10;
     tailcount++;
     }

   
}



int main(){
setup();
while(Gameover!=1){
        draw();
        input();
        MakeLogic();
        }
system("cls");
printf("YOU LOOSE SNAKE DIED!\nPress E to Restart\n");
printf("Your Score= %d\n",score);
printf("Press Q to shutdown window!");
while(1){
   if(kbhit()==1){
      if(getch()=='e'){
            Gameover=0;
            main();}
      else if(getch()=='q'){
         break;}
      }
return 0;
}}
