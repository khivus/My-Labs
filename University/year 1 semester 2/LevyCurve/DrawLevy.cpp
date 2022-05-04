#include "DrawLevy.h"

#include <math.h>

#define PI 3.1415

System::Void LevyCurve::DrawLevy::draw_levy(int iterations, float l, float a, float x, float y) {
	float alpha;
	Bitmap^ bm = gcnew Bitmap(ClientSize.Width, ClientSize.Height);
	if (iterations > 0) {
		l = l / sqrt(2);
		draw_levy(iterations - 1, l, (a + 45), x, y);
		alpha = alpha+(a + 45) * PI / 180;
		x = x + l * cos(alpha);
		y = y + l * sin(alpha);
		draw_levy(iterations - 1, l, (a - 45), x, y);
	}
	else {
		alpha = alpha + a * PI / 180;

	}
	pictureBox1->Image = bm;
}

System::Void LevyCurve::DrawLevy::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	int iterations = 10;
	draw_levy(iterations, 250, 0, 400, 300);
}
