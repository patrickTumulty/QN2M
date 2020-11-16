/*
  ==============================================================================

    QN2M_NoteRangeSelector.h
    Created: 27 Oct 2020 10:18:43am
    Author:  Patrick Tumulty

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class QN2M_NoteRangeSelector  : public juce::Component,
                                public juce::Slider::Listener
{
public:
    QN2M_NoteRangeSelector (Qn2mAudioProcessor&);
    ~QN2M_NoteRangeSelector() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    void sliderValueChanged (juce::Slider * slider) override;

private:
//    juce::Slider rangeSlider;
    
    juce::Slider rangeHighSlider;
    juce::Slider rangeLowSlider;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> mRangeSliderAttachment;
    
    juce::Label rangeLabel;
    juce::Label rangeHighLabel;
    juce::Label rangeLowLabel;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (QN2M_NoteRangeSelector)
};
