/* This class connects an audio parameter to a faust dsp instance. The faust
 * dsp parameters are automatically updated when the parameter is changed */

#include "JuceHeader.h"

class MapUI;

class FaustParameterFloat : public juce::AudioParameterFloat
{
    public:
        FaustParameterFloat(MapUI** faustUI, String parameterID, String parameterName, float minValue, float maxValue, float defaultValue);
    protected:
        virtual void valueChanged(float newValue) override;
    private:
        MapUI** faustUI;
};
