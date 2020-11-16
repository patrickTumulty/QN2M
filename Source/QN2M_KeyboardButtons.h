/*
  ==============================================================================

    QN2M_KeyboardButtons.h
    Created: 26 Oct 2020 3:53:25pm
    Author:  Patrick Tumulty

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class QN2M_KeyboardButtons  : public juce::Component
{
public:
    QN2M_KeyboardButtons();
    ~QN2M_KeyboardButtons() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    void noteSelectButtonConfig(juce::TextButton* button, juce::String noteName);

private:
    
    juce::TextButton C_Button;
    juce::TextButton CS_Button;
    juce::TextButton D_Button;
    juce::TextButton DS_Button;
    juce::TextButton E_Button;
    juce::TextButton F_Button;
    juce::TextButton FS_Button;
    juce::TextButton G_Button;
    juce::TextButton GS_Button;
    juce::TextButton A_Button;
    juce::TextButton AS_Button;
    juce::TextButton B_Button;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (QN2M_KeyboardButtons)
};
