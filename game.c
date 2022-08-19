#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<dos.h>
#include<dir.h>
void game_rules(char [],int);
void play_game(char [],int);
void print_random_matrix(int [],int);
void print_matrix(int [],int);
int find_index(int [],int);
int compare_matrix(int [],int []);
void resultant_matrix(int []);
void SetColor(int);
int main()
{
    char name[20];
    int result,moves=4;
    printf("\n\n\n\nPlayer Name : ");
    fgets(name,20,stdin);
    name[strlen(name)-1]='\0';
    system("cls");
    game_rules(name,moves);
    play_game(name,moves);
    while(1)
    {
        system("cls");
        SetColor(4);
        printf("\n\n              YOU LOSE\n\n");
        SetColor(2);
        printf("Want to play again ?\n");
        SetColor(15);
        printf("Enter 'y' to play again or 'n' to exit the game: ");
        int ch;
        ch=getch();
        if(ch=='n')
            exit(0);
        else
            play_game(name,moves);

    }
    getch();
}
void print_matrix(int b[],int size)
{
    printf("---------------------\n");
    for(int i=0;i<=3;i++)
    {
        if(b[i]==32)
            printf("|  %c ",b[i]);
        else if(b[i]>=10)
            printf("| %d ",b[i]);
        else
            printf("|  %d ",b[i]);
    }
    printf("|\n");
    for(int i=4;i<=7;i++)
    {
        if(b[i]==32)
            printf("|  %c ",b[i]);

        else if(b[i]>=10)
            printf("| %d ",b[i]);
        else
            printf("|  %d ",b[i]);
    }
    printf("|\n");
    for(int i=8;i<=11;i++)
    {
        if(b[i]==32)
            printf("|  %c ",b[i]);
        else if(b[i]>=10)
            printf("| %d ",b[i]);
        else
            printf("|  %d ",b[i]);
    }
    printf("|\n");
    for(int i=12;i<=15;i++)
    {
        if(b[i]==32)
            printf("|  %c ",b[i]);
        else if(b[i]>=10)
            printf("| %d ",b[i]);
        else
            printf("|  %d ",b[i]);
    }
    printf("|\n");
    printf("---------------------");
}
void print_random_matrix(int b[],int size)
{
    int num,temp=1;
    for(int i=0;i<size;i++)
        b[i]=temp++;
    srand(time(NULL));
    for(int i=14;i>0;i--)
    {
        num=(rand()%i);
        temp=b[num];
        b[num]=b[i];
        b[i]=temp;
    }
    b[15]=32;
    print_matrix(b,size);
}
int find_index(int a[],int size)
{
    for(int i=0;i<size;i++)
    {
        if(a[i]==32)
            return i;
    }
}
void resultant_matrix(int a[])
{
    for(int i=0;i<=14;i++)
    {
        a[i]=++i;
    }
    a[15]=32;
}
int compare_matrix(int a[],int b[])
{
    for(int i=0;i<=15;i++)
    {
        if(a[i]!=b[i])
            return 0;
    }
    return 1;
}
void play_game(char name[],int moves)
{
    int result,i,temp,index,a[16],b[16];
    system("cls");
    printf("\n\n  Player Name: %s , Moves remaining : %d\n\n",name,moves);
    print_random_matrix(a,16);
    printf("\n\n");
    char ch=getch();
    if(ch=='E'||ch=='e')
            exit(0);
    else if(ch==77)
    {

            for(;;)
            {
                i=find_index(a,16);
                if(i==0)
                {
                    printf("\nYou have pressed wrong arrow key as no. can;t move,press correct key to play further ");
                    ch=getch();
                    if(ch!=77)
                        break;
                    else
                        continue;
                }
                else
                {
                     temp=a[i-1];
                     a[i-1]=a[i];
                     a[i]=temp;
                    moves--;
                    break;
                }
            }
    }
    else if(ch==75)
    {

            for(;;)
            {
                i=find_index(a,16);
                if(i==15)
                {
                    if(i==0)
                    {
                      printf("\nYou have pressed wrong arrow key as no. can;t move,press correct key to play further ");
                      ch=getch();
                      if(ch!=75)
                        break;
                      else
                        continue;
                    }
                }
                else
                {
                   temp=a[i];
                   a[i]=a[i+1];
                   a[i+1]=temp;
                   moves--;
                    break;
                }

            }

    }
    else if(ch==72)
    {

            for(;;)
            {
                i=find_index(a,16);
                if(i>=12)
                {
                    printf("\nYou have pressed wrong arrow key as no. can;t move,press correct key to play further ");
                    ch=getch();
                    if(ch!=72)
                        break;
                    else
                        continue;
                }
                else
                {
                    temp=a[i];
                    a[i]=a[i+4];
                    a[i+4]=temp;
                    moves--;
                    break;
                }
            }

    }
    else if(ch==80)
    {

            for(;;)
            {
                i=find_index(a,16);
                if(i<=3)
                {
                    printf("You have pressed wrong arrow key as no. can;t move,press correct key to play further ");
                    ch=getch();
                    if(ch!=80)
                        break;
                    else
                        continue;


                }
                else
                {
                    temp=a[i-4];
                    a[i-4]=a[i];
                    a[i]=temp;
                    moves--;
                    break;
                }
            }

    }
    for(int i=moves;moves>0;i--)
    {
        system("cls");
        printf("\n\n  Player Name: %s , Move remaining : %d\n\n",name,moves);
        print_matrix(a,16);
        printf("\n\n");
        resultant_matrix(b);
        result=compare_matrix(a,b);
        if(result==1)
        {
            printf("         YOU WON        ");
            exit(0);
        }
        else
        {
            ch=getch();
            if(ch=='E'||ch=='e')
                exit(0);
            else if(ch==77)
            {
                    for(;;)
                    {
                        i=find_index(a,16);
                        if(i==0)
                        {
                            printf("\nYou have pressed wrong arrow key as no. can;t move,press correct key to play further \n");
                            ch=getch();
                            if(ch!=77)
                                break;
                            else
                                continue;
                        }
                        else
                        {
                             temp=a[i-1];
                             a[i-1]=a[i];
                             a[i]=temp;
                            moves--;
                            break;
                        }
                    }
            }
            else if(ch==75)
            {

                for(;;)
                {
                    i=find_index(a,16);
                    if(i==15)
                    {
                          printf("\nYou have pressed wrong arrow key as no. can;t move,press correct key to play further ");
                          ch=getch();
                          if(ch!=75)
                              break;
                          else
                            continue;


                    }
                    else
                    {
                       temp=a[i];
                       a[i]=a[i+1];
                       a[i+1]=temp;
                       moves--;
                        break;
                    }

                }
            }
            else if(ch==72)
            {

                for(;;)
                {
                    i=find_index(a,16);
                    if(i>=12)
                    {
                        printf("\nYou have pressed wrong arrow key as no. can;t move,press correct key to play further ");
                        ch=getch();
                        if(ch!=72)
                            break;
                        else
                            continue;
                    }
                    else
                    {
                        temp=a[i];
                        a[i]=a[i+4];
                        a[i+4]=temp;
                        moves--;
                        break;
                    }
                }

            }
            else if(ch==80)
            {

                for(;;)
                {
                    i=find_index(a,16);
                    if(i<=3)
                    {
                        printf("\nYou have pressed wrong arrow key as no. can;t move,press correct key to play further ");
                        ch=getch();
                        if(ch!=80)
                            break;
                        else
                            continue;

                    }
                    else
                    {
                        temp=a[i-4];
                        a[i-4]=a[i];
                        a[i]=temp;
                        break;
                    }
                }
            }
        }
    }
}
void game_rules(char name[],int moves)
{
    printf("                     MATRIX PUZZLE\n\n");
    SetColor(4);
    printf("                    RULE OF THIS GAME\n\n");
    printf("1.You can move only 1 step at a time by arrow key\n");
    SetColor(15);
    printf("       Move Up   : by Up arrow key\n");
    printf("       Move Down : by Down arrow key\n");
    printf("       Move Left : by Left arrow key\n");
    printf("       Move Right: by Right arrow key\n");
    SetColor(4);
    printf("2.You can move number at empty position only\n\n");
    printf("3.For each valid move : your total number of move will decreased by 1\n");
    printf("4. Winning situation : Number in 1 4*4 matrix should be in order from 1 to 15\n\n");
    SetColor(15);
    printf("          Winning situation:\n");
    SetColor(11);
    printf("---------------------\n");
    int k=1;
    for(int i=0;i<=3;i++)
    {
        for(int j=0;j<=3;j++)
        {
            if(k==16)
                printf("|    ");
            else if(k>=10)
                printf("| %d ",k++);
            else
                printf("|  %d ",k++);
        }
        printf("|\n");
    }

    printf("---------------------\n\n");
    SetColor(15);
    printf("5.You can exit at any time by pressing 'E' or 'e' \nSo Try to win in minimum no. of moves\n\n");
    printf("Enter any key to start....  ");
    getch();
}
void SetColor(int ForgC)
{
    WORD wColor;
    HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut,&csbi))
    {
        wColor=(csbi.wAttributes & 0xF0)+(ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut,wColor);
    }
    return ;
}

