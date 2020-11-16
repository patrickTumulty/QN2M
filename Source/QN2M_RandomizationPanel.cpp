/*
  ==============================================================================

    QN2M_RandomizationPanel.cpp
    Created: 28 Oct 2020 12:36:15am
    Author:  Patrick Tumulty

  ==============================================================================
*/

#include <JuceHeader.h>
#include "QN2M_RandomizationPanel.h"

//==============================================================================
QN2M_RandomizationPanel::QN2M_RandomizationPanel()
{
    
    // ==== LABELS ====
    
    addAndMakeVisible (randLabel);
    randLabel.setText ("RANDOMIZATION", juce::NotificationType::dontSendNotification);
    randLabel.setFont (juce::Font ("Futura", 21.0f, juce::Font::bold));
    randLabel.setJustificationType (juce::Justification::centredLeft);
    
    addAndMakeVisible (tempoLabel);
    tempoLabel.setText ("T*", juce::NotificationType::dontSendNotification);
    tempoLabel.setFont (juce::Font ("Futura", 16.0f, juce::Font::bold));
    tempoLabel.attachToComponent(&randTempo, true);
    tempoLabel.setJustificationType (juce::Justification::centredRight);
    
    addAndMakeVisible (spaceLabel);
    spaceLabel.setText ("S*", juce::NotificationType::dontSendNotification);
    spaceLabel.setFont (juce::Font ("Futura", 16.0f, juce::Font::bold));
    spaceLabel.attachToComponent(&randSpace, true);
    spaceLabel.setJustificationType (juce::Justification::centredRight);
    
    // ==== SPACE SLIDER ====
    
    addAndMakeVisible (randSpace);
    randSpace.setRange (juce::Range<double>(0, 99), 1);
    randSpace.setTextValueSuffix("%");
    randSpace.setTextBoxStyle (juce::Slider::TextEntryBoxPosition::TextBoxLeft, false, 30, 20);
    randSpace.setColour (juce::Slider::ColourIds::thumbColourId, juce::Colours::yellow);
    randSpace.setColour (juce::Slider::ColourIds::trackColourId, juce::Colours::orangered);
    
    // ==== TEMPO SLIDER ====
    
    addAndMakeVisible (randTempo);
    randTempo.setRange (juce::Range<double>(0, 99), 1);
    randTempo.setTextValueSuffix("%");
    randTempo.setTextBoxStyle (juce::Slider::TextEntryBoxPosition::TextBoxLeft, false, 30, 20);
    randTempo.setColour (juce::Slider::ColourIds::thumbColourId, juce::Colours::yellow);
    randTempo.setColour (juce::Slider::ColourIds::trackColourId, juce::Colours::darkturquoise);

}

QN2M_RandomizationPanel::~QN2M_RandomizationPanel()
{
}

void QN2M_RandomizationPanel::paint (juce::Graphics& g)
{
    
    juce::Rectangle<int> randPanelBackground = getLocalBounds().reduced (3, 3);
          
    g.setColour (juce::Colours::darkgrey);
    g.fillRoundedRectangle (randPanelBackground.getX(),
                            randPanelBackground.getY(),
                            randPanelBackground.getWidth(),
                            randPanelBackground.getHeight(),
                            5); // corner
    g.setColour (juce::Colours::yellow);
    g.drawRoundedRectangle (randPanelBackground.getX(),
                            randPanelBackground.getY(),
                            randPanelBackground.getWidth(),
                            randPanelBackground.getHeight(),
                            9, 3); // corner and line thickness
}

void QN2M_RandomizationPanel::resized()
{
    juce::Rectangle<int> localArea = getLocalBounds().reduced (3, 3);
    
    int height = getLocalBounds().getHeight() / 3;
    
    randLabel.setBounds (localArea.removeFromTop(height).reduced (5, 5));
    randTempo.setBounds (localArea.removeFromTop(height).removeFromRight(getWidth() * 0.85f).reduced (5, 5));
    randSpace.setBounds (localArea.removeFromRight(getWidth() * 0.85f).reduced (5, 5));
    

}
