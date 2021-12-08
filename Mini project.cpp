// Mini Project

// Design and implement game / animation clip / Graphics Editor using open source 
// graphics library. Make use of maximum features of Object Oriented Programming.
//  Software used Turbo cpp

#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <graphics.h>

// Animation class
class Animation
{
// private variables can be accessed by the class member functions
private:
    int x, i, j, k;

// Public member functions accessed publically
public:
    Animation();
    void cycle();
    void road(int);
    void mountain(int);
    void sun(int);
    void background(int);
    void child1_open(int);
    void child2_open(int);
    void text();
    void Close();
    void scene();
};

// ---------------------------------------------------------------------

// Default Constructor
Animation::Animation()
{
    x = 0;
}

// ---------------------------------------------------------------------

// In this function it it display count down as 3 2 1 with text
void Animation::text()
{
    for (i = 0; i < 50; i++)
    {
        settextstyle(3, HORIZ_DIR, 4);
        outtextxy(150, 150, "Cycle Animation Begins");
        settextstyle(3, HORIZ_DIR, 10);
        outtextxy(270, 200, "3");
        setcolor(RED);
        delay(30);
        cleardevice();
    }

    for (j = 0; j < 30; j++)
    {
        settextstyle(3, HORIZ_DIR, 4);
        outtextxy(150, 150, "Cycle Animation Begins");
        settextstyle(3, HORIZ_DIR, 10);
        outtextxy(270, 200, "2");
        setcolor(YELLOW);
        delay(50);
        cleardevice();
    }

    for (k = 0; k < 20; k++)
    {
        settextstyle(3, HORIZ_DIR, 4);
        outtextxy(150, 150, "Cycle Animation Begins");
        settextstyle(3, HORIZ_DIR, 10);
        outtextxy(270, 200, "1");
        setcolor(GREEN);
        delay(50);
        cleardevice();
    }
}

// ---------------------------------------------------------------------

// Drew Boy
void Animation::child1_open(int color)
{
    // Boy
    for (i = 0; i < 3; i++)
    {
        setcolor(color);
        circle(100, 320, 30);
        line(100 + i, 350, 100 + i, 400);
        // legs
        line(100 + i, 400, 80 + i, 450);
        line(100 + i, 400, 120 + i, 450);
        // left hand
        line(100 + i, 360, 70 + i, 400);
        // right hand
        line(100, 360 + i, 130, 400 + i);
    }
}

// ---------------------------------------------------------------------

// Drew Girl
void Animation::child2_open(int color)
{
    // Girl
    for (i = 0; i < 2; i++)
    {
        setcolor(color);
        circle(550, 320, 30);
        // dress
        line(550 + i, 350, 540 + i, 400);
        line(550 + i, 350, 560 + i, 400);
        line(540, 400 - i, 560, 400 - i);
        // legs
        line(550 + i, 400, 530 + i, 450);
        line(550 + i, 400, 570 + i, 450);
        // left hand
        line(550 + i, 350, 520 + i, 400);
        // right hand
        line(550 + i, 350, 580 + i, 400);
    }
}

// ---------------------------------------------------------------------

// Drew Road and colored it
void Animation::road(int color)
{
    setcolor(color);
    line(0, 401, 660, 401);
    for (j = 0; j < 5; j++)
    {
        rectangle(10, 440 + j, 40, 445 + j);
        rectangle(70, 440 + j, 100, 445 + j);
        rectangle(130, 440 + j, 160, 445 + j);
        rectangle(190, 440 + j, 220, 445 + j);
        rectangle(250, 440 + j, 280, 445 + j);
        rectangle(310, 440 + j, 340, 445 + j);
        rectangle(370, 440 + j, 400, 445 + j);
        rectangle(430, 440 + j, 460, 445 + j);
        rectangle(490, 440 + j, 520, 445 + j);
        rectangle(550, 440 + j, 580, 445 + j);
        rectangle(610, 440 + j, 640, 445 + j);
    }
    setcolor(WHITE);
}

// ---------------------------------------------------------------------

// Drew Mountain and colored it
void Animation::mountain(int color)
{
    setcolor(color);
    for (j = 0; j < 3; j++)
    {
        line(0, 199 + j, 200, 100 + j);
        arc(220, 157 + j, 49, 118, 60);
        line(259, 112 + j, 460, 300 + j);
        line(353, 200 + j, 600, 60 + j);
        arc(625, 115 + j, 49, 118, 60);
    }
    setcolor(WHITE);
}

// ---------------------------------------------------------------------

// Drew Sun and colored it
void Animation::sun(int color)
{
    setcolor(color);
    for (j = 0; j < 3; j++)
    {
        arc(356, 200 + j, 33, 139, 40);
        line(327, 169 + j, 300, 140 + j);
        line(335, 165 + j, 322, 148 + j);
        line(345, 162 + j, 327, 129 + j);
        line(355, 160 + j, 348, 137 + j);
        line(365, 161 + j, 367, 124 + j);
        line(375, 164 + j, 382, 137 + j);
        line(381, 168 + j, 410, 134 + j);
        line(387, 172 + j, 413, 157 + j);
    }
    setcolor(WHITE);
}

// ---------------------------------------------------------------------

// Background Decor
void Animation::background(int color)
{
    for (x = 0; x < 3; x++)
    {
        // Mountain
        mountain(2);

        // Sun
        sun(14);

        // Wheels
        circle(40, 370 + x, 30);
        circle(150, 370 + x, 30);

        // Body of cycle
        line(40, 370 + x, 100, 370 + x);
        line(40, 370 + x, 60, 340 + x);
        line(100, 370 + x, 120, 340 + x);
        line(120, 340 + x, 60, 340 + x);
        line(60, 340 + x, 60, 335 + x);
        line(55, 335 + x, 65, 335 + x);
        line(150, 370 + x, 100, 320 + x);
        line(100, 320 + x, 90, 320 + x);

        setcolor(color);
        delay(20);
    }
}

// ---------------------------------------------------------------------

// Cycle animation
void Animation::cycle()
{
    // Cycle is moving
    for (x = 0; x < 450; x++)
    {
        // Wheels
        circle(40 + x, 370, 30);
        circle(150 + x, 370, 30);

        // Body of cycle
        line(40 + x, 370, 100 + x, 370);
        line(40 + x, 370, 60 + x, 340);
        line(100 + x, 370, 120 + x, 340);
        line(120 + x, 340, 60 + x, 340);
        line(60 + x, 340, 60 + x, 335);
        line(55 + x, 335, 65 + x, 335);
        line(150 + x, 370, 100 + x, 320);
        line(100 + x, 320, 90 + x, 320);

        // Road
        road(6);

        // mountain
        mountain(2);

        // Sun
        sun(14);

        setcolor(WHITE);
        delay(20);
        cleardevice();
    }
}

// ---------------------------------------------------------------------

// Closing text 
void Animation::Close()
{
    // Here we are setting text style
    settextstyle(7, HORIZ_DIR, 8);
    // Printing text in graphics window
    outtextxy(100, 150, "Thank you");
}

// ---------------------------------------------------------------------

// One scene called function here
void Animation::scene()
{
    background(2);
    cycle();
}

// ---------------------------------------------------------------------

// Main function
void main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C://TurboC3/BGI");
    cleardevice();

    Animation ob;
    ob.text();
    ob.scene();
    cleardevice();
    ob.Close();
    ob.child1_open(15);
    ob.child2_open(15);

    getch();
    closegraph();
}

// ----------------------------------End of Program----------------------------------
