/*
  ==============================================================================

    QN2M_MainPanel.cpp
    Created: 25 Oct 2020 12:01:55am
    Author:  Patrick Tumulty

  ==============================================================================
*/

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "QN2M_MainPanel.h"

//==============================================================================
QN2M_MainPanel::QN2M_MainPanel (Qn2mAudioProcessor& p) 
{
    mLogo = juce::ImageCache::getFromMemory(BinaryData::QN2M_Logo_png, BinaryData::QN2M_Logo_pngSize);
    
    addAndMakeVisible (keyBoard);
    addAndMakeVisible (rangeSelector);
    
    addAndMakeVisible (mainLogo);
    
    addAndMakeVisible (randomizationPanel);
    
    // ===== TEMPO LABEL =====
    
    addAndMakeVisible (tempoLabel);
    tempoLabel.setText ("TEMPO", juce::NotificationType::dontSendNotification);
    tempoLabel.setFont (juce::Font ("Futura", 21.0f, juce::Font::bold));
    tempoLabel.setJustificationType (juce::Justification::centredRight);
    
    // ===== START BUTTON =====
    
    addAndMakeVisible (startButton);
    startButton.setButtonText (juce::CharPointer_UTF8("ƒ(x)"));
    startButton.setClickingTogglesState(true);
    startButton.setColour (juce::TextButton::ColourIds::buttonColourId, juce::Colours::darkgrey);
    startButton.setColour (juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::limegreen);
    
    // ===== TEMPO SELECTOR ====
    
    addAndMakeVisible (tempoSelector);
    tempoSelector.addItemList (juce::StringArray { "1/1", "1/2", "1/4", "1/8", "1/16", "1/32" }, 1);
    tempoSelector.setSelectedId (3); // start with 1/4
    tempoSelector.setColour (juce::ComboBox::ColourIds::backgroundColourId, juce::Colours::darkturquoise);
    tempoSelector.setColour (juce::ComboBox::ColourIds::arrowColourId, juce::Colours::yellow);
    tempoSelector.setColour (juce::ComboBox::ColourIds::textColourId, juce::Colours::black);
}

QN2M_MainPanel::~QN2M_MainPanel()
{
}



void QN2M_MainPanel::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::dimgrey); // set background color
//    juce::Rectangle<float> backgroundArea = juce::Rectangle<float>(0, 0, getWidth(), getHeight());
//    g.drawImage(mBackground, backgroundArea);
    
    
        

}

void QN2M_MainPanel::resized()
{
    
    juce::Rectangle<int> localArea = getLocalBounds();

    juce::Rectangle<int> lowerButtonArea = localArea.removeFromBottom (getHeight() * 0.67f);
    
    rangeSelector.setBounds (lowerButtonArea.removeFromBottom (lowerButtonArea.getHeight() / 3).reduced (5, 5));
    keyBoard.setBounds (lowerButtonArea.reduced (5, 5));
    
    mainLogo.setBounds (localArea.removeFromLeft(localArea.getHeight()).reduced (5, 5));
    
    juce::Rectangle<int> startTempoArea = localArea.removeFromLeft (getWidth() / 3);
    
    startButton.setBounds (startTempoArea.removeFromTop (startTempoArea.getHeight() * 0.67f).reduced (8, 8));
    tempoLabel.setBounds (startTempoArea.removeFromLeft (startTempoArea.getWidth() / 2).reduced (8,8));
    tempoSelector.setBounds (startTempoArea.reduced (8, 8));
    
    randomizationPanel.setBounds (localArea.reduced (5, 5));
    
    
}
