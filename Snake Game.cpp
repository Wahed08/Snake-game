#include <dos.h>
#include <conio.h>
#include <windows.h>
#include <graphics.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>;

using namespace std;
void help();
void game();
void check();
void dead();
void level();
void high();
void border_End();
void play_again();
int snake_x[500],snake_y[500],snake_size = 5,score,highscore,spd = 100,l,foodcount=0, page=0;

bool checkdied = false,BONUS = false;
main()
{

    int gdirect = DETECT,gmode;  /* request autodetection */
    initgraph(&gdirect,&gmode,""); /* initialize graphics and local variables */
    char ch;
      setcolor(15);
  settextstyle(4,0,4);
  outtextxy(80,10," Project-1: Snake game");
  settextstyle(6,0,2);
  setcolor(GREEN);
  outtextxy(100,100,"Presented by:");
  outtextxy(100,140,"Mohammad Farhad-08");
  outtextxy(100,180,"Talha Bin Jafar-15");
  outtextxy(100,280,"Presented to: ");
  outtextxy(100,320,"Asif Mohammed Samir Sir ");
  outtextxy(100,340,"Assistant Professor");
  outtextxy(100,360,"IICT,SUST");
  ch=getch();
  cleardevice();



    int cursor_y = 130;
    while(1)
    {
        clearviewport();
        setcolor(RED);
        settextstyle(1,0,6);
        outtextxy(180,30," Snake ");
        setcolor(YELLOW);
        settextstyle(3,0,3); /*this part prints menu again but inside while loop,because other functions will return here*/
        outtextxy(200,130,"New Game");
        outtextxy(200,160,"Help");
        outtextxy(200,190,"Select Level");
        outtextxy(200,220,"Highscore");
        outtextxy(200,250,"Exit");
        outtextxy(160,cursor_y,">");
        setcolor(WHITE);
        settextstyle(3,0,3);
        outtextxy(200,300,"<<Please Select Level First>>   ");

        if(kbhit){
        ch = getch();
        setcolor(GREEN);
        outtextxy(160,cursor_y,"<");
        if(ch == 13) {
            //if(cursor_y==250) exit(0);
             if(cursor_y==160) help();
            else if(cursor_y==130) game();
            else if(cursor_y==190) level();
            else if(cursor_y==220) high();
            else if(cursor_y==250) exit(0);
        }
        }
        setcolor(WHITE);
        if(ch==80) {cursor_y+=30;
        if(cursor_y > 250) {cursor_y=130;}
        }
        if(ch==72) {cursor_y-=30;
        if(cursor_y < 130) {cursor_y=250;}
        }
        outtextxy(160,cursor_y,">");
    }

    return 0;
}
void help()
{
    setcolor(WHITE);
    outtextxy(100,300,"Move the snake using the Arrow keys.");
    outtextxy(100,330,"Press 'Alt' to Pause");
    char ch = getch();
    clearviewport();
    return;
}
void play_again()
{
 setactivepage(page);
            setvisualpage(1-page);
    getch();
    snake_size=5;
    score=0;
    game();
    main();
    clearviewport();
    return;
    page=1-page;
}
void game()
{

    clearviewport();
    freopen("GameData.dat","r",stdin);
    cin >> highscore;


    cleardevice();
    char ch;
    int k;
    string key = "right";

    int x = 65,y = 65;
    int maxx=getmaxx();
    int maxy=getmaxy();


    int food_x = rand()%600,food_y = rand()%400;
    int temp;
    temp = food_x%13;
    food_x-=temp;
    temp = food_y%13;
    food_y-=temp;
    //if(food_x<22||food_y<45)
      //  goto ram;
    int i = 0;
    int bonus = 5000;
    int foodcount=0;
    while(true)
        {
            setactivepage(page);
            setvisualpage(1-page);
            cleardevice();
         //clearviewport();
        if(score >0 && score%5==4) BONUS = true;
        else{ bonus = 1000;
         BONUS = false;
        }
        if(!BONUS || bonus == 0){
        setcolor(BLACK);
        outtextxy(250,25,"Hurry!! 888");
        setcolor(WHITE);
        setfillstyle(SOLID_FILL,WHITE);
        circle(food_x,food_y,7 ); //x position,y position,size
        floodfill(food_x,food_y,WHITE);

        }
        else
        {
        setcolor(RED);
        setfillstyle(SOLID_FILL,RED);
        circle(food_x,food_y,10);
        floodfill(food_x,food_y,RED);

        char spp[1000];
        setcolor(BLACK);
        sprintf(spp,"Hurry!! %d",bonus);
        outtextxy(250,25,"Hurry!! 888");
        setcolor(GREEN);
        outtextxy(250,25,spp);
        // clears
        }
        maxx = getmaxx();
        maxy = getmaxy()-50;
        setcolor(WHITE);
        //line(0,maxy+8,maxx,maxy+8);
        if(kbhit())
        {
            ch = getch(); if(ch == 0) ch = getch();
            if(ch == 72 && key != "down" ) key = "up";
            if(ch == 80 && key != "up") key = "down";
            if(ch == 75 && key != "right") key = "left";
            if(ch == 77 && key != "left") key = "right";
            if(ch == 27) {
            cleardevice();
            return;
        }

        }
     rectangle(25,25,maxx-25,maxy-25);
     rectangle(10,10,maxx-10,maxy-10);
     setfillstyle(LTSLASH_FILL,LIGHTGRAY);
     floodfill(11,11,WHITE);
    if(foodcount>=5){
            bar(250,130,400,150);

    if(x>=250&&x<=400&&y>=130&&y<=150){
            delay(0.1);
            setcolor(WHITE);
            for(int i = 0;i < snake_size;i++)
            {
                circle(snake_x[i],snake_y[i],5);
                setfillstyle(SOLID_FILL,RED);
                floodfill(snake_x[i],snake_y[i],WHITE);
            }
            delay(0.1);
            clearviewport();
            while(1){
            if(kbhit()){
            char ch = getch();
            if(ch == 13){

            checkdied = true;
            clearviewport();
            cleardevice();

            return;
}
            }
            }
}
}
      if(foodcount>=10){
            bar(250,280,400,300);
      if(x>=250&&x<=400&&y>=280&&y<=300){
            delay(500);
            setcolor(WHITE);
            for(int i = 0;i < snake_size;i++)
            {
                circle(snake_x[i],snake_y[i],5);
                setfillstyle(SOLID_FILL,RED);
                floodfill(snake_x[i],snake_y[i],WHITE);
            }
           while(1){
            if(kbhit()){
            char ch = getch();
            if(ch == 13){
            checkdied = true;
            clearviewport();
            cleardevice();

            return;
}
            }
            }

}

}
     if(foodcount>=15){
        bar(150,140,170,290);
     if(x>=150&&x<=170&&y>=140&&y<=290){
            delay(500);
            setcolor(WHITE);
            for(int i = 0;i < snake_size;i++)
            {
                circle(snake_x[i],snake_y[i],5);
                setfillstyle(SOLID_FILL,RED);
                floodfill(snake_x[i],snake_y[i],WHITE);
            }
            while(1){
            if(kbhit()){
            char ch = getch();
            if(ch == 13){
            checkdied = true;
            clearviewport();
            cleardevice();

            return;
}
            }
            }
}
}
        if(foodcount>=20){
            bar(500,140,520,290);

       if(x>=500&&x<=520&&y>=140&&y<=290){
            delay(500);
            setcolor(WHITE);
            for(int i = 0;i < snake_size;i++)
            {
                circle(snake_x[i],snake_y[i],5);
                setfillstyle(SOLID_FILL,RED);
                floodfill(snake_x[i],snake_y[i],WHITE);
            }
            while(1){
            if(kbhit()){
            char ch = getch();
            if(ch == 13){
            checkdied = true;
            clearviewport();
            cleardevice();

            return;
}
            }
            }
}
}
            //delay(500);
            //cleardevice();

        if(i < 5)
         {
            snake_x[i] = x-240;
            snake_y[i] = y-285;
            i++;
        }
        else {
        for(int _size = snake_size-2;_size >= 0;_size--) {
        snake_x[_size+1] = snake_x[_size];
        snake_y[_size+1] = snake_y[_size];
        }
        snake_x[0] = x;
        snake_y[0] = y;

        setcolor(WHITE);
        circle(snake_x[0],snake_y[0],8);
        setfillstyle(SOLID_FILL,WHITE);
        floodfill(snake_x[0],snake_y[0],WHITE);

        setcolor(YELLOW);
        for(int _size = 1; _size < snake_size;_size++)
        {
        circle(snake_x[_size],snake_y[_size],5);
        setfillstyle(SOLID_FILL,GREEN);
        floodfill(snake_x[_size],snake_y[_size],YELLOW);
        }



        char ara[100];
        sprintf(ara,"Score: %d",score);
        setcolor(WHITE);
        outtextxy(20,maxy+00,ara);
        //sprintf(ara,"Bestscore: %d",highscore);
        //setcolor(WHITE);
        //outtextxy(400,maxy+10,ara);


        delay(spd+20);

        }
        if(x == food_x && y== food_y)
        {
        snake_size++;score++;foodcount++;

            /* Snake eats food*/
        if(score%5==0 && score>0)score+=bonus;
        food_x = rand()%600,food_y = rand()%400;
        temp = food_x%13;
        food_x-=temp;
        temp = food_y%13;
        food_y-=temp;

        if((food_x < 35 || food_x > maxx - 35 || food_y < 35 || food_y > maxy - 35)||(foodcount>=5 && food_x>=250 && food_x<=400 && food_y>=130 && food_y<=150) || (foodcount >= 9 && food_x >= 250 && food_x <= 400 && food_y >= 280 && food_y <= 300)||(foodcount >= 14 && food_x >= 150 && food_x <= 170 && food_y >= 140 && food_y <= 290)||(foodcount >= 19 && food_x >= 150 && food_x <= 170 && food_y >= 140 && food_y <= 290)||(foodcount >= 24 && food_x >= 500 && food_x <= 520 && food_y >= 140 && food_y <= 290))
        {
            while((food_x < 35 || food_x > maxx - 35 || food_y < 35 || food_y > maxy - 35)||(foodcount>=5 && food_x>=250 && food_x<=400 && food_y>=130 && food_y<=150) || (foodcount >= 9 && food_x >= 250 && food_x <= 400 && food_y >= 280 && food_y <= 300)||(foodcount >= 14 && food_x >= 150 && food_x <= 170 && food_y >= 140 && food_y <= 290)||(foodcount >= 19 && food_x >= 150 && food_x <= 170 && food_y >= 140 && food_y <= 290)||(foodcount >= 24 && food_x >= 500 && food_x <= 520 && food_y >= 140 && food_y <= 290)){
            food_x = rand()%600,food_y = rand()%400;
            temp = food_x%13;
            food_x-=temp;
            temp = food_y%13;
            food_y-=temp;
        }
        }
        }
        if(snake_size>15)
            snake_size=5;
        if(key == "right") x = x+13; if(x > maxx-25) border_End();
        if(key == "left") x = x-13; if(x < 25) border_End();
        if(key == "up") y = y-13; if(y > maxy-25) border_End();
        if(key == "down") y = y+13; if(y < 25) border_End();
        check();
        if(checkdied){
        dead();
        return;
        }


    if(BONUS){
    if(bonus>0)
    bonus-=05;
      }
       /* setcolor(BLACK);
        circle(snake_x[0],snake_y[0],8);
        setfillstyle(SOLID_FILL,BLACK);
        floodfill(snake_x[0],snake_y[0],BLACK);
        page=1-page;*/
      }
        for(int _size = 1; _size < snake_size;_size++)
         {
        circle(snake_x[_size],snake_y[_size],5);
        setfillstyle(SOLID_FILL,BLACK);
        floodfill(snake_x[_size],snake_y[_size],BLACK);
        }
        page=1-page;
}

