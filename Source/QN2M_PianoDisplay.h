/*
  ==============================================================================

    QN2M_PianoDisplay.h
    Created: 2 Nov 2020 4:24:39pm
    Author:  Patrick Tumulty

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class QN2M_PianoDisplay  : public juce::Component
{
public:
    QN2M_PianoDisplay();
    ~QN2M_PianoDisplay() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (QN2M_PianoDisplay)
};
