#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p)
{
    juce::ignoreUnused (processorRef);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);

    gainLabel.setText("Gain", juce::dontSendNotification);
    toneLabel.setText("Tone", juce::dontSendNotification);
    volumeLabel.setText("Volume", juce::dontSendNotification);

    gainAttachment.reset(new SliderAttachment(processorRef.parameters, "gain", gainSlider));
    toneAttachment.reset(new SliderAttachment(processorRef.parameters, "tone", toneSlider));
    volumeAttachment.reset(new SliderAttachment(processorRef.parameters, "volume", volumeSlider));

    addAndMakeVisible(gainLabel);
    addAndMakeVisible(toneLabel);
    addAndMakeVisible(volumeLabel);

    addAndMakeVisible(gainSlider);
    addAndMakeVisible(toneSlider);
    addAndMakeVisible(volumeSlider);
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor()
{
}

//==============================================================================
void AudioPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void AudioPluginAudioProcessorEditor::resized()
{
    auto area = getLocalBounds();

    auto row = area.removeFromTop(100);
    gainLabel.setBounds(row.removeFromLeft(200));
    gainSlider.setBounds(row);

    row = area.removeFromTop(100);
    toneLabel.setBounds(row.removeFromLeft(200));
    toneSlider.setBounds(row);

    row = area.removeFromTop(100);
    volumeLabel.setBounds(row.removeFromLeft(200));
    volumeSlider.setBounds(row);
}
