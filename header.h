#ifndef header_H
#define header_H

#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <malloc.h>
#include <math.h>
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

#define Nil NULL
#define Simbol(P) (P)->simbol
#define Info(P)  (P)->info
#define Next(P)  (P)->next
#define baris(P) (P)->baris
#define First(L) (L).First

using namespace std;

#endif // header_H
