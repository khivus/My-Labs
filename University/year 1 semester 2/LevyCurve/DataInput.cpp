#include "DataInput.h"
#include "DataIterations.h"
#include "MyForm.h"

System::Void LevyCurve::DataInput::OkButton_Click(System::Object^ sender, System::EventArgs^ e) // save data from numupdown
{
    DataIterations::num_iterations = Convert::ToInt32(IterationsGet->Value);
}

System::Void LevyCurve::DataInput::CancelButton_Click(System::Object^ sender, System::EventArgs^ e) // resets data
{
    if (DataIterations::num_iterations != 0) {
        IterationsGet->Value = Convert::ToDecimal(DataIterations::num_iterations);
    }
}

System::Void LevyCurve::DataInput::DataInput_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) // resets data
{
    if (DataIterations::num_iterations != 0) {
        IterationsGet->Value = Convert::ToDecimal(DataIterations::num_iterations);
    }
}
