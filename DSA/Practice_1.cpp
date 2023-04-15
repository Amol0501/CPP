#include<iostream>
using namespace std;

class Rectangle{
    private:
        int length;
        int breadth;
    public:
        void initialize(int l, int b){
            length = l;
            breadth = b;
        }
        int area(){
            return length*breadth;
        }
        int perimeter(){
            return 2*(length + breadth);
        }
};

int main(){
    Rectangle r;
    int l, b;
    cout << "Enter the value of length and breadth of rectangle";
    cin >> l >> b;
    r.initialize(l, b);
    cout << "Area of rectangle is: " << r.area();
    cout << "Perimeter of rectangle is: " << r.perimeter();
    return 0;
}