# QN2M

QN2M (Quantized Noise to Midi) is a Midi generating plugin. Users get to define a number of parameters that will control the pitch and tempo at which new midi notes are randomly drawn to their DAWs piano roll. The randomization panel is meant to create further variations in the MIDI note generation. The `T*` parameter determines a probability that the tempo will be randomly changed on any given note. A previous iteration of this project, titled [SPIT](https://github.com/patrickTumulty/Spit), was only capable of generating MIDI notes at a constant interval. The `S*` parameter will control the likely hood that any given note will be silent.

<p align="center">
	<img src="Images/GUIExample.png" width="500">
</p>

## Inspiration

The inspiration for this project came from studying modular synthesis techniques over the duration of a semester. During this class, I noticed that I was using a similar set of modules each time I began a new patch. This sequence of modules is illustrated below in VCVRack. We start with a clock (Square wave) that decides our tempo. That clock will control an ADSR envelope and a noise generator. We now get a new random value from the noise generator with every pulse of our clock. That random noise value gets quantized into a musical pitch based on a user defined scale. In this example we are quantizing these noise values to a C major scale. The ADSR controls the envelope of a VCO and voila! Endless music!

The example illustrated below actually sounds pretty terrible, but it is a foundation that can be expanded upon. I wanted to take this concept and use it with some of my favorite MIDI synth plugins. Though QN2M doesn't actually create any sound, it can be used to create generative music with any MIDI synth in a DAW environment.  

<p align="center">
	<img src="Images/VCVExample.png" width="700">
</p>
