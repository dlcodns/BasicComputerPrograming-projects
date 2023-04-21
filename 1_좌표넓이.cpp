#include <iostream>
#include <cmath>
using namespace std;
int main() {
	float a1, b1, a2, b2, a3, b3, a, b, c, x1, y1, x2, y2;
	cout << "<triangle area>\nenter the first coordinate. (a1 and b1) >> ";
	cin >> a1;
	cin >> b1;

	cout << "<triangle area>\nenter the second coordinate. (a2 and b2) >> ";
	cin >> a2;
	cin >> b2;

	cout << "<triangle area>\nenter the third coordinate. (a3 and b3) >> ";
	cin >> a3;
	cin >> b3;

	float a = sqrt(pow((a2 - a1), 2) + pow((b2 - b1), 2));
	float b = sqrt(pow((a3 - a1), 2) + pow((b3 - b1), 2));
	float c = sqrt(pow((a2 - a3), 2) + pow((b2 - b3), 2));

	cout << a, b, c;

	float s = (a + b + c) / 2;
	float t_area = sqrt(float(s * (s - a) * (s - b) * (s - c))); 
	
	cout << "triangle area : " << t_area;
//___________________________________________________________
	cout << "\n\n\n<square area>\nenter the first coordinate. (x1 and y1) >> ";
	cin >> x1;
	cin >> y1;
	
	cout << "enter the second coordinate. (x2 and y2) >> ";
	cin >> x2;
	cin >> y2;

	float base = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
	float s_area = pow(base, 2);

	cout << "square area : " << s_area << std::endl;

	return 0;
}
