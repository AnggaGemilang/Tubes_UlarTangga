#ifndef header_H
#define header_H

#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <malloc.h>
#include <math.h>
#include <atomic>
#include <thread>
#include <cmath>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#include "users.h"
#include "linkedlist.h"
#include "maps.h"
#include "umum.h"
#include "menu.h"
#include "permainan.h"
#include "boolean.h"

#define ENTER_KEY 13
#define UP_KEY 72
#define DOWN_KEY 80
#define LEFT_KEY 75
#define RIGHT_KEY 77
#define ESC_KEY 27
#define WDT_SCREEN GetSystemMetrics(SM_CXSCREEN)
#define HGT_SCREEN GetSystemMetrics(SM_CYSCREEN)
#define BLACK           0
#define PURPLE          5
#define LIGHT_GRAY      7
#define LIGHT_GREEN    10
#define LIGHT_BLUE     11
#define RED            12
#define YELLOW         14
#define WHITE          15

#define Nil NULL
#define Prev(P)     (P)->prev
#define Info(P)     (P)->info
#define Simbol(P)   (P)->simbol
#define Jump(P)     (P)->jump
#define Next(P)     (P)->next
#define posisi(P)   (P)->posisi
#define Nama(P)     (P)->nama
#define Bidak(P)    (P)->bidak
//#define x(P)     (P)->x
//#define y(P)     (P)->y
#define First(L) (L).First
#define Last(L) (L).Last

using namespace std;

#endif // header_H
