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
