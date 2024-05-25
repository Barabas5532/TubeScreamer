/* TubeScreamer - Guitar Overdrive pedal simulation created with faust and JUCE
 * Copyright (C) 2021 Barabas Raffai
 *
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

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
