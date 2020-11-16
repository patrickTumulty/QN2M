/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "QN2M_MainPanel.h"
#include "QN2M_PianoDisplay.h"
#include "QN2M_NoteRangeSelectorV2.h"

//==============================================================================
/**
*/
class Qn2mAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    Qn2mAudioProcessorEditor (Qn2mAudioProcessor&);
    ~Qn2mAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    QN2M_MainPanel mainPanel;
    
//    QN2M_PianoDisplay piano;
//    QN2M_NoteRangeSelectorV2 noteRangeSelector;
    
    Qn2mAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Qn2mAudioProcessorEditor)
};
