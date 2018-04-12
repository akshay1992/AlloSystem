#ifndef AL_ALLOSPHERE_SPEAKER_LAYOUT_H
#define AL_ALLOSPHERE_SPEAKER_LAYOUT_H

#include "allocore/sound/al_Speaker.hpp"

#define NUM_SPEAKERS 54

namespace al {

/// Current arrangement of speakers in AlloSphere
struct AlloSphereSpeakerLayout : public SpeakerLayout{
	AlloSphereSpeakerLayout(){
		const int numSpeakers = 54;
		Speaker speakers[numSpeakers] = {
		    Speaker(1-1, -77.660913, 41.000000, 4.992118),
		    Speaker(2-1, -45.088015, 41.000000, 5.571107),
		    Speaker(3-1, -14.797289, 41.000000, 5.900603),
		    Speaker(4-1, 14.797289, 41.000000, 5.900603),
		    Speaker(5-1, 45.088015, 41.000000, 5.571107),
		    Speaker(6-1, 77.660913, 41.000000, 4.992118),
		    Speaker(7-1, 102.339087, 41.000000, 4.992118),
		    Speaker(8-1, 134.911985, 41.000000, 5.571107),
		    Speaker(9-1, 165.202711, 41.000000, 5.900603),
		    Speaker(10-1, -165.202711, 41.000000, 5.900603),
		    Speaker(11-1, -134.911985, 41.000000, 5.571107),
		    Speaker(12-1, -102.339087, 41.000000, 4.992118),
		    Speaker(17-1, -77.660913, 0.000000, 4.992118),
		    Speaker(18-1, -65.647587, 0.000000, 5.218870),
		    Speaker(19-1, -54.081600, 0.000000, 5.425483),
		    Speaker(20-1, -42.869831, 0.000000, 5.604350),
		    Speaker(21-1, -31.928167, 0.000000, 5.749461),
		    Speaker(22-1, -21.181024, 0.000000, 5.856274),
		    Speaker(23-1, -10.559657, 0.000000, 5.921613),
		    Speaker(24-1, 0.000000, 0.000000, 5.943600),
		    Speaker(25-1, 10.559657, 0.000000, 5.921613),
		    Speaker(26-1, 21.181024, 0.000000, 5.856274),
		    Speaker(27-1, 31.928167, 0.000000, 5.749461),
		    Speaker(28-1, 42.869831, 0.000000, 5.604350),
		    Speaker(29-1, 54.081600, 0.000000, 5.425483),
		    Speaker(30-1, 65.647587, 0.000000, 5.218870),
		    Speaker(31-1, 77.660913, 0.000000, 4.992118),
		    Speaker(32-1, 102.339087, 0.000000, 4.992118),
		    Speaker(33-1, 114.352413, 0.000000, 5.218870),
		    Speaker(34-1, 125.918400, 0.000000, 5.425483),
		    Speaker(35-1, 137.130169, 0.000000, 5.604350),
		    Speaker(36-1, 148.071833, 0.000000, 5.749461),
		    Speaker(37-1, 158.818976, 0.000000, 5.856274),
		    Speaker(38-1, 169.440343, 0.000000, 5.921613),
		    Speaker(39-1, 180.000000, 0.000000, 5.943600),
		    Speaker(40-1, -169.440343, 0.000000, 5.921613),
		    Speaker(41-1, -158.818976, 0.000000, 5.856274),
		    Speaker(42-1, -148.071833, 0.000000, 5.749461),
		    Speaker(43-1, -137.130169, 0.000000, 5.604350),
		    Speaker(44-1, -125.918400, 0.000000, 5.425483),
		    Speaker(45-1, -114.352413, 0.000000, 5.218870),
		    Speaker(46-1, -102.339087, 0.000000, 4.992118),
		    Speaker(49-1, -77.660913, -32.500000, 4.992118),
		    Speaker(50-1, -45.088015, -32.500000, 5.571107),
		    Speaker(51-1, -14.797289, -32.500000, 5.900603),
		    Speaker(52-1, 14.797289, -32.500000, 5.900603),
		    Speaker(53-1, 45.088015, -32.500000, 5.571107),
		    Speaker(54-1, 77.660913, -32.500000, 4.992118),
		    Speaker(55-1, 102.339087, -32.500000, 4.992118),
		    Speaker(56-1, 134.911985, -32.500000, 5.571107),
		    Speaker(57-1, 165.202711, -32.500000, 5.900603),
		    Speaker(58-1, -165.202711, -32.500000, 5.900603),
		    Speaker(59-1, -134.911985, -32.500000, 5.571107),
		    Speaker(60-1, -102.339087, -32.500000, 4.992118),
		};

		mSpeakers.reserve(NUM_SPEAKERS);
		for(int i=0; i<NUM_SPEAKERS; ++i)
			addSpeaker(alloSpeakers[i]);
	}
};

}  // al
#endif
