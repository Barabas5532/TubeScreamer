#include "FaustParameterFloat.h"
#include "faust/gui/MapUI.h"

FaustParameterFloat::FaustParameterFloat(MapUI** faustUI, String parameterID, String parameterName, float minValue, float maxValue, float defaultValue)
    : AudioParameterFloat(parameterID, parameterName, minValue, maxValue, defaultValue)
{
    this->faustUI = faustUI;
}

void FaustParameterFloat::valueChanged(float newValue)
{
    if(faustUI != nullptr)
    {
        (*faustUI)->setParamValue(AudioParameterFloat::RangedAudioParameter::AudioProcessorParameterWithID::paramID.toStdString(), newValue);
    }
}
