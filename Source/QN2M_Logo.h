/*
  ==============================================================================

    QN2M_Logo.h
    Created: 27 Oct 2020 11:27:22am
    Author:  Patrick Tumulty

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class QN2M_Logo  : public juce::Component
{
public:
    QN2M_Logo();
    ~QN2M_Logo() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    juce::Image mLogo;
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (QN2M_Logo)
};
