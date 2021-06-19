#ifndef header_H
#define header_H

#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <malloc.h>
#include <math.h>
#include <cmath>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#include "linkedlist.h"
#include "maps.h"
#include "umum.h"
#include "menu.h"
#include "permainan.h"
#include "boolean.h"

#define UP_KEY 72
#define DOWN_KEY 80
#define LEFT_KEY 75
#define RIGHT_KEY 77
#define WDT_SCREEN GetSystemMetrics(SM_CXSCREEN)
#define HGT_SCREEN GetSystemMetrics(SM_CYSCREEN)

#define Nil NULL
#define Prev(P)     (P)->prev
#define Info(P)     (P)->info
#define Simbol(P)   (P)->simbol
#define Jump(P)     (P)->jump
#define Next(P)     (P)->next
#define posisi(P)   (P)->posisi
//#define x(P)     (P)->x
//#define y(P)     (P)->y
#define First(L) (L).First
#define Last(L) (L).Last

using namespace std;

#endif // header_H
