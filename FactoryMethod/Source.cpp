#include <iostream>
#include <string>
using namespace std;


/*
Фабричный метод (Factory Method) — порождающий шаблон проектирования, предоставляющий подклассам интерфейс для создания экземпляров некоторого класса.
В момент создания наследники могут определить, какой класс инстанциировать. Иными словами, фабрика делегирует создание объектов наследникам родительского класса.
Это позволяет использовать в коде программы не специфические классы, а манипулировать абстрактными объектами на более высоком уровне.
Фабричный метод  определяет интерфейс для создания объекта, но оставляет подклассам решение о том, какой класс инстанциировать.

Применимость
-	классу заранее неизвестно, объекты каких подклассов ему нужно создавать.
-	класс спроектирован так, чтобы объекты, которые он создаёт, специфицировались подклассами.
-	класс делегирует свои обязанности одному из нескольких вспомогательных подклассов, и планируется локализовать знание о том, какой класс принимает эти обязанности на себя.

Достоинство
Фабричные методы избавляют проектировщика от необходимости встраивать в код зависящие от приложения классы. Код имеет дело только с интерфейсом
класса Product, поэтому он может работать с любыми определенными пользователями классами конкретных продуктов.
Недостаток
Потенциальный недостаток фабричного метода состоит в том, что клиентам, возможно, придется создавать подкласс класса Creator для создания лишь одного объекта ConcreteProduct.
*/

//продукт (House) определяет интерфейс объектов, создаваемых фабричным методом
class Figure abstract
{
protected:
	int geometry[4][4]; //размерность массива указана, поэтому массив статический
	int color[3];
	string name;
public:
	virtual void SetGeometry() = 0;
	virtual void SetColor() = 0;
	virtual void SetName() = 0;
	virtual void showFigure() = 0;
};

// Конкретный продукт реализует интерфейс Product (в нашем случае, House)
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

// Конкретный продукт реализует интерфейс Product (в нашем случае, House)
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


// Creator объявляет фабричный метод, возвращающий объект типа Product.
// абстрактный класс строительной компании
class Developer abstract
{
	// фабричный метод
public:
	virtual Figure* Create() = 0;
};

// конкретный создатель замещает фабричный метод, возвращающий объект ConcreteProduct.
// строит панельные дома
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

// конкретный создатель замещает фабричный метод, возвращающий объект ConcreteProduct.
// строит деревянные дома
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

// Паттерн позволяет использовать в клиентском коде программы не специфические классы, а манипулировать абстрактными объектами на более высоком уровне.
//Figure* Client(Developer *pDev)
//{
//	return pDev->Create();
//}

void Factory(Developer** creators, int size)
{
	// Создатель «полагается» на свои подклассы в определении фабричного метода, который будет возвращать экземпляр подходящего конкретного продукта.
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
