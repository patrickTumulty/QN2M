/*
  ==============================================================================

    QN2M_MainPanel.h
    Created: 25 Oct 2020 12:01:55am
    Author:  Patrick Tumulty

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "QN2M_KeyboardButtons.h"
#include "QN2M_NoteRangeSelector.h"
#include "QN2M_Logo.h"
#include "QN2M_NoteRangeSelectorV2.h"
#include "QN2M_RandomizationPanel.h"

//==============================================================================
/*
*/
class QN2M_MainPanel  : public juce::Component
{
public:
    QN2M_MainPanel (Qn2mAudioProcessor&);
    ~QN2M_MainPanel() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    QN2M_KeyboardButtons keyBoard;
//    QN2M_NoteRangeSelector rangeSelector;
    QN2M_NoteRangeSelectorV2 rangeSelector;
    QN2M_Logo mainLogo;
    QN2M_RandomizationPanel randomizationPanel;

    
    juce::TextButton startButton; 
    
    juce::ComboBox tempoSelector;
    juce::Label tempoLabel;
    
    juce::Image mLogo;
    juce::Image mBackground;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (QN2M_MainPanel)
};
