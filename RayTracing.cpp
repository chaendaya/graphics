#include <iostream>
using namespace std;

class Vector {

private:
	float x, y, z;

public:
	Vector() { x = 0; y = 0; z = 0; }
	~Vector() = default;
	Vector(float a, float b, float c) {	x = a; y = b; z = c; }

public:
	void PrintVector(void)
	{
		cout << "( " << x << ", " << y << ", " << z << " )" << endl;
	}

	Vector operator + (Vector p)
	{
		return Vector(x + p.x, y + p.y, z + p.z);
	}

	Vector operator - (Vector p)
	{
		return Vector(x - p.x, y - p.y, z - p.z);
	}

	float Dot(Vector v)
	{
		return (x * v.x + y * v.y + z * v.z);
	}

	Vector Cross(Vector v)
	{
		return Vector(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
	}

	Vector operator /(float k)
	{
		return Vector(x / k, y / k, z / k);
	}
	
	Vector operator *(float k)
	{
		return Vector(x * k, y * k, z * k);
	}
};


int main() {

	cout << " 1. �ﰢ���� ���� : " << endl;

	Vector P0(0, 0, 0);
	Vector P1(-1, 5, 0);
	Vector P2(1, 0, 5);

	Vector P0P1 = P1 - P0;
	Vector P0P2 = P2 - P0;

	Vector N = P0P1.Cross(P0P2);
	cout << "    (1) �ﰢ���� ���� ����" << endl;
	cout << "         N = ";
	N.PrintVector();
	cout << endl;

	float k = N.Dot(N);

	Vector U = P0P2.Cross(N) / k;
	cout << "    (2) ��� ����" << endl;
	cout << "         U = ";
	U.PrintVector();
	cout << endl;


	Vector V = N.Cross(P0P1) / k;
	cout << "    (3) ��� ����" << endl;
	cout << "         V = ";
	V.PrintVector();
	cout << endl << endl;

	
	cout << " 2. �� ������ ���� ���� : " << endl;

	Vector O(5, 1, 1);
	Vector V1(-1, 0, 0);
	Vector V2(-1, 1, 1);

	float t1 = (P0 - O).Dot(N) / V1.Dot(N);
	float t2 = (P0 - O).Dot(N) / V2.Dot(N);

	Vector P__1 = O + V1 * t1;
	Vector P__2 = O + V2 * t2;
	cout << "    (1) ������ �ﰢ�� ����� ���� " << endl;
	cout << "        V1�� ���� ���� P1 = ";
	P__1.PrintVector();
	cout << "        V2�� ���� ���� P2 = ";
	P__2.PrintVector();
	cout << endl;
	cout << endl;

	
	cout << "    (2) �������� �����ϴ� �Ǽ� (u,v) " << endl;
	float u1 = (P__1 - P0).Dot(U);
	float v1 = (P__1 - P0).Dot(V);
	cout << "        1�� ���� : ( " << u1 << ", " << v1 << " )" << endl;

	float u2 = (P__2 - P0).Dot(U);
	float v2 = (P__2 - P0).Dot(V);
	cout << "        2�� ���� : ( " << u2 << ", " << v2 << " )" << endl;
	cout << endl;


	cout << "    (3) ������ �ﰢ���� ���� ���� " << endl;

	if (u1 > 0 && v1 > 0 && u1 + v1 < 1) 
		cout << "        1�� ������ �����Ѵ� " << endl;
	else
		cout << "        1�� ������ �������� �ʴ´� " << endl;


	if (u2 > 0 && v2 > 0 && u2 + v2 < 1) 
		cout << "        2�� ������ �����Ѵ� " << endl;
	else
		cout << "        2�� ������ �������� �ʴ´� " << endl;




}