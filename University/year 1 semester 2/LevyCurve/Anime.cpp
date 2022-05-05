#include "Anime.h"
#include "DataIterations.h"

#include <math.h>

#define PI 3.1415

System::Void LevyCurve::Anime::animate_levy(float x, float y, float length, float alpha, int iteration) {
	Graphics^ gfx = pictureBox1->CreateGraphics();
	float rads = 0;
	if (iteration > 0) {
		length = length / sqrt(2);
		animate_levy(x, y, length, alpha + 45, iteration - 1);
		rads = rads + (alpha + 45) * PI / 180;
		x = x + length * cos(rads);
		y = y + length * sin(rads);
		animate_levy(x, y, length, alpha - 45, iteration - 1);
	}
	else {
		rads = rads + alpha * PI / 180;
		gfx->DrawLine(Pens::Black, x, y, x + length * cos(rads), y + length * sin(rads));
	}
}

System::Void LevyCurve::Anime::FrameUser_Click(System::Object^ sender, System::EventArgs^ e) {

	if (DataIterations::num_iterations != 0) {

		Graphics^ gfx = pictureBox1->CreateGraphics();
		gfx->Clear(Color::White);

		Animate->Enabled = false;

		counter++;

		IterationNow->Text = Convert::ToString(counter);
		float x = pictureBox1->Width / 3;
		float y = pictureBox1->Height / 3;
		float length = 200;
		float alpha = 0;
		
		animate_levy(x, y, length, alpha, counter);
	}
}

System::Void LevyCurve::Anime::Animate_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (DataIterations::num_iterations != 0) {

		if (timer1->Enabled == false) {
			timer1->Start();
		}
		else {
			timer1->Stop();
		}
		FrameUser->Enabled = false;
	}
}

System::Void LevyCurve::Anime::timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	Graphics^ gfx = pictureBox1->CreateGraphics();
	gfx->Clear(Color::White);
	counter++;
	IterationNow->Text = Convert::ToString(counter);

	float x = pictureBox1->Width / 3;
	float y = pictureBox1->Height / 3;
	float length = 200;
	float alpha = 0;

	animate_levy(x, y, length, alpha, counter);
	
	if (counter >= DataIterations::num_iterations) {
		counter = 0;
		timer1->Stop();
	}
}

System::Void LevyCurve::Anime::ResetButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	Graphics^ gfx = pictureBox1->CreateGraphics();
	gfx->Clear(Color::White);
	timer1->Stop();
	IterationNow->Text = "0";
	counter = 0;
	Animate->Enabled = true;
	FrameUser->Enabled = true;
}

System::Void LevyCurve::Anime::ExitButtonA_Click(System::Object^ sender, System::EventArgs^ e)
{
	Graphics^ gfx = pictureBox1->CreateGraphics();
	gfx->Clear(Color::White);
	timer1->Stop();
	IterationNow->Text = "0";
	counter = 0;
	Animate->Enabled = true;
	FrameUser->Enabled = true;
}
