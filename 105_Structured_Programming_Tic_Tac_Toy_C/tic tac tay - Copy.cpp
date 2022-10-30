#include<stdio.h>
char body[3][3]= {'1','2','3','4','5','6','7','8','9'};
int print_pattern ();
int plyer_1();
int plyer_2();
int result_checking1();
int result_checking2();
int x,y,a;
int assign_value();

main()
{
    printf( "welcome our project game TIC TOC TEY\n\n");
    print_pattern();
    plyer_1();
    plyer_2();


}
int print_pattern()
{
    printf ("\nits tic tac toe\n\n");
    int x,y;
    for (x=0; x<3; x++)
    {
        for (y=0; y<3; y++)
        {
            printf("%c",body[x][y]);
            printf("_|_");
        }
        printf("\n");
    }
}
int plyer_1()
{
    printf("\n [ player 1 ] please enter a number you want   : ");

    int i,j;

    char symbol='x';

    scanf ("%d",&a);
    printf("\n");
    //assign_value(symbol);
    if(a==1)
        body[0][0]=symbol;
    else if(a==2)
        body[0][1]=symbol;
    else if(a==3)
        body[0][2]=symbol;
    else if(a==4)
        body[1][0]=symbol;
    else if(a==5)
        body[1][1]=symbol;
    else if(a==6)
        body[1][2]=symbol;
    else if(a==7)
        body[2][0]=symbol;
    else if(a==8)
        body[2][1]=symbol;
    else if(a==9)
        body[2][2]=symbol;
    for (x=0; x<3; x++)
    {
        for (y=0; y<3; y++)
        {
            printf("%c",body[x][y]);
            printf("_|_");
        }
        printf("\n");
    }

}
int plyer_2()
{
    printf("now its time for [player 2] : ");
    char symbol='o';
    int a;
    scanf ("%d",&a);
    printf("\n");
    // assign_value(symbol);
    if(a==1)
        body[0][0]=symbol;
    else if(a==2)
        body[0][1]=symbol;
    else if(a==3)
        body[0][2]=symbol;
    else if(a==4)
        body[1][0]=symbol;
    else if(a==5)
        body[1][1]=symbol;
    else if(a==6)
        body[1][2]=symbol;
    else if(a==7)
        body[2][0]=symbol;
    else if(a==8)
        body[2][1]=symbol;
    else if(a==9)
        body[2][2]=symbol;

    for (x=0; x<3; x++)
    {
        for (y=0; y<3; y++)
        {
            printf("%c",body[x][y]);
            printf("_|_");
        }
        printf("\n");
    }
}


int assign_value(char symbol)
{
    if(a==1)
        body[0][0]=symbol;
    else if(a==2)
        body[0][1]=symbol;
    else if(a==3)
        body[0][2]=symbol;
    else if(a==4)
        body[1][0]=symbol;
    else if(a==5)
        body[1][1]=symbol;
    else if(a==6)
        body[1][2]=symbol;
    else if(a==7)
        body[2][0]=symbol;
    else if(a==8)
        body[2][1]=symbol;
    else if(a==9)
        body[2][2]=symbol;


}

int result_checking1()
{
    if(body[0][0]=='o'&& body[0][1]=='o'&& body[0][2]=='o')
        return 'o';
    if(body[1][0]=='o'&& body[1][1]=='o'&& body[1][2]=='o')
        return 'o';
    if(body[2][0]=='o'&& body[2][1]=='o'&& body[2][2]=='o')
        return 'o';
    if(body[0][0]=='o'&& body[1][0]=='o'&& body[2][0]=='o')
        return 'o';
    if(body[0][1]=='o'&& body[1][1]=='o'&& body[2][1]=='o')
        return 'o';
    if(body[0][2]=='o'&& body[1][2]=='o'&& body[2][2]=='o')
        return 'o';
    if(body[2][0]=='o'&& body[1][1]=='o'&& body[0][2]=='o')
        return 'o';
    if(body[0][0]=='o'&& body[1][1]=='o'&& body[2][2]=='o')
        return 'o';


}
result_checking2()
{
    if(body[0][0]=='o'&& body[0][1]=='o'&& body[0][2]=='o')
        return 'o';
    if(body[1][0]=='o'&& body[1][1]=='o'&& body[1][2]=='o')
        return 'o';
    if(body[2][0]=='o'&& body[2][1]=='o'&& body[2][2]=='o')
        return 'o';
    if(body[0][0]=='o'&& body[1][0]=='o'&& body[2][0]=='o')
        return 'o';
    if(body[0][1]=='o'&& body[1][1]=='o'&& body[2][1]=='o')
        return 'o';
    if(body[0][2]=='o'&& body[1][2]=='o'&& body[2][2]=='o')
        return 'o';
    if(body[2][0]=='o'&& body[1][1]=='o'&& body[0][2]=='o')
        return 'o';
    if(body[0][0]=='o'&& body[1][1]=='o'&& body[2][2]=='o')
        return 'o';


}

