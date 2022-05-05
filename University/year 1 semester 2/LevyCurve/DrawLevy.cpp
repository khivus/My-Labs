#include "DrawLevy.h"
#include "DataIterations.h"

#include <math.h>

#define PI 3.1415

System::Void LevyCurve::DrawLevy::draw_levy(float x, float y, float length, float alpha, int iteration) {
	Graphics^ gfx = pictureBox1->CreateGraphics();
	float rads = 0;
	if (iteration > 0) {
		length = length / sqrt(2);
		draw_levy(x, y, length, alpha + 45, iteration - 1);
		rads = rads + (alpha + 45) * PI / 180;
		x = x + length * cos(rads);
		y = y + length * sin(rads);
		draw_levy(x, y, length, alpha - 45, iteration - 1);
	}
	else {
		rads = rads + alpha * PI / 180;
		gfx->DrawLine(Pens::Black, x, y, x + length * cos(rads), y + length * sin(rads));
	}
}

System::Void LevyCurve::DrawLevy::button1_Click(System::Object^ sender, System::EventArgs^ e) {

	if (DataIterations::num_iterations != 0) {
		int iterations = DataIterations::num_iterations;
		float x = pictureBox1->Width / 3;
		float y = pictureBox1->Height / 3;
		float length = 200;
		float alpha = 0;

		draw_levy(x, y, length, alpha, iterations);
	}
}

System::Void LevyCurve::DrawLevy::ExitButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