void check()
{

    freopen("GameData.dat","w",stdout);
    if(highscore < score)
    cout << score << endl;
    else cout << highscore << endl;
   for(int i = 1;i < snake_size;i++)
    {setactivepage(page);
            setvisualpage(1-page);
        if(snake_x[0] == snake_x[i] && snake_y[0] == snake_y[i])
        {
            delay(1000);
            setcolor(WHITE);
            for(int i = 0;i < snake_size;i++)
            {
                circle(snake_x[i],snake_y[i],5);
                setfillstyle(SOLID_FILL,RED);
                floodfill(snake_x[i],snake_y[i],WHITE);
            }
            delay(500);
            cleardevice();
            settextstyle(3,0,4);
    outtextxy(150,150,"    GAME OVER ");
    outtextxy(100,200,"Press Enter to play again");
    outtextxy(100,250,"Press Esc to back");
    //page=1-page;
    char ch=getch();
    if(ch==13)    play_again();
   else if(ch==27) exit(0);
   page=1-page;

     cleardevice();
     delay(500);
    //getch();
   // getch();
    exit(0);
   // page=1-page;
          /*  while(1){
            if(kbhit()){
            char ch = getch();
            if(ch == 13){
            checkdied = true;
            clearviewport();
            cleardevice();

            return;
            }
            }
            }*/
        }
    }
}

