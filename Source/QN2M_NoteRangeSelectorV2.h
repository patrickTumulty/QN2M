/*
  ==============================================================================

    QN2M_NoteRangeSelectorV2.h
    Created: 3 Nov 2020 6:30:31pm
    Author:  Patrick Tumulty

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class QN2M_NoteRangeSelectorV2  : public juce::Component,
                                    public juce::Slider::Listener
{
public:
    QN2M_NoteRangeSelectorV2();
    ~QN2M_NoteRangeSelectorV2() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    void sliderValueChanged (juce::Slider *slider) override;
    
  

    
private:
    juce::Slider rangeSlider;
    juce::Slider centerSlider;
    
    juce::Image keyboard;
    
    int maxWidth { 108 };
    int initX { 1 };
    
    float widthScalar;
    float xScalar;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (QN2M_NoteRangeSelectorV2)
};
