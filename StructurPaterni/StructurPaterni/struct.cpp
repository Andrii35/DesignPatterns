#include "struct.h"


Rectangle::Rectangle(int x, int y, int x2, int y2) :x(x), y(y), x2(x2), y2(y2) {

}
void Rectangle::Draw()
{
	cout << "Rectangle drow: " << "(" << x << "," << y << ")" << "," << "(" << x2 << "," << y2 << ")";
}

void RectangleAdapter::Draw()
{

	Rectangle::Draw();
	cout << endl;
	cout<<"Color: "<<NewRectangle::color;
	cout << endl;
}

RectangleAdapter::RectangleAdapter(string color,int x, int y, int w, int h):Rectangle(x,y,x+w,h+y),NewRectangle(color)
{
	
}

NewRectangle::NewRectangle(string color):color(color)
{
}
