import("stdfaust.lib");

gain = hslider("gain", 0.5, 0, 1, 0.01) : si.smoo;
tone = hslider("tone", 0.5, 0, 1, 0.01) : si.smoo;
volume = hslider("volume", 0.5, 0, 1, 0.01) : si.smoo;

input_filter = fi.highpass(1, 720);

clipping = ef.cubicnl(gain, 0);

post_filter = fi.lowpass(1, 350 + (tone * (4500 - 350)));

volume_control = ba.db2linear((volume - 1) * 40);

process =  input_filter : clipping : post_filter * volume_control;
