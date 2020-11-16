/*
  ==============================================================================

    QN2M_KeyboardButtons.cpp
    Created: 26 Oct 2020 3:53:25pm
    Author:  Patrick Tumulty

  ==============================================================================
*/

#include <JuceHeader.h>
#include "QN2M_KeyboardButtons.h"

//==============================================================================
QN2M_KeyboardButtons::QN2M_KeyboardButtons()
{
    noteSelectButtonConfig (&C_Button, "C");
    noteSelectButtonConfig (&D_Button, "D");
    noteSelectButtonConfig (&E_Button, "E");
    noteSelectButtonConfig (&F_Button, "F");
    noteSelectButtonConfig (&G_Button, "G");
    noteSelectButtonConfig (&A_Button, "A");
    noteSelectButtonConfig (&B_Button, "B");
    
    noteSelectButtonConfig (&CS_Button, "C#");
    noteSelectButtonConfig (&DS_Button, "D#");
    noteSelectButtonConfig (&FS_Button, "F#");
    noteSelectButtonConfig (&GS_Button, "G#");
    noteSelectButtonConfig (&AS_Button, "A#");

}

QN2M_KeyboardButtons::~QN2M_KeyboardButtons()
{
}

void QN2M_KeyboardButtons::paint (juce::Graphics& g)
{
    
    // ====== KEYBOARD BUTTONS BACKGROUND =====
    
    juce::Rectangle<int> keyboardButtonsBackground = getLocalBounds().reduced (3, 3);
    
    g.setColour (juce::Colours::darkgrey);
    g.fillRoundedRectangle (keyboardButtonsBackground.getX(),
                            keyboardButtonsBackground.getY(),
                            keyboardButtonsBackground.getWidth(),
                            keyboardButtonsBackground.getHeight(),
                            5); // corner
    g.setColour (juce::Colours::limegreen);
    g.drawRoundedRectangle (keyboardButtonsBackground.getX(),
                           keyboardButtonsBackground.getY(),
                           keyboardButtonsBackground.getWidth(),
                           keyboardButtonsBackground.getHeight(),
                           9, 3); // corner and line thickness
}

void QN2M_KeyboardButtons::resized()
{
    juce::Rectangle<int> buttonArea = getLocalBounds().reduced (3,3);
    
    int reducedX = 10;
    int reducedY = 10;
    
    int topRowCoordinateScalarX = (getWidth() / 14);
    int topRowButtonWidth = getWidth() / 7;
    int topRowButtonHeight = getHeight() / 2;
    
    buttonArea = buttonArea.removeFromBottom(getHeight() / 2);
    
    C_Button.setBounds (buttonArea.removeFromLeft (getWidth() / 7).reduced (reducedX, reducedY));
    D_Button.setBounds (buttonArea.removeFromLeft (getWidth() / 7).reduced (reducedX, reducedY));
    E_Button.setBounds (buttonArea.removeFromLeft (getWidth() / 7).reduced (reducedX, reducedY));
    F_Button.setBounds (buttonArea.removeFromLeft (getWidth() / 7).reduced (reducedX, reducedY));
    G_Button.setBounds (buttonArea.removeFromLeft (getWidth() / 7).reduced (reducedX, reducedY));
    A_Button.setBounds (buttonArea.removeFromLeft (getWidth() / 7).reduced (reducedX, reducedY));
    B_Button.setBounds (buttonArea.removeFromLeft (getWidth() / 7).reduced (reducedX, reducedY));
    
    CS_Button.setBounds (juce::Rectangle<int> (topRowCoordinateScalarX * 1, 5, topRowButtonWidth, topRowButtonHeight).reduced (reducedX, reducedY));
    DS_Button.setBounds (juce::Rectangle<int> (topRowCoordinateScalarX * 3, 5, topRowButtonWidth, topRowButtonHeight).reduced (reducedX, reducedY));
    
    FS_Button.setBounds (juce::Rectangle<int> (topRowCoordinateScalarX * 7, 5, topRowButtonWidth, topRowButtonHeight).reduced (reducedX, reducedY));
    GS_Button.setBounds (juce::Rectangle<int> (topRowCoordinateScalarX * 9, 5, topRowButtonWidth, topRowButtonHeight).reduced (reducedX, reducedY));
    AS_Button.setBounds (juce::Rectangle<int> (topRowCoordinateScalarX * 11, 5, topRowButtonWidth, topRowButtonHeight).reduced (reducedX, reducedY));

}

void QN2M_KeyboardButtons::noteSelectButtonConfig (juce::TextButton* button, juce::String noteName)
{
//    button->setButtonText (noteName); // Commented out because text overlaps in the way that buttons are drawn
    button->setClickingTogglesState (true);
    button->setColour (juce::TextButton::ColourIds::buttonColourId, juce::Colours::darkgrey);
    button->setColour (juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::limegreen);
    button->setColour (juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    button->setColour (juce::TextButton::ColourIds::textColourOffId, juce::Colours::dimgrey);
    addAndMakeVisible(button);
}
