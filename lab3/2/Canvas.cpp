#include "Canvas.h"
#include <iostream> 
using namespace std;
Canvas::Canvas(int width, int height)
{
    cwidth = width;
    cheight = height;
    canvas = new char[cwidth*cheight];
}
void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
    int ny;
    for (int i = x - ray; i <= x + ray; i++) {
        ny = sqrt(pow(ray, 2) - pow(i - x, 2)) + y;
        SetPoint(i, ny, ch);
        SetPoint(i, 2*y-ny, ch);
    }

}

void Canvas::FillCircle(int x, int y, int ray, char ch){

    int ny;
    for (int i = x - ray; i <= x + ray; i++) {
        ny = sqrt(pow(ray, 2) - pow(i - x, 2)) + y;
        
        for (int j = 2 * y - ny; j <= ny; j++) {
            SetPoint(i, j, ch);
        }
    } 
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    for (int i = left; i < right; i++) {
        SetPoint(i, top, ch);
        SetPoint(i, bottom, ch);
    }
    for (int i = top; i <= bottom; i++) {
        SetPoint(left, i, ch);
        SetPoint(right,i, ch);
    }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    for (int i = left; i < right; i++) {
        for (int j= top; j <= bottom; j++) {
            SetPoint(i, j, ch);
        }
    }
}

void Canvas::SetPoint(int x, int y, char ch)
{
    if (x >= 0 && x < cwidth && y >= 0 && y < cheight) {
        canvas[y * cwidth + x] = ch;
    }
    
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    int dx, dy, pk,decide;

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    if (dx > dy) {
        decide = 0;   
        int pk = 2 * dy - dx;
        for (int i = 0; i <= dx; i++) {
            x1 < x2 ? x1++ : x1--;
            if (pk < 0) {
                if (decide == 0) {
                    SetPoint(x1, y1, ch);
                    pk = pk + 2 * dy;
                }
                else {
                    SetPoint(x1, y1, ch);
                    pk = pk + 2 * dy;
                }
            }
            else {
                y1 < y2 ? y1++ : y1--;
                if (decide == 0) {
                    SetPoint(x1, y1, ch);
                }
                else {
                    SetPoint(x1, y1, ch);

                }
                pk = pk + 2 * dy - 2 * dx;
            }
        }
    }
    else {
        decide = 1;
        int temp = x1;
        x1 = y1;
        y1 = temp;
        temp = x2;
        x2 = y2;
        y2 = temp; 
        temp = dx;
        dx = dy;
        dy = temp;

        int pk = 2 * dy - dx;
        for (int i = 0; i <= dx; i++) {
            x1 < x2 ? x1++ : x1--;
            if (pk < 0) {
                if (decide == 0) {
                    SetPoint(x1, y1, ch);
                    pk = pk + 2 * dy;
                }
                else {
                    SetPoint(x1, y1, ch);
                    pk = pk + 2 * dy;
                }
            }
            else {
                y1 < y2 ? y1++ : y1--;
                if (decide == 0) {
                    SetPoint(x1, y1, ch);
                }
                else {
                    SetPoint(x1, y1, ch);

                }
                pk = pk + 2 * dy - 2 * dx;
            }
        }
    }
}

void Canvas::Print()
{
    for (int i = 0; i < cheight; i++) {
        for (int j = 0; j < cwidth; j++) {
            printf("%c", canvas[i*cwidth+j]);
        }
        printf("\n");
    }
}

void Canvas::Clear()
{
    for (int i = 0; i < cheight; i++) {
        for (int j = 0; j < cwidth; j++) {
            SetPoint(j, i, 32);
        }
    }
}
