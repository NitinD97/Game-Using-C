#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void createFood();
void createSnake();
    void createSnakeHead();
    void createSnakeBody();
    void createSnakeTail();
void updateCanvas();
void moveSnake(char canvas[15][15]);
void updateSnake(char);

struct Snake{
    int x;
    int y;
    char symbol;
    struct Snake *next;
}*head=NULL;

struct Food{
    int x;
    int y;
    char symbol;
}food;

void createSnakeHead()
{
    struct Snake *s=(struct Snake*) malloc(sizeof(struct Snake));
    s->symbol='A';
    s->x=2;
    s->y=2;
    s->next=NULL;
    head=s;
}

void createSnakeBody()
{
    struct Snake *s=(struct Snake*) malloc(sizeof(struct Snake));
    struct Snake *temp=head;
    s->symbol='O';
    s->x=2;
    s->y=3;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=s;
    s->next=NULL;
}

void createSnakeTail()
{
    struct Snake *s=(struct Snake*) malloc(sizeof(struct Snake));
    struct Snake *temp=head;
    s->symbol='C';
    s->x=2;
    s->y=4;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=s;
    s->next=NULL;
}

void createSnake()
{
    createSnakeHead();
    createSnakeBody();
    createSnakeTail();
}

void createFood()
{
    food.x=6;
    food.y=3;
    food.symbol='X';
}

void displaySnake()
{
    struct Snake *temp=head;
    while(temp!=NULL)
    {
        printf("%c",temp->symbol);
        temp=temp->next;
    }
    printf("%c",food.symbol);
}

void increaseSnakeLength()
{
    struct Snake *s=head;

}

void updateCanvas(char canvas[15][15])
{
    struct Snake *temp=head;
    while(temp!=NULL)
    {
        canvas[temp->x][temp->y]=temp->symbol;
        temp=temp->next;
    }
   /* int check=checkFoodEaten();
    if(check)
    {
        increaseSnakeLength();
    }*/
    canvas[food.x][food.y]=food.symbol;
}

/*int checkFoodEaten()
{
    struct Snake *s=head;
    if((s->x==food.x) && (s->y==food.y))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}*/

void createCanvas(char canvas[15][15])
{
    int i,j;
    for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            canvas[i][j]='.';
            //printf("%c ",canvas[i][j]);
        }
       // printf("\n");
    }
}

void printcanvas(char canvas[15][15])
{
    int i,j;
    for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            //canvas[i][j]='.';
            printf("%c ",canvas[i][j]);
        }
        printf("\n");
    }
}

int getXOfSnakeHead()
{
    struct Snake *temp=head;
    return temp->x;
}

int getYofSnakeHead()
{
    struct Snake *temp=head;
    return temp->y;
}

void updateSnake(char dir)
{
    int x,y;
    x=getXOfSnakeHead();
    y=getYofSnakeHead();
    if(dir=='i')
    {

        x=x-1;  //up
        if(x<0)
        {
            x=14;
        }
    }
    else if(dir=='j')
    {
        y=y-1;  //left
        if(y<0)
        {
            y=14;
        }
    }
    else if(dir=='k')
    {
        x=x+1;  //down
        if(x>14)
        {
            x=0;
        }
    }
    else if(dir=='l')
    {
        y=y+1;  //right
        if(y>14)
        {
            y=0;
        }
    }
    else
    {
        return;
    }
    int r[225],top=-1,c[255];
    struct Snake *temp=head;
    while(temp!=NULL)
    {
        top++;
        r[top]=temp->x;
        c[top]=temp->y;
        temp=temp->next;
    }
    int i=0;
    struct Snake *temp1=head;
    temp1->x=x;
    temp1->y=y;
    temp1=temp1->next;
    while(temp1!=NULL)
    {
        temp1->x=r[i];
        temp1->y=c[i];
        i++;
        temp1=temp1->next;
    }

}

void moveSnake(char canvas[15][15])
{
    int n=30;
    char dir='l';
    while(n)
    {
        if(kbhit)
        {
            dir=getch();
        }
        updateSnake(dir);
        createCanvas(canvas);
        updateCanvas(canvas);
        printf("\n");
        printcanvas(canvas);
        n--;
    }
}

int main()
{
    char canvas[15][15];
    createCanvas(canvas);
    createSnake();
    createFood();
    //printcanvas(canvas);
    updateCanvas(canvas);
    printcanvas(canvas);
    moveSnake(canvas);
    return 0;
}