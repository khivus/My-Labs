#include "pch.h"
//#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Geometry/Geometry.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace MathTest
{
	TEST_CLASS(GeometryTests)
	{
	public:
		TEST_METHOD(RectangleS3_5_15)
		{
			// �������� ������
			int a = 3;
			int b = 5;
			int expected = 15;
			// ��������� �������� � ������� ������������ ������
			CGeometry g;
			int actual = g.RectangleArea(a, b);
			// ��������� ���������� ���������� � ����������
			Assert::AreEqual(expected, actual);
		}
	};
}
