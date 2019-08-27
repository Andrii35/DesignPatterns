#include"struct.h"

int main() {

	NewRectangle* rect = new RectangleAdapter("red",13, 17, 24, 29);
	rect->Draw();
	delete rect;
	system("pause");
}