#include <iostream>
#include <string>
#include <algorithm>

void twoDShape();
void threeDShape();

class Moveable {
	public:
		int move(int move1, int move2){
			return 0;
		}
		std::string messageTwo = " classes. The shape you just calculated the area for is: ";
};

class Shape {
	public:
		std::string messageOne = "This is a message comprised of two inherited";

	protected:
		float vari1;
		float vari2;
};

class MoveableShape : public Moveable, public Shape {
	public:
		std::string returnMessage(){
			std::string fullMessage = messageOne + messageTwo;
			return fullMessage;
		}
};

class twoDShape : public Shape {
	public:
		void setVariable1(float x) {
			vari1 = x;

		}

		void setVariable2(float y) {
			vari2 = y;
		}
};

class threeDShape : public Shape {
public:
	void setVariable1(float x) {
		vari1 = x;
	}

	void setVariable2(float y) {
		vari2 = y;
	}
};

class Circle : public twoDShape {
	public:
		double getArea() {
			double pi = 3.14159;
			return (pi * (vari1 * vari1));
		}

		std::string getName() {
			return ("Circle");
		}
};

class Rectangle : public twoDShape {
	public:
		double getArea() {
			return (vari1 * vari2);
		}

		std::string getName() {
			return ("Rectangle");
		}
};

class Triangle : public twoDShape {
	public:
		double getArea() {
			return ((vari1 * vari2)/2);
		}

		std::string getName() {
			return ("Triangle");
		}
};

class Sphere : public threeDShape {
public:
	double getArea() {
		double pi = 3.14159;
		return (4 * (pi * (vari1 * vari1)));
	}

	std::string getName() {
		return ("Sphere");
	}
};

class Cube : public threeDShape {
	public:
		double getArea() {
			return (6 * (vari1 * vari2));
		}

		std::string getName() {
			return ("Cube");
		}
};

class Tetrahedron : public threeDShape {
	public:
		double getArea() {
			return (4 * ((vari1 * vari2) / 2));
		}

		std::string getName() {
			return ("Tetrahedron");
		}
};

int main() {
	int firstChoice;
	firstChoice = 0;

	std::cout << "Would you like to calculate for a 2D or 3D shape? Put either '2' or '3' in as input. Enter '0' to exit the program.\n";
	std::cin >> firstChoice;

	if ((firstChoice != 2) && (firstChoice != 3) && (firstChoice != 0)) {
		std::cout << "That is not a valid input. Please try again.\n";
		main();
	}

	else if (firstChoice == 2) {
		twoDShape();
		main();
	}
	
	else if (firstChoice == 3){
			threeDShape();
			main();
	}

	else if (firstChoice == 0) {
		std::cout << "Thank you for using the program.\n";
	}
}

void twoDShape() {
	Circle Cir{};
	Rectangle Rect{};
	Triangle Tri{};
	MoveableShape Move{};
	std::string secondChoice;
	std::string shapeName;
	float input2 = 0;
	float input1 = 0;

	std::cout << "What shape would you like to calculate the area for?\n";
	std::cout << "Please enter either 'rectangle', 'triangle', or 'circle'.\n";
	std::cin >> secondChoice;
	transform(secondChoice.begin(), secondChoice.end(), secondChoice.begin(), ::tolower);

	if (secondChoice == "circle") {
		std::cout << "Please enter the length of the circle's radius.\n";
		std::cin >> input1;
		if (input1 > 0) {
			Cir.setVariable1(input1);
			std::cout << "The total area is: " << Cir.getArea() << "\n";
			shapeName = Cir.getName();
			std::cout << Move.returnMessage() + shapeName + "\n";
		}
		else {
			std::cout << "This shape cannot exist. Please try again. \n";
			twoDShape();
		}
	}

	else if (secondChoice == "rectangle") {
		std::cout << "Please enter the length of the rectangle.\n";
		std::cin >> input1;
		std::cout << "Please enter the width of the rectangle.\n";
		std::cin >> input2;
		if ((input1 > 0) && (input2 > 0)) {
			Rect.setVariable1(input1);
			Rect.setVariable2(input2);
			std::cout << "The total area is: " << Rect.getArea() << "\n";
			shapeName = Rect.getName();
			std::cout << Move.returnMessage() + shapeName + "\n";
		}
		else {
			std::cout << "This shape cannot exist. Please try again. \n";
			twoDShape();
		}
	}

	else if (secondChoice == "triangle") {
		std::cout << "Please enter the base length of the triangle.\n";
		std::cin >> input1;
		std::cout << "Please enter the height of the rectangle.\n";
		std::cin >> input2;
		if ((input1 > 0) && (input2 > 0)) {
			Tri.setVariable1(input1);
			Tri.setVariable2(input2);
			std::cout << "The total area is: " << Tri.getArea() << "\n";
			shapeName = Tri.getName();
			std::cout << Move.returnMessage() + shapeName + "\n";
		}
		else {
			std::cout << "This shape cannot exist. Please try again. \n";
			twoDShape();
		}
	}

	else {
		std::cout << "That is not a valid input. Please try again.";
		twoDShape();
	}


}

void threeDShape() {
	Sphere Sphere{};
	Cube Cube{};
	Tetrahedron Tetra{};
	MoveableShape Move{};
	std::string secondChoice;
	std::string shapeName;
	float input1 = 0;
	float input2 = 0;

	std::cout << "What 3D shape would you like to calculate the area for?\n";
	std::cout << "Please enter either 'sphere', 'cube', or 'tetra' (for tetrahedron).\n";
	std::cin >> secondChoice;
	transform(secondChoice.begin(), secondChoice.end(), secondChoice.begin(), ::tolower);

	if (secondChoice == "sphere") {
		std::cout << "Please enter the length of the sphere's radius.\n";
		std::cin >> input1;
		Sphere.setVariable1(input1);
		if (input1 > 0) {
			std::cout << "The total area is: " << Sphere.getArea() << "\n";
			shapeName = Sphere.getName();
			std::cout << Move.returnMessage() + shapeName + "\n";
		}
		else {
			std::cout << "This shape cannot exist. Please try again.\n";
			twoDShape();
		}
	}

	else if (secondChoice == "cube") {
		std::cout << "Please enter the length of the cube.\n";
		std::cin >> input1;
		std::cout << "Please enter the width of the cube.\n";
		std::cin >> input2;
		if ((input1 > 0) && (input2 > 0)) {
			Cube.setVariable1(input1);
			Cube.setVariable2(input2);
			std::cout << "The total area is: " << Cube.getArea() << "\n";
			shapeName = Cube.getName();
			std::cout << Move.returnMessage() + shapeName + "\n";
		}
		else {
			std::cout << "This shape cannot exist. Please try again.\n";
			twoDShape();
		}
	}

	else if (secondChoice == "tetra") {
		std::cout << "Please enter the base length of one of the faces of the tetrahedron.\n";
		std::cin >> input1;
		std::cout << "Please enter the height of one of the faces of the tetrahedron.\n";
		std::cin >> input2;
		if ((input1 > 0) && (input2 > 0)) {
			Tetra.setVariable1(input1);
			Tetra.setVariable2(input2);
			std::cout << "The total area is: " << Tetra.getArea() << "\n";
			shapeName = Tetra.getName();
			std::cout << Move.returnMessage() + shapeName + "\n";
		}
		else {
			std::cout << "This shape cannot exist. Please try again.\n";
			twoDShape();
		}
	}

	else {
		std::cout << "That is not a valid input. Please try again.";
		threeDShape();
	}
}