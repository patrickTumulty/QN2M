/*
  ==============================================================================

    QN2M_Logo.cpp
    Created: 27 Oct 2020 11:27:22am
    Author:  Patrick Tumulty

  ==============================================================================
*/

#include <JuceHeader.h>
#include "QN2M_Logo.h"

//==============================================================================
QN2M_Logo::QN2M_Logo()
{
    
    mLogo = juce::ImageCache::getFromMemory(BinaryData::QN2M_Logo_png, BinaryData::QN2M_Logo_pngSize);
    
}

QN2M_Logo::~QN2M_Logo()
{
}

void QN2M_Logo::paint (juce::Graphics& g)
{
    juce::Rectangle<int> logoBackground = getLocalBounds().reduced (3, 3);
    juce::Rectangle<int> imgRecangle = logoBackground.reduced (10, 10);

    g.setColour (juce::Colours::darkgrey);
    g.fillRoundedRectangle (logoBackground.getX(),
                            logoBackground.getY(),
                            logoBackground.getHeight(),
                            logoBackground.getHeight(),
                            5); // corner
    g.setColour (juce::Colours::ghostwhite);
    g.drawRoundedRectangle (logoBackground.getX(),
                           logoBackground.getY(),
                           logoBackground.getHeight(),
                           logoBackground.getHeight(),
                           9, 3); // corner and line thickness
    
    g.drawImageWithin(mLogo, imgRecangle.getX(), imgRecangle.getY(), imgRecangle.getHeight(), imgRecangle.getHeight(), juce::RectanglePlacement::centred);
    
}

void QN2M_Logo::resized()
{


}
