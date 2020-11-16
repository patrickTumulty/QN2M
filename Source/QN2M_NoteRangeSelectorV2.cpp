/*
  ==============================================================================

    QN2M_NoteRangeSelectorV2.cpp
    Created: 3 Nov 2020 6:30:31pm
    Author:  Patrick Tumulty

  ==============================================================================
*/

#include <JuceHeader.h>
#include "QN2M_NoteRangeSelectorV2.h"

//==============================================================================
QN2M_NoteRangeSelectorV2::QN2M_NoteRangeSelectorV2()
{
    keyboard = juce::ImageCache::getFromMemory (BinaryData::Keyboard2358x342_png, BinaryData::Keyboard2358x342_pngSize);
    
    addAndMakeVisible (rangeSlider);
    rangeSlider.setSliderStyle (juce::Slider::SliderStyle::Rotary);
    rangeSlider.setTextBoxStyle (rangeSlider.NoTextBox, false, 0, 0);
    rangeSlider.setRange (juce::Range<double>(1.0f, 108.0f), 1.0f); // Minimum one midi note, Mac full range
    rangeSlider.setValue (108.0f); // start with max range
    rangeSlider.addListener (this);
    rangeSlider.setColour(juce::Slider::ColourIds::thumbColourId, juce::Colours::orange);
    
    addAndMakeVisible (centerSlider);
    centerSlider.setSliderStyle (juce::Slider::SliderStyle::Rotary);
    centerSlider.setTextBoxStyle (centerSlider.NoTextBox, false, 0, 0);
    centerSlider.setRange (juce::Range<double>(1.0f, 107.0f), 1.0f); // First note of range
    centerSlider.setValue (1.0f);
    centerSlider.addListener (this);
    centerSlider.setColour(juce::Slider::ColourIds::thumbColourId, juce::Colours::orange);

}

QN2M_NoteRangeSelectorV2::~QN2M_NoteRangeSelectorV2()
{
}

void QN2M_NoteRangeSelectorV2::paint (juce::Graphics& g)
{
    
    // Draw Keyboard Image
    juce::Rectangle<float> keyboardBounds = juce::Rectangle<float> (0, 5, getLocalBounds().getWidth(), getLocalBounds().getHeight());
    juce::Rectangle<float> local = juce::Rectangle<float> (0, 5, getLocalBounds().getWidth(), getLocalBounds().getHeight());
    
    juce::Rectangle<float> keyboardAndBackground = keyboardBounds.removeFromRight (getWidth() * 0.66f);
    g.setColour (juce::Colours::darkgrey);
    g.fillRoundedRectangle(keyboardAndBackground.reduced (5, 5), 10);
    g.drawImage (keyboard, keyboardAndBackground.reduced (10, 20));
    
    
    // Draw Rectangle
    g.setColour (juce::Colours::orange); // set rectangle color
    
    local = local.removeFromRight (getWidth() * 0.66f);
    maxWidth = getLocalBounds().removeFromRight (getWidth() * 0.66f).getWidth() - 5;
    initX = getLocalBounds().removeFromRight (getWidth() * 0.66f).getX();
    

    local.setWidth (widthScalar);
    local.setX ((float)(initX + xScalar));
    
    g.drawRoundedRectangle (local.reduced (5, 10), 10, 4);
    

}

void QN2M_NoteRangeSelectorV2::resized()
{
    juce::Rectangle<int> local = getLocalBounds();
    int w = getWidth();
    rangeSlider.setBounds (local.removeFromLeft (w / 6));
    centerSlider.setBounds (local.removeFromLeft (w / 6));
 
}


void QN2M_NoteRangeSelectorV2::sliderValueChanged(juce::Slider *slider)
{
    // TODO: Work on this logic to make lessy jittery.
    // TODO: Fix issue where rectangle is drawn out of frame for just a second 
    if (slider == &rangeSlider)
    {
        widthScalar = (maxWidth / 108.0f) * slider->getValue();
        if (slider->getValue() < 5) widthScalar = (maxWidth / 108.0f) * 5; // This changes visual display, not internal dial values
        
        
        if (slider->getValue() + centerSlider.getValue() > 108.0f)
        {
            centerSlider.setValue (108.0f - slider->getValue());
        }
    }
    else if (slider == &centerSlider)
    {
        xScalar =  (maxWidth / 108.0f) * slider->getValue();
        if (slider->getValue() + rangeSlider.getValue() > 108.0f)
        {
            rangeSlider.setValue (108.0f - slider->getValue());
        }
    }
    
    if (rangeSlider.getValue() == 1 && centerSlider.getValue() >= 103)
    {
        xScalar = (maxWidth / 108.0f) * 103;
        widthScalar = (maxWidth / 108.0f) * 5;
    }
  
    repaint();
}
