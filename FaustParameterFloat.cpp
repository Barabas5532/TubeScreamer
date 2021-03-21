#include "FaustParameterFloat.h"
#include "faust/gui/MapUI.h"
#include <stdio.h>

FaustParameterFloat::FaustParameterFloat(MapUI** faustUI, String parameterID, String parameterName, float minValue, float maxValue, float defaultValue)
    : AudioParameterFloat(parameterID, parameterName, minValue, maxValue, defaultValue)
{
    this->faustUI = faustUI;
}

void FaustParameterFloat::valueChanged(float newValue)
{
    if(*faustUI != nullptr)
    {
        const char *test = AudioParameterFloat::RangedAudioParameter::AudioProcessorParameterWithID::paramID.toStdString().c_str();

        printf("%s: %s %f\n", __FUNCTION__, test, newValue);

        (*faustUI)->setParamValue(test, newValue);
    }
}