void dead()
{
     setactivepage(page);
            setvisualpage(1-page);
    checkdied = false;
    snake_size = 5;
    score = 0;
    page=1-page;
//    clearviewport();
}
void border_End()
{

   cleardevice();
    setactivepage(page);
            setvisualpage(1-page);
    settextstyle(3,0,4);
    outtextxy(150,150,"    GAME OVER ");
    outtextxy(100,200,"Press Enter to play again");
    outtextxy(100,250,"Press Esc to back");
    // page=1-page;
    char ch = getch();
    if(ch==13)
    play_again();
    else if(ch==27)
        exit(0);
page=1-page;
     cleardevice();
     delay(500);
    getch();
    exit(0);
    }

void level()
{
    char ch;
    char ara[100];
    while(true){

    int i = abs(spd/10-10);
    sprintf(ara,"SELECT LEVEL : %d",i);
    setcolor(WHITE);
    outtextxy(180,350,ara);

    if(kbhit())
    {
        ch = getch();
        if(ch == 80) {
        spd-=10;
        if(spd < 0) spd = 100;
        }
        else if(ch == 72) {
            spd+=10;
        if(spd > 100) spd = 0;
        }
        else if(ch == 13)
            break;
    sprintf(ara,"SELECT LEVEL : %d",i);
    setcolor(BLACK);
    outtextxy(180,350,ara);
    }
    }

    clearviewport();
}
void high()
{
        freopen("GameData.dat","r",stdin);
        cin >> highscore;
        char ara[100];
        sprintf(ara,"Highscore: %d",highscore);
        setcolor(WHITE);
        outtextxy(200,350,ara);
        char ch = getch();
        clearviewport();
}
