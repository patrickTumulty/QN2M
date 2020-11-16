/*
  ==============================================================================

    QN2M_NoteRangeSelector.cpp
    Created: 27 Oct 2020 10:18:43am
    Author:  Patrick Tumulty

  ==============================================================================
*/

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "QN2M_NoteRangeSelector.h"

//==============================================================================
QN2M_NoteRangeSelector::QN2M_NoteRangeSelector (Qn2mAudioProcessor& p)
{
    // ==== RANGE LABEL ====
    
    addAndMakeVisible (rangeLabel);
    rangeLabel.setText ("RANGE", juce::NotificationType::dontSendNotification);
    rangeLabel.setFont (juce::Font ("Futura", 21.0f, juce::Font::bold));
    rangeLabel.setJustificationType(juce::Justification::left);
    
    addAndMakeVisible (rangeHighLabel);
    rangeHighLabel.setText ("H*", juce::NotificationType::dontSendNotification);
    rangeHighLabel.setFont (juce::Font ("Futura", 16.0f, juce::Font::bold));
    rangeHighLabel.setJustificationType(juce::Justification::right);
    
    addAndMakeVisible (rangeLowLabel);
    rangeLowLabel.setText ("L*", juce::NotificationType::dontSendNotification);
    rangeLowLabel.setFont (juce::Font ("Futura", 16.0f, juce::Font::bold));
    rangeLowLabel.setJustificationType(juce::Justification::right);
  
    
    // ==== RANGE SLIDER ====
    
//    addAndMakeVisible (rangeSlider);
//    rangeSlider.setSliderStyle (juce::Slider::SliderStyle::TwoValueHorizontal);
//    rangeSlider.setColour (juce::Slider::ColourIds::thumbColourId, juce::Colours::orangered);
//    rangeSlider.setColour (juce::Slider::ColourIds::trackColourId, juce::Colours::darkorange);
//    rangeSlider.setRange (juce::Range<double>(21.0f, 108.0f), 1.0f);
//    rangeSlider.setMinAndMaxValues (21.0f, 108.0f);
//    rangeSlider.setTextBoxStyle (rangeSlider.NoTextBox, false, 0, 0);
//    
//    rangeSlider.addListener (this);
    
//    mRangeSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(p.getAPVTS(), "RANGE_HIGH", rangeSlider);
    
    
    addAndMakeVisible (rangeHighSlider);
    rangeHighSlider.setRange (juce::Range<double>(21.0f, 108.0f), 1.0f);
    rangeHighSlider.setValue (108.0f);
    rangeHighSlider.setTextBoxStyle (juce::Slider::TextEntryBoxPosition::TextBoxLeft, false, 30, 20);
    rangeHighSlider.setColour (juce::Slider::ColourIds::textBoxOutlineColourId, juce::Colours::darkgrey);
    rangeHighSlider.setColour (juce::Slider::ColourIds::thumbColourId, juce::Colours::orangered);
    rangeHighSlider.setColour (juce::Slider::ColourIds::backgroundColourId, juce::Colours::dimgrey);
    rangeHighSlider.setColour (juce::Slider::ColourIds::trackColourId, juce::Colours::orange);


    
    addAndMakeVisible (rangeLowSlider);
    rangeLowSlider.setRange(juce::Range<double>(21.0f, 108.0f), 1.0f);
    rangeLowSlider.setValue (21.0f);
    rangeLowSlider.setTextBoxStyle (juce::Slider::TextEntryBoxPosition::TextBoxLeft, false, 30, 20);
    rangeLowSlider.setColour(juce::Slider::ColourIds::textBoxOutlineColourId, juce::Colours::darkgrey);
    rangeLowSlider.setColour(juce::Slider::ColourIds::thumbColourId, juce::Colours::orangered);
    rangeLowSlider.setColour(juce::Slider::ColourIds::backgroundColourId, juce::Colours::orange);
    rangeLowSlider.setColour(juce::Slider::ColourIds::trackColourId, juce::Colours::dimgrey);


}

QN2M_NoteRangeSelector::~QN2M_NoteRangeSelector()
{
}

void QN2M_NoteRangeSelector::paint (juce::Graphics& g)
{
    
    juce::Rectangle<int> rangeSelectorBackground = getLocalBounds().reduced (3, 3);
       
    g.setColour (juce::Colours::darkgrey);
    g.fillRoundedRectangle (rangeSelectorBackground.getX(),
                            rangeSelectorBackground.getY(),
                            rangeSelectorBackground.getWidth(),
                            rangeSelectorBackground.getHeight(),
                            5); // corner
    g.setColour (juce::Colours::orangered);
    g.drawRoundedRectangle (rangeSelectorBackground.getX(),
                            rangeSelectorBackground.getY(),
                            rangeSelectorBackground.getWidth(),
                            rangeSelectorBackground.getHeight(),
                            9, 3); // corner and line thickness

}

void QN2M_NoteRangeSelector::resized()
{
//    juce::Rectangle<int> localArea = getLocalBounds().reduced (5, 10);
//    rangeLabel.setBounds (localArea.removeFromRight (getWidth() / 8));
//    rangeSlider.setBounds (localArea);
    
    juce::Rectangle<int> localArea = getLocalBounds();
    juce::Rectangle<int> rangeLabelArea = localArea.removeFromRight (getWidth() / 6);
    juce::Rectangle<int> HLLabelArea = localArea.removeFromLeft (getWidth() / 12);
    
    rangeLabel.setBounds (rangeLabelArea);
    rangeHighLabel.setBounds (HLLabelArea.removeFromTop (getHeight() / 2));
    rangeLowLabel.setBounds (HLLabelArea);
    
    rangeHighSlider.setBounds (localArea.removeFromTop(getHeight() / 2).reduced(0, 5));
    rangeLowSlider.setBounds (localArea);

}

void QN2M_NoteRangeSelector::sliderValueChanged(juce::Slider *slider)
{
//    if (slider == &rangeSlider)
//    {
//        DBG(rangeSlider.getMinValue() << " " << rangeSlider.getMaxValue());
//    }
    
}
