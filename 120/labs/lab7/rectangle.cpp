/*
	Charles Park
	Section 5
	2/28/23
	Lab 7
*/

#include <iostream>

using namespace std;

class Rectangle {
    private:
        int width;
        int height;

    public:
        Rectangle() {
            width = 0;
            height = 0;
        }
        Rectangle(int _width, int _height) {
            width = _width;
            height = _height;
        }

        void setDimensions(int _width, int _height) {
            if (_width < 0) {
                _width = -_width;
            }
            if (_height < 0) {
                _height = -_height;
            }
            width = _width;
            height = _height;
        }

        void print() {
            cout << "width = " << width << "\n"
                 << "height = " << height << "\n";
        }

        void draw() {
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    cout << "* ";
                }
                cout << "\n";
            }
        }
        
        int area() {
            return width*height;
        }
        int perimeter() {
            return 2 * width + 2 * height;
        }
};

int main() {
    Rectangle charles;
    Rectangle april;
    int width, height;
    cout << "Enter the width: ";
    cin >> width;
    cout << "Enter the height: ";
    cin >> height;
    charles.setDimensions(width, height);
    charles.print();
    charles.draw();
    cout << "Area: " << charles.area() << "\n";
    cout << "Perimeter: " << charles.perimeter() << "\n";
}