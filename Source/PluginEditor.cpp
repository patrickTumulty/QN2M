/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Qn2mAudioProcessorEditor::Qn2mAudioProcessorEditor (Qn2mAudioProcessor& p)
    : AudioProcessorEditor (&p), mainPanel (p), audioProcessor (p) 
{
    setSize (560, 400);
    
    addAndMakeVisible (mainPanel);
//    addAndMakeVisible (noteRangeSelector);
}

Qn2mAudioProcessorEditor::~Qn2mAudioProcessorEditor()
{
}

//==============================================================================
void Qn2mAudioProcessorEditor::paint (juce::Graphics& g)
{
    
}

void Qn2mAudioProcessorEditor::resized()
{
    mainPanel.setBounds (getLocalBounds());
//    noteRangeSelector.setBounds(getLocalBounds().removeFromTop (getHeight() / 3)); // for prototyping
}
