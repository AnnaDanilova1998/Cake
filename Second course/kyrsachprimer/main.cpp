#include <stdio.h>
#include <math.h>
#include <fstream>
#include <vector>
//#include "rus_io.h"
#include "conio2.h"
#include "graphics.h"
#include <iostream>
#include <stdio.h>
using namespace std;

const int maxn=24;

struct XY{
int x,y;
} cordVrt[maxn];

int n;
const int cm_save=1,//комманды от пользователя
cm_load=2,
cm_change_amoung=3,
cm_change_cord=4,
cm_add_edge=5,
cm_delete_edge=6,
cm_change_adge=7,
cm_solution=8;
const int inf=-1;
const int inf2=-2;
const int colorEdge=BLACK;
const int colorPathEdge=YELLOW;
int d[maxn][1<<maxn];
typedef int tgraph[maxn][maxn];
tgraph g;
vector <int> path;
void clearScreen()
{
setcolor(BLUE);
setfillstyle(1,DARKGRAY);
rectangle(0,0,getmaxx(),getmaxy());
floodfill(1,1,BLUE);

}
void str(char s[], int a)
{
int i=0;
char ch[30];
s[0]='\0';
ch[1]='\0';
while (a)
{
ch[1]='\0';
ch[0]=a%10+'0';
strcat(ch,s);
strcpy(s,ch);
a/=10;
}
}
void drawVrt(XY cordVrt[], int i)
{
settextstyle(3,0,2);
char s[20];
str(s,i+1);
setcolor(YELLOW);
setfillstyle(1,DARKGRAY);
setbkcolor(DARKGRAY);
if (i>8)
outtextxy(cordVrt[i].x-12,cordVrt[i].y-12,s);
else outtextxy(cordVrt[i].x-7,cordVrt[i].y-12,s);
setcolor(YELLOW);
circle(cordVrt[i].x,cordVrt[i].y,15);
circle(cordVrt[i].x,cordVrt[i].y,16);
circle(cordVrt[i].x,cordVrt[i].y,17);
circle(cordVrt[i].x,cordVrt[i].y,18);
}
void drawArc(XY cordVrt[], int v1, int v2, int cost, int color)
{
if (v1>v2) swap(v1,v2);
int dx=cordVrt[v1].x-cordVrt[v2].x,
dy=cordVrt[v1].y-cordVrt[v2].y;
double mn=18/pow(dx*dx+dy*dy,0.5);
int mx=(cordVrt[v1].x+cordVrt[v2].x)/2,
my=(cordVrt[v1].y+cordVrt[v2].y)/2;
setcolor(color);
dx=rint(double(dx)*mn);
dy=rint(double(dy)*mn);
line(cordVrt[v1].x-dx, cordVrt[v1].y-dy,cordVrt[v2].x+dx, cordVrt[v2].y+dy);
line(cordVrt[v1].x-dx, cordVrt[v1].y-dy-1,cordVrt[v2].x+dx, cordVrt[v2].y+dy-1);
line(cordVrt[v1].x-dx-1, cordVrt[v1].y-dy,cordVrt[v2].x+dx-1, cordVrt[v2].y+dy);
char s[20];
str(s,cost);
settextstyle(3,0,2);
outtextxy(mx+dx*0,my+dy*0, s);
}
bool canAddVrt(XY cordVrt[],int vrt)
{
for (int i=0;i<vrt;i++)
if (((pow(cordVrt[i].x-cordVrt[vrt].x,2))+pow(cordVrt[i].y-cordVrt[vrt].y,2))<3600)
return false;
return true;
}
int getCommand()
{
clrscr();
int n;
cout << "type one of the next number and press ENTER\n";
cout << "0 - exit program\n";
cout << "1 - save graph to file\n";
cout << "2 - load graph from file\n";
cout << "3 - change amount vertix in graph\n";
cout << "4 - change coordinates of the vertex\n";
cout << "5 - add edge\n";
cout << "6 - delete edge\n";
cout << "7 - change cost of the edge\n";
cout << "8 - find a solution to the traveling salesman problem\n";
cin >> n;
if (!cin) n=25;
return n;
}
void outAll(XY cordVrt[], tgraph g,int n)
{
clearScreen();
for (int i=0;i<n;i++)
drawVrt(cordVrt,i);
for (int i=0;i<n;i++)
for (int j=i+1;j<n;j++)
if (g[i][j]!=inf)
drawArc(cordVrt,i,j, g[i][j], colorEdge);
}
void saveData(XY cordVrt[], tgraph g,int n)
{
cout << "type name of the file: ";
char s[30];
gets(s);
gets(s);
ofstream out;
out.open(s);
out << n << endl;
for (int i=0;i<n;i++)
out << cordVrt[i].x << " "<< cordVrt[i].y<< endl;
out << endl;
for (int i=0;i<n;i++)
{
for (int j=0;j<n;j++)
out << g[i][j] << " ";
out << endl;
}
cout << "Data has saved";
delay(2000);
}
void loadData(XY cordVrt[], tgraph g,int &n)
{
cout << "type name of the file: ";
char s[30];
gets(s);
gets(s);
ifstream in;
in.open(s);
if (in.fail())
{
cout << "can't open file!Try again";
delay(2000);
}
in >> n;
for (int i=0;i<n;i++)
in >> cordVrt[i].x >> cordVrt[i].y;
for (int i=0;i<n;i++)
for (int j=0;j<n;j++)
in >> g[i][j];
cout << "Data has loaded";
outAll(cordVrt, g,n);
delay(2000);
}
void changeAmoung(XY cordVrt[],tgraph g, int &n)
{
cout << "type new count of vertex: ";
int newn;
cin >> newn;
if (newn>n)
{
int maxx=getmaxx(),
maxy=getmaxy();
maxx-=50;maxy-=50;
for (int i=n;i<newn;i++)
{
do
{
cordVrt[i].x=rand()%maxx+20;
cordVrt[i].y=rand()%maxy+20;
} while (!canAddVrt(cordVrt, i));
drawVrt(cordVrt,i);
}
for (int i=0;i<n;i++)
for (int j=n;j<newn;j++)
g[i][j]=inf;
for (int i=n;i<newn;i++)
for (int j=0;j<newn;j++)
g[i][j]=inf;
n=newn;
}
else {n=newn; outAll(cordVrt, g,n);}
}
void changeCord(XY cordVrt[], tgraph g,int n)
{
cout << "type number of vertix which coordinates you want to change: ";
int k;
cin >> k;
k--;
cout << "old coordinate X: " << cordVrt[k].x<< endl;
cout << "old coordinate Y: " << cordVrt[k].y<< endl;
cout << "type new coordinate X: ";
cin >> cordVrt[k].x;
cout << "type new coordinate Y: ";
cin >> cordVrt[k].y;
outAll(cordVrt, g,n);
}
void addEdge(XY cordVrt[], tgraph g)
{
cout << "type the numbers of vertices: ";
int v1,v2,cost;
cin >> v1 >> v2;
v1--;v2--;
cout << "type cost the new edge: ";
cin >> cost;
g[v1][v2]=cost;
g[v2][v1]=cost;
drawArc(cordVrt,v1,v2, cost, colorEdge);
}
void deleteEdge(XY cordVrt[], tgraph g,int n)
{
cout << "type the numbers of vertices: ";
int v1,v2,cost;
cin >> v1 >> v2;
v1--;v2--;
g[v1][v2]=-1;
g[v2][v1]=-1;
outAll(cordVrt, g,n);
}
void changeEdge(XY cordVrt[], tgraph g,int n)
{
cout << "type the numbers of vertices: ";
int v1,v2,cost;
cin >> v1 >> v2;
v1--;v2--;
cout << "type new cost the new edge: ";
cin >> cost;
g[v1][v2]=cost;
g[v2][v1]=cost;
outAll(cordVrt,g,n);
}
void initPerem(XY cordVrt[], tgraph g)
{
for (int i=0;i<maxn;i++)
for (int j=0;j<maxn;j++)
g[i][j]=inf;
//cin >> n;
n=2;
int maxx=getmaxx(),
maxy=getmaxy();
maxx-=50;maxy-=50;
for (int i=0;i<n;i++){
do
{
cordVrt[i].x=rand()%maxx+20;
cordVrt[i].y=rand()%maxy+20;
} while (!canAddVrt(cordVrt, i));
drawVrt(cordVrt,i);
}
}
/*-------------getSolution ----------*/
int rec(int i, int mask)//масссив d и n не передаётся, чтобы экономить стековую память
{
if (d[i][mask] != inf )
return d[i][mask];
for (int j=n-1;j>=0;j--)
if ((g[i][j]!=inf) && (mask & (1 << j)))// j-ый бит mask == 1)
{
int k=rec(j, mask - (1<<j));
if (k==inf2) continue;
if (d[i][mask]==inf)
d[i][mask] = k + g[i][j];
else d[i][mask] = min(d[i][mask], k + g[i][j]);
}
if (d[i][mask]==inf) d[i][mask]=inf2;
return d[i][mask];
}
bool getPath(tgraph g)
{
    path.clear();
path.push_back(0);
int i=0, mask= (1<<n)-1;
if (d[i][mask]==inf2) return false;
for (int k=0;k<n;k++)
{
for (int j=0;j<n;j++)
if (g[i][j]!=inf)
if (d[i][mask] == d[j][mask-(1<<j)]+g[i][j])
{
path.push_back(j);
i=j;
mask=mask - (1<<j);
continue;
}
}
return true;
}

void outResult(XY cordVrt[])
{
for (int i=0;i<path.size()-1;i++)
{
drawArc(cordVrt,path[i],path[i+1],g[path[i]][path[i+1]], colorPathEdge);
}
}

void getSolution(XY cordVrt[], tgraph g, int n)
{
//инициализация переменны
int maxj=(1<<n);
for (int i=0;i<n;i++)
for (int j=0;j<maxj;j++)
d[i][j]=inf;
d[0][0]=0;

//

rec(0,(1 << n) - 1);

if (getPath(g))
{
int k=d[0][(1<<n)-1];
outResult(cordVrt);
//найдем стоимость всех дуг
int r=0;
for (int i=0;i<n;i++)
for (int j=i+1;j<n;j++)
if (g[i][j]!=inf)
r+=g[i][j];
cout << "cost of the path = "<<k;
cout << "\ncost of the all edges = "<<r<<endl;
// cout << "\npress any key to continue";
}
