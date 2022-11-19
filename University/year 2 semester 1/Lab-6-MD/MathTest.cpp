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
			// исходные данные
			int a = 3;
			int b = 5;
			int expected = 15;
			// получение значения с помощью тестируемого метода
			CGeometry g;
			int actual = g.RectangleArea(a, b);
			// сравнение ожидаемого результата с полученным
			Assert::AreEqual(expected, actual);
		}
	};
}
