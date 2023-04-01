/*
Attempt at a true vibrato
And it works well!
Sounds very sweet with tubes wrapped

Need
LFO to modulate de.delay	- LFO 5 - 14Hz
	speed and depth
*/
import("stdfaust.lib");
import("redeye.lib");


/* os.triangle oscillator (not bandlimited, frequency is approximate) */

trianglewave(freq) = _ ~ (_ <: _ + hyst) : /(periodsamps) with {
    if(c,t,e) = select2(c,e,t);
    hyst(x) = if(_ > 0, 2 * (x < periodsamps) - 1, 1 - 2 * (x > 0)) ~ _;
    periodsamps = int(ma.SR / (2*float(freq)));
};

/* vibrato unit, using os.triangle or sine oscillator as lfo 
	to modulate the de.delay time 
*/

vibrato = ((( lfo + 1 ) *5)+5)*depth with {
    sine(freq) = (os.oscs(freq) + 1) / 2 : max(0); // max(0) because of numerical inaccuracy
    SINE=checkbox("SINEWAVE[enum:os.triangle|sine]");
    lfo = select2(SINE, trianglewave(freq), sine(freq));
	freq = vslider("speed[style:knob]",5,0,14,0.1) ;
	depth = vslider("depth[style:knob]",0.5,0.0,1.0,0.01) ;
};

delayed  = de.sdelay(65536, interp, vibrato*ma.SR/1000.0) with{
	N 		= int(2^12); //65536
	interp = 100.0 *ma.SR/1000.0;
	dtime	= hslider("delay[unit:ms][style:knob]", 0, 0, 14, 0.1)*ma.SR/1000.0;
};

output = vslider("output[style:knob]", 0.0, -20.0, 20.0, 0.1):ba.db2linear:si.smooth(0.993);
amp = input12ax7:delayed:output12ax7:*(output);
freq_split = fi.filterbank(3, (86.0,210.0,1200.0,6531.0));
process    = freq_split: ( amp , amp , amp, amp, amp) :>_;
