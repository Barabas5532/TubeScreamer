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

#pragma once

#include "PluginProcessor.h"
#include "juce_gui_basics/juce_gui_basics.h"

//==============================================================================
class AudioPluginAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    explicit AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor&);
    ~AudioPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AudioPluginAudioProcessor& processorRef;

    typedef juce::AudioProcessorValueTreeState::SliderAttachment SliderAttachment;

    juce::Label gainLabel;
    juce::Slider gainSlider;
    std::unique_ptr<SliderAttachment> gainAttachment;

    juce::Label toneLabel;
    juce::Slider toneSlider;
    std::unique_ptr<SliderAttachment> toneAttachment;

    juce::Label volumeLabel;
    juce::Slider volumeSlider;
    std::unique_ptr<SliderAttachment> volumeAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioPluginAudioProcessorEditor)
};
