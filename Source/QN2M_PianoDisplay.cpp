/*
  ==============================================================================

    QN2M_PianoDisplay.cpp
    Created: 2 Nov 2020 4:24:39pm
    Author:  Patrick Tumulty

  ==============================================================================
*/

#include <JuceHeader.h>
#include "QN2M_PianoDisplay.h"

//==============================================================================
QN2M_PianoDisplay::QN2M_PianoDisplay()
{
   

}

QN2M_PianoDisplay::~QN2M_PianoDisplay()
{
}

void QN2M_PianoDisplay::paint (juce::Graphics& g)
{
    int widthOfKey = getWidth() / 52; // 52 White piano keys
    int offsetX = (getWidth() - (widthOfKey * 52)) / 2;
    
 
    juce::Rectangle<int> localArea = getLocalBounds().reduced (offsetX, 5);
    juce::Rectangle<int> currentKey;
    
    for (int i = 0; i < 52; i++) // draw white keys
    {
        currentKey = localArea.removeFromLeft (widthOfKey);
        g.setColour (juce::Colours::ghostwhite);
        g.fillRect (currentKey);
        g.setColour (juce::Colours::black);
        g.drawRect (currentKey);
    }
    
    g.setColour(juce::Colours::gold);
    g.drawRoundedRectangle(10.0f, 0.0f, 40.0f, (float)getHeight(), 10.0f, 3.0f);
  
    
}

void QN2M_PianoDisplay::resized()
{
\

}
