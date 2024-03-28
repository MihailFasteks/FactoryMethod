#include <iostream>
#include <string>
using namespace std;


/*
��������� ����� (Factory Method) � ����������� ������ ��������������, ��������������� ���������� ��������� ��� �������� ����������� ���������� ������.
� ������ �������� ���������� ����� ����������, ����� ����� ���������������. ����� �������, ������� ���������� �������� �������� ����������� ������������� ������.
��� ��������� ������������ � ���� ��������� �� ������������� ������, � �������������� ������������ ��������� �� ����� ������� ������.
��������� �����  ���������� ��������� ��� �������� �������, �� ��������� ���������� ������� � ���, ����� ����� ���������������.

������������
-	������ ������� ����������, ������� ����� ���������� ��� ����� ���������.
-	����� ������������� ���, ����� �������, ������� �� ������, ����������������� �����������.
-	����� ���������� ���� ����������� ������ �� ���������� ��������������� ����������, � ����������� ������������ ������ � ���, ����� ����� ��������� ��� ����������� �� ����.

�����������
��������� ������ ��������� �������������� �� ������������� ���������� � ��� ��������� �� ���������� ������. ��� ����� ���� ������ � �����������
������ Product, ������� �� ����� �������� � ������ ������������� �������������� �������� ���������� ���������.
����������
������������� ���������� ���������� ������ ������� � ���, ��� ��������, ��������, �������� ��������� �������� ������ Creator ��� �������� ���� ������ ������� ConcreteProduct.
*/

//������� (House) ���������� ��������� ��������, ����������� ��������� �������
class Figure abstract
{
protected:
	int geometry[4][4]; //����������� ������� �������, ������� ������ �����������
	int color[3];
	string name;
public:
	virtual void SetGeometry() = 0;
	virtual void SetColor() = 0;
	virtual void SetName() = 0;
	virtual void showFigure() = 0;
};

// ���������� ������� ��������� ��������� Product (� ����� ������, House)
class Square : public Figure
{
public:
	void SetGeometry()override 
	{
		geometry[1][1] = 1;
		geometry[1][2] = 1;
		geometry[2][1] = 1;
		geometry[2][2] = 1;
	}
	void SetColor()override {
		color[0] = 1;
		color[1] = 1;
		color[2] = 1;
	}
	void SetName()override {
		name = "square";
	}
	void showFigure()override {
		cout << "RGB color: " << color[0] << " " << color[1] << " " << color[2] << endl;
		cout << name << endl;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cout << geometry[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	 }
};

// ���������� ������� ��������� ��������� Product (� ����� ������, House)
class Triangle : public Figure
{
public:
	void SetGeometry()override
	{
		geometry[1][2] = 1;
		geometry[2][1] = 1;
		geometry[2][2] = 1;
		geometry[2][3] = 1;
	}
	void SetColor()override {
		color[0] = 1;
		color[1] = 1;
		color[2] = 1;
	}
	void SetName()override {
		name = "triangle";
	}
	void showFigure()override {
		cout << "RGB color: " << color[0] << " " << color[1] << " " << color[2] << endl;
		cout << name << endl;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cout << geometry[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
};

class Rhombus : public Figure
{
public:
	void SetGeometry()override
	{
		geometry[1][2] = 1;
		geometry[2][1] = 1;
		geometry[2][3] = 1;
		geometry[3][2] = 1;
	}
	void SetColor()override {
		color[0] = 1;
		color[1] = 1;
		color[2] = 1;
	}
	void SetName()override {
		name = "rhombus";
	}
	void showFigure()override {
		cout << "RGB color: " << color[0] << " " << color[1] << " " << color[2] << endl;
		cout << name << endl;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cout << geometry[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
};


// Creator ��������� ��������� �����, ������������ ������ ���� Product.
// ����������� ����� ������������ ��������
class Developer abstract
{
	// ��������� �����
public:
	virtual Figure* Create() = 0;
};

// ���������� ��������� �������� ��������� �����, ������������ ������ ConcreteProduct.
// ������ ��������� ����
class SquareDeveloper : public Developer
{
public:
	Figure* Create() override
	{
		/*return new Square;*/
		Figure* figure = new Square();
		figure->SetGeometry();
		figure->SetColor();
		figure->SetName();
		return figure;
	}
};

// ���������� ��������� �������� ��������� �����, ������������ ������ ConcreteProduct.
// ������ ���������� ����
class TriangleDeveloper : public Developer
{
public:
	Figure* Create() override
	{
		/*return new Square;*/
		Figure* figure = new Triangle();
		figure->SetGeometry();
		figure->SetColor();
		figure->SetName();
		return figure;
	}
};
class RhombusDeveloper : public Developer
{
public:
	Figure* Create() override
	{
		/*return new Square;*/
		Figure* figure = new Rhombus();
		figure->SetGeometry();
		figure->SetColor();
		figure->SetName();
		return figure;
	}
};

// ������� ��������� ������������ � ���������� ���� ��������� �� ������������� ������, � �������������� ������������ ��������� �� ����� ������� ������.
//Figure* Client(Developer *pDev)
//{
//	return pDev->Create();
//}

void Factory(Developer** creators, int size)
{
	// ��������� ������������ �� ���� ��������� � ����������� ���������� ������, ������� ����� ���������� ��������� ����������� ����������� ��������.
	for (int i = 0; i < size; i++)
	{
		Figure* pfigure = creators[i]->Create();
		pfigure->showFigure();
	}
}

void main()
{
	/*Developer *pDev = new SquareDeveloper();
	Figure* p = Client(pDev);
	delete pHouse;
	delete pDev;

	pDev = new TriangleDeveloper();
	pHouse = Client(pDev);

	pDev = new RhombusDeveloper();
	pHouse = Client(pDev); 

	delete pHouse;
	delete pDev;

	system("pause");*/
	Developer* creators[3];
	creators[0] = new SquareDeveloper();
	creators[1] = new TriangleDeveloper();
	creators[2] = new RhombusDeveloper();

	Factory(creators, 3);

	system("pause");
}
