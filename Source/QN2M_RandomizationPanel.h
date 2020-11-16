/*
  ==============================================================================

    QN2M_RandomizationPanel.h
    Created: 28 Oct 2020 12:36:15am
    Author:  Patrick Tumulty

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class QN2M_RandomizationPanel  : public juce::Component
{
public:
    QN2M_RandomizationPanel();
    ~QN2M_RandomizationPanel() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    
    juce::Slider randTempo;
    juce::Slider randSpace;
    
    juce::Label randLabel;
    juce::Label spaceLabel;
    juce::Label tempoLabel;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (QN2M_RandomizationPanel)
};
